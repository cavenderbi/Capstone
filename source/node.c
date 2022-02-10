#include "node.h"

/*  Inserts into the linked list. 
    Be careful as the datatype of the data is lost in this. 
    @param head A pointer to the head of the list to be inserted into. 
    @param data A pointer to the data to be inserted at the front of the list. 
    @returns A pointer to the new head. */
Node * insert(Node * head, void * data) {
    Node * node = (Node *) malloc(sizeof(Node));
    node->data = data;
    /*  If the list is empty, insert at the head. */
    if (head == NULL) {
        node->next = head;
        return node;
    }
    /*  If the list is NOT empty, iterate to the end and 
        insert there. */
    node->next = NULL;
    Node * current = head;
    while (true) {
        if (current->next == NULL) {
            current->next = node;
            break;
        }
        current = current->next;
    }
}

/*  Removes from the linked list and deletes the data. 
    @param head A pointer to the head of the list to be removed from. 
    @param index The index of the item to be removed. 
    @return The pointer to the head. */
Node * remove(Node * head, int index) {
    /*  If the list is empty, you can't remove from it. */
    if (head == NULL) 
        return NULL;
    /* If the head is to be removed, set the head to the 
        next node and remove the old head. */
    Node * temp = head;
    if (index == 0) {
        head = head->next;
        free(temp);
        return head;
    }
    int i;
    for (i = 0; i < index - 1; i++)
        temp = temp->next;

    Node * temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);   
    return head;
}
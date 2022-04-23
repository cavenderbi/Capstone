#include <stdint.h>
#include <gb/gb.h>
#include "../lib/hUGEDriver.h"

void ISR_wrapper() {
    hUGE_dosound/* _banked */();
}
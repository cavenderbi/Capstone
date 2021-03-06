#include "../lib/hUGEDriver.h"
#include <stddef.h>
#pragma bank 1
static const unsigned char order_cnt = 28;

static const unsigned char P0[] = {
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_4,0,0x000),
    DN(As4,0,0x000),
    DN(A_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_4,0,0x000),
    DN(___,0,0x000),
    DN(Ds4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(D_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_4,0,0x000),
    DN(As4,0,0x000),
    DN(C_5,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(A_4,0,0x000),
    DN(___,0,0x000),
    DN(G_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_4,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P1[] = {
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P2[] = {
    DN(Ds4,11,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(C_4,11,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_4,11,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(C_4,11,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_4,11,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Gs4,0,0x000),
    DN(___,0,0x000),
    DN(G_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Gs4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(C_4,11,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P3[] = {
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P4[] = {
    DN(Ds4,11,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(C_4,11,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_4,11,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(C_4,11,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_4,11,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Gs4,0,0x000),
    DN(___,0,0x000),
    DN(C_5,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As4,0,0x000),
    DN(___,0,0x000),
    DN(C_5,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P5[] = {
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_4,0,0x000),
    DN(As4,0,0x000),
    DN(A_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_4,0,0x000),
    DN(___,0,0x000),
    DN(Ds4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(D_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_4,0,0x000),
    DN(As4,0,0x000),
    DN(C_5,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(A_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P6[] = {
    DN(G_3,11,0xC07),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As3,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_3,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_3,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As3,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Gs3,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_3,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As3,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(A_3,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(D_4,11,0x000),
    DN(___,0,0x000),
};
static const unsigned char P9[] = {
    DN(C_5,1,0xC09),
    DN(___,0,0x000),
    DN(D_5,0,0x000),
    DN(___,0,0x000),
    DN(C_5,0,0x000),
    DN(___,0,0x000),
    DN(As4,0,0x000),
    DN(___,0,0x000),
    DN(A_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_5,1,0xC09),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_5,1,0xC09),
    DN(___,0,0x000),
    DN(As4,0,0x000),
    DN(___,0,0x000),
    DN(A_4,0,0x000),
    DN(___,0,0x000),
    DN(F_4,0,0x000),
    DN(___,0,0x000),
    DN(G_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Gs4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P10[] = {
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_5,2,0x000),
    DN(___,0,0x107),
    DN(G_5,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Ds5,0,0x000),
    DN(G_5,0,0x000),
    DN(F_5,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Ds5,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(D_5,0,0x000),
    DN(___,0,0x000),
    DN(C_5,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_5,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_5,2,0x000),
    DN(___,0,0x107),
    DN(G_5,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Ds5,0,0x000),
    DN(G_5,0,0x000),
    DN(A_5,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_5,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_5,0,0x000),
    DN(___,0,0x000),
    DN(Ds5,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(D_5,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Ds5,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P13[] = {
    DN(C_5,1,0xC08),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(A_4,0,0x000),
    DN(___,0,0x000),
    DN(G_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As4,1,0xC09),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Gs4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_4,0,0x000),
    DN(___,0,0x000),
    DN(F_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Ds4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Gs4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P14[] = {
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_5,2,0x000),
    DN(___,0,0x107),
    DN(G_5,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Ds5,0,0x000),
    DN(G_5,0,0x000),
    DN(F_5,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Ds5,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(D_5,0,0x000),
    DN(___,0,0x000),
    DN(C_5,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_5,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_5,2,0x000),
    DN(___,0,0x107),
    DN(G_5,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Ds5,0,0x000),
    DN(G_5,0,0x000),
    DN(F_5,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P19[] = {
    DN(Ds4,11,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(C_4,11,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_4,11,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(C_4,11,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_4,11,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Gs4,0,0x000),
    DN(___,0,0x000),
    DN(C_5,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As4,0,0x000),
    DN(___,0,0x000),
    DN(A_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Gs4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P22[] = {
    DN(C_4,11,0xC07),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Ds4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(D_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As3,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Gs3,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_3,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As3,11,0xC07),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As3,11,0xC07),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Gs3,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P100[] = {
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(C_6,1,0x000),
    DN(C_7,3,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(C_6,1,0x000),
    DN(C_7,3,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(C_6,1,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
};
static const unsigned char P101[] = {
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_7,3,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(C_6,1,0x000),
    DN(C_7,3,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
};
static const unsigned char P102[] = {
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0xB03),
};
static const unsigned char P103[] = {
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0xB05),
};
static const unsigned char P104[] = {
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_7,3,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_7,3,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
    DN(C_8,2,0x000),
    DN(___,0,0x000),
    DN(C_6,1,0x000),
    DN(___,0,0x000),
};
static const unsigned char P106[] = {
    DN(C_5,8,0x000),
    DN(___,0,0x000),
    DN(C_5,8,0xC09),
    DN(___,0,0x000),
    DN(Ds5,8,0x000),
    DN(___,0,0x000),
    DN(Ds5,8,0xC09),
    DN(___,0,0x000),
    DN(As5,8,0x000),
    DN(___,0,0x000),
    DN(As5,8,0xC09),
    DN(___,0,0x000),
    DN(G_5,8,0x000),
    DN(___,0,0x000),
    DN(G_5,8,0xC09),
    DN(___,0,0x000),
    DN(A_5,8,0x000),
    DN(___,0,0x000),
    DN(A_5,8,0xC09),
    DN(___,0,0x000),
    DN(A_5,8,0xC07),
    DN(___,0,0x000),
    DN(A_5,8,0xC05),
    DN(___,0,0x000),
    DN(A_5,8,0xC03),
    DN(___,0,0x000),
    DN(A_5,8,0xC01),
    DN(___,0,0x000),
    DN(As5,8,0x000),
    DN(___,0,0x000),
    DN(As5,8,0xC09),
    DN(___,0,0x000),
    DN(C_6,8,0x000),
    DN(___,0,0x000),
    DN(C_6,8,0xC09),
    DN(___,0,0x000),
    DN(As5,8,0x000),
    DN(___,0,0x000),
    DN(As5,8,0xC09),
    DN(___,0,0x000),
    DN(A_5,8,0x000),
    DN(___,0,0x000),
    DN(A_5,8,0xC09),
    DN(___,0,0x000),
    DN(F_5,8,0x000),
    DN(___,0,0x000),
    DN(F_5,8,0xC09),
    DN(___,0,0x000),
    DN(G_5,8,0x000),
    DN(___,0,0x000),
    DN(G_5,8,0xC09),
    DN(___,0,0x000),
    DN(G_5,8,0xC07),
    DN(___,0,0x000),
    DN(G_5,8,0xC05),
    DN(___,0,0x000),
    DN(G_5,8,0xC03),
    DN(___,0,0x000),
    DN(G_5,8,0xC01),
    DN(___,0,0x000),
    DN(As5,8,0x000),
    DN(___,0,0x000),
    DN(As5,8,0xC09),
    DN(___,0,0x000),
};
static const unsigned char P107[] = {
    DN(C_6,8,0x000),
    DN(___,0,0x000),
    DN(C_6,8,0xC09),
    DN(___,0,0x000),
    DN(D_6,8,0x000),
    DN(___,0,0x000),
    DN(D_6,8,0xC09),
    DN(___,0,0x000),
    DN(C_6,8,0x000),
    DN(___,0,0x000),
    DN(C_6,8,0xC09),
    DN(___,0,0x000),
    DN(As5,8,0x000),
    DN(___,0,0x000),
    DN(As5,8,0xC09),
    DN(___,0,0x000),
    DN(A_5,8,0x000),
    DN(___,0,0x000),
    DN(A_5,8,0xC09),
    DN(___,0,0x000),
    DN(G_5,8,0x000),
    DN(___,0,0x000),
    DN(G_5,8,0xC09),
    DN(___,0,0x000),
    DN(F_5,8,0x000),
    DN(___,0,0x000),
    DN(F_5,8,0xC09),
    DN(___,0,0x000),
    DN(G_5,8,0x000),
    DN(___,0,0x000),
    DN(G_5,8,0xC09),
    DN(___,0,0x000),
    DN(C_6,8,0x000),
    DN(___,0,0x000),
    DN(C_6,8,0xC09),
    DN(___,0,0x000),
    DN(As5,8,0x000),
    DN(___,0,0x000),
    DN(As5,8,0xC09),
    DN(___,0,0x000),
    DN(A_5,8,0x000),
    DN(___,0,0x000),
    DN(A_5,8,0xC09),
    DN(___,0,0x000),
    DN(F_5,8,0x000),
    DN(___,0,0x000),
    DN(F_5,8,0xC09),
    DN(___,0,0x000),
    DN(G_5,8,0x000),
    DN(___,0,0x000),
    DN(G_5,8,0xC09),
    DN(___,0,0x000),
    DN(G_5,8,0xC07),
    DN(___,0,0x000),
    DN(G_5,8,0xC05),
    DN(___,0,0x000),
    DN(F_5,8,0x000),
    DN(___,0,0x000),
    DN(F_5,8,0xC07),
    DN(___,0,0x000),
    DN(F_5,8,0xC05),
    DN(___,0,0x000),
    DN(F_5,8,0xC03),
    DN(___,0,0x000),
};

static const unsigned char* const order1[] = {P0,P0,P0,P5,P0,P5,P9,P13,P0,P5,P0,P5,P9,P13};
static const unsigned char* const order2[] = {P1,P3,P1,P3,P10,P14,P1,P3,P1,P3,P10,P14,P106,P107};
static const unsigned char* const order3[] = {P2,P19,P2,P19,P2,P4,P22,P6,P2,P19,P2,P4,P22,P6};
static const unsigned char* const order4[] = {P1,P103,P104,P104,P100,P101,P1,P3,P104,P104,P100,P101,P3,P102};

static const unsigned char duty_instruments[] = {
8,0,240,128,
8,64,240,128,
8,128,240,128,
8,192,240,128,
8,0,241,128,
8,64,241,128,
8,128,241,128,
8,192,129,128,
8,128,240,128,
8,128,240,128,
8,128,240,128,
8,128,240,128,
8,128,240,128,
8,128,240,128,
8,128,240,128,
};
static const unsigned char wave_instruments[] = {
0,32,0,128,
0,32,1,128,
0,32,2,128,
0,32,3,128,
0,32,4,128,
0,32,5,128,
0,32,6,128,
0,32,7,128,
0,32,8,128,
0,32,9,128,
0,32,10,128,
0,32,11,128,
0,32,12,128,
0,32,13,128,
0,32,14,128,
};
static const unsigned char noise_instruments[] = {
247,118,9,4,3,0,0,0,
246,0,9,9,0,0,4,0,
240,104,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
};

static const unsigned char waves[] = {
    121,172,221,86,68,104,188,221,183,51,69,103,172,203,134,51,
    0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,
    0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,
    0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,
    0,1,18,35,52,69,86,103,120,137,154,171,188,205,222,239,
    254,220,186,152,118,84,50,16,18,52,86,120,154,188,222,255,
    122,205,219,117,33,19,104,189,220,151,65,1,71,156,221,184,
    15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
    254,252,250,248,246,244,242,240,242,244,246,248,250,252,254,255,
    254,221,204,187,170,153,136,119,138,189,241,36,87,138,189,238,
    132,17,97,237,87,71,90,173,206,163,23,121,221,32,3,71,
    40,59,1,226,235,78,74,115,137,73,112,56,116,189,59,56,
    122,106,44,17,55,217,94,59,92,30,76,48,185,85,145,204,
    142,200,84,161,56,203,108,37,199,169,69,192,110,133,52,52,
    139,173,123,46,64,35,151,195,73,73,139,80,61,188,139,134,
    89,44,210,90,181,186,116,43,109,125,227,173,219,177,227,226,
};

const hUGESong_t fight_theme = {6, &order_cnt, order1, order2, order3, order4, duty_instruments, wave_instruments, noise_instruments, NULL, waves};

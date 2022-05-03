#include "../lib/hUGEDriver.h"
#include <stddef.h>
#pragma bank 2
static const unsigned char order_cnt = 24;

static const unsigned char P0[] = {
    DN(C_4,8,0x000),
    DN(___,0,0x000),
    DN(C_4,8,0xC09),
    DN(___,0,0x000),
    DN(Ds4,8,0x000),
    DN(___,0,0x000),
    DN(Ds4,8,0xC09),
    DN(___,0,0x000),
    DN(As4,8,0x000),
    DN(___,0,0x000),
    DN(As4,8,0xC09),
    DN(___,0,0x000),
    DN(G_4,8,0x000),
    DN(___,0,0x000),
    DN(G_4,8,0xC09),
    DN(___,0,0x000),
    DN(A_4,8,0x000),
    DN(___,0,0x000),
    DN(A_4,8,0xC09),
    DN(___,0,0x000),
    DN(A_4,8,0xC07),
    DN(___,0,0x000),
    DN(A_4,8,0xC05),
    DN(___,0,0x000),
    DN(A_4,8,0xC03),
    DN(___,0,0x000),
    DN(A_4,8,0xC01),
    DN(___,0,0x000),
    DN(As4,8,0x000),
    DN(___,0,0x000),
    DN(As4,8,0xC09),
    DN(___,0,0x000),
    DN(C_5,8,0x000),
    DN(___,0,0x000),
    DN(C_5,8,0xC09),
    DN(___,0,0x000),
    DN(As4,8,0x000),
    DN(___,0,0x000),
    DN(As4,8,0xC09),
    DN(___,0,0x000),
    DN(A_4,8,0x000),
    DN(___,0,0x000),
    DN(A_4,8,0xC09),
    DN(___,0,0x000),
    DN(F_4,8,0x000),
    DN(___,0,0x000),
    DN(F_4,8,0xC09),
    DN(___,0,0x000),
    DN(G_4,8,0x000),
    DN(___,0,0x000),
    DN(G_4,8,0xC09),
    DN(___,0,0x000),
    DN(G_4,8,0xC07),
    DN(___,0,0x000),
    DN(G_4,8,0xC05),
    DN(___,0,0x000),
    DN(G_4,8,0xC03),
    DN(___,0,0x000),
    DN(G_4,8,0xC01),
    DN(___,0,0x000),
    DN(As4,8,0x000),
    DN(___,0,0x000),
    DN(As4,8,0xC09),
    DN(___,0,0x000),
};
static const unsigned char P1[] = {
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_6,7,0x000),
    DN(___,0,0x000),
    DN(G_6,7,0xC05),
    DN(___,0,0x000),
    DN(Ds6,7,0x000),
    DN(___,0,0x000),
    DN(Ds6,7,0xC05),
    DN(___,0,0x000),
    DN(D_6,7,0x000),
    DN(___,0,0x000),
    DN(D_6,7,0xC05),
    DN(___,0,0x000),
    DN(C_6,7,0x000),
    DN(___,0,0x000),
    DN(C_6,7,0xC05),
    DN(___,0,0x000),
    DN(As5,7,0x000),
    DN(___,0,0x000),
    DN(As5,7,0xC05),
    DN(___,0,0x000),
    DN(Gs5,7,0x000),
    DN(___,0,0x000),
    DN(Gs5,7,0xC05),
    DN(___,0,0x000),
    DN(C_6,7,0x000),
    DN(___,0,0x000),
    DN(C_6,7,0xC05),
    DN(___,0,0x000),
    DN(C_6,7,0xC03),
    DN(___,0,0x000),
    DN(C_6,7,0xC01),
    DN(___,0,0x000),
    DN(D_6,7,0x000),
    DN(___,0,0x000),
    DN(D_6,7,0xC05),
    DN(___,0,0x000),
    DN(D_6,7,0xC03),
    DN(___,0,0x000),
    DN(D_6,7,0xC01),
    DN(___,0,0x000),
    DN(As5,7,0x000),
    DN(___,0,0x000),
    DN(As5,7,0xC05),
    DN(___,0,0x000),
    DN(As5,7,0xC03),
    DN(___,0,0x000),
    DN(As5,7,0xC01),
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
static const unsigned char P6[] = {
    DN(C_5,8,0x000),
    DN(___,0,0x000),
    DN(C_5,8,0xC09),
    DN(___,0,0x000),
    DN(D_5,8,0x000),
    DN(___,0,0x000),
    DN(D_5,8,0xC09),
    DN(___,0,0x000),
    DN(C_5,8,0x000),
    DN(___,0,0x000),
    DN(C_5,8,0xC09),
    DN(___,0,0x000),
    DN(As4,8,0x000),
    DN(___,0,0x000),
    DN(As4,8,0xC09),
    DN(___,0,0x000),
    DN(A_4,8,0x000),
    DN(___,0,0x000),
    DN(A_4,8,0xC09),
    DN(___,0,0x000),
    DN(G_4,8,0x000),
    DN(___,0,0x000),
    DN(G_4,8,0xC09),
    DN(___,0,0x000),
    DN(F_4,8,0x000),
    DN(___,0,0x000),
    DN(F_4,8,0xC09),
    DN(___,0,0x000),
    DN(G_4,8,0x000),
    DN(___,0,0x000),
    DN(G_4,8,0xC09),
    DN(___,0,0x000),
    DN(C_5,8,0x000),
    DN(___,0,0x000),
    DN(C_5,8,0xC09),
    DN(___,0,0x000),
    DN(As4,8,0x000),
    DN(___,0,0x000),
    DN(As4,8,0xC09),
    DN(___,0,0x000),
    DN(A_4,8,0x000),
    DN(___,0,0x000),
    DN(A_4,8,0xC09),
    DN(___,0,0x000),
    DN(F_4,8,0x000),
    DN(___,0,0x000),
    DN(F_4,8,0xC09),
    DN(___,0,0x000),
    DN(G_4,8,0x000),
    DN(___,0,0x000),
    DN(G_4,8,0xC09),
    DN(___,0,0x000),
    DN(G_4,8,0xC07),
    DN(___,0,0x000),
    DN(G_4,8,0xC05),
    DN(___,0,0x000),
    DN(F_4,8,0x000),
    DN(___,0,0x000),
    DN(F_4,8,0xC07),
    DN(___,0,0x000),
    DN(F_4,8,0xC05),
    DN(___,0,0x000),
    DN(F_4,8,0xC03),
    DN(___,0,0x000),
};
static const unsigned char P7[] = {
    DN(Gs5,7,0x000),
    DN(___,0,0x000),
    DN(Gs5,7,0xC05),
    DN(___,0,0x000),
    DN(Gs5,7,0xC03),
    DN(___,0,0x000),
    DN(Gs5,7,0xC01),
    DN(___,0,0x000),
    DN(C_6,7,0x000),
    DN(___,0,0x000),
    DN(C_6,7,0xC05),
    DN(___,0,0x000),
    DN(Ds6,7,0x000),
    DN(___,0,0x000),
    DN(Ds6,7,0xC05),
    DN(___,0,0x000),
    DN(As5,7,0x000),
    DN(___,0,0x000),
    DN(As5,7,0xC05),
    DN(___,0,0x000),
    DN(As5,7,0xC03),
    DN(___,0,0x000),
    DN(As5,7,0xC01),
    DN(___,0,0x000),
    DN(As5,7,0x000),
    DN(___,0,0x000),
    DN(As5,7,0xC05),
    DN(___,0,0x000),
    DN(Ds6,7,0x000),
    DN(___,0,0x000),
    DN(Ds6,7,0xC05),
    DN(___,0,0x000),
    DN(Gs5,7,0x000),
    DN(___,0,0x000),
    DN(Gs5,7,0xC05),
    DN(___,0,0x000),
    DN(Gs5,7,0xC03),
    DN(___,0,0x000),
    DN(Gs5,7,0xC01),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_5,7,0x000),
    DN(___,0,0x000),
    DN(G_5,7,0xC05),
    DN(___,0,0x000),
    DN(As5,7,0x000),
    DN(___,0,0x000),
    DN(As5,7,0xC05),
    DN(___,0,0x000),
    DN(As5,7,0xC03),
    DN(___,0,0x000),
    DN(As5,7,0xC01),
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
static const unsigned char P10[] = {
    DN(C_5,8,0x000),
    DN(___,0,0x000),
    DN(C_5,8,0xC09),
    DN(___,0,0x000),
    DN(D_5,8,0x000),
    DN(___,0,0x000),
    DN(D_5,8,0xC09),
    DN(___,0,0x000),
    DN(C_5,8,0x000),
    DN(___,0,0x000),
    DN(C_5,8,0xC09),
    DN(___,0,0x000),
    DN(As4,8,0x000),
    DN(___,0,0x000),
    DN(As4,8,0xC09),
    DN(___,0,0x000),
    DN(A_4,8,0x000),
    DN(___,0,0x000),
    DN(A_4,8,0xC09),
    DN(___,0,0x000),
    DN(G_4,8,0x000),
    DN(___,0,0x000),
    DN(G_4,8,0xC09),
    DN(___,0,0x000),
    DN(F_4,8,0x000),
    DN(___,0,0x000),
    DN(F_4,8,0xC09),
    DN(___,0,0x000),
    DN(G_4,8,0x000),
    DN(___,0,0x000),
    DN(G_4,8,0xC09),
    DN(___,0,0x000),
    DN(C_5,8,0x000),
    DN(___,0,0x000),
    DN(C_5,8,0xC09),
    DN(___,0,0x000),
    DN(As4,8,0x000),
    DN(___,0,0x000),
    DN(As4,8,0xC09),
    DN(___,0,0x000),
    DN(G_4,8,0x000),
    DN(___,0,0x000),
    DN(G_4,8,0xC09),
    DN(___,0,0x000),
    DN(F_4,8,0x000),
    DN(___,0,0x000),
    DN(F_4,8,0xC09),
    DN(___,0,0x000),
    DN(G_4,8,0x000),
    DN(___,0,0x000),
    DN(G_4,8,0xC09),
    DN(___,0,0x000),
    DN(G_4,8,0xC07),
    DN(___,0,0x000),
    DN(G_4,8,0xC05),
    DN(___,0,0x000),
    DN(G_4,8,0xC03),
    DN(___,0,0x000),
    DN(G_4,8,0xC01),
    DN(___,0,0x000),
    DN(G_4,8,0x000),
    DN(___,0,0x000),
    DN(G_4,8,0xC09),
    DN(___,0,0x000),
};
static const unsigned char P11[] = {
    DN(Gs5,7,0x000),
    DN(___,0,0x000),
    DN(Gs5,7,0xC05),
    DN(___,0,0x000),
    DN(Gs5,7,0xC03),
    DN(___,0,0x000),
    DN(Gs5,7,0xC01),
    DN(___,0,0x000),
    DN(F_5,7,0x000),
    DN(___,0,0x000),
    DN(F_5,7,0xC05),
    DN(___,0,0x000),
    DN(Gs5,7,0x000),
    DN(___,0,0x000),
    DN(Gs5,7,0xC05),
    DN(___,0,0x000),
    DN(G_5,7,0x000),
    DN(___,0,0x000),
    DN(G_5,7,0xC05),
    DN(___,0,0x000),
    DN(G_5,7,0xC03),
    DN(___,0,0x000),
    DN(G_5,7,0xC01),
    DN(___,0,0x000),
    DN(As5,7,0x000),
    DN(___,0,0x000),
    DN(As5,7,0xC05),
    DN(___,0,0x000),
    DN(Ds6,7,0x000),
    DN(___,0,0x000),
    DN(Ds6,7,0xC05),
    DN(___,0,0x000),
    DN(Gs5,7,0x000),
    DN(___,0,0x000),
    DN(Gs5,7,0xC05),
    DN(___,0,0x000),
    DN(Gs5,7,0xC03),
    DN(___,0,0x000),
    DN(Gs5,7,0xC01),
    DN(___,0,0x000),
    DN(As5,7,0x000),
    DN(___,0,0x000),
    DN(As5,7,0xC05),
    DN(___,0,0x000),
    DN(Gs5,7,0x000),
    DN(___,0,0x000),
    DN(Gs5,7,0xC05),
    DN(___,0,0x000),
    DN(G_5,7,0x000),
    DN(___,0,0x000),
    DN(G_5,7,0xC05),
    DN(___,0,0x000),
    DN(G_5,7,0xC03),
    DN(___,0,0x000),
    DN(G_5,7,0xC01),
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
static const unsigned char P15[] = {
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_6,7,0x000),
    DN(___,0,0x000),
    DN(G_6,7,0xC05),
    DN(___,0,0x000),
    DN(Ds6,7,0x000),
    DN(___,0,0x000),
    DN(Ds6,7,0xC05),
    DN(___,0,0x000),
    DN(D_6,7,0x000),
    DN(___,0,0x000),
    DN(D_6,7,0xC05),
    DN(___,0,0x000),
    DN(C_6,7,0x000),
    DN(___,0,0x000),
    DN(C_6,7,0xC05),
    DN(___,0,0x000),
    DN(As5,7,0x000),
    DN(___,0,0x000),
    DN(As5,7,0xC05),
    DN(___,0,0x000),
    DN(Gs5,7,0x000),
    DN(___,0,0x000),
    DN(Gs5,7,0xC05),
    DN(___,0,0x000),
    DN(C_6,7,0x000),
    DN(___,0,0x000),
    DN(C_6,7,0xC05),
    DN(___,0,0x000),
    DN(D_6,7,0x000),
    DN(___,0,0x000),
    DN(D_6,7,0xC05),
    DN(___,0,0x000),
    DN(F_6,7,0x000),
    DN(___,0,0x000),
    DN(F_6,7,0xC05),
    DN(___,0,0x000),
    DN(D_6,7,0x000),
    DN(___,0,0x000),
    DN(D_6,7,0xC05),
    DN(___,0,0x000),
    DN(Ds6,7,0x000),
    DN(___,0,0x000),
    DN(Ds6,7,0xC05),
    DN(___,0,0x000),
    DN(Ds6,7,0xC03),
    DN(___,0,0x000),
    DN(Ds6,7,0xC01),
    DN(___,0,0x000),
    DN(D_6,7,0x000),
    DN(___,0,0x000),
    DN(D_6,7,0xC05),
    DN(___,0,0x000),
    DN(D_6,7,0xC03),
    DN(___,0,0x000),
    DN(D_6,7,0xC01),
    DN(___,0,0x000),
};
static const unsigned char P44[] = {
    DN(Gs3,0,0x000),
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
    DN(As3,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P48[] = {
    DN(C_4,14,0xC01),
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
    DN(D_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As3,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P60[] = {
    DN(C_4,14,0xC01),
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
    DN(D_4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Ds4,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As3,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P64[] = {
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0xC02),
    DN(___,0,0x000),
    DN(C_7,2,0xC00),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0xC02),
    DN(___,0,0x000),
    DN(C_7,2,0xC00),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(C_7,2,0xC06),
    DN(C_7,2,0xC07),
    DN(C_7,2,0xC05),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0xC02),
    DN(___,0,0x000),
    DN(C_7,2,0xC00),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0xC02),
    DN(___,0,0x000),
    DN(C_7,2,0xC00),
    DN(___,0,0x000),
    DN(Cs7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(C_7,2,0xC06),
    DN(C_7,2,0xC07),
    DN(C_7,2,0xC05),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
};
static const unsigned char P68[] = {
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0xC02),
    DN(___,0,0x000),
    DN(C_7,2,0xC00),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0xC02),
    DN(___,0,0x000),
    DN(C_7,2,0xC00),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0xC02),
    DN(___,0,0x000),
    DN(C_7,2,0xC00),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(C_7,2,0xC06),
    DN(C_7,2,0xC07),
    DN(C_7,2,0xC05),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0xC02),
    DN(___,0,0x000),
    DN(C_7,2,0xC00),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0xC06),
    DN(___,0,0x000),
    DN(C_7,2,0xC02),
    DN(___,0,0x000),
    DN(Cs7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(C_7,2,0xC06),
    DN(C_7,2,0xC07),
    DN(C_7,2,0xC05),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0xC06),
    DN(___,0,0x000),
};
static const unsigned char P69[] = {
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0xC02),
    DN(___,0,0x000),
    DN(C_7,2,0xC00),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0xC02),
    DN(___,0,0x000),
    DN(C_7,2,0xC00),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0xC02),
    DN(___,0,0x000),
    DN(C_7,2,0xC00),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(C_7,2,0xC06),
    DN(C_7,2,0xC07),
    DN(C_7,2,0xC05),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0xC02),
    DN(___,0,0x000),
    DN(C_7,2,0xC00),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0xC02),
    DN(___,0,0x000),
    DN(C_7,2,0xC00),
    DN(___,0,0x000),
    DN(Cs7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(C_7,2,0xC06),
    DN(C_7,2,0xC07),
    DN(C_7,2,0xC05),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
};
static const unsigned char P70[] = {
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0xC02),
    DN(___,0,0x000),
    DN(C_7,2,0xC00),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0xC02),
    DN(___,0,0x000),
    DN(C_7,2,0xC00),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0xC02),
    DN(___,0,0x000),
    DN(C_7,2,0xC00),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(C_7,2,0xC06),
    DN(C_7,2,0xC07),
    DN(C_7,2,0xC05),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0xC02),
    DN(___,0,0x000),
    DN(C_7,2,0xC00),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0xC06),
    DN(___,0,0x000),
    DN(C_7,2,0xC02),
    DN(___,0,0x000),
    DN(Cs7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0x000),
    DN(C_7,2,0xC06),
    DN(C_7,2,0xC07),
    DN(C_7,2,0xC05),
    DN(C_7,2,0x000),
    DN(___,0,0x000),
    DN(C_7,2,0xC04),
    DN(___,0,0x000),
    DN(C_7,2,0xC02),
    DN(___,0,0x000),
    DN(C_7,2,0xC00),
    DN(___,0,0xB09),
};

static const unsigned char* const order1[] = {P0,P6,P0,P10,P0,P6,P0,P10,P0,P6,P0,P10};
static const unsigned char* const order2[] = {P1,P7,P15,P11,P1,P7,P15,P11,P1,P7,P15,P11};
static const unsigned char* const order3[] = {P2,P3,P3,P3,P48,P44,P60,P44,P48,P44,P60,P44};
static const unsigned char* const order4[] = {P3,P3,P3,P3,P3,P3,P3,P3,P64,P68,P69,P70};

static const unsigned char duty_instruments[] = {
8,42,242,128,
8,64,240,128,
8,128,240,128,
8,192,240,128,
8,0,241,128,
8,64,241,128,
14,150,114,192,
8,192,209,128,
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
195,0,0,0,0,0,0,0,
119,118,249,4,9,252,4,254,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
161,0,0,0,0,0,0,0,
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
    0,0,185,139,221,222,221,221,204,186,170,170,171,220,102,255,
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
    58,217,218,197,197,77,178,120,55,217,214,40,124,51,227,194,
    132,141,154,64,156,57,66,222,230,198,89,154,202,3,50,77,
    133,212,153,141,71,199,8,115,211,202,149,192,18,195,25,16,
    80,90,78,225,146,60,168,228,201,96,177,97,179,165,171,53,
    123,232,84,235,188,193,237,75,236,36,219,217,40,32,77,51,
};

const hUGESong_t title_theme = {5, &order_cnt, order1, order2, order3,order4, duty_instruments, wave_instruments, noise_instruments, NULL, waves};

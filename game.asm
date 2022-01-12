;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.6 #12439 (Linux)
;--------------------------------------------------------
	.module game
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _draw
	.globl _logic
	.globl _input
	.globl _set_sprite_data
	.globl _heart
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_heart::
	.ds 16
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;game.c:15: void input() {
;	---------------------------------
; Function input
; ---------------------------------
_input::
;game.c:18: }
	ret
;game.c:20: void logic() {
;	---------------------------------
; Function logic
; ---------------------------------
_logic::
;game.c:23: }
	ret
;game.c:25: void draw() {
;	---------------------------------
; Function draw
; ---------------------------------
_draw::
;game.c:29: set_sprite_data(0, 1, heart);
	ld	de, #_heart
	push	de
	xor	a, a
	inc	a
	push	af
	call	_set_sprite_data
	add	sp, #4
;/home/brandanc/Downloads/gbdk/include/gb/gb.h:1174: shadow_OAM[nb].tile=tile;
	ld	hl, #(_shadow_OAM + 2)
	ld	(hl), #0x00
;/home/brandanc/Downloads/gbdk/include/gb/gb.h:1247: OAM_item_t * itm = &shadow_OAM[nb];
	ld	hl, #_shadow_OAM
;/home/brandanc/Downloads/gbdk/include/gb/gb.h:1248: itm->y=y, itm->x=x;
	ld	a, #0x48
	ld	(hl+), a
	ld	(hl), #0x50
;game.c:35: SHOW_SPRITES;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x02
	ldh	(_LCDC_REG + 0), a
;game.c:36: }
	ret
;game.c:38: void main() {
;	---------------------------------
; Function main
; ---------------------------------
_main::
;game.c:39: draw();
;game.c:40: }
	jp	_draw
	.area _CODE
	.area _INITIALIZER
__xinit__heart:
	.db #0x66	; 102	'f'
	.db #0x66	; 102	'f'
	.db #0x99	; 153
	.db #0xff	; 255
	.db #0x81	; 129
	.db #0xff	; 255
	.db #0x81	; 129
	.db #0xff	; 255
	.db #0x42	; 66	'B'
	.db #0x7e	; 126
	.db #0x24	; 36
	.db #0x3c	; 60
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x00	; 0
	.db #0x00	; 0
	.area _CABS (ABS)

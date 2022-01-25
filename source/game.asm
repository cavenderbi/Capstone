;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.6 #12539 (Linux)
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
	.globl _wait_vbl_done
	.globl _joypad
	.globl _walkcycle
	.globl _heart
	.globl _y
	.globl _x
	.globl _dir
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
_dir::
	.ds 1
_x::
	.ds 1
_y::
	.ds 1
_draw_frame_count_65536_109:
	.ds 2
_draw_anim_count_65536_109:
	.ds 2
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_heart::
	.ds 32
_walkcycle::
	.ds 64
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
;game.c:36: static int frame_count = 0;
	xor	a, a
	ld	hl, #_draw_frame_count_65536_109
	ld	(hl+), a
	ld	(hl), a
;game.c:37: static int anim_count = 0;
	xor	a, a
	ld	hl, #_draw_anim_count_65536_109
	ld	(hl+), a
	ld	(hl), a
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;game.c:14: void input() {
;	---------------------------------
; Function input
; ---------------------------------
_input::
;game.c:15: uint8_t j = joypad();
	call	_joypad
	ld	c, e
;game.c:17: if (j & J_UP)
	bit	2, c
	jr	Z, 00110$
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1415: OAM_item_t * itm = &shadow_OAM[nb];
	ld	bc, #_shadow_OAM+0
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1416: itm->y+=y, itm->x+=x;
	ld	a, (bc)
	dec	a
	ld	(bc), a
	inc	bc
	ld	a, (bc)
	ld	(bc), a
;game.c:18: scroll_sprite(0, 0, -1);
	ret
00110$:
;game.c:19: else if (j & J_DOWN)
	bit	3, c
	jr	Z, 00107$
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1415: OAM_item_t * itm = &shadow_OAM[nb];
	ld	bc, #_shadow_OAM+0
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1416: itm->y+=y, itm->x+=x;
	ld	a, (bc)
	inc	a
	ld	(bc), a
	inc	bc
	ld	a, (bc)
	ld	(bc), a
;game.c:20: scroll_sprite(0, 0, 1);
	ret
00107$:
;game.c:21: else if (j & J_LEFT)
	bit	1, c
	jr	Z, 00104$
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1415: OAM_item_t * itm = &shadow_OAM[nb];
	ld	bc, #_shadow_OAM+0
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1416: itm->y+=y, itm->x+=x;
	ld	a, (bc)
	ld	(bc), a
	inc	bc
	ld	a, (bc)
	dec	a
	ld	(bc), a
;game.c:22: scroll_sprite(0, -1, 0);
	ret
00104$:
;game.c:23: else if (j & J_RIGHT)
	bit	0, c
	ret	Z
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1415: OAM_item_t * itm = &shadow_OAM[nb];
	ld	bc, #_shadow_OAM+0
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1416: itm->y+=y, itm->x+=x;
	ld	a, (bc)
	ld	(bc), a
	inc	bc
	ld	a, (bc)
	inc	a
	ld	(bc), a
;game.c:24: scroll_sprite(0, 1, 0);
;game.c:26: }
	ret
;game.c:28: void logic() {
;	---------------------------------
; Function logic
; ---------------------------------
_logic::
;game.c:30: }
	ret
;game.c:34: void draw() {
;	---------------------------------
; Function draw
; ---------------------------------
_draw::
	dec	sp
	dec	sp
;game.c:35: unsigned char anim_tiles[2] = {0, 1};
	ldhl	sp,	#0
	ld	c, l
	ld	b, h
	xor	a, a
	ld	(bc), a
	ld	l, c
;	spillPairReg hl
;	spillPairReg hl
	ld	h, b
;	spillPairReg hl
;	spillPairReg hl
	inc	hl
	ld	(hl), #0x01
;game.c:39: frame_count++;
	ld	hl, #_draw_frame_count_65536_109
	inc	(hl)
	jr	NZ, 00111$
	inc	hl
	inc	(hl)
00111$:
;game.c:40: if (frame_count >= FRAMES_ANIM_UPDATE) {
	ld	hl, #_draw_frame_count_65536_109
	ld	a, (hl+)
	sub	a, #0x0a
	ld	a, (hl)
	sbc	a, #0x00
	ld	d, (hl)
	ld	a, #0x00
	bit	7,a
	jr	Z, 00112$
	bit	7, d
	jr	NZ, 00113$
	cp	a, a
	jr	00113$
00112$:
	bit	7, d
	jr	Z, 00113$
	scf
00113$:
	jr	C, 00104$
;game.c:41: frame_count = 0;
	xor	a, a
	ld	hl, #_draw_frame_count_65536_109
	ld	(hl+), a
	ld	(hl), a
;game.c:42: anim_count = !anim_count;
	ld	hl, #_draw_anim_count_65536_109 + 1
	ld	a, (hl-)
	or	a, (hl)
	sub	a,#0x01
	ld	a, #0x00
	rla
	ld	(hl+), a
;game.c:43: set_sprite_tile(0, anim_tiles[anim_count]);
	xor	a, a
	ld	(hl-), a
	ld	a, c
	add	a, (hl)
	inc	hl
	ld	c, a
	ld	a, b
	adc	a, (hl)
	ld	b, a
	ld	a, (bc)
	ld	c, a
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1326: shadow_OAM[nb].tile=tile;
	ld	hl, #(_shadow_OAM + 2)
	ld	(hl), c
;game.c:43: set_sprite_tile(0, anim_tiles[anim_count]);
00104$:
;game.c:45: }
	inc	sp
	inc	sp
	ret
;game.c:47: void main() {
;	---------------------------------
; Function main
; ---------------------------------
_main::
;game.c:48: set_sprite_data(0, 2, heart);
	ld	de, #_heart
	push	de
	ld	hl, #0x200
	push	hl
	call	_set_sprite_data
	add	sp, #4
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1326: shadow_OAM[nb].tile=tile;
	ld	hl, #(_shadow_OAM + 2)
	ld	(hl), #0x00
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1399: OAM_item_t * itm = &shadow_OAM[nb];
	ld	hl, #_shadow_OAM
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1400: itm->y=y, itm->x=x;
	ld	a, #0x4e
	ld	(hl+), a
	ld	(hl), #0x58
;game.c:53: SHOW_SPRITES;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x02
	ldh	(_LCDC_REG + 0), a
;game.c:55: while (true) {
00102$:
;game.c:56: input();
	call	_input
;game.c:57: logic();
	call	_logic
;game.c:58: draw();
	call	_draw
;game.c:59: wait_vbl_done();
	call	_wait_vbl_done
;game.c:62: }
	jr	00102$
	.area _CODE
	.area _INITIALIZER
__xinit__heart:
	.db #0x6c	; 108	'l'
	.db #0x6c	; 108	'l'
	.db #0x9e	; 158
	.db #0xf2	; 242
	.db #0x86	; 134
	.db #0xfa	; 250
	.db #0x44	; 68	'D'
	.db #0x7c	; 124
	.db #0x28	; 40
	.db #0x38	; 56	'8'
	.db #0x10	; 16
	.db #0x10	; 16
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x6c	; 108	'l'
	.db #0x6c	; 108	'l'
	.db #0x92	; 146
	.db #0xf2	; 242
	.db #0x82	; 130
	.db #0xf2	; 242
	.db #0x44	; 68	'D'
	.db #0x74	; 116	't'
	.db #0x28	; 40
	.db #0x38	; 56	'8'
	.db #0x10	; 16
	.db #0x10	; 16
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
__xinit__walkcycle:
	.db #0x07	; 7
	.db #0x07	; 7
	.db #0x1f	; 31
	.db #0x18	; 24
	.db #0x1f	; 31
	.db #0x10	; 16
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0x3f	; 63
	.db #0x20	; 32
	.db #0x1f	; 31
	.db #0x10	; 16
	.db #0x1f	; 31
	.db #0x18	; 24
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0x09	; 9
	.db #0x0f	; 15
	.db #0x09	; 9
	.db #0x0f	; 15
	.db #0x09	; 9
	.db #0x0f	; 15
	.db #0x07	; 7
	.db #0x07	; 7
	.db #0x08	; 8
	.db #0x08	; 8
	.db #0x1c	; 28
	.db #0x1c	; 28
	.db #0x80	; 128
	.db #0x80	; 128
	.db #0xe0	; 224
	.db #0x60	; 96
	.db #0xe0	; 224
	.db #0x20	; 32
	.db #0xf0	; 240
	.db #0x90	; 144
	.db #0xf0	; 240
	.db #0x90	; 144
	.db #0xf0	; 240
	.db #0x10	; 16
	.db #0xf0	; 240
	.db #0x10	; 16
	.db #0xe0	; 224
	.db #0x20	; 32
	.db #0xe0	; 224
	.db #0x60	; 96
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x40	; 64
	.db #0xc0	; 192
	.db #0x40	; 64
	.db #0xc0	; 192
	.db #0x40	; 64
	.db #0xc0	; 192
	.db #0xa0	; 160
	.db #0xa0	; 160
	.db #0x60	; 96
	.db #0x60	; 96
	.db #0xc0	; 192
	.db #0xc0	; 192
	.area _CABS (ABS)

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
	.globl _shoot
	.globl _initPlayer
	.globl _fadein
	.globl _fadeout
	.globl _show_title
	.globl _set_sprite_palette
	.globl _set_sprite_data
	.globl _set_win_tiles
	.globl _set_win_data
	.globl _set_bkg_tiles
	.globl _set_bkg_data
	.globl _wait_vbl_done
	.globl _waitpad
	.globl _joypad
	.globl _test_tilemap
	.globl _test_data
	.globl _hud_tilemap
	.globl _hud_data
	.globl _test_enemy
	.globl _test_projectile
	.globl _arrow
	.globl _projectile
	.globl _player
	.globl _test_title_map
	.globl _test_title_data
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
_player::
	.ds 6
_projectile::
	.ds 5
_draw_frame_count_65536_183:
	.ds 2
_draw_anim_count_65536_183:
	.ds 2
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_arrow::
	.ds 128
_test_projectile::
	.ds 64
_test_enemy::
	.ds 16
_hud_data::
	.ds 320
_hud_tilemap::
	.ds 40
_test_data::
	.ds 144
_test_tilemap::
	.ds 320
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
;game.c:130: static int frame_count = 0;
	xor	a, a
	ld	hl, #_draw_frame_count_65536_183
	ld	(hl+), a
	ld	(hl), a
;game.c:131: static int anim_count = 0;
	xor	a, a
	ld	hl, #_draw_anim_count_65536_183
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
;title_screen.c:6: void show_title() {
;	---------------------------------
; Function show_title
; ---------------------------------
_show_title::
;title_screen.c:8: set_bkg_data(0, 137, test_title_data);
	ld	de, #_test_title_data
	push	de
	ld	hl, #0x8900
	push	hl
	call	_set_bkg_data
	add	sp, #4
;title_screen.c:9: set_bkg_tiles(0, 0, 20, 18, test_title_map);
	ld	de, #_test_title_map
	push	de
	ld	hl, #0x1214
	push	hl
	xor	a, a
	rrca
	push	af
	call	_set_bkg_tiles
	add	sp, #6
;title_screen.c:11: SHOW_BKG;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x01
	ldh	(_LCDC_REG + 0), a
;title_screen.c:12: DISPLAY_ON;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x80
	ldh	(_LCDC_REG + 0), a
;title_screen.c:14: waitpad(J_START);
	ld	a, #0x80
	push	af
	inc	sp
	call	_waitpad
	inc	sp
;title_screen.c:15: }
	ret
_test_title_data:
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x3f	; 63
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xc1	; 193
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x1f	; 31
	.db #0xff	; 255
	.db #0x3f	; 63
	.db #0xff	; 255
	.db #0x7c	; 124
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x1f	; 31
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x0e	; 14
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xc1	; 193
	.db #0xff	; 255
	.db #0x81	; 129
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x81	; 129
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x1e	; 30
	.db #0xff	; 255
	.db #0x3c	; 60
	.db #0xff	; 255
	.db #0x7c	; 124
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x78	; 120	'x'
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x7e	; 126
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x0e	; 14
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x1f	; 31
	.db #0xff	; 255
	.db #0x1f	; 31
	.db #0xff	; 255
	.db #0x1d	; 29
	.db #0xff	; 255
	.db #0x3c	; 60
	.db #0xff	; 255
	.db #0x1f	; 31
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xfd	; 253
	.db #0xff	; 255
	.db #0xf1	; 241
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0xfe	; 254
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xdf	; 223
	.db #0xff	; 255
	.db #0xcf	; 207
	.db #0xff	; 255
	.db #0xc3	; 195
	.db #0xff	; 255
	.db #0x81	; 129
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x81	; 129
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0x3f	; 63
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe1	; 225
	.db #0xff	; 255
	.db #0xe1	; 225
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x0e	; 14
	.db #0xff	; 255
	.db #0x0e	; 14
	.db #0xff	; 255
	.db #0x0e	; 14
	.db #0xff	; 255
	.db #0x0e	; 14
	.db #0xff	; 255
	.db #0x1e	; 30
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xe7	; 231
	.db #0xff	; 255
	.db #0x81	; 129
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0x3c	; 60
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0x70	; 112	'p'
	.db #0xff	; 255
	.db #0x78	; 120	'x'
	.db #0xff	; 255
	.db #0x78	; 120	'x'
	.db #0xff	; 255
	.db #0x3e	; 62
	.db #0xff	; 255
	.db #0x3f	; 63
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x87	; 135
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xfe	; 254
	.db #0xff	; 255
	.db #0x7c	; 124
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xe3	; 227
	.db #0xff	; 255
	.db #0xf7	; 247
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x3e	; 62
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf9	; 249
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x1e	; 30
	.db #0xff	; 255
	.db #0x3f	; 63
	.db #0xff	; 255
	.db #0x3f	; 63
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0xfb	; 251
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x1f	; 31
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x1f	; 31
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x70	; 112	'p'
	.db #0xff	; 255
	.db #0x70	; 112	'p'
	.db #0xff	; 255
	.db #0x70	; 112	'p'
	.db #0xff	; 255
	.db #0x78	; 120	'x'
	.db #0xff	; 255
	.db #0x78	; 120	'x'
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x1f	; 31
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0xc1	; 193
	.db #0xff	; 255
	.db #0xf3	; 243
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x78	; 120	'x'
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x78	; 120	'x'
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x78	; 120	'x'
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x0e	; 14
	.db #0xff	; 255
	.db #0x0e	; 14
	.db #0xff	; 255
	.db #0x0e	; 14
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x3f	; 63
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x78	; 120	'x'
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x0e	; 14
	.db #0xff	; 255
	.db #0x1e	; 30
	.db #0xff	; 255
	.db #0x1e	; 30
	.db #0xff	; 255
	.db #0x3c	; 60
	.db #0xff	; 255
	.db #0x3c	; 60
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x1c	; 28
	.db #0xff	; 255
	.db #0x1c	; 28
	.db #0xff	; 255
	.db #0x1c	; 28
	.db #0xff	; 255
	.db #0x3c	; 60
	.db #0xff	; 255
	.db #0x7c	; 124
	.db #0xff	; 255
	.db #0x78	; 120	'x'
	.db #0xff	; 255
	.db #0x70	; 112	'p'
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x0e	; 14
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x78	; 120	'x'
	.db #0xff	; 255
	.db #0x78	; 120	'x'
	.db #0xff	; 255
	.db #0x70	; 112	'p'
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x78	; 120	'x'
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x81	; 129
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x3f	; 63
	.db #0xff	; 255
	.db #0xfe	; 254
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0x70	; 112	'p'
	.db #0xff	; 255
	.db #0x70	; 112	'p'
	.db #0xff	; 255
	.db #0x70	; 112	'p'
	.db #0xff	; 255
	.db #0x70	; 112	'p'
	.db #0xff	; 255
	.db #0xf1	; 241
	.db #0xff	; 255
	.db #0xf3	; 243
	.db #0xff	; 255
	.db #0xf7	; 247
	.db #0xff	; 255
	.db #0xef	; 239
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xfe	; 254
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0x3f	; 63
	.db #0xff	; 255
	.db #0x1f	; 31
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0x78	; 120	'x'
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x70	; 112	'p'
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x3f	; 63
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x3f	; 63
	.db #0xff	; 255
	.db #0xfe	; 254
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x71	; 113	'q'
	.db #0xff	; 255
	.db #0x71	; 113	'q'
	.db #0xff	; 255
	.db #0x71	; 113	'q'
	.db #0xff	; 255
	.db #0x71	; 113	'q'
	.db #0xff	; 255
	.db #0x71	; 113	'q'
	.db #0xff	; 255
	.db #0x70	; 112	'p'
	.db #0xff	; 255
	.db #0x70	; 112	'p'
	.db #0xff	; 255
	.db #0x70	; 112	'p'
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xfb	; 251
	.db #0xff	; 255
	.db #0xf9	; 249
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x81	; 129
	.db #0xff	; 255
	.db #0x81	; 129
	.db #0xff	; 255
	.db #0x83	; 131
	.db #0xff	; 255
	.db #0xc7	; 199
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xfe	; 254
	.db #0xff	; 255
	.db #0x78	; 120	'x'
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x1f	; 31
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x1f	; 31
	.db #0xff	; 255
	.db #0x3f	; 63
	.db #0xff	; 255
	.db #0x3e	; 62
	.db #0xff	; 255
	.db #0x3e	; 62
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xfe	; 254
	.db #0xff	; 255
	.db #0xfe	; 254
	.db #0xff	; 255
	.db #0x7e	; 126
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xf7	; 247
	.db #0xff	; 255
	.db #0xe7	; 231
	.db #0xff	; 255
	.db #0x87	; 135
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xc1	; 193
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x78	; 120	'x'
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x3f	; 63
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x81	; 129
	.db #0xff	; 255
	.db #0x83	; 131
	.db #0xff	; 255
	.db #0x83	; 131
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x7e	; 126
	.db #0xff	; 255
	.db #0xfe	; 254
	.db #0xff	; 255
	.db #0xfe	; 254
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x3e	; 62
	.db #0xff	; 255
	.db #0x7e	; 126
	.db #0xff	; 255
	.db #0x7e	; 126
	.db #0xff	; 255
	.db #0x7c	; 124
	.db #0xff	; 255
	.db #0x7e	; 126
	.db #0xff	; 255
	.db #0x1f	; 31
	.db #0xff	; 255
	.db #0x3f	; 63
	.db #0xff	; 255
	.db #0x1f	; 31
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x3f	; 63
	.db #0xff	; 255
	.db #0x1e	; 30
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x70	; 112	'p'
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x3c	; 60
	.db #0xff	; 255
	.db #0x7c	; 124
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xc3	; 195
	.db #0xff	; 255
	.db #0xc3	; 195
	.db #0xff	; 255
	.db #0xc3	; 195
	.db #0xff	; 255
	.db #0xe3	; 227
	.db #0xff	; 255
	.db #0xe3	; 227
	.db #0xff	; 255
	.db #0xe3	; 227
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x80	; 128
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x1f	; 31
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x83	; 131
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0x7c	; 124
	.db #0xff	; 255
	.db #0x3c	; 60
	.db #0xff	; 255
	.db #0x3c	; 60
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0x07	; 7
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x1e	; 30
	.db #0xff	; 255
	.db #0x3e	; 62
	.db #0xff	; 255
	.db #0xfe	; 254
	.db #0xff	; 255
	.db #0xfe	; 254
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x78	; 120	'x'
	.db #0xff	; 255
	.db #0x78	; 120	'x'
	.db #0xff	; 255
	.db #0x38	; 56	'8'
	.db #0xff	; 255
	.db #0x3c	; 60
	.db #0xff	; 255
	.db #0x3c	; 60
	.db #0xff	; 255
	.db #0x1c	; 28
	.db #0xff	; 255
	.db #0x1c	; 28
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xfe	; 254
	.db #0xff	; 255
	.db #0xfc	; 252
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xf0	; 240
	.db #0xff	; 255
	.db #0xf8	; 248
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x7f	; 127
	.db #0xff	; 255
	.db #0x1f	; 31
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xc0	; 192
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xe0	; 224
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0xff	; 255
_test_title_map:
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x01	; 1
	.db #0x02	; 2
	.db #0x03	; 3
	.db #0x04	; 4
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x05	; 5
	.db #0x06	; 6
	.db #0x07	; 7
	.db #0x08	; 8
	.db #0x09	; 9
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x0a	; 10
	.db #0x0b	; 11
	.db #0x0c	; 12
	.db #0x0d	; 13
	.db #0x00	; 0
	.db #0x0e	; 14
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x0f	; 15
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x10	; 16
	.db #0x11	; 17
	.db #0x12	; 18
	.db #0x13	; 19
	.db #0x14	; 20
	.db #0x15	; 21
	.db #0x16	; 22
	.db #0x17	; 23
	.db #0x18	; 24
	.db #0x19	; 25
	.db #0x00	; 0
	.db #0x1a	; 26
	.db #0x1b	; 27
	.db #0x1c	; 28
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x1d	; 29
	.db #0x00	; 0
	.db #0x1e	; 30
	.db #0x1f	; 31
	.db #0x20	; 32
	.db #0x21	; 33
	.db #0x22	; 34
	.db #0x23	; 35
	.db #0x24	; 36
	.db #0x25	; 37
	.db #0x26	; 38
	.db #0x27	; 39
	.db #0x28	; 40
	.db #0x29	; 41
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x2a	; 42
	.db #0x00	; 0
	.db #0x2b	; 43
	.db #0x2c	; 44
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x2d	; 45
	.db #0x2e	; 46
	.db #0x2f	; 47
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x30	; 48	'0'
	.db #0x31	; 49	'1'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x32	; 50	'2'
	.db #0x33	; 51	'3'
	.db #0x34	; 52	'4'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x35	; 53	'5'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x36	; 54	'6'
	.db #0x37	; 55	'7'
	.db #0x00	; 0
	.db #0x38	; 56	'8'
	.db #0x00	; 0
	.db #0x39	; 57	'9'
	.db #0x3a	; 58
	.db #0x3b	; 59
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x3c	; 60
	.db #0x3d	; 61
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x3e	; 62
	.db #0x3f	; 63
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0x01	; 1
	.db #0x41	; 65	'A'
	.db #0x42	; 66	'B'
	.db #0x43	; 67	'C'
	.db #0x00	; 0
	.db #0x44	; 68	'D'
	.db #0x45	; 69	'E'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x46	; 70	'F'
	.db #0x2f	; 47
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x47	; 71	'G'
	.db #0x00	; 0
	.db #0x48	; 72	'H'
	.db #0x49	; 73	'I'
	.db #0x4a	; 74	'J'
	.db #0x4b	; 75	'K'
	.db #0x4c	; 76	'L'
	.db #0x4d	; 77	'M'
	.db #0x4e	; 78	'N'
	.db #0x4f	; 79	'O'
	.db #0x50	; 80	'P'
	.db #0x00	; 0
	.db #0x01	; 1
	.db #0x51	; 81	'Q'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x52	; 82	'R'
	.db #0x53	; 83	'S'
	.db #0x54	; 84	'T'
	.db #0x55	; 85	'U'
	.db #0x56	; 86	'V'
	.db #0x57	; 87	'W'
	.db #0x58	; 88	'X'
	.db #0x59	; 89	'Y'
	.db #0x5a	; 90	'Z'
	.db #0x5b	; 91
	.db #0x5c	; 92
	.db #0x5d	; 93
	.db #0x5e	; 94
	.db #0x5f	; 95
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x60	; 96
	.db #0x61	; 97	'a'
	.db #0x62	; 98	'b'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x63	; 99	'c'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x64	; 100	'd'
	.db #0x65	; 101	'e'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x66	; 102	'f'
	.db #0x67	; 103	'g'
	.db #0x68	; 104	'h'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x69	; 105	'i'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x6a	; 106	'j'
	.db #0x6b	; 107	'k'
	.db #0x6c	; 108	'l'
	.db #0x6d	; 109	'm'
	.db #0x6e	; 110	'n'
	.db #0x6f	; 111	'o'
	.db #0x70	; 112	'p'
	.db #0x71	; 113	'q'
	.db #0x00	; 0
	.db #0x72	; 114	'r'
	.db #0x73	; 115	's'
	.db #0x74	; 116	't'
	.db #0x75	; 117	'u'
	.db #0x42	; 66	'B'
	.db #0x76	; 118	'v'
	.db #0x77	; 119	'w'
	.db #0x78	; 120	'x'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x79	; 121	'y'
	.db #0x7a	; 122	'z'
	.db #0x7b	; 123
	.db #0x7c	; 124
	.db #0x7d	; 125
	.db #0x7e	; 126
	.db #0x7f	; 127
	.db #0x00	; 0
	.db #0x80	; 128
	.db #0x81	; 129
	.db #0x82	; 130
	.db #0x83	; 131
	.db #0x84	; 132
	.db #0x85	; 133
	.db #0x86	; 134
	.db #0x87	; 135
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x88	; 136
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
;title_screen.c:17: void fadeout() {
;	---------------------------------
; Function fadeout
; ---------------------------------
_fadeout::
;title_screen.c:18: for (uint8_t i = 0; i < 4; i++) { 
	ld	c, #0x00
00112$:
;title_screen.c:19: switch (i) {
	ld	a,c
	cp	a,#0x04
	ret	NC
	or	a, a
	jr	Z, 00101$
	ld	a, c
	dec	a
	jr	Z, 00102$
	ld	a,c
	cp	a,#0x02
	jr	Z, 00103$
	sub	a, #0x03
	jr	Z, 00104$
	jr	00122$
;title_screen.c:20: case 0: 
00101$:
;title_screen.c:21: BGP_REG = 0xE4;
	ld	a, #0xe4
	ldh	(_BGP_REG + 0), a
;title_screen.c:22: break;
	jr	00122$
;title_screen.c:23: case 1:
00102$:
;title_screen.c:24: BGP_REG = 0xF9;
	ld	a, #0xf9
	ldh	(_BGP_REG + 0), a
;title_screen.c:25: break;
	jr	00122$
;title_screen.c:26: case 2:
00103$:
;title_screen.c:27: BGP_REG = 0xFE;
	ld	a, #0xfe
	ldh	(_BGP_REG + 0), a
;title_screen.c:28: break;
	jr	00122$
;title_screen.c:29: case 3:
00104$:
;title_screen.c:30: BGP_REG = 0xFF;
	ld	a, #0xff
	ldh	(_BGP_REG + 0), a
;title_screen.c:33: for (uint8_t i = 0; i < 20; i++)
00122$:
	ld	b, #0x00
00109$:
	ld	a, b
	sub	a, #0x14
	jr	NC, 00113$
;title_screen.c:34: wait_vbl_done();
	call	_wait_vbl_done
;title_screen.c:33: for (uint8_t i = 0; i < 20; i++)
	inc	b
	jr	00109$
00113$:
;title_screen.c:18: for (uint8_t i = 0; i < 4; i++) { 
	inc	c
;title_screen.c:36: }
	jr	00112$
;title_screen.c:38: void fadein() {
;	---------------------------------
; Function fadein
; ---------------------------------
_fadein::
;title_screen.c:39: for (uint8_t i = 0; i < 3; i++) {
	ld	c, #0x00
00111$:
;title_screen.c:40: switch (i) {
	ld	a,c
	cp	a,#0x03
	ret	NC
	or	a, a
	jr	Z, 00101$
	ld	a, c
	dec	a
	jr	Z, 00102$
	ld	a, c
	sub	a, #0x02
	jr	Z, 00103$
	jr	00120$
;title_screen.c:41: case 0: 
00101$:
;title_screen.c:42: BGP_REG = 0xFE;
	ld	a, #0xfe
	ldh	(_BGP_REG + 0), a
;title_screen.c:43: break;
	jr	00120$
;title_screen.c:44: case 1:
00102$:
;title_screen.c:45: BGP_REG = 0xF9;
	ld	a, #0xf9
	ldh	(_BGP_REG + 0), a
;title_screen.c:46: break;
	jr	00120$
;title_screen.c:47: case 2:
00103$:
;title_screen.c:48: BGP_REG = 0xE4;
	ld	a, #0xe4
	ldh	(_BGP_REG + 0), a
;title_screen.c:51: for (uint8_t i = 0; i < 20; i++)
00120$:
	ld	b, #0x00
00108$:
	ld	a, b
	sub	a, #0x14
	jr	NC, 00112$
;title_screen.c:52: wait_vbl_done();
	call	_wait_vbl_done
;title_screen.c:51: for (uint8_t i = 0; i < 20; i++)
	inc	b
	jr	00108$
00112$:
;title_screen.c:39: for (uint8_t i = 0; i < 3; i++) {
	inc	c
;title_screen.c:54: }
	jr	00111$
;game.c:47: void initPlayer() {
;	---------------------------------
; Function initPlayer
; ---------------------------------
_initPlayer::
;game.c:48: player.x = 88;
	ld	hl, #_player
	ld	(hl), #0x58
;game.c:49: player.y = 78;
	ld	hl, #(_player + 1)
	ld	(hl), #0x4e
;game.c:50: player.dir = RIGHT;
	ld	hl, #(_player + 2)
	ld	(hl), #0x03
;game.c:51: player.maxHealth = 4;
	ld	hl, #(_player + 3)
	ld	(hl), #0x04
;game.c:52: player.health = 4;
	ld	hl, #(_player + 4)
	ld	(hl), #0x04
;game.c:53: player.alive = true;
	ld	hl, #(_player + 5)
	ld	(hl), #0x01
;game.c:54: }
	ret
;game.c:57: void shoot(uint8_t x, uint8_t y, Direction dir) {
;	---------------------------------
; Function shoot
; ---------------------------------
_shoot::
;game.c:58: projectile.x = x;
	ld	de, #_projectile
	ldhl	sp,	#2
;game.c:59: projectile.y = y;
	ld	a, (hl+)
	ld	(de), a
	ld	de, #(_projectile + 1)
;game.c:60: projectile.dir = dir;
	ld	a, (hl+)
	ld	(de), a
	ld	de, #(_projectile + 2)
	ld	a, (hl)
	ld	(de), a
;game.c:61: projectile.alive = true;
	ld	hl, #(_projectile + 4)
	ld	(hl), #0x01
;game.c:62: move_sprite(1, x, y);
	ldhl	sp,	#3
	ld	a, (hl-)
	ld	b, a
	ld	c, (hl)
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1399: OAM_item_t * itm = &shadow_OAM[nb];
	ld	hl, #(_shadow_OAM + 4)
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1400: itm->y=y, itm->x=x;
	ld	a, b
	ld	(hl+), a
	ld	(hl), c
;game.c:62: move_sprite(1, x, y);
;game.c:63: }
	ret
;game.c:75: void input() {
;	---------------------------------
; Function input
; ---------------------------------
_input::
	add	sp, #-8
;game.c:76: UBYTE j = joypad();
	call	_joypad
	ldhl	sp,	#0
	ld	(hl), e
;game.c:77: if (j & J_UP) {
	push	hl
	bit	2, (hl)
	pop	hl
	jp	Z,00118$
;game.c:78: player.dir = UP;
	ld	bc, #_player + 2
	xor	a, a
	ld	(bc), a
;game.c:79: if (collision(player.x, player.y - 1))
	ld	a, (#(_player + 1) + 0)
	ldhl	sp,#1
	ld	(hl), a
	dec	a
	ldhl	sp,	#6
	ld	(hl), a
	ld	a, (#_player + 0)
	ldhl	sp,	#7
	ld	(hl), a
;game.c:67: if (player.dir == DOWN || player.dir == RIGHT) {
	ld	a, (bc)
	ldhl	sp,	#5
	ld	(hl), a
	dec	a
	jr	Z, 00123$
	ldhl	sp,	#5
	ld	a, (hl)
	sub	a, #0x03
	jr	NZ, 00124$
00123$:
;game.c:68: x += 7;
	ldhl	sp,	#7
	ld	a, (hl)
	add	a, #0x07
;game.c:69: y += 7;
	ld	(hl-), a
	ld	a, (hl)
	add	a, #0x07
	ld	(hl), a
00124$:
;game.c:71: return test_tilemap[(((y - 16) / 8) * 20) + ((x - 8) / 8)] == 0x15;
	ldhl	sp,	#6
	ld	a, (hl)
	ldhl	sp,	#3
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0010
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#6
	ld	(hl-), a
	ld	(hl), e
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	bit	7, (hl)
	jr	Z, 00140$
	dec	hl
	dec	hl
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0xfff7
	add	hl, de
	ld	c, l
	ld	b, h
00140$:
	sra	b
	rr	c
	sra	b
	rr	c
	sra	b
	rr	c
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	push	hl
	ld	a, l
	ldhl	sp,	#4
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#3
	ld	(hl), a
	ldhl	sp,	#7
	ld	a, (hl)
	ldhl	sp,	#4
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0008
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#7
	ld	(hl-), a
	ld	(hl), e
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	bit	7, (hl)
	jr	Z, 00141$
	dec	hl
	dec	hl
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0xffff
	add	hl, de
	ld	c, l
	ld	b, h
00141$:
	sra	b
	rr	c
	sra	b
	rr	c
	sra	b
	rr	c
	ldhl	sp,	#2
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	ld	bc,#_test_tilemap
	add	hl,bc
	ld	a, (hl)
	sub	a, #0x15
	jp	NZ,00119$
;game.c:79: if (collision(player.x, player.y - 1))
;game.c:80: player.y--;
	ldhl	sp,	#1
	ld	a, (hl)
	dec	a
	ld	hl, #(_player + 1)
	ld	(hl), a
	jp	00119$
00118$:
;game.c:81: } else if (j & J_DOWN) {
	push	hl
	ldhl	sp,	#2
	bit	3, (hl)
	pop	hl
	jp	Z,00115$
;game.c:82: player.dir = DOWN;
	ld	hl, #(_player + 2)
	ld	(hl), #0x01
;game.c:83: if(collision(player.x, player.y + 1))
	ld	a, (#(_player + 1) + 0)
	ldhl	sp,#1
	ld	(hl), a
	ld	c, (hl)
	inc	c
	ld	a, (#_player + 0)
	ldhl	sp,	#7
	ld	(hl), a
;game.c:67: if (player.dir == DOWN || player.dir == RIGHT) {
	ld	a, (#(_player + 2) + 0)
	cp	a, #0x01
	jr	Z, 00127$
	sub	a, #0x03
	jr	NZ, 00128$
00127$:
;game.c:68: x += 7;
	ldhl	sp,	#7
	ld	a, (hl)
	add	a, #0x07
	ld	(hl), a
;game.c:69: y += 7;
	ld	a, c
	add	a, #0x07
	ld	c, a
00128$:
;game.c:71: return test_tilemap[(((y - 16) / 8) * 20) + ((x - 8) / 8)] == 0x15;
	ldhl	sp,	#3
	ld	a, c
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0010
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#6
	ld	(hl-), a
	ld	(hl), e
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	bit	7, (hl)
	jr	Z, 00142$
	dec	hl
	dec	hl
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0xfff7
	add	hl, de
	ld	c, l
	ld	b, h
00142$:
	sra	b
	rr	c
	sra	b
	rr	c
	sra	b
	rr	c
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	push	hl
	ld	a, l
	ldhl	sp,	#4
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#3
	ld	(hl), a
	ldhl	sp,	#7
	ld	a, (hl)
	ldhl	sp,	#4
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0008
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#7
	ld	(hl-), a
	ld	(hl), e
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	bit	7, (hl)
	jr	Z, 00143$
	dec	hl
	dec	hl
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0xffff
	add	hl, de
	ld	c, l
	ld	b, h
00143$:
	sra	b
	rr	c
	sra	b
	rr	c
	sra	b
	rr	c
	ldhl	sp,	#2
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	ld	bc,#_test_tilemap
	add	hl,bc
	ld	a, (hl)
	sub	a, #0x15
	jp	NZ,00119$
;game.c:83: if(collision(player.x, player.y + 1))
;game.c:84: player.y++;
	ldhl	sp,	#1
	ld	a, (hl)
	inc	a
	ld	hl, #(_player + 1)
	ld	(hl), a
	jp	00119$
00115$:
;game.c:85: } else if (j & J_LEFT) {
	push	hl
	ldhl	sp,	#2
	bit	1, (hl)
	pop	hl
	jp	Z,00112$
;game.c:86: player.dir = LEFT;
	ld	hl, #(_player + 2)
	ld	(hl), #0x02
;game.c:87: if (collision(player.x - 1, player.y))
	ld	hl, #_player + 1
	ld	c, (hl)
	ld	a, (#_player + 0)
	ldhl	sp,#1
	ld	(hl), a
	dec	a
	ldhl	sp,	#7
	ld	(hl), a
;game.c:67: if (player.dir == DOWN || player.dir == RIGHT) {
	ld	hl, #(_player + 2)
	ld	b, (hl)
	ld	a, b
	dec	a
	jr	Z, 00131$
	ld	a, b
	sub	a, #0x03
	jr	NZ, 00132$
00131$:
;game.c:68: x += 7;
	ldhl	sp,	#7
	ld	a, (hl)
	add	a, #0x07
	ld	(hl), a
;game.c:69: y += 7;
	ld	a, c
	add	a, #0x07
	ld	c, a
00132$:
;game.c:71: return test_tilemap[(((y - 16) / 8) * 20) + ((x - 8) / 8)] == 0x15;
	ldhl	sp,	#3
	ld	a, c
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0010
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#6
	ld	(hl-), a
	ld	(hl), e
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	bit	7, (hl)
	jr	Z, 00144$
	dec	hl
	dec	hl
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0xfff7
	add	hl, de
	ld	c, l
	ld	b, h
00144$:
	sra	b
	rr	c
	sra	b
	rr	c
	sra	b
	rr	c
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	push	hl
	ld	a, l
	ldhl	sp,	#4
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#3
	ld	(hl), a
	ldhl	sp,	#7
	ld	a, (hl)
	ldhl	sp,	#4
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0008
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#7
	ld	(hl-), a
	ld	(hl), e
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	bit	7, (hl)
	jr	Z, 00145$
	dec	hl
	dec	hl
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0xffff
	add	hl, de
	ld	c, l
	ld	b, h
00145$:
	sra	b
	rr	c
	sra	b
	rr	c
	sra	b
	rr	c
	ldhl	sp,	#2
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	ld	bc,#_test_tilemap
	add	hl,bc
	ld	a, (hl)
	sub	a, #0x15
	jp	NZ,00119$
;game.c:87: if (collision(player.x - 1, player.y))
;game.c:88: player.x--;
	ldhl	sp,	#1
	ld	a, (hl)
	dec	a
	ld	hl, #_player
	ld	(hl), a
	jp	00119$
00112$:
;game.c:89: } else if (j & J_RIGHT) {
	push	hl
	ldhl	sp,	#2
	bit	0, (hl)
	pop	hl
	jp	Z,00119$
;game.c:90: player.dir = RIGHT;
	ld	hl, #(_player + 2)
	ld	(hl), #0x03
;game.c:91: if (collision(player.x + 1, player.y))
	ld	hl, #_player + 1
	ld	c, (hl)
	ld	a, (#_player + 0)
	ldhl	sp,#1
	ld	(hl), a
	inc	a
	ldhl	sp,	#7
	ld	(hl), a
;game.c:67: if (player.dir == DOWN || player.dir == RIGHT) {
	ld	hl, #(_player + 2)
	ld	b, (hl)
	ld	a, b
	dec	a
	jr	Z, 00135$
	ld	a, b
	sub	a, #0x03
	jr	NZ, 00136$
00135$:
;game.c:68: x += 7;
	ldhl	sp,	#7
	ld	a, (hl)
	add	a, #0x07
	ld	(hl), a
;game.c:69: y += 7;
	ld	a, c
	add	a, #0x07
	ld	c, a
00136$:
;game.c:71: return test_tilemap[(((y - 16) / 8) * 20) + ((x - 8) / 8)] == 0x15;
	ldhl	sp,	#3
	ld	a, c
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0010
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#6
	ld	(hl-), a
	ld	(hl), e
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	bit	7, (hl)
	jr	Z, 00146$
	dec	hl
	dec	hl
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0xfff7
	add	hl, de
	ld	c, l
	ld	b, h
00146$:
	sra	b
	rr	c
	sra	b
	rr	c
	sra	b
	rr	c
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	push	hl
	ld	a, l
	ldhl	sp,	#4
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#3
	ld	(hl), a
	ldhl	sp,	#7
	ld	a, (hl)
	ldhl	sp,	#4
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0008
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#7
	ld	(hl-), a
	ld	(hl), e
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	bit	7, (hl)
	jr	Z, 00147$
	dec	hl
	dec	hl
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0xffff
	add	hl, de
	ld	c, l
	ld	b, h
00147$:
	sra	b
	rr	c
	sra	b
	rr	c
	sra	b
	rr	c
	ldhl	sp,	#2
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	ld	bc,#_test_tilemap
	add	hl,bc
	ld	a, (hl)
	sub	a, #0x15
	jr	NZ, 00119$
;game.c:91: if (collision(player.x + 1, player.y))
;game.c:92: player.x++;
	ldhl	sp,	#1
	ld	a, (hl)
	inc	a
	ld	hl, #_player
	ld	(hl), a
00119$:
;game.c:96: if (j & J_A) 
	push	hl
	ldhl	sp,	#2
	bit	4, (hl)
	pop	hl
	jr	Z, 00138$
;game.c:97: shoot(player.x, player.y, player.dir);
	ld	hl, #(_player + 2)
	ld	c, (hl)
	ld	hl, #(_player + 1)
	ld	b, (hl)
	ld	a, (#_player + 0)
	ld	h, c
;	spillPairReg hl
;	spillPairReg hl
	ld	l, b
	push	hl
	push	af
	inc	sp
	call	_shoot
	add	sp, #3
00138$:
;game.c:98: }
	add	sp, #8
	ret
;game.c:100: void logic() {
;	---------------------------------
; Function logic
; ---------------------------------
_logic::
	add	sp, #-7
;game.c:102: switch (projectile.dir) {
	ld	a, (#(_projectile + 2) + 0)
	ldhl	sp,	#4
	ld	(hl), a
;game.c:104: if (collision(projectile.x, projectile.y - 1))
	ld	a, (#_projectile + 0)
	ldhl	sp,	#0
	ld	(hl), a
	ld	a, (#(_projectile + 1) + 0)
	ldhl	sp,#6
	ld	(hl), a
	ld	a, (hl-)
;game.c:102: switch (projectile.dir) {
	ld	(hl-), a
	ld	a, (hl)
	or	a, a
	jr	Z, 00101$
	ldhl	sp,	#4
	ld	a, (hl)
	dec	a
	jp	Z,00104$
;game.c:112: if (collision(projectile.x - 1, projectile.y))
	ldhl	sp,	#0
	ld	c, (hl)
;game.c:102: switch (projectile.dir) {
	ldhl	sp,	#4
	ld	a, (hl)
	sub	a, #0x02
	jp	Z,00107$
	ldhl	sp,	#4
	ld	a, (hl)
	sub	a, #0x03
	jp	Z,00110$
	jp	00113$
;game.c:103: case UP:
00101$:
;game.c:104: if (collision(projectile.x, projectile.y - 1))
	ldhl	sp,	#5
	ld	a, (hl-)
	dec	a
	ld	(hl), a
	ldhl	sp,	#0
	ld	a, (hl)
	ldhl	sp,	#5
	ld	(hl), a
;game.c:67: if (player.dir == DOWN || player.dir == RIGHT) {
	ld	a, (#(_player + 2) + 0)
	ldhl	sp,#3
	ld	(hl), a
	ld	a, (hl)
	dec	a
	jr	Z, 00117$
	ldhl	sp,	#3
	ld	a, (hl)
	sub	a, #0x03
	jr	NZ, 00118$
00117$:
;game.c:68: x += 7;
	ldhl	sp,	#5
	ld	a, (hl)
	add	a, #0x07
;game.c:69: y += 7;
	ld	(hl-), a
	ld	a, (hl)
	add	a, #0x07
	ld	(hl), a
00118$:
;game.c:71: return test_tilemap[(((y - 16) / 8) * 20) + ((x - 8) / 8)] == 0x15;
	ldhl	sp,	#4
	ld	a, (hl-)
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0010
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#2
	ld	(hl-), a
	ld	(hl), e
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	bit	7, (hl)
	jr	Z, 00139$
	inc	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0xfff7
	add	hl, de
	ld	c, l
	ld	b, h
00139$:
	sra	b
	rr	c
	sra	b
	rr	c
	sra	b
	rr	c
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	push	hl
	ld	a, l
	ldhl	sp,	#4
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#3
	ld	(hl+), a
	inc	hl
	ld	a, (hl-)
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0008
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#1
	ld	(hl-), a
	ld	a, e
	ld	(hl+), a
	pop	bc
	push	bc
	bit	7, (hl)
	jr	Z, 00140$
	ldhl	sp,#4
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0xffff
	add	hl, de
	ld	c, l
	ld	b, h
00140$:
	sra	b
	rr	c
	sra	b
	rr	c
	sra	b
	rr	c
	ldhl	sp,	#2
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	ld	bc,#_test_tilemap
	add	hl,bc
	ld	a, (hl)
	sub	a, #0x15
	jp	NZ,00113$
;game.c:104: if (collision(projectile.x, projectile.y - 1))
;game.c:105: projectile.y--;
	ldhl	sp,	#6
	ld	a, (hl)
	dec	a
	ld	(#(_projectile + 1)),a
;game.c:106: break;
	jp	00113$
;game.c:107: case DOWN:
00104$:
;game.c:108: if (collision(projectile.x, projectile.y + 1))
	ldhl	sp,	#5
	ld	c, (hl)
	inc	c
	ldhl	sp,	#0
	ld	a, (hl)
	ldhl	sp,	#5
	ld	(hl), a
;game.c:67: if (player.dir == DOWN || player.dir == RIGHT) {
	ld	a, (#(_player + 2) + 0)
	cp	a, #0x01
	jr	Z, 00121$
	sub	a, #0x03
	jr	NZ, 00122$
00121$:
;game.c:68: x += 7;
	ldhl	sp,	#5
	ld	a, (hl)
	add	a, #0x07
	ld	(hl), a
;game.c:69: y += 7;
	ld	a, c
	add	a, #0x07
	ld	c, a
00122$:
;game.c:71: return test_tilemap[(((y - 16) / 8) * 20) + ((x - 8) / 8)] == 0x15;
	ldhl	sp,	#1
	ld	a, c
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0010
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#4
	ld	(hl-), a
	ld	(hl), e
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	bit	7, (hl)
	jr	Z, 00141$
	dec	hl
	dec	hl
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0xfff7
	add	hl, de
	ld	c, l
	ld	b, h
00141$:
	sra	b
	rr	c
	sra	b
	rr	c
	sra	b
	rr	c
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	inc	sp
	inc	sp
	push	hl
	ldhl	sp,	#5
	ld	a, (hl)
	ldhl	sp,	#2
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0008
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#5
	ld	(hl-), a
	ld	(hl), e
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	bit	7, (hl)
	jr	Z, 00142$
	dec	hl
	dec	hl
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0xffff
	add	hl, de
	ld	c, l
	ld	b, h
00142$:
	sra	b
	rr	c
	sra	b
	rr	c
	sra	b
	rr	c
	pop	hl
	push	hl
	add	hl, bc
	ld	bc,#_test_tilemap
	add	hl,bc
	ld	a, (hl)
	sub	a, #0x15
	jp	NZ,00113$
;game.c:108: if (collision(projectile.x, projectile.y + 1))
;game.c:109: projectile.y++;
	ldhl	sp,	#6
	ld	a, (hl)
	inc	a
	ld	(#(_projectile + 1)),a
;game.c:110: break;
	jp	00113$
;game.c:111: case LEFT:
00107$:
;game.c:112: if (collision(projectile.x - 1, projectile.y))
	ldhl	sp,	#6
	ld	e, (hl)
	ld	a, c
	dec	a
	ld	(hl), a
	ld	c, e
;game.c:67: if (player.dir == DOWN || player.dir == RIGHT) {
	ld	de, #_player+2
	ld	a, (de)
	ld	e, a
	dec	a
	jr	Z, 00125$
	ld	a, e
	sub	a, #0x03
	jr	NZ, 00126$
00125$:
;game.c:68: x += 7;
	ldhl	sp,	#6
	ld	a, (hl)
	add	a, #0x07
	ld	(hl), a
;game.c:69: y += 7;
	ld	a, c
	add	a, #0x07
	ld	c, a
00126$:
;game.c:71: return test_tilemap[(((y - 16) / 8) * 20) + ((x - 8) / 8)] == 0x15;
	ldhl	sp,	#2
	ld	a, c
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0010
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#5
	ld	(hl-), a
	ld	(hl), e
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	bit	7, (hl)
	jr	Z, 00143$
	dec	hl
	dec	hl
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0xfff7
	add	hl, de
	ld	c, l
	ld	b, h
00143$:
	sra	b
	rr	c
	sra	b
	rr	c
	sra	b
	rr	c
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	push	hl
	ld	a, l
	ldhl	sp,	#3
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#2
	ld	(hl), a
	ldhl	sp,	#6
	ld	a, (hl)
	ldhl	sp,	#3
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0008
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#6
	ld	(hl-), a
	ld	(hl), e
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	bit	7, (hl)
	jr	Z, 00144$
	dec	hl
	dec	hl
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0xffff
	add	hl, de
	ld	c, l
	ld	b, h
00144$:
	sra	b
	rr	c
	sra	b
	rr	c
	sra	b
	rr	c
	ldhl	sp,	#1
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	ld	bc,#_test_tilemap
	add	hl,bc
	ld	a, (hl)
	sub	a, #0x15
	jp	NZ,00113$
;game.c:112: if (collision(projectile.x - 1, projectile.y))
;game.c:113: projectile.x--;
	ldhl	sp,	#0
	ld	a, (hl)
	dec	a
	ld	(#_projectile),a
;game.c:114: break;
	jp	00113$
;game.c:115: case RIGHT:
00110$:
;game.c:116: if (collision(projectile.x + 1, projectile.y))
	ldhl	sp,	#6
	ld	e, (hl)
	ld	a, c
	inc	a
	ld	(hl), a
	ld	c, e
;game.c:67: if (player.dir == DOWN || player.dir == RIGHT) {
	ld	de, #_player+2
	ld	a, (de)
	ld	e, a
	dec	a
	jr	Z, 00129$
	ld	a, e
	sub	a, #0x03
	jr	NZ, 00130$
00129$:
;game.c:68: x += 7;
	ldhl	sp,	#6
	ld	a, (hl)
	add	a, #0x07
	ld	(hl), a
;game.c:69: y += 7;
	ld	a, c
	add	a, #0x07
	ld	c, a
00130$:
;game.c:71: return test_tilemap[(((y - 16) / 8) * 20) + ((x - 8) / 8)] == 0x15;
	ldhl	sp,	#2
	ld	a, c
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0010
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#5
	ld	(hl-), a
	ld	(hl), e
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	bit	7, (hl)
	jr	Z, 00145$
	dec	hl
	dec	hl
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0xfff7
	add	hl, de
	ld	c, l
	ld	b, h
00145$:
	sra	b
	rr	c
	sra	b
	rr	c
	sra	b
	rr	c
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	push	hl
	ld	a, l
	ldhl	sp,	#3
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#2
	ld	(hl), a
	ldhl	sp,	#6
	ld	a, (hl)
	ldhl	sp,	#3
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0008
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#6
	ld	(hl-), a
	ld	(hl), e
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	bit	7, (hl)
	jr	Z, 00146$
	dec	hl
	dec	hl
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0xffff
	add	hl, de
	ld	c, l
	ld	b, h
00146$:
	sra	b
	rr	c
	sra	b
	rr	c
	sra	b
	rr	c
	ldhl	sp,	#1
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	ld	bc,#_test_tilemap
	add	hl,bc
	ld	a, (hl)
	sub	a, #0x15
	jr	NZ, 00113$
;game.c:116: if (collision(projectile.x + 1, projectile.y))
;game.c:117: projectile.x++;
	ldhl	sp,	#0
	ld	a, (hl)
	inc	a
	ld	(#_projectile),a
;game.c:119: }
00113$:
;game.c:120: if (!collision(projectile.x, projectile.y)){
	ld	hl, #(_projectile + 1)
	ld	c, (hl)
	ld	a, (#_projectile + 0)
	ldhl	sp,	#6
	ld	(hl), a
;game.c:67: if (player.dir == DOWN || player.dir == RIGHT) {
	ld	a, (#(_player + 2) + 0)
	cp	a, #0x01
	jr	Z, 00133$
	sub	a, #0x03
	jr	NZ, 00134$
00133$:
;game.c:68: x += 7;
	ldhl	sp,	#6
	ld	a, (hl)
	add	a, #0x07
	ld	(hl), a
;game.c:69: y += 7;
	ld	a, c
	add	a, #0x07
	ld	c, a
00134$:
;game.c:71: return test_tilemap[(((y - 16) / 8) * 20) + ((x - 8) / 8)] == 0x15;
	ldhl	sp,	#2
	ld	a, c
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0010
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#5
	ld	(hl-), a
	ld	(hl), e
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	bit	7, (hl)
	jr	Z, 00147$
	dec	hl
	dec	hl
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0xfff7
	add	hl, de
	ld	c, l
	ld	b, h
00147$:
	sra	b
	rr	c
	sra	b
	rr	c
	sra	b
	rr	c
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	push	hl
	ld	a, l
	ldhl	sp,	#3
	ld	(hl), a
	pop	hl
	ld	a, h
	ldhl	sp,	#2
	ld	(hl), a
	ldhl	sp,	#6
	ld	a, (hl)
	ldhl	sp,	#3
	ld	(hl+), a
	xor	a, a
	ld	(hl-), a
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0x0008
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ldhl	sp,	#6
	ld	(hl-), a
	ld	(hl), e
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	bit	7, (hl)
	jr	Z, 00148$
	dec	hl
	dec	hl
	dec	hl
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	ld	hl, #0xffff
	add	hl, de
	ld	c, l
	ld	b, h
00148$:
	sra	b
	rr	c
	sra	b
	rr	c
	sra	b
	rr	c
	ldhl	sp,	#1
	ld	a,	(hl+)
	ld	h, (hl)
	ld	l, a
	add	hl, bc
	ld	bc,#_test_tilemap
	add	hl,bc
	ld	c, l
	ld	b, h
	ld	a, (bc)
	sub	a, #0x15
	jr	Z, 00137$
;game.c:120: if (!collision(projectile.x, projectile.y)){
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1425: shadow_OAM[nb].y = 0;
	ld	hl, #(_shadow_OAM + 4)
	ld	(hl), #0x00
;game.c:122: projectile.alive = false;
	ld	hl, #(_projectile + 4)
	ld	(hl), #0x00
00137$:
;game.c:124: }
	add	sp, #7
	ret
;game.c:128: void draw() {
;	---------------------------------
; Function draw
; ---------------------------------
_draw::
	add	sp, #-3
;game.c:129: unsigned char anim_tiles[2] = {0, 1};
	ldhl	sp,	#0
	ld	c, l
	ld	b, h
	xor	a, a
	ld	(bc), a
	inc	bc
	ld	a, #0x01
	ld	(bc), a
;game.c:133: frame_count++;
	ld	hl, #_draw_frame_count_65536_183
	inc	(hl)
	jr	NZ, 00177$
	inc	hl
	inc	(hl)
00177$:
;game.c:134: if (frame_count >= FRAMES_ANIM_UPDATE) {
	ld	hl, #_draw_frame_count_65536_183
	ld	a, (hl+)
	sub	a, #0x0a
	ld	a, (hl)
	sbc	a, #0x00
	ld	d, (hl)
	ld	a, #0x00
	bit	7,a
	jr	Z, 00178$
	bit	7, d
	jr	NZ, 00179$
	cp	a, a
	jr	00179$
00178$:
	bit	7, d
	jr	Z, 00179$
	scf
00179$:
	jr	C, 00102$
;game.c:135: frame_count = 0;
	xor	a, a
	ld	hl, #_draw_frame_count_65536_183
	ld	(hl+), a
	ld	(hl), a
;game.c:136: anim_count = !anim_count;
	ld	hl, #_draw_anim_count_65536_183 + 1
	ld	a, (hl-)
	or	a, (hl)
	sub	a,#0x01
	ld	a, #0x00
	rla
	ld	(hl+), a
	ld	(hl), #0x00
00102$:
;game.c:138: switch (player.dir) {
	ld	a, (#(_player + 2) + 0)
	or	a, a
	jr	Z, 00103$
;game.c:143: set_sprite_tile(0, anim_count + 4);
	ld	hl, #_draw_anim_count_65536_183
	ld	c, (hl)
;game.c:138: switch (player.dir) {
	cp	a, #0x01
	jr	Z, 00104$
	cp	a, #0x02
	jr	Z, 00105$
	sub	a, #0x03
	jr	Z, 00106$
	jr	00107$
;game.c:139: case UP:
00103$:
;game.c:140: set_sprite_tile(0, anim_count);
	ld	hl, #_draw_anim_count_65536_183
	ld	c, (hl)
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1326: shadow_OAM[nb].tile=tile;
	ld	hl, #(_shadow_OAM + 2)
	ld	(hl), c
;game.c:141: break;
	jr	00107$
;game.c:142: case DOWN:
00104$:
;game.c:143: set_sprite_tile(0, anim_count + 4);
	inc	c
	inc	c
	inc	c
	inc	c
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1326: shadow_OAM[nb].tile=tile;
	ld	hl, #(_shadow_OAM + 2)
	ld	(hl), c
;game.c:144: break;
	jr	00107$
;game.c:145: case LEFT:
00105$:
;game.c:146: set_sprite_tile(0, anim_count + 6);
	ld	a, c
	add	a, #0x06
	ld	c, a
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1326: shadow_OAM[nb].tile=tile;
	ld	hl, #(_shadow_OAM + 2)
	ld	(hl), c
;game.c:147: break;
	jr	00107$
;game.c:148: case RIGHT:
00106$:
;game.c:149: set_sprite_tile(0, anim_count + 2);
	inc	c
	inc	c
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1326: shadow_OAM[nb].tile=tile;
	ld	hl, #(_shadow_OAM + 2)
	ld	(hl), c
;game.c:151: }
00107$:
;game.c:153: switch (projectile.dir) {
	ld	a, (#(_projectile + 2) + 0)
	or	a, a
	jr	Z, 00108$
	cp	a, #0x01
	jr	Z, 00109$
	cp	a, #0x02
	jr	Z, 00110$
	sub	a, #0x03
	jr	Z, 00111$
	jr	00112$
;game.c:154: case UP:
00108$:
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1326: shadow_OAM[nb].tile=tile;
	ld	hl, #(_shadow_OAM + 6)
	ld	(hl), #0x0b
;game.c:156: break;
	jr	00112$
;game.c:157: case DOWN:
00109$:
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1326: shadow_OAM[nb].tile=tile;
	ld	hl, #(_shadow_OAM + 6)
	ld	(hl), #0x09
;game.c:159: break;
	jr	00112$
;game.c:160: case LEFT:
00110$:
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1326: shadow_OAM[nb].tile=tile;
	ld	hl, #(_shadow_OAM + 6)
	ld	(hl), #0x0a
;game.c:162: break;
	jr	00112$
;game.c:163: case RIGHT:
00111$:
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1326: shadow_OAM[nb].tile=tile;
	ld	hl, #(_shadow_OAM + 6)
	ld	(hl), #0x08
;game.c:166: }
00112$:
;game.c:168: move_sprite(0, player.x, player.y);
	ld	hl, #(_player + 1)
	ld	c, (hl)
	ld	hl, #_player
	ld	b, (hl)
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1399: OAM_item_t * itm = &shadow_OAM[nb];
	ld	hl, #_shadow_OAM
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1400: itm->y=y, itm->x=x;
	ld	a, c
	ld	(hl+), a
	ld	(hl), b
;game.c:169: if (projectile.alive)
	ld	hl, #(_projectile + 4)
	bit	0, (hl)
	jr	Z, 00114$
;game.c:170: move_sprite(1, projectile.x, projectile.y);
	ld	a, (#(_projectile + 1) + 0)
	ldhl	sp,	#2
	ld	(hl), a
	ld	hl, #_projectile
	ld	c, (hl)
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1399: OAM_item_t * itm = &shadow_OAM[nb];
	ld	de, #(_shadow_OAM + 4)
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1400: itm->y=y, itm->x=x;
	ldhl	sp,	#2
	ld	a, (hl)
	ld	(de), a
	inc	de
	ld	a, c
	ld	(de), a
;game.c:170: move_sprite(1, projectile.x, projectile.y);
00114$:
;game.c:172: wait_vbl_done();
	call	_wait_vbl_done
;game.c:173: }
	add	sp, #3
	ret
;game.c:175: void main() {
;	---------------------------------
; Function main
; ---------------------------------
_main::
	add	sp, #-4
;game.c:176: show_title();
	call	_show_title
;game.c:178: const unsigned char arrow_palette[] =  {0, RGB_RED, RGB_LIGHTGRAY, RGB_BLACK};
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
	ld	(hl), #0x1f
	ld	l, c
;	spillPairReg hl
;	spillPairReg hl
	ld	h, b
;	spillPairReg hl
;	spillPairReg hl
	inc	hl
	inc	hl
	ld	(hl), #0xb5
	ld	e, c
	ld	d, b
	inc	de
	inc	de
	inc	de
	xor	a, a
	ld	(de), a
;game.c:179: set_sprite_palette(0, 8, arrow_palette);
	push	bc
	ld	hl, #0x800
	push	hl
	call	_set_sprite_palette
	add	sp, #4
;game.c:180: set_sprite_data(0, 8, arrow);
	ld	de, #_arrow
	push	de
	ld	hl, #0x800
	push	hl
	call	_set_sprite_data
	add	sp, #4
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1326: shadow_OAM[nb].tile=tile;
	ld	hl, #(_shadow_OAM + 2)
	ld	(hl), #0x00
;game.c:183: set_sprite_data(8, 4, test_projectile);
	ld	de, #_test_projectile
	push	de
	ld	hl, #0x408
	push	hl
	call	_set_sprite_data
	add	sp, #4
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1326: shadow_OAM[nb].tile=tile;
	ld	hl, #(_shadow_OAM + 6)
	ld	(hl), #0x09
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1425: shadow_OAM[nb].y = 0;
	ld	hl, #(_shadow_OAM + 4)
	ld	(hl), #0x00
;game.c:186: set_sprite_data(13, 1, test_enemy);
	ld	de, #_test_enemy
	push	de
	ld	hl, #0x10d
	push	hl
	call	_set_sprite_data
	add	sp, #4
;game.c:188: initPlayer();
	call	_initPlayer
;game.c:189: move_sprite(0, player.x, player.y);
	ld	hl, #_player + 1
	ld	b, (hl)
	ld	hl, #_player
	ld	c, (hl)
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1399: OAM_item_t * itm = &shadow_OAM[nb];
	ld	hl, #_shadow_OAM
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1400: itm->y=y, itm->x=x;
	ld	a, b
	ld	(hl+), a
	ld	(hl), c
;game.c:191: set_bkg_data(21, 9, test_data);
	ld	de, #_test_data
	push	de
	ld	hl, #0x915
	push	hl
	call	_set_bkg_data
	add	sp, #4
;game.c:192: set_bkg_tiles(0, 0, test_tilemapWidth, test_tilemapHeight, test_tilemap);
	ld	de, #_test_tilemap
	push	de
	ld	hl, #0x1014
	push	hl
	xor	a, a
	rrca
	push	af
	call	_set_bkg_tiles
	add	sp, #6
;game.c:194: set_win_data(0, 20, hud_data);
	ld	de, #_hud_data
	push	de
	ld	hl, #0x1400
	push	hl
	call	_set_win_data
	add	sp, #4
;game.c:195: set_win_tiles(0, 0, hud_tilemapWidth, hud_tilemapHeight, hud_tilemap);
	ld	de, #_hud_tilemap
	push	de
	ld	hl, #0x214
	push	hl
	xor	a, a
	rrca
	push	af
	call	_set_win_tiles
	add	sp, #6
;/home/cavenderbi/Downloads/gbdk/include/gb/gb.h:1195: WX_REG=x, WY_REG=y;
	ld	a, #0x08
	ldh	(_WX_REG + 0), a
	ld	a, #0x80
	ldh	(_WY_REG + 0), a
;game.c:198: SHOW_SPRITES;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x02
	ldh	(_LCDC_REG + 0), a
;game.c:199: SHOW_BKG;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x01
	ldh	(_LCDC_REG + 0), a
;game.c:200: SHOW_WIN;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x20
	ldh	(_LCDC_REG + 0), a
;game.c:201: DISPLAY_ON;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x80
	ldh	(_LCDC_REG + 0), a
;game.c:203: while (true) {
00102$:
;game.c:204: input();
	call	_input
;game.c:205: logic();
	call	_logic
;game.c:206: draw();
	call	_draw
	jr	00102$
;game.c:208: }
	add	sp, #4
	ret
	.area _CODE
	.area _INITIALIZER
__xinit__arrow:
	.db #0x10	; 16
	.db #0x10	; 16
	.db #0x28	; 40
	.db #0x38	; 56	'8'
	.db #0x44	; 68	'D'
	.db #0x7c	; 124
	.db #0x82	; 130
	.db #0xfe	; 254
	.db #0xee	; 238
	.db #0xfe	; 254
	.db #0x28	; 40
	.db #0x38	; 56	'8'
	.db #0x28	; 40
	.db #0x38	; 56	'8'
	.db #0x38	; 56	'8'
	.db #0x38	; 56	'8'
	.db #0x10	; 16
	.db #0x10	; 16
	.db #0x38	; 56	'8'
	.db #0x28	; 40
	.db #0x7c	; 124
	.db #0x44	; 68	'D'
	.db #0xfe	; 254
	.db #0x82	; 130
	.db #0xfe	; 254
	.db #0xee	; 238
	.db #0x38	; 56	'8'
	.db #0x28	; 40
	.db #0x38	; 56	'8'
	.db #0x28	; 40
	.db #0x38	; 56	'8'
	.db #0x38	; 56	'8'
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x14	; 20
	.db #0x1c	; 28
	.db #0xf2	; 242
	.db #0xfe	; 254
	.db #0x81	; 129
	.db #0xff	; 255
	.db #0xf2	; 242
	.db #0xfe	; 254
	.db #0x14	; 20
	.db #0x1c	; 28
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x1c	; 28
	.db #0x14	; 20
	.db #0xfe	; 254
	.db #0xf2	; 242
	.db #0xff	; 255
	.db #0x81	; 129
	.db #0xfe	; 254
	.db #0xf2	; 242
	.db #0x1c	; 28
	.db #0x14	; 20
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x38	; 56	'8'
	.db #0x38	; 56	'8'
	.db #0x28	; 40
	.db #0x38	; 56	'8'
	.db #0x28	; 40
	.db #0x38	; 56	'8'
	.db #0xee	; 238
	.db #0xfe	; 254
	.db #0x82	; 130
	.db #0xfe	; 254
	.db #0x44	; 68	'D'
	.db #0x7c	; 124
	.db #0x28	; 40
	.db #0x38	; 56	'8'
	.db #0x10	; 16
	.db #0x10	; 16
	.db #0x38	; 56	'8'
	.db #0x38	; 56	'8'
	.db #0x38	; 56	'8'
	.db #0x28	; 40
	.db #0x38	; 56	'8'
	.db #0x28	; 40
	.db #0xfe	; 254
	.db #0xee	; 238
	.db #0xfe	; 254
	.db #0x82	; 130
	.db #0x7c	; 124
	.db #0x44	; 68	'D'
	.db #0x38	; 56	'8'
	.db #0x28	; 40
	.db #0x10	; 16
	.db #0x10	; 16
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x28	; 40
	.db #0x38	; 56	'8'
	.db #0x4f	; 79	'O'
	.db #0x7f	; 127
	.db #0x81	; 129
	.db #0xff	; 255
	.db #0x4f	; 79	'O'
	.db #0x7f	; 127
	.db #0x28	; 40
	.db #0x38	; 56	'8'
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x38	; 56	'8'
	.db #0x28	; 40
	.db #0x7f	; 127
	.db #0x4f	; 79	'O'
	.db #0xff	; 255
	.db #0x81	; 129
	.db #0x7f	; 127
	.db #0x4f	; 79	'O'
	.db #0x38	; 56	'8'
	.db #0x28	; 40
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x00	; 0
	.db #0x00	; 0
__xinit__test_projectile:
	.db #0xc2	; 194
	.db #0x02	; 2
	.db #0x01	; 1
	.db #0x7f	; 127
	.db #0xc2	; 194
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xa0	; 160
	.db #0x00	; 0
	.db #0xa0	; 160
	.db #0x40	; 64
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0xa0	; 160
	.db #0xe0	; 224
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x43	; 67	'C'
	.db #0x40	; 64
	.db #0x80	; 128
	.db #0xfe	; 254
	.db #0x43	; 67	'C'
	.db #0x40	; 64
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0xa0	; 160
	.db #0xe0	; 224
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0xa0	; 160
	.db #0x40	; 64
	.db #0xa0	; 160
	.db #0x00	; 0
__xinit__test_enemy:
	.db #0x7e	; 126
	.db #0x7e	; 126
	.db #0xff	; 255
	.db #0xe7	; 231
	.db #0xff	; 255
	.db #0x81	; 129
	.db #0xff	; 255
	.db #0xa5	; 165
	.db #0xff	; 255
	.db #0x81	; 129
	.db #0xff	; 255
	.db #0x99	; 153
	.db #0xff	; 255
	.db #0xa5	; 165
	.db #0x7e	; 126
	.db #0x7e	; 126
__xinit__hud_data:
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
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
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x38	; 56	'8'
	.db #0x38	; 56	'8'
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x38	; 56	'8'
	.db #0x38	; 56	'8'
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x38	; 56	'8'
	.db #0x38	; 56	'8'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x60	; 96
	.db #0x60	; 96
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x60	; 96
	.db #0x60	; 96
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x06	; 6
	.db #0x06	; 6
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x06	; 6
	.db #0x06	; 6
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x20	; 32
	.db #0x00	; 0
	.db #0x60	; 96
	.db #0x3f	; 63
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0x60	; 96
	.db #0x00	; 0
	.db #0x20	; 32
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x0a	; 10
	.db #0x00	; 0
	.db #0x14	; 20
	.db #0x00	; 0
	.db #0xfc	; 252
	.db #0xfc	; 252
	.db #0x14	; 20
	.db #0x00	; 0
	.db #0x0a	; 10
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x2c	; 44
	.db #0x2c	; 44
	.db #0x34	; 52	'4'
	.db #0x34	; 52	'4'
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x08	; 8
	.db #0x08	; 8
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x08	; 8
	.db #0x08	; 8
	.db #0x08	; 8
	.db #0x08	; 8
	.db #0x08	; 8
	.db #0x08	; 8
	.db #0x1c	; 28
	.db #0x1c	; 28
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x04	; 4
	.db #0x04	; 4
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x20	; 32
	.db #0x20	; 32
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x08	; 8
	.db #0x08	; 8
	.db #0x04	; 4
	.db #0x04	; 4
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x1c	; 28
	.db #0x1c	; 28
	.db #0x04	; 4
	.db #0x04	; 4
	.db #0x04	; 4
	.db #0x04	; 4
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x20	; 32
	.db #0x20	; 32
	.db #0x38	; 56	'8'
	.db #0x38	; 56	'8'
	.db #0x04	; 4
	.db #0x04	; 4
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x20	; 32
	.db #0x20	; 32
	.db #0x38	; 56	'8'
	.db #0x38	; 56	'8'
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x04	; 4
	.db #0x04	; 4
	.db #0x08	; 8
	.db #0x08	; 8
	.db #0x10	; 16
	.db #0x10	; 16
	.db #0x10	; 16
	.db #0x10	; 16
	.db #0x10	; 16
	.db #0x10	; 16
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x24	; 36
	.db #0x1c	; 28
	.db #0x1c	; 28
	.db #0x04	; 4
	.db #0x04	; 4
	.db #0x04	; 4
	.db #0x04	; 4
	.db #0x00	; 0
	.db #0x00	; 0
__xinit__hud_tilemap:
	.db #0x00	; 0
	.db #0x01	; 1
	.db #0x01	; 1
	.db #0x01	; 1
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x08	; 8
	.db #0x09	; 9
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x03	; 3
	.db #0x04	; 4
	.db #0x00	; 0
	.db #0x06	; 6
	.db #0x00	; 0
	.db #0x02	; 2
	.db #0x04	; 4
	.db #0x00	; 0
	.db #0x06	; 6
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x01	; 1
	.db #0x01	; 1
	.db #0x01	; 1
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x0a	; 10
	.db #0x0a	; 10
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x05	; 5
	.db #0x00	; 0
	.db #0x07	; 7
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x05	; 5
	.db #0x00	; 0
	.db #0x07	; 7
	.db #0x00	; 0
__xinit__test_data:
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xdf	; 223
	.db #0x20	; 32
	.db #0xdf	; 223
	.db #0x20	; 32
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xfb	; 251
	.db #0x04	; 4
	.db #0xfb	; 251
	.db #0x04	; 4
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x03	; 3
	.db #0x03	; 3
	.db #0x03	; 3
	.db #0x02	; 2
	.db #0x03	; 3
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x03	; 3
	.db #0x03	; 3
	.db #0x02	; 2
	.db #0x03	; 3
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x02	; 2
	.db #0x03	; 3
	.db #0x03	; 3
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x40	; 64
	.db #0xc0	; 192
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x40	; 64
	.db #0xc0	; 192
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0x40	; 64
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
__xinit__test_tilemap:
	.db #0x17	; 23
	.db #0x16	; 22
	.db #0x16	; 22
	.db #0x16	; 22
	.db #0x16	; 22
	.db #0x16	; 22
	.db #0x16	; 22
	.db #0x16	; 22
	.db #0x16	; 22
	.db #0x16	; 22
	.db #0x16	; 22
	.db #0x16	; 22
	.db #0x16	; 22
	.db #0x16	; 22
	.db #0x16	; 22
	.db #0x16	; 22
	.db #0x16	; 22
	.db #0x16	; 22
	.db #0x16	; 22
	.db #0x1a	; 26
	.db #0x18	; 24
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x1b	; 27
	.db #0x18	; 24
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x1b	; 27
	.db #0x18	; 24
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x1b	; 27
	.db #0x18	; 24
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x1b	; 27
	.db #0x18	; 24
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x1b	; 27
	.db #0x18	; 24
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x1b	; 27
	.db #0x18	; 24
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x1b	; 27
	.db #0x18	; 24
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x1b	; 27
	.db #0x18	; 24
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x1b	; 27
	.db #0x18	; 24
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x1b	; 27
	.db #0x18	; 24
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x1b	; 27
	.db #0x18	; 24
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x1b	; 27
	.db #0x18	; 24
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x1b	; 27
	.db #0x18	; 24
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x15	; 21
	.db #0x1b	; 27
	.db #0x19	; 25
	.db #0x1d	; 29
	.db #0x1d	; 29
	.db #0x1d	; 29
	.db #0x1d	; 29
	.db #0x1d	; 29
	.db #0x1d	; 29
	.db #0x1d	; 29
	.db #0x1d	; 29
	.db #0x1d	; 29
	.db #0x1d	; 29
	.db #0x1d	; 29
	.db #0x1d	; 29
	.db #0x1d	; 29
	.db #0x1d	; 29
	.db #0x1d	; 29
	.db #0x1d	; 29
	.db #0x1d	; 29
	.db #0x1d	; 29
	.db #0x1c	; 28
	.area _CABS (ABS)

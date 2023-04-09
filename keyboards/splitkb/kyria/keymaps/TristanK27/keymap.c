/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
// TODO: Add numpad layer
enum layers {
    BASE,
    NUMB,
    SYMB,
    MDIA,
    NUMPAD,
    ADJUST
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 
 * Layer Name: Base
 * Description: Default Layer
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | del/alt|   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Bksp/ctl|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Shift |   Z  |   X  |   C  |   V  |   B  |  GUI | home |  |esc/AD|      |   N  |   M  |   ,  |   .  |   /  |  Shift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |  spc |  end |  |      |  ent |      |      |      |
 *                        |      |NUMP  |NUMB  |  SYMB|  MDIA|  |  MDIA|  SYMB| NUMB | NUMP |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [BASE] = LAYOUT(
     MT(MOD_LALT, KC_DEL)  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                                                                          KC_Y,   KC_U ,  KC_I ,   KC_O ,    KC_P ,    MT(MOD_RALT, KC_BSLS),
     MT(MOD_LCTL, KC_BSPC) , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                                                                          KC_H,   KC_J ,  KC_K ,   KC_L ,    KC_SCLN,  MT(MOD_RCTL, KC_QUOT),
     KC_LSFT               , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B ,   LGUI_T(CW_TOGG) ,   KC_HOME,                 LT(ADJUST, KC_ESC), CW_TOGG,              KC_N,   KC_M ,  KC_COMM, KC_DOT ,  KC_SLSH,  KC_RSFT,
                    KC_TRNS , LT(NUMPAD, KC_TRNS), LT(NUMB, KC_TRNS),      LT(SYMB, KC_SPC) , LT(MDIA, KC_END) ,       LT(MDIA, KC_TAB) , LT(SYMB, KC_ENT) ,    LT(NUMB, KC_TRNS), LT(NUMPAD,KC_TRNS) , KC_APP
    ),

/*
 * Layer Name: NUMB
 * Description: Numeric Layer with F-keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  F15   |  F9  |  F10 |  F11 |  F12 |  F18 |                              |      |  7   |  8   |  9   |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  F14   |  F5  |  F6  |  F7  |  F8  |  F17 |                              |      |  4   |  5   |  6   |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  F13   |  F1  |  F2  |  F3  |  F4  |  F16 |      |      |  |      |      |  0   |  1   |  2   |  3   |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [NUMB] = LAYOUT(
     KC_F15 , KC_F9, KC_F10, KC_F11,   KC_F12,   KC_F18 ,                                                    KC_TRNS,   KC_7 ,  KC_8 ,   KC_9 ,  KC_TRNS , KC_TRNS,
     KC_F14 , KC_F5, KC_F6 , KC_F7 ,   KC_F8 ,   KC_F17 ,                                                    KC_TRNS,   KC_4 ,  KC_5 ,   KC_6 ,  KC_TRNS , KC_TRNS,
     KC_F13 , KC_F1, KC_F2 , KC_F3 ,   KC_F4 ,   KC_F16 ,      KC_TRNS, KC_TRNS,      KC_TRNS , KC_TRNS,     KC_0 ,     KC_1 ,  KC_2 ,   KC_3 ,  KC_TRNS,  KC_TRNS,
                                KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
    ),
/*
 * Layer Name: SYMB
 * Description: Symbol Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |      |                              |      |      |  &   |  *   |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |      |                              |      |  +   |  -   |  _   |  `   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |      |      |      |  |      |      |      |  =   |  ~   |  |   |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
*/
    [SYMB] = LAYOUT(
      KC_TRNS, S(KC_1), S(KC_2), S(KC_LBRC), S(KC_RBRC), KC_TRNS,                                    KC_TRNS, KC_TRNS, S(KC_7), S(KC_8), KC_TRNS, KC_TRNS,
      KC_TRNS, S(KC_3), S(KC_4), S(KC_9),    S(KC_0), KC_TRNS,                                          KC_TRNS, S(KC_EQUAL), KC_MINUS, S(KC_MINUS), KC_GRAVE, KC_TRNS,
      KC_TRNS, S(KC_5), S(KC_6), KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS, KC_EQUAL, S(KC_GRAVE), KC_TRNS, KC_TRNS,
                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

/*
 * Layer Name: MDIA
 * Description: Media and Control Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |C-w   |C->   |C-e   |C-y   |      |                              |      |C-c   |C-z   |      |C-v   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |PrtSc |                              | Left | Down | Up   | Right|      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |C-<   |      |      |  |      |      | M-Rev| Vol- | Vol+ | M-Fwd| pause|        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [MDIA] = LAYOUT(
      KC_TRNS, LCTL(KC_W), LCTL(KC_RIGHT), LCTL(KC_E), LCTL(KC_Y), KC_TRNS,                                         KC_TRNS, LCTL(KC_C), LCTL(KC_Z), KC_TRNS, LCTL(KC_V), KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR,                                                         KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_LEFT), KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_MEDIA_REWIND, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_FAST_FORWARD, KC_MPLY, KC_TRNS,
                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

/*
    * Layer Name: NUMPAD
    * Description: Numpad Layer
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |        |      |      |      |      |      |                              |      |  7   |  8   |  9   |      |        |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * |        |      |      |      |      |      |                              |      |  4   |  5   |  6   |      |        |
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * |        |      |      |      |      |      |      |      |  |      |      |  0   |  1   |  2   |  3   |      |        |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *                        |      |      |      |      |      |  |      |      |      |      |      |
    *                        |      |      |      |      |      |  |      |      |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [NUMPAD] = LAYOUT(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                         KC_TRNS, KC_KP_7, KC_KP_8, KC_KP_9, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                         KC_TRNS, KC_KP_4, KC_KP_5, KC_KP_6, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_TRNS, KC_TRNS,
                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
/*
 * Layer Name: ADJUST
 * Description: Adjust Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |RESET |Debug |RGBtog|RGBmod|RGBh+ |                              |RGBh- |RGBs+ |RGBs- |RGBv+ |RGBv- |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
*/
    [ADJUST] = LAYOUT(
      KC_TRNS, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI,                                                         RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                         KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS ,KC_TRNS, KC_TRNS, 
                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};
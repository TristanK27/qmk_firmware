/* Copyright 2020 tominabox1
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

enum layers {
  BASE,
  NUMB,
  SYMB,
  MDIA,
  NUMPAD,
  ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base Layer
 * ,-----------------------------------------------------------------------------------.
 * |Alt/Del|  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   |Alt/Bs|
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * |Ctl/Bs |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |  ;   |Ctl/' |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift |  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  /   | Shift|
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl  | Trns |  GUI |Symb/H|Numb/E|  GUI/Space  |Numb  |Symb  | Trns | Trns | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[BASE] = LAYOUT_planck_mit(
    MT(MOD_LALT, KC_DEL), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, MT(MOD_RALT, KC_BSPC),
    MT(MOD_LCTL, KC_BSPC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, MT(MOD_RCTL, KC_QUOT),
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLASH, KC_RSFT,
    KC_LCTL, KC_TRNS, KC_LGUI, LT(SYMB, KC_HOME), LT(NUMB, KC_END), MT(MOD_LGUI, KC_SPACE), LT(NUMB,  KC_TRNS), LT(SYMB,  KC_TRNS), KC_TRNS, KC_TRNS, KC_RCTL
),

/* Number
 * ,-----------------------------------------------------------------------------------.
 * |  F15  |  F9  |  F10 |  F11 |  F12 |  F18 | Trns |   7  |   8  |   9  | Trns | Trns |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F14  |  F5  |  F6  |  F7  |  F8  |  F17 | Trns |   4  |   5  |   6  | Trns | Trns |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F13  |  F1  |  F2  |  F3  |  F4  |  F16 |   0  |   1  |   2  |   3  | Trns | Trns |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * | Trns | Trns | Trns | Trns | Trns |  Trns | Trns | Trns | Trns | Trns | Trns | Trns |
 * `-----------------------------------------------------------------------------------'
 */
[NUMB] = LAYOUT_planck_mit(
    KC_F15,  KC_F9,    KC_F10,    KC_F11,    KC_F12,    KC_F18,    KC_TRNS,    KC_7,    KC_8,    KC_9,    KC_TRNS,    KC_TRNS,
    KC_F14,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F17,    KC_TRNS,    KC_4,    KC_5,    KC_6,    KC_TRNS, KC_TRNS,
    KC_F13, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F16,    KC_0,    KC_1,    KC_2, KC_3,  KC_TRNS, KC_TRNS ,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS
),

/* Number
 * ,-----------------------------------------------------------------------------------.
 * |  F15  |  F9  |  F10 |  F11 |  F12 |  F18 | Trns |   7  |   8  |   9  | Trns | Trns |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F14  |  F5  |  F6  |  F7  |  F8  |  F17 | Trns |   4  |   5  |   6  | Trns | Trns |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F13  |  F1  |  F2  |  F3  |  F4  |  F16 |   0  |   1  |   2  |   3  | Trns | Trns |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * | Trns | Trns | Trns | Trns | Trns |  Trns | Trns | Trns | Trns | Trns | Trns | Trns |
 * `-----------------------------------------------------------------------------------'
 */
[SYMB] = LAYOUT_planck_mit(
    KC_TRNS, S(KC_1), S(KC_2),   S(KC_9), S(KC_0),  KC_TRNS, KC_TRNS, S(KC_7),    S(KC_8),    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,  S(KC_3),   S(KC_4),   S(KC_LBRC),   S(KC_RBRC),   KC_TRNS,   KC_TRNS,   S(KC_EQUAL),    KC_MINUS,    S(KC_MINUS), S(KC_GRAVE), KC_TRNS,
    KC_TRNS, S(KC_5),   S(KC_6),   KC_LBRC,   KC_RBRC,  KC_TRNS,  KC_TRNS,  KC_EQUAL, S(KC_GRAVE), KC_TRNS, KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
),

/* Media Layer
 * ,----------------------------------------------------------------------------------.
 * | Trns |Ctl+W |Ctl+Rt|Ctl+E |Ctl+Y | Trns |Ctl+C |Ctl+Z | Trns | Trns |Ctl+V | Trns |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Trns | Trns | Trns | Trns | Trns |PrtScr| Left | Down |  Up  | Right| Trns | Trns |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Trns | Trns | Trns | Trns | Trns |Ctl+Lt| Prev | Vol+ | Vol- | Next | Trns | Trns |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Trns | Trns | Trns | Trns | Trns |        Trns        | Trns | Trns | Trns | Trns |
 * `----------------------------------------------------------------------------------'
 */
[MDIA] = LAYOUT_planck_mit(
    KC_TRNS,  LCTL(KC_W),    LCTL(KC_RIGHT),    LCTL(KC_E),    LCTL(KC_Y),    KC_TRNS,    LCTL(KC_C),    LCTL(KC_Z),    KC_TRNS,    KC_TRNS,    LCTL(KC_V),    KC_TRNS,
    KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_PSCR,   KC_LEFT,   KC_DOWN, KC_UP,  KC_RIGHT, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  LCTL(KC_LEFT),  KC_MEDIA_PREV_TRACK,  KC_VOLU, KC_VOLD, KC_MEDIA_NEXT_TRACK, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* Numpad Layer
 * ,----------------------------------------------------------------------------------.
 * | Trns | Trns | Trns | Trns | Trns | Trns |NmLock|  7   |  8   |  9   |  /   |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Trns | Trns | Trns | Trns | Trns | Trns | Trns |  4   |  5   |  6   |  *   |  +   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Trns | Trns | Trns | Trns | Trns | Trns |  0   |  1   |  2   |  3   | Trns | Trns |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Trns | Trns | Trns | Trns | Trns |        Trns        | Trns | Trns | Trns | Trns |
 * `----------------------------------------------------------------------------------'
 */
[NUMPAD] = LAYOUT_planck_mit(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NUM_LOCK, KC_KP_7, KC_KP_8,  KC_KP_9, KC_KP_SLASH, KC_KP_MINUS ,
    _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_4,  KC_KP_5,  KC_KP_6, KC_KP_ASTERISK, KC_KP_PLUS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_0, KC_KP_1,  KC_KP_2,  KC_KP_3, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
),

/* Adjust Layer
 * ,-----------------------------------------------------------------------------------.
 * | Trns |QK_Boo|DB_Tog|RGB_Tg|RGB_Md|RGB_HU|RGB_HD|RGB_SA|RGB_SD|RGB_VA|RGB_VD| Trns |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Trns | Trns | Trns | Trns | Trns | Trns | Trns | Trns | Trns | Trns | Trns | Trns |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Trns | Trns | Trns | Trns | Trns | Trns | Trns | Trns | Trns | Trns | Trns | Trns |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Trns | Trns | Trns | Trns | Trns |        Trns        | Trns | Trns | Trns | Trns |
 * `-----------------------------------------------------------------------------------'
 */
[ADJUST] = LAYOUT_planck_mit(
    KC_TRNS, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_TRNS ,
    _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
),

};
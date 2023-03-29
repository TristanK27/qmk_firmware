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

enum layers {
    BASE,
    NUMB,
    SYMB,
    MDIA,
    NUMPAD,
    ADJUST
};


// Aliases for readability
#define QWERTY   DF(BASE)

#define SYM      MO(MDIA)
#define NAV      MO(SYMB)
#define FKEYS    MO(NUMPAD)
#define ADJUST   MO(ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [BASE] = LAYOUT(
     MT(MOD_LALT, KC_DEL)  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                                                KC_Y,   KC_U ,  KC_I ,   KC_O ,    KC_P ,  MT(MOD_RALT, KC_BSLS),
     MT(MOD_LCTL, KC_BSPC) , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                                                KC_H,   KC_J ,  KC_K ,   KC_L ,    KC_SCLN,MT(MOD_RCTL, KC_QUOT),
     KC_LSFT               , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B ,   KC_LGUI ,           KC_HOME,     KC_TRNS , KC_TRNS,          KC_N,   KC_M ,  KC_COMM, KC_DOT ,  KC_SLSH, KC_RSFT,
                                KC_TRNS , KC_TRNS, LT(SYMB, KC_TRNS),       LT(NUMB, KC_BSPC) , KC_END ,    KC_TAB  , LT(NUMB, KC_ENT) ,LT(SYMB, KC_TRNS), KC_RGUI, KC_APP
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

    [SYMB] = LAYOUT(
      KC_TRNS, S(KC_1), S(KC_2), S(KC_LBRC), S(KC_RBRC), KC_TRNS,                                    KC_TRNS, KC_TRNS, S(KC_7), S(KC_8), KC_TRNS, KC_TRNS,
      KC_TRNS, S(KC_3), S(KC_4), S(KC_9),    S(KC_0), KC_TRNS,                                          KC_TRNS, S(KC_EQUAL), KC_MINUS, S(KC_MINUS), KC_GRAVE, KC_TRNS,
      KC_TRNS, S(KC_5), S(KC_6), KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS, KC_EQUAL, S(KC_GRAVE), KC_TRNS, KC_TRNS,
                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |   +    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |   \  |  :   |  ;   |  -   |  [   |  {   |      |  |      |   }  |   ]  |  _   |  ,   |  .   |  /   |   ?    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [MDIA] = LAYOUT(
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
     KC_TILD , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
     KC_PIPE , KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______, _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [NUMPAD] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

};
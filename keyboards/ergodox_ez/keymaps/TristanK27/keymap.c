#include QMK_KEYBOARD_H
#include "version.h"

// TODO: add layer for numpad

enum layers {
    BASE,  // default layer
    NUMB,  // numbers and f-keys
    SYMB,  // symbol keys
    MDIA,  // arrow keys, media keys and other shortcut keys
    NUMPAD,// numpad keys, on the right side of the keyboard
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  TRNS  |   1  |   2  |   3  |   4  |   5  | TRNS |           | TRNS |   6  |   7  |   8  |   9  |   0  |  TRNS  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Del   |   Q  |   W  |   E  |   R  |   T  | PScr |           | TRNS |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Ctl/BkSp|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |Ctl/'   |
 * |--------+------+------+------+------+------| Ins  |           | TRNS |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | TRNS | TRNS | TRNS | Left | Right|                                       |  Up  | Down | TRNS | TRNS | TRNS |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LGui | TRNS |       | Esc  | TRNS |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |Symb/ |Numb/ |------|       |------| Numb/  |Symb/ |
 *                                 | Space|BkSp  | End  |       | PgDn | Tab    | Enter|
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  KC_TRNS,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_TRNS,              KC_TRNS,      KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_TRNS,
  MT(MOD_LALT, KC_DEL),          KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    KC_PSCR,             KC_TRNS,     KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           MT(MOD_RALT, KC_BSLS),
  MT(MOD_LCTL, KC_BSPC),         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MT(MOD_RCTL, KC_QUOT),
  KC_LSFT,         KC_Z, KC_X,          KC_C,    KC_V,    KC_B,    KC_INSERT,                  KC_TRNS, KC_N,    KC_M,    KC_COMM, KC_DOT,           KC_SLASH, KC_RSFT,
  KC_TRNS, KC_TRNS,     KC_TRNS, KC_LEFT, LT(MDIA, KC_RIGHT),                                              LT(MDIA, KC_UP),   KC_DOWN, KC_TRNS, KC_TRNS, KC_TRNS,
                                                           KC_LGUI, KC_TRNS,                KC_ESCAPE, KC_TRNS,
                                                                          KC_HOME,                 KC_PGUP,
                                                         LT(SYMB, KC_SPC), LT(NUMB, KC_BSPC), KC_END,                  KC_PGDN, LT(NUMB, KC_TAB), LT(SYMB, KC_ENT)
),
/* Keymap 1: [NUMB] Number layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |           | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |  TRNS  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   F15  |  F9  | F10  | F11  | F12  | F18  | TRNS |           | TRNS | TRNS |   7  |   8  |   9  | TRNS | TRNS   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   F14  |  F5  |  F6  |  F7  |  F8  | F17  |------|           |------| TRNS |   4  |   5  |   6  | TRNS | TRNS   |
 * |--------+------+------+------+------+------| TRNS |           | TRNS |------+------+------+------+------+--------|
 * |   F13  |  F1  |  F2  |  F3  |  F4  | F16  |      |           |      |   0  |   1  |   2  |   3  | TRNS | TRNS   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | TRNS | TRNS | TRNS | TRNS | TRNS |                                       | TRNS | TRNS | TRNS | TRNS | TRNS |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | TRNS | TRNS |       | TRNS | TRNS |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | TRNS |       | TRNS |        |      |
 *                                 | TRNS | TRNS |------|       |------| TRNS  | TRNS |
 *                                 |      |      | TRNS |       | TRNS |        |      |
 *                                 `--------------------'       `----------------------'
 */
[NUMB] = LAYOUT_ergodox_pretty(
  KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,
  KC_F15, KC_F9, KC_F10,   KC_F11, KC_F12, KC_F18, KC_TRNS,     KC_TRNS, KC_TRNS,   KC_7,    KC_8,    KC_9,    KC_TRNS, KC_TRNS,
  KC_F14, KC_F5, KC_F6,  KC_F7, KC_F8, KC_F17,               KC_TRNS, KC_4,    KC_5,    KC_6,    KC_TRNS, KC_TRNS,
  KC_F13, KC_F1, KC_F2, KC_F3, KC_F4, KC_F16, KC_TRNS,     KC_TRNS, KC_0, KC_1,    KC_2,    KC_3,    KC_TRNS, KC_TRNS,
  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: [SYMB] Symbols layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |           | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |  TRNS  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  TRNS  |   !  |   @  |   (  |   )  | TRNS | TRNS |           | TRNS | TRNS |   &  |   *  | TRNS | TRNS | TRNS   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  TRNS  |   #  |   $  |   {  |   }  | TRNS |------|           |------| TRNS |   +  |  -   |   _  |   `  | TRNS   |
 * |--------+------+------+------+------+------| TRNS |           | TRNS |------+------+------+------+------+--------|
 * |  TRNS  |   %  |   ^  |   [  |   ]  | TRNS |      |           |      | TRNS |  =   |   ~  | TRNS | TRNS | TRNS   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | TRNS | TRNS | TRNS | TRNS | TRNS |                                       | TRNS | TRNS | TRNS | TRNS | TRNS |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | TRNS | TRNS |       | TRNS | TRNS |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | TRNS |       | TRNS |        |      |
 *                                 | TRNS | TRNS |------|       |------| TRNS  | TRNS |
 *                                 |      |      | TRNS |       | TRNS |        |      |
 *                                 `--------------------'       `----------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, S(KC_1), S(KC_2), S(KC_LBRC), S(KC_RBRC), KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, S(KC_7), S(KC_8), KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, S(KC_3), S(KC_4), S(KC_9), S(KC_0), KC_TRNS,                       KC_TRNS, S(KC_EQUAL), KC_MINUS, S(KC_MINUS), KC_GRAVE, KC_TRNS,
  KC_TRNS, S(KC_5), S(KC_6), KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_EQUAL, S(KC_GRAVE), KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: [MDIA] Media and mouse layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |           | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |  TRNS  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  TRNS  |Ctrl+W|Ctrl+R|Ctrl+E|Ctrl+Y| TRNS | TRNS |           | TRNS |Ctrl+C|Ctrl+Z| TRNS | TRNS |Ctrl+V| TRNS   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  TRNS  | TRNS | TRNS | TRNS | TRNS |PrtSc |------|           |------| Left | Down |  Up  |Right | TRNS | TRNS   |
 * |--------+------+------+------+------+------| TRNS |           | TRNS |------+------+------+------+------+--------|
 * |  TRNS  | TRNS | TRNS | TRNS | TRNS |Ctrl+L|      |           |      |PrevTr|VolDwn|VolUp |NextTr| Play | TRNS   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | TRNS | TRNS | TRNS | TRNS | TRNS |                                       | TRNS | TRNS | TRNS | TRNS | TRNS |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | TRNS | TRNS |       | TRNS | TRNS |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | TRNS |       | TRNS |        |      |
 *                                 | TRNS | TRNS |------|       |------| TRNS  | TRNS |
 *                                 |      |      | TRNS |       | TRNS |        |      |
 *                                 `--------------------'       `----------------------'
 */
[MDIA] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, LCTL(KC_W), LCTL(KC_RIGHT), LCTL(KC_E), LCTL(KC_Y), KC_TRNS, KC_TRNS,     KC_TRNS, LCTL(KC_C), LCTL(KC_Z), KC_TRNS, KC_TRNS, LCTL(KC_V), KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR,                       KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_LEFT), KC_TRNS,     KC_TRNS, KC_MEDIA_REWIND, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_FAST_FORWARD, KC_MPLY, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
/*

*/
[NUMB] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,    KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_TRNS, KC_TRNS, 
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS,    KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_TRNS, KC_TRNS, 
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_0,       KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_TRNS, KC_TRNS, 
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                            KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};

#include QMK_KEYBOARD_H
#include "version.h"

// TODO: move tab away from thumb cluster

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    NORM,  // media keys
    SPEC,  // special keys
    FUNC,  // function keys
    ARRO, // arrow keys
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  TRNS |  1   |  2   |  3   |  4   |  5   |  L3   |           |  L3  |  6   |  7   |  8   |  9   |  0   | TG(2)  |
 * |-------+------+------+------+------+------------- |           |------+------+------+------+------+------+--------|
 * |Del/Alt|  Q   |  W   |  E   |  R   |  T   | PrtSc |           | TRNS |  Y   |  U   |  I   |  O   |  P   | \ /RAlt|
 * |-------+------+------+------+------+------|       |           |      |------+------+------+------+------+--------|
 * |BkSp/L1|  A/L5|  S   |  D   |  F   |  G   |-------|           |------|  H   |  J   |  K   |  L   |  ;/L5|  '/L1  |
 * |-------+------+------+------+------+------| Hyper |           | Meh  |------+------+------+------+------+--------|
 * | LShift|Z/Ctrl|  X   |  C   |  V   |  B   |       |           |      |  N   |  M   |  ,   |  .   |//Ctrl| RShift |
 * `-------+------+------+------+------+--------------'           `-------------+------+------+------+------+--------'
 *   |Gui+S|C+A+S |Alt+S | Left |Right/L4|                                      | Up/L4| Down |RAlt+S|C+A+S |RGui+S|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Esc/Gui|  Ins|       | TRNS|Esc/RGui|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space| Enter|------|       |------|  Tab   | Enter|
 *                                 |      |      |  End |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS,        KC_1,         KC_2,          KC_3,    KC_4, KC_5,    MO(3),                    MO(3),        KC_6,        KC_7,    KC_8,          KC_9,         KC_0,            TG(2),
  LALT_T(KC_DEL), KC_Q,         KC_W,          KC_E,    KC_R, KC_T,    KC_PRINT_SCREEN,          KC_TRNS,      KC_Y,        KC_U,    KC_I,          KC_O,         KC_P,            RALT_T(KC_BACKSLASH),
  LT(1,KC_BSPC),  LT(5,KC_A),   KC_S,          KC_D,    KC_F, KC_G,                                            KC_H,        KC_J,    KC_K,          KC_L,         LT(5,KC_SCLN),   LT(1,KC_QUOT),
  KC_LSFT,        LCTL_T(KC_Z), KC_X,          KC_C,    KC_V, KC_B,    ALL_T(KC_NO),             MEH_T(KC_NO), KC_N,        KC_M,    KC_COMM,       KC_DOT,       RCTL_T(KC_SLSH), KC_RSFT,
  LGUI(KC_LSFT),  LCA(KC_LSFT), LALT(KC_LSFT), KC_LEFT, LT(4,KC_RGHT),                                         LT(4,KC_UP), KC_DOWN, RALT(KC_RSFT), LCA(KC_RSFT), RGUI(KC_RSFT),
                                                        LGUI_T(KC_ESCAPE), KC_INSERT,            KC_TRNS, RGUI_T(KC_ESCAPE),
                                                                           KC_HOME,              KC_PGUP,
                                                           KC_SPC, KC_ENT, KC_END,               KC_PGDN, KC_TAB, KC_ENT
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |  !   |  @   |  {   |  }   |      |      |           |      |      |  &   |  *   |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  #   |  $   |  (   |  )   |      |------|           |------|      |  +   |  -   |  _   |   `  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  %   |  ^   |  [   |  ]   |      |      |           |      |      |  =   |  ~   |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,     KC_TRNS,       KC_TRNS, KC_TRNS,
  KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_AMPERSAND, KC_ASTERISK, KC_TRNS,       KC_TRNS, KC_TRNS,
  KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_TRNS,                            KC_TRNS, KC_PLUS,      KC_MINUS,    KC_UNDERSCORE, KC_GRV,  KC_TRNS,
  KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_EQUAL,     KC_TILDE,    KC_TRNS,       KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                              KC_TRNS,      KC_TRNS,     KC_TRNS,       KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,
                                                        KC_TRNS,          KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: NORM layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      | TG(2)  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Alt   |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Bspc  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Shft  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |  Shft  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |      |      |      |      |                                       |      |      |      |      | Ctrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NORM] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  TG(2),
  KC_LALT, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TRNS,          KC_TRNS, KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_BSLS,
  KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_QUOTE,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_TRNS,          KC_TRNS, KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLASH, KC_RSFT,
  KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_RCTL,
                                                KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,
                                                         KC_TRNS,          KC_TRNS,
                                       KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: SPEC layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Sleep  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Power  |      | Play | Prev | Next | Vol+ |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      | Vol- |------|           |------|      | Br-  | Br+  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | Calc |      |Search|      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 * |        |      |DT_PRT|DT_DN |DTU_UP|                                       |      |      |      |      |        |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SPEC] = LAYOUT_ergodox_pretty(
  KC_SYSTEM_SLEEP, KC_TRNS, KC_TRNS,                       KC_TRNS,                        KC_TRNS,                    KC_TRNS,           KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_SYSTEM_POWER, KC_TRNS, KC_MEDIA_PLAY_PAUSE,           KC_MEDIA_PREV_TRACK,            KC_MEDIA_NEXT_TRACK,        KC_AUDIO_VOL_UP,   KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,         KC_TRNS, KC_TRNS,                       KC_TRNS,                        KC_TRNS,                    KC_AUDIO_VOL_DOWN,                           KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,         KC_TRNS, KC_TRNS,                       KC_CALCULATOR,                  KC_TRNS,                    KC_WWW_SEARCH,     KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,         KC_TRNS, QK_DYNAMIC_TAPPING_TERM_PRINT, QK_DYNAMIC_TAPPING_TERM_DOWN,   QK_DYNAMIC_TAPPING_TERM_UP,                                                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                 KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,
                                                          KC_TRNS,          KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 4: FUNC layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |NumLck| KP / | KP * | KP - |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | F9   | F10  | F11  | F12  |      |      |           |      |      | KP 7 | KP 8 | KP 9 | KP + |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | F5   | F6   | F7   | F8   |      |------|           |------|      | KP 4 | KP 5 | KP 6 |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | F1   | F2   | F3   | F4   |      |      |           |      |      | KP 1 | KP 2 | KP 3 |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | KP 0 |      | KP . |KPEnt |        |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[FUNC] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_NUM_LOCK, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, KC_TRNS,
  KC_F15,  KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_KP_7,     KC_KP_8,     KC_KP_9,        KC_KP_PLUS,  KC_TRNS,
  KC_F14,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_TRNS,                            KC_TRNS, KC_KP_4,     KC_KP_5,     KC_KP_6,        KC_TRNS,     KC_TRNS,
  KC_F13,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_KP_1,     KC_KP_2,     KC_KP_3,        KC_TRNS,     KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                              KC_KP_0,     KC_TRNS,     KC_KP_DOT,      KC_KP_ENTER, KC_TRNS,
                                                KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,
                                                         KC_TRNS,          KC_TRNS,
                                       KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 5: ARRO layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Tab  |      |      |      |      |------|           |------| Left | Down |  Up  |Right |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |        |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[ARRO] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
  KC_TRNS, KC_TAB,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
                                               KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS,
                                                        KC_TRNS,         KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS
),
};

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

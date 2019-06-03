#include QMK_KEYBOARD_H

enum {
  TD_LSFT_CAPS = 0,
  TD_RSFT_CAPS = 1
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
  [TD_RSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_CAPS)
};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
  _BL,
  _FL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = | Backsp|
   * |-----------------------------------------------------------|
   * | Tab | Q | W | E | R | T | Y | U | I | O | P | [ | ] |  \  |
   * |-----------------------------------------------------------|
   * | Caps  | A | S | D | F | G | H | J | K | L | ; | ' | Enter |
   * |-----------------------------------------------------------|
   * | Shift  | Z | X | C | V | B | N | M | , | . | / |    Shift |
   * |-----------------------------------------------------------|
   * |Ctrl|GUI |Alt|         Space        |AltGr| GUI|   Fn| Ctrl|
   * `-----------------------------------------------------------'
   */
  [_BL] = LAYOUT_60_ansi(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
    KC_NO,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
    TD(TD_LSFT_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TD(TD_RSFT_CAPS), \
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, MO(_FL), KC_RCTL
  ),

  /* Keymap _FL: Function Layer
   * ,-----------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   | KC_DEL|
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   | L | D | U | R |   | ` |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   | ~ |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
  [_FL] = LAYOUT_60_ansi(
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,  KC_F10, _______, _______, KC_DEL , \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, _______,  KC_GRV,          _______, \
    _______,          _______, _______, _______, _______, _______,  KC_TILD, _______,  _______, _______, _______,         _______, \
    _______, _______, _______,                            _______,                             _______, _______, _______, _______
  )
};

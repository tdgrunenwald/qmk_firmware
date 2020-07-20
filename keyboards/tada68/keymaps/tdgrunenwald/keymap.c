#include QMK_KEYBOARD_H

// !!!IMPORTANT!!! DEFINE A RESET KEY COMMAND, ELSE YOU CAN'T DFU PROGRAM!

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Layer 0: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   *
   * Note: Shift + Esc = ~
   *       Win   + Esc = `
   *       Hold  + RShift = (
   *       Hold  + LShift = )
   */
[0] = LAYOUT_ansi(
  KC_GESC,         KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,KC_GRV, \
  KC_TAB,          KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,KC_DEL, \
  LT(1, KC_ESC),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,KC_PGUP,  \
  KC_LSPO,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSPC,KC_UP,KC_PGDN, \
  KC_LCTL, KC_LGUI,KC_LALT,                     KC_SPC,                    KC_RALT,MO(1),KC_RCTRL, KC_LEFT,KC_DOWN,KC_RGHT),

// Make sure this layer has MO(2) somewhere so RESET is accessible
[1] = LAYOUT_ansi(
  MO(2)  , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11, KC_F12, KC_DEL, BL_TOGG ,  \
  XXXXXXX,XXXXXXX,C(KC_RGHT),C(KC_RGHT),XXXXXXX,XXXXXXX,XXXXXXX,KC_PGUP,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX,KC_INS, \
  XXXXXXX,XXXXXXX,XXXXXXX,KC_PGDN,XXXXXXX,XXXXXXX,KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,XXXXXXX,XXXXXXX,        _______, BL_INC, \
  _______,XXXXXXX, KC_DEL,XXXXXXX,XXXXXXX,C(KC_LEFT),XXXXXXX,KC_MUTE,KC_VOLD,KC_VOLU,KC_BSLS,_______, KC_PGUP, BL_DEC, \
  _______,_______,_______,                 KC_UNDS,               _______,XXXXXXX,_______,KC_HOME, KC_PGDN, KC_END),

// RESET key on layer 3 to avoid accidental presses
[2] = LAYOUT_ansi(
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_END,XXXXXXX,KC_HOME,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,  \
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, RESET ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX,XXXXXXX, \
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,        XXXXXXX,XXXXXXX, \
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX,XXXXXXX, \
  XXXXXXX,XXXXXXX,XXXXXXX,                 XXXXXXX,               XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	// If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
	uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif 
	return true;
}

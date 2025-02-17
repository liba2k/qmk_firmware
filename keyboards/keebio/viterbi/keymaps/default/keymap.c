#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |  Ins |   `  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  | Bksp | Del  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   -  | Tab  |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   =  | Esc  |   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |   ;  |   "  |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Pg Up| Shift|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   /  | Home | End  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Pg Dn|Adjust| Ctrl | Alt  | GUI  |Lower |Space |      |Space |Raise | Left | Down |  Up  | Right|   \  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_QWERTY] = LAYOUT_ortho_5x14(
      KC_ESC ,  KC_GRV , KC_1    , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL , KC_BSPC,
      KC_TAB , KC_Q    , KC_W    , KC_E   , KC_R   , KC_T   , _______,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC,
      QK_LOCK, KC_A    , KC_S    , KC_D   , KC_F   , KC_G   , _______,     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, MT(MOD_RSFT, KC_MINS),
      KC_LSFT, KC_Z    , KC_X    , KC_C   , KC_V   , KC_B   , _______,     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_UP  ,  KC_ENT,
      ADJUST,  KC_LCTL , KC_LALT , KC_LGUI, LOWER  , KC_SPC , KC_SPC ,     KC_SPC , KC_SPC , RAISE  , KC_BSLS, KC_LEFT, KC_DOWN,  KC_RGHT
  ),

/* Lower
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |   ~  |  F1  |  F3  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   _  |      |   !  |   @  |   #  |   $  |   %  |      |   ^  |   &  |   *  |   (  |   )  |   {  |   }  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   +  |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |   _  |   +  |   {  |   }  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |  F12 |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_LOWER] = LAYOUT_ortho_5x14(
    _______, KC_TILD, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    KC_UNDS, _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_HOME,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR,
    KC_PLUS, _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_END ,     KC_F6  , KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, KC_MINS,
    _______, _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_PGUP,     KC_F12 , _______, _______, _______, _______, _______, KC_EQL ,
    _______, _______, _______, _______, _______, _______, KC_PGDN,     _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_MUTE
  ),

/* Raise
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |   ~  |  F1  |  F3  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   _  |      |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   {  |   }  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   +  |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |   -  |   =  |   [  |   ]  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |  F12 |ISO # |ISO / |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_RAISE] = LAYOUT_ortho_5x14(
    _______, KC_TILD, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_BSPC ,
    KC_UNDS, _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_ASTERISK, KC_0   , KC_LCBR, KC_RCBR,
    KC_PLUS, _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_MINUS, KC_RBRC, KC_MUTE, KC_UNDS,
    _______, _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,     KC_KP_1, KC_KP_2, KC_KP_3,KC_KP_PLUS, RAISE, KC_VOLU, KC_EQL,
    ADJUST, KC_LCTL , KC_LALT, KC_LGUI, LOWER  , _______, RAISE  ,     KC_KP_0, KC_KP_0,KC_KP_DOT,KC_KP_ENTER, KC_MPLY, KC_VOLD, KC_MNXT
  ),

  [_ADJUST] = LAYOUT_ortho_5x14(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    _______, _______, QK_BOOT, UG_TOGG, UG_NEXT, UG_HUED, UG_HUEU,     UG_SATD, UG_SATU, UG_VALD, UG_VALU, _______, KC_DEL,  _______,
    _______, _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, AG_SWAP
  )

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t my_layer_timer;
  static bool other_key_pressed = false;

  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
       if (record->event.pressed) {
            my_layer_timer = timer_read();
            other_key_pressed = false;
            layer_on(_RAISE);
        } else {
            if (other_key_pressed || timer_elapsed(my_layer_timer) < TAPPING_TERM * 10) {
                layer_off(_RAISE);
            }
        }
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    default:
        if (record->event.pressed) {
            other_key_pressed = true; // Any other key sets this flag
        }
  }
  return true;
}

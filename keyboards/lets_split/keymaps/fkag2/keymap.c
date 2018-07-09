// This is Filip Gokstorp's keymap file for a Let's Split.
// Fancy keyboard layout comments are taken from Noah Frederick's blog.
// Design is a mix of Noah Frederick's layout for the Planck,
// Heartrobotninja's Let's Split layout, and personal modifications

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _NORMAN 2
#define _DVORAK 3
#define _LOWER 4
#define _RAISE 5
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  NORMAN,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define ___x___ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base layer (Qwerty)
   *            ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
   *            │ TAB │  Q  │  W  │  E  │  R  │  T  │   │  Y  │  U  │  I  │  O  │  P  │  '  │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │ ESC │  A  │  S  │  D  │  F  │  G  │   │  H  │  J  │  K  │  L  │  ;  │BKSPC│
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │  ⇧  │  Z  │  X  │  C  │  V  │  B  │   │  N  │  M  │  ,  │  .  │  /  │ENTER│
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │ ADJ │CTRL │  ⌥  │  ⌘  │LOWER│ SPC │   │ SPC │RAISE│LEFT │ UP  │ DOWN│ RGHT│
   *            └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
   */
[_QWERTY] = LAYOUT_ortho_4x12( \
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT, \
   KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_BSPC, \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
   ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,  KC_SPC,  KC_SPC,   RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Base layer (Colemak Mod-DH)
   *            ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
   *            │     │  Q  │  W  │  F  │  P  │  B  │   │  J  │  L  │  U  │  Y  │  ;  │  '  │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │  A  │  R  │  S  │  T  │  G  │   │  M  │  N  │  E  │  I  │  O  │     │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │  Z  │  X  │  C  │  D  │  V  │   │  K  │  H  │  ,  │  .  │  /  │     │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │     │     │     │     │     │   │     │     │     │     │     │     │
   *            └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
   */
[_COLEMAK] = LAYOUT_ortho_4x12( \
  _______,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN, KC_QUOT, \
  _______,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,   _______, \
  _______,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,   KC_COMM,  KC_DOT, KC_SLSH, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Base layer (Norman)
   *            ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
   *            │     │  Q  │  W  │  D  │  F  │  K  │   │  J  │  U  │  R  │  L  │  ;  │  '  │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │  A  │  S  │  E  │  T  │  G  │   │  Y  │  N  │  I  │  O  │  H  │     │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │  Z  │  X  │  C  │  V  │  B  │   │  P  │  M  │  ,  │  .  │  /  │     │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │     │     │     │     │     │   │     │     │     │     │     │     │
   *            └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
   */
[_NORMAN] = LAYOUT_ortho_4x12( \
  _______,  KC_Q,    KC_W,    KC_D,    KC_F,    KC_K,    KC_J,    KC_U,    KC_R,    KC_L,   KC_SCLN, KC_QUOT, \
  _______,  KC_A,    KC_S,    KC_E,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_I,    KC_O,    KC_H,   _______, \
  _______,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_P,    KC_M,   KC_COMM,  KC_DOT, KC_SLSH, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),


/* Base layer (Dvorak)
   *            ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
   *            │     │  '  │  ,  │  .  │  P  │  Y  │   │  F  │  G  │  C  │  R  │  L  │  /  │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │  A  │  O  │  E  │  U  │  I  │   │  D  │  H  │  T  │  N  │  S  │     │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │  ;  │  Q  │  J  │  K  │  X  │   │  B  │  M  │  W  │  V  │  Z  │     │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │     │     │     │     │     │   │     │     │     │     │     │     │
   *            └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
   */
[_DVORAK] = LAYOUT_ortho_4x12( \
  _______,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,   KC_SLSH, \
  _______,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,   _______, \
  _______, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Lower
   *            ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
   *            │     │     │  ↑  │     │     │  {  │   │  }  │  7  │  8  │  9  │  /  │  =  │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │  ←  │  ↓  │  →  │     │  (  │   │  )  │  4  │  5  │  6  │  *  │     │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │Next │Vol- │Vol+ │Play │  [  │   │  ]  │  1  │  2  │  3  │  -  │     │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │     │     │     │     │     │   │     │     │  0  │  .  │  +  │     │
   *            └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
   */
[_LOWER] = LAYOUT_ortho_4x12( \
  _______, ___x___,  KC_UP , ___x___, ___x___, S(KC_LBRC), S(KC_RBRC),   KC_7 ,   KC_8 ,   KC_9 , KC_PSLS, KC_PEQL, \
  _______, KC_LEFT, KC_DOWN, KC_RGHT, ___x___, S(KC_9)   ,    S(KC_0),   KC_4 ,   KC_5 ,   KC_6 , KC_PAST, _______, \
  _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_LBRC   ,    KC_RBRC,   KC_1 ,   KC_2 ,   KC_3 , KC_PMNS, _______, \
  _______, _______, _______, _______, _______, _______   ,    _______, _______,   KC_0 ,  KC_DOT, KC_PPLS, _______  \
),

/* Raise
   *            ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
   *            │     │ F1  │ F2  │ F3  │ F4  │  {  │   │  }  │  &  │  *  │  \  │  |  │  ~  │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │ F5  │ F6  │ F7  │ F8  │  (  │   │  )  │  $  │  %  │  ^  │  `  │     │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │ F9  │ F10 │ F11 │ F12 │  [  │   │  ]  │  !  │  @  │  #  │  _  │     │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │     │     │     │     │     │   │     │     │     │     │     │     │
   *            └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
   */
[_RAISE] = LAYOUT_ortho_4x12( \
  _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , S(KC_LBRC), S(KC_RBRC), S(KC_7), S(KC_8), KC_BSLS, KC_PIPE, KC_TILD, \
  _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , S(KC_9)   ,    S(KC_0), S(KC_4), S(KC_5), S(KC_6), KC_GRV , _______, \
  _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, KC_LBRC   ,    KC_RBRC, S(KC_1), S(KC_2), S(KC_3), KC_UNDS, _______, \
  _______, _______, _______, _______, _______, _______   ,    _______, _______, _______, _______, _______, _______  \
),

/* Adjust (Lower + Raise)
   *            ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
   *            │     │RESET│     │     │     │  {  │   │  }  │     │     │     │     │     │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │     │     │     │     │  (  │   │  )  │QWRTY│COLMK│NORMN│DVORK│     │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │     │     │     │     │  [  │   │  ]  │     │     │     │     │     │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │     │     │     │     │     │   │     │     │     │     │     │     │
   *            └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
   */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______,  RESET , ___x___, ___x___, ___x___, S(KC_LBRC), S(KC_RBRC), ___x___, ___x___, ___x___, ___x___, ___x___, \
  _______, ___x___, ___x___, ___x___, ___x___, S(KC_9)   ,    S(KC_0), QWERTY , COLEMAK, NORMAN , DVORAK , _______, \
  _______, ___x___, ___x___, ___x___, ___x___, KC_LBRC   ,    KC_RBRC, ___x___, ___x___, ___x___, ___x___, _______, \
  _______, _______, _______, _______, _______, _______   ,    _______, _______, _______, _______, _______, _______ \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
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
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
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
  }
  return true;
}

// This is Filip Gokstorp's keymap file for a Let's Split.
// Fancy keyboard layout comments are taken from Noah Frederick's blog.
// Design is a mix of Noah Frederick's layout for the Planck and
// the normacos Let's Split layout, with personal modifications

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _NORMAN 0
#define _QWERTY 1
#define _LOWER 4
#define _RAISE 5
#define _CENTER 16

enum custom_keycodes {
  NORMAN = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  CENTER,
};

// Tap dance definitions
enum tap_dances {
  TD_L = 0,  // Left parens, brace
  TD_R,  // Right parens, brace
  TD_E  // 0 or e
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_L]  = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_LCBR),
  [TD_R]  = ACTION_TAP_DANCE_DOUBLE(KC_RPRN, KC_RCBR),
  [TD_E]  = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_E)
};

// Mod taps
#define SFT_ENT SFT_T(KC_ENT)  // Shift when held, Enter when tapped
#define SFT_TAB SFT_T(KC_TAB)  // Shift when held, Tab when tapped
#define SFT_ESC SFT_T(KC_ESC)  // Shift when held, Escape when tapped
#define CTL_ESC CTL_T(KC_ESC)  // Control when held, Escape when tapped
#define CTL_TAB CTL_T(KC_TAB)  // Control when held, Tab when tapped

// Tap braces / brackets / parens
#define HYPER_L ALL_T(KC_LBRC)  // Hyper when held, { when tapped
#define HYPER_R ALL_T(KC_RBRC)  // Hyper when held, } when tapped
#define TAP_L TD(TD_L)  // (, {
#define TAP_R TD(TD_R)  // ), }
#define TAP_0E TD(TD_E) // 0, e

// Mac desktop movement keys
#define DSK_L LCTL(KC_LEFT)
#define DSK_R LCTL(KC_RIGHT)
#define DSK_U LCTL(KC_UP)
#define DSK_D LCTL(KC_DOWN)

// Mac commands
#define SCSHT SCMD(KC_3)       // Takes full-screen screenshot
#define SCSLC SCMD(KC_4)       // Takes a select-area screenshot
#define W_L   SCMD(KC_LBRC)    // Shifts view one tab to the left
#define W_R   SCMD(KC_RBRC)    // Shifts view one tab to the right
#define SCLCK S(LCTL(KC_PWR)) // Locks the screen on a Mac

// Fillers to make layering more clear
#define _______ KC_TRNS
#define ___x___ KC_NO

// Split key layers for ease of programming / clarity

// NORMAN layer
#define _________________NORMAN_L1_________________ KC_Q,    KC_W,    KC_D,    KC_F,    KC_K
#define _________________NORMAN_L2_________________ KC_A,    KC_S,    KC_E,    KC_T,    KC_G
#define _________________NORMAN_L3_________________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________NORMAN_R1_________________ KC_J,    KC_U,    KC_R,    KC_L,    KC_SCLN
#define _________________NORMAN_R2_________________ KC_Y,    KC_N,    KC_I,    KC_O,    KC_H
#define _________________NORMAN_R3_________________ KC_P,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

// QWERTY layer
#define _________________QWERTY_L1_________________ KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________ KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________ KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________ KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________ KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define LETS_SPLIT(...) LAYOUT_ortho_4x12(__VA_ARGS__)  // macro wrapper to manage with above definitions


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Modifiers, not a separate layer, used on the first layer
 *            ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
 *            │ DEL │     │     │     │     │     │   │     │     │     │     │     │     │
 *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
 *            │⌃/TAB│     │     │     │     │     │   │     │     │     │     │     │     │
 *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
 *            │⇧/ESC│     │     │     │     │     │   │     │     │     │     │     │⇧/ENT│
 *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
 *            │TAP L│HYPER│  ⌥  │  ⌘  │LOWER│ SPC │   │BSPC │RAISE│  ⌘  │  ⌥  │HYPER│TAP R│
 *            └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
 */

/* Base layer (Norman)
 *            ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
 *            │     │  Q  │  W  │  D  │  F  │  K  │   │  J  │  U  │  R  │  L  │  ;  │  \  │
 *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
 *            │     │  A  │  S  │  E  │  T  │  G  │   │  Y  │  N  │  I  │  O  │  H  │  '  │
 *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
 *            │     │  Z  │  X  │  C  │  V  │  B  │   │  P  │  M  │  ,  │  .  │  /  │     │
 *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
 *            │     │     │     │     │     │     │   │     │     │     │     │     │     │
 *            └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
 */
[_NORMAN] = LETS_SPLIT( \
   KC_DEL, _________________NORMAN_L1_________________, _________________NORMAN_R1_________________, KC_BSLS, \
  CTL_TAB, _________________NORMAN_L2_________________, _________________NORMAN_R2_________________, KC_QUOT, \
  SFT_ESC, _________________NORMAN_L3_________________, _________________NORMAN_R3_________________, SFT_ENT, \
   TAP_L , HYPER_L, KC_LALT, KC_LCMD,   LOWER,  KC_SPC, KC_BSPC,   RAISE, KC_RCMD, KC_RALT, HYPER_R,  TAP_R   \
),

/* Base layer (Qwerty, back-up layer)
 *            ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
 *            │     │  Q  │  W  │  E  │  R  │  T  │   │  Y  │  U  │  I  │  O  │  P  │  \  │
 *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
 *            │     │  A  │  S  │  D  │  F  │  G  │   │  H  │  J  │  K  │  L  │  ;  │  '  │
 *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
 *            │     │  Z  │  X  │  C  │  V  │  B  │   │  N  │  M  │  ,  │  .  │  /  │     │
 *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
 *            │     │     │     │     │     │     │   │     │     │     │     │     │     │
 *            └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
 */
[_QWERTY] = LETS_SPLIT( \
  _______, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSLS, \
  _______, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_QUOT, \
  _______, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Lower (Numbers and Desktop Navigation)
   *            ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
   *            │     │SCSHT│SCSLC│ W_L │ W_R │  {  │   │  }  │  &  │  *  │  \  │  [  │  ]  │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │  ←  │  ↑  │  ↓  │  →  │  (  │   │  )  │  $  │  %  │  ^  │  (  │  )  │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │Next │Vol- │Vol+ │Play │  [  │   │  ]  │  !  │  @  │  #  │  |  │     │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │SCLCK│     │     │     │     │     │   │     │     │  `  │  ~  │     │     │
   *            └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
   */
[_LOWER] = LETS_SPLIT( \
  _______,  SCSHT ,  SCSLC ,   W_L  ,   W_R  , KC_LCBR, KC_RCBR, S(KC_7), S(KC_8), KC_BSLS, KC_LBRC, KC_RBRC, \
  _______,  DSK_L ,  DSK_U ,  DSK_D ,  DSK_R , KC_LPRN, KC_RPRN, S(KC_4), S(KC_5), S(KC_6), KC_LPRN, KC_RPRN, \
  _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_LBRC, KC_RBRC, S(KC_1), S(KC_2), S(KC_3), KC_PIPE, _______, \
   SCLCK , _______, _______, _______, _______, _______, _______, _______,  KC_GRV, KC_TILD, _______, _______  \
),

/* Raise (Symbols and navigation keys)
   *            ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
   *            │     │     │     │  ↑  │     │  {  │   │  }  │  7  │  8  │  9  │  /  │  =  │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │     │  ←  │  ↓  │  →  │  (  │   │  )  │  4  │  5  │  6  │  *  │  _  │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │     │     │     │     │  [  │   │  ]  │  1  │  2  │  3  │  -  │  +  │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │     │     │     │     │     │   │     │     │  0  │  .  │  ,  │ SPC │
   *            └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
   */
[_RAISE] = LETS_SPLIT( \
  _______,  KC_F1 ,  KC_F2 ,  KC_UP , ___x___, KC_LCBR, KC_RCBR,   KC_7 ,   KC_8 ,   KC_9 , KC_PSLS, KC_PEQL, \
  _______,  KC_F5 , KC_LEFT, KC_DOWN, KC_RGHT, KC_LPRN, KC_RPRN,   KC_4 ,   KC_5 ,   KC_6 , KC_PAST, KC_UNDS, \
  _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, KC_LBRC, KC_RBRC,   KC_1 ,   KC_2 ,   KC_3 , KC_PMNS, KC_PPLS, \
  _______, _______, _______, _______, _______, _______, _______, _______,  TAP_0E,  KC_DOT, KC_COMM, KC_SPC  \
),

/* Center (Lower + Raise)  (Function keys and misc)
   *            ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
   *            │RESET│ F1  │ F2  │ F3  │ F4  │  {  │   │  }  │     │     │     │     │     │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │ F5  │ F6  │ F7  │ F8  │  (  │   │  )  │NORMN│QWRTY│     │     │     │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │ F9  │ F10 │ F11 │ F12 │  [  │   │  ]  │     │     │     │     │     │
   *            ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
   *            │     │     │     │     │     │     │   │     │     │     │     │     │     │
   *            └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
   */
[_CENTER] = LETS_SPLIT( \
   RESET ,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , KC_LCBR, KC_RCBR, ___x___, ___x___, ___x___, ___x___, ___x___, \
  ___x___,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , KC_LPRN, KC_RPRN,  NORMAN,  QWERTY, ___x___, ___x___, ___x___, \
  ___x___,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, KC_LBRC, KC_RBRC, ___x___, ___x___, ___x___, ___x___, ___x___, \
  ___x___, ___x___, ___x___, ___x___, _______, _______, _______, _______, ___x___, ___x___, ___x___, ___x___  \
)

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NORMAN:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_NORMAN);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _CENTER);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _CENTER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _CENTER);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _CENTER);
      }
      return false;
      break;
    case CENTER:
      if (record->event.pressed) {
        layer_on(_CENTER);
      } else {
        layer_off(_CENTER);
      }
      return false;
      break;
  }
  return true;
}

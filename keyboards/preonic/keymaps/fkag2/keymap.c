/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _NORMAN,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  NORMAN,
  LOWER,
  RAISE,
  BACKLIT
};

// Tap dance definitions
enum tap_dances {
  TD_L = 0,  // Left parens, brace
  TD_R,  // Right parens, brace
  TD_E  // dot or e
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_L]  = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_LCBR),
  [TD_R]  = ACTION_TAP_DANCE_DOUBLE(KC_RPRN, KC_RCBR),
  [TD_E]  = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_E)
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
#define TAP_DE TD(TD_E) // ., e

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

// top number layer
#define _________________NUMBER_L0_________________ KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _________________NUMBER_R0_________________ KC_6,    KC_7,    KC_8,    KC_9,    KC_0

// QWERTY layer
#define _________________QWERTY_L1_________________ KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________ KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________ KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________ KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________ KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

// NORMAN layer
#define _________________NORMAN_L1_________________ KC_Q,    KC_W,    KC_D,    KC_F,    KC_K
#define _________________NORMAN_L2_________________ KC_A,    KC_S,    KC_E,    KC_T,    KC_G
#define _________________NORMAN_L3_________________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________NORMAN_R1_________________ KC_J,    KC_U,    KC_R,    KC_L,    KC_SCLN
#define _________________NORMAN_R2_________________ KC_Y,    KC_N,    KC_I,    KC_O,    KC_H
#define _________________NORMAN_R3_________________ KC_P,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define PREONIC(...) LAYOUT_preonic_grid(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Modifiers / base
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │     │     │     │     │     │     │     │     │     │     │     │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │ DEL │     │     │     │     │     │     │     │     │     │     │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │⌃/TAB│     │     │     │     │     │     │     │     │     │     │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │⇧/ESC│     │     │     │     │     │     │     │     │     │     │⇧/ENT│
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │TAP L│HYPER│  ⌥  │  ⌘  │LOWER│ SPC │BSPC │RAISE│  ⌘  │  ⌥  │HYPER│TAP R│
     * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */

    /* QWERTY
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │  `  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  §  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  \  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │     │     │     │     │     │     │     │     │
     * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
    [_QWERTY] = PREONIC(\
       KC_GRV, _________________NUMBER_L0_________________, _________________NUMBER_R0_________________, KC_BSPC, \
       KC_DEL, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSLS, \
      CTL_TAB, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_QUOT, \
      SFT_ESC, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, SFT_ENT, \
        TAP_L, BACKLIT, KC_LALT,  KC_LCMD,  LOWER,  KC_SPC, KC_BSPC,  RAISE,  KC_RCMD,  KC_RALT,  KC_UP, TAP_R \
    ),

    /* NORMAN
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │  `  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  §  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │  Q  │  W  │  D  │  F  │  K  │  J  │  U  │  R  │  L  │  ;  │  \  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │  A  │  S  │  E  │  T  │  G  │  Y  │  N  │  I  │  O  │  H  │  '  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │  Z  │  X  │  C  │  V  │  B  │  P  │  M  │  ,  │  .  │  /  │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │     │     │     │     │     │     │     │     │
     * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
    [_NORMAN] = PREONIC(\
       KC_GRV, _________________NUMBER_L0_________________, _________________NUMBER_R0_________________, KC_BSPC, \
       KC_DEL, _________________NORMAN_L1_________________, _________________NORMAN_R1_________________, KC_BSLS, \
      CTL_TAB, _________________NORMAN_L2_________________, _________________NORMAN_R2_________________, KC_QUOT, \
      SFT_ESC, _________________NORMAN_L3_________________, _________________NORMAN_R3_________________, SFT_ENT, \
        TAP_L, BACKLIT, KC_LALT,  KC_LCMD,  LOWER,  KC_SPC, KC_BSPC,  RAISE,  KC_RCMD,  KC_RALT,  KC_UP, TAP_R \
    ),

    /* Lower
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │  ~  │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  \  │  [  │  ]  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │SCSHT│SCSLC│ W_L │ W_R │  {  │  }  │  $  │  %  │  ^  │  (  │  )  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │  ←  │  ↑  │  ↓  │  →  │  (  │  )  │  !  │  @  │  #  │  {  │  }  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │ Next│ Vol-│ Vol+│ Play│  [  │  ]  │     │  `  │  ~  │  |  │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │SCLCK│     │     │     │     │     │     │     │     │     │     │     │
     * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
    [_LOWER] = PREONIC( \
      _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), KC_BSLS, KC_LBRC, KC_RBRC, \
      _______,   SCSHT,   SCSLC,     W_L,     W_R, KC_LCBR, KC_RCBR, S(KC_4), S(KC_5), S(KC_6), KC_LPRN, KC_RPRN, \
      _______,   DSK_L,   DSK_U,   DSK_D,   DSK_R, KC_LPRN, KC_RPRN, S(KC_1), S(KC_2), S(KC_3), KC_LCBR, KC_RCBR, \
      _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_LBRC, KC_RBRC, ___x___, KC_GRV,  KC_TILD, KC_PIPE, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
    ),

    /* Raise
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │  `  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  /  │  =  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │ HOME│  ↑  │ END │     │  {  │  }  │  4  │  5  │  6  │  *  │  _  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │  ←  │  ↓  │  →  │     │  (  │  )  │  1  │  2  │  3  │  -  │  +  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │ Next│ Vol-│ Vol+│ Prev│  [  │  ]  │     │  0  │  .  │  ,  │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │     │     │     │     │     │     │     │     │
     * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
    [_RAISE] = PREONIC( \
       KC_GRV,    KC_1,   KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9, KC_PSLS, KC_PEQL, \
      _______, KC_HOME,  KC_UP,   KC_END, ___x___, KC_LCBR, KC_RCBR,    KC_4,    KC_5,    KC_6, KC_PAST, KC_UNDS, \
      _______, KC_LEFT, KC_DOWN, KC_RGHT, ___x___, KC_LPRN, KC_RPRN,    KC_1,    KC_2,    KC_3, KC_PMNS, KC_PPLS, \
      _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_LBRC, KC_RBRC, KC_NUHS,    KC_0,  TAP_DE, KC_COMM, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
    ),

    /* Adjust (Lower + Raise)
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │     │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │RESET│ F5  │ F6  │ F7  │ F8  │  {  │  }  │TrmOn│TrmOf│AudOn│AudOf│AGnrm│
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │DEBUG│ F9  │ F10 │ F11 │ F12 │  (  │  )  │QWRTY│NORMN│MdiOn│MdiOf│AGswp│
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │     │  [  │  ]  │     │MusMd│MusOn│MusOf│     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │     │     │     │     │     │     │     │     │
     * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
    [_ADJUST] = PREONIC( \
      ___x___,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, ___x___, \
        RESET,   KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_LCBR, KC_RBRC, TERM_ON,TERM_OFF,   AU_ON,  AU_OFF, AG_NORM, \
        DEBUG,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_LPRN, KC_RPRN,  QWERTY,  NORMAN,   MI_ON,  MI_OFF, AG_SWAP, \
      _______, ___x___, ___x___, ___x___, ___x___, KC_LBRC, KC_RBRC, ___x___,  MU_MOD,   MU_ON,  MU_OFF, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
    )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case NORMAN:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_NORMAN);
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
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            PORTE &= ~(1<<6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            PORTE |= (1<<6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

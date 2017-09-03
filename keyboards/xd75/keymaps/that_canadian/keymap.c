/* Copyright 2017 REPLACE_WITH_YOUR_NAME
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
#include "xd75.h"

// Fillers to make layering more clear
#define _______ KC_TRNS
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO

// Layer shorthand
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FUNC 3

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------'--------------------'-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   +  |   -  |Enter |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|------+------+------|------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   7  |   8  |   9  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|------+------+------|------+------+------+------+------+------|
 * | Func |   A  |   S  |   D  |   F  |   G  |   4  |   5  |   6  |   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------|------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   1  |   2  |   3  |   N  |   M  |   ,  |   .  |   /  |  '   |
 * |------+------+------+------+------+------|------+------+------|------+------+------+------+------+------|
 * | Ctrl |  `   | GUI  | Alt  |Lower | Space|   ,  |   0  |   .  | Bksp |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------'--------------------'-----------------------------------------'
 */
	
 [_QWERTY] = { /* QWERTY */
  { KC_ESC,        KC_1,   KC_2,    KC_3,    KC_4,       KC_5,  /**/KC_PLUS, KC_MINS, KC_ENT,/**/KC_6,    KC_7,       KC_8,    KC_9,    KC_0,    KC_DEL },
  { KC_TAB,        KC_Q,   KC_W,    KC_E,    KC_R,       KC_T,  /**/KC_7,    KC_8,    KC_9,  /**/KC_Y,    KC_U,       KC_I,    KC_O,    KC_P,    KC_BSPC },
  { MO(_FUNC),     KC_A,   KC_S,    KC_D,    KC_F,       KC_G,  /**/KC_4,    KC_5,    KC_6,  /**/KC_H,    KC_J,       KC_K,    KC_L,    KC_SCLN, KC_ENT  },
  { OSM(MOD_LSFT), KC_Z,   KC_X,    KC_C,    KC_V,       KC_B,  /**/KC_1,    KC_2,    KC_3,  /**/KC_N,    KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT },
  { KC_LCTL,       KC_GRV, KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC,/**/KC_COMM, KC_0,    KC_DOT,/**/KC_BSPC, MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT }
 },

/* Lower
 * ,-----------------------------------------'--------------------'-----------------------------------------.
 * |   `  |   F1 |   F2 |   F3 |   F4 |   F5 |  F11 |  F12 |  F13 |   F6 |   F7 |   F8 |   F9 |  F10 |      |
 * |------+------+------+------+------+------|------+------+------|------+------+------+------+------+------|
 * | Esc  |   !  |   @  |   #  |   $  |   %  |Taskmg|      |caltde|   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------|------+------+------|------+------+------+------+------+------|
 * | Func |      |      |      |      |      |      |      |      |      |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------|------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      | Mute |      |  |   |
 * |------+------+------+------+------+------|------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |Lower |      |      |      |      | Enter|Raise | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------'--------------------'-----------------------------------------'
 */
 
 [_LOWER] = { /* Lower */
  { KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  /**/KC_F11,  KC_F12,  KC_F13, /**/KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______ },
  { KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,/**/TSKMGR,  _______, CALTDEL,/**/KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL },
  { ___T___, _______, _______, _______, _______, _______,/**/_______, _______, _______,/**/_______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______ },
  { _______, _______, _______, _______, _______, _______,/**/_______, _______, _______,/**/_______, _______, _______, KC_MUTE, _______, KC_PIPE },
  { _______, _______, _______, _______, ___T___, _______,/**/_______, _______, _______,/**/KC_ENT,  ___T___, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY }
 },

/* Raise
 * ,-----------------------------------------'--------------------'-----------------------------------------.
 * |   `  |   F1 |   F2 |   F3 |   F4 |   F5 |  F11 |  F12 |  F13 |   F6 |   F7 |   F8 |   F9 |  F10 |      |
 * |------+------+------+------+------+------|------+------+------|------+------+------+------+------+------|
 * | Esc  |   1  |   2  |   3  |   4  |   5  |Taskmg|      |caltde|   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|------+------+------|------+------+------+------+------+------|
 * | Func |      |      |      |      |      |      |      |      |      |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------|------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      | Mute |      |   \  |
 * |------+------+------+------+------+------|------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |Lower |      |      |BACKLI|      |      |Raise | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------'--------------------'-----------------------------------------'
 */
 
 [_RAISE] = { /* Raise */
  { KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  /**/KC_PLUS, KC_MINS, KC_ENT, /**/KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______ },
  { KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   /**/TSKMGR,  _______, CALTDEL,/**/KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL  },
  { ___T___, _______, _______, _______, _______, _______,/**/_______, _______, _______,/**/_______, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, _______ },
  { _______, _______, _______, _______, _______, _______,/**/_______, _______, _______,/**/_______, _______, _______, KC_MUTE, _______, KC_PIPE },
  { _______, _______, _______, _______, ___T___, _______,/**/_______, BACKLIT, _______,/**/_______, ___T___, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY }
 },
 
/* Function
 * ,-----------------------------------------'--------------------'-----------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------|------+------+------|------+------+------+------+------+------|
 * | Func |      |      |      |      |      |      |      |      |      | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|------+------+------|------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |Lower |      |      |      |      |      |Raise |      |      |      | RESET|
 * `-----------------------------------------'--------------------'-----------------------------------------'
 */
 
 [_FUNC] = { /* Function */
  { _______, _______, _______, _______, _______, _______,/**/_______, _______, _______,/**/_______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______,/**/_______, _______, _______,/**/_______, _______, KC_UP,   _______, _______, _______ },
  { ___T___, _______, _______, _______, _______, _______,/**/_______, _______, _______,/**/_______, KC_LEFT, KC_DOWN, KC_RGHT, KC_RCBR, _______ },
  { KC_CAPS, _______, _______, _______, _______, _______,/**/_______, _______, _______,/**/_______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, ___T___, _______,/**/_______, _______, _______,/**/_______, ___T___, _______, _______, _______, RESET }
 },
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
  }
  return true;
}

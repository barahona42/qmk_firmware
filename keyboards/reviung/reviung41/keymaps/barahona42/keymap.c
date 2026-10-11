/* Copyright 2020 gtips
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
#include <stdio.h>
#include "keycodes.h"
#include "process_combo.h"
#include "barahona42.c"
#include "gpio.h"

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _FUNCS,
    _SPECS
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCS MO(_FUNCS)
#define SPECS MO(_SPECS)

#define LOW_SPC LT(_LOWER, KC_SPC)
#define RAI_SPC LT(_RAISE, KC_SPC)

#define MC_UP    LCTL(LGUI(KC_UP))
#define MC_DOWN  LCTL(LGUI(KC_DOWN))
#define MC_LEFT  LCTL(LGUI(KC_LEFT))
#define MC_RIGHT LCTL(LGUI(KC_RIGHT))
#define MCS_UP   LCTL(LSFT(LGUI(KC_UP)))
#define MCS_DOWN LCTL(LSFT(LGUI(KC_DOWN)))

#define CK_CPY  LGUI(KC_C)
#define CK_PST  LGUI(KC_V)
#define CK_CUT  LGUI(KC_X)
#define CK_TAB  LCTL(KC_TAB)
#define CK_TABS LCTL(LSFT(KC_TAB))

combo_t            key_combos[]        = {};
tap_dance_action_t tap_dance_actions[] = {};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
 // ----------,----------,----------,----------,----------,----------,----------,----------,----------,----------,----------,----------,----------,
    KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                 KC_Y,      KC_U,      KC_I ,     KC_O,      KC_P,      KC_BSPC,
    KC_ESC,    KC_A,      LCTL_S,    LALT_D,    LGUI_F,    LSFT_G,               RSFT_H,    RGUI_J,    RALT_K,    RCTL_L,    KC_SCLN,   KC_QUOT,
    KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,                 KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_ENT,
                                                LSFT_MIN,  LOW_SPC,   RAISE,     RAI_SPC,   RSFT_MIN
  ),
  [_LOWER] = LAYOUT(
 // ----------,----------,----------,----------,----------,----------,----------,----------,----------,----------,----------,----------,----------,
    _______,   KC_PLUS,   _______,   _______,   _______,   _______,              _______,   KC_TILDE,  KC_LPRN,   KC_RPRN,   KC_EQL,    KC_DEL,
    _______,   KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    _______,              _______,   KC_UNDS,   KC_LBRC,   KC_RBRC,   KC_PIPE,   KC_BSLS,
    _______,   KC_PERC,   KC_CIRC,   KC_AMPR,   KC_ASTR,   _______,              _______,   KC_MINUS,  KC_LCBR,   KC_RCBR,   KC_GRAVE,  _______,
                                                _______,   _______,   _______,   _______,   _______
  ),
  [_RAISE] = LAYOUT(
 // ----------,----------,----------,----------,----------,----------,----------,----------,----------,----------,----------,----------,----------,
    _______,   _______,   KC_UP,     _______,   KC_PGUP,   _______,              _______,   KC_7,      KC_8,      KC_9,      _______,   KC_DEL,
    _______,   KC_LEFT,   KC_DOWN,   KC_RIGHT,  KC_PGDN,   _______,              _______,   KC_4,      KC_5,      KC_6,      _______,   _______,
    _______,   CK_TABS,   CK_TAB,    CK_CPY,    CK_PST,    CK_CUT,               _______,   KC_1,      KC_2,      KC_3,      _______,   _______,
                                                _______,   _______,   _______,   _______,   KC_0
  ),
  [_SPECS] = LAYOUT(
 // ----------,----------,----------,----------,----------,----------,----------,----------,----------,----------,----------,----------,----------,
    KC_VOLU,   MCS_DOWN,  MC_UP,     MCS_UP,    UG_VALU,   UG_SPDU,              KC_F12,    KC_F7,     KC_F8,     KC_F9,     _______,   _______,
    KC_VOLD,   MC_LEFT,   MC_DOWN,   MC_RIGHT,  UG_VALD,   UG_SPDD,              KC_F11,    KC_F4,     KC_F5,     KC_F6,     _______,   _______,
    KC_MUTE,   _______,   _______,   _______,   RGB_TOG,   RGB_MOD,              KC_F10,    KC_F1,     KC_F2,     KC_F3,     _______,   _______,
                                                _______,   _______,   _______,   _______,   _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _SPECS);
}

void keyboard_pre_init_user(void) {
    gpio_set_pin_output(24);
    gpio_write_pin_high(24);
}

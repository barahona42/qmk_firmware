/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
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

#include "process_combo.h"

// enum {
//     COMBO_OSX_DESKTOP_LEFT,
//     COMBO_OSX_DESKTOP_RIGHT,
//     COMBO_OSX_SHOW_WINDOWS,
//     COMBO_OSX_SHOW_DESKTOP,
// };

// const uint16_t PROGMEM combo_osx_desktop_left[] = {COMBO_END};
// const uint16_t PROGMEM combo_osx_desktop_right[] = {COMBO_END};
// const uint16_t PROGMEM combo_osx_show_windows[] = {COMBO_END};
// const uint16_t PROGMEM combo_osx_show_desktop[] = {COMBO_END};

// combo_t key_combos[] = {
//     [COMBO_OSX_DESKTOP_LEFT] = COMBO(combo_osx_desktop_left, LCTL(LALT(KC_LEFT))),
//     [COMBO_OSX_DESKTOP_RIGHT] = COMBO(combo_osx_desktop_right, LCTL(LALT(KC_RIGHT))),
//     [COMBO_OSX_SHOW_WINDOWS] = COMBO(combo_osx_show_windows, LCTL(LALT(KC_UP))),
//     [COMBO_OSX_SHOW_DESKTOP] = COMBO(combo_osx_show_desktop, LCTL(LALT(KC_DOWN))),
// };


enum custom_keycodes {
    CTL_GUI_LEFT = SAFE_RANGE,
    CTL_GUI_RIGHT,
    CTL_GUI_UP,
    CTL_GUI_DOWN,
    CTL_GUI_1,
    CTL_GUI_2,
    CTL_GUI_3,
    CTL_GUI_4,
    CTL_GUI_5,
    CTL_GUI_6,
    CTL_GUI_7,
    CTL_GUI_8,
    CTL_GUI_9,
    CTL_GUI_0,
};

bool _handle_lctl_lgui_tap(bool pressed, char* keys) {
    if (pressed){ SEND_STRING(keys); }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_GUI_LEFT:
            return _handle_lctl_lgui_tap(record->event.pressed, SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(X_LEFT)SS_UP(X_LCTL)SS_UP(X_LGUI));
        case CTL_GUI_RIGHT:
            return _handle_lctl_lgui_tap(record->event.pressed, SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(X_RIGHT)SS_UP(X_LCTL)SS_UP(X_LGUI));
        case CTL_GUI_UP:
            return _handle_lctl_lgui_tap(record->event.pressed, SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(X_UP)SS_UP(X_LCTL)SS_UP(X_LGUI));
        case CTL_GUI_DOWN:
            return _handle_lctl_lgui_tap(record->event.pressed, SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(X_DOWN)SS_UP(X_LCTL)SS_UP(X_LGUI));
        case CTL_GUI_1:
            return _handle_lctl_lgui_tap(record->event.pressed, SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(X_1)SS_UP(X_LCTL)SS_UP(X_LGUI));
        case CTL_GUI_2:
            return _handle_lctl_lgui_tap(record->event.pressed, SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(X_2)SS_UP(X_LCTL)SS_UP(X_LGUI));
        case CTL_GUI_3:
            return _handle_lctl_lgui_tap(record->event.pressed, SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(X_3)SS_UP(X_LCTL)SS_UP(X_LGUI));
        case CTL_GUI_4:
            return _handle_lctl_lgui_tap(record->event.pressed, SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(X_4)SS_UP(X_LCTL)SS_UP(X_LGUI));
        case CTL_GUI_5:
            return _handle_lctl_lgui_tap(record->event.pressed, SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(X_5)SS_UP(X_LCTL)SS_UP(X_LGUI));
        case CTL_GUI_6:
            return _handle_lctl_lgui_tap(record->event.pressed, SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(X_6)SS_UP(X_LCTL)SS_UP(X_LGUI));
        case CTL_GUI_7:
            return _handle_lctl_lgui_tap(record->event.pressed, SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(X_7)SS_UP(X_LCTL)SS_UP(X_LGUI));
        case CTL_GUI_8:
            return _handle_lctl_lgui_tap(record->event.pressed, SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(X_8)SS_UP(X_LCTL)SS_UP(X_LGUI));
        case CTL_GUI_9:
            return _handle_lctl_lgui_tap(record->event.pressed, SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(X_9)SS_UP(X_LCTL)SS_UP(X_LGUI));
        case CTL_GUI_0:
            return _handle_lctl_lgui_tap(record->event.pressed, SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(X_0)SS_UP(X_LCTL)SS_UP(X_LGUI));
    }
    return true;
};

enum custom_layers {
    L0, // primary layer
    L1, // momentary fn layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[L0] = LAYOUT(
  QK_GESC,  KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,         KC_F10,        KC_F11,         KC_F12,         KC_DEL,     KC_HOME,   KC_END,    KC_PGUP,  KC_PGDN,
  KC_GRV,   KC_1,       KC_2,       KC_3,       KC_4,       KC_5,      KC_6,     KC_7,     KC_8,     KC_9,          KC_0,          KC_MINS,        KC_EQL,         KC_BSPC,    KC_NUM,    KC_PSLS,   KC_PAST,  KC_PMNS,
  KC_TAB,   KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,          KC_P,          KC_LBRC,        KC_RBRC,        KC_BSLS,    KC_P7,     KC_P8,     KC_P9,    KC_PPLS,
  KC_CAPS,  KC_A,       KC_S,       KC_D,       KC_F,       KC_G,      KC_H,     KC_J,     KC_K,     KC_L,          KC_SCLN,       KC_QUOT,        KC_ENT,         KC_P4,      KC_P5,     KC_P6,
  KC_LSFT,  KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,      KC_N,     KC_M,     KC_COMM,  KC_DOT,        KC_SLSH,       KC_RSFT,        KC_UP,          KC_P1,      KC_P2,     KC_P3,     KC_PENT,
  KC_LCTL,  KC_LALT,    KC_LGUI,                    KC_SPC,                                  KC_RALT,  MO(L1),   KC_RCTL,       KC_LEFT,       KC_DOWN,        KC_RGHT,        KC_P0,      KC_PDOT),

[L1] = LAYOUT(
  RGB_TOG,  KC_MPLY,    KC_MPRV,    KC_MNXT,    _______,    _______,   _______,    _______,    _______,    _______,       _______,       KC_VOLD,        KC_VOLU,        KC_MUTE,     _______,  _______,   _______,  QK_BOOTLOADER,
  RGB_VAI,  CTL_GUI_1,  CTL_GUI_2,  CTL_GUI_3,  CTL_GUI_4,  CTL_GUI_5, CTL_GUI_6,  CTL_GUI_7,  CTL_GUI_8,  CTL_GUI_9,     CTL_GUI_0,     _______,        _______,        _______,     _______,  _______,   _______,  _______,
  RGB_VAD,  _______,    KC_UP,      _______,    _______,    _______,   _______,    _______,    _______,    _______,       CTL_GUI_UP,    _______,        _______,        _______,     _______,  _______,   _______,  _______,
  RGB_SPI,  KC_LEFT,    KC_DOWN,    KC_RIGHT,   _______,    _______,   _______,    _______,    _______,    CTL_GUI_LEFT,  CTL_GUI_DOWN,  CTL_GUI_RIGHT,  _______,        _______,     _______,  _______,
  RGB_SPD,  RGB_M_P,    RGB_M_K,    RGB_M_G,    RGB_M_TW,   _______,   _______,    _______,    _______,    _______,       _______,       _______,        _______,        _______,     _______,   _______,   _______,
  _______,  _______,    _______,                    _______,                                   _______,    _______,    _______,       _______,       _______,        _______,        _______,     _______),
};

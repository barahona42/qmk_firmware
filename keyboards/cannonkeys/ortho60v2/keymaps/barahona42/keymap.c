/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include "process_combo.h"

#define LCTL_LGUI(keycode)SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(keycode)SS_UP(X_LCTL)SS_UP(X_LGUI)


bool handle_tap(keyrecord_t *record, char *keycode) {
    if (record->event.pressed) {
        send_string(keycode);
    }
    return true;
}

enum custom_keycodes {
    CGUIL = SAFE_RANGE,
    CGUIR,
    CGUIU,
    CGUID,
    CGUI1,
    CGUI2,
    CGUI3,
    CGUI4,
    CGUI5,
    CGUI6,
    CGUI7,
    CGUI8,
    CGUI9,
    CGUI0,
    CK_RAISE,
    CK_LOWER,
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CGUIL:
            return handle_tap(record, LCTL_LGUI(X_LEFT));
        case CGUIR:
            return handle_tap(record, LCTL_LGUI(X_RIGHT));
        case CGUIU:
            return handle_tap(record, LCTL_LGUI(X_UP));
        case CGUID:
            return handle_tap(record, LCTL_LGUI(X_DOWN));
        case CGUI1:
            return handle_tap(record, LCTL_LGUI(X_1));
        case CGUI2:
            return handle_tap(record, LCTL_LGUI(X_2));
        case CGUI3:
            return handle_tap(record, LCTL_LGUI(X_3));
        case CGUI4:
            return handle_tap(record, LCTL_LGUI(X_4));
        case CGUI5:
            return handle_tap(record, LCTL_LGUI(X_5));
        case CGUI6:
            return handle_tap(record, LCTL_LGUI(X_6));
        case CGUI7:
            return handle_tap(record, LCTL_LGUI(X_7));
        case CGUI8:
            return handle_tap(record, LCTL_LGUI(X_8));
        case CGUI9:
            return handle_tap(record, LCTL_LGUI(X_9));
        case CGUI0:
            return handle_tap(record, LCTL_LGUI(X_0));
    }
    return true;
};

enum custom_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ortho_5x12(
        KC_ESC,     KC_1,       KC_2,       KC_3,        KC_4,        KC_5,      KC_6,        KC_7,        KC_8,          KC_9,       KC_0,       _______,
        KC_TAB,     KC_Q,       KC_W,       KC_E,        KC_R,        KC_T,      KC_Y,        KC_U,        KC_I,          KC_O,       KC_P,       KC_BSPC,
        KC_CAPS,    KC_A,       KC_S,       KC_D,        KC_F,        KC_G,      KC_H,        KC_J,        KC_K,          KC_L,       KC_SCLN,    KC_QUOT,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,        KC_V,        KC_B,      KC_N,        KC_M,        KC_COMM,       KC_DOT,     KC_SLSH,    KC_ENT,
        KC_LCTL,    KC_LALT,    KC_LGUI,    MO(_LOWER),  KC_SPC,      KC_SPC,   KC_SPC,       KC_SPC,      MO(_RAISE),    KC_RSFT,    KC_RALT,    KC_RCTL
    ),
    [_LOWER] = LAYOUT_ortho_5x12(
        _______,    _______,    _______,    _______,     _______,     _______,   _______,     _______,     _______,       _______,    _______,    _______,
        _______,    _______,    _______,    _______,     _______,     _______,   _______,     KC_7,        KC_8,          KC_9,       _______,    _______,
        _______,    _______,    _______,    _______,     _______,     _______,   _______,     KC_4,        KC_5,          KC_6,       _______,    _______,
        _______,    _______,    _______,    _______,     _______,     _______,   _______,     KC_1,        KC_2,          KC_3,       KC_DEL,    _______,
        _______,    _______,    _______,    _______,     _______,     _______,   _______,     KC_0,     MO(_FN),       _______,    _______,    _______
    ),
    [_RAISE] = LAYOUT_ortho_5x12(
        KC_GRV,     _______,    KC_UP,      _______,     KC_PERC,     KC_CIRC,   KC_AMPR,     KC_ASTR,     KC_LPRN,       KC_RPRN,    KC_EQL,     KC_DEL,
        _______,    KC_LEFT,    KC_DOWN,    KC_RIGHT,    KC_AT,       KC_HASH,   _______,     KC_MINS,     KC_AMPR,       KC_LBRC,    KC_RBRC,    KC_BSLS,
        _______,    _______,    _______,    _______,     KC_UNDS,     _______,   _______,     KC_EXLM,     KC_DLR,        _______,    _______,    KC_PIPE,
        _______,    _______,    _______,    _______,     _______,     _______,   _______,     _______,     _______,       _______,    _______,    _______,
        _______,    _______,    _______,    MO(_FN),     _______,     _______,   _______,     _______,     _______,       _______,    _______,    _______
    ),
    [_FN] = LAYOUT_ortho_5x12(
        QK_BOOT,    CGUI1,      CGUI2,      CGUI3,      CGUI4,        CGUI5,     CGUI6,       CGUI7,       CGUI8,         CGUI9,      CGUI0,      _______,
        _______,    _______,    CGUIU,      _______,    _______,      _______,   _______,     KC_F7,       KC_F8,         KC_F9,      KC_F12,     CGUI1,
        _______,    CGUIL,      CGUID,      CGUIR,      _______,      _______,   _______,     KC_F4,       KC_F5,         KC_F6,      KC_F11,     CGUI2,
        KC_CAPS,    _______,    _______,    _______,    _______,      _______,   _______,     KC_F1,       KC_F2,         KC_F3,      KC_F10,     CGUI7,
        _______,    _______,    _______,    _______,    _______,      _______,   _______,     _______,     _______,       _______,    _______,    CGUI0
    )
};

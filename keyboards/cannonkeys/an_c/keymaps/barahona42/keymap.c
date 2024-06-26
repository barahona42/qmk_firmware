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
#include "rgblight/rgblight.h"


enum custom_keycodes {
    CTL_GUI_L = SAFE_RANGE,
    CTL_GUI_R,
    CTL_GUI_U,
    CTL_GUI_D,
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
    CTL_ALT_LBRC,
    CTL_ALT_RBRC,
    KC_TEST,
};

bool _handle_ctl_alt_tap(bool pressed, char *keys) {
    if (pressed) {
        SEND_STRING(keys);
    }
    return true;
}

bool _handle_lctl_lgui_tap(bool pressed, char* keys) {
    if (pressed) {
        SEND_STRING(keys);
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_GUI_L:
            return _handle_lctl_lgui_tap(record->event.pressed, SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(X_LEFT)SS_UP(X_LCTL)SS_UP(X_LGUI));
        case CTL_GUI_R:
            return _handle_lctl_lgui_tap(record->event.pressed, SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(X_RIGHT)SS_UP(X_LCTL)SS_UP(X_LGUI));
        case CTL_GUI_U:
            return _handle_lctl_lgui_tap(record->event.pressed, SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(X_UP)SS_UP(X_LCTL)SS_UP(X_LGUI));
        case CTL_GUI_D:
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
        case CTL_ALT_LBRC:
            return _handle_ctl_alt_tap(record->event.pressed,SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_TAP(X_COMMA)SS_UP(X_LCTL)SS_UP(X_LALT));
        case CTL_ALT_RBRC:
            return _handle_ctl_alt_tap(record->event.pressed, SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_TAP(X_DOT) SS_UP(X_LCTL) SS_UP(X_LALT));
    }
    return true;
};

enum custom_layers {
    _BASE,
    _LAYER1,
    _LAYER2,
    _HALMAK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_60_ansi(
        QK_GESC,  KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,      KC_9,        KC_0,        KC_MINS,         KC_EQL,        KC_BSPC,
        KC_TAB,   KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,      KC_O,        KC_P,        KC_LBRC,         KC_RBRC,       KC_BSLS,
        KC_CAPS,  KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,      KC_L,        KC_SCLN,     KC_QUOT,                        KC_ENT,
        KC_LSFT,  KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,   KC_DOT,      KC_SLSH,                                     KC_RSFT,
        KC_LCTL,  KC_LALT,    KC_LGUI,                                        KC_SPC,                                         MO(_LAYER1),       KC_RGUI,           KC_RALT,       KC_RCTL
    ),
    [_LAYER1] = LAYOUT_60_ansi(
        KC_GRV,   KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,      KC_F11,          KC_F12,      KC_DEL,
        KC_PGUP,  _______,    KC_UP,      _______,    _______,    _______,    _______,    _______,    _______,    CTL_GUI_D,  CTL_GUI_U,   _______,         _______,     _______,
        KC_PGDN,  KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    _______,    _______,    _______,    _______,    _______,    CTL_GUI_L,   CTL_GUI_R,                    _______,
        _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                                   _______,
        _______,  _______,    _______,                                        _______,                                        _______,     MO(_LAYER2),         _______,     _______
    ),
    [_LAYER2] = LAYOUT_60_ansi(
        KC_MUTE,  CTL_GUI_1,    CTL_GUI_2,  CTL_GUI_3,  CTL_GUI_4,  CTL_GUI_5,  CTL_GUI_6,  CTL_GUI_7,  CTL_GUI_8,    CTL_GUI_9,    CTL_GUI_0,   _______,         _______,       QK_BOOT,
        KC_VOLU,  RGB_MOD,      RGB_VAI,    RGB_TOG,    _______,    _______,    _______,    _______,    _______,      _______,      KC_MPLY,     KC_MPRV,         KC_MNXT,       _______,
        KC_VOLD,  RGB_SPD,      RGB_VAD,    RGB_SPI,    _______,    _______,    _______,    _______,    _______,      _______,      _______,     _______,                        _______,
        _______,  TT(_HALMAK),  TT(_BASE),  _______,    _______,    _______,    _______,    _______,    _______,      _______,      _______,                                     _______,
        _______,  _______,      _______,                                        _______,                                            _______,     _______,         _______,       _______
    ),
    [_HALMAK] = LAYOUT_60_ansi(
        QK_GESC,  KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,        KC_MINS,         KC_EQL,       KC_BSPC,
        KC_TAB,   KC_W,       KC_L,       KC_R,       KC_B,       KC_Z,       KC_SCLN,    KC_Q,       KC_U,       KC_D,       KC_J,        KC_LBRC,         KC_RBRC,      KC_BSLS,
        KC_CAPS,  KC_S,       KC_H,       KC_N,       KC_T,       KC_COMM,    KC_DOT,     KC_A,       KC_E,       KC_O,       KC_I,        KC_QUOT,                       KC_ENT,
        KC_LSFT,  KC_F,       KC_M,       KC_V,       KC_C,       KC_SLSH,    KC_G,       KC_P,       KC_X,       KC_K,       KC_Y,                                       KC_RSFT,
        KC_LCTL,  KC_LALT,    KC_LGUI,                                        KC_SPC,                                         MO(1),       KC_RGUI,         KC_RALT,      KC_RCTL
    ),
};

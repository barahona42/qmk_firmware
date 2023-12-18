// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "helpers.h"

const uint16_t PROGMEM combo_rprn_eql[] = {KC_RPRN, KC_EQL, COMBO_END};
const uint16_t PROGMEM combo_eql_del[]   = {KC_EQL, KC_DEL, COMBO_END};
const uint16_t PROGMEM combo_lbrc_rbrc[] = {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM combo_rbrc_bsls[] = {KC_RBRC, KC_BSLS, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_eql_del, KC_F12),
    COMBO(combo_rprn_eql, S(KC_F12)),
    COMBO(combo_lbrc_rbrc, LCTL(LALT(KC_COMM))),
    COMBO(combo_rbrc_bsls, LCTL(LALT(KC_DOT)))
};

bool handle_tap(keyrecord_t *record, char *keycode) {
    if (record->event.pressed) {
        send_string(keycode);
    }
    return true;
}

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ortho_4x12(
        KC_ESC,     KC_Q,       KC_W,       KC_E,        KC_R,        KC_T,      KC_Y,        KC_U,        KC_I,          KC_O,       KC_P,       KC_BSPC,
        KC_TAB,     KC_A,       KC_S,       KC_D,        KC_F,        KC_G,      KC_H,        KC_J,        KC_K,          KC_L,       KC_SCLN,    KC_QUOT,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,        KC_V,        KC_B,      KC_N,        KC_M,        KC_COMM,       KC_DOT,     KC_SLSH,    KC_ENT,
        KC_LCTL,    KC_LALT,    KC_LGUI,    MO(_LOWER),  KC_SPC,      _______,   KC_SPC,      _______,     MO(_RAISE),    KC_RSFT,    KC_RALT,    KC_RCTL
    ),
    [_LOWER] = LAYOUT_ortho_4x12(
        _______,    _______,    _______,    _______,     _______,     _______,   _______,     _______,     _______,       KC_7,        KC_8,      KC_9,
        _______,    _______,    _______,    _______,     _______,     _______,   _______,     _______,     _______,       KC_4,        KC_5,      KC_6,
        _______,    _______,    _______,    _______,     _______,     _______,   _______,     _______,     _______,       KC_1,        KC_2,      KC_3,
        _______,    _______,    _______,    _______,     _______,     _______,   _______,     _______,     MO(_NAV),      KC_0,        KC_DOT,    KC_ENT
    ),
    [_RAISE] = LAYOUT_ortho_4x12(
        KC_GRV,     _______,    KC_UP,      _______,     KC_PERC,     KC_CIRC,   KC_AMPR,     KC_ASTR,     KC_LPRN,       KC_RPRN,    KC_EQL,     KC_DEL,
        _______,    KC_LEFT,    KC_DOWN,    KC_RIGHT,    KC_MINS,     KC_HASH,   _______,     KC_UNDS,     KC_AMPR,       KC_LBRC,    KC_RBRC,    KC_BSLS,
        _______,    _______,    _______,    _______,     KC_PIPE,     _______,   _______,     KC_EXLM,     KC_AT,         KC_HASH,    KC_DLR,     MO(_FN),
        _______,    _______,    _______,    MO(_NAV),    _______,     _______,   _______,     _______,     _______,       _______,    _______,    _______
    ),
    [_NAV] = LAYOUT_ortho_4x12(
        QK_BOOT,    _______,    CGUIU,      _______,    _______,      _______,   _______,     _______,     _______,       _______,    _______,    _______,
        _______,    CGUIL,      CGUID,      CGUIR,      _______,      _______,   _______,     _______,     _______,       _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,      _______,   _______,     _______,     _______,       _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,      _______,   _______,     _______,     _______,       _______,    _______,    _______
    ),
    [_FN] = LAYOUT_ortho_4x12(
        KC_F1,      KC_F2,      KC_F3,      KC_F4,       KC_F5,       KC_F6,     KC_F7,       KC_F8,       KC_F9,         KC_F10,      KC_F11,    KC_F12,
        KC_1,       KC_2,       KC_3,       KC_4,        KC_5,        KC_6,      KC_7,        KC_8,        KC_9,          KC_0,        KC_MINS,   KC_EQL,
        KC_CAPS,    _______,    _______,    _______,     _______,     _______,   _______,     _______,     _______,       _______,     _______,   _______,
        _______,    _______,    _______,    _______,     _______,     _______,   _______,     _______,     _______,       _______,     _______,   _______
    )
};

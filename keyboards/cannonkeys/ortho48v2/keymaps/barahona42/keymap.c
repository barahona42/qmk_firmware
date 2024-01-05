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


#define LCTL_LGUI(keycode) SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(keycode)SS_UP(X_LCTL)SS_UP(X_LGUI)
#define LCTL_LALT(keycode) SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_TAP(keycode)SS_UP(X_LCTL)SS_UP(X_LALT)
#define LCTL_LGUI_LALT_LSFT(keycode) SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_DOWN(X_LALT)SS_DOWN(X_LSFT)SS_TAP(keycode)SS_UP(X_LCTL)SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LSFT)

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
    CACOM,
    CADOT,
    CCGASFTU,
    CCGASFTD,
    CK_RAISE,
    CK_LOWER,
};

enum custom_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _FN1,
    _FN2,
    _NUMPAD
};

enum custom_tapdances {
    TD_LCPS = 0,
    TD_RCPS,
    TD_MDIA,
};


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
        case CACOM:
            return handle_tap(record, LCTL_LALT(X_COMM));
        case CADOT:
            return handle_tap(record, LCTL_LALT(X_DOT));
    }
    return true;
};

void handle_td_media(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            register_code(KC_MPLY);
            break;
        case 2:
            register_code(KC_MNXT);
            break;
        case 3:
            register_code(KC_MPRV);
            break;
    }
}

void handle_td_media_reset(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            unregister_code(KC_MPLY);
            break;
        case 2:
            unregister_code(KC_MNXT);
            break;
        case 3:
            unregister_code(KC_MPRV);
            break;
    }
    uint8_t cur_level = get_backlight_level();
    for (uint8_t j = 0; j < cur_level; j++) {
        backlight_level(j);
        wait_ms(10);
    }
    backlight_level(cur_level);
    for (int i = state->count-1; i > 0; i--) {
        wait_ms(75);
        backlight_toggle();
        wait_ms(75);
        backlight_toggle();
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_LCPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_RCPS] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_CAPS),
    [TD_MDIA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, handle_td_media, handle_td_media_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ortho_4x12(
        KC_ESC,      KC_Q,       KC_W,       KC_E,        KC_R,        KC_T,      KC_Y,        KC_U,        KC_I,          KC_O,       KC_P,       KC_BSPC,
        KC_TAB,      KC_A,       KC_S,       KC_D,        KC_F,        KC_G,      KC_H,        KC_J,        KC_K,          KC_L,       KC_SCLN,    KC_QUOT,
        TD(TD_LCPS), KC_Z,       KC_X,       KC_C,        KC_V,        KC_B,      KC_N,        KC_M,        KC_COMM,       KC_DOT,     KC_SLSH,    TD(TD_RCPS),
        KC_LCTL,     KC_LALT,    KC_LGUI,    MO(_LOWER),  KC_SPC,      KC_SPC,    KC_SPC,      KC_SPC,      MO(_RAISE),    KC_RALT,    KC_RCTL,    KC_ENT
    ),
    [_LOWER] = LAYOUT_ortho_4x12(
        TD(TD_MDIA), KC_1,       KC_2,       KC_3,        KC_4,        KC_5,      KC_6,        KC_7,        KC_8,          KC_9,       KC_0,       _______,
        _______,     KC_EXLM,    KC_AT,      KC_HASH,     KC_DLR,      _______,   _______,     _______,     _______,       _______,    _______,    _______,
        _______,     KC_PERC,    KC_CIRC,    KC_AMPR,     KC_ASTR,     _______,   _______,     _______,     _______,       _______,    _______,    _______,
        TG(_NUMPAD), _______,    _______,    _______,     _______,     _______,   _______,     _______,     MO(_FN1),      _______,    _______,    _______
    ),
    [_RAISE] = LAYOUT_ortho_4x12(
        KC_GRV,      _______,    KC_UP,      _______,     _______,     _______,   _______,     _______,     KC_LPRN,       KC_RPRN,    KC_EQL,     KC_DEL,
        _______,     KC_LEFT,    KC_DOWN,    KC_RIGHT,    _______,     _______,   _______,     KC_UNDS,     KC_LBRC,       KC_RBRC,    _______,    KC_BSLS,
        _______,     _______,    _______,   _______,      _______,     _______,   _______,     KC_MINS,     KC_LCBR,       KC_RCBR,    _______,    _______,
        _______,     _______,    _______,    MO(_FN1),    _______,     _______,   _______,     _______,     _______,       MO(_FN2),   _______,    _______
    ),
    [_FN1] = LAYOUT_ortho_4x12(
        _______,     _______,    CGUIU,      _______,     _______,     _______,   _______,     _______,     _______,       _______,    _______,    _______,
        _______,     CGUIL,      CGUID,      CGUIR,       _______,     _______,   _______,     _______,     _______,       _______,    _______,    _______,
        _______,     _______,    _______,    _______,     _______,     _______,   _______,     _______,     _______,       _______,    _______,    _______,
        _______,     _______,    _______,    _______,     _______,     _______,   _______,     _______,     _______,       _______,    _______,    QK_BOOT
    ),
    [_FN2] = LAYOUT_ortho_4x12(
        _______,     _______,    KC_PGUP,    _______,     _______,     _______,   _______,     KC_F9,       KC_F10,        KC_F11,     KC_F12,     _______,
        _______,     KC_HOME,    KC_PGDN,    KC_END,      _______,     _______,   _______,     KC_F5,       KC_F6,         KC_F7,      KC_F8,     _______,
        _______,     KC_F12,     CACOM,      CADOT,       _______,     _______,   _______,     KC_F1,       KC_F2,         KC_F3,      KC_F4,     _______,
        _______,     _______,    _______,    _______,     _______,     _______,   _______,     _______,     _______,       _______,    _______,    _______
    ),
    [_NUMPAD] = LAYOUT_ortho_4x12(
        _______,     _______,    _______,    _______,     _______,     _______,   KC_ASTR,     KC_7,        KC_8,          KC_9,       _______,    KC_BSPC,
        _______,     _______,    _______,    _______,     _______,     _______,   KC_MINS,     KC_4,        KC_5,          KC_6,       _______,    _______,
        _______,     _______,    _______,    _______,     _______,     _______,   KC_SLSH,     KC_1,        KC_2,          KC_3,       _______,    _______,
        TG(_NUMPAD), _______,    _______,    _______,     _______,     _______,   KC_SPC,      KC_0,        KC_0,          KC_DOT,     _______,    _______
    )
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]  = {ENCODER_CCW_CW(_______, _______)},
    [_LOWER] = {ENCODER_CCW_CW(_______, _______)},
    [_RAISE] = {ENCODER_CCW_CW(_______, _______)},
    [_FN1]   = {ENCODER_CCW_CW(_______, _______)},
    [_FN2] = { ENCODER_CCW_CW(_______, _______) },
    [_NUMPAD] = { ENCODER_CCW_CW(_______, _______) }
};

/* Copyright 2021 BrickBots Labs
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
#include "keycodes.h"
#include "process_combo.h"
#include "customs.h"


#define KC_CTL_A       MT(MOD_LCTL, KC_A)
#define KC_CTL_SCLN    MT(MOD_RCTL, KC_SCLN)

#define KC_SFT_Z       MT(MOD_LSFT, KC_Z)
#define KC_SFT_SLSH    MT(MOD_RSFT, KC_SLSH)

#define KC_GUI_ESC     MT(MOD_LGUI, KC_ESC)
#define KC_ALT_ENT     MT(MOD_LALT, KC_ENT)
#define KC_LAY1_SPC    MT(_LAY1, KC_SPC)
#define KC_LAY2_SPC    MT(_LAY2, KC_SPC)
#define KC_SFT_TAB     MT(MOD_RSFT, KC_TAB)


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
const uint16_t PROGMEM combo_rprn_eql[] = {KC_RPRN, KC_EQL, COMBO_END};
const uint16_t PROGMEM combo_eql_del[]   = {KC_EQL, KC_DEL, COMBO_END};
const uint16_t PROGMEM combo_lbrc_rbrc[] = {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM combo_rbrc_bsls[] = {KC_RBRC, KC_BSLS, COMBO_END};

combo_t key_combos[] = {COMBO(combo_eql_del, KC_F12), COMBO(combo_rprn_eql, S(KC_F12)), COMBO(combo_lbrc_rbrc, LCTL(LALT(KC_COMM))), COMBO(combo_rbrc_bsls, LCTL(LALT(KC_DOT)))};

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
        case CK_CACOM:
            return handle_tap(record, LCTL_LALT(X_COMM));
        case CK_CADOT:
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
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_MDIA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, handle_td_media, handle_td_media_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_BASE] = LAYOUT_split_3x5_3(

        KC_Q,     KC_W,     KC_E,       KC_R,       KC_T,               KC_Y,           KC_U,       KC_I,      KC_O,     KC_P,
        KC_CTL_A, KC_S,     KC_D,       KC_F,       KC_G,               KC_H,           KC_J,       KC_K,      KC_L,     KC_CTL_SCLN,
        KC_SFT_Z, KC_X,     KC_C,       KC_V,       KC_B,               KC_N,           KC_M,       KC_COMM,   KC_DOT,   KC_SFT_SLSH,
                            KC_GUI_ESC, KC_ALT_ENT, KC_LAY1_SPC,        KC_LAY2_SPC,    KC_RSFT,    KC_SFT_TAB
    ),
   [_LAY1] = LAYOUT_split_3x5_3(

        KC_EXLM,  KC_AT,    KC_LCBR,    KC_RCBR,    KC_PIPE,            KC_GRV,         KC_TILD,    KC_TRNS,   KC_TRNS,  KC_BSLS,
        KC_HASH,  KC_DLR,   KC_LPRN,    KC_RPRN,    KC_BTN2,            KC_PLUS,        KC_MINS,    KC_SLSH,   KC_ASTR,  KC_QUOT,
        KC_PERC,  KC_CIRC,  KC_LBRC,    KC_RBRC,    KC_BTN1,            KC_AMPR,        KC_EQL,     KC_COMM,   KC_DOT,   KC_MINS,
                            CM_TOGG,    KC_SCLN,    KC_EQL,             KC_EQL,         KC_SCLN,    KC_DEL
    ),
   [_LAY2] = LAYOUT_split_3x5_3(

        KC_1,     KC_2,     KC_3,       KC_4,       KC_5,               KC_6,           KC_7,       KC_8,      KC_9,     KC_0,
        KC_F1,    KC_F2,    KC_F3,      KC_F4,      KC_F5,              KC_LEFT,        KC_DOWN,    KC_UP,     KC_RGHT,  KC_VOLU,
        KC_F6,    KC_F7,    KC_F8,      KC_F9,      KC_F10,             KC_MS_L,        KC_MS_D,    KC_MS_U,   KC_MS_R,  KC_VOLD,
                            KC_F11,     KC_F12,     KC_TRNS,            KC_TRNS,        KC_MPLY,    KC_MNXT
    ),
};

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "barahona42.c"

char wpm_str[10];

tap_dance_action_t tap_dance_actions[] = {};
combo_t key_combos[] = {};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                                                                   KC_Y,      KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
        KC_ESC,     KC_A,       LCTL_S,     LALT_D,     LGUI_F,     KC_G,                                                                   KC_H,      RGUI_J,     RALT_K,     RCTL_L,     KC_SCLN,    KC_QUOT,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       _______,    MO(CONF),                MO(CONF),    MO(NAVS), KC_N,      KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    RSTF_ENT,
                                            KC_LCTL,    KC_LALT,    KC_LGUI,    LAY2_SPC,   MO(NUMS),                MO(NUMS),    LAY1_SPC, KC_RGUI,  KC_RALT,  KC_RCTL
    ),

    [LAY1] = LAYOUT(
        KC_GRV,     _______,    KC_UP,      _______,    _______,    _______,                                                                _______,    _______,    KC_LPRN,    KC_RPRN,    KC_EQL,     KC_DEL,
        _______,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   _______,    _______,                                                                _______,    KC_UNDS,    KC_LBRC,    KC_RBRC,    _______,    KC_BSLS,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    KC_MINS,    KC_LCBR,    KC_RCBR,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______
    ),
    [LAY2] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,                                                                _______,    _______,    _______,    _______,    _______,    _______,
        _______,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     _______,                                                                _______,    _______,    _______,    _______,    _______,    _______,
        _______,    KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______
    ),
    [SYMS] = LAYOUT(
        KC_GRV,     _______,    _______,    _______,    _______,    _______,                                                                _______,    _______,    KC_LPRN,    KC_RPRN,    KC_EQL,     KC_DEL,
        _______,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     _______,                                                                _______,    KC_UNDS,    KC_LBRC,    KC_RBRC,    _______,    KC_BSLS,
        _______,    KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    _______,    _______,    _______,                _______,    _______,    _______,    KC_MINS,    KC_LCBR,    KC_RCBR,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______
    ),
    [NUMS]= LAYOUT(
        _______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                                                                   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_DEL,
        _______,    _______,    _______,    _______,    _______,    _______,                                                                _______,    KC_4,       KC_5,       KC_6,       _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    KC_1,       KC_2,       KC_3,       _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    KC_0,       _______
    ),
    [NAVS]= LAYOUT(
        KC_HOME,    _______,    KC_UP,      _______,    KC_PGUP,    _______,                                                                _______,    _______,    _______,    _______,    _______,    KC_DEL,
        KC_DOWN,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_PGDN,    _______,                                                                _______,    KC_RGUI,    KC_RALT,    KC_RCTL,    _______,    _______,
        KC_LSFT,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______
    ),
    [CONF]= LAYOUT(
        BL_TOGG,    _______,    _______,    _______,    _______,    _______,                                                                _______,    _______,    _______,    _______,    QK_MAKE,    QK_BOOT,
        RGB_TOG,    RGB_MOD,    _______,    _______,    _______,    _______,                                                                _______,    _______,    _______,    _______,    _______,    _______,
        UG_TOGG,    UG_SPDU,    UG_SPDD,    UG_NEXT,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______
    )
};
void master_oled_display(void){
        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Layer:"), false);
        // Host Keyboard Layer Status
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case BASE:
                oled_write_P(PSTR("BASE\n"), false);
                break;
            case LAY1:
                oled_write_P(PSTR("LAY1\n"), false);
                break;
            case LAY2:
                oled_write_P(PSTR("LAY2\n"), false);
                break;
            case SYMS:
                oled_write_P(PSTR("SYMS\n"), false);
                break;
            case NUMS:
                oled_write_P(PSTR("NUMS\n"), false);
                break;
            case NAVS:
                oled_write_P(PSTR("NAVS\n"), false);
                break;
            case CONF:
                oled_write_P(PSTR("CONF\n"), false);
                break;
            default:
                oled_write_P(PSTR("idk\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);

        if ((get_mods() & MOD_BIT(KC_LGUI)) == MOD_BIT(KC_LGUI)) {
            oled_write_P(PSTR("\n\nMOD LGUI"), false);
        } else if ((get_mods() & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT)) {
            oled_write_P(PSTR("\n\nMOD LALT"), false);
        } else if ((get_mods() & MOD_BIT(KC_LCTL)) == MOD_BIT(KC_LCTL)) {
            oled_write_P(PSTR("\n\nMOD LCTL"),false);
        } else {
            oled_write_P(PSTR(""), false);
        }
}

void secondary_oled_display() {
    master_oled_display();
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        master_oled_display();
    } else {
        secondary_oled_display();
    }
    return false;
}

// #ifdef ENCODER_ENABLE
// bool encoder_update_user(uint8_t index, bool clockwise) {

//     if (index == 0) {
//         // Volume control
//         if (clockwise) {
//             tap_code(KC_VOLU);
//         } else {
//             tap_code(KC_VOLD);
//         }
//     } else if (index == 1) {
//         // Page up/Page down
//         if (clockwise) {
//             tap_code(KC_PGDN);
//         } else {
//             tap_code(KC_PGUP);
//         }
//     }
//     return false;
// }
// #endif

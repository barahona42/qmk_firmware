#include QMK_KEYBOARD_H
#include <stdio.h>
#include "keycodes.h"
#include "process_combo.h"
#include "barahona42.c"

#define LG_LEFT LCTL(LGUI(KC_LEFT))
#define LG_RGHT LCTL(LGUI(KC_RIGHT))
#define LG_UP LCTL(LGUI(KC_UP))
#define LG_DOWN LCTL(LGUI(KC_DOWN))

#define LCA_DOT LCA(KC_COMM)
#define LCA_COM LCA(KC_DOT)

#define CS_LCA(keycode) SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_TAP(keycode) SS_UP(X_LCTL) SS_UP(X_LALT)

char wpm_str[10];

combo_t            key_combos[]        = {};
tap_dance_action_t tap_dance_actions[] = {[TD_MDIA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, handle_td_media, handle_td_media_reset)};

bool handle_tap(keyrecord_t *record, char *keycode) {
    if (record->event.pressed) {
        send_string(keycode);
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case CK_CACOM:
        //     return handle_tap(record, CTL_ALT(X_TAB));
    }
    return true;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_TAB      ,KC_Q        ,W_LAY2      ,E_LAY1      ,KC_R        ,KC_T                                                                         ,KC_Y        ,KC_U        ,I_LAY1      ,O_LAY2      ,KC_P        ,KC_BSPC     ,
        KC_ESC      ,KC_A        ,LCTL_S      ,LALT_D      ,LGUI_F      ,LSFT_G                                                                       ,RSFT_H      ,RGUI_J      ,RALT_K      ,RCTL_L      ,KC_SCLN     ,KC_QUOT     ,
        KC_LSFT     ,KC_Z        ,KC_X        ,KC_C        ,KC_V        ,KC_B        ,MO(NAVS)    ,_______                  ,_______     ,MO(NAVS)    ,KC_N        ,KC_M        ,KC_COMM     ,KC_DOT      ,KC_SLSH     ,RSTF_ENT    ,
                                               KC_LCTL     ,KC_LALT     ,KC_LGUI     ,LAY2_SPC    ,MO(NUMS)                 ,MO(NUMS)    ,LAY1_SPC    ,KC_RGUI     ,KC_RALT     ,KC_RCTL
    ),
    [LAY1] = LAYOUT(
        KC_GRV      ,_______     ,KC_UP       ,_______     ,_______     ,_______                                                                      ,_______     ,_______     ,KC_LPRN     ,KC_RPRN     ,KC_EQL      ,KC_DEL      ,
        _______     ,KC_LEFT     ,KC_DOWN     ,KC_RIGHT    ,_______     ,_______                                                                      ,_______     ,KC_UNDS     ,KC_LBRC     ,KC_RBRC     ,_______     ,KC_BSLS     ,
        _______     ,_______     ,_______     ,_______     ,_______     ,_______     ,_______     ,_______                  ,_______     ,_______     ,_______     ,KC_MINS     ,KC_LCBR     ,KC_RCBR     ,_______     ,_______     ,
                                               _______     ,_______     ,_______     ,_______     ,_______                  ,_______     ,_______     ,_______     ,_______     ,_______
    ),
    [LAY2] = LAYOUT(
        _______     ,_______     ,_______     ,_______     ,_______     ,_______                                                                      ,_______     ,_______     ,_______     ,_______     ,_______     ,_______     ,
        _______     ,KC_EXLM     ,KC_AT       ,KC_HASH     ,KC_DLR      ,QK_LEAD                                                                      ,_______     ,_______     ,_______     ,_______     ,_______     ,_______     ,
        _______     ,KC_PERC     ,KC_CIRC     ,KC_AMPR     ,KC_ASTR     ,_______     ,_______     ,_______                  ,_______     ,_______     ,_______     ,_______     ,_______     ,_______     ,_______     ,_______     ,
                                               _______     ,_______     ,_______     ,_______     ,_______                  ,_______     ,_______     ,_______     ,_______     ,_______
    ),
    [NUMS] = LAYOUT(
        _______     ,_______     ,_______     ,_______     ,LSG(KC_TAB) ,LGUI(KC_TAB)                                                                 ,_______     ,KC_7        ,KC_8        ,KC_9        ,_______     ,_______     ,
        _______     ,_______     ,_______     ,_______     ,LSG(KC_GRV) ,LGUI(KC_GRV)                                                                 ,_______     ,KC_4        ,KC_5        ,KC_6        ,_______     ,_______     ,
        _______     ,KC_F12      ,LCA_DOT     ,LCA_COM     ,RCS(KC_TAB) ,RCTL(KC_TAB),_______     ,_______                  ,_______     ,_______     ,_______     ,KC_1        ,KC_2        ,KC_3        ,_______     ,_______     ,
                                               _______     ,_______     ,_______     ,_______     ,_______                  ,_______     ,_______     ,KC_0        ,KC_DOT      ,_______
    ),
    [NAVS] = LAYOUT(
        _______     ,_______     ,LG_UP       ,_______     ,_______     ,_______                                                                      ,_______     ,_______     ,_______     ,_______     ,_______     ,TD(TD_MDIA) ,
        _______     ,LG_LEFT     ,LG_DOWN     ,LG_RGHT     ,_______     ,_______                                                                      ,_______     ,_______     ,_______     ,_______     ,_______     ,_______     ,
        QK_BOOT     ,QK_MAKE     ,_______     ,_______     ,_______     ,_______     ,_______     ,_______                  ,_______     ,_______     ,_______     ,_______     ,_______     ,_______     ,RGB_MOD     ,RGB_TOG     ,
                                               _______     ,_______     ,_______     ,_______     ,_______                  ,_______     ,_______     ,_______     ,_______     ,_______
    )
};

// clang-format on
void leader_start_user() {
    oled_write_P(PSTR("leader key starting\n"), false);
}

void leader_end_user() {
    if (leader_sequence_one_key(KC_O)) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_TAP(X_O) SS_UP(X_LCTL) SS_UP(X_LALT));
    } else if (leader_sequence_one_key(KC_P)) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_TAP(X_P) SS_UP(X_LCTL) SS_UP(X_LALT));
    } else if (leader_sequence_two_keys(KC_O, KC_O)) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_O) SS_UP(X_LSFT) SS_UP(X_LCTL) SS_UP(X_LALT));
    } else if (leader_sequence_two_keys(KC_P, KC_P)) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_P) SS_UP(X_LSFT) SS_UP(X_LCTL) SS_UP(X_LALT));
    } else if (leader_sequence_one_key(KC_J)) {
        SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_C) SS_UP(X_LGUI));
    } else if (leader_sequence_two_keys(KC_J, KC_J)) {
        SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_V) SS_UP(X_LGUI));
    }
    oled_write_P(PSTR("leader key ended\n"), false);
}

void master_oled_display(void) {
    oled_write_P(qmk_logo, false);
    oled_write_P(PSTR("Layer:"), false);
    // Host Keyboard Layer Status
    switch (get_highest_layer(layer_state | default_layer_state)) {
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
    // led_t led_usb_state = host_keyboard_led_state();
    // oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
    // oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
    // oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);

    // if ((get_mods() & MOD_BIT(KC_LGUI)) == MOD_BIT(KC_LGUI)) {
    //     oled_write_P(PSTR("\n\nMOD LGUI"), false);
    // } else if ((get_mods() & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT)) {
    //     oled_write_P(PSTR("\n\nMOD LALT"), false);
    // } else if ((get_mods() & MOD_BIT(KC_LCTL)) == MOD_BIT(KC_LCTL)) {
    //     oled_write_P(PSTR("\n\nMOD LCTL"),false);
    // } else {
    //     oled_write_P(PSTR(""), false);
    // }
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

#include QMK_KEYBOARD_H

// clang-format off
// GUI
#define LGUI_F      MT(MOD_LGUI, KC_F)      // hold: left gui       tap: f
#define RGUI_J      MT(MOD_RGUI, KC_J)      // hold: right gui      tap: j
// ALT
#define LALT_D      MT(MOD_LALT, KC_D)      // hold: left alt       tap: d
#define RALT_K      MT(MOD_RALT, KC_K)      // hold: right alt      tap: k
// CTL
#define LCTL_S      MT(MOD_LCTL, KC_S)      // hold: left ctl       tap: s
#define RCTL_L      MT(MOD_RCTL, KC_L)      // hold: right ctl      tap: l
// etc
#define RSTF_ENT    MT(MOD_RSFT, KC_ENT)    // hold: right shift    tap: enter
#define SYMS_SPC    LT(SYMS, KC_SPC)
#define LOWR_SPC    LT(LOWR, KC_SPC)        // hold: lower          tap: space
#define RAIS_SPC    LT(RAIS, KC_SPC)        // hold: raise          tap: space
// #define SPC_RAIS    MT()
// clang-format on
void master_oled_display(void);
void secondary_oled_display(void);

enum custom_layers {
    BASE = 0,
    SYMS,
    NUMS,
    NAVS,
    CONF
};

enum custom_tapdances {
    TD_MEDIA = 0
};

tap_dance_action_t tap_dance_actions[] = {};
combo_t key_combos[] = {};
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                                                                   KC_Y,      KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
        KC_ESC,     KC_A,       LCTL_S,     LALT_D,     LGUI_F,     KC_G,                                                                   KC_H,      RGUI_J,     RALT_K,     RCTL_L,     KC_SCLN,    KC_QUOT,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       TT(NUMS),   _______,                _______,    MO(CONF),   KC_N,      KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    RSTF_ENT,
                                            _______,    _______,    KC_SPC,     MO(SYMS),   _______,                _______,    MO(SYMS),   KC_SPC,    MO(NAVS),   _______
    ),
    [SYMS] = LAYOUT(
        _______,    KC_GRV,     _______,    _______,    _______,    _______,                                                                _______,    _______,    KC_LPRN,    KC_RPRN,    KC_EQL,     KC_DEL,
        _______,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     _______,                                                                _______,    KC_UNDS,    KC_LBRC,    KC_RBRC,    _______,    KC_BSLS,
        _______,    KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    _______,    _______,    _______,                _______,    _______,    _______,    KC_MINS,    KC_LCBR,    KC_RCBR,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______
    ),
    [NUMS]= LAYOUT(
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,                                                                  _______,    _______,    _______,    _______,    _______,    _______,
        KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,                                                                 _______,    KC_4,       KC_5,       KC_6,       _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    KC_1,       KC_2,       KC_3,       _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,                _______,    _______,    KC_0,       _______,    _______
    ),
    [NAVS]= LAYOUT(
        KC_HOME,    _______,    KC_UP,      _______,    KC_PGUP,    _______,                                                                _______,    _______,    _______,    _______,    _______,    _______,
        KC_DOWN,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_PGDN,    _______,                                                                _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______
    ),
    [CONF]= LAYOUT(
        BL_TOGG,    _______,    _______,    _______,    _______,    _______,                                                                _______,    _______,    _______,    _______,    QK_MAKE,    QK_BOOT,
        RGB_TOG,    _______,    _______,    _______,    _______,    _______,                                                                _______,    _______,    _______,    _______,    _______,    _______,
        UG_TOGG,    UG_SPDU,    UG_SPDD,    UG_NEXT,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______
    )
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */


oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

void master_oled_display(void){
// QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case BASE:
                oled_write_P(PSTR("BASE\n"), false);
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
}

void secondary_oled_display() {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        master_oled_display();
    } else {
        // secondary_oled_display();
        master_oled_display();
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

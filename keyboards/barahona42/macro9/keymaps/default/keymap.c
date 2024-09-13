#include QMK_KEYBOARD_H

enum custom_layers {
    BASE = 0,
    LAY1,
};

enum custom_tapdances {
    TD_MEDIA = 0,
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [LAY1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
};
#endif

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
    [TD_MEDIA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, handle_td_media, handle_td_media_reset),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
                    _______,    _______,      _______,
                    _______,    TD(TD_MEDIA), _______,
        _______,    MO(LAY1),      _______,      _______
    ),
    [LAY1] = LAYOUT(
                    _______,    _______,      QK_BOOT,
                    _______,    _______,      _______,
        _______,    _______,    _______,      _______
    ),
};

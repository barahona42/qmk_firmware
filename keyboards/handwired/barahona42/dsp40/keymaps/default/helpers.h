#include QMK_KEYBOARD_H
#include "process_combo.h"

#define LCTL_LGUI(keycode)SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(keycode)SS_UP(X_LCTL)SS_UP(X_LGUI)


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

enum custom_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _NAV,
    _FN,
    _SYM
};

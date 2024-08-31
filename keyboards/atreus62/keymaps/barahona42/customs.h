#include "keycodes.h"

#define LCTL_LGUI(keycode) SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(keycode)SS_UP(X_LCTL)SS_UP(X_LGUI)
#define LCTL_LALT(keycode) SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_TAP(keycode)SS_UP(X_LCTL)SS_UP(X_LALT)
#define LCTL_LGUI_LALT_LSFT(keycode) SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_TAP(keycode) SS_UP(X_LCTL) SS_UP(X_LGUI) SS_UP(X_LALT) SS_UP(X_LSFT)

enum custom_keycodes {
    CGUIL = SAFE_RANGE,
    CGUIR,
    CGUIU,
    CGUID,
    CK_CACOM,
    CK_CADOT,
    CK_RAISE,
    CK_LOWER,
};

enum custom_layers {
    _BASE,  // core keymap
    _LOWER, // left lower
    _RAISE, // right raise
    _FN1,
    _FN2,
    _THBL,
    _THBR,
    _NUMS,
};

enum custom_tapdances {
    TD_MDIA = 0,
};

#include "keycodes.h"

#define LCTL_LGUI(keycode) SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(keycode)SS_UP(X_LCTL)SS_UP(X_LGUI)
#define LCTL_LALT(keycode) SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_TAP(keycode)SS_UP(X_LCTL)SS_UP(X_LALT)
#define LCTL_LGUI_LALT_LSFT(keycode) SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_TAP(keycode) SS_UP(X_LCTL) SS_UP(X_LGUI) SS_UP(X_LALT) SS_UP(X_LSFT)

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
#define SYMS_SPC    LT(SYMS, KC_SPC)        // hold: symbols layer  tap: space
#define LAY1_SPC    LT(LAY1, KC_SPC)
#define LAY2_SPC    LT(LAY2, KC_SPC)
#define LGUI_SPC    MT(MOD_LGUI, KC_SPC)
#define RGUI_SPC    MT(MOD_RGUI, KC_SPC)
#define RALT_NAVS   LT(NAVS, KC_RALT)
#define E_LAY1      LT(LAY1, KC_E)
#define W_LAY2      LT(LAY2, KC_W)


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
    BASE,
    CONF,
    LOWR,
    NAVS,
    NUMS,
    RAIS,
    SYMS,
    LAY1,
    LAY2,
    LAY3,
};

enum custom_tapdances {
    TD_MDIA = 0,
};

void master_oled_display(void);
void secondary_oled_display(void);

static const char PROGMEM kyria_logo[];
static const char PROGMEM qmk_logo[];

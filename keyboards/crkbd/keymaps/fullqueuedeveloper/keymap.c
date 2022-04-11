#include QMK_KEYBOARD_H

enum custom_layers {
    _MIRYOKU_COLEMAK = 0,
      _MIRYOKU_NAV,
      _MIRYOKU_NUM,
      _MIRYOKU_SYM,
      _MIRYOKU_FUN,
      _MIRYOKU_MEDIA,
      _MIRYOKU_MOUSE,
      _MIRYOKU_BRACKETS,

    _COLMK,
      _LOWER,
      _RAISE,

    _ADJUST,
};

enum custom_keycodes {
    U_LOWER = SAFE_RANGE,
    U_RAISE,

    U_MIRYO,
    U_COLMK,

    U_PRVWD,
    U_NXTWD,
    U_LSTRT,
    U_LEND,
    U_DLINE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_MIRYOKU_COLEMAK] = LAYOUT(\
MO(_ADJUST),           KC_Q,         KC_W,          KC_F,              KC_P,              KC_B,                      KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,       KC_MUTE,
KC_BSPC,               LGUI_T(KC_A), LALT_T(KC_R),  LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,                      KC_M,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),  KC_VOLU,
MO(_MIRYOKU_MEDIA),    KC_Z,         ALGR_T(KC_X),  KC_C,              KC_D,              KC_V,                      KC_K,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    KC_SLSH,       KC_VOLD,
    LT(_MIRYOKU_BRACKETS, KC_ESC), LT(_MIRYOKU_NAV, KC_SPC), LT(_MIRYOKU_MOUSE, KC_TAB),            LT(_MIRYOKU_SYM, KC_ENT),   LT(_MIRYOKU_NUM, KC_BSPC), LT(_MIRYOKU_FUN, KC_DEL)
),

[_MIRYOKU_NUM] = LAYOUT(
_______, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
XXXXXXX, KC_SCLN, KC_4,    KC_5,    KC_6,     KC_EQL,                   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
XXXXXXX, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, XXXXXXX, _______,
                                  KC_DOT,       KC_0, KC_MINS, XXXXXXX, XXXXXXX, XXXXXXX
),

[_MIRYOKU_NAV] = LAYOUT(\
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_AGIN,KC_PASTE, KC_COPY,  KC_CUT, KC_UNDO, _______, \
XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   KC_PGUP, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, \
XXXXXXX, XXXXXXX, KC_ALGR, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PGDN, U_LSTRT, U_PRVWD, U_NXTWD,  U_LEND, _______, \
                                    XXXXXXX, XXXXXXX, XXXXXXX,  KC_ENT, KC_BSPC,  KC_DEL
),

[_MIRYOKU_SYM] = LAYOUT(
_______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
XXXXXXX, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
XXXXXXX, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, XXXXXXX, _______,
                                    KC_LPRN, KC_RPRN, KC_UNDS, XXXXXXX, XXXXXXX, XXXXXXX
),

[_MIRYOKU_FUN] = LAYOUT(
_______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK,                   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, XXXXXXX, _______,
                                    KC_APP,  KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
[_MIRYOKU_MEDIA] = LAYOUT(
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
XXXXXXX, XXXXXXX, KC_ALGR, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                    XXXXXXX, XXXXXXX, XXXXXXX, KC_MSTP, KC_MPLY, KC_MUTE
),

[_MIRYOKU_MOUSE] = LAYOUT(
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ACL2,                   KC_AGIN, KC_PASTE,KC_COPY,  KC_CUT, KC_UNDO, _______,
XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_ACL1,                   XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
XXXXXXX, XXXXXXX, KC_ALGR, XXXXXXX, XXXXXXX, KC_ACL0,                   XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
                                    XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2
),

[_MIRYOKU_BRACKETS] = LAYOUT(
_______, XXXXXXX, KC_LBRC, XXXXXXX, KC_RBRC, XXXXXXX,                   XXXXXXX, KC_LBRC, XXXXXXX, KC_RBRC, XXXXXXX, _______,
XXXXXXX, KC_LCBR, KC_LPRN, XXXXXXX, KC_RPRN, KC_RCBR,                   KC_LCBR, KC_LPRN, XXXXXXX, KC_RPRN, KC_RCBR, _______,
XXXXXXX, XXXXXXX, KC_LABK, XXXXXXX, KC_RABK, XXXXXXX,                   XXXXXXX, KC_LABK, XXXXXXX, KC_RABK, XXXXXXX, _______,
                                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),


[_COLMK] = LAYOUT( \
  KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,     KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,  KC_MUTE,
  KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,     KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  KC_VOLU,
  KC_SPC,   KC_Z,   KC_X,    KC_C,    KC_D,     KC_V,                      KC_H,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_VOLD,
                                  KC_LCTRL,  KC_LSFT, U_LOWER, U_RAISE, KC_LGUI,  KC_ENT
),

[_LOWER] = LAYOUT(
    KC_0, KC_LBRC,  KC_7,    KC_8,    KC_9,  KC_RBRC,                   KC_AGIN,KC_PASTE, KC_COPY,  KC_CUT, KC_UNDO, _______,
  KC_DOT, KC_SCLN,  KC_4,    KC_5,    KC_6,   KC_EQL,                   KC_PGUP, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
 KC_MINS,  KC_GRV,  KC_1,    KC_2,    KC_3,  KC_BSLS,                   KC_PGDN, U_LSTRT, U_PRVWD, U_NXTWD,  U_LEND, _______,
                                   _______,  _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT(
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_ESC,  KC_ENT,  KC_TAB, XXXXXXX, XXXXXXX, _______,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_BSPC,  KC_SPC,  KC_DEL, XXXXXXX, XXXXXXX, _______,
                                    _______, _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT(
XXXXXXX, CG_SWAP, CG_NORM, CG_TOGG, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
XXXXXXX, XXXXXXX, XXXXXXX, U_MIRYO, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
XXXXXXX, XXXXXXX, XXXXXXX, U_COLMK, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                    _______, _______, _______, _______, _______, _______
)
};



#ifdef OLED_ENABLE

void print_status_primary(void) {
    // Print current mode

    switch (get_highest_layer(default_layer_state)) {
        case _MIRYOKU_COLEMAK:
            oled_write_ln_P(PSTR("Mryku"), false);

            switch (get_highest_layer(layer_state)) {
                case _MIRYOKU_COLEMAK:
                    oled_write_ln_P(PSTR("Base "), false);
                    break;
                case _ADJUST:
                    oled_write_ln_P(PSTR("Adjst"), false);
                    break;
                case _MIRYOKU_FUN:
                    oled_write_ln_P(PSTR("Fun  "), false);
                    break;
                case _MIRYOKU_NUM:
                    oled_write_ln_P(PSTR("Num  "), false);
                    break;
                case _MIRYOKU_SYM:
                    oled_write_ln_P(PSTR("Sym  "), false);
                    break;
                case _MIRYOKU_NAV:
                    oled_write_ln_P(PSTR("Nav  "), false);
                    break;
                case _MIRYOKU_MEDIA:
                    oled_write_ln_P(PSTR("Media"), false);
                    break;
                case _MIRYOKU_MOUSE:
                    oled_write_ln_P(PSTR("Mouse"), false);
                    break;
                case _MIRYOKU_BRACKETS:
                    oled_write_ln_P(PSTR("Brkts"), false);
                    break;
                default:
                    oled_write_ln_P(PSTR("? ? ?"), false);
                    break;
            }
            break;
        case _COLMK:
            oled_write_ln_P(PSTR("Colmk"), false);

                switch (get_highest_layer(layer_state)) {
                    case _COLMK:
                        oled_write_ln_P(PSTR("Base "), false);
                        break;
                    case _RAISE:
                        oled_write_ln_P(PSTR("Raise"), false);
                        break;
                    case _LOWER:
                        oled_write_ln_P(PSTR("Lower"), false);
                        break;
                    case _ADJUST:
                        oled_write_ln_P(PSTR("Adjst"), false);
                        break;
                    default:
                        oled_write_ln_P(PSTR("? ? ?"), false);
                        break;
                }
            break;
        default:
            oled_write_ln_P(PSTR(" ?  ?  ?"), true);
            oled_write_ln_P(PSTR(""), false);
            break;
    }


    uint8_t modifiers = get_mods();

    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));

    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
    } else {
        oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    }

    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));

    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    } else {
        oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
    }
    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR(""), false);

    oled_write_ln_P(host_keyboard_led_state().caps_lock
    ? PSTR("ABC")
    : PSTR("abc"), host_keyboard_led_state().caps_lock);

    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(PSTR("Mac"), false);
    } else {
        oled_write_P(PSTR("Win"), true);
    }

    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR(""), false);


// ---- layer grid
    uint8_t layer = get_highest_layer(default_layer_state);


    oled_write_P(PSTR("."), false);

    oled_write_P(PSTR("."), false);

    layer == _MIRYOKU_COLEMAK
    ? oled_write_P(PSTR("M"), false)
    : oled_write_P(PSTR("."), false);
    oled_write_ln_P(PSTR(".."), false);

    oled_write_P(PSTR("."), false);
    oled_write_P(PSTR("."), false);

    layer == _COLMK
    ? oled_write_P(PSTR("C"), false)
    : oled_write_P(PSTR("."), false);
    oled_write_ln_P(PSTR(".."), false);

}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_left()) {
        return OLED_ROTATION_270;
    } else {
        return rotation;
    }
}


void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_left()) {
        print_status_primary();
    } else {
        oled_render_logo();
    }
    return true;
}

#endif



layer_state_t default_layer_state_set_user(layer_state_t state) {
    keymap_config.swap_lctl_lgui = true;
    keymap_config.swap_rctl_rgui = true;
    return state;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case U_MIRYO:
            set_single_persistent_default_layer(_MIRYOKU_COLEMAK);
            layer_move(_MIRYOKU_COLEMAK);
            return false;

        case U_COLMK:
            set_single_persistent_default_layer(_COLMK);
            layer_move(_COLMK);
            return false;

        case U_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case U_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;

        case U_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case U_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case U_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case U_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case U_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
        case KC_AGIN:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL|MOD_LSFT));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL|MOD_LSFT));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}

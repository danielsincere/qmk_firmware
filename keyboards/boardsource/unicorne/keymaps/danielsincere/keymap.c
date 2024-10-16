#include QMK_KEYBOARD_H
#include "transactions.h"
#if __has_include("keymap.h")
#    include "keymap.h"
#endif


enum sincere_layers {
    _MIRYOKU_COLEMAK = 0,
      _MIRYOKU_NAV,
      _MIRYOKU_NUM,
      _MIRYOKU_SYM,
      _MIRYOKU_FUN,
      _MIRYOKU_POINTER,
      _MIRYOKU_MOUSE,

    _COLMK,
    _COLFN,
    _QWERT,

    _ADJST,
    _LOWER,
    _RAISE,
};

enum custom_keycodes {
    U_LOWER = SAFE_RANGE,
    U_RAISE,

    U_MIRYO,
    U_COLMK,
    U_COLFN,
    U_QWERT,


    U_PRVWD,
    U_NXTWD,
    U_LSTRT,
    U_LEND,
    U_DLINE
};

#define LGUI_A LGUI_T(KC_A)
#define LALT_R LALT_T(KC_R)
#define LCTL_S LCTL_T(KC_S)
#define LSFTT LSFT_T(KC_T)

#define RSFT_N RSFT_T(KC_N)
#define RCTL_E RCTL_T(KC_E)
#define RALT_I RALT_T(KC_I)
#define RGUI_O RGUI_T(KC_O)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MIRYOKU_COLEMAK] = LAYOUT_split_3x6_3(
 MO(_ADJST),    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, KC_MUTE,
   KC_PASTE,  LGUI_A,  LALT_R,  LCTL_S,   LSFTT,    KC_G,                      KC_M,  RSFT_N,  RCTL_E,  RALT_I,  RGUI_O, KC_VOLU,
    KC_COPY,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                      KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_VOLD,

        LT(_MIRYOKU_POINTER, KC_ESC), LT(_MIRYOKU_NAV, KC_SPC), LT(_MIRYOKU_MOUSE, KC_TAB),

        LT(_MIRYOKU_SYM, KC_ENT), LT(_MIRYOKU_NUM, KC_BSPC), LT(_MIRYOKU_FUN, KC_DEL)
  ),
  [_MIRYOKU_NUM] = LAYOUT_split_3x6_3(
    _______, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    XXXXXXX, KC_SCLN, KC_4,    KC_5,    KC_6,     KC_EQL,                   XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
    XXXXXXX, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                      KC_DOT,       KC_0, KC_MINS, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_MIRYOKU_NAV] = LAYOUT_split_3x6_3(\
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_AGIN,KC_PASTE, KC_COPY,  KC_CUT, KC_UNDO, _______, \
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   KC_PGUP, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PGDN, U_LSTRT, U_PRVWD, U_NXTWD,  U_LEND, _______,  \
                                        XXXXXXX, XXXXXXX, XXXXXXX,  KC_ENT, KC_BSPC,  KC_DEL
  ),

  [_MIRYOKU_SYM] = LAYOUT_split_3x6_3(
    _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    XXXXXXX, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                   XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
    XXXXXXX, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                        KC_LPRN, KC_RPRN, KC_UNDS, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_MIRYOKU_FUN] = LAYOUT_split_3x6_3(
    _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,                   XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
    XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                        KC_APP,  KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
  [_MIRYOKU_POINTER] = LAYOUT_split_3x6_3(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN3,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_BTN1,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN2,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                        XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2
  ),

  [_MIRYOKU_MOUSE] = LAYOUT_split_3x6_3(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_AGIN, KC_PASTE,KC_COPY,  KC_CUT, KC_UNDO, _______,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
    XXXXXXX, XXXXXXX, KC_ACL2, KC_ACL1, KC_ACL0, XXXXXXX,                   XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
                                        XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2
  ),

  [_COLMK] = LAYOUT_split_3x6_3( \
     KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_MUTE,
     KC_TAB,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                   XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_VOLU,
     KC_ENT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_VOLD,
                                        KC_LCTL, KC_LSFT, U_LOWER,
                                                                MO(_ADJST),  KC_SPC,  KC_ENT
  ),

  [_COLFN] = LAYOUT_split_3x6_3( \
     KC_ESC,   KC_F4,   KC_F3,   KC_F2,   KC_F1,    KC_B,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_MUTE,
     KC_TAB,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                   XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_VOLU,
     KC_ENT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_VOLD,
                                        KC_LCTL, KC_LSFT, U_LOWER,
                                                                MO(_ADJST),  KC_SPC,  KC_ENT
    ),

  [_QWERT] = LAYOUT_split_3x6_3( \
     KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_MUTE,
     KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                   XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_VOLU,
     KC_ENT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_VOLD,
                                           KC_N,    KC_M, U_LOWER,
                                                                MO(_ADJST),  KC_SPC, KC_ENT
    ),

  [_LOWER] = LAYOUT_split_3x6_3(
        KC_0, KC_LBRC,  KC_7,    KC_8,    KC_9,  KC_RBRC,                   KC_AGIN,KC_PASTE, KC_COPY,  KC_CUT, KC_UNDO, _______,
      KC_DOT, KC_SCLN,  KC_4,    KC_5,    KC_6,   KC_EQL,                   KC_PGUP, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
     KC_MINS,  KC_GRV,  KC_1,    KC_2,    KC_3,  KC_BSLS,                   KC_PGDN, U_LSTRT, U_PRVWD, U_NXTWD,  U_LEND, _______,
                                       _______,  _______, _______, _______, _______, _______
  ),

  [_ADJST] = LAYOUT_split_3x6_3(
    XXXXXXX, CG_TOGG, CG_SWAP, CG_NORM, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, U_MIRYO, U_QWERT, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, U_COLMK, U_COLFN, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                        QK_BOOT, _______, _______, _______, _______, _______
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
                case _ADJST:
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
                case _MIRYOKU_POINTER:
                    oled_write_ln_P(PSTR("Point"), false);
                    break;
                case _MIRYOKU_MOUSE:
                    oled_write_ln_P(PSTR("Mouse"), false);
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
                    case _LOWER:
                        oled_write_ln_P(PSTR("Lower"), false);
                        break;
                    case _ADJST:
                        oled_write_ln_P(PSTR("Adjst"), false);
                        break;
                    default:
                        oled_write_ln_P(PSTR("? ? ?"), false);
                        break;
                }
            break;

            case _COLFN:
            oled_write_ln_P(PSTR("ColFN"), false);

                switch (get_highest_layer(layer_state)) {
                    case _COLFN:
                        oled_write_ln_P(PSTR("Base "), false);
                        break;
                    case _LOWER:
                        oled_write_ln_P(PSTR("Lower"), false);
                        break;
                    case _ADJST:
                        oled_write_ln_P(PSTR("Adjst"), false);
                        break;
                    default:
                        oled_write_ln_P(PSTR("? ? ?"), false);
                        break;
                }
            break;

            case _QWERT:
                oled_write_ln_P(PSTR("Qwert"), false);

                    switch (get_highest_layer(layer_state)) {
                        case _QWERT:
                            oled_write_ln_P(PSTR("Base "), false);
                            break;
                        case _LOWER:
                            oled_write_ln_P(PSTR("Lower"), false);
                            break;
                        case _ADJST:
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
    return false;
}

#endif

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

        case U_COLFN:
            set_single_persistent_default_layer(_COLFN);
            layer_move(_COLFN);
            return false;

        case U_QWERT:
            set_single_persistent_default_layer(_QWERT);
            layer_move(_QWERT);
            return false;


        case U_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJST);
            }
            return false;
        case U_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJST);
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

void keyboard_pre_init_user(void) {

}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    uint8_t layer = get_highest_layer(layer_state);

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];

            if (index >= led_min && index < led_max && index != NO_LED) {

                uint16_t key_code = keymap_key_to_keycode(layer, (keypos_t){col,row});
                switch (key_code) {
                    case LGUI_A:
                    case RGUI_O:
                    case KC_LGUI:
                    case KC_RGUI:
                        if (!keymap_config.swap_lctl_lgui) {
                            rgb_matrix_set_color(index, RGB_WHITE);
                        } else {
                            rgb_matrix_set_color(index, RGB_PURPLE);
                        }
                        break;
                    case LSFTT:
                    case RSFT_N:
                    case KC_LSFT:
                    case KC_RSFT:
                    case KC_LALT:
                    case KC_RALT:
                    case LALT_R:
                    case RALT_I:
                        rgb_matrix_set_color(index, RGB_PURPLE);
                        break;
                    case LCTL_S:
                    case RCTL_E:
                    case KC_LCTL:
                    case KC_RCTL:
                        if (keymap_config.swap_lctl_lgui) {
                            rgb_matrix_set_color(index, RGB_WHITE);
                        } else {
                            rgb_matrix_set_color(index, RGB_PURPLE);
                        }
                        break;
                    default:
                        break;
                }
            }
        }
    }

    return false;
}

void housekeeping_task_user(void) {
    if (is_keyboard_master()) {
        static uint32_t last_sync = 0;
        if (timer_elapsed32(last_sync) > 500) {
            master_to_slave_t m2s = keymap_config.swap_lctl_lgui ? (master_to_slave_t){0} : (master_to_slave_t){6};
            if(transaction_rpc_exec(USER_SYNC_LGUI_SWAP, sizeof(m2s), &m2s, 0, NULL)) {
                last_sync = timer_read32();
            }
        }
    }
}

void user_sync_lgui_swap_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    const master_to_slave_t *m2s = (const master_to_slave_t*)in_data;
    // slave_to_master_t *s2m = (slave_to_master_t*)out_data;
    if (m2s->is_swapped == 0) {
        keymap_config.swap_lctl_lgui = true;
    } else {
        keymap_config.swap_lctl_lgui = false;
    }
}

void keyboard_post_init_user(void) {
    transaction_register_rpc(USER_SYNC_LGUI_SWAP, user_sync_lgui_swap_slave_handler);
}

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

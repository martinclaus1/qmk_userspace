/* Copyright 2023 Brian Low
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
#include "keymap_german.h"
#include "print.h"

enum layers { _MAC0, _MAC1, _MAC2, _WIN0, _WIN1, _WIN2 };

// Use the shift mask to recognize both left and right shift keys
const key_override_t exclamation_mark  = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DE_1, S(DE_1), ~0, (uint8_t)~0);    // !
const key_override_t at_sign           = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DE_2, A(DE_L), ~0, (uint8_t)~0);    // @
const key_override_t hash_sign         = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DE_3, DE_HASH, ~0, (uint8_t)~0);    // #
const key_override_t dollar_sign       = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DE_4, DE_DLR, ~0, (uint8_t)~0);     // $
const key_override_t percent_sign      = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DE_5, DE_PERC, ~0, (uint8_t)~0);    // %
const key_override_t caret_sign        = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DE_6, DE_CIRC, ~0, (uint8_t)~0);    // ^
const key_override_t ampersand_sign    = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DE_7, DE_AMPR, ~0, (uint8_t)~0);    // &
const key_override_t plus_sign         = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DE_8, DE_PLUS, ~0, (uint8_t)~0);    // +
const key_override_t left_parenthesis  = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DE_9, DE_LPRN, ~0, (uint8_t)~0);    // (
const key_override_t right_parenthesis = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DE_0, DE_RPRN, ~0, (uint8_t)~0);    // )
const key_override_t underscore_sign   = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DE_GRV, DE_UNDS, ~0, (uint8_t)~0);  // _
const key_override_t question_mark     = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DE_COMM, DE_QUES, ~0, (uint8_t)~0); // ?
const key_override_t less_than_sign    = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DE_DOT, DE_LABK, ~0, (uint8_t)~0);  // <
const key_override_t greater_than_sign = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DE_SLSH, DE_RABK, ~0, (uint8_t)~0); // >
const key_override_t double_quote_sign = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DE_QUOT, DE_DQUO, ~0, (uint8_t)~0); // "

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {&exclamation_mark, &at_sign, &hash_sign, &dollar_sign, &percent_sign, &caret_sign, &ampersand_sign, &plus_sign, &left_parenthesis, &right_parenthesis, &underscore_sign, &question_mark, &less_than_sign, &greater_than_sign, &double_quote_sign};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Colemak DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  +   |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   +  |   (  |   )  |  _   |
 * |  =   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |  "   |
 * | Tab  |   A  |   R  |   S  |   T  |   G  |       .    ,       |   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |    |       |      |      |   <  |   >  |   ?  |      |
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LALT | LCMD | MO(1)| /Enter  /       \Space \  | MO(2)| RCMD | RALT | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |   ↑  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |      |      |      |      |      |      |-------.    ,-------|      |   ←  |   ↓  |   →  |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

    [_MAC0] = LAYOUT(
        DE_EQL,     DE_1,       DE_2,       DE_3,       DE_4,       DE_5,                               DE_6,       DE_7,       DE_8,       DE_9,       DE_0,       DE_GRV,
        KC_ESC,     DE_Q,       DE_W,       DE_F,       DE_P,       DE_B,                               DE_J,       DE_L,       DE_U,       DE_Y,       DE_SCLN,    KC_BSPC,
        KC_TAB,     DE_A,       DE_R,       DE_S,       DE_T,       DE_G,                               DE_M,       DE_N,       DE_E,       DE_I,       DE_O,       DE_QUOT,
        KC_LSFT,    DE_Z,       DE_X,       DE_C,       DE_D,       DE_V,       KC_MUTE,    KC_MPLY,    DE_K,       DE_H,       DE_COMM,    DE_DOT,     DE_SLSH,    KC_RSFT,
                                KC_LCTL,    KC_LALT,    KC_LCMD,    MO(_MAC1),  KC_ENT,     KC_SPC,     MO(_MAC2),  KC_RCMD,    KC_RALT,    KC_RCTL
    ),
    [_MAC1] = LAYOUT (
        _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    KC_UP,      _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,                            _______,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
    [_MAC2] = LAYOUT (
        _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
        _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    KC_F12,
        _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    )
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_MAC0] = { ENCODER_CCW_CW(MS_WHLD, MS_WHLU), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_MAC1] = { ENCODER_CCW_CW(KC_BRIU, KC_BRID), ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
    [_MAC2] = { ENCODER_CCW_CW(KC_RIGHT, KC_LEFT), ENCODER_CCW_CW(KC_DOWN, KC_UP) }
};
#endif

// clang-format on

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_0; // flips the display 180 degrees if offhand
    }

    return rotation;
}

bool oled_task_user(void) {
    // Check if the keyboard has been inactive
    if (last_input_activity_elapsed() > OLED_TIMEOUT) {
        oled_off();
        return false;
    }

    oled_clear();

    // Only show OS info on the master side
    if (is_keyboard_master()) {
        // Get the OS variant
        os_variant_t os = detected_host_os();

        // Convert enum to appropriate string
        switch (os) {
            case OS_MACOS:
                oled_write_P(PSTR("macOS"), false);
                break;
            case OS_WINDOWS:
                oled_write_P(PSTR("Windows"), false);
                break;
            case OS_LINUX:
                oled_write_P(PSTR("Linux"), false);
                break;
            case OS_IOS:
                oled_write_P(PSTR("iOS"), false);
                break;
            default:
                oled_write_P(PSTR("Unknown"), false);
                break;
        }
    } else {
        // For the slave half, display a different message or leave blank
        oled_write_P(PSTR("Sofle"), false);
    }

    return false;
}
#endif

bool process_detected_host_os_user(os_variant_t detected_os) {
    switch (detected_os) {
        case OS_LINUX:
        case OS_UNSURE:
        case OS_WINDOWS:
            layer_move(_MAC0);
            break;
        case OS_MACOS:
        case OS_IOS:
            layer_move(_MAC0);
            break;
    }

    return true;
}

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv(5, 217, 210);
}

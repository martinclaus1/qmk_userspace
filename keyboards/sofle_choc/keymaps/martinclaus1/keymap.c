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

enum layers {
    _MAC0,
    _MAC1,
    _MAC2,
    _WIN0,
    _WIN1,
    _WIN2
};


// const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_1, KC_MUTE);

// // This globally defines all key overrides to be used
// const key_override_t *key_overrides[] = {
// 	&delete_key_override
// };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Colemak DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LALT | LCMD | MO(1)| /Enter  /       \Space \  | MO(2)| RCMD | RALT | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   ↑  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   ←  |   ↓  |   →  |   O  |  '   |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LALT | LCMD | MO(1)| /Enter  /       \Space \  | MO(2)| RCMD | RALT | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ~   |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |  |   |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|   =  |   -  |   +  |   {  |   }  |-------|    |-------|   [  |   ]  |   ,  |   .  |   \  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LALT | LCMD | MO(1)| /Enter  /       \Space \  | MO(2)| RCMD | RALT | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

    [_MAC0] = LAYOUT(
        DE_LABK,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    DE_GRV,
        KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                       KC_J,     KC_L,     KC_U,    DE_Y,    DE_SCLN, KC_BSPC,
        KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                       KC_M,     KC_N,     KC_E,    KC_I,    KC_O,    DE_QUOT,
        KC_LSFT,  DE_Z,   KC_X,    KC_C,    KC_D,    KC_V,  KC_MUTE,    KC_MPLY, KC_K,     KC_H,     KC_COMM, KC_DOT,  DE_SLSH, KC_RSFT,
                          KC_LCTL, KC_LALT, KC_LCMD, MO(_MAC1), KC_ENT,     KC_SPC,  MO(_MAC2),  KC_RCMD,  KC_RALT, KC_RCTL
    ),
    [_MAC1] = LAYOUT (
        DE_LABK,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_GRV,
        KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                       KC_J,     KC_L,     KC_UP,   DE_Y,    DE_SCLN, KC_BSPC,
        KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                       KC_M,     KC_LEFT,  KC_DOWN, KC_RIGHT,KC_O,    KC_QUOT,
        KC_LSFT,  DE_Z,   KC_X,    KC_C,    KC_D,    KC_V,  KC_MUTE,   KC_MPLY,  KC_K,     KC_H,     KC_COMM, KC_DOT,  DE_SLSH, KC_RSFT,
                        _______, _______, _______, MO(_MAC1), KC_ENT,    KC_SPC,   MO(_MAC2),  _______,  _______, _______
    ),
    [_MAC2] = LAYOUT (
        DE_LABK,   KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,    KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                       KC_J,     KC_L,     KC_U,    DE_Y,    DE_SCLN, KC_F12,
        KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                       KC_M,     KC_N,     KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LSFT,  DE_EQL, DE_MINS, DE_PLUS, DE_LCBR, DE_RCBR, KC_MUTE,   KC_MPLY,  KC_A,     KC_H,     KC_COMM, KC_DOT,  DE_SLSH, KC_RSFT,
        _______, _______, _______, MO(_MAC1), KC_ENT,    KC_SPC,   MO(_MAC2),  _______,  _______, _______
    ),
    [_WIN0] = LAYOUT(
        DE_LABK,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    DE_GRV,
        KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                       KC_J,     KC_L,     KC_U,    DE_Y,    DE_SCLN, KC_BSPC,
        KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                       KC_M,     KC_N,     KC_E,    KC_I,    KC_O,    DE_QUOT,
        KC_LSFT,  DE_Z,   KC_X,    KC_C,    KC_D,    KC_V,  KC_MUTE,    KC_MPLY, KC_K,     KC_H,     KC_COMM, KC_DOT,  DE_SLSH, KC_RSFT,
                          KC_LCTL, KC_LALT, KC_LCMD, MO(_WIN1), KC_ENT,     KC_SPC,  MO(_WIN2),  KC_RCMD,  KC_RALT, KC_RCTL
    ),
    [_WIN1] = LAYOUT (
        DE_LABK,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_GRV,
        KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                       KC_J,     KC_L,     KC_UP,   DE_Y,    DE_SCLN, KC_BSPC,
        KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                       KC_M,     KC_LEFT,  KC_DOWN, KC_RIGHT,KC_O,    KC_QUOT,
        KC_LSFT,  DE_Z,   KC_X,    KC_C,    KC_D,    KC_V,  KC_MUTE,   KC_MPLY,  KC_K,     KC_H,     KC_COMM, KC_DOT,  DE_SLSH, KC_RSFT,
                          KC_LCTL, KC_LALT, KC_LCMD, MO(_WIN1), KC_ENT,    KC_SPC,   MO(_WIN2),  KC_RCMD,  KC_RALT, KC_RCTL
    ),
    [_WIN2] = LAYOUT (
        DE_LABK,   KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,    KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                       KC_J,     KC_L,     KC_U,    DE_Y,    DE_SCLN, KC_F12,
        KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                       KC_M,     KC_N,     KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LSFT,  DE_EQL, DE_MINS, DE_PLUS, DE_LCBR, DE_RCBR, KC_MUTE,   KC_MPLY,  KC_A,     KC_H,     KC_COMM, KC_DOT,  DE_SLSH, KC_RSFT,
                          KC_LCTL, KC_LALT, KC_LCMD, MO(_WIN1), KC_ENT,    KC_SPC,   MO(_WIN2),  KC_RCMD,  KC_RALT, KC_RCTL
    )
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_MAC0] = { ENCODER_CCW_CW(MS_WHLD, MS_WHLU), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_MAC1] = { ENCODER_CCW_CW(KC_BRIU, KC_BRID), ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
    [_MAC2] = { ENCODER_CCW_CW(KC_RIGHT, KC_LEFT), ENCODER_CCW_CW(KC_DOWN, KC_UP) },
    [_WIN0] = { ENCODER_CCW_CW(MS_WHLD, MS_WHLU), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_WIN1] = { ENCODER_CCW_CW(KC_BRIU, KC_BRID), ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
    [_WIN2] = { ENCODER_CCW_CW(KC_RIGHT, KC_LEFT), ENCODER_CCW_CW(KC_DOWN, KC_UP) }
};
#endif

#ifdef OLED_ENABLE
    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        if (is_keyboard_master()) {
            return OLED_ROTATION_0;  // flips the display 180 degrees if offhand
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
                    layer_move(_MAC0);
                    break;
                case OS_WINDOWS:
                    oled_write_P(PSTR("Windows"), false);
                    layer_move(_WIN0);
                    break;
                case OS_LINUX:
                    oled_write_P(PSTR("Linux"), false);
                    layer_move(_WIN0);
                    break;
                case OS_IOS:
                    oled_write_P(PSTR("iOS"), false);
                    layer_move(_MAC0);
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


void keyboard_post_init_user(void) {
}

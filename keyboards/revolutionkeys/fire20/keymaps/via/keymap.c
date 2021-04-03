/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#define _BASE 0
#define _F1 1
#define _F2 2
#define _F3 3
enum custom_keycodes {
  SPOTIFY_PLAY = SAFE_RANGE,
  CHROME_PLAY,
  PLAY_ALL,
  PAUSE_ALL,
};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SPOTIFY_PLAY:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                tap_code(KC_MPLY);
                unregister_code(KC_LSFT);
            } else {
            }
            break;
        case CHROME_PLAY:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_MPLY);
                unregister_code(KC_LGUI);
            } else {
            }
            break;
        case PLAY_ALL:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LSFT);
                tap_code(KC_MPLY);
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
            } else {
            }
            break;
        case PAUSE_ALL:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_MPLY);
                unregister_code(KC_LALT);
            } else {
            }
            break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_25(
    TO(0), KC_Y,   KC_Z,	\
    TO(0), SPOTIFY_PLAY, KC_P9, KC_PEQL, KC_A, \
    TO(1), PAUSE_ALL, KC_P6, KC_PAST, KC_B, \
    TO(2), PLAY_ALL, KC_P3, KC_PSLS, KC_C, \
    TO(3), KC_PDOT, KC_PMNS, KC_PPLS, KC_D \
  ),
[_F1] = LAYOUT_25(
    TO(0), KC_Y,   KC_Z,	\
    TO(0), KC_P8, KC_P9, KC_PEQL, KC_A, \
    TO(1), KC_P5, KC_P6, KC_PAST, KC_B, \
    TO(2), KC_P2, KC_P3, KC_PSLS, KC_C, \
    TO(3), KC_PDOT, KC_PMNS, KC_PPLS, KC_D \
  ),
[_F2] = LAYOUT_25(
    TO(3), KC_Y,   KC_Z,	\
    TO(0), KC_P8, KC_P9, KC_PEQL, KC_A, \
    TO(1), KC_P5, KC_P6, KC_PAST, KC_B, \
    TO(2), KC_P2, KC_P3, KC_PSLS, KC_C, \
    TO(3), KC_PDOT, KC_PMNS, KC_PPLS, KC_D \
  ),
[_F3] = LAYOUT_25(
    TO(0), KC_Y,   KC_Z,	\
    TO(0), CHROME_PLAY, KC_P9, KC_PEQL, KC_A, \
    TO(1), KC_P5, KC_P6, KC_PAST, KC_B, \
    TO(2), KC_P2, KC_P3, KC_PSLS, KC_C, \
    TO(3), KC_PDOT, KC_PMNS, KC_PPLS, RESET \
  )
};
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
           switch (get_highest_layer(layer_state)) {
                case _BASE:
                    register_code(KC_LSFT);
                    tap_code(KC_VOLU);
                    //tap_code(KC_WH_U);           
                    unregister_code(KC_LSFT);
                    break;
                case _F1:
                    register_code(KC_LCTL);
                    tap_code(KC_VOLU);
                    //tap_code(KC_WH_U);           
                    unregister_code(KC_LCTL);
                    break;
                case _F2:
                    register_code(KC_LALT);
                    tap_code(KC_VOLU);
                    //tap_code(KC_WH_U);           
                    unregister_code(KC_LALT);
                    break;
                case _F3:
                    register_code(KC_LWIN);
                    tap_code(KC_VOLU);
                    //tap_code(KC_WH_U);           
                    unregister_code(KC_LWIN);
                    break;
                default:
                    tap_code(KC__VOLUP);
            }
        } else {
            switch (get_highest_layer(layer_state)) {
                case _BASE:
                    register_code(KC_LSFT);
                    tap_code(KC_VOLD);
                    //tap_code(KC_WH_D);           
                    unregister_code(KC_LSFT);
                    break;
                case _F1:
                    register_code(KC_LCTL);
                    tap_code(KC_VOLD);
                    //tap_code(KC_WH_D);           
                    unregister_code(KC_LCTL);
                    break;
                case _F2:
                    register_code(KC_LALT);
                    tap_code(KC_VOLD);
                    //tap_code(KC_WH_D);           
                    unregister_code(KC_LALT);
                    break;
                case _F3:
                    register_code(KC_LWIN);
                    tap_code(KC_VOLD);
                    //tap_code(KC_WH_D);           
                    unregister_code(KC_LWIN);
                    break;
                default:
                    tap_code(KC__VOLDOWN);
            }
        }
    }
    if (index == 1) { /* Second encoder */
         if (clockwise) {
            switch (get_highest_layer(layer_state)) {
                case _BASE:
                    tap_code(KC_VOLU);
                    tap_code(KC__VOLUP);
                    break;
                case _F1:
                    rgblight_increase_val();
                    break;
                case _F2:
                    tap_code(KC_W);
                    //tap_code(KC__VOLUP);
                    break;
                case _F3:
                    //tap_code(KC__VOLUP);
                    break;
                default:
                    tap_code(KC__VOLUP);
            }
        } else {
             switch (get_highest_layer(layer_state)) {
                case _BASE:
                    tap_code(KC_VOLD);
                    tap_code(KC__VOLDOWN);
                    break;
                case _F1:
                    rgblight_decrease_val();
                    break;
                case _F2:
                    register_code(KC_LSFT);
                    tap_code(KC_W);
                    unregister_code(KC_LSFT);
                    break;
                case _F3:
                    //tap_code(KC__VOLUP);
                    break;
                default:
                    tap_code(KC__VOLDOWN);
            }
        }
    }
    if (index == 2) { /* Top encoder */
          if (clockwise) {
            switch (get_highest_layer(layer_state)) {
                case _BASE:
                    tap_code(KC_PGDN);
                    break;
                case _F1:
	                rgblight_step();
                    break;
                case _F2:
                    
                    break;
                case _F3:
                    //tap_code(KC__VOLUP);
                    break;
            }
        } else {
             switch (get_highest_layer(layer_state)) {
                case _BASE:
                    tap_code(KC_PGUP);
                    break;
                case _F1:
	                rgblight_step_reverse();
                    break;
                case _F2:
                    //tap_code(KC__VOLUP);
                    break;
                case _F3:
                    //tap_code(KC__VOLUP);
                    break;
            }
        }
        if (clockwise) {
            //tap_code(KC__VOLUP);
	    
        } else {
            //tap_code(KC__VOLDOWN);
	    
        }
    }

}
#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("LAY\n"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("DEF\n"), false);
            break;
        case _F1:
            oled_write_P(PSTR("F1\n"), false);
            break;
        case _F2:
            oled_write_P(PSTR("F2\n"), false);
            break;
        case _F3:
            oled_write_P(PSTR("F3\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif

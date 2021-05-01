/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

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

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6465
#define DEVICE_VER      0x0001
#define MANUFACTURER    none
#define PRODUCT         onekey

// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_COL_PINS { A15, B4, B5, B10, B0, A7 }
#define MATRIX_ROW_PINS { B12, B13, B15, A8, A10, A11 }
#define MATRIX_COL_PINS_RIGHT { A15, B4, B5, B10, B0, A7 }
#define MATRIX_ROW_PINS_RIGHT { B12, B13, B15, A8, A10, A11 }

#define DIODE_DIRECTION COL2ROW

#define ENCODERS_PAD_A {A3}
#define ENCODERS_PAD_B {A2}
#define ENCODERS_RESOLUTION 4

#define RGBLIGHT_LIMIT_VAL 120

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

#define TAPPING_TERM 500

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


#define SPLIT_HAND_PIN B9
#define SOFT_SERIAL_PIN B6
//#define SELECT_SOFT_SERIAL_SPEED 0
#define SERIAL_USART_SPEED 921600
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */
#define RGB_DI_PIN B1
#define RGBLED_NUM 1
#define RGBLIGHT_ANIMATIONS

#define WS2812_PWM_DRIVER PWMD3
#define WS2812_PWM_CHANNEL 4
#define WS2812_PWM_PAL_MODE 2
#define WS2812_DMA_STREAM STM32_DMA1_STREAM2
#define WS2812_DMA_CHANNEL 5


/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

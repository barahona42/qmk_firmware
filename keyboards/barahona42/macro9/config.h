// Copyright 2023 Sebastian Stumpf (@sebastian-stumpf)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
/** TAP DANCE */


/** ENCODER */
#define ENCODER_A_PINS {GP1}
#define ENCODER_B_PINS {GP2}
#define NUM_ENCODERS 1
#define NUM_DIRECTIONS 2

/** BOOTLOADER OPTIONS */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U



/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#ifndef CONFIG_KEYMAP_H
#define CONFIG_KEYMAP_H

#include "../../config.h"

// Trim down on underglow effect
#undef RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_STATIC_GRADIENT

// Enable backlight breathing
#define BACKLIGHT_BREATHING
// Disable backlight when sleeping
//#define RGBLIGHT_SLEEP

#define TAPPING_TERM 150

// Disable legacy MACRO and FUNCTION keys
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#endif

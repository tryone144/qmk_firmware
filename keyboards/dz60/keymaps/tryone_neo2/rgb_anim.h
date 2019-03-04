#ifndef RGB_ANIM_H
#define RGB_ANIM_H

#include "rgblight.h"

#define RGB_ANIM_DURATION_LAYER 500
#define RGB_ANIM_DURATION_WAKEUP 5000
#define RGB_ANIM_DURATION_WINLOCK 500
#define RGB_ANIM_MODE_LAYER (RGBLIGHT_MODE_SNAKE + 4)
#define RGB_ANIM_MODE_WAKEUP (RGBLIGHT_MODE_BREATHING + 2)
#define RGB_ANIM_MODE_WINLOCK (RGBLIGHT_MODE_SNAKE + 4)

#define RGB_ANIM_HUE_BASE 0
#define RGB_ANIM_HUE_QWERTZ 60
#define RGB_ANIM_HUE_NEO2 120
#define RGB_ANIM_HUE_EMULATOR 270

#define RGB_ANIM_HUE_WIN_LOCKED 16
#define RGB_ANIM_HUE_WIN_UNLOCKED 80


void rgb_anim_start(uint16_t duration, uint16_t mode, uint16_t hue, uint8_t sat, uint8_t val);
void rgb_anim_update(void);
void rgb_anim_reset(void);

#endif // RGB_ANIM_H

// vim: set ts=2 sw=2 sts=4 et:

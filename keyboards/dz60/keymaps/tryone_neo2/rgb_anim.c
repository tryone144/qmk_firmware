#include "timer.h"
#include "rgb_anim.h"

static rgblight_config_t rgb_config;

static bool rgb_anim = false;
static uint16_t rgb_anim_duration = 0;
static uint16_t rgb_anim_timer = 0;

// Start a new timed animation
void rgb_anim_start(uint16_t duration, uint16_t mode, uint16_t hue, uint8_t sat, uint8_t val) {
  rgb_config.raw = eeconfig_read_rgblight();
  rgb_anim = true;
  rgb_anim_duration = duration;
  rgb_anim_timer = timer_read();

  rgblight_enable_noeeprom();
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
  rgblight_sethsv_noeeprom(hue, sat, val);
  rgblight_mode_noeeprom(mode);
}

// Update and handle the animation timer
void rgb_anim_update() {
  if (rgb_anim) { // Reset current animation if ANIM_TIME is over
    if (timer_elapsed(rgb_anim_timer) > rgb_anim_duration) {
      rgb_anim = false;
      rgblight_update_dword(rgb_config.raw);
    }
  }
}

// Reset a running animation
void rgb_anim_reset() {
  if (rgb_anim) {
    rgb_anim = false;
    rgblight_update_dword(rgb_config.raw);
  }
}

// vim: set ts=2 sw=2 sts=4 et:

#include QMK_KEYBOARD_H

#include "keymap_german.h"
#include "keymap_neo2.h"

// ==== LAYERS ====
enum layers_idx {
    _BASE = 0,  // Base Layer (Software Neo2)
    _QWERTZ,    // QWERTY Hardware emulation on Neo2 Software
    _NEO2,      // Neo2 Hardware emulation on QWERTZ Software
    _NEO2_L1,   // Neo2 (Layer 1) Hardware emulation on QWERTZ Software
    _FUNCTION,  // Function Layer
    _PROGRAM,   // Programming functions (Layer / RGB Lighting)
};

#define _BL _BASE
#define _QL _QWERTZ
#define _NL _NEO2
#define _NL1 _NEO2_L1
#define _FN _FUNCTION
#define _PN _PROGRAM

// ==== KEYCODES ====
#define ________ KC_TRNS
#define ___XX___ KC_TRNS
#define XXX KC_NO

#define MG_SCCL MAGIC_SWAP_CONTROL_CAPSLOCK
#define MG_USCCL MAGIC_UNSWAP_CONTROL_CAPSLOCK

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* === BASE LAYER === (software Neo2)
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  `  |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  X  |  V  |  L  |  C  |  W  |  K  |  H  |  G  |  F  |  Q  |  ß  |  ´  |  Enter |
   * |---------------------------------------------------------------------------------+       +
   * |  Ctrl   |  U  |  I  |  A  |  E  |  O  |  S  |  N  |  R  |  T  |  D  |  Y  |NeoL1|       |
   * |-----------------------------------------------------------------------------------------+
   * |LShift|NeoL2|  Ü  |  Ö  |  Ä  |  P  |  Z  |  B  |  M  |  ,  |  .  |  J  |  RShift  | Pn  |
   * |-----------------------------------------------------------------------------------------+
   * | NeoL1 | Win  | Alt  |  Space     |  Fn   |   RShift        | NeoL2 | Win  | Ctrl | Menu |
   * `-----------------------------------------------------------------------------------------'
   */
  [_BASE] = LAYOUT_60_iso_split_2fn(
    KC_ESC,   NEO_1,    NEO_2,    NEO_3,    NEO_4,    NEO_5,    NEO_6,    NEO_7,    NEO_8,    NEO_9,    NEO_0,    NEO_MINS, NEO_GRV,  KC_BSPC,
    KC_TAB,   NEO_X,    NEO_V,    NEO_L,    NEO_C,    NEO_W,    NEO_K,    NEO_H,    NEO_G,    NEO_F,    NEO_Q,    NEO_SS,   NEO_ACUT,
    KC_LCTL,  NEO_U,    NEO_I,    NEO_A,    NEO_E,    NEO_O,    NEO_S,    NEO_N,    NEO_R,    NEO_T,    NEO_D,    NEO_Y,    NEO_L1_R, KC_ENT,
    KC_LSFT,  NEO_L2_L, NEO_UE,   NEO_OE,   NEO_AE,   NEO_P,    NEO_Z,    NEO_B,    NEO_M,    NEO_COMM, NEO_DOT,  NEO_J,    KC_RSFT,  MO(_PN),
    NEO_L1_L, KC_LGUI,  KC_LALT,  KC_SPC,             MO(_FN),            KC_RSFT,                      NEO_L2_R, KC_RGUI,  KC_RCTL,  KC_APP
  ),

  /* === QWERTZ LAYER === (Hardware emulation of QWERTZ on Software Neo2)
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  ß  |  ´  |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Z  |  U  |  I  |  O  |  P  |  Ü  |  +  |  Enter |
   * |---------------------------------------------------------------------------------+       +
   * |  Ctrl   |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  Ö  |  Ä  |  #  |       |
   * |-----------------------------------------------------------------------------------------+
   * |LShift|  <  |  Y  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  -  |  RShift  | Pn  |
   * |-----------------------------------------------------------------------------------------+
   * |       | Win  | Alt  |  Space     |  Fn   |   RShift        | AltGr | Win  | Ctrl | Menu |
   * `-----------------------------------------------------------------------------------------'
   */
  [_QWERTZ] = LAYOUT_60_iso_split_2fn(
    KC_ESC,   DE_1,     DE_2,     DE_3,     DE_4,     DE_5,     DE_6,     DE_7,     DE_8,     DE_9,     DE_0,     DE_UE,    DE_PLUS,  KC_BSPC,
    KC_TAB,   DE_P,     DE_T,     DE_F,     DE_K,     DE_L,     DE_B,     DE_A,     DE_S,     DE_G,     DE_V,     DE_Y,     XXX,
    KC_LCTL,  DE_D,     DE_H,     DE_OE,    DE_O,     DE_I,     DE_U,     DE_MINS,  DE_Z,     DE_E,     DE_X,     DE_C,     XXX,      KC_ENT,
    KC_LSFT,  XXX,      DE_AE,    DE_Q,     DE_R,     DE_W,     DE_N,     DE_J,     DE_M,     DE_COMM,  DE_DOT,   DE_SS,    KC_RSFT,  MO(_PN),
    XXX,      KC_LGUI,  KC_LALT,  KC_SPC,             MO(_FN),            KC_RSFT,                      XXX,      KC_RGUI,  KC_RCTL,  KC_APP
  ),

  /* === NEO2 LAYER === (Hardware emulation of Neo2 on Software QWERTZ)
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  `  |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  X  |  V  |  L  |  C  |  W  |  K  |  H  |  G  |  F  |  Q  |  ß  |  ´  |  Enter |
   * |---------------------------------------------------------------------------------+       +
   * |  Ctrl   |  U  |  I  |  A  |  E  |  O  |  S  |  N  |  R  |  T  |  D  |  Y  |NeoL1|       |
   * |-----------------------------------------------------------------------------------------+
   * |LShift|NeoL2|  Ü  |  Ö  |  Ä  |  P  |  Z  |  B  |  M  |  ,  |  .  |  J  |  RShift  | Pn  |
   * |-----------------------------------------------------------------------------------------+
   * | NeoL1 | Win  | Alt  |  Space     |  Fn   |   RShift        | NeoL2 | Win  | Ctrl | Menu |
   * `-----------------------------------------------------------------------------------------'
   */
  [_NEO2] = LAYOUT_60_iso_split_2fn(
    KC_ESC,   DE_1,     DE_2,     DE_3,     DE_4,     DE_5,     DE_6,     DE_7,     DE_8,     DE_9,     DE_0,     DE_MINS,  DE_GRV,   KC_BSPC,
    KC_TAB,   DE_X,     DE_V,     DE_L,     DE_C,     DE_W,     DE_K,     DE_H,     DE_G,     DE_F,     DE_Q,     DE_SS,    DE_ACUT,
    KC_LCTL,  DE_U,     DE_I,     DE_A,     DE_E,     DE_O,     DE_S,     DE_N,     DE_R,     DE_T,     DE_D,     DE_Y,     MO(_NL1), KC_ENT,
    KC_LSFT,  XXX,      DE_UE,    DE_OE,    DE_AE,    DE_P,     DE_Z,     DE_B,     DE_M,     DE_COMM,  DE_DOT,   DE_J,     KC_RSFT,  MO(_PN),
    MO(_NL1), KC_LGUI,  KC_LALT,  KC_SPC,             MO(_FN),            KC_RSFT,                      XXX,      KC_RGUI,  KC_RCTL,  KC_APP
  ),

  /* === NEO2 LAYER (LAYER 1) === (Hardware emulation of Neo2 Layer 1 on Software QWERTZ)
   * ,-----------------------------------------------------------------------------------------.
   * | Esc | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    | XXX |  _  |  [  |  ]  |  ^  |  !  |  <  |  >  |  =  |  &  | XXX | XXX |  Enter |
   * |---------------------------------------------------------------------------------+       +
   * |  Ctrl   |  \  |  /  |  {  |  }  |  *  |  ?  |  (  |  )  |  -  |  :  |  @  |NeoL1|       |
   * |-----------------------------------------------------------------------------------------+
   * | XXX  | XXX |  #  |  $  |  |  |  ~  |  `  |  +  |  %  |  "  |  '  |  ;  |   XXX    | Pn  |
   * |-----------------------------------------------------------------------------------------+
   * | NeoL1 | Win  | Alt  |  Space     |  Fn   |   RShift        |  XXX  | Win  | Ctrl | Menu |
   * `-----------------------------------------------------------------------------------------'
   */
  [_NEO2_L1] = LAYOUT_60_iso_split_2fn(
    KC_ESC,   XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      KC_BSPC,
    KC_TAB,   XXX,      DE_UNDS,  DE_LBRC,  DE_RBRC,  DE_CIRC,  DE_EXLM,  DE_LESS,  DE_MORE,  DE_EQL,   DE_AMPR,  XXX,      XXX,
    KC_LCTL,  DE_BSLS,  DE_SLSH,  DE_LCBR,  DE_RCBR,  DE_ASTR,  DE_QST,   DE_LPRN,  DE_RPRN,  DE_MINS,  DE_COLN,  DE_AT,    ___XX___, KC_ENT,
    XXX,      XXX,      DE_HASH,  DE_DLR,   DE_PIPE,  DE_TILD,  DE_GRV,   DE_PLUS,  DE_PERC,  DE_DQOT,  DE_QUOT,  DE_SCLN,  XXX,      MO(_PN),
    ___XX___, KC_LGUI,  KC_LALT,  KC_SPC,             MO(_FN),            XXX,                          XXX,      KC_RGUI,  KC_RCTL,  KC_APP
  ),

  /* === FUNCTION LAYER ===
   */
  [_FUNCTION] = LAYOUT_60_iso_split_2fn(
    NEO_CIRC, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,
    ________, ________, ________, ________, ________, ________, ________, KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_VOLU,  KC_MUTE,
    ________, ________, ________, ________, ________, ________, ________, KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_VOLD,  KC_PSCR,  ________,
    ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, XXX,
    ________, ________, ________, ________,           ___XX___,           ________,                     ________, ________, ________, ________
  ),

  /* === PROGRAMMING LAYER === (Programming functions: Layer switching / RGB Lighting)
   */
  [_PROGRAM] = LAYOUT_60_iso_split_2fn(
    RESET,    DF(_BL),  DF(_QL),  DF(_NL),  XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,
    XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      BL_TOGG,  BL_INC,
    MG_USCCL, RGB_VAI,  RGB_HUI,  RGB_SAI,  XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      BL_BRTG,  BL_DEC,   XXX,
    ___XX___, RGB_MOD,  RGB_VAD,  RGB_HUD,  RGB_SAD,  XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      ___XX___, ___XX___,
    MG_SCCL,  XXX,      XXX,      RGB_TOG,            XXX,                XXX,                          XXX,      XXX,      XXX,      XXX
  )
};

// ==== CUSTOM ACTIONS ====
#define RGB_ANIM_LAYER 500

static rgblight_config_t rgb_config;
static bool rgb_anim = false;
static uint16_t rgb_anim_duration = 0;
static uint16_t rgb_anim_timer = 0;

// Safe previous config and start animation
void rgb_anim_start(uint16_t duration, uint16_t mode, uint8_t hue, uint8_t sat, uint8_t val) {
  rgb_config.raw = eeconfig_read_rgblight();
  rgb_anim = true;
  rgb_anim_duration = duration;
  rgb_anim_timer = timer_read();

  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(hue, sat, val);
  rgblight_mode_noeeprom(mode);
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
  if (rgb_anim) { // Reset current animation if ANIM_TIME is over
    if (timer_elapsed(rgb_anim_timer) > rgb_anim_duration) {
      rgb_anim = false;
      rgblight_update_dword(rgb_config.raw);
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DF(_BL):
      if (record->event.pressed) {
        rgb_anim_start(RGB_ANIM_LAYER, 19,  0, 255, 255);
      }
      return true;
    case DF(_QL):
      if (record->event.pressed) {
        rgb_anim_start(RGB_ANIM_LAYER, 19,  60, 255, 255);
      }
      return true;
    case DF(_NL):
      if (record->event.pressed) {
        rgb_anim_start(RGB_ANIM_LAYER, 19, 120, 255, 255);
      }
      return true;
  default:
    return true;
  }
}

//uint32_t layer_state_set_user(uint32_t state) {
//  switch (biton32(state)) {
//    case _BASE:
//      rgblight_setrgb(0x00,  0x00, 0xFF);
//      break;
//    case _QWERTZ:
//      rgblight_setrgb(0xFF,  0x00, 0x00);
//      break;
//    case _NEO2:
//      rgblight_setrgb(0x00,  0xFF, 0x00);
//      break;
//    default:
//      rgblight_setrgb(0x00,  0xFF, 0xFF);
//      break;
//  }
//  return state;
//}

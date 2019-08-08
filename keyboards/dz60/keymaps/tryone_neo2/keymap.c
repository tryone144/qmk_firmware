#include QMK_KEYBOARD_H

#include "keymap_german.h"
#include "keymap_neo2.h"

#include "rgb_anim.h"


// ==== LAYERS ====
enum layers_idx {
  _BASE = 0,      // Base Layer (Software Neo2)
  _EMULATOR,      // 40% Emulation Layer (Software Neo2)
  _QWERTZ,        // QWERTY Hardware emulation on Neo2 Software
  _NEO2,          // Neo2 Hardware emulation on QWERTZ Software
  _NEO2_L1,       // Neo2 (Layer 1 / Symbols) Hardware emulation on QWERTZ Software
  _NEO2_L2,       // Neo2 (Layer 2 / Navigation) Hardware emulation on QWERTZ Software
  _FUNCTION,      // Function Layer
  _PROGRAM,       // Programming functions (Layer / RGB Lighting)
};

#define _BL _BASE
#define _40 _EMULATOR
#define _QL _QWERTZ
#define _NL _NEO2
#define _NL1 _NEO2_L1
#define _NL2 _NEO2_L2
#define _FN _FUNCTION
#define _PN _PROGRAM

// ==== KEYCODES ====
enum function_keycodes {
  BB_FN_PROGRAM = SAFE_RANGE,
  BB_FN_LOCK_WIN,
  BB_FN_RGB_CONFIG_1,
  BB_FN_RGB_CONFIG_2,
  BB_FN_RGB_CONFIG_3,
  BB_FN_RGB_CONFIG_4,
  BB_FN_RESET_EEPROM,
  BB_FN_SAFE_RANGE,
};

enum macro_keycodes {
  BB_MACRO_QWERTZ_1 = BB_FN_SAFE_RANGE,
  //BB_MACRO_QWERTZ_2,
  //BB_MACRO_QWERTZ_3,
  //BB_MACRO_QWERTZ_4,
  //BB_MACRO_QWERTZ_5,
  //BB_MACRO_QWERTZ_6,
  //BB_MACRO_QWERTZ_7,
  //BB_MACRO_QWERTZ_8,
  //BB_MACRO_QWERTZ_9,
  //BB_MACRO_QWERTZ_0,
  //BB_MACRO_QWERTZ_SS,
  //BB_MACRO_QWERTZ_ACUT,
  BB_MACRO_QWERTZ_HASH,
  BB_MACRO_QWERTZ_PLUS,
  BB_MACRO_QWERTZ_COMM,
  BB_MACRO_QWERTZ_DOT,
  BB_MACRO_QWERTZ_MINS,
  BB_MACRO_QWERTZ_LESS,
  BB_MACRO_SAFE_RANGE,
};

#define ________ KC_TRNS
#define ___XX___ KC_TRNS
#define XXX KC_NO

#define MG_SCCL  MAGIC_SWAP_CONTROL_CAPSLOCK
#define MG_USCCL MAGIC_UNSWAP_CONTROL_CAPSLOCK

#define MT_RSFT  RSFT_T(KC_ENT)
#define MT_LCTL  LCTL_T(KC_ESC)

#define _BB_PN   BB_FN_PROGRAM
#define _BB_LOCK BB_FN_LOCK_WIN
#define _BB_RST  BB_FN_RESET_EEPROM
#define _BB_RGB1 BB_FN_RGB_CONFIG_1
#define _BB_RGB2 BB_FN_RGB_CONFIG_2
#define _BB_RGB3 BB_FN_RGB_CONFIG_3
#define _BB_RGB4 BB_FN_RGB_CONFIG_4

#define _QL_HASH BB_MACRO_QWERTZ_HASH
#define _QL_PLUS BB_MACRO_QWERTZ_PLUS
#define _QL_COMM BB_MACRO_QWERTZ_COMM
#define _QL_DOT  BB_MACRO_QWERTZ_DOT
#define _QL_MINS BB_MACRO_QWERTZ_MINS
#define _QL_LESS BB_MACRO_QWERTZ_LESS

#define _NL_NL1L MO(_NEO2_L1)
#define _NL_NL1R MO(_NEO2_L1)
#define _NL_NL2L MO(_NEO2_L2)
#define _NL_NL2R MO(_NEO2_L2)


// ==== LAYOUT CONFIGURATION ====
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* === BASE LAYER === (software Neo2)
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  `  |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  X  |  V  |  L  |  C  |  W  |  K  |  H  |  G  |  F  |  Q  |  ß  |  ´  |  Enter |
   * |---------------------------------------------------------------------------------+       +
   * |Ctrl(Esc)|  U  |  I  |  A  |  E  |  O  |  S  |  N  |  R  |  T  |  D  |  Y  |NeoL1|       |
   * |-----------------------------------------------------------------------------------------+
   * |LShift|NeoL2|  Ü  |  Ö  |  Ä  |  P  |  Z  |  B  |  M  |  ,  |  .  |  J  |  RShift  | Pn  |
   * |-----------------------------------------------------------------------------------------+
   * | NeoL1 | Win  | Alt  |  Space     |  Fn   |  RShift(Enter)  | NeoL2 | Win  | Ctrl | Menu |
   * `-----------------------------------------------------------------------------------------'
   */
  [_BASE] = LAYOUT_60_iso_split_2fn(
    KC_ESC,   NEO_1,    NEO_2,    NEO_3,    NEO_4,    NEO_5,    NEO_6,    NEO_7,    NEO_8,    NEO_9,    NEO_0,    NEO_MINS, NEO_GRV,  KC_BSPC,
    KC_TAB,   NEO_X,    NEO_V,    NEO_L,    NEO_C,    NEO_W,    NEO_K,    NEO_H,    NEO_G,    NEO_F,    NEO_Q,    NEO_SS,   NEO_ACUT,
    MT_LCTL,  NEO_U,    NEO_I,    NEO_A,    NEO_E,    NEO_O,    NEO_S,    NEO_N,    NEO_R,    NEO_T,    NEO_D,    NEO_Y,    NEO_L1_R, KC_ENT,
    KC_LSFT,  NEO_L2_L, NEO_UE,   NEO_OE,   NEO_AE,   NEO_P,    NEO_Z,    NEO_B,    NEO_M,    NEO_COMM, NEO_DOT,  NEO_J,    KC_RSFT,  _BB_PN,
    NEO_L1_L, KC_LGUI,  KC_LALT,  KC_SPC,             MO(_FN),            MT_RSFT,                      NEO_L2_R, KC_RGUI,  KC_RCTL,  KC_APP
  ),

  /* === 40% EMULATION LAYER === (software Neo2)
   * ,-----------------------------------------------------------------------------------------.
   * | Esc | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX |   XXX     |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  X  |  V  |  L  |  C  |  W  |  K  |  H  |  G  |  F  |  Q  |  ß  |Bkspc|   XXX  |
   * |---------------------------------------------------------------------------------+       +
   * |Ctrl(Esc)|  U  |  I  |  A  |  E  |  O  |  S  |  N  |  R  |  T  |  D  |  Y  | XXX |       |
   * |-----------------------------------------------------------------------------------------+
   * |LShift| XXX |  Ü  |  Ö  |  Ä  |  P  |  Z  |  B  |  M  |  ,  |  .  |  J  |   XXX    | Pn  |
   * |-----------------------------------------------------------------------------------------+
   * | NeoL1 | Win  | Alt  |  Space     |  XXX  |  RShift(Enter)  | NeoL2 | Win  | Ctrl | Menu |
   * `-----------------------------------------------------------------------------------------'
   */
  [_EMULATOR] = LAYOUT_60_iso_split_2fn(
    XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,
    KC_TAB,   NEO_X,    NEO_V,    NEO_L,    NEO_C,    NEO_W,    NEO_K,    NEO_H,    NEO_G,    NEO_F,    NEO_Q,    NEO_SS,   KC_BSPC,
    MT_LCTL,  NEO_U,    NEO_I,    NEO_A,    NEO_E,    NEO_O,    NEO_S,    NEO_N,    NEO_R,    NEO_T,    NEO_D,    NEO_Y,    XXX,      XXX,
    KC_LSFT,  XXX,      NEO_UE,   NEO_OE,   NEO_AE,   NEO_P,    NEO_Z,    NEO_B,    NEO_M,    NEO_COMM, NEO_DOT,  NEO_J,    XXX,      _BB_PN,
    NEO_L1_L, KC_LGUI,  KC_LALT,  KC_SPC,             XXX,                MT_RSFT,                      NEO_L2_R, KC_RGUI,  KC_RCTL,  KC_APP
  ),

  /* === QWERTZ LAYER === (Hardware emulation of QWERTZ on Software Neo2)
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  ß  |  ´  |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Z  |  U  |  I  |  O  |  P  |  Ü  |  +  |  Enter |
   * |---------------------------------------------------------------------------------+       +
   * |Ctrl(Esc)|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  Ö  |  Ä  |  #  |       |
   * |-----------------------------------------------------------------------------------------+
   * |LShift|  <  |  Y  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  -  |  RShift  | Pn  |
   * |-----------------------------------------------------------------------------------------+
   * |       | Win  | Alt  |  Space     |  Fn   |  RShift(Enter)  | AltGr | Win  | Ctrl | Menu |
   * `-----------------------------------------------------------------------------------------'
   */
  [_QWERTZ] = LAYOUT_60_iso_split_2fn(
    KC_ESC,   NEO_1,    NEO_2,    NEO_3,    NEO_4,    NEO_5,    NEO_6,    NEO_7,    NEO_8,    NEO_9,    NEO_0,    NEO_SS,   NEO_ACUT, KC_BSPC,
    KC_TAB,   NEO_Q,    NEO_W,    NEO_E,    NEO_R,    NEO_T,    NEO_Z,    NEO_U,    NEO_I,    NEO_O,    NEO_P,    NEO_UE,   _QL_PLUS,
    MT_LCTL,  NEO_A,    NEO_S,    NEO_D,    NEO_F,    NEO_G,    NEO_H,    NEO_J,    NEO_K,    NEO_L,    NEO_OE,   NEO_AE,   _QL_HASH, KC_ENT,
    KC_LSFT,  _QL_LESS, NEO_Y,    NEO_X,    NEO_C,    NEO_V,    NEO_B,    NEO_N,    NEO_M,    _QL_COMM, _QL_DOT,  _QL_MINS, KC_RSFT,  _BB_PN,
    XXX,      KC_LGUI,  KC_LALT,  KC_SPC,             MO(_FN),            MT_RSFT,                      XXX,      KC_RGUI,  KC_RCTL,  KC_APP
  ),

  /* === NEO2 LAYER === (Hardware emulation of Neo2 on Software QWERTZ)
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  `  |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  X  |  V  |  L  |  C  |  W  |  K  |  H  |  G  |  F  |  Q  |  ß  |  ´  |  Enter |
   * |---------------------------------------------------------------------------------+       +
   * |Ctrl(Esc)|  U  |  I  |  A  |  E  |  O  |  S  |  N  |  R  |  T  |  D  |  Y  |NeoL1|       |
   * |-----------------------------------------------------------------------------------------+
   * |LShift|NeoL2|  Ü  |  Ö  |  Ä  |  P  |  Z  |  B  |  M  |  ,  |  .  |  J  |  RShift  | Pn  |
   * |-----------------------------------------------------------------------------------------+
   * | NeoL1 | Win  | Alt  |  Space     |  Fn   |  RShift(Enter)  | NeoL2 | Win  | Ctrl | Menu |
   * `-----------------------------------------------------------------------------------------'
   */
  [_NEO2] = LAYOUT_60_iso_split_2fn(
    KC_ESC,   DE_1,     DE_2,     DE_3,     DE_4,     DE_5,     DE_6,     DE_7,     DE_8,     DE_9,     DE_0,     DE_MINS,  DE_GRV,   KC_BSPC,
    KC_TAB,   DE_X,     DE_V,     DE_L,     DE_C,     DE_W,     DE_K,     DE_H,     DE_G,     DE_F,     DE_Q,     DE_SS,    DE_ACUT,
    MT_LCTL,  DE_U,     DE_I,     DE_A,     DE_E,     DE_O,     DE_S,     DE_N,     DE_R,     DE_T,     DE_D,     DE_Y,     _NL_NL1R, KC_ENT,
    KC_LSFT,  _NL_NL2L, DE_UE,    DE_OE,    DE_AE,    DE_P,     DE_Z,     DE_B,     DE_M,     DE_COMM,  DE_DOT,   DE_J,     KC_RSFT,  _BB_PN,
    _NL_NL1L, KC_LGUI,  KC_LALT,  KC_SPC,             MO(_FN),            MT_RSFT,                      _NL_NL2R, KC_RGUI,  KC_RCTL,  KC_APP
  ),

  /* === NEO2 LAYER (LAYER 1) === (Hardware emulation of Neo2 Layer 1 on Software QWERTZ)
   * ,-----------------------------------------------------------------------------------------.
   * | Esc | XXX |  ²  |  ³  | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    | XXX |  _  |  [  |  ]  |  ^  |  !  |  <  |  >  |  =  |  &  | XXX | XXX |  Enter |
   * |---------------------------------------------------------------------------------+       +
   * |Ctrl(Esc)|  \  |  /  |  {  |  }  |  *  |  ?  |  (  |  )  |  -  |  :  |  @  |NeoL1|       |
   * |-----------------------------------------------------------------------------------------+
   * | XXX  | XXX |  #  |  $  |  |  |  ~  |  `  |  +  |  %  |  "  |  '  |  ;  |   XXX    | Pn  |
   * |-----------------------------------------------------------------------------------------+
   * | NeoL1 | Win  | Alt  |  Space     |  Fn   |   XXX           |  XXX  | Win  | Ctrl | Menu |
   * `-----------------------------------------------------------------------------------------'
   */
  [_NEO2_L1] = LAYOUT_60_iso_split_2fn(
    KC_ESC,   XXX,      DE_SQ2,   DE_SQ3,   XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      KC_BSPC,
    KC_TAB,   XXX,      DE_UNDS,  DE_LBRC,  DE_RBRC,  DE_CIRC,  DE_EXLM,  DE_LESS,  DE_MORE,  DE_EQL,   DE_AMPR,  XXX,      XXX,
    MT_LCTL,  DE_BSLS,  DE_SLSH,  DE_LCBR,  DE_RCBR,  DE_ASTR,  DE_QST,   DE_LPRN,  DE_RPRN,  DE_MINS,  DE_COLN,  DE_AT,    ___XX___, KC_ENT,
    XXX,      XXX,      DE_HASH,  DE_DLR,   DE_PIPE,  DE_TILD,  DE_GRV,   DE_PLUS,  DE_PERC,  DE_DQOT,  DE_QUOT,  DE_SCLN,  XXX,      _BB_PN,
    ___XX___, KC_LGUI,  KC_LALT,  KC_SPC,             MO(_FN),            XXX,                          XXX,      KC_RGUI,  KC_RCTL,  KC_APP
  ),

  /* === NEO2 LAYER (LAYER 2) === (Hardware emulation of Neo2 Layer 2 on Software QWERTZ)
   * ,-----------------------------------------------------------------------------------------.
   * | Esc | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |PgUp |Bkspc| Up  | Del |PgDwn| XXX |  7  |  8  |  9  |  +  |  −  | XXX |  Enter |
   * |---------------------------------------------------------------------------------+       +
   * |Ctrl(Esc)|Home |Left |Down |Right| End | XXX |  4  |  5  |  6  |  ,  |  .  | XXX |       |
   * |-----------------------------------------------------------------------------------------+
   * | XXX  |NeoL2| Esc | Tab | XXX |Enter| XXX |  :  |  1  |  2  |  3  |  ;  |   XXX    | Pn  |
   * |-----------------------------------------------------------------------------------------+
   * | XXX   | Win  | Alt  |  0         |  Fn   |   XXX           | NeoL2 | Win  | Ctrl | Menu |
   * `-----------------------------------------------------------------------------------------'
   */
  [_NEO2_L2] = LAYOUT_60_iso_split_2fn(
    KC_ESC,   XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      KC_BSPC,
    KC_TAB,   KC_PGUP,  KC_BSPC,  KC_UP,    KC_DEL,   KC_PGDN,  XXX,      KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_PPLS,  KC_PMNS,  XXX,
    MT_LCTL,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_END,   XXX,      KC_KP_4,  KC_KP_5,  KC_KP_6,  KC_PCMM,  KC_PDOT,  XXX,      KC_ENT,
    XXX,      ___XX___, KC_ESC,   KC_TAB,   XXX,      KC_ENT,   XXX,      DE_COLN,  KC_KP_1,  KC_KP_2,  KC_KP_3,  DE_SCLN,  XXX,      _BB_PN,
    XXX,      KC_LGUI,  KC_LALT,  KC_KP_0,            MO(_FN),            XXX,                          ___XX___, KC_RGUI,  KC_RCTL,  KC_APP
  ),

  /* === FUNCTION LAYER === */
  [_FUNCTION] = LAYOUT_60_iso_split_2fn(
    NEO_CIRC, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,
    ________, ________, ________, ________, ________, ________, ________, KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_VOLU,  KC_MUTE,
    ________, ________, ________, ________, ________, ________, ________, KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_VOLD,  KC_PSCR,  ________,
    ________, ________, KC_MPRV,  KC_MPLY,  KC_MSTP,  KC_MNXT,  ________, ________, ________, ________, ________, ________, ________, XXX,
    ________, ________, ________, ________,           ___XX___,           ________,                     ________, ________, ________, ________
  ),

  /* === PROGRAMMING LAYER === (Programming functions: Layer switching / RGB Lighting) */
  [_PROGRAM] = LAYOUT_60_iso_split_2fn(
    RESET,    DF(_BL),  DF(_QL),  DF(_NL),  DF(_40),  XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      _BB_RST,
    XXX,      _BB_RGB1, _BB_RGB2, _BB_RGB3, _BB_RGB4, XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      BL_INC,   BL_BRTG,
    MG_USCCL, RGB_VAI,  RGB_HUI,  RGB_SAI,  XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      BL_DEC,   BL_TOGG,  XXX,
    ___XX___, RGB_MOD,  RGB_VAD,  RGB_HUD,  RGB_SAD,  XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      ___XX___, ___XX___,
    MG_SCCL,  _BB_LOCK, XXX,      RGB_TOG,            XXX,                XXX,                          XXX,      _BB_LOCK, XXX,      XXX
  )
};


// ==== CUSTOM ACTIONS ====

// Custom down event for compatibility macros
#define _BB_MACRO_MOD_DOWN(default, shifted) \
  if (is_shift) { \
    kc_shift |= (keycode); \
    del_mods(is_shift); \
    SEND_STRING((shifted)); \
    add_mods(is_shift); \
  } else { \
    SEND_STRING((default)); \
  }
// Custom up event for compatibility macros
#define _BB_MACRO_MOD_UP(default, shifted) \
  if (kc_shift & keycode) { \
    kc_shift &= (~keycode); \
    del_mods(is_shift); \
    SEND_STRING((shifted)); \
    add_mods(is_shift); \
  } else { \
    SEND_STRING((default)); \
  }

// User configuration from EEPROM
typedef union {
  uint32_t raw;
  struct {
    bool win_locked :1;
  };
} user_config_t;

typedef struct {
  struct {
    uint32_t config_1;
    uint32_t config_2;
    uint32_t config_3;
    uint32_t config_4;
  } rgb;
} volatile_config_t;

user_config_t user_config;
volatile_config_t volatile_config;

static uint16_t kc_shift = 0;
//static uint8_t kc_modifiers = 0;
static uint16_t tap_timer = 0;


// Suspend: Disable RGB underglow
void suspend_power_down_user(void) {
  rgblight_disable_noeeprom();
}

// Wakeup: Highlight current layer on wakeup
void suspend_wakeup_init_user(void) {
  uint8_t layer = biton32(default_layer_state);
  switch (layer) {
    case _BASE:
      rgb_anim_start(RGB_ANIM_DURATION_WAKEUP, RGB_ANIM_MODE_WAKEUP, RGB_ANIM_HUE_BASE, 255, 255);
      break;
    case _QWERTZ:
      rgb_anim_start(RGB_ANIM_DURATION_WAKEUP, RGB_ANIM_MODE_WAKEUP, RGB_ANIM_HUE_QWERTZ, 255, 255);
      break;
    case _NEO2:
      rgb_anim_start(RGB_ANIM_DURATION_WAKEUP, RGB_ANIM_MODE_WAKEUP, RGB_ANIM_HUE_NEO2, 255, 255);
      break;
    case _EMULATOR:
      rgb_anim_start(RGB_ANIM_DURATION_WAKEUP, RGB_ANIM_MODE_WAKEUP, RGB_ANIM_HUE_EMULATOR, 255, 255);
      break;
  }
}

// Startup: Init keyboard state
void matrix_init_user(void) {
  kc_shift = 0;
  //kc_modifiers = 0;

  // Read user config from EEPROM
  user_config.raw = eeconfig_read_user();

  // Clear volatile config in RAM
  volatile_config.rgb.config_1 = 0;
  volatile_config.rgb.config_2 = 0;
  volatile_config.rgb.config_3 = 0;
  volatile_config.rgb.config_4 = 0;
}

void matrix_scan_user(void) {
  rgb_anim_update();
}

// Handle keypress/release events
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t is_shift = keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));

  switch (keycode) {
    // ==== Animate Layer switching ====
    case DF(_BASE): // Layer switch animation => Software Neo2
      if (record->event.pressed) {
        rgb_anim_start(RGB_ANIM_DURATION_LAYER, RGB_ANIM_MODE_LAYER, RGB_ANIM_HUE_BASE, 255, 255);
      }
      return true;
    case DF(_QWERTZ): // Layer switch animation => QWERTZ emulation
      if (record->event.pressed) {
        rgb_anim_start(RGB_ANIM_DURATION_LAYER, RGB_ANIM_MODE_LAYER, RGB_ANIM_HUE_QWERTZ, 255, 255);
      }
      return true;
    case DF(_NEO2): // Layer switch animation => Neo2 emulation
      if (record->event.pressed) {
        rgb_anim_start(RGB_ANIM_DURATION_LAYER, RGB_ANIM_MODE_LAYER, RGB_ANIM_HUE_NEO2, 255, 255);
      }
      return true;
    case DF(_EMULATOR): // Layer switch animation => 40% emulation
      if (record->event.pressed) {
        rgb_anim_start(RGB_ANIM_DURATION_LAYER, RGB_ANIM_MODE_LAYER, RGB_ANIM_HUE_EMULATOR, 255, 255);
      }
      return true;

    // ==== Handle Win-Locked keys ====
    case KC_LGUI:
      return !user_config.win_locked;
    case MT_LCTL:
      if (user_config.win_locked) {
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTRL));
        } else {
          SEND_STRING(SS_UP(X_LCTRL));
        }
        return false;
      }
      return true;
    case MT_RSFT:
      if (user_config.win_locked) {
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_RSHIFT));
        } else {
          SEND_STRING(SS_UP(X_RSHIFT));
        }
        return false;
      }
      return true;

    // ==== Custom function keys ====
    case BB_FN_PROGRAM: // Indicate current layer on PROGRAM tap
      if (record->event.pressed) {
        tap_timer = timer_read();
        layer_on(_PROGRAM);
      } else {
        layer_off(_PROGRAM);
        if (timer_elapsed(tap_timer) < TAPPING_TERM) {
          switch (biton32(default_layer_state)) {
            case _BASE:
              rgb_anim_start(RGB_ANIM_DURATION_LAYER, RGB_ANIM_MODE_LAYER, RGB_ANIM_HUE_BASE, 255, 255);
              break;
            case _QWERTZ:
              rgb_anim_start(RGB_ANIM_DURATION_LAYER, RGB_ANIM_MODE_LAYER, RGB_ANIM_HUE_QWERTZ, 255, 255);
              break;
            case _NEO2:
              rgb_anim_start(RGB_ANIM_DURATION_LAYER, RGB_ANIM_MODE_LAYER, RGB_ANIM_HUE_NEO2, 255, 255);
              break;
            case _EMULATOR:
              rgb_anim_start(RGB_ANIM_DURATION_LAYER, RGB_ANIM_MODE_LAYER, RGB_ANIM_HUE_EMULATOR, 255, 255);
              break;
          }
        }
      }
      return false;
    case BB_FN_LOCK_WIN: // Lock WIN key and tap-action keys
      if (record->event.pressed) {
        user_config.win_locked = !user_config.win_locked;
        eeconfig_update_user(user_config.raw); // Update EEPROM config
        if (user_config.win_locked) {
          rgb_anim_start(RGB_ANIM_DURATION_WINLOCK, RGB_ANIM_MODE_WINLOCK, RGB_ANIM_HUE_WIN_LOCKED, 255, 255);
        } else {
          rgb_anim_start(RGB_ANIM_DURATION_WINLOCK, RGB_ANIM_MODE_WINLOCK, RGB_ANIM_HUE_WIN_UNLOCKED, 255, 255);
        }
      }
      return false;
    case BB_FN_RGB_CONFIG_1: // Load / Save RGB configuratio from RAM
      if (record->event.pressed) {
        if (is_shift) { // Save to RAM
          volatile_config.rgb.config_1 = eeconfig_read_rgblight();
        } else { // Load from RAM
          rgblight_update_dword(volatile_config.rgb.config_1);
        }
      }
      return false;
    case BB_FN_RGB_CONFIG_2: // Load / Save RGB configuratio from RAM
      if (record->event.pressed) {
        if (is_shift) { // Save to RAM
          volatile_config.rgb.config_2 = eeconfig_read_rgblight();
        } else { // Load from RAM
          rgblight_update_dword(volatile_config.rgb.config_2);
        }
      }
      return false;
    case BB_FN_RGB_CONFIG_3: // Load / Save RGB configuratio from RAM
      if (record->event.pressed) {
        if (is_shift) { // Save to RAM
          volatile_config.rgb.config_3 = eeconfig_read_rgblight();
        } else { // Load from RAM
          rgblight_update_dword(volatile_config.rgb.config_3);
        }
      }
      return false;
    case BB_FN_RGB_CONFIG_4: // Load / Save RGB configuratio from RAM
      if (record->event.pressed) {
        if (is_shift) { // Save to RAM
          volatile_config.rgb.config_4 = eeconfig_read_rgblight();
        } else { // Load from RAM
          rgblight_update_dword(volatile_config.rgb.config_4);
        }
      }
      return false;
    case BB_FN_RESET_EEPROM: // Reset user configuration in EEPROM
      if (record->event.pressed) {
        eeconfig_init();
        user_config.raw = eeconfig_read_user();
      }
      return false;

    // ==== Neo2 emulation compatibility macros ====
    case BB_MACRO_QWERTZ_HASH: // Compat macro: QWERTZ <#> on Neo2 emulation
      if (record->event.pressed) {
        _BB_MACRO_MOD_DOWN(SS_DOWN(X_CAPSLOCK) SS_DOWN(X_Z),  // <#> == [ <NEO_L1> + <NEO_UE> ]
                           SS_DOWN(X_CAPSLOCK) SS_DOWN(X_DOT))  // <'> == [ <NEO_L1> + <NEO_DOT> ]
      } else {
        _BB_MACRO_MOD_UP(SS_UP(X_Z) SS_UP(X_CAPSLOCK),
                         SS_UP(X_DOT) SS_UP(X_CAPSLOCK))
      }
      return false;
    case BB_MACRO_QWERTZ_PLUS: // Compat macro: QWERTZ <+> on Neo2 emulation
      if (record->event.pressed) {
        _BB_MACRO_MOD_DOWN(SS_DOWN(X_CAPSLOCK) SS_DOWN(X_N),  // <+> == [ <NEO_L1> + <NEO_B> ]
                           SS_DOWN(X_CAPSLOCK) SS_DOWN(X_G))  // <*> == [ <NEO_L1> + <NEO_L> ]
      } else {
        _BB_MACRO_MOD_UP(SS_UP(X_N) SS_UP(X_CAPSLOCK),
                         SS_UP(X_G) SS_UP(X_CAPSLOCK))
      }
      return false;
    case BB_MACRO_QWERTZ_COMM: // Compat macro: QWERTZ <,> on Neo2 emulation
      if (record->event.pressed) {
        _BB_MACRO_MOD_DOWN(SS_DOWN(X_COMMA),  // <,> == [ <NEO_COMM> ]
                           SS_DOWN(X_CAPSLOCK) SS_DOWN(X_SLASH))  // <;> == [ <NEO_L1> + <NEO_MINS> ]
      } else {
        _BB_MACRO_MOD_UP(SS_UP(X_COMMA),
                         SS_UP(X_SLASH) SS_UP(X_CAPSLOCK))
      }
      return false;
    case BB_MACRO_QWERTZ_DOT: // Compat macro: QWERTZ <.> on Neo2 emulation
      if (record->event.pressed) {
        _BB_MACRO_MOD_DOWN(SS_DOWN(X_DOT),  // <.> == [ <NEO_DOT> ]
                           SS_DOWN(X_CAPSLOCK) SS_DOWN(X_SCOLON))  // <:> == [ <NEO_L1> + <NEO_D> ]
      } else {
        _BB_MACRO_MOD_UP(SS_UP(X_DOT),
                         SS_UP(X_SCOLON) SS_UP(X_CAPSLOCK))
      }
      return false;
    case BB_MACRO_QWERTZ_MINS: // Compat macro: QWERTZ <-> on Neo2 emulation
      if (record->event.pressed) {
        _BB_MACRO_MOD_DOWN(SS_DOWN(X_MINUS),  // <-> == [ <NEO_MINS> ]
                           SS_DOWN(X_CAPSLOCK) SS_DOWN(X_W))  // <_> == [ <NEO_L1> + <NEO_V> ]
      } else {
        _BB_MACRO_MOD_UP(SS_UP(X_MINUS),
                         SS_UP(X_W) SS_UP(X_CAPSLOCK))
      }
      return false;
    case BB_MACRO_QWERTZ_LESS: // Compat macro: QWERTZ <<> on Neo2 emulation
      if (record->event.pressed) {
        _BB_MACRO_MOD_DOWN(SS_DOWN(X_CAPSLOCK) SS_DOWN(X_U),  // <<> == [ <NEO_L1> + <NEO_H> ]
                           SS_DOWN(X_CAPSLOCK) SS_DOWN(X_I))  // <>> == [ <NEO_L1> + <NEO_G> ]
      } else {
        _BB_MACRO_MOD_UP(SS_UP(X_U) SS_UP(X_CAPSLOCK),
                         SS_UP(X_I) SS_UP(X_CAPSLOCK))
      }
      return false;

    default:
      return true;
  }
}

// vim: set ts=2 sw=2 sts=4 et:

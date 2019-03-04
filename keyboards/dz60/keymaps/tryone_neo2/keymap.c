#include QMK_KEYBOARD_H

#include "keymap_german.h"
#include "keymap_neo2.h"

#include "rgb_anim.h"


// ==== LAYERS ====
enum layers_idx {
  _BASE = 0,      // Base Layer (Software Neo2)
  _QWERTZ,        // QWERTY Hardware emulation on Neo2 Software
  _NEO2,          // Neo2 Hardware emulation on QWERTZ Software
  _NEO2_L1,       // Neo2 (Layer 1) Hardware emulation on QWERTZ Software
  _FUNCTION,      // Function Layer
  _PROGRAM,       // Programming functions (Layer / RGB Lighting)
};

#define _BL _BASE
#define _QL _QWERTZ
#define _NL _NEO2
#define _NL1 _NEO2_L1
#define _FN _FUNCTION
#define _PN _PROGRAM

// ==== KEYCODES ====
enum macro_keycodes {
  BB_MACRO_QWERTZ_1 = SAFE_RANGE,
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

#define _QL_HASH BB_MACRO_QWERTZ_HASH
#define _QL_PLUS BB_MACRO_QWERTZ_PLUS
#define _QL_COMM BB_MACRO_QWERTZ_COMM
#define _QL_DOT  BB_MACRO_QWERTZ_DOT
#define _QL_MINS BB_MACRO_QWERTZ_MINS
#define _QL_LESS BB_MACRO_QWERTZ_LESS

#define _NL_NL1L MO(_NEO2_L1)
#define _NL_NL1R MO(_NEO2_L1)

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
    KC_ESC,   NEO_1,    NEO_2,    NEO_3,    NEO_4,    NEO_5,    NEO_6,    NEO_7,    NEO_8,    NEO_9,    NEO_0,    NEO_SS,   NEO_ACUT, KC_BSPC,
    KC_TAB,   NEO_Q,    NEO_W,    NEO_E,    NEO_R,    NEO_T,    NEO_Z,    NEO_U,    NEO_I,    NEO_O,    NEO_P,    NEO_UE,   _QL_PLUS,
    KC_LCTL,  NEO_A,    NEO_S,    NEO_D,    NEO_F,    NEO_G,    NEO_H,    NEO_J,    NEO_K,    NEO_L,    NEO_OE,   NEO_AE,   _QL_HASH, KC_ENT,
    KC_LSFT,  _QL_LESS, NEO_Y,    NEO_X,    NEO_C,    NEO_V,    NEO_B,    NEO_N,    NEO_M,    _QL_COMM, _QL_DOT,  _QL_MINS, KC_RSFT,  MO(_PN),
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
    KC_LCTL,  DE_U,     DE_I,     DE_A,     DE_E,     DE_O,     DE_S,     DE_N,     DE_R,     DE_T,     DE_D,     DE_Y,     _NL_NL1R, KC_ENT,
    KC_LSFT,  XXX,      DE_UE,    DE_OE,    DE_AE,    DE_P,     DE_Z,     DE_B,     DE_M,     DE_COMM,  DE_DOT,   DE_J,     KC_RSFT,  MO(_PN),
    _NL_NL1L, KC_LGUI,  KC_LALT,  KC_SPC,             MO(_FN),            KC_RSFT,                      XXX,      KC_RGUI,  KC_RCTL,  KC_APP
  ),

  /* === NEO2 LAYER (LAYER 1) === (Hardware emulation of Neo2 Layer 1 on Software QWERTZ)
   * ,-----------------------------------------------------------------------------------------.
   * | Esc | XXX |  ²  |  ³  | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    | XXX |  _  |  [  |  ]  |  ^  |  !  |  <  |  >  |  =  |  &  | XXX | XXX |  Enter |
   * |---------------------------------------------------------------------------------+       +
   * |  Ctrl   |  \  |  /  |  {  |  }  |  *  |  ?  |  (  |  )  |  -  |  :  |  @  |NeoL1|       |
   * |-----------------------------------------------------------------------------------------+
   * | XXX  | XXX |  #  |  $  |  |  |  ~  |  `  |  +  |  %  |  "  |  '  |  ;  |   XXX    | Pn  |
   * |-----------------------------------------------------------------------------------------+
   * | NeoL1 | Win  | Alt  |  Space     |  Fn   |   XXX           |  XXX  | Win  | Ctrl | Menu |
   * `-----------------------------------------------------------------------------------------'
   */
  [_NEO2_L1] = LAYOUT_60_iso_split_2fn(
    KC_ESC,   XXX,      DE_SQ2,   DE_SQ3,   XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      KC_BSPC,
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
    XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      BL_INC,   BL_BRTG,
    MG_USCCL, RGB_VAI,  RGB_HUI,  RGB_SAI,  XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      BL_DEC,   BL_TOGG,  XXX,
    ___XX___, RGB_MOD,  RGB_VAD,  RGB_HUD,  RGB_SAD,  XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      ___XX___, ___XX___,
    MG_SCCL,  XXX,      XXX,      RGB_TOG,            XXX,                XXX,                          XXX,      XXX,      XXX,      XXX
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

// Disable RGB underglow
void suspend_power_down_user(void) {
  rgblight_disable_noeeprom();
}

// Highlight current layer on wakeup
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
    default:
      rgb_anim_start(RGB_ANIM_DURATION_WAKEUP, RGB_ANIM_MODE_WAKEUP, 270, 255, 255);
  }
}


static uint16_t kc_shift = 0;
static uint8_t kc_modifiers = 0;

void matrix_init_user(void) {
  kc_shift = 0;
  kc_modifiers = 0;
}

void matrix_scan_user(void) {
  rgb_anim_update();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t is_shift = keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));

  switch (keycode) {
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

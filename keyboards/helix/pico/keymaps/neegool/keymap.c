#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#ifdef OLED_DRIVER_ENABLE
  #include "oled_driver.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _COLEMAK,
    _DVORAK,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMPAD
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
  NUMPAD,
  BACKLIT,
  EISU,
  KANA,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

//Macros
#define M_SAMPLE M(KC_SAMPLEMACRO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * | Ctrl |Adjust| Esc  | Alt  | GUI  |Lower |Space |Space |Raise | GUI  | Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */

[_QWERTY] = LAYOUT( \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
      KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
      KC_LCTL, ADJUST,  NUMPAD,  KC_LALT, KC_LGUI, LOWER,   KC_SPC, KC_SPC,   RAISE,   KC_LGUI, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),
  /* Colemak
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   F  |   P  |   G  |             |   J  |   L  |   U  |   Y  |   ;  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   R  |   S  |   T  |   D  |             |   H  |   N  |   E  |   I  |   O  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   K  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |Adjust| Esc  | Alt  | GUI  | EISU |Lower |Space |Space |Raise | KANA | Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_COLEMAK] = LAYOUT( \
      KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
      KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
      KC_LCTL, ADJUST,  KC_ESC,  KC_LALT, KC_LGUI, LOWER,   KC_SPC, KC_SPC,   RAISE,   KC_LGUI, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),

  /* Dvorak
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   '  |   ,  |   .  |   P  |   Y  |             |   F  |   G  |   C  |   R  |   L  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   O  |   E  |   U  |   I  |             |   D  |   H  |   T  |   N  |   S  |  /   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   ;  |   Q  |   J  |   K  |   X  |             |   B  |   M  |   W  |   V  |   Z  |Enter |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |Adjust| Esc  | Alt  | GUI  | EISU |Lower |Space |Space |Raise | KANA | Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_DVORAK] = LAYOUT( \
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
      KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
      KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
      KC_LCTL, ADJUST,  KC_ESC,  KC_LALT, KC_LGUI, LOWER,   KC_SPC, KC_SPC,   RAISE,   KC_LGUI, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),

  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   _  |   +  |   {  |   }  |  |   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |             |  F12 |      | PrSc | Home | End  |      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT( \
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
      KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                    KC_F12,  _______, KC_PSCR, KC_HOME, KC_END,  _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   -  |   =  |   [  |   ]  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |             |  F12 |      | PrSc |PageDn|PageUp|      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT( \
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                    KC_F12,  _______, KC_PSCR, KC_PGDN, KC_PGUP, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, KC_BRID, KC_BRIU, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
      ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      | Reset|      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |Aud on|Audoff|MU TOG|MU MOD| Mac  |             | Win  |Qwerty|Colemk|Dvorak|      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |CK TOG|CK RST| CK UP|CK DWN|      |             |      |      |RGB ON| HUE+ | SAT+ | VAL+ |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | MODE | HUE- | SAT- | VAL- |
   * `-------------------------------------------------------------------------------------------------'
   */
  // [_ADJUST] =  LAYOUT( 
  //     _______, RESET,   _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, 
  //     _______, AU_ON,   AU_OFF,  MU_TOG,  MU_MOD,  AG_NORM,                   AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______, 
  //     _______, CK_TOGG, CK_RST,  CK_UP,   CK_DOWN, _______,                   _______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, 
  //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD 
  //     )
  [_ADJUST] =  LAYOUT( \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______,                   RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD \
      ),
  [_NUMPAD] = LAYOUT( \
      _______, _______, _______, _______, _______, _______,                   KC_KP_7, KC_KP_8, KC_KP_9, KC_NLCK, KC_PEQL, _______, \
      _______, _______, _______, _______, _______, _______,                   KC_KP_4, KC_KP_5, KC_KP_6, KC_PAST, KC_PMNS, KC_PPLS, \
      _______, _______, _______, KC_CALC, _______, _______,                   KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT, KC_PSLS, KC_PENT, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_0, _______, _______, _______, _______ \
    )
};

#ifdef AUDIO_ENABLE

float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
#endif

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    #ifdef RGBLIGHT_ENABLE
      //rgblight_mode(RGB_current_mode);
    #endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
          //not sure how to have keyboard check mode and set it to a variable, so my work around
          //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
            //rgblight_mode(RGBLIGHT_MODE_SNAKE + 1);
          #endif
        }
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGB_current_mode);   // revert RGB to initial mode prior to RGB mode change
        #endif
        TOG_STATUS = false;
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        //not sure how to have keyboard check mode and set it to a variable, so my work around
        //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
            //rgblight_mode(RGBLIGHT_MODE_SNAKE);
          #endif
        }
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGB_current_mode);  // revert RGB to initial mode prior to RGB mode change
        #endif
        layer_off(_RAISE);
        TOG_STATUS = false;
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
    case NUMPAD:
        if (record->event.pressed) {
            layer_on(_NUMPAD);
        } else {
            layer_off(_NUMPAD);
        }
        return false;
        break;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
      break;
    case EISU:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LANG2);
        }else{
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG2);
      }
      return false;
      break;
    case KANA:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LANG1);
        }else{
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG1);
      }
      return false;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
      rgblight_enable_noeeprom();
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        // iota_gfx_init(!has_usb());   // turns on the display
        // oled_init(has_usb()? OLED_ROTATION_0 : OLED_ROTATION_180);
    #endif
}


#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(50); // gets rid of tick
}

void shutdown_user()
{
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}

#endif


//OLED update loop, make sure to add #define OLED_DRIVER_ENABLE in config.h
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!has_usb()) return OLED_ROTATION_180;  // flip 180 for offhand
    return OLED_ROTATION_270;
}

//assign the right code to your layers for OLED display
#define L_BASE 0
#define L_LOWER (1<<_LOWER)
#define L_RAISE (1<<_RAISE)
#define L_ADJUST (1<<_ADJUST)
#define L_NUMPAD (1<<_NUMPAD)
#define L_ADJUST_TRI (L_ADJUST|L_RAISE|L_LOWER)

static void render_logo(void) {
    // static const char PROGMEM qmk_logo[] = {
    //     0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    //     0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    //     0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
    static const char PROGMEM qmk_logo[] = {
        0x9f,0x9f,0x9f,0x80,0x81,0x82,0x83,0x9f,0x84,0x85,0x9f,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x9f,0x9f,0x9f,
        0x9f,0x9f,0x9f,0xa0,0xa1,0x9f,0xa3,0x9f,0xa4,0xa5,0x9f,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0x9f,0x9f,0x9f,
        0x9f,0x9f,0x9f,0xc0,0xc1,0xc2,0xc3,0x9f,0xc4,0xc5,0x9f,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0x9f,0x9f,0x9f,0};

    oled_write_P(qmk_logo, false);
}

static void render_status(void) {
  // Render to mode icon
//   static char logo[][2][3]={{{0x95,0x96,0},{0xb5,0xb6,0}},{{0x97,0x98,0},{0xb7,0xb8,0}}};
//   if(keymap_config.swap_lalt_lgui==false){
//         oled_write(logo[0][0], false);
//         oled_write_P(PSTR("\n"), false);
//         oled_write(logo[0][1], false);
//   }else{
//         oled_write(logo[1][0], false);
//         oled_write_P(PSTR("\n"), false);
//         oled_write(logo[1][1], false);
//   }

  static char stats[][2][4] = {
      {{0x9f, 0x9f, 0x9f, 0}, {0x9f, 0x9f, 0x9f, 0}},  // Blank
      {{0x8d, 0x90, 0x8f, 0}, {0xad, 0xb0, 0xaf, 0}},  // NUM
      {{0x8d, 0x91, 0x8f, 0}, {0xad, 0xb1, 0xaf, 0}},  // CAPS
      {{0x8d, 0x92, 0x8f, 0}, {0xad, 0xb2, 0xaf, 0}},  // SCRL
      {{0x8d, 0x93, 0x8f, 0}, {0xad, 0xb3, 0xaf, 0}},  // RAISE
      {{0x8d, 0x94, 0x8f, 0}, {0xad, 0xb4, 0xaf, 0}},  // LOWER
      {{0x8d, 0x95, 0x8f, 0}, {0xad, 0xb5, 0xaf, 0}},  // ADJUST
  };

  static char line[] = {0xcd, 0xcd, 0xcd, 0};

  oled_write_P(PSTR("\n\n  "), false);
  oled_write((host_keyboard_leds() & (1 << USB_LED_NUM_LOCK)) ? stats[1][0] : stats[0][0], false);
  oled_write_P(PSTR("  "), false);
  oled_write((host_keyboard_leds() & (1 << USB_LED_NUM_LOCK)) ? stats[1][1] : stats[0][1], false);
  oled_write_P(PSTR("  "), false);
  oled_write((host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) ? stats[2][0] : stats[0][0], false);
  oled_write_P(PSTR("  "), false);
  oled_write((host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) ? stats[2][1] : stats[0][1], false);
  oled_write_P(PSTR("  "), false);
  oled_write((host_keyboard_leds() & (1 << USB_LED_SCROLL_LOCK)) ? stats[3][0] : stats[0][0], false);
  oled_write_P(PSTR("  "), false);
  oled_write((host_keyboard_leds() & (1 << USB_LED_SCROLL_LOCK)) ? stats[3][1] : stats[0][1], false);

  oled_write_P(PSTR("\n  "), false);
  oled_write(line, false);
  oled_write_P(PSTR("\n  "), false);

  switch (layer_state) {
      case L_BASE:
          oled_write(stats[0][0], false);
          oled_write_P(PSTR("  "), false);
          oled_write(stats[0][1], false);
          break;
      case L_RAISE:
          oled_write(stats[4][0], false);
          oled_write_P(PSTR("  "), false);
          oled_write(stats[4][1], false);
          break;
      case L_LOWER:
          oled_write(stats[5][0], false);
          oled_write_P(PSTR("  "), false);
          oled_write(stats[5][1], false);
          break;
      case L_ADJUST:
      case L_ADJUST_TRI:
          oled_write(stats[6][0], false);
          oled_write_P(PSTR("  "), false);
          oled_write(stats[6][1], false);
          break;
      case L_NUMPAD:
          oled_write(stats[1][0], false);
          oled_write_P(PSTR("  "), false);
          oled_write(stats[1][1], false);
          break;
      default:
          oled_write_P(PSTR("\n\n  "), false);
  }
}


void oled_task_user(void) {
    #if DEBUG_TO_SCREEN
    if (debug_enable) {
        return;
    }
    #endif
    if(is_master){
        render_status();
    }else{
        render_logo();
    }
}

#endif

// Copyright 2023 Danny Nguyen (danny@keeb.io)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define caps_lock_led 11

enum custom_keycodes {
  MACRO1 = SAFE_RANGE,
  MACRO2,
  MACRO3
};

enum custom_layers {
  _BASE,
  _FN1,
  _FN2
};

static bool caps_active = false;
static uint8_t saved_mode;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_4x4(
    KC_P7,    KC_P8,    KC_P9,   KC_NUM,
    KC_P4,    KC_P5,    KC_P6,   KC_RGHT,
    KC_P1,    KC_P2,    KC_P3,   KC_CAPS,
    MO(_FN2), KC_P0,    KC_DOT,  KC_PENT
  ),
  [_FN1] = LAYOUT_ortho_4x4(
    KC_ESC,   KC_P7,    KC_P8,    KC_P9,
    KC_TAB,   KC_P4,    KC_P5,    KC_P6,
    KC_ENT,   KC_P1,    KC_P2,    KC_P3,
    _______,  KC_P0,    KC_P0,    KC_DOT
  ),
  [_FN2] = LAYOUT_ortho_4x4(
    RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,
    RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,
    _______,  _______,  _______,  QK_BOOT,
    BL_STEP,  _______,  _______,  _______
  )

};

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {11, 1, HSV_RED}
);

bool led_update_user(led_t led_state) {
  rgblight_set_layer_state(0, led_state.caps_lock);
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case MACRO1:
      if (record->event.pressed) {
        SEND_STRING("Hello, world!");
      } else {
        // Nothing on the upstroke
      }
      return false;
    case MACRO2:
      if (record->event.pressed) {
        SEND_STRING("Hello, world!");
      } else {
        // Nothing on the upstroke
      }
      return false;
    case MACRO3:
      if (record->event.pressed) {
        SEND_STRING("Hello, world!");
      } else {
        // Nothing on the upstroke
      }
      return false;
    default:
      return true;
  }
  return true;
}

// Copyright 2023 Danny Nguyen (danny@keeb.io)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
  MACRO1 = SAFE_RANGE,
  MACRO2,
  MACRO3
};

enum custom_layers {
  _BASE,
  _FN1,
  _FN2,
  _FN3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_4x4(
    KC_P7,    KC_P8,    KC_P9,   KC_NUM,
    KC_P4,    KC_P5,    KC_P6,   MACRO1,
    KC_P1,    KC_P2,    KC_P3,   KC_CAPS,
    MO(_FN3), KC_P0,    KC_DOT,  KC_PENT
  ),
  [_FN1] = LAYOUT_ortho_4x4(
    KC_HOME,   KC_UP,    KC_PGUP,    MACRO1,
    KC_LEFT,   KC_DOWN,  KC_RGHT,    MACRO2,
    KC_END,    KC_P1,    KC_PGDN,    MACRO3,
    MO(_FN3),  KC_LSFT,  C(KC_C),    C(KC_V)
  ),
  [_FN2] = LAYOUT_ortho_4x4(
    KC_HOME,   KC_UP,    KC_PGUP,       MACRO1,
    KC_LEFT,   KC_DOWN,  KC_RGHT,       MACRO2,
    KC_END,    KC_P1,    KC_PGDN,       MACRO3,
    MO(_FN3),  KC_LSFT,  LGUI(KC_C),    LGUI(KC_V)
  ),
  [_FN3] = LAYOUT_ortho_4x4(
    RGB_TOG,  RGB_HUI,    RGB_SAI,    RGB_VAI,
    RGB_MOD,  RGB_HUD,    RGB_SAD,    RGB_VAD,
    _______,  _______,    _______,    QK_BOOT,
    _______,  DF(_BASE),  DF(_FN1),   DF(_FN2)
  )

};

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

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Number 5 is the num lock LED
    if (host_keyboard_led_state().num_lock) {
        if (g_led_config.flags[5] & LED_FLAG_KEYLIGHT) {
            rgb_matrix_set_color(5, RGB_RED);
        }
    }

    // Number 10 is the num lock LED
    if (host_keyboard_led_state().caps_lock) {
        if (g_led_config.flags[13] & LED_FLAG_KEYLIGHT) {
            rgb_matrix_set_color(13, RGB_RED);
        }
    }

    return false;
}
// Copyright 2023 Danny Nguyen (danny@keeb.io)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define USB_VBUS_PIN GP0
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP12
#define SERIAL_USART_RX_PIN GP13
#define SERIAL_USART_PIN_SWAP
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U
#define I2C_DRIVER I2CD2
#define I2C1_SDA_PIN GP10
#define I2C1_SCL_PIN GP11

// Redefine trilayer enums to let builtin function know where layers are on custom keymap
#define TRI_LAYER_LOWER_LAYER 6
#define TRI_LAYER_UPPER_LAYER 7
#define TRI_LAYER_ADJUST_LAYER 8


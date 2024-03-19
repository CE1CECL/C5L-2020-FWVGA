/*
 * Copyright (C) 2017 Spreadtrum Communications Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "sprd_panel.h"
#include "sprd_dsi.h"
#include "dsi/mipi_dsi_api.h"
#include "sprd_dphy.h"

static uint8_t init_data[] = {
	0x23, 0x00, 0x00, 0x02, 0xFF, 0xEE, // to avoid black screen if sleep-in cmd send failed
	0x23, 0x0A, 0x00, 0x02, 0x18, 0x40, // OSC ON 10ms
	0x23, 0x14, 0x00, 0x02, 0x18, 0x00, // OSC OFF 20ms
	0x23, 0x00, 0x00, 0x02, 0xFF, 0x01,
	0x23, 0x00, 0x00, 0x02, 0xFB, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x00, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x01, 0x55,
	0x23, 0x00, 0x00, 0x02, 0x02, 0x40,
	0x23, 0x00, 0x00, 0x02, 0x05, 0x40,
	0x23, 0x00, 0x00, 0x02, 0x06, 0x94,
	0x23, 0x00, 0x00, 0x02, 0x07, 0x94,
	0x23, 0x00, 0x00, 0x02, 0x08, 0x0C,
	0x23, 0x00, 0x00, 0x02, 0x11, 0x19,
	0x23, 0x00, 0x00, 0x02, 0x12, 0x19,
	0x23, 0x00, 0x00, 0x02, 0x13, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x14, 0x94,
	0x23, 0x00, 0x00, 0x02, 0x15, 0x15,
	0x23, 0x00, 0x00, 0x02, 0x16, 0x15,
	0x23, 0x00, 0x00, 0x02, 0x6D, 0x22,
	0x23, 0x00, 0x00, 0x02, 0x0B, 0xAF,
	0x23, 0x00, 0x00, 0x02, 0x0C, 0xAF,
	0x23, 0x00, 0x00, 0x02, 0x0E, 0xAB,
	0x23, 0x00, 0x00, 0x02, 0x0F, 0xA4,
	0x23, 0x00, 0x00, 0x02, 0x58, 0x82,
	0x23, 0x00, 0x00, 0x02, 0x59, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x5A, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x5B, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x5C, 0x82,
	0x23, 0x00, 0x00, 0x02, 0x5D, 0x82,
	0x23, 0x00, 0x00, 0x02, 0x5E, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x5F, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x75, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x76, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x77, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x78, 0x11,
	0x23, 0x00, 0x00, 0x02, 0x79, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x7A, 0x30,
	0x23, 0x00, 0x00, 0x02, 0x7B, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x7C, 0x4A,
	0x23, 0x00, 0x00, 0x02, 0x7D, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x7E, 0x62,
	0x23, 0x00, 0x00, 0x02, 0x7F, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x80, 0x78,
	0x23, 0x00, 0x00, 0x02, 0x81, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x82, 0x8C,
	0x23, 0x00, 0x00, 0x02, 0x83, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x84, 0x9E,
	0x23, 0x00, 0x00, 0x02, 0x85, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x86, 0xAE,
	0x23, 0x00, 0x00, 0x02, 0x87, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x88, 0xE4,
	0x23, 0x00, 0x00, 0x02, 0x89, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x8A, 0x0E,
	0x23, 0x00, 0x00, 0x02, 0x8B, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x8C, 0x4C,
	0x23, 0x00, 0x00, 0x02, 0x8D, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x8E, 0x7B,
	0x23, 0x00, 0x00, 0x02, 0x8F, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x90, 0xC2,
	0x23, 0x00, 0x00, 0x02, 0x91, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x92, 0xFB,
	0x23, 0x00, 0x00, 0x02, 0x93, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x94, 0xFC,
	0x23, 0x00, 0x00, 0x02, 0x95, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x96, 0x34,
	0x23, 0x00, 0x00, 0x02, 0x97, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x98, 0x79,
	0x23, 0x00, 0x00, 0x02, 0x99, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x9A, 0xA4,
	0x23, 0x00, 0x00, 0x02, 0x9B, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x9C, 0xDD,
	0x23, 0x00, 0x00, 0x02, 0x9D, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x9E, 0x05,
	0x23, 0x00, 0x00, 0x02, 0x9F, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xA0, 0x39,
	0x23, 0x00, 0x00, 0x02, 0xA2, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xA3, 0x48,
	0x23, 0x00, 0x00, 0x02, 0xA4, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xA5, 0x58,
	0x23, 0x00, 0x00, 0x02, 0xA6, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xA7, 0x6A,
	0x23, 0x00, 0x00, 0x02, 0xA9, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xAA, 0x7F,
	0x23, 0x00, 0x00, 0x02, 0xAB, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xAC, 0x98,
	0x23, 0x00, 0x00, 0x02, 0xAD, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xAE, 0xB7,
	0x23, 0x00, 0x00, 0x02, 0xAF, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xB0, 0xD7,
	0x23, 0x00, 0x00, 0x02, 0xB1, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xB2, 0xFF,
	0x23, 0x00, 0x00, 0x02, 0xB3, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xB4, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xB5, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xB6, 0x11,
	0x23, 0x00, 0x00, 0x02, 0xB7, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xB8, 0x30,
	0x23, 0x00, 0x00, 0x02, 0xB9, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xBA, 0x4A,
	0x23, 0x00, 0x00, 0x02, 0xBB, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xBC, 0x62,
	0x23, 0x00, 0x00, 0x02, 0xBD, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xBE, 0x78,
	0x23, 0x00, 0x00, 0x02, 0xBF, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xC0, 0x8C,
	0x23, 0x00, 0x00, 0x02, 0xC1, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xC2, 0x9E,
	0x23, 0x00, 0x00, 0x02, 0xC3, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xC4, 0xAE,
	0x23, 0x00, 0x00, 0x02, 0xC5, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xC6, 0xE4,
	0x23, 0x00, 0x00, 0x02, 0xC7, 0x01,
	0x23, 0x00, 0x00, 0x02, 0xC8, 0x0E,
	0x23, 0x00, 0x00, 0x02, 0xC9, 0x01,
	0x23, 0x00, 0x00, 0x02, 0xCA, 0x4C,
	0x23, 0x00, 0x00, 0x02, 0xCB, 0x01,
	0x23, 0x00, 0x00, 0x02, 0xCC, 0x7B,
	0x23, 0x00, 0x00, 0x02, 0xCD, 0x01,
	0x23, 0x00, 0x00, 0x02, 0xCE, 0xC2,
	0x23, 0x00, 0x00, 0x02, 0xCF, 0x01,
	0x23, 0x00, 0x00, 0x02, 0xD0, 0xFB,
	0x23, 0x00, 0x00, 0x02, 0xD1, 0x01,
	0x23, 0x00, 0x00, 0x02, 0xD2, 0xFC,
	0x23, 0x00, 0x00, 0x02, 0xD3, 0x02,
	0x23, 0x00, 0x00, 0x02, 0xD4, 0x34,
	0x23, 0x00, 0x00, 0x02, 0xD5, 0x02,
	0x23, 0x00, 0x00, 0x02, 0xD6, 0x79,
	0x23, 0x00, 0x00, 0x02, 0xD7, 0x02,
	0x23, 0x00, 0x00, 0x02, 0xD8, 0xA4,
	0x23, 0x00, 0x00, 0x02, 0xD9, 0x02,
	0x23, 0x00, 0x00, 0x02, 0xDA, 0xDD,
	0x23, 0x00, 0x00, 0x02, 0xDB, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xDC, 0x05,
	0x23, 0x00, 0x00, 0x02, 0xDD, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xDE, 0x39,
	0x23, 0x00, 0x00, 0x02, 0xDF, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xE0, 0x48,
	0x23, 0x00, 0x00, 0x02, 0xE1, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xE2, 0x58,
	0x23, 0x00, 0x00, 0x02, 0xE3, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xE4, 0x6A,
	0x23, 0x00, 0x00, 0x02, 0xE5, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xE6, 0x7F,
	0x23, 0x00, 0x00, 0x02, 0xE7, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xE8, 0x98,
	0x23, 0x00, 0x00, 0x02, 0xE9, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xEA, 0xB7,
	0x23, 0x00, 0x00, 0x02, 0xEB, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xEC, 0xD7,
	0x23, 0x00, 0x00, 0x02, 0xED, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xEE, 0xFF,
	0x23, 0x00, 0x00, 0x02, 0xEF, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xF0, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xF1, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xF2, 0x11,
	0x23, 0x00, 0x00, 0x02, 0xF3, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xF4, 0x30,
	0x23, 0x00, 0x00, 0x02, 0xF5, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xF6, 0x4A,
	0x23, 0x00, 0x00, 0x02, 0xF7, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xF8, 0x62,
	0x23, 0x00, 0x00, 0x02, 0xF9, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xFA, 0x78,
	0x23, 0x00, 0x00, 0x02, 0xFF, 0x02,
	0x23, 0x00, 0x00, 0x02, 0xFB, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x00, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x01, 0x8C,
	0x23, 0x00, 0x00, 0x02, 0x02, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x03, 0x9E,
	0x23, 0x00, 0x00, 0x02, 0x04, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x05, 0xAE,
	0x23, 0x00, 0x00, 0x02, 0x06, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x07, 0xE4,
	0x23, 0x00, 0x00, 0x02, 0x08, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x09, 0x0E,
	0x23, 0x00, 0x00, 0x02, 0x0A, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x0B, 0x4C,
	0x23, 0x00, 0x00, 0x02, 0x0C, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x0D, 0x7B,
	0x23, 0x00, 0x00, 0x02, 0x0E, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x0F, 0xC2,
	0x23, 0x00, 0x00, 0x02, 0x10, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x11, 0xFB,
	0x23, 0x00, 0x00, 0x02, 0x12, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x13, 0xFC,
	0x23, 0x00, 0x00, 0x02, 0x14, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x15, 0x34,
	0x23, 0x00, 0x00, 0x02, 0x16, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x17, 0x79,
	0x23, 0x00, 0x00, 0x02, 0x18, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x19, 0xA4,
	0x23, 0x00, 0x00, 0x02, 0x1A, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x1B, 0xDD,
	0x23, 0x00, 0x00, 0x02, 0x1C, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x1D, 0x05,
	0x23, 0x00, 0x00, 0x02, 0x1E, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x1F, 0x39,
	0x23, 0x00, 0x00, 0x02, 0x20, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x21, 0x48,
	0x23, 0x00, 0x00, 0x02, 0x22, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x23, 0x58,
	0x23, 0x00, 0x00, 0x02, 0x24, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x25, 0x6A,
	0x23, 0x00, 0x00, 0x02, 0x26, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x27, 0x7F,
	0x23, 0x00, 0x00, 0x02, 0x28, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x29, 0x98,
	0x23, 0x00, 0x00, 0x02, 0x2A, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x2B, 0xB7,
	0x23, 0x00, 0x00, 0x02, 0x2D, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x2F, 0xD7,
	0x23, 0x00, 0x00, 0x02, 0x30, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x31, 0xFF,
	0x23, 0x00, 0x00, 0x02, 0x32, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x33, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x34, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x35, 0x11,
	0x23, 0x00, 0x00, 0x02, 0x36, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x37, 0x30,
	0x23, 0x00, 0x00, 0x02, 0x38, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x39, 0x4A,
	0x23, 0x00, 0x00, 0x02, 0x3A, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x3B, 0x62,
	0x23, 0x00, 0x00, 0x02, 0x3D, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x3F, 0x78,
	0x23, 0x00, 0x00, 0x02, 0x40, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x41, 0x8C,
	0x23, 0x00, 0x00, 0x02, 0x42, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x43, 0x9E,
	0x23, 0x00, 0x00, 0x02, 0x44, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x45, 0xAE,
	0x23, 0x00, 0x00, 0x02, 0x46, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x47, 0xE4,
	0x23, 0x00, 0x00, 0x02, 0x48, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x49, 0x0E,
	0x23, 0x00, 0x00, 0x02, 0x4A, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x4B, 0x4C,
	0x23, 0x00, 0x00, 0x02, 0x4C, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x4D, 0x7B,
	0x23, 0x00, 0x00, 0x02, 0x4E, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x4F, 0xC2,
	0x23, 0x00, 0x00, 0x02, 0x50, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x51, 0xFB,
	0x23, 0x00, 0x00, 0x02, 0x52, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x53, 0xFC,
	0x23, 0x00, 0x00, 0x02, 0x54, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x55, 0x34,
	0x23, 0x00, 0x00, 0x02, 0x56, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x58, 0x79,
	0x23, 0x00, 0x00, 0x02, 0x59, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x5A, 0xA4,
	0x23, 0x00, 0x00, 0x02, 0x5B, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x5C, 0xDD,
	0x23, 0x00, 0x00, 0x02, 0x5D, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x5E, 0x05,
	0x23, 0x00, 0x00, 0x02, 0x5F, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x60, 0x39,
	0x23, 0x00, 0x00, 0x02, 0x61, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x62, 0x48,
	0x23, 0x00, 0x00, 0x02, 0x63, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x64, 0x58,
	0x23, 0x00, 0x00, 0x02, 0x65, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x66, 0x6A,
	0x23, 0x00, 0x00, 0x02, 0x67, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x68, 0x7F,
	0x23, 0x00, 0x00, 0x02, 0x69, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x6A, 0x98,
	0x23, 0x00, 0x00, 0x02, 0x6B, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x6C, 0xB7,
	0x23, 0x00, 0x00, 0x02, 0x6D, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x6E, 0xD7,
	0x23, 0x00, 0x00, 0x02, 0x6F, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x70, 0xFF,
	0x23, 0x00, 0x00, 0x02, 0x71, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x72, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x73, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x74, 0x11,
	0x23, 0x00, 0x00, 0x02, 0x75, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x76, 0x30,
	0x23, 0x00, 0x00, 0x02, 0x77, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x78, 0x4A,
	0x23, 0x00, 0x00, 0x02, 0x79, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x7A, 0x62,
	0x23, 0x00, 0x00, 0x02, 0x7B, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x7C, 0x78,
	0x23, 0x00, 0x00, 0x02, 0x7D, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x7E, 0x8C,
	0x23, 0x00, 0x00, 0x02, 0x7F, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x80, 0x9E,
	0x23, 0x00, 0x00, 0x02, 0x81, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x82, 0xAE,
	0x23, 0x00, 0x00, 0x02, 0x83, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x84, 0xE4,
	0x23, 0x00, 0x00, 0x02, 0x85, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x86, 0x0E,
	0x23, 0x00, 0x00, 0x02, 0x87, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x88, 0x4C,
	0x23, 0x00, 0x00, 0x02, 0x89, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x8A, 0x7B,
	0x23, 0x00, 0x00, 0x02, 0x8B, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x8C, 0xC2,
	0x23, 0x00, 0x00, 0x02, 0x8D, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x8E, 0xFB,
	0x23, 0x00, 0x00, 0x02, 0x8F, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x90, 0xFC,
	0x23, 0x00, 0x00, 0x02, 0x91, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x92, 0x34,
	0x23, 0x00, 0x00, 0x02, 0x93, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x94, 0x79,
	0x23, 0x00, 0x00, 0x02, 0x95, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x96, 0xA4,
	0x23, 0x00, 0x00, 0x02, 0x97, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x98, 0xDD,
	0x23, 0x00, 0x00, 0x02, 0x99, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x9A, 0x05,
	0x23, 0x00, 0x00, 0x02, 0x9B, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x9C, 0x39,
	0x23, 0x00, 0x00, 0x02, 0x9D, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x9E, 0x48,
	0x23, 0x00, 0x00, 0x02, 0x9F, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xA0, 0x58,
	0x23, 0x00, 0x00, 0x02, 0xA2, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xA3, 0x6A,
	0x23, 0x00, 0x00, 0x02, 0xA4, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xA5, 0x7F,
	0x23, 0x00, 0x00, 0x02, 0xA6, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xA7, 0x98,
	0x23, 0x00, 0x00, 0x02, 0xA9, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xAA, 0xB7,
	0x23, 0x00, 0x00, 0x02, 0xAB, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xAC, 0xD7,
	0x23, 0x00, 0x00, 0x02, 0xAD, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xAE, 0xFF,
	0x23, 0x00, 0x00, 0x02, 0xAF, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xB0, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xB1, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xB2, 0x11,
	0x23, 0x00, 0x00, 0x02, 0xB3, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xB4, 0x30,
	0x23, 0x00, 0x00, 0x02, 0xB5, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xB6, 0x4A,
	0x23, 0x00, 0x00, 0x02, 0xB7, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xB8, 0x62,
	0x23, 0x00, 0x00, 0x02, 0xB9, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xBA, 0x78,
	0x23, 0x00, 0x00, 0x02, 0xBB, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xBC, 0x8C,
	0x23, 0x00, 0x00, 0x02, 0xBD, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xBE, 0x9E,
	0x23, 0x00, 0x00, 0x02, 0xBF, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xC0, 0xAE,
	0x23, 0x00, 0x00, 0x02, 0xC1, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xC2, 0xE4,
	0x23, 0x00, 0x00, 0x02, 0xC3, 0x01,
	0x23, 0x00, 0x00, 0x02, 0xC4, 0x0E,
	0x23, 0x00, 0x00, 0x02, 0xC5, 0x01,
	0x23, 0x00, 0x00, 0x02, 0xC6, 0x4C,
	0x23, 0x00, 0x00, 0x02, 0xC7, 0x01,
	0x23, 0x00, 0x00, 0x02, 0xC8, 0x7B,
	0x23, 0x00, 0x00, 0x02, 0xC9, 0x01,
	0x23, 0x00, 0x00, 0x02, 0xCA, 0xC2,
	0x23, 0x00, 0x00, 0x02, 0xCB, 0x01,
	0x23, 0x00, 0x00, 0x02, 0xCC, 0xFB,
	0x23, 0x00, 0x00, 0x02, 0xCD, 0x01,
	0x23, 0x00, 0x00, 0x02, 0xCE, 0xFC,
	0x23, 0x00, 0x00, 0x02, 0xCF, 0x02,
	0x23, 0x00, 0x00, 0x02, 0xD0, 0x34,
	0x23, 0x00, 0x00, 0x02, 0xD1, 0x02,
	0x23, 0x00, 0x00, 0x02, 0xD2, 0x79,
	0x23, 0x00, 0x00, 0x02, 0xD3, 0x02,
	0x23, 0x00, 0x00, 0x02, 0xD4, 0xA4,
	0x23, 0x00, 0x00, 0x02, 0xD5, 0x02,
	0x23, 0x00, 0x00, 0x02, 0xD6, 0xDD,
	0x23, 0x00, 0x00, 0x02, 0xD7, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xD8, 0x05,
	0x23, 0x00, 0x00, 0x02, 0xD9, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xDA, 0x39,
	0x23, 0x00, 0x00, 0x02, 0xDB, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xDC, 0x48,
	0x23, 0x00, 0x00, 0x02, 0xDD, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xDE, 0x58,
	0x23, 0x00, 0x00, 0x02, 0xDF, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xE0, 0x6A,
	0x23, 0x00, 0x00, 0x02, 0xE1, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xE2, 0x7F,
	0x23, 0x00, 0x00, 0x02, 0xE3, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xE4, 0x98,
	0x23, 0x00, 0x00, 0x02, 0xE5, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xE6, 0xB7,
	0x23, 0x00, 0x00, 0x02, 0xE7, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xE8, 0xD7,
	0x23, 0x00, 0x00, 0x02, 0xE9, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xEA, 0xFF,
	0x23, 0x00, 0x00, 0x02, 0xFF, 0x05,
	0x23, 0x00, 0x00, 0x02, 0xFB, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x00, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x01, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x02, 0x0B,
	0x23, 0x00, 0x00, 0x02, 0x03, 0x0C,
	0x23, 0x00, 0x00, 0x02, 0x04, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x05, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x06, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x07, 0x04,
	0x23, 0x00, 0x00, 0x02, 0x08, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x09, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x0A, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x0B, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x0C, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x0D, 0x17,
	0x23, 0x00, 0x00, 0x02, 0x0E, 0x15,
	0x23, 0x00, 0x00, 0x02, 0x0F, 0x13,
	0x23, 0x00, 0x00, 0x02, 0x10, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x11, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x12, 0x0B,
	0x23, 0x00, 0x00, 0x02, 0x13, 0x0C,
	0x23, 0x00, 0x00, 0x02, 0x14, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x15, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x16, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x17, 0x04,
	0x23, 0x00, 0x00, 0x02, 0x18, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x19, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x1A, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x1B, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x1C, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x1D, 0x17,
	0x23, 0x00, 0x00, 0x02, 0x1E, 0x15,
	0x23, 0x00, 0x00, 0x02, 0x1F, 0x13,
	0x23, 0x00, 0x00, 0x02, 0x20, 0x09,
	0x23, 0x00, 0x00, 0x02, 0x21, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x22, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x23, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x24, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x25, 0x3D,
	0x23, 0x00, 0x00, 0x02, 0x29, 0x38,
	0x23, 0x00, 0x00, 0x02, 0x2A, 0x2B,
	0x23, 0x00, 0x00, 0x02, 0x2F, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x30, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x31, 0x49,
	0x23, 0x00, 0x00, 0x02, 0x32, 0x23,
	0x23, 0x00, 0x00, 0x02, 0x33, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x34, 0x05,
	0x23, 0x00, 0x00, 0x02, 0x35, 0x74,
	0x23, 0x00, 0x00, 0x02, 0x36, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x37, 0x2D,
	0x23, 0x00, 0x00, 0x02, 0x38, 0x08,
	0x23, 0x00, 0x00, 0x02, 0x92, 0x94,
	0x23, 0x00, 0x00, 0x02, 0x5B, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x5F, 0x1D,
	0x23, 0x00, 0x00, 0x02, 0x63, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x67, 0x04,
	0x23, 0x00, 0x00, 0x02, 0x6C, 0x55,
	0x23, 0x00, 0x00, 0x02, 0x7A, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x7B, 0xA2,
	0x23, 0x00, 0x00, 0x02, 0x7C, 0xD8,
	0x23, 0x00, 0x00, 0x02, 0x7D, 0x50,
	0x23, 0x00, 0x00, 0x02, 0x7E, 0x0A,
	0x23, 0x00, 0x00, 0x02, 0x7F, 0x1C,
	0x23, 0x00, 0x00, 0x02, 0x81, 0x06,
	0x23, 0x00, 0x00, 0x02, 0x82, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x84, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x85, 0x05,
	0x23, 0x00, 0x00, 0x02, 0xC5, 0x20,
	0x23, 0x00, 0x00, 0x02, 0x80, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x83, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x93, 0x08,
	0x23, 0x00, 0x00, 0x02, 0x94, 0x0A,
	0x23, 0x00, 0x00, 0x02, 0x8A, 0x33,
	0x23, 0x00, 0x00, 0x02, 0xA4, 0x0F,
	0x23, 0x00, 0x00, 0x02, 0x9B, 0x0F,
	0x23, 0x00, 0x00, 0x02, 0x9D, 0xB0,
	0x23, 0x00, 0x00, 0x02, 0xE7, 0x83,
	0x23, 0x00, 0x00, 0x02, 0xE3, 0x02,
	0x23, 0x00, 0x00, 0x02, 0xFF, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xD2, 0x03,
	0x23, 0x00, 0x00, 0x02, 0xD3, 0x24,	//vsync+vbp
	0x23, 0x00, 0x00, 0x02, 0xD4, 0x20,	//vfp
	0x23, 0x00, 0x00, 0x02, 0x35, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xBA, 0x03,
	0x13, 0x78, 0x00, 0x01, 0x11,
	0x13, 0x64, 0x00, 0x01, 0x29,
	CMD_END
};

static int mipi_dsi_send_cmds(struct sprd_dsi *dsi, void *data)
{
	uint16_t len;
	struct dsi_cmd_desc *cmds = data;

	if ((cmds == NULL) || (dsi == NULL))
		return -1;

	for (; cmds->data_type != CMD_END;) {
		len = (cmds->wc_h << 8) | cmds->wc_l;
		mipi_dsi_gen_write(dsi, cmds->payload, len);
		if (cmds->wait)
			msleep(cmds->wait);
		cmds = (struct dsi_cmd_desc *)(cmds->payload + len);
	}
	return 0;
}

static int nt35596_init(void)
{
	struct sprd_dsi *dsi = &dsi_device;
	struct sprd_dphy *dphy = &dphy_device;

	mipi_dsi_lp_cmd_enable(dsi, true);
	mipi_dsi_send_cmds(dsi, init_data);
	mipi_dsi_set_work_mode(dsi, SPRD_MIPI_MODE_VIDEO);
	mipi_dsi_state_reset(dsi);
	mipi_dphy_hs_clk_en(dphy, true);

	return 0;
}

static int nt35596_readid(void)
{
	struct sprd_dsi *dsi = &dsi_device;
	uint8_t read_buf[4] = {0};

	mipi_dsi_lp_cmd_enable(dsi, true);
	mipi_dsi_set_max_return_size(dsi, 1);
	mipi_dsi_dcs_read(dsi, 0xF4, read_buf, 1);

	if (read_buf[0] == 0x96) {
		pr_info("nt35596 read id success!\n");
		return 0;
	}

	pr_err("nt35596 read id failed!\n");
	return -1;
}

static int nt35596_power(int on)
{
#ifndef CONFIG_FPGA
	if (on) {
		sprd_gpio_request(NULL, CONFIG_LCM_GPIO_AVDDEN);
		sprd_gpio_direction_output(NULL, CONFIG_LCM_GPIO_AVDDEN, 1);
		mdelay(10);
		sprd_gpio_request(NULL, CONFIG_LCM_GPIO_AVEEEN);
		sprd_gpio_direction_output(NULL, CONFIG_LCM_GPIO_AVEEEN, 1);
		mdelay(20);
		sprd_gpio_request(NULL, CONFIG_LCM_GPIO_RSTN);
		sprd_gpio_direction_output(NULL, CONFIG_LCM_GPIO_RSTN, 1);
		mdelay(5);
		sprd_gpio_direction_output(NULL, CONFIG_LCM_GPIO_RSTN, 0);
		mdelay(5);
		sprd_gpio_direction_output(NULL, CONFIG_LCM_GPIO_RSTN, 1);
		mdelay(5);
		sprd_gpio_direction_output(NULL, CONFIG_LCM_GPIO_RSTN, 0);
		mdelay(5);
		sprd_gpio_direction_output(NULL, CONFIG_LCM_GPIO_RSTN, 1);
		mdelay(20);
	} else {
		sprd_gpio_direction_output(NULL, CONFIG_LCM_GPIO_RSTN, 0);
		mdelay(5);
	}
#endif
	return 0;
}

static struct panel_ops nt35596_ops = {
	.init = nt35596_init,
	.read_id = nt35596_readid,
	.power = nt35596_power,
};

static struct panel_info nt35596_info = {
	/* common parameters */
	.lcd_name = "lcd_nt35596_boe_mipi_fhd",
	.type = SPRD_PANEL_TYPE_MIPI,
	.bpp = 24,
//	.fps = 3,
	.width = 1080,
	.height = 1920,

	/* DPI specific parameters */
#ifdef CONFIG_FPGA
	.pixel_clk = 6500000, /*Hz*/
#else
	.pixel_clk = 153600000, /*Hz*/
#endif
	.rgb_timing = {
		.hfp = 176,
		.hbp = 16,
		.hsync = 10,
		.vfp = 32,
		.vbp = 32,
		.vsync = 4,
	},

	/* MIPI DSI specific parameters */
#ifdef CONFIG_FPGA
	.phy_freq = 300000, /*Kbps*/
#else
	.phy_freq = 1000000, /*Kbps*/
#endif
	.lane_num = 4,
	.work_mode = SPRD_MIPI_MODE_VIDEO,
	.burst_mode = PANEL_VIDEO_BURST_MODE,
	.nc_clk_en = false,
};

struct panel_driver nt35596_boe_driver = {
	.info = &nt35596_info,
	.ops = &nt35596_ops,
};

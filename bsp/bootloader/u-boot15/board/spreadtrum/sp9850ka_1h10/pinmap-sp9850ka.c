/*
 * Copyright (C) 2012 Spreadtrum Communications Inc.
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

/*
 *Version SC9850-2_KA_V1.0.0_PINMAP
 */

#include <asm/io.h>
#include <asm/arch/pinmap.h>
#include <power/sprd_pmic/sprd_2721_pinmap.h>

#define BIT_PIN_SLP_ALL  (BIT_PIN_SLP_AP|BIT_PIN_SLP_PUBCP|BIT_PIN_SLP_WTLCP)
#define BIT_PIN_SLP_ALL_CP  (BIT_PIN_SLP_PUBCP|BIT_PIN_SLP_WTLCP)

static pinmap_t pinmap[]={
{REG_PIN_CTRL0,0x00000000},
{REG_PIN_CTRL1,0x00000240},
{REG_PIN_CTRL2,0x20403810},//uart5->LTEDSP'uart0   uart0->PUBCP'uart;  uart1->AP'uart1; uart2->TGDSP'uart1; uart3->GPS'uart3; 
{REG_PIN_CTRL3,0x0},//IIS DEF = AP
{REG_PIN_CTRL4,0x00000002},
{REG_PIN_CTRL5,0x00005b00},//   BAT_DET = APEMMC/APSDIO1/APSDIO0/PUBCPSIM1/PUBCPSIM0

{REG_PIN_EXTINT0,                  BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_EXTINT0,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU},//CTP_INT
{REG_PIN_EXTINT1,                  BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_EXTINT1,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//CTP_RST
{REG_PIN_SCL3,                     BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SCL3,                BIT_PIN_WPUS|BITS_PIN_DS(3)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//CTP_SCL
{REG_PIN_SDA3,                     BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SDA3,                BIT_PIN_WPUS|BITS_PIN_DS(3)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//CTP_SDA
{REG_PIN_RFSDA0,                   BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_RFSDA0,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_WPD},//PCC_RFSDA
{REG_PIN_RFSCK0,                   BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_RFSCK0,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_WPD},//PCC_RFSCK
{REG_PIN_RFSEN0,                   BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_RFSEN0,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_WPD},//PCC_RFSEN
{REG_PIN_RFSDA1,                   BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_RFSDA1,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_WPD},//SCC_RFSDA
{REG_PIN_RFSCK1,                   BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_RFSCK1,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_WPD},//SCC_RFSCK
{REG_PIN_RFSEN1,                   BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_RFSEN1,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_WPD},//SCC_RFSEN
{REG_PIN_RF_LVDS0_ADC_ON,          BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(3)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_RF_LVDS0_ADC_ON,     BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//NC
{REG_PIN_RF_LVDS0_DAC_ON,          BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(3)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_RF_LVDS0_DAC_ON,     BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//NC
{REG_PIN_RFCTL15,                  BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_RFCTL15,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//VDD_SMARTAMP_BYP
{REG_PIN_RFCTL16,                  BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_RFCTL16,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//NC
{REG_PIN_RFCTL17,                  BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_RFCTL17,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//NC
{REG_PIN_RFCTL0,                   BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_RFCTL0,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//NC
{REG_PIN_RFCTL1,                   BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_RFCTL1,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//NC
{REG_PIN_RFCTL2,                   BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_RFCTL2,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//NC
{REG_PIN_RFCTL3,                   BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_RFCTL3,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//RFCTL3
{REG_PIN_RFCTL4,                   BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_RFCTL4,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//RFCTL4
{REG_PIN_RFCTL5,                   BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_RFCTL5,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//RFCTL5
{REG_PIN_RFCTL6,                   BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_RFCTL6,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//RFCTL6
{REG_PIN_RFCTL7,                   BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_RFCTL7,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//RFCTL7
{REG_PIN_RFCTL8,                   BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_RFCTL8,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//RFCTL8
{REG_PIN_RFCTL9,                   BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_RFCTL9,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//NC
{REG_PIN_RFCTL10,                  BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_RFCTL10,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//NC
{REG_PIN_RFCTL11,                  BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_RFCTL11,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//CAMERA_FLASH_SYNC  
{REG_PIN_RFCTL12,                  BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_RFCTL12,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//CAMERA_FLASH_EN (GPIO31)
{REG_PIN_RFCTL13,                  BIT_PIN_SLP_AP|BITS_PIN_AF(1)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_RFCTL13,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//LCM_PWM_BL
{REG_PIN_RFCTL14,                  BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_RFCTL14,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//VDD_SMARTAMP_EN
{REG_PIN_XTL_EN,                   BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_XTL_EN,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//NC
{REG_PIN_RFFE0_SCK,                BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_RFFE0_SCK,           BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_WPD},//PCC_RFFE_SCK0
{REG_PIN_RFFE0_SDA,                BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_RFFE0_SDA,           BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//PCC_RFFE_SDA0
{REG_PIN_RFFE1_SCK,                BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_RFFE1_SCK,           BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_WPD},//SCC_RFFE_SCK0
{REG_PIN_RFFE1_SDA,                BIT_PIN_SLP_ALL_CP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_RFFE1_SDA,           BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//PCC_RFFE_SDA0
{REG_PIN_DTDO_LTE,                 BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_DTDO_LTE,            BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//M_INT
{REG_PIN_DTDI_LTE,                 BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_DTDI_LTE,            BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//M_DRDY
{REG_PIN_DTCK_LTE,                 BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_DTCK_LTE,            BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//CAMERA_TORCH_EN
{REG_PIN_DTMS_LTE,                 BIT_PIN_SLP_ALL|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_DTMS_LTE,            BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPD},//T2116
{REG_PIN_DRTCK_LTE,                BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_DRTCK_LTE,           BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//CAMERA_FLASH_CHIPEN
{REG_PIN_SIMCLK0,                  BIT_PIN_SLP_PUBCP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_SIMCLK0,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//SIM0_CLK
{REG_PIN_SIMDA0,                   BIT_PIN_SLP_PUBCP|BITS_PIN_AF(0)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_SIMDA0,              BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//SIM0_DA
{REG_PIN_SIMRST0,                  BIT_PIN_SLP_PUBCP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_SIMRST0,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//SIM0_RST
{REG_PIN_SIMCLK1,                  BIT_PIN_SLP_PUBCP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_SIMCLK1,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//SIM1_CLK
{REG_PIN_SIMDA1,                   BIT_PIN_SLP_PUBCP|BITS_PIN_AF(0)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_SIMDA1,              BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//SIM1_DA
{REG_PIN_SIMRST1,                  BIT_PIN_SLP_PUBCP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_SIMRST1,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//SIM1_RST
{REG_PIN_SIMCLK2,                  BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SIMCLK2,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//NC
{REG_PIN_SIMDA2,                   BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SIMDA2,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//NC
{REG_PIN_SIMRST2,                  BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SIMRST2,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//NC
{REG_PIN_IIS3DI,                   BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_IIS3DI,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//BOARD_ID0
{REG_PIN_IIS3DO,                   BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_IIS3DO,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//BOARD_ID1
{REG_PIN_IIS3CLK,                  BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_IIS3CLK,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU},//CHG_STAT
{REG_PIN_IIS3LRCK,                 BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_IIS3LRCK,            BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//LCM_ID
{REG_PIN_LCM_RSTN,                 BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_LCM_RSTN,            BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//LCM_RSTN
{REG_PIN_DSI_TE,                   BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_DSI_TE,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//LCM_FMARK
{REG_PIN_SCL2,                     BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SCL2,                BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU},//I2C2_SCL
{REG_PIN_SDA2,                     BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SDA2,                BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU},//I2C2_SDA
{REG_PIN_SPI0_CSN,                 BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_SPI0_CSN,            BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU},//PROX_INT
{REG_PIN_SPI0_DO,                  BIT_PIN_SLP_AP|BITS_PIN_AF(1)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SPI0_DO,             BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU},//I2C1_SDA
{REG_PIN_SPI0_DI,                  BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_SPI0_DI,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//AG_INT0
{REG_PIN_SPI0_CLK,                 BIT_PIN_SLP_AP|BITS_PIN_AF(1)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SPI0_CLK,            BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU},//I2C1_SCL
{REG_PIN_SD0_D3,                   BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SD0_D3,              BIT_PIN_NULL|BITS_PIN_DS(4)|BIT_PIN_WPU|BIT_PIN_SLP_WPD},//TF_SD0_D3
{REG_PIN_SD0_D2,                   BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SD0_D2,              BIT_PIN_NULL|BITS_PIN_DS(4)|BIT_PIN_WPU|BIT_PIN_SLP_WPD},//TF_SD0_D2
{REG_PIN_SD0_CMD,                  BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SD0_CMD,             BIT_PIN_NULL|BITS_PIN_DS(4)|BIT_PIN_WPU|BIT_PIN_SLP_WPD},//TF_SD0_CMD
{REG_PIN_SD0_D0,                   BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SD0_D0,              BIT_PIN_NULL|BITS_PIN_DS(4)|BIT_PIN_WPU|BIT_PIN_SLP_WPD},//TF_SD0_D0
{REG_PIN_SD0_D1,                   BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SD0_D1,              BIT_PIN_NULL|BITS_PIN_DS(4)|BIT_PIN_WPU|BIT_PIN_SLP_WPD},//TF_SD0_D1
{REG_PIN_SD0_CLK0,                 BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_SD0_CLK0,            BIT_PIN_NULL|BITS_PIN_DS(7)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//TF_SD0_CLK
{REG_PIN_SD2_CLK,                  BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SD2_CLK,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//NC
{REG_PIN_SD2_CMD,                  BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SD2_CMD,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//NC
{REG_PIN_SD2_D0,                   BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SD2_D0,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//NC
{REG_PIN_SD2_D1,                   BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SD2_D1,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//NC
{REG_PIN_SD2_D2,                   BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SD2_D2,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//NC
{REG_PIN_SD2_D3,                   BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SD2_D3,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//NC
{REG_PIN_PTEST,                    BIT_PIN_SLP_ALL|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_PTEST,               BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//GND
{REG_PIN_ANA_INT,                  BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_ANA_INT,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//ANA_INT
{REG_PIN_EXT_RST_B,                BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_EXT_RST_B,           BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//EXT_RST_B
{REG_PIN_CHIP_SLEEP,               BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_CHIP_SLEEP,          BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//CHIP_SLEEP
{REG_PIN_XTL_BUF_EN0,              BIT_PIN_SLP_ALL|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_XTL_BUF_EN0,         BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//VDDARM_EN
{REG_PIN_XTL_BUF_EN1,              BIT_PIN_SLP_ALL|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_XTL_BUF_EN1,         BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//XTL_BUF_EN
{REG_PIN_CLK_32K,                  BIT_PIN_SLP_ALL|BITS_PIN_AF(0)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_CLK_32K,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//CLK_32K
{REG_PIN_AUD_SCLK,                 BIT_PIN_SLP_ALL|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_AUD_SCLK,            BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//AUD_SCLK
{REG_PIN_AUD_ADD0,                 BIT_PIN_SLP_ALL|BITS_PIN_AF(0)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_AUD_ADD0,            BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//AUD_ADD0
{REG_PIN_AUD_ADSYNC,               BIT_PIN_SLP_ALL|BITS_PIN_AF(0)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_AUD_ADSYNC,          BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//AUD_ADSYNC
{REG_PIN_AUD_DAD1,                 BIT_PIN_SLP_ALL|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_AUD_DAD1,            BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//AUD_DAD1
{REG_PIN_AUD_DAD0,                 BIT_PIN_SLP_ALL|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_AUD_DAD0,            BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//AUD_DAD0
{REG_PIN_AUD_DASYNC,               BIT_PIN_SLP_ALL|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_AUD_DASYNC,          BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//AUD_DASYNC
{REG_PIN_ADI_D,                    BIT_PIN_SLP_NONE|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_ADI_D,               BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_WPD},//ADI_D
{REG_PIN_ADI_SCLK,                 BIT_PIN_SLP_NONE|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_ADI_SCLK,            BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_WPD},//ADI_SCLK
{REG_PIN_U1TXD,                    BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_U1TXD,               BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//BB_U1TXD
{REG_PIN_U1RXD,                    BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_U1RXD,               BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU},//BB_U1RXD
{REG_PIN_U2TXD,                    BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_U2TXD,               BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//BB_U2TXD
{REG_PIN_U2RXD,                    BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_U2RXD,               BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU},//BB_U2RXD
{REG_PIN_U4TXD,                    BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_U4TXD,               BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU},//TF_DET
{REG_PIN_U4RXD,                    BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_U4RXD,               BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU},//BUA_BAT_DET !!!
{REG_PIN_IIS1DI,                   BIT_PIN_SLP_AP|BITS_PIN_AF(2)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_IIS1DI,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//FTID_INT
{REG_PIN_IIS1DO,                   BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_IIS1DO,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//FTID_RSTN
{REG_PIN_IIS1CLK,                  BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_IIS1CLK,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//NC
{REG_PIN_IIS1LRCK,                 BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_IIS1LRCK,            BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//NC
{REG_PIN_SPI2_CSN,                 BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_SPI2_CSN,            BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//FTID_SPI_CS
{REG_PIN_SPI2_DO,                  BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SPI2_DO,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_WPD},//FTID_SPI_DI
{REG_PIN_SPI2_DI,                  BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SPI2_DI,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_WPD},//FTID_SPI_DO
{REG_PIN_SPI2_CLK,                 BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SPI2_CLK,            BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_WPD},//FTID_SPI_CLK
{REG_PIN_MTCK_ARM,                 BIT_PIN_SLP_NONE|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_MTCK_ARM,            BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//MTCK(sim0_det)
{REG_PIN_MTMS_ARM,                 BIT_PIN_SLP_NONE|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_MTMS_ARM,            BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPD},//MTMS(sim1_det)
{REG_PIN_EMMC_D2,                  BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_EMMC_D2,             BIT_PIN_NULL|BITS_PIN_DS(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPD},//EMMC_D2
{REG_PIN_EMMC_D5,                  BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_EMMC_D5,             BIT_PIN_NULL|BITS_PIN_DS(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPD},//EMMC_D5
{REG_PIN_EMMC_D1,                  BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_EMMC_D1,             BIT_PIN_NULL|BITS_PIN_DS(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPD},//EMMC_D1
{REG_PIN_EMMC_D4,                  BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_EMMC_D4,             BIT_PIN_NULL|BITS_PIN_DS(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPD},//EMMC_D4
{REG_PIN_EMMC_DS,                  BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_EMMC_DS,             BIT_PIN_NULL|BITS_PIN_DS(3)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//EMMC_RLCK
{REG_PIN_EMMC_CLK,                 BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_EMMC_CLK,            BIT_PIN_NULL|BITS_PIN_DS(3)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//EMMC_CLK
{REG_PIN_EMMC_D6,                  BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_EMMC_D6,             BIT_PIN_NULL|BITS_PIN_DS(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPD},//EMMC_D6
{REG_PIN_EMMC_D3,                  BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_EMMC_D3,             BIT_PIN_NULL|BITS_PIN_DS(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPD},//EMMC_D3
{REG_PIN_EMMC_D0,                  BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_EMMC_D0,             BIT_PIN_NULL|BITS_PIN_DS(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPD},//EMMC_D0
{REG_PIN_EMMC_CMD,                 BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_EMMC_CMD,            BIT_PIN_NULL|BITS_PIN_DS(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPD},//EMMC_CMD
{REG_PIN_EMMC_D7,                  BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_EMMC_D7,             BIT_PIN_NULL|BITS_PIN_DS(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPD},//EMMC_D7
{REG_PIN_EMMC_RST,                 BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_EMMC_RST,            BIT_PIN_NULL|BITS_PIN_DS(3)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//EMMC_RST
{REG_PIN_MEMS_MIC_CLK0,            BIT_PIN_SLP_AP|BITS_PIN_AF(1)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_MEMS_MIC_CLK0,       BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//WF_COEXIST
{REG_PIN_MEMS_MIC_DATA0,           BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_MEMS_MIC_DATA0,      BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//AG_INT1
{REG_PIN_MEMS_MIC_CLK1,            BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_MEMS_MIC_CLK1,       BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//NC
{REG_PIN_MEMS_MIC_DATA1,           BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_MEMS_MIC_DATA1,      BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//WB_CHIP_EN
{REG_PIN_SD1_CLK,                  BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_SD1_CLK,             BIT_PIN_NULL|BITS_PIN_DS(3)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//WF_SD1_CLK
{REG_PIN_SD1_CMD,                  BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SD1_CMD,             BIT_PIN_WPUS|BITS_PIN_DS(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPD},//WF_SD1_CMD
{REG_PIN_SD1_D0,                   BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SD1_D0,              BIT_PIN_WPUS|BITS_PIN_DS(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPD},//WF_SD1_D0
{REG_PIN_SD1_D1,                   BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SD1_D1,              BIT_PIN_WPUS|BITS_PIN_DS(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPD},//WF_SD1_D1
{REG_PIN_SD1_D2,                   BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SD1_D2,              BIT_PIN_WPUS|BITS_PIN_DS(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPD},//WF_SD1_D2
{REG_PIN_SD1_D3,                   BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SD1_D3,              BIT_PIN_WPUS|BITS_PIN_DS(3)|BIT_PIN_WPU|BIT_PIN_SLP_WPD},//WF_SD1_D3
{REG_PIN_IIS0DI,                   BIT_PIN_SLP_ALL|BITS_PIN_AF(0)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_IIS0DI,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//BT_PCM_OUT
{REG_PIN_IIS0DO,                   BIT_PIN_SLP_ALL|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_IIS0DO,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//BT_PCM_IN
{REG_PIN_IIS0CLK,                  BIT_PIN_SLP_ALL|BITS_PIN_AF(0)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_IIS0CLK,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//BT_PCM_CLK
{REG_PIN_IIS0LRCK,                 BIT_PIN_SLP_ALL|BITS_PIN_AF(0)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_IIS0LRCK,            BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//BT_PCM_SYNC
{REG_PIN_CLK_AUX0,                 BIT_PIN_SLP_ALL|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_CLK_AUX0,            BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//CON_32K_IN
{REG_PIN_U0TXD,                    BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_U0TXD,               BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//BB_U0TXD
{REG_PIN_U0RXD,                    BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_U0RXD,               BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU},//BB_U0RXD
{REG_PIN_U0CTS,                    BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_U0CTS,               BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU},//BB_U0CTS
{REG_PIN_U0RTS,                    BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_U0RTS,               BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_WPU},//BB_U0RTS
{REG_PIN_U3TXD,                    BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_U3TXD,               BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//GPS_U0RXD
{REG_PIN_U3RXD,                    BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_U3RXD,               BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU},//GPS_U0TXD
{REG_PIN_U3CTS,                    BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_U3CTS,               BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU},//GPS_U0RTS
{REG_PIN_U3RTS,                    BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_U3RTS,               BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_WPU},//GPS_U0CTS
{REG_PIN_RFCTL18,                  BIT_PIN_SLP_AP|BITS_PIN_AF(1)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_RFCTL18,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//WB_WCI_2_RXD
{REG_PIN_RFCTL19,                  BIT_PIN_SLP_AP|BITS_PIN_AF(1)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_RFCTL19,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU},//WB_WCI_2_TXD
{REG_PIN_KEYOUT0,                  BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_KEYOUT0,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//WB_INT
{REG_PIN_KEYOUT1,                  BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_KEYOUT1,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//WB_RX_REQ
{REG_PIN_KEYOUT2,                  BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_KEYOUT2,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//WB_RST
{REG_PIN_KEYIN0,                   BIT_PIN_SLP_AP|BITS_PIN_AF(1)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_KEYIN0,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU},//KEYIN0
{REG_PIN_KEYIN1,                   BIT_PIN_SLP_AP|BITS_PIN_AF(1)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_KEYIN1,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU},//KEYIN1
{REG_PIN_KEYIN2,                   BIT_PIN_SLP_AP|BITS_PIN_AF(1)|BIT_PIN_SLP_IE},
{REG_MISC_PIN_KEYIN2,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU},//USBID_CTRL !!!
{REG_PIN_CMPD2,                    BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_CMPD2,               BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//NC
{REG_PIN_CMRST2,                   BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_CMRST2,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD},//NC
{REG_PIN_CMMCLK0,                  BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_CMMCLK0,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//CAM_MCLK0
{REG_PIN_CMMCLK1,                  BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_OE},
{REG_MISC_PIN_CMMCLK1,             BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//CAM_MCLK1
{REG_PIN_CMRST0,                   BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_OE},  
{REG_MISC_PIN_CMRST0,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//CAM_RST0
{REG_PIN_CMRST1,                   BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_OE},  
{REG_MISC_PIN_CMRST1,              BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//CAM_RST1
{REG_PIN_CMPD0,                    BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_OE},  
{REG_MISC_PIN_CMPD0,               BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//CAM_PWDN0
{REG_PIN_CMPD1,                    BIT_PIN_SLP_AP|BITS_PIN_AF(3)|BIT_PIN_SLP_OE},  
{REG_MISC_PIN_CMPD1,               BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL},//CAM_PWDN1
{REG_PIN_SCL0,                     BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},  
{REG_MISC_PIN_SCL0,                BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU},//I2C0_SCL
{REG_PIN_SDA0,                     BIT_PIN_SLP_AP|BITS_PIN_AF(0)|BIT_PIN_SLP_Z},
{REG_MISC_PIN_SDA0,	               BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU},//I2C0_SDA
};

/*here is the adie pinmap such as 2723*/
static pinmap_t adie_pinmap[]={
{REG_PIN_ANA_EXT_XTL_EN0,		BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BIT_ANA_PIN_SLP_IE},//WB_CLK_REQ
{REG_PIN_ANA_EXT_XTL_EN1,		BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BIT_ANA_PIN_SLP_IE},
{REG_PIN_ANA_EXT_XTL_EN2,		BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BIT_ANA_PIN_SLP_IE},//XTL_BUF_EN1
{REG_PIN_ANA_EXT_XTL_EN3,		BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BIT_ANA_PIN_SLP_IE},
{REG_PIN_ANA_PTESTO,            BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_NUL|BITS_ANA_PIN_AF(1)|BIT_ANA_PIN_SLP_OE},//BUA_BAT_DET
};

int  pin_init(void)
{
	int i;
	for (i = 0; i < sizeof(pinmap)/sizeof(pinmap[0]); i++) {
		__raw_writel(pinmap[i].val, CTL_PIN_BASE + pinmap[i].reg);
	}

	for (i = 0; i < sizeof(adie_pinmap)/sizeof(adie_pinmap[0]); i++) {
		sci_adi_set(CTL_ANA_PIN_BASE + adie_pinmap[i].reg, adie_pinmap[i].val);
	}

	return 0;
}


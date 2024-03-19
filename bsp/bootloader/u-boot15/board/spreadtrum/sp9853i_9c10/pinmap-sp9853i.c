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
 *Version SC9853-1_I-IA_V1.0.0_Pinmap_V1.0  
 */

#include <asm/io.h>
#include <asm/arch/pinmap.h>
#include <power/sprd_pmic/sprd_2731_pinmap.h>

#define BIT_PIN_SLP_ALL  (BIT_PIN_SLP_AP|BIT_PIN_SLP_PUBCP|BIT_PIN_SLP_WTLCP|BIT_PIN_SLP_AONSYS)
#define BIT_SLP_ALL  (BIT_SLP_AP|BIT_SLP_PUBCP|BIT_SLP_WTLCP|BIT_SLP_AONSYS)


#define BIT_PIN_SLP_ALL_CP  (BIT_PIN_SLP_PUBCP|BIT_PIN_SLP_WTLCP|BIT_PIN_SLP_AONSYS)
#define BIT_SLP_ALL_CP  (BIT_SLP_PUBCP|BIT_SLP_WTLCP|BIT_SLP_AONSYS)


static pinmap_t pinmap[]={
{REG_PIN_CTRL_REG1,0x0},       // 0000 0000 0000 0000 0000 0000 0000 0000
{REG_PIN_CTRL_REG2,0x00408200}, // uart0->ap'uart0;  uart1->ap'uart1; uart2->pubcp'uart0; uart3->gps; uart4->tgdsp'uart0; uart5->ap'uart4 0000 0000 0100 0000 1000 0010 0000 0000
{REG_PIN_CTRL_REG3,0x0},        // 
{REG_PIN_CTRL_REG4,0x00000200}, // I2C3 for LCD Driver,I2C2 for CM4,  I2C4 for AP I2C5 Controller?  0000 0000 0000 0000 0000 0010 0000 0000
{REG_PIN_CTRL_REG5,0x0},        // 
{REG_GROUP_PIN_SIM_MS,0x0},      //0000 0000 0000 0000 0000 0000 0000 0000
{REG_GROUP_PIN_SD_MS,0x0},     //0000 0000 0000 0000 0000 0000 0000 0000
{REG_GROUP_PIN_CLK_AUX0_SEL,0x1}, //Marlin2 Deep sleep 32K input always
{REG_GROUP_PIN_CLK_AUX1_SEL,0x0}, 
{REG_GROUP_PIN_CLK_AUX2_SEL,0x0},
// CFIO                             Function | Sleep mode | Drive strength | Func WPU(30K)/WPUS(5K)/WPUS2(1K)/WPD(30K)/WPD2(5K)/NUL | Sleep WPU/WPD/NUL | Sleep OE/IE/Z
//G2 pad
{REG_PIN_EXTINT5,                 	BITS_AF(3)},
{REG_GROUP_PIN_EXTINT5,           	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_POC|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//TF_DET
//{REG_GROUP_PIN_EXTINT5,           	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//TF_DET
{REG_PIN_EXTINT6,                 	BITS_AF(3)},
{REG_GROUP_PIN_EXTINT6,           	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPU|BIT_SLP_WPU|BIT_SLP_IE},//BAT_DET   No Battery A die output low voltage to BB
{REG_PIN_EXT_RST_B,              	BITS_AF(0)},
{REG_GROUP_PIN_EXT_RST_B,        	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//EXT_RST_B'
{REG_PIN_AUD_SCLK,                	BITS_AF(0)},
{REG_GROUP_PIN_AUD_SCLK,          	BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//AUD_SCLK
{REG_PIN_DCDC_ARM_EN0,            	BITS_AF(0)},
{REG_GROUP_PIN_DCDC_ARM_EN0,      	BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//VDDCPU0_EN
{REG_PIN_CLK_32K,                 	BITS_AF(0)},
{REG_GROUP_PIN_CLK_32K,           	BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//CLK_32K
{REG_PIN_CHIP_SLEEP,              	BITS_AF(0)},
{REG_GROUP_PIN_CHIP_SLEEP,        	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//CHIP_SLEEP
{REG_PIN_AUD_ADD0,                	BITS_AF(0)},
{REG_GROUP_PIN_AUD_ADD0,          	BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//AUD_ADD0
{REG_PIN_AUD_DAD0,                	BITS_AF(0)},
{REG_GROUP_PIN_AUD_DAD0,          	BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//AUD_DAD0
{REG_PIN_AUD_ADSYNC,              	BITS_AF(0)},
{REG_GROUP_PIN_AUD_ADSYNC,        	BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//AUD_ADSYNC
{REG_PIN_AUD_DAD1,               	BITS_AF(0)},
{REG_GROUP_PIN_AUD_DAD1,          	BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//AUD_DAD1
{REG_PIN_AUD_DASYNC,              	BITS_AF(0)},
{REG_GROUP_PIN_AUD_DASYNC,        	BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//AUD_DASYNC
{REG_PIN_ADI_SCLK,                  	BITS_AF(0)},
{REG_GROUP_PIN_ADI_SCLK,            	BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//ADI_SCLK
{REG_PIN_ADI_D,                     	BITS_AF(0)},
{REG_GROUP_PIN_ADI_D,               	BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//ADI_D
{REG_PIN_DCDC_ARM_EN1,              	BITS_AF(0)},
{REG_GROUP_PIN_DCDC_ARM_EN1,        	BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//VDDCPU1_EN
{REG_PIN_SENSOR_HUB_ACTION,         	BITS_AF(0)},
{REG_GROUP_PIN_SENSOR_HUB_ACTION,   	BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//XTL_BUF_EN1
{REG_PIN_PTEST,                     	BITS_AF(0)},
{REG_GROUP_PIN_PTEST,               	BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//GND
{REG_PIN_ANA_INT,                   	BITS_AF(0)},
{REG_GROUP_PIN_ANA_INT,             	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//ANA_INT

//G3
{REG_PIN_DSI_TE,                  	BITS_AF(0)},
{REG_GROUP_PIN_DSI_TE,            	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_POC|BIT_WPD|BIT_SLP_WPD|BIT_SLP_IE},//LCM_FMARK  
{REG_PIN_LCM_RSTN,                	BITS_AF(3)},
{REG_GROUP_PIN_LCM_RSTN,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//LCM_RSTN     
{REG_PIN_PWMA,                    	BITS_AF(0)},
{REG_GROUP_PIN_PWMA,              	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//LCM_BL_PWM  
{REG_PIN_EXTINT10,                	BITS_AF(3)},
{REG_GROUP_PIN_EXTINT10,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//NC
{REG_PIN_EXTINT9,                 	BITS_AF(3)},
{REG_GROUP_PIN_EXTINT9,           	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//GPIO31_AF_EN 

//G5
{REG_PIN_EXTINT11,                	BITS_AF(3)},
{REG_GROUP_PIN_EXTINT11,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_POC|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//NC
{REG_PIN_EXTINT7,                 	BITS_AF(3)},
{REG_GROUP_PIN_EXTINT7,           	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//SIM0_DET
{REG_PIN_EXTINT8,                 	BITS_AF(3)},
{REG_GROUP_PIN_EXTINT8,           	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//SIM1_DET

//G8
{REG_PIN_U0TXD,                		BITS_AF(0)},
{REG_GROUP_PIN_U0TXD,          		BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_POC|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//BB_U0TXD
{REG_PIN_U0RXD,                		BITS_AF(0)},
{REG_GROUP_PIN_U0RXD,         		BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPU|BIT_SLP_WPU|BIT_SLP_IE},//BB_U0RXD
{REG_PIN_U0CTS,                		BITS_AF(0)},
{REG_GROUP_PIN_U0CTS,          		BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPU|BIT_SLP_WPU|BIT_SLP_IE},//BB_U0CTS
{REG_PIN_U0RTS,                		BITS_AF(0)},
{REG_GROUP_PIN_U0RTS,          		BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPU|BIT_SLP_Z},//BB_U0RTS
{REG_PIN_IIS0DI,                	BITS_AF(0)},
{REG_GROUP_PIN_IIS0DI,          	BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_IE},//BT_PCM_OUT  
{REG_PIN_IIS0DO,                	BITS_AF(0)},
{REG_GROUP_PIN_IIS0DO,          	BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//BT_PCM_IN   
{REG_PIN_IIS0CLK,                	BITS_AF(0)},
{REG_GROUP_PIN_IIS0CLK,          	BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//BT_PCM_CLK  
{REG_PIN_IIS0LRCK,                	BITS_AF(0)},
{REG_GROUP_PIN_IIS0LRCK,          	BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//BT_PCM_SYNC  
{REG_PIN_CLK_AUX0,                	BITS_AF(0)},
{REG_GROUP_PIN_CLK_AUX0,          	BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//CON_32K_IN
{REG_PIN_RFCTL19,                	BITS_AF(1)},
{REG_GROUP_PIN_RFCTL19,          	BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_WPU|BIT_SLP_WPU|BIT_SLP_IE},//WB_WCI_2_TXD  
{REG_PIN_RFCTL18,                	BITS_AF(1)},
{REG_GROUP_PIN_RFCTL18,          	BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//WB_WCI_2_RXD  
{REG_PIN_WIFI_COEXIST,              BITS_AF(3)},
{REG_GROUP_PIN_WIFI_COEXIST,        BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//NC
{REG_PIN_BEIDOU_COEXIST,            BITS_AF(3)},
{REG_GROUP_PIN_BEIDOU_COEXIST,      BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//NC
{REG_PIN_MTCK_ARM,                	BITS_AF(3)},
{REG_GROUP_PIN_MTCK_ARM,          	BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//FP_LDO_EN
{REG_PIN_MTMS_ARM,                	BITS_AF(0)},
{REG_GROUP_PIN_MTMS_ARM,          	BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_WPU|BIT_SLP_WPD|BIT_SLP_Z},//MTMS
{REG_PIN_MTRST_N_ARM,               BITS_AF(0)},
{REG_GROUP_PIN_MTRST_N_ARM,         BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_WPU|BIT_SLP_WPD|BIT_SLP_Z},//MTRSTN
{REG_PIN_MTDO_ARM,                	BITS_AF(0)},
{REG_GROUP_PIN_MTDO_ARM,          	BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//MTDO
{REG_PIN_MTDI_ARM,                	BITS_AF(0)},
{REG_GROUP_PIN_MTDI_ARM,          	BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_WPU|BIT_SLP_WPD|BIT_SLP_Z},//MTDI
{REG_PIN_U3TXD,                		BITS_AF(0)},
//{REG_GROUP_PIN_U3TXD,          		BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//GPS_U0RXD
{REG_GROUP_PIN_U3TXD,                  BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_PIN_ISO_VALUE|BIT_SLP_NUL|BIT_SLP_OE},//GPS_U0RXD139 
{REG_PIN_U3RXD,                		BITS_AF(0)},
{REG_GROUP_PIN_U3RXD,          		BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPU|BIT_SLP_WPU|BIT_SLP_IE},//GPS_U0TXD
{REG_PIN_U3CTS,                		BITS_AF(0)},
{REG_GROUP_PIN_U3CTS,          		BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPU|BIT_SLP_WPU|BIT_SLP_IE},//GPS_U0RTS
{REG_PIN_U3RTS,                		BITS_AF(0)},
{REG_GROUP_PIN_U3RTS,          		BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPU|BIT_SLP_Z},//GPS_U0CTS

//G9
{REG_PIN_CMPD1,                		BITS_AF(3)},
{REG_GROUP_PIN_CMPD1,          		BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_POC|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//CAM_PWDN1 
{REG_PIN_CMPD0,                		BITS_AF(3)},
{REG_GROUP_PIN_CMPD0,          		BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//CAM_PWDN0 
{REG_PIN_CMRST1,                	BITS_AF(3)},
{REG_GROUP_PIN_CMRST1,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//CAM_RST1 
{REG_PIN_CMRST0,                	BITS_AF(3)},
{REG_GROUP_PIN_CMRST0,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//CAM_RST0 
{REG_PIN_CMMCLK1,                	BITS_AF(0)},
{REG_GROUP_PIN_CMMCLK1,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//CAM_MCLK1 
{REG_PIN_CMMCLK,                	BITS_AF(0)},
{REG_GROUP_PIN_CMMCLK,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//CAM_MCLK0  
{REG_PIN_SDA0,                		BITS_AF(0)},
{REG_GROUP_PIN_SDA0,          		BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPUS|BIT_SLP_WPU|BIT_SLP_Z},//I2C0_SDA  
{REG_PIN_SCL0,                		BITS_AF(0)},
{REG_GROUP_PIN_SCL0,          		BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPUS|BIT_SLP_WPU|BIT_SLP_Z},//I2C0_SCL   

//G10
{REG_PIN_RFSEN0,                	BITS_AF(0)},
{REG_GROUP_PIN_RFSEN0,          	BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_POC|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//PCC_RFSEN
{REG_PIN_RFSCK0,                	BITS_AF(0)},
{REG_GROUP_PIN_RFSCK0,          	BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//PCC_RFSCK
{REG_PIN_RFSDA0,                	BITS_AF(0)},
{REG_GROUP_PIN_RFSDA0,          	BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//PCC_RFSDA
{REG_PIN_RFSEN1,                	BITS_AF(0)},
{REG_GROUP_PIN_RFSEN1,          	BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//SCC_RFSEN
{REG_PIN_RFSCK1,                	BITS_AF(0)},
{REG_GROUP_PIN_RFSCK1,          	BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//SCC_RFSCK
{REG_PIN_RFSDA1,                	BITS_AF(0)},
{REG_GROUP_PIN_RFSDA1,          	BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//SCC_RFSDA
{REG_PIN_RFFE0_SDA,                 BITS_AF(0)},
{REG_GROUP_PIN_RFFE0_SDA,           BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//PCC_RFFE_SDA0
{REG_PIN_RFFE0_SCK,                	BITS_AF(0)},
{REG_GROUP_PIN_RFFE0_SCK,          	BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//PCC_RFFE_SCK0
{REG_PIN_RFFE1_SDA,                	BITS_AF(0)},
{REG_GROUP_PIN_RFFE1_SDA,          	BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//SCC_RFFE_SDA0
{REG_PIN_RFFE1_SCK,                	BITS_AF(0)},
{REG_GROUP_PIN_RFFE1_SCK,          	BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//SCC_RFFE_SCK0
{REG_PIN_RF_LVDS0_DAC_ON,           BITS_AF(3)},
{REG_GROUP_PIN_RF_LVDS0_DAC_ON,     BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//NC
{REG_PIN_RF_LVDS0_ADC_ON,           BITS_AF(3)},
{REG_GROUP_PIN_RF_LVDS0_ADC_ON,     BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//NC
{REG_PIN_RFCTL0,                	BITS_AF(3)},
{REG_GROUP_PIN_RFCTL0,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//CAM_PWDN2
{REG_PIN_RFCTL1,                	BITS_AF(3)},
{REG_GROUP_PIN_RFCTL1,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//VDDGPU_EN
{REG_PIN_RFCTL2,                	BITS_AF(3)},
{REG_GROUP_PIN_RFCTL2,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//CAM_RST2
{REG_PIN_RFCTL3,                	BITS_AF(0)},
{REG_GROUP_PIN_RFCTL3,          	BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//NC
{REG_PIN_RFCTL4,                	BITS_AF(0)},
{REG_GROUP_PIN_RFCTL4,          	BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//NC
{REG_PIN_RFCTL5,                	BITS_AF(0)},
{REG_GROUP_PIN_RFCTL5,          	BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//NC
{REG_PIN_RFCTL6,                	BITS_AF(0)},
{REG_GROUP_PIN_RFCTL6,          	BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//RFCTL6
{REG_PIN_RFCTL7,                	BITS_AF(0)},
{REG_GROUP_PIN_RFCTL7,          	BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//RFCTL7
{REG_PIN_RFCTL8,                	BITS_AF(0)},
{REG_GROUP_PIN_RFCTL8,          	BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//RFCTL8
{REG_PIN_RFCTL9,                	BITS_AF(0)},
{REG_GROUP_PIN_RFCTL9,          	BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//NC
{REG_PIN_RFCTL10,                	BITS_AF(3)},
{REG_GROUP_PIN_RFCTL10,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//MIPI_SWITCH_SEL
{REG_PIN_RFCTL11,                	BITS_AF(3)},
{REG_GROUP_PIN_RFCTL11,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//MIPI_SWITCH_EN
{REG_PIN_RFCTL12,                	BITS_AF(3)},
{REG_GROUP_PIN_RFCTL12,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//WB_RX_REQ            Marlin GPIO2 not used,BB Input
{REG_PIN_RFCTL13,                	BITS_AF(3)},
{REG_GROUP_PIN_RFCTL13,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//NC
{REG_PIN_RFCTL14,                	BITS_AF(3)},
{REG_GROUP_PIN_RFCTL14,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_IE},//AG_INT0////to be confirm
{REG_PIN_RFCTL15,                	BITS_AF(3)},
{REG_GROUP_PIN_RFCTL15,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//NC
{REG_PIN_RFCTL16,                	BITS_AF(3)},
{REG_GROUP_PIN_RFCTL16,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//CAMERA_FLASH_EN0
{REG_PIN_RFCTL17,                	BITS_AF(3)},
{REG_GROUP_PIN_RFCTL17,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//CAMERA_FLASH_EN1

//G12
{REG_PIN_U4TXD,                		BITS_AF(3)},
{REG_GROUP_PIN_U4TXD,          		BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_POC|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//AUDIO_PA_EN
{REG_PIN_U4RXD,                		BITS_AF(3)},
{REG_GROUP_PIN_U4RXD,          		BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//LCM_VLED_EN
{REG_PIN_U2TXD,                		BITS_AF(0)},
{REG_GROUP_PIN_U2TXD,          		BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//BB_U2TXD
{REG_PIN_U2RXD,                		BITS_AF(0)},
{REG_GROUP_PIN_U2RXD,          		BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPU|BIT_SLP_WPU|BIT_SLP_IE},//BB_U2RXD
{REG_PIN_U1TXD,                		BITS_AF(0)},
{REG_GROUP_PIN_U1TXD,          		BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//BB_U1TXD
{REG_PIN_U1RXD,                		BITS_AF(0)},
{REG_GROUP_PIN_U1RXD,          		BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPU|BIT_SLP_WPU|BIT_SLP_IE},//BB_U1RXD
{REG_PIN_SDA4,                		BITS_AF(0)},
{REG_GROUP_PIN_SDA4,          		BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPUS|BIT_SLP_WPU|BIT_SLP_Z},//I2C4_SDA   
{REG_PIN_SCL4,                		BITS_AF(0)},
{REG_GROUP_PIN_SCL4,          		BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPUS|BIT_SLP_WPU|BIT_SLP_Z},//I2C4_SCL   
{REG_PIN_SCL2,                		BITS_AF(0)},
{REG_GROUP_PIN_SCL2,          		BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_WPUS2|BIT_SLP_WPU|BIT_SLP_Z},//I2C2_SCL
{REG_PIN_SDA2,                		BITS_AF(0)},
{REG_GROUP_PIN_SDA2,          		BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_WPUS2|BIT_SLP_WPU|BIT_SLP_Z},//I2C2_SDA
{REG_PIN_IIS3DI,                	BITS_AF(3)},
{REG_GROUP_PIN_IIS3DI,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//BOARD_ID0
{REG_PIN_IIS3DO,                	BITS_AF(3)},
{REG_GROUP_PIN_IIS3DO,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//BOARD_ID1
{REG_PIN_IIS3CLK,                	BITS_AF(3)},
{REG_GROUP_PIN_IIS3CLK,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//NC
{REG_PIN_IIS3LRCK,                	BITS_AF(3)},
{REG_GROUP_PIN_IIS3LRCK,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//NC 
{REG_PIN_IIS1DI,                	BITS_AF(3)},
{REG_GROUP_PIN_IIS1DI,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPU|BIT_SLP_WPU|BIT_SLP_IE},//PROX_INT///to be confirm/
{REG_PIN_IIS1DO,                	BITS_AF(3)},
{REG_GROUP_PIN_IIS1DO,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//FTID_RSTN
{REG_PIN_IIS1CLK,                	BITS_AF(3)},
{REG_GROUP_PIN_IIS1CLK,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//NC
{REG_PIN_IIS1LRCK,                	BITS_AF(3)},
{REG_GROUP_PIN_IIS1LRCK,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//WB_INT        When Marlin2 Wake up provide INT to BB
{REG_PIN_SPI0_CSN,                	BITS_AF(0)},
{REG_GROUP_PIN_SPI0_CSN,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//FTID_SPI_CS
{REG_PIN_SPI0_DO,                	BITS_AF(0)},
{REG_GROUP_PIN_SPI0_DO,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//FTID_SPI_DO
{REG_PIN_SPI0_DI,                	BITS_AF(0)},
{REG_GROUP_PIN_SPI0_DI,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//FTID_SPI_DI
{REG_PIN_SPI0_CLK,                	BITS_AF(0)},
{REG_GROUP_PIN_SPI0_CLK,          	BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//FTID_SPI_CLK


// SPRD 
//G1
{REG_PIN_SD0_D0,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_SD0_D0,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(6)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//TF_SD0_D0
{REG_PIN_SD0_D1,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_SD0_D1,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(6)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//TF_SD0_D1
{REG_PIN_SD0_CLK0,                	BITS_PIN_AF(0)},
{REG_GROUP_PIN_SD0_CLK0,          	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(6)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//TF_SD0_CLK0
{REG_PIN_SD0_CMD,                	BITS_PIN_AF(0)},
{REG_GROUP_PIN_SD0_CMD,          	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(6)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//TF_SD0_CMD
{REG_PIN_SD0_D2,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_SD0_D2,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(6)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//TF_SD0_SD2
{REG_PIN_SD0_D3,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_SD0_D3,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(6)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//TF_SD0_SD3

//G4
{REG_PIN_EMMC_CLK,                  BITS_PIN_AF(0)},
{REG_GROUP_PIN_EMMC_CLK,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//EMMC_CLK
{REG_PIN_EMMC_RSTB,                 BITS_PIN_AF(0)}, 
{REG_GROUP_PIN_EMMC_RSTB,           BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_ISO_VALUE|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//EMMC_RST
{REG_PIN_EMMC_CMD,                  BITS_PIN_AF(0)},
{REG_GROUP_PIN_EMMC_CMD,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(7)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//EMMC_CMD
{REG_PIN_EMMC_D0,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_EMMC_D0,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(7)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//EMMC_D0
{REG_PIN_EMMC_D1,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_EMMC_D1,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(7)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//EMMC_D1
{REG_PIN_EMMC_D2,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_EMMC_D2,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(7)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//EMMC_D2
{REG_PIN_EMMC_D3,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_EMMC_D3,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(7)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//EMMC_D3
{REG_PIN_EMMC_D4,                 	BITS_PIN_AF(0)},
{REG_GROUP_PIN_EMMC_D4,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(7)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//EMMC_D4
{REG_PIN_EMMC_D5,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_EMMC_D5,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(7)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//EMMC_D5
{REG_PIN_EMMC_D6,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_EMMC_D6,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(7)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//EMMC_D6
{REG_PIN_EMMC_D7,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_EMMC_D7,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(7)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//EMMC_D7
{REG_PIN_EMMC_STROBE,               BITS_PIN_AF(0)},
{REG_GROUP_PIN_EMMC_STROBE,         BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_IE},//EMMC_RCLK

//G6
{REG_PIN_SD1_CMD,                   BITS_PIN_AF(0)},
{REG_GROUP_PIN_SD1_CMD,             BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//WF_SD1_CMD  
{REG_PIN_SD1_D0,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_SD1_D0,            	BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//WF_SD1_D0 
{REG_PIN_SD1_D1,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_SD1_D1,            	BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//WF_SD1_D1
{REG_PIN_SD1_CLK,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_SD1_CLK,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(5)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//WF_SD1_CLK
{REG_PIN_SD1_D2,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_SD1_D2,            	BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//WF_SD1_D2
{REG_PIN_SD1_D3,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_SD1_D3,            	BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//WF_SD1_D3

//G7
{REG_PIN_KEYOUT0,                  	BITS_PIN_AF(3)},
{REG_GROUP_PIN_KEYOUT0,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_ISO_VALUE|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//WB_RST       
{REG_PIN_KEYOUT1,                  	BITS_PIN_AF(3)},
{REG_GROUP_PIN_KEYOUT1,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_ISO_VALUE|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//WB_CHIP_EN   
{REG_PIN_KEYOUT2,                  	BITS_PIN_AF(3)},
{REG_GROUP_PIN_KEYOUT2,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_IE},//WB_TX_REQ   From Marlin2 GPIO1, WB Wakeup BB, High Active
{REG_PIN_KEYIN0,                  	BITS_PIN_AF(1)},
{REG_GROUP_PIN_KEYIN0,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN0
{REG_PIN_KEYIN1,                  	BITS_PIN_AF(1)},
{REG_GROUP_PIN_KEYIN1,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN1
{REG_PIN_KEYIN2,                  	BITS_PIN_AF(1)},
{REG_GROUP_PIN_KEYIN2,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//USBID_CRTL
{REG_PIN_SDA1,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_SDA1,            	BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_Z},//CTP_SDA
{REG_PIN_SCL1,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_SCL1,            	BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_Z},//CTP_SCL
{REG_PIN_EXTINT1,                  	BITS_PIN_AF(3)},
{REG_GROUP_PIN_EXTINT1,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//CTP_INT
{REG_PIN_EXTINT0,                  	BITS_PIN_AF(3)},
{REG_GROUP_PIN_EXTINT0,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CTP_RST
{REG_PIN_EXTINT12,                  BITS_PIN_AF(0)},
{REG_GROUP_PIN_EXTINT12,            BIT_PIN_SLP_NONE|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_IE},//FTID_INT
{REG_PIN_EXTINT15,                  BITS_PIN_AF(3)},
{REG_GROUP_PIN_EXTINT15,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC

//G11
{REG_PIN_SD2_CMD,                  	BITS_PIN_AF(3)},
{REG_GROUP_PIN_SD2_CMD,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SD2_D0,                  	BITS_PIN_AF(3)},
{REG_GROUP_PIN_SD2_D0,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SD2_D1,                  	BITS_PIN_AF(3)},
{REG_GROUP_PIN_SD2_D1,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SD2_CLK,                  	BITS_PIN_AF(3)},
{REG_GROUP_PIN_SD2_CLK,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SD2_D2,                  	BITS_PIN_AF(3)},
{REG_GROUP_PIN_SD2_D2,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SD2_D3,                  	BITS_PIN_AF(3)},
{REG_GROUP_PIN_SD2_D3,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC

//G13
{REG_PIN_SIMCLK2,                  	BITS_PIN_AF(1)},
{REG_GROUP_PIN_SIMCLK2,            	BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//I2C3_SCL
{REG_PIN_SIMDA2,                  	BITS_PIN_AF(1)},
{REG_GROUP_PIN_SIMDA2,            	BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//I2C3_SDA
{REG_PIN_SIMRST2,                  	BITS_PIN_AF(3)},
{REG_GROUP_PIN_SIMRST2,            	BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SIMCLK1,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_SIMCLK1,            	BIT_PIN_SLP_PUBCP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SIM1_CLK
{REG_PIN_SIMDA1,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_SIMDA1,            	BIT_PIN_SLP_PUBCP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//SIM1_DA
{REG_PIN_SIMRST1,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_SIMRST1,            	BIT_PIN_SLP_PUBCP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SIM1_RST
{REG_PIN_SIMCLK0,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_SIMCLK0,            	BIT_PIN_SLP_PUBCP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SIM0_CLK
{REG_PIN_SIMDA0,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_SIMDA0,            	BIT_PIN_SLP_PUBCP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//SIM0_DA
{REG_PIN_SIMRST0,                  	BITS_PIN_AF(0)},
{REG_GROUP_PIN_SIMRST0,            	BIT_PIN_SLP_PUBCP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SIM0_RST
};



/*here is the adie pinmap such as 2731*/
static pinmap_t adie_pinmap[]={
{REG_PIN_ANA_EXT_XTL_EN0,		BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BIT_ANA_PIN_SLP_IE},//NC
{REG_PIN_ANA_EXT_XTL_EN1,		BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BIT_ANA_PIN_SLP_IE},//WB_CLK_REQ  From Marlin2 to BB provide 26M
{REG_PIN_ANA_EXT_XTL_EN2,		BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BIT_ANA_PIN_SLP_IE},//XTL_BUF_EN1
{REG_PIN_ANA_EXT_XTL_EN3,		BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BIT_ANA_PIN_SLP_IE},//NC    
};

int  pin_init(void)
{
	int i;
	for (i = 0; i < sizeof(pinmap)/sizeof(pinmap[0]); i++) {
		__raw_writel(pinmap[i].val, pinmap[i].reg);
	}

	for (i = 0; i < sizeof(adie_pinmap)/sizeof(adie_pinmap[0]); i++) {
		sci_adi_set(CTL_ANA_PIN_BASE + adie_pinmap[i].reg, adie_pinmap[i].val);
	}

	return 0;
}


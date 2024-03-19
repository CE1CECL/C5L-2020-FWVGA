/*
 * Copyright (C) 2016-2018 Spreadtrum Communications Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __PCIE_DRV_H__
#define __PCIE_DRV_H__

#include <linux/pci.h>
#include <misc/wcn_bus.h>

#define DRVER_NAME      "wcn_pcie"

/* Synopsis PCIE configuration registers */

/* For Region control 2 */
#define REGION_EN	BIT(31)
/*
 * 0: Address Match Mode. The iATU operates using addresses as in the outbound
 * direction. The Region Base and Limit Registers must be setup.
 *
 * 1:BAR Match Mode. BAR matching is used. The "BAR Number" field is relevant.
 * Not used for RC.
 */
#define MATCH_MODE		BIT(30)
#define ADDR_MATCH_MODE		~BIT(30)
#define BAR_MATCH_MODE		BIT(30)
#define BAR_NUM			(BIT(10) | BIT(9) | BIT(8))
#define BAR_0			BIT(8)
#define BAR_1			BIT(9)
#define BAR_2			(BIT(9) | BIT(8))
#define IATU_OFFSET_ADDR	0x10000
#define OBREG0_OFFSET_ADDR	(0x10000 + (0 * 0x200))
#define IBREG0_OFFSET_ADDR	(0x10000 + (0 * 0x200) + 0x100)
#define OBREG1_OFFSET_ADDR	(0x10000 + (1 * 0x200))
#define IBREG1_OFFSET_ADDR	(0x10000 + (1 * 0x200) + 0x100)
/* Parameters for the waiting for iATU enabled routine */
#define LINK_WAIT_MAX_IATU_RETRIES	5
#define LINK_WAIT_IATU			9
#define PCIE_ATU_ENABLE			(0x1 << 31)
#define PCIE_ATU_BAR_MODE_ENABLE	(0x1 << 30)

#define BUS_REMOVE_CARD_VAL 0x8000
#define WCN_CARD_EXIST(xmit) \
	(atomic_read(xmit) < BUS_REMOVE_CARD_VAL)

struct bar_info {
	resource_size_t mmio_start;
	resource_size_t mmio_end;
	resource_size_t mmio_len;
	unsigned long mmio_flags;
	unsigned char *mem;
	unsigned char *vmem;
};

struct dma_buf {
	unsigned long vir;
	unsigned long phy;
	int size;
};

struct wcn_pcie_info {
	struct pci_dev *dev;
	struct pci_saved_state *saved_state;
	int legacy_en;
	int msi_en;
	int msix_en;
	int in_use;
	int irq;
	int irq_num;
	int irq_en;
	int bar_num;
	struct bar_info bar[8];
	struct msix_entry msix[100];
	/* board info */
	unsigned char revision;
	unsigned char irq_pin;
	unsigned char irq_line;
	unsigned short sub_vendor_id;
	unsigned short sub_system_id;
	unsigned short vendor_id;
	unsigned short device_id;
	unsigned int card_dump_flag;
	struct char_drv_info *p_char;
	enum wcn_bus_state pci_status;
	struct completion scan_done;
	struct completion remove_done;
	atomic_t xmit_cnt;
	atomic_t edma_ready;
};

struct inbound_reg {
	unsigned int type;/* region contril 1 ;0:mem, 2:i/o 4:cfg */
	unsigned int en;/* region contril 2 [10:8]:BAR_NUM, */
	unsigned int lower_base_addr;
	unsigned int upper_base_addr;
	unsigned int limit;
	unsigned int lower_target_addr;
	unsigned int upper_target_addr;
} __packed;

struct outbound_reg {
	unsigned int type;
	unsigned int en;
	unsigned int lower_base_addr;
	unsigned int upper_base_addr;
	unsigned int limit;
	unsigned int lower_target_addr;
	unsigned int upper_target_addr;
} __packed;
int pcie_bar_write(struct wcn_pcie_info *priv, int bar, int offset, void *buf,
		   int len);
int pcie_bar_read(struct wcn_pcie_info *priv, int bar, int offset, void *buf,
		  int len);
char *pcie_bar_vmem(struct wcn_pcie_info *priv, int bar);
int dmalloc(struct wcn_pcie_info *priv, struct dma_buf *dm, int size);
int dmfree(struct wcn_pcie_info *priv, struct dma_buf *dm);
unsigned char *ibreg_base(struct wcn_pcie_info *priv, char region);
unsigned char *obreg_base(struct wcn_pcie_info *priv, char region);
int pcie_config_read(struct wcn_pcie_info *priv, int offset, char *buf,
		     int len);
int sprd_pcie_bar_map(struct wcn_pcie_info *priv, int bar,
		      unsigned int addr, char region);
int sprd_pcie_mem_write(unsigned int addr, void *buf, unsigned int len);
int sprd_pcie_mem_read(unsigned int addr, void *buf, unsigned int len);
int sprd_pcie_update_bits(unsigned int reg, unsigned int mask,
			  unsigned int val);
struct wcn_pcie_info *get_wcn_device_info(void);
int wcn_pcie_get_bus_status(void);
void sprd_pcie_set_carddump_status(unsigned int flag);
unsigned int sprd_pcie_get_carddump_status(void);
int sprd_pcie_scan_card(void *wcn_dev);
void sprd_pcie_register_scan_notify(void *func);
void sprd_pcie_remove_card(void *wcn_dev);
u32 sprd_pcie_read_reg32(struct wcn_pcie_info *priv, int offset);
void sprd_pcie_write_reg32(struct wcn_pcie_info *priv, u32 reg_offset,
			   u32 value);
int wcn_get_edma_status(void);
#endif

/*
 *  linux/drivers/mmc/host/msmsdcc.h - QCT MSM7K SDC Controller
 *
 *  Copyright (C) 2008 Google, All Rights Reserved.
 *  Copyright (c) 2009, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * - Based on mmci.h
 */

#ifndef _MSM_SDCC_H
#define _MSM_SDCC_H

#define MSMSDCC_CRCI_SDC1	6
#define MSMSDCC_CRCI_SDC2	7
#define MSMSDCC_CRCI_SDC3	12
#define MSMSDCC_CRCI_SDC4	13

#define MMCIPOWER		0x000
#define MCI_PWR_OFF		0x00
#define MCI_PWR_UP		0x02
#define MCI_PWR_ON		0x03
#define MCI_OD			(1 << 6)

#define MMCICLOCK		0x004
#define MCI_CLK_ENABLE		(1 << 8)
#define MCI_CLK_PWRSAVE		(1 << 9)
#define MCI_CLK_WIDEBUS_1	(0 << 10)
#define MCI_CLK_WIDEBUS_4	(2 << 10)
#define MCI_CLK_WIDEBUS_8	(3 << 10)
#define MCI_CLK_FLOWENA		(1 << 12)
#define MCI_CLK_INVERTOUT	(1 << 13)
#define MCI_CLK_SELECTIN	(1 << 15)

#define MMCIARGUMENT		0x008
#define MMCICOMMAND		0x00c
#define MCI_CPSM_RESPONSE	(1 << 6)
#define MCI_CPSM_LONGRSP	(1 << 7)
#define MCI_CPSM_INTERRUPT	(1 << 8)
#define MCI_CPSM_PENDING	(1 << 9)
#define MCI_CPSM_ENABLE		(1 << 10)
#define MCI_CPSM_PROGENA	(1 << 11)
#define MCI_CSPM_DATCMD		(1 << 12)
#define MCI_CSPM_MCIABORT	(1 << 13)
#define MCI_CSPM_CCSENABLE	(1 << 14)
#define MCI_CSPM_CCSDISABLE	(1 << 15)


#define MMCIRESPCMD		0x010
#define MMCIRESPONSE0		0x014
#define MMCIRESPONSE1		0x018
#define MMCIRESPONSE2		0x01c
#define MMCIRESPONSE3		0x020
#define MMCIDATATIMER		0x024
#define MMCIDATALENGTH		0x028

#define MMCIDATACTRL		0x02c
#define MCI_DPSM_ENABLE		(1 << 0)
#define MCI_DPSM_DIRECTION	(1 << 1)
#define MCI_DPSM_MODE		(1 << 2)
#define MCI_DPSM_DMAENABLE	(1 << 3)

#define MMCIDATACNT		0x030
#define MMCISTATUS		0x034
#define MCI_CMDCRCFAIL		(1 << 0)
#define MCI_DATACRCFAIL		(1 << 1)
#define MCI_CMDTIMEOUT		(1 << 2)
#define MCI_DATATIMEOUT		(1 << 3)
#define MCI_TXUNDERRUN		(1 << 4)
#define MCI_RXOVERRUN		(1 << 5)
#define MCI_CMDRESPEND		(1 << 6)
#define MCI_CMDSENT		(1 << 7)
#define MCI_DATAEND		(1 << 8)
#define MCI_DATABLOCKEND	(1 << 10)
#define MCI_CMDACTIVE		(1 << 11)
#define MCI_TXACTIVE		(1 << 12)
#define MCI_RXACTIVE		(1 << 13)
#define MCI_TXFIFOHALFEMPTY	(1 << 14)
#define MCI_RXFIFOHALFFULL	(1 << 15)
#define MCI_TXFIFOFULL		(1 << 16)
#define MCI_RXFIFOFULL		(1 << 17)
#define MCI_TXFIFOEMPTY		(1 << 18)
#define MCI_RXFIFOEMPTY		(1 << 19)
#define MCI_TXDATAAVLBL		(1 << 20)
#define MCI_RXDATAAVLBL		(1 << 21)
#define MCI_SDIOINTR		(1 << 22)
#define MCI_PROGDONE		(1 << 23)
#define MCI_ATACMDCOMPL		(1 << 24)
#define MCI_SDIOINTOPER		(1 << 25)
#define MCI_CCSTIMEOUT		(1 << 26)

#define MMCICLEAR		0x038
#define MCI_CMDCRCFAILCLR	(1 << 0)
#define MCI_DATACRCFAILCLR	(1 << 1)
#define MCI_CMDTIMEOUTCLR	(1 << 2)
#define MCI_DATATIMEOUTCLR	(1 << 3)
#define MCI_TXUNDERRUNCLR	(1 << 4)
#define MCI_RXOVERRUNCLR	(1 << 5)
#define MCI_CMDRESPENDCLR	(1 << 6)
#define MCI_CMDSENTCLR		(1 << 7)
#define MCI_DATAENDCLR		(1 << 8)
#define MCI_STARTBITERRCLR	(1 << 9)
#define MCI_DATABLOCKENDCLR	(1 << 10)

#define MCI_SDIOINTRCLR		(1 << 22)
#define MCI_PROGDONECLR		(1 << 23)
#define MCI_ATACMDCOMPLCLR	(1 << 24)
#ifdef CONFIG_HUAWEI_WIFI_SDCC
#define MCI_SDIOINTROPECLR	(1 << 25)
#endif
#define MCI_CCSTIMEOUTCLR 	(1 << 26)

#ifdef CONFIG_HUAWEI_WIFI_SDCC
#define msmsdcc_micro_opt		udelay
#define msmsdcc_milli_opt		mdelay
#define msmsdcc_unit_opt		msmsdcc_micro_opt
#define MCI_CLEAR_STATIC_MASK	\
	(MCI_CMDCRCFAILCLR|MCI_DATACRCFAILCLR|MCI_CMDTIMEOUTCLR|\
	MCI_DATATIMEOUTCLR|MCI_TXUNDERRUNCLR|MCI_RXOVERRUNCLR|  \
	MCI_CMDRESPENDCLR|MCI_CMDSENTCLR|MCI_DATAENDCLR|		  \
	MCI_STARTBITERRCLR|MCI_DATABLOCKENDCLR|MCI_SDIOINTRCLR|MCI_SDIOINTROPECLR| \
	MCI_PROGDONECLR|MCI_ATACMDCOMPLCLR|MCI_CCSTIMEOUTCLR)
#define msmsdcc_wait_status_reg()	msmsdcc_unit_opt(WAIT_STATUS_REG)
#define msmsdcc_wait_arg_reg()		msmsdcc_unit_opt(WAIT_ARG_REG)
#define msmsdcc_wait_cmd_reg()		msmsdcc_unit_opt(WAIT_CMD_REG)
#define msmsdcc_dummy_cmd52_arg_cfg()	{writel(0,base+MMCIARGUMENT);msmsdcc_wait_arg_reg();}
#define msmsdcc_dummy_cmd52_cmd_cfg()	{writel(52|MCI_CPSM_ENABLE|MCI_CPSM_RESPONSE|MCI_CPSM_PROGENA,base+MMCICOMMAND);msmsdcc_wait_cmd_reg();}
#define msmsdcc_dummy_cmd52_reg_cfg()	{msmsdcc_dummy_cmd52_arg_cfg();msmsdcc_dummy_cmd52_cmd_cfg();}
#else
#define MCI_CLEAR_STATIC_MASK	\
	(MCI_CMDCRCFAILCLR|MCI_DATACRCFAILCLR|MCI_CMDTIMEOUTCLR|\
	MCI_DATATIMEOUTCLR|MCI_TXUNDERRUNCLR|MCI_RXOVERRUNCLR|  \
	MCI_CMDRESPENDCLR|MCI_CMDSENTCLR|MCI_DATAENDCLR|	\
	MCI_STARTBITERRCLR|MCI_DATABLOCKENDCLR|MCI_SDIOINTRCLR| \
	MCI_PROGDONECLR|MCI_ATACMDCOMPLCLR|MCI_CCSTIMEOUTCLR)
#endif

#define MMCIMASK0		0x03c
#define MCI_CMDCRCFAILMASK	(1 << 0)
#define MCI_DATACRCFAILMASK	(1 << 1)
#define MCI_CMDTIMEOUTMASK	(1 << 2)
#define MCI_DATATIMEOUTMASK	(1 << 3)
#define MCI_TXUNDERRUNMASK	(1 << 4)
#define MCI_RXOVERRUNMASK	(1 << 5)
#define MCI_CMDRESPENDMASK	(1 << 6)
#define MCI_CMDSENTMASK		(1 << 7)
#define MCI_DATAENDMASK		(1 << 8)
#define MCI_DATABLOCKENDMASK	(1 << 10)
#define MCI_CMDACTIVEMASK	(1 << 11)
#define MCI_TXACTIVEMASK	(1 << 12)
#define MCI_RXACTIVEMASK	(1 << 13)
#define MCI_TXFIFOHALFEMPTYMASK	(1 << 14)
#define MCI_RXFIFOHALFFULLMASK	(1 << 15)
#define MCI_TXFIFOFULLMASK	(1 << 16)
#define MCI_RXFIFOFULLMASK	(1 << 17)
#define MCI_TXFIFOEMPTYMASK	(1 << 18)
#define MCI_RXFIFOEMPTYMASK	(1 << 19)
#define MCI_TXDATAAVLBLMASK	(1 << 20)
#define MCI_RXDATAAVLBLMASK	(1 << 21)
#define MCI_SDIOINTMASK		(1 << 22)
#define MCI_PROGDONEMASK	(1 << 23)
#define MCI_ATACMDCOMPLMASK	(1 << 24)
#define MCI_SDIOINTOPERMASK	(1 << 25)
#define MCI_CCSTIMEOUTMASK	(1 << 26)

#define MMCIMASK1		0x040
#define MMCIFIFOCNT		0x044
#define MCICCSTIMER		0x058

#define MMCIFIFO		0x080 /* to 0x0bc */

#define MCI_IRQENABLE	\
	(MCI_CMDCRCFAILMASK|MCI_DATACRCFAILMASK|MCI_CMDTIMEOUTMASK|	\
	MCI_DATATIMEOUTMASK|MCI_TXUNDERRUNMASK|MCI_RXOVERRUNMASK|	\
	MCI_CMDRESPENDMASK|MCI_CMDSENTMASK|MCI_DATAENDMASK)

/*
 * The size of the FIFO in bytes.
 */
#define MCI_FIFOSIZE	(16*4)

#define MCI_FIFOHALFSIZE (MCI_FIFOSIZE / 2)

#define NR_SG		32

struct clk;

struct msmsdcc_nc_dmadata {
	dmov_box	cmd[NR_SG];
	uint32_t	cmdptr;
};

struct msmsdcc_dma_data {
	struct msmsdcc_nc_dmadata	*nc;
	dma_addr_t			nc_busaddr;
	dma_addr_t			cmd_busaddr;
	dma_addr_t			cmdptr_busaddr;

	struct msm_dmov_cmd		hdr;
	enum dma_data_direction		dir;

	struct scatterlist		*sg;
	int				num_ents;

	int				channel;
	struct msmsdcc_host		*host;
	int				busy; /* Set if DM is busy */
	unsigned int 			result;
	struct msm_dmov_errdata 	*err;
};

struct msmsdcc_pio_data {
	struct scatterlist	*sg;
	unsigned int		sg_len;
	unsigned int		sg_off;
};

struct msmsdcc_curr_req {
	struct mmc_request	*mrq;
	struct mmc_command	*cmd;
	struct mmc_data		*data;
	unsigned int		xfer_size;	/* Total data size */
	unsigned int		xfer_remain;	/* Bytes remaining to send */
	unsigned int		data_xfered;	/* Bytes acked by BLKEND irq */
	int			got_dataend;
	int			got_datablkend;
	int			user_pages;
};

struct msmsdcc_stats {
	unsigned int reqs;
	unsigned int cmds;
	unsigned int cmdpoll_hits;
	unsigned int cmdpoll_misses;
};

struct msmsdcc_host {
	struct resource		*cmd_irqres;
	struct resource		*pio_irqres;
	struct resource		*memres;
	struct resource		*dmares;
	void __iomem		*base;
	int			pdev_id;
	unsigned int		stat_irq;

	struct msmsdcc_curr_req	curr;

	struct mmc_host		*mmc;
	struct clk		*clk;		/* main MMC bus clock */
	struct clk		*pclk;		/* SDCC peripheral bus clock */
	unsigned int		clks_on;	/* set if clocks are enabled */
	struct timer_list	command_timer;

	unsigned int		eject;		/* eject state */

	spinlock_t		lock;

	unsigned int		clk_rate;	/* Current clock rate */
	unsigned int		pclk_rate;

	u32			pwr;
	u32			saved_irq0mask;	/* MMCIMASK0 reg value */
	struct mmc_platform_data *plat;

	unsigned int		oldstat;

	struct msmsdcc_dma_data	dma;
#ifdef CONFIG_HUAWEI_WIFI_SDCC
	unsigned int		pre_cmd_with_data;
	unsigned int		mci_irqenable;
#endif
	struct msmsdcc_pio_data	pio;
	int			cmdpoll;
	struct msmsdcc_stats	stats;

#ifdef CONFIG_HAS_EARLYSUSPEND
	struct early_suspend early_suspend;
	int polling_enabled;
#endif

#ifdef CONFIG_MMC_MSM7X00A_RESUME_IN_WQ
	struct work_struct	resume_task;
#endif
	struct tasklet_struct 	dma_tlet;
	unsigned int prog_scan;
	unsigned int prog_enable;
};

#endif

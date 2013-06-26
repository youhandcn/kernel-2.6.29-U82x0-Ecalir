/*
 * Copyright (C) 2007 Google, Inc.
 * Copyright (c) 2008-2009, Code Aurora Forum. All rights reserved.
 * Author: Brian Swetland <swetland@google.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/platform_device.h>
#include <linux/gpio_event.h>

#include <asm/mach-types.h>

/*                                          c8600 keypad begin                                                                 */
static unsigned int keypad_row_gpios_c8600[] = { 35, 34, 33 };//driver
static unsigned int keypad_col_gpios_c8600[] = { 41, 40, 39 };//sensor
#undef  KEYMAP_INDEX
#define KEYMAP_INDEX(row, col) ((row)*ARRAY_SIZE(keypad_col_gpios_c8600) + (col))
static const unsigned short keypad_keymap_c8600[ARRAY_SIZE(keypad_col_gpios_c8600) *
					      ARRAY_SIZE(keypad_row_gpios_c8600)] = {
	[KEYMAP_INDEX(0, 0)] = KEY_SEND,   /* KEY_SEND 231 */ 
	[KEYMAP_INDEX(0, 1)] = 62,   /* ENDCALL 62 */ 
	[KEYMAP_INDEX(0, 2)] = KEY_VOLUMEUP,  /* KEY_VOLUMEUP 115 */ 
	[KEYMAP_INDEX(1, 0)] = KEY_MENU,  /* KEY_MENU  139  */ 
	[KEYMAP_INDEX(1, 1)] = 250,  /* KEY_BACKLIGHT 250 ,250 will be deleted in u8230 */
	[KEYMAP_INDEX(1, 2)] = KEY_VOLUMEDOWN,  /* KEY_VOLUMEDOWN 114 */ 
	[KEYMAP_INDEX(2, 0)] = 232,  /* DPAD_CENTER 232 */ 
	[KEYMAP_INDEX(2, 1)] = 249,  /* KEY_FOCUS  249   */ 
	[KEYMAP_INDEX(2, 2)] = KEY_CAMERA,  /* KEY_CAMERA 212 */
};

/*  keypad platform device information */
static struct gpio_event_matrix_info c8600_keypad_matrix_info = {
	.info.func	= gpio_event_matrix_func,
	.keymap		= keypad_keymap_c8600,
	.output_gpios	= keypad_row_gpios_c8600,
	.input_gpios	= keypad_col_gpios_c8600,
	.noutputs	= ARRAY_SIZE(keypad_row_gpios_c8600),
	.ninputs	= ARRAY_SIZE(keypad_col_gpios_c8600),
	.settle_time.tv.nsec = 40 * NSEC_PER_USEC,
	.poll_time.tv.nsec = 20 * NSEC_PER_MSEC,
	.flags		= GPIOKPF_LEVEL_TRIGGERED_IRQ | GPIOKPF_DRIVE_INACTIVE |
			  GPIOKPF_PRINT_UNMAPPED_KEYS | GPIOKPF_PRINT_MAPPED_KEYS
};

static struct gpio_event_info *c8600_keypad_info[] = {
	&c8600_keypad_matrix_info.info
};

static struct gpio_event_platform_data c8600_keypad_data = {
	.name		= "surf_keypad",
	.info		= c8600_keypad_info,
	.info_count	= ARRAY_SIZE(c8600_keypad_info)
};

struct platform_device keypad_device_c8600 = {
	.name	= GPIO_EVENT_DEV_NAME,
	.id	= -1,
	.dev	= {
		.platform_data	= &c8600_keypad_data,
	},
};
/*                                          c8600 keypad end                                                                 */

/*                                    u8100/u8110 keypad begin                                                                 */
static unsigned int keypad_row_gpios_u8100[] = { 35, 34, 33 };//driver
static unsigned int keypad_col_gpios_u8100[] = { 41, 40, 39, 38 };//sense
#undef  KEYMAP_INDEX
#define KEYMAP_INDEX(row, col) ((row)*ARRAY_SIZE(keypad_col_gpios_u8100) + (col))
static const unsigned short keypad_keymap_u8100[ARRAY_SIZE(keypad_col_gpios_u8100) *
					      ARRAY_SIZE(keypad_row_gpios_u8100)] = {
	[KEYMAP_INDEX(0, 0)] = KEY_SEND,   /* KEY_SEND 231 */ 
	[KEYMAP_INDEX(0, 1)] = KEY_DOWN,  /* KEY_DOWN 108   */ 
	[KEYMAP_INDEX(0, 2)] = 62,   /* ENDCALL 62 */ 
	[KEYMAP_INDEX(0, 3)] = KEY_VOLUMEUP,  /* KEY_VOLUMEUP 115  */ 

	[KEYMAP_INDEX(1, 0)] = KEY_LEFT,  /* KEY_LEFT 105  */ 
	[KEYMAP_INDEX(1, 1)] = 232,  /* DPAD_CENTER 232 */ 
	[KEYMAP_INDEX(1, 2)] = KEY_RIGHT,  /* KEY_RIGHT 106 */ 
	[KEYMAP_INDEX(1, 3)] = KEY_VOLUMEDOWN,  /* KEY_VOLUMEDOWN  114 */

	[KEYMAP_INDEX(2, 0)] = KEY_CAMERA,  /* KEY_CAMERA 212 */
	[KEYMAP_INDEX(2, 1)] = KEY_VOLUMEUP,  /* KEY_VOLUMEUP 115  */ 
	[KEYMAP_INDEX(2, 2)] = 0,  /* KEY_RESERVED */ 
	[KEYMAP_INDEX(2, 3)] = 0,  /* KEY_RESERVED */ 
};

/*  keypad platform device information */
static struct gpio_event_matrix_info u8100_keypad_matrix_info = {
	.info.func	= gpio_event_matrix_func,
	.keymap		= keypad_keymap_u8100,
	.output_gpios	= keypad_row_gpios_u8100,
	.input_gpios	= keypad_col_gpios_u8100,
	.noutputs	= ARRAY_SIZE(keypad_row_gpios_u8100),
	.ninputs	= ARRAY_SIZE(keypad_col_gpios_u8100),
	.settle_time.tv.nsec = 40 * NSEC_PER_USEC,
	.poll_time.tv.nsec = 20 * NSEC_PER_MSEC,
	.flags		= GPIOKPF_LEVEL_TRIGGERED_IRQ | GPIOKPF_DRIVE_INACTIVE |
			  GPIOKPF_PRINT_UNMAPPED_KEYS | GPIOKPF_PRINT_MAPPED_KEYS
};

static struct gpio_event_info *u8100_keypad_info[] = {
	&u8100_keypad_matrix_info.info
};

static struct gpio_event_platform_data u8100_keypad_data = {
	.name		= "surf_keypad",
	.info		= u8100_keypad_info,
	.info_count	= ARRAY_SIZE(u8100_keypad_info)
};

struct platform_device keypad_device_u8100 = {
	.name	= GPIO_EVENT_DEV_NAME,
	.id	= -1,
	.dev	= {
		.platform_data	= &u8100_keypad_data,
	},
};
/*                                     u8100/u8110 keypad end                                                                */

/*                                          u7610 keypad begin                                                                 */
static unsigned int keypad_row_gpios_u7610[] = { 35, 34, 33, 32 };//driver
static unsigned int keypad_col_gpios_u7610[] = { 41, 40 };//sense
#undef  KEYMAP_INDEX
#define KEYMAP_INDEX(row, col) ((row)*ARRAY_SIZE(keypad_col_gpios_u7610) + (col))
static const unsigned short keypad_keymap_u7610[ARRAY_SIZE(keypad_col_gpios_u7610) *
					      ARRAY_SIZE(keypad_row_gpios_u7610)] = {
	[KEYMAP_INDEX(0, 0)] = KEY_SEND,   /* KEY_SEND 231 */  
	[KEYMAP_INDEX(0, 1)] = 62,   /* ENDCALL 62 */ 

	[KEYMAP_INDEX(1, 0)] = KEY_VOLUMEUP,  /* KEY_VOLUMEUP 115 */ 
	[KEYMAP_INDEX(1, 1)] = KEY_VOLUMEDOWN,  /* KEY_VOLUMEDOWN  114  */ 

	[KEYMAP_INDEX(2, 0)] = 249,  /* KEY_FOCUS ,249 */
	[KEYMAP_INDEX(2, 1)] = KEY_CAMERA,  /* KEY_CAMERA 212 */ 

	[KEYMAP_INDEX(3, 0)] = 0,  /*  KEY_RESERVED */ 
	[KEYMAP_INDEX(3, 1)] = 232,  /* DPAD_CENTER 232 */ 
};

/*  keypad platform device information */
static struct gpio_event_matrix_info u7610_keypad_matrix_info = {
	.info.func	= gpio_event_matrix_func,
	.keymap		= keypad_keymap_u7610,
	.output_gpios	= keypad_row_gpios_u7610,
	.input_gpios	= keypad_col_gpios_u7610,
	.noutputs	= ARRAY_SIZE(keypad_row_gpios_u7610),
	.ninputs	= ARRAY_SIZE(keypad_col_gpios_u7610),
	.settle_time.tv.nsec = 40 * NSEC_PER_USEC,
	.poll_time.tv.nsec = 20 * NSEC_PER_MSEC,
	.flags		= GPIOKPF_LEVEL_TRIGGERED_IRQ | GPIOKPF_DRIVE_INACTIVE |
			  GPIOKPF_PRINT_UNMAPPED_KEYS | GPIOKPF_PRINT_MAPPED_KEYS
};

static struct gpio_event_info *u7610_keypad_info[] = {
	&u7610_keypad_matrix_info.info
};

static struct gpio_event_platform_data u7610_keypad_data = {
	.name		= "surf_keypad",
	.info		= u7610_keypad_info,
	.info_count	= ARRAY_SIZE(u7610_keypad_info)
};

struct platform_device keypad_device_u7610 = {
	.name	= GPIO_EVENT_DEV_NAME,
	.id	= -1,
	.dev	= {
		.platform_data	= &u7610_keypad_data,
	},
};
/*                                          u7610 keypad end                                                                 */


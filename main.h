/*
 * Soft:        Keepalived is a failover program for the LVS project
 *              <www.linuxvirtualserver.org>. It monitor & manipulate
 *              a loadbalanced server pool using multi-layer checks.
 *
 * Part:        Main program include file.
 *
 * Version:     $Id: main.h,v 0.6.4 2002/06/25 20:18:34 acassen Exp $
 *
 * Author:      Alexandre Cassen, <acassen@linux-vs.org>
 *
 *              This program is distributed in the hope that it will be useful,
 *              but WITHOUT ANY WARRANTY; without even the implied warranty of
 *              MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *              See the GNU General Public License for more details.
 *
 *              This program is free software; you can redistribute it and/or
 *              modify it under the terms of the GNU General Public License
 *              as published by the Free Software Foundation; either version
 *              2 of the License, or (at your option) any later version.
 */

#ifndef _MAIN_H
#define _MAIN_H

/* global includes */
#include <sys/stat.h>
#include <sys/wait.h>
#include <popt.h>

/* local includes */
#include "daemon.h"
#include "memory.h"
#include "parser.h"
#include "utils.h"
#include "pidfile.h"
#include "data.h"
#include "scheduler.h"
#include "ipwrapper.h"
#include "check_api.h"
#include "vrrp.h"
#include "vrrp_if.h"
#include "vrrp_netlink.h"

/* global var */
thread_master *master = NULL;
unsigned int debug;
unsigned long mem_allocated = 0;
data *conf_data;

/* extern prototypes */
#ifdef _WITH_LVS_
  extern void clear_ssl(SSL_DATA *ssl);
  extern int init_ssl_ctx(void);
#endif
extern void register_vrrp_thread(void);

/* Build version */
#define PROG    "Keepalived"

#define VERSION_CODE 0x000604
#define DATE_CODE    0x190602

#define KEEPALIVED_VERSION(version)	\
	(version >> 16) & 0xFF,		\
	(version >> 8) & 0xFF,		\
	version & 0xFF

#define VERSION_STRING PROG" v%d.%d.%d (%.2d/%.2d, 20%.2d)\n", \
		KEEPALIVED_VERSION(VERSION_CODE), \
		KEEPALIVED_VERSION(DATE_CODE)
#endif

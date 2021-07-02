/**
 * NEURON IIoT System for Industry 4.0
 * Copyright (C) 2020-2021 EMQ Technologies Co., Ltd All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 **/

#include <stdlib.h>
#include <stdio.h>

#include "neuron.h"

const neu_plugin_module_t neu_plugin_module;

struct neu_plugin {
	neu_plugin_common_t common;
};

static neu_plugin_t* sample_plugin_open(neu_adapter_t* adapter)
{
	neu_plugin_t* plugin;

	plugin = (neu_plugin_t*)malloc(sizeof(neu_plugin_t));
	if (plugin == NULL) {
		log_error("Failed to allocate plugin %s",
			   	neu_plugin_module.module_name);
		return NULL;
	}

	log_info("Success to create plugin: %s", neu_plugin_module.module_name);
	return plugin;
}

static int sample_plugin_close(neu_plugin_t* plugin)
{
	int rv = 0;

	free(plugin);
	log_info("Success to free plugin: %s", neu_plugin_module.module_name);
	return rv;
}

static int sample_plugin_init(neu_plugin_t* plugin)
{
	int rv = 0;

	log_info("Initialize plugin: %s", neu_plugin_module.module_name);
	return rv;
}

static int sample_plugin_uninit(neu_plugin_t* plugin)
{
	int rv = 0;

	log_info("Uninitialize plugin: %s", neu_plugin_module.module_name);
	return rv;
}

static int sample_plugin_config(neu_plugin_t* plugin, neu_config_t* configs)
{
	int rv = 0;

	log_info("config plugin: %s", neu_plugin_module.module_name);
	return rv;
}

static int sample_plugin_request(neu_plugin_t* plugin,
				   neu_request_t* req)
{
	int rv = 0;

	log_info("send request to plugin: %s", neu_plugin_module.module_name);
	return rv;
}

static int sample_plugin_event_reply(neu_adapter_t* adapter,
 					   neu_event_reply_t* reply)
{
	int rv = 0;

	log_info("reply event to plugin: %s", neu_plugin_module.module_name);
	return rv;
}

static const neu_plugin_intf_funs_t plugin_intf_funs = {
	.open   = sample_plugin_open,
	.close  = sample_plugin_close,
	.init   = sample_plugin_init,
	.uninit = sample_plugin_uninit,
	.config = sample_plugin_config,
	.request     = sample_plugin_request,
	.event_reply = sample_plugin_event_reply
};

static const char* const sample_plugin_descr =
		"A sample plugin for demonstrate how to write a neuron plugin";

const neu_plugin_module_t neu_plugin_module = {
	.version 	  = NEURON_PLUGIN_VER_1_0,
	.module_name  = "neuron-sample-plugin",
	.module_descr = sample_plugin_descr,
	.intf_funs    = &plugin_intf_funs
};


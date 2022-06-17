/**
 * NEURON IIoT System for Industry 4.0
 * Copyright (C) 2020-2022 EMQ Technologies Co., Ltd All rights reserved.
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

#ifndef NEURON_PLUGIN_MQTT_COMMAND_READ_WRITE
#define NEURON_PLUGIN_MQTT_COMMAND_READ_WRITE

#ifdef __cplusplus
extern "C" {
#endif

#include <neuron.h>

#include "common.h"

int command_rw_read_once_request(neu_plugin_t *plugin, neu_json_mqtt_t *mqtt,
                                 neu_json_read_req_t *req);

char *command_rw_read_once_response(neu_plugin_t *         plugin,
                                    neu_reqresp_head_t *   head,
                                    neu_resp_read_group_t *data, int format);

char *command_rw_read_periodic_response(neu_plugin_t *            plugin,
                                        neu_reqresp_trans_data_t *data,
                                        int                       format);

int command_rw_write_request(neu_plugin_t *plugin, neu_json_mqtt_t *mqtt,
                             neu_json_write_req_t *req);

char *command_rw_write_response(neu_plugin_t *plugin, neu_reqresp_head_t *head,
                                neu_resp_error_t *data);

#ifdef __cplusplus
}
#endif
#endif
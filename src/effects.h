/*
 * This file is part of mod-host.
 *
 * mod-host is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * mod-host is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with mod-host.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/*
************************************************************************************************************************
*
************************************************************************************************************************
*/

#ifndef EFFECTS_H
#define EFFECTS_H


/*
************************************************************************************************************************
*           INCLUDE FILES
************************************************************************************************************************
*/


/*
************************************************************************************************************************
*           DO NOT CHANGE THESE DEFINES
************************************************************************************************************************
*/

/* Errors definitions */
enum {
    SUCCESS = 0,
    ERR_INSTANCE_INVALID = -1,
    ERR_INSTANCE_ALREADY_EXISTS = -2,
    ERR_INSTANCE_NON_EXISTS = -3,

    ERR_LV2_INVALID_URI = -101,
    ERR_LILV_INSTANTIATION = -102,
    ERR_LV2_INVALID_PARAM_SYMBOL = -103,

    ERR_JACK_CLIENT_CREATION = -201,
    ERR_JACK_CLIENT_ACTIVATION = -202,
    ERR_JACK_CLIENT_DEACTIVATION = -203,
    ERR_JACK_PORT_REGISTER = -204,
    ERR_JACK_PORT_CONNECTION = -205,
    ERR_JACK_PORT_DISCONNECTION = -206,

    ERR_MEMORY_ALLOCATION = -301,
};


/*
************************************************************************************************************************
*           CONFIGURATION DEFINES
************************************************************************************************************************
*/

#define MAX_INSTANCES           10000

#define MOD_URI                 "http://portalmod.com/ns/mod"
#define MOD_URI_PREFIX          MOD_URI "/"

#define MOD__Session            MOD_URI_PREFIX "Session"
#define MOD__Connection         MOD_URI_PREFIX "Connection"
#define MOD__Instance           MOD_URI_PREFIX "Instance"
#define MOD__instance           MOD_URI_PREFIX "instance"
#define MOD__connection         MOD_URI_PREFIX "connection"
#define MOD__inInstance         MOD_URI_PREFIX "inInstance"
#define MOD__inPortSymbol       MOD_URI_PREFIX "inPortSymbol"
#define MOD__outInstance        MOD_URI_PREFIX "outInstance"
#define MOD__outPortSymbol      MOD_URI_PREFIX "outPortSymbol"

/*
************************************************************************************************************************
*           DATA TYPES
************************************************************************************************************************
*/


/*
************************************************************************************************************************
*           GLOBAL VARIABLES
************************************************************************************************************************
*/


/*
************************************************************************************************************************
*           MACRO'S
************************************************************************************************************************
*/


/*
************************************************************************************************************************
*           FUNCTION PROTOTYPES
************************************************************************************************************************
*/

int effects_init(void);
int effects_finish(void);
int effects_add(const char *uid, int instance);
int effects_remove(int effect_id);
int effects_preset(int effect_id, const char *label);
int effects_preset_save(int effect_id, const char *dir, const char *fname, const char *label, const char *uri);
int effects_session_save(const char *dir, const char *fname, const char *label);
int effects_connect(const char *portA, const char *portB);
int effects_disconnect(const char *portA, const char *portB);
int effects_set_parameter(int effect_id, const char *control_symbol, float value);
int effects_set_property(int effect_id, const char *label, const char *value);
int effects_get_parameter(int effect_id, const char *control_symbol, float *value);
int effects_monitor_parameter(int effect_id, const char *control_symbol, const char *op, float value);
int effects_bypass(int effect_id, int value);
int effects_get_parameter_symbols(int effect_id, char** symbols);
int effects_get_presets_labels(int effect_id, char **labels);
int effects_get_parameter_info(int effect_id, const char *control_symbol, float **range, const char **scale_points);
float effects_jack_cpu_load(void);

/*
************************************************************************************************************************
*           CONFIGURATION ERRORS
************************************************************************************************************************
*/


/*
************************************************************************************************************************
*           END HEADER
************************************************************************************************************************
*/

#endif

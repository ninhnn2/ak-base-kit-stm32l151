#ifndef __APP_DATA_H__
#define __APP_DATA_H__
#include <stdint.h>

#include "sys_boot.h"

#include "app.h"

#if defined (TASK_MBMASTER_EN)
#include "mbport.h"
#include "mbm.h"
#include "common/mbportlayer.h"
#endif

#if defined (TASK_BUZZER_EN)
#include "buzzer.h"
#endif

#include "sys_dbg.h"

/******************************************************************************
* IF Type
*******************************************************************************/
/** RF24 interface for modules
 * IF_TYPE_RF24_GW using to transfer data to gateway.
 * IF_TYPE_RF24_AC using to transfer data to air_condition module.
*/
#define IF_TYPE_RF24_MIN					(0)
#define IF_TYPE_RF24_GW						(0)
#define IF_TYPE_RF24_AC						(1)
#define IF_TYPE_RF24_MAX					(99)

#define IF_TYPE_RF24_ME						IF_TYPE_RF24_AC

/** APP interface, communication via socket interface
 *
 */
#define IF_TYPE_APP_MIN						(100)
#define IF_TYPE_APP_GW						(100)
#define IF_TYPE_APP_GI						(101)
#define IF_TYPE_APP_MAX						(119)

/** UART interface
 *
 */
#define IF_TYPE_UART_GW_MIN					(120)
#define IF_TYPE_UART_GW						(120)
#define IF_TYPE_UART_AC						(121)
#define IF_TYPE_UART_GW_MAX					(140)


#define RF24_ENCRYPT_DECRYPT_KEY_SIZE		16
extern uint8_t rf24_encrypt_decrypt_key[];

typedef struct {
	uint8_t is_power_on_reset;
} boot_app_share_data_t;


/******************************************************************************
* RS485-MODBUS
*******************************************************************************/
/* global setting type */
typedef struct t_ac_setting_info {
	uint32_t magic_number;

	uint32_t acc_buff_length;
	uint8_t acc_checksum;
	uint32_t udev_buff_length;
	uint8_t udev_checksum;
} __AK_PACKETED ac_setting_info_t;

/* define settings parametters */
#define AC_SETTING_MAGIC                    (0x1234ABCD)

#if defined (TASK_MBMASTER_EN)
extern xMBHandle xMBMMaster;
#endif

#endif //__APP_DATA_H__

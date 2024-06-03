/*
 * USB_Device_Driver.h
 *
 *  Created on: Jun 3, 2024
 *      Author: kunal
 */

#ifndef USB_DEVICE_DRIVER_H_
#define USB_DEVICE_DRIVER_H_

#include "main.h"

#define USB_OTG_HS_PCGCCTL ((uint32_t *) (USB_OTG_HS_PERIPH_BASE + USB_OTG_PCGCCTL_BASE))


void USB_Core_Init(void);
void USB_Pin_Init(void);
void USB_Connect(void);
void USB_Disconnect(void);


#endif /* USB_DEVICE_DRIVER_H_ */

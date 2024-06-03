/*
 * USB_Device_Framework.c
 *
 *  Created on: Jun 3, 2024
 *      Author: kunal
 */


#include "USB_Device_Framework.h"


void USB_Device_Init()
{
	USB_Core_Init();
	USB_Connect();
}

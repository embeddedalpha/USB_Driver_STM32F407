/*
 * USB_Device_Driver.c
 *
 *  Created on: Jun 3, 2024
 *      Author: kunal
 */


#include "USB_Device_Driver.h"
#include "GPIO.h"



void USB_Pin_Init(void)
{
	GPIO_Pin_Init(GPIOA, 11, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.OTG_FS_1);

	GPIO_Pin_Init(GPIOA, 12, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.OTG_FS_1);

}


void USB_Core_Init(void)
{
	USB_Pin_Init();

	RCC -> AHB2ENR |= RCC_AHB2ENR_OTGFSEN  ; //ENABLE USB CORE

	USB_OTG_FS -> GUSBCFG |= 0x09 << USB_OTG_GUSBCFG_TRDT_Pos;
	USB_OTG_FS -> GUSBCFG |= USB_OTG_GUSBCFG_FDMOD   //FORCE DEVICE MODE
			              |  USB_OTG_GUSBCFG_PHYSEL;  //SELECT PHYSCIAL LAYER
	USB_OTG_Device -> DCFG |= USB_OTG_DCFG_DSPD; //Full speed
	USB_OTG_FS -> GCCFG |= USB_OTG_GCCFG_VBUSBSEN; //ENABLE BUS SENSING

	USB_OTG_FS -> GINTMSK |= USB_OTG_GINTMSK_ENUMDNEM
			              | USB_OTG_GINTMSK_USBRST
						  | USB_OTG_GINTMSK_SOFM
			              | USB_OTG_GINTMSK_WUIM
						  | USB_OTG_GINTMSK_USBSUSPM
						  | USB_OTG_GINTMSK_IEPINT
						  | USB_OTG_GINTMSK_OEPINT
						  | USB_OTG_GINTMSK_RXFLVLM;

	USB_OTG_FS -> GINTSTS = 0xFFFFFFFF;
	USB_OTG_FS -> GAHBCFG |= USB_OTG_GAHBCFG_GINT;

}

void USB_Connect(void)
{
	USB_OTG_FS -> GCCFG |= USB_OTG_GCCFG_PWRDWN;
	USB_OTG_Device -> DCTL &= ~USB_OTG_DCTL_SDIS;
}

void USB_Disconnect(void)
{
	USB_OTG_Device -> DCTL |= USB_OTG_DCTL_SDIS;
	USB_OTG_FS -> GCCFG &= ~USB_OTG_GCCFG_PWRDWN;
}



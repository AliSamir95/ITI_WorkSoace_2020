#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include"LED_interface.h"
#include"LED_config.h"

void SetLedOn (void)
{
	SetPinValue(LED_Port,LED_Pin,LED_Mode);
}

void SetLedOff (void)
{
	
	SetPinValue(LED_Port,LED_Pin,LED_Mode^0x01);
}

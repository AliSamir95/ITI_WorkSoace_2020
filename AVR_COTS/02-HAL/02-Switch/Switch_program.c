#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include"Switch_interface.h"
#include"Switch_config.h"


u8 GetSwitchStatus (void)
{
	u8 result;
	result = GetPinValue(Switch_Port,Switch_Pin);
/*it's better to make this using #if than do just if condition because 
the switch mode will never change its value during runtime	*/

	#if Switch_Mode==0
	
		return result;
	
	#else
	
		return result^0x01;
	
	#endif
			
	

	
}



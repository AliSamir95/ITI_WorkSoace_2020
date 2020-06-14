#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"WDGT_register.h"
#include"WDGT_config.h"
#include"WDGT_interface.h"
#include"WDGT_private.h"
#include"INTGLB_regester.h"



void WDGT_Sleep(u8 sleepOption)
{
	/*Set WDEand WDOE Bit at the same time */
		WDTCR=0b0001100;
		/*Clear WDE*/
		WDTCR=0;
		/*Set Prescling and set but 4 for enable */
		WDTCR=(sleepOption | 0b1000);
}
void WDGT_Stop(void)
{
	/*Set WDEand WDOE Bit at the same time */
	WDTCR=0b0001100;
	/*Clear WDE*/
	WDTCR=0;

}
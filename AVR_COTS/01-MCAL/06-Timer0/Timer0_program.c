#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"Timer0_register.h"
#include"Timer0_config.h"
#include"Timer0_interface.h"
#include"Timer0_private.h"
#include"INTGLB_regester.h"


static  void (*Timer_Pfunc)(void);
void TIMER0_voidInit(void)
{
  //Set mode --> Normal mode 
  //Enable ovf int
  //Enable global  int
  //Set preload
  //Set prescaller 
  SET_BIT(TIMSK,0);
  INT_voidEnableGlobal();
  TCNT0=PRELOAD;
  CLEAR_BIT(TCCR0,2);
  SET_BIT(TCCR0,1;
  SET_BIT(TCCR0,0);
}


void TIMER0_voidSetCallback(void(*pfunc)(void))
{
  Timer_Pfunc=pfunc;
}

void __vector_11(void) 
{
  static u16 Local_u16counter;
  Local_u16counter++;
  if ( Local_u16counter==DESRED_TIME)
  {
    Timer_Pfunc();
    Local_u16counter=0;
  }
   TCNT0=PRELOAD;
}
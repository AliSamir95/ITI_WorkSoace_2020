#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"PORT_interface.h"
#include"EXTI_reg.h"
#include"EXTI_interface.h"

void EXTI_voidInt0Init(void)
{
  SET_BIT(MCUCR,1);
 CLEAR_BIT(MCUCR,0);
 
  SET_BIT(GICR,6);

}
void EXTI_voidInt1Init(void)
{
 SET_BIT(MCUCR,3);
 CLEAR_BIT(MCUCR,2);
  SET_BIT(GICR,7); 
}

void INT_voidEnableGlobal(void)
{
  SET_BIT(SREG,3);
}
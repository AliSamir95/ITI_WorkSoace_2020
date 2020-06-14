 /************************************************************************\
 * Author : May Alaa                                                     * 
 * Version : 1                                                           *
 * Date 14/1/2020                                                        *
 \************************************************************************/
#define CLR_CMD (0b00000001)
#define DISP_CONTROL_CMD 0b00001100

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"
#include <avr/delay.h>


/*****************************************************
* Description: This API shall initialize LCD
*  Input Parameter: void
*  Return: void 
*****************************************************/
void CLCD_voidInitialize(void)
{
	_delay_ms(40);
#if CLCD_u8_DATA_LENGTH == FOUR_BITS_MODE
	/*  Set RS= 0               */
	SetPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,0);
	/*  Set RW= 0               */
	SetPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);
	/*send 0010*/
	/*writing the function set command using writehalfdataport*/
	CLCD_voidSetHalfDataPort(0b0010);
	/*Enable pulse*/
	CLCD_voidSetEnablePulse();
	/*send 0010 again*/
	CLCD_voidSetHalfDataPort(0b0010);
	/*Enable pulse*/
	CLCD_voidSetEnablePulse();
	/*send last command of function set*/
	CLCD_voidSetHalfDataPort(0b1000);
	/*Enable pulse*/
	CLCD_voidSetEnablePulse();


#elif CLCD_u8_DATA_LENGTH == EIGHT_BITS_MODE
	CLCD_voidWriteCmd(0b00111000);

#else #error "Wrong Data Length choice"
#endif

	/* we need to wait 39 us after that but this function waits for 1 ms anyways inside it*/
	CLCD_voidWriteCmd(0b00001100);
	CLCD_voidWriteCmd(0b00000001);
	_delay_ms(2);



}

/*****************************************************
* Description: This API shall Display Data on LCD
*  Input Parameter: 
*   - u8 Copy_u8Data: Data to be displayed
*  Return: void 
******************************************************/
void CLCD_voidWriteData(u8 Copy_u8Data)
{
	/*  Set RS= 1               */
	SetPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,1);
	/*  Set RW= 0               */
	SetPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);
	/*  Set Data on Data port   */
#if CLCD_u8_DATA_LENGTH == FOUR_BITS_MODE

	/*send higher order 4 bits*/
	CLCD_voidSetHalfDataPort(Copy_u8Data>>4);
	/*Enable pulse*/
	CLCD_voidSetEnablePulse();
	/*send lower order 4 bits*/
	CLCD_voidSetHalfDataPort(Copy_u8Data);
	CLCD_voidSetEnablePulse();



#elif CLCD_u8_DATA_LENGTH == EIGHT_BITS_MODE
	CLCD_voidSetDataPort(Copy_u8Data);
	CLCD_voidSetEnablePulse();

#else #error "Wrong Data Length choice"

#endif

}

/*****************************************************
* Description: This API shall execute commands
*  Input Parameter: 
*   - u8 Copy_u8Cmd: Command to be executed
*  Return: void 
******************************************************/
void CLCD_voidWriteCmd(u8 Copy_u8Cmd)
{
  /*  Set RS= 0               */
      SetPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,0);
  /*  Set RW= 0               */
      SetPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);
  /*  Set Data on Data port   */

#if CLCD_u8_DATA_LENGTH == FOUR_BITS_MODE

      /*send higher order 4 bits*/
      CLCD_voidSetHalfDataPort(Copy_u8Cmd>>4);
      /*Enable pulse*/
      CLCD_voidSetEnablePulse();
      /*send lower order 4 bits*/
      CLCD_voidSetHalfDataPort(Copy_u8Cmd);
      CLCD_voidSetEnablePulse();

#elif CLCD_u8_DATA_LENGTH == EIGHT_BITS_MODE
      CLCD_voidSetDataPort(Copy_u8Cmd);
      CLCD_voidSetEnablePulse();

#else
      #error "Wrong Data Length choice"

#endif


}

static void CLCD_voidSetDataPort(u8 Copy_u8Data)
{

      u8 Local_u8BitVal;
      Local_u8BitVal = GET_BIT(Copy_u8Data,0);
      SetPinValue(CLCD_u8_D0_PORT,CLCD_u8_D0_PIN,Local_u8BitVal);

      Local_u8BitVal = GET_BIT(Copy_u8Data,1);
      SetPinValue(CLCD_u8_D1_PORT,CLCD_u8_D1_PIN,Local_u8BitVal);

      Local_u8BitVal = GET_BIT(Copy_u8Data,2);
      SetPinValue(CLCD_u8_D2_PORT,CLCD_u8_D2_PIN,Local_u8BitVal);

      Local_u8BitVal = GET_BIT(Copy_u8Data,3);
      SetPinValue(CLCD_u8_D3_PORT,CLCD_u8_D3_PIN,Local_u8BitVal);

      Local_u8BitVal = GET_BIT(Copy_u8Data,4);
      SetPinValue(CLCD_u8_D4_PORT,CLCD_u8_D4_PIN,Local_u8BitVal);

      Local_u8BitVal = GET_BIT(Copy_u8Data,5);
      SetPinValue(CLCD_u8_D5_PORT,CLCD_u8_D5_PIN,Local_u8BitVal);

      Local_u8BitVal = GET_BIT(Copy_u8Data,6);
      SetPinValue(CLCD_u8_D6_PORT,CLCD_u8_D6_PIN,Local_u8BitVal);

      Local_u8BitVal = GET_BIT(Copy_u8Data,7);
      SetPinValue(CLCD_u8_D7_PORT,CLCD_u8_D7_PIN,Local_u8BitVal);
}

static void CLCD_voidSetHalfDataPort(u8 Copy_u8Data)
{
	u8 Local_u8BitVal;

	Local_u8BitVal = GET_BIT(Copy_u8Data,0);
	SetPinValue(CLCD_u8_D4_PORT,CLCD_u8_D4_PIN,Local_u8BitVal);

	Local_u8BitVal = GET_BIT(Copy_u8Data,1);
	SetPinValue(CLCD_u8_D5_PORT,CLCD_u8_D5_PIN,Local_u8BitVal);

	Local_u8BitVal = GET_BIT(Copy_u8Data,2);
	SetPinValue(CLCD_u8_D6_PORT,CLCD_u8_D6_PIN,Local_u8BitVal);

	Local_u8BitVal = GET_BIT(Copy_u8Data,3);
	SetPinValue(CLCD_u8_D7_PORT,CLCD_u8_D7_PIN,Local_u8BitVal);
}

static void CLCD_voidSetEnablePulse(void)
{
    /*  Enable pulse            */
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
	_delay_ms(1);
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
	_delay_ms(1);
}

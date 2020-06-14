/********************************/
/* Author : Ali Samir           */ 
/*Version : V01                 */
/*Date    : 14 Jan 2020         */
/********************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"CLCD_config.h"
#include"CLCD_Private.h"
#include"PORT_interface.h"
#include <util/delay.h>

static void CLCD_voidsetDataPort (u8 Copy_u8Data);

void CLCD_voidInitalize (void)
{
  /*Follow Data sheet instructions*/
      _delay_ms(40);
  #if CLCD_u8_DATA_LENGTH == FOUR_BITS_MODE
   /* Set Rs = 0 */ 
  SetPinValue( CLCD_u8_RS_PORT,  CLCD_u8_RS_PIN,0);
  /* Set Rw = 0 */ 
  SetPinValue( CLCD_u8_RW_PORT,  CLCD_u8_RW_PIN,0);
  /* Set Data on Data port  */
      /* Send0010*/
      CLCD_voidsetHalfDataPort(0b0010);
       /* Enable pulse */ 
      CLCD_voidSetEnablePulse();
      /* Send0010*/
      CLCD_voidsetHalfDataPort(0b0010);
       /* Enable pulse */ 
      CLCD_voidSetEnablePulse(); 
     /* Send 2 lines display , font = 5*7*/
      CLCD_voidsetHalfDataPort(0b1000);
       /* Enable pulse */ 
      CLCD_voidSetEnablePulse(); 
  #elif CLCD_u8_DATA_LENGTH == EIGHT_BITS_MODE
    CLCD_voidWriteCmd (0b00111000);

  #else #error "Wrong DATA LENGTH Choice" 
  #endif
  CLCD_voidWriteCmd (0b00001100);
  CLCD_voidWriteCmd (0b00000001);
  _delay_ms(2);
  
}

/*Description : This API shall display data on LCD */ 

void CLCD_voidWriteData (u8 Copy_u8Data)

{
  /* Set Rs = 1 */ 
  SetPinValue( CLCD_u8_RS_PORT,  CLCD_u8_RS_PIN,1);
  /* Set Rw = 0 */ 
  SetPinValue( CLCD_u8_RW_PORT,  CLCD_u8_RW_PIN,0);
  /* Set Data on Data port  */
  
    #if CLCD_u8_DATA_LENGTH == FOUR_BITS_MODE
  /*Send higher order 4bits of the command */
   CLCD_voidsetHalfDataPort(Copy_u8Data>>4);
    /* Enable pulse */ 
   CLCD_voidSetEnablePulse();
    /*Send lower order 4bits of the command */
   CLCD_voidsetHalfDataPort(Copy_u8Data);
    /* Enable pulse */ 
   CLCD_voidSetEnablePulse();
  #elif CLCD_u8_DATA_LENGTH == EIGHT_BITS_MODE
  CLCD_voidsetDataPort (Copy_u8Cmd);
 /* Enable pulse */ 
  CLCD_voidSetEnablePulse();
  #else #error "Wrong DATA LENGTH Choice"
  
  #endif
}
/*Description : This API shall display data on LCD */ 
void CLCD_voidWriteCmd (u8 Copy_u8Cmd)
{
  /* Set Rs = 0 */ 
  SetPinValue( CLCD_u8_RS_PORT,  CLCD_u8_RS_PIN,0);
  /* Set Rw = 0 */ 
  SetPinValue( CLCD_u8_RW_PORT,  CLCD_u8_RW_PIN,0);
  /* Set Data on Data port  */
  
  #if CLCD_u8_DATA_LENGTH == FOUR_BITS_MODE
  /*Send higher order 4bits of the command */
   CLCD_voidsetHalfDataPort(Copy_u8Cmd>>4);
    /* Enable pulse */ 
   CLCD_voidSetEnablePulse();
    /*Send lower order 4bits of the command */
   CLCD_voidsetHalfDataPort(Copy_u8Cmd);
    /* Enable pulse */ 
   CLCD_voidSetEnablePulse();
  #elif CLCD_u8_DATA_LENGTH == EIGHT_BITS_MODE
  CLCD_voidsetDataPort (Copy_u8Cmd);
 /* Enable pulse */ 
  CLCD_voidSetEnablePulse();
  #else #error "Wrong DATA LENGTH Choice"
  
  #endif
}

/*Set Cursor*/
/*
void CLCD_voidSetCursor(u8 row,u8 column)
{
	if (row==0)
	{
		CLCD_voidWriteCmd(0b10000000+column);
	}
	else if (row==1)
	{
		CLCD_voidWriteCmd(0b10000000+0x40+column);
	}
}
*/

/*Go to Specific LOcation */
void CLCD_voidGotoLocation(u8 Copy_LineNb,u8 Copy_Position)
{
  if (Copy_LineNb==CLCD_LINE_1)
  {
  		CLCD_voidWriteCmd(CLCD_LINE_1_CMND + Copy_Position);
 
  }
  else if(Copy_LineNb==CLCD_LINE_2)
  {
    CLCD_voidWriteCmd(CLCD_LINE_2_CMND + Copy_Position);
  }
  else 
  {
  }
}
/*Write string */

void CLCD_voidWriteString( char * Copy_Pu8String ) 
{
  u8 Local_u8Counter = 0;
  while(Copy_Pu8String[Local_u8Counter] != '\0')
  {
  CLCD_voidWriteData(Copy_Pu8String[Local_u8Counter]);
  Local_u8Counter++;
  }
}


/*Enable Function */ 

static void CLCD_voidSetEnablePulse(void)
{
 SetPinValue( CLCD_u8_RS_PORT,  CLCD_u8_E_PIN,1);
  _delay_ms(10);
  SetPinValue( CLCD_u8_RS_PORT,  CLCD_u8_E_PIN,0);
    _delay_ms(10); 
}    

 static void CLCD_voidsetDataPort (u8 Copy_u8Data)
{
  u8 Local_u8BitVal;
  
   Local_u8BitVal=GET_BIT(Copy_u8Data,0);

  SetPinValue( CLCD_u8_DATA_PORT ,  CLCD_u8_D0,Local_u8BitVal);

    Local_u8BitVal=GET_BIT(Copy_u8Data,1);

  SetPinValue( CLCD_u8_DATA_PORT ,  CLCD_u8_D1,Local_u8BitVal);
    Local_u8BitVal=GET_BIT(Copy_u8Data,2);
  SetPinValue( CLCD_u8_DATA_PORT ,  CLCD_u8_D2,Local_u8BitVal);
    Local_u8BitVal=GET_BIT(Copy_u8Data,3);
  SetPinValue( CLCD_u8_DATA_PORT ,  CLCD_u8_D3,Local_u8BitVal);
    Local_u8BitVal=GET_BIT(Copy_u8Data,4);
  SetPinValue( CLCD_u8_DATA_PORT ,  CLCD_u8_D4,Local_u8BitVal);
    Local_u8BitVal=GET_BIT(Copy_u8Data,5);
  SetPinValue( CLCD_u8_DATA_PORT ,  CLCD_u8_D5,Local_u8BitVal);
    Local_u8BitVal=GET_BIT(Copy_u8Data,6);
  SetPinValue( CLCD_u8_DATA_PORT ,  CLCD_u8_D6,Local_u8BitVal);
    Local_u8BitVal=GET_BIT(Copy_u8Data,7);
  SetPinValue( CLCD_u8_DATA_PORT ,  CLCD_u8_D7,Local_u8BitVal);
}

static void CLCD_voidsetHalfDataPort(u8 Copy_u8Data)
{
  u8 Local_u8BitVal;
 Local_u8BitVal=GET_BIT(Copy_u8Data,0);
  SetPinValue( CLCD_u8_DATA_PORT ,  CLCD_u8_D4,Local_u8BitVal);
    Local_u8BitVal=GET_BIT(Copy_u8Data,1);
  SetPinValue( CLCD_u8_DATA_PORT ,  CLCD_u8_D5,Local_u8BitVal);
    Local_u8BitVal=GET_BIT(Copy_u8Data,2);
  SetPinValue( CLCD_u8_DATA_PORT ,  CLCD_u8_D6,Local_u8BitVal);
    Local_u8BitVal=GET_BIT(Copy_u8Data,3);
  SetPinValue( CLCD_u8_DATA_PORT ,  CLCD_u8_D7,Local_u8BitVal);
}
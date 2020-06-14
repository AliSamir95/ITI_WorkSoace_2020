/*******************************************************/
/* Author : ALI SAMIR                                  */ 
/* DATEE  : 9 march 2020                               */ 
/* Version: V01                                        */ 
/*******************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"UART_interface.h"
#include"UART_register.h"
#include"UART_private.h"
#include"UART_config.h"


void  (* EndoFTransmitCB(void));
void  (* EndoFRECIEVECB(void));

const u8 BaudRate[3][3]=
{
 
/*LOOK UP TABLE*/

  /* 4800  , 9600  , 115200*/
  
  {  0x67  ,  0x33  ,   0x03      }, /*Clock System 0 = 8 MHZ*/
  {  154   ,   77   ,     6       }, /*Clock System 1 = 12 MHZ*/
  {  0xCF  ,  0X67   ,   0x08     }  /*Clock System 2 = 16 MHZ*/
                   
}

void UART_voidInitialize(void)
{
 /*u2x = 0 */ 
 CLEAR_BIT(UCSRA,1);
 /* Disable all UART Interrupts*/
 /* Enable RX and TX*/
 /* Character size 8 Bit*/
 UCSRB=0x18;
 
 /*Asynch mode
   Character Size = 8 bit */
 UCSRC=((1                 <<7)|
       (UART_u8_PARITY     <<4)|
       (UART_u8_STOP_BITS  <<3)|
       (3                  <<1)
       );
       
  UBRRL=BaudRate[UART_u8_SYS_FREQ][UART_BAUDRATE]     
}

u8 UART_u8TransmitDataSynch(u8 Copy_u8Data)
{
 u8 Local_Error==OK;
 u32 Timeout=0;
 /*Send data on UDR*/
  UDR_T=Copy_u8Data;
  /*Wait Flag raised */
  while(GET_BIT(USCRA,7)==0 && (Timeout < UART_u8_TIME_OUT_TH))
  {
    Timeout++;
  }
  if (Timeout >= UART_u8_TIME_OUT_TH)
  {
    Local_Error==NOK;
  }
  else
  {
    /*Clear Flag*/
    SET_BIT(USCRA,6);
  }
  return Local_Error;
}
void UART_voidTransmitDataASynch(u8 Copy_u8Data,void(*Copy_ptr)(void))
{
 /*Enable interrupt*/
SET_BIT(UCSRB,6);
/*Set recieve data*/
UDR_T=Copy_u8Data;
EndoFTransmitCB=Copy_ptr;
 
}

u8 UART_u8ReceiveSynch(u8 * Copy_ptrData)
{
  
u8 Local_Error==OK;
 u32 Timeout=0;

  /*Wait Flag raised */
  while(GET_BIT(USCRA,7)==0 && (Timeout < UART_u8_TIME_OUT_TH))
  {
    Timeout++;
  }
  if (Timeout >= UART_u8_TIME_OUT_TH)
  {
    Local_Error==NOK;
  }
  else
  {
    /*SET Data to Recieve pointer */
    Copy_ptrData = UDR_R;
  }
  return Local_Error;
}
void UART_u8ReceiveSynch(void(*Copy_ptr)(void
{
  /*Check if Data to recieve */
  if(GET_BIT(USCRA,7)==1)
  {
    Copy_ptr(UDR);
  }
  /*Nothing to recieve */
  else
  {
    /*Enable RX interrupt*/
    SET_BIT(USCRB,7);
    /*Save Call back*/
    EndoFRECIEVECB=Copy_ptr;
  }
  
}
/*************************************************/
/*************************************************/
/*Author   : Ali Samir 							 */
/*Component: Handler_UART						 */					 
/*Layer    : ECUCAL								 */
/*************************************************/	
/*************************************************/	


#include "RCC.h"
#include "GPIO.h"
#include "uart.h"
#include "huart_Config.h"
#include "huart.h

Notify_t Notification_Send,Notification_Receive;

uint32_t  clock ;
uint8_t Huart_Initialization(void)
{
	uint8_t Error_state=OK;
	uint32_t BaudRateDIV_Mantissa;
	uint32_t BaudRateDIV_Fraction;
	/**RCC Configuration**/
	RCC_SetPriephralStatus(GPIO_A_ENABLE,ON);
	RCC_SetPriephralStatus(USART_1_ENABLE,ON);
	/**Gpio Configuraion**/
	GPIO_t GPIO;
	GPIO.Mode=MODE_PIN10_IP_PUR|MODE_PIN9_AF_PP;
	GPIO.Speed=SPEED_PIN10_INPUT|SPEED_PIN9_2MHZ;
	GPIO.Port=PORT_A;
	GPIO.Pin=PIN_9|PIN_10;
	Error_state=GPIO_Config(&GPIO);
	/**UART Defualt Configuraion**/
	Error_state|=RCC_GetBusClock(APB2_BUS,&clock);
	BaudRateDIV_Mantissa = ( (clock) / (16*BAUD_RATE) );
	BaudRateDIV_Fraction = (( ( (clock) % (16*BAUD_RATE) ) *16 ) / (16*BAUD_RATE));
	#if MODE==DMA_MODE
	D_DMA_Init(); //mark
#elif MODE==INTERRUPT_MODE
	UART->CR1 |= USART_RXNEIE_ENABLE | USART_TCEIE_ENABLE
#endif
	Error_state|=UART_Initialization(BaudRateDIV_Mantissa,BaudRateDIV_Fraction,PARITY_BIT,DATA_BITS,STOP_BITS);
	return Error_state;
}
/*************************************************************************************************************************/

uint8_t Huart_Send(uint8_t *Buffer, uint16_t Length)
{
	uint8_t Error_state=OK;
	#if SEND_MODE==SEND_MODE_INTERRUPT
	Error_state= UART_Send(Buffer,Length);
	#elif SEND_MODE==SEND_MODE_DMA
Notification_Send.TC=DMA_ChannelFour_Finish;
	D_DMA_SetNotifyCbf(&Notification_Send,CHANNEL_FOUR);
	localError=D_DMA_Start((uint_32t)Buffer,(uint_32t)(&(UART->DR)),Length,CHANNEL_ONE);
	return Error_state;

}
/*************************************************************************************************************************/
uint8_t Huart_Receive(uint8_t *Buffer, uint16_t Length)
{
	
	uint8_t Error_state=OK;
	Error_state= UART_Receive(Buffer,Length);
	return Error_state;

}
/*************************************************************************************************************************/
uint8_t Huart_Config(uint32_t BaudRate,uint32_t ParityBits,uint32_t DataSize,uint32_t StopBits)
{
	uint8_t Error_state=OK;
	uint32_t BaudRateDIV_Mantissa;
	uint32_t BaudRateDIV_Fraction;
if((ParityBits==PARITY_DISABLED || ParityBits==PARITY_EVEN || ParityBits==PARITY_ODD) && (DataSize==DATA_8_BITS || DataSize==DATA_9_BITS) && (StopBits==ONE_STOP_BIT || StopBits==TWO_STOP_BIT))
{
	BaudRateDIV_Mantissa = ( (clock) / (16*BAUD_RATE) );
	BaudRateDIV_Fraction = (( ( (clock) % (16*BAUD_RATE) ) *16 ) / (16*BAUD_RATE));
	Error_state=UART_Config(BaudRateDIV_Mantissa,BaudRateDIV_Fraction,ParityBits,DataSize,StopBits);
}
else
{
	Error_state=NOK;
}
return 	Error_state;
}

/*************************************************************************************************************************/

uint8_t Huart_SetTxCbf(TxCbf_t TxCbf)
{
	uint8_t Error_state=OK;
	if(TxCbf)
	{
		Error_state=UART_SetTxCbf(TxCbf);
	}
	else
	{
		Error_state=NOK;
	}
	return Error_state;
}
/*************************************************************************************************************************/
uint8_t Huart_SetRxCbf(RxCbf_t RxCbf)
{
	uint8_t Error_state=OK;
	if(RxCbf)
	{
		Error_state = UART_SetRxCbf(RxCbf);
	}
	else
	{
		Error_state=NOK;
	}
	return Error_state;
}















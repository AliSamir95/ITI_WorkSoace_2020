#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H





#define ADC_u8CHANNEL_0    0
#define ADC_u8CHANNEL_1    1
#define ADC_u8CHANNEL_2    2
#define ADC_u8CHANNEL_3    3
#define ADC_u8CHANNEL_4    4
#define ADC_u8CHANNEL_5    5
#define ADC_u8CHANNEL_6    6
#define ADC_u8CHANNEL_7    7

typedef struct 
{
  u8 * ptrchain;
  u8 length;
  u16 * ptResult;
}ADC_Chain;


void ADC_voidInit(void);

u8 ADC_u8GetChannel_Reading_Synchronous(u8 channel,u16 * ReturnResultl);

u8 ADC_u8GetChannel_Reading_Asynchronous(u8 channel,(void)(* ptr_fun)(void),u16 * ReturnResult)

u8 ADC_u8ChainInit(ADC_Chain * StrChain,u8 * ptrChainArr,u8 length,u16 * );

u8 ADC_u8StartChainConversionAsynchronous()

#endif

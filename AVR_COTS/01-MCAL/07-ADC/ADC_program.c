#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"ADC_register.h"
#include"ADC_config.h"
#include"ADC_interface.h"
#include"ADC_private.h"
#include"INTGLB_regester.h"


static void (*GPfunc)(void)=NULL;
static u16 * ADC_pu16ADCResult=NULL; 
static u8 ADC_u8STATE =ADC_u8_STATE_IDLE; 
static u8 ADC_u8ISRStatus =ADC_u8_SINGLE_CONVERSION; 
static u8 * ADC_ChainArr=NULL;
static u8 ADC_ChainLength;

void ADC_voidInit(void)
{
   /*8bit mode ADC ref voltage polling (not interrupted)*/

   /*ADC reference voltage*/
     CLEAR_BIT(ADMUX,7);
     SET_BIT(ADMUX,6);
  /*Active Left Adjust mode*/
     SET_BIT(ADMUX,5);
  /*ADC Enable*/
     SET_BIT(ADCSRA,7);
  /*prescaler 128*/
     SET_BIT(ADCSRA,2);
     SET_BIT(ADCSRA,1);
     SET_BIT(ADCSRA,0);
}

u8 ADC_u8GetChannel_Reading_Synchronous(u8 channel,u16 * ReturnResultl);
{
  /*Check pointer not equal null*/
  
  u32 local_Time_out =0;
  u8 local_u8ReturnStaus=STD_TYPES_ERROR_OK ;
  
  if (ReturnResultl==NULL || channel > 32)
  {
    local_u8ReturnStaus=STD_TYPES_ERROR_NOK;
  }
  
 else
 {   
  /*Set the channel in ADMUX*/
     ADMUX&=0b11100000;
     ADMUX|=channel;
  /*Start Conversion */
     SET_BIT(ADCSRA,6);
  /*polling on the conversion comeleting*/
  while((GET_BIT(ADCSRA,4))==0) && local_Time_out<ADC_Time_out_Count)
  {
    local_Time_out++;
  }
  
  if (local_Time_out=>ADC_Time_out_Count)
  {
    local_u8ReturnStaus=STD_TYPES_ERROR_NOK;
  }
  else
  {
    /*Clear Flag*/
     SET_BIT(ADCSRA,4);
    /*get resualt*/
    #if ADC_U8_RESOLUTION == ADC_u8_8bit_RESOLUTION
        *ReturnResultl= ADCH;
    #elif ADC_U8_RESOLUTION == ADC_u8_10bit_RESOLUTION
           *ReturnResultl= ADC;
  }
 }    
      return local_u8ReturnStaus;
}

u8 ADC_u8GetChannel_Reading_Asynchronous(u8 channel,(void)(* ptr_fun)(void),u16 * ReturnResult)
{
    u8 local_u8ReturnStaus=STD_TYPES_ERROR_OK ;
    
    if ((ptr_fun==NULL) || (ReturnResultl==NULL) || (channel > 32))
    {
      local_u8ReturnStaus=STD_TYPES_ERROR_NOK;
    }
  else 
  {
     
      if (ADC_u8STATE == ADC_u8_STATE_IDLE)
      {  
      /*Init objects*/
      ADC_u8STATE =ADC_u8_STATE_BUSY; 
      ADC_u8ISRStatus =ADC_u8_SINGLE_CONVERSION;
      GPfunc=ptr_fun;
      ADC_pu16ADCResult=ReturnResult;
  /*Set the channel in ADMUX*/
     ADMUX&=0b11100000;
     ADMUX|=channel;
  /*Enable Interrupt of ADC*/
       SET_BIT(ADCSRA,ADCSRA_ADIE_PIN);
      /*Start Conversion */
     SET_BIT(ADCSRA,6);

      }
      else
      {
            local_u8ReturnStaus=STD_TYPES_ERROR_NOK;
      }
  }
  return  local_u8ReturnStaus;
}

















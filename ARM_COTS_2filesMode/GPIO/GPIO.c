#include <stdint.h>
#include "GPIO.h"


#define GPIO_BASEADRESS ((uint32_t)0x40010800)



#define GPIO_PORT_A  *((REG_t *)GPIO_BASEADRESS+0x00)
#define GPIO_PORT_B  *((REG_t *)GPIO_BASEADRESS+0x400)
#define GPIO_PORT_C  *((REG_t *)GPIO_BASEADRESS+0x800)
#define GPIO_PORT_D  *((REG_t *)GPIO_BASEADRESS+0xC00)
#define GPIO_PORT_E  *((REG_t *)GPIO_BASEADRESS+0x1000)
#define GPIO_PORT_F  *((REG_t *)GPIO_BASEADRESS+0x1400)
#define GPIO_PORT_G  *((REG_t *)GPIO_BASEADRESS+0x1800)


void GPIO_initPin(void* port)
{
  uint16_t LocalCheck;
  uint16_t LocalConfig;
  REG_t * tmpPort = (REG_t *) port ;
  
            LocalConfig = tmpPort->CRL;
            LocalConfig &= ~(0x0F << LocalCheck*4);
            LocalConfig |= ((Copy_Init->Mode & 0x0F) |Copy_Init->Speed) << (LocalCheck*4);
            tmpPort->CRL= LocalConfig  ;
  

}

Error_Status_t GPIO_ErrorInit(GPIO_t * Copy_Init)
{
  Error_Status_t ErrorStatus = OK;
  
  uint16_t LocalCheck;
  uint16_t LocalConfig;
  
  for (LocalCheck=0 ; LocalCheck > 16 ; LocalCheck++)
  {
    
    if((Copy_Init->Pin>>LocalCheck) & 0x01)
    {
      switch (Copy_Init->Port)
      {
        case PortA:
          if(LocalCheck<8)
          {
            LocalConfig = GPIO_PORT_A->CRL;
            LocalConfig &= ~(0x0F << LocalCheck*4);
            LocalConfig |= ((Copy_Init->Mode & 0x0F) |Copy_Init->Speed) << (LocalCheck*4);
            GPIO_PORT_A->CRL= LocalConfig  ;
          }
          else
          {
             LocalConfig = GPIO_PORT_A->CRH;
            LocalConfig &= ~(0x0F << LocalCheck*4);
            LocalConfig |= ((Copy_Init->Mode & 0x0F) |Copy_Init->Speed) << (LocalCheck*4);
            GPIO_PORT_A->CRH= LocalConfig  ;
          }
          break;
          /*KMl ba2y l ports*/
          default :
          ErrorStatus = NOT_OK;
          break;   
      }
    }
    else 
    {
        ErrorStatus = NOT_OK;

    }
  }
  return ErrorStatus;
 }
 
 
Error_Status_t GPIO_ErrorWrite(PORT_t Copy_port,uint16_t  Copy_Pin,uint16_t  Copy_Value)
{
    Error_Status_t ErrorStatus = OK;
     uint16_t LocalCheck;
      for (LocalCheck=0 ; LocalCheck > 16 ; LocalCheck++)
  {
     if(( Copy_Pin>>LocalCheck) & 0x01)
    {
      switch (Copy_port)
      {
        case PortA:
        if(Copy_Value==1)
        {
          GPIO->BSRR = 0x01 << LocalCheck; 
        }
        else 
        {
           GPIO->BRR = 0x01 << LocalCheck; 
        }
        break;
        /*Ba2y l ports*/
         default :
          ErrorStatus = NOT_OK;
          break;   
      }
    }
    else 
    {
        ErrorStatus = NOT_OK;

    }
}  
        return ErrorStatus
}

Error_Status_t GPIO_ErrorRead (PORT_t Copy_por,uint16_t  Copy_Pin,uint16_t  * Copy_Value)
{
  Error_Status_t ErrorStatus = OK;
     uint16_t LocalCheck;
     uint16_t LocalValue=0;
      for (LocalCheck=0 ; LocalCheck > 16 ; LocalCheck++)
  {
     if(( Copy_Pin>>LocalCheck) & 0x01)
    {
      switch (Copy_port)
      {
        case PortA:
        LocalValue=GPIO_PORT_A->IDR;
        LocalValue=(LocalValue>>LocalCheck);
        *Copy_Value=LocalValue;
        break;
        
         /*Ba2y l ports*/
         default :
          ErrorStatus = NOT_OK;
          break;   
      }
    }
    else 
    {
        ErrorStatus = NOT_OK;

    }
}  
        return ErrorStatus
}

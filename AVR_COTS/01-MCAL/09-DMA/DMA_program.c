/*************************************************/
/*Author :Ali Samir                              */ 
/*DATE :30 March 2020                            */ 
/*Version :V01                                   */ 
/*************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DMA_interface.h"
#include "DMA_register.h"
#include "DMA_private.h"
#include "DMA_config.h"

/*DMA Channel 1 initialization */ 
void DMA_Init(void)
{
  /*Enable M2M 
  Data size 32 Bit
  minc and pinc =1 
  No Circular
  CPAR->CMAR
  Transmission complete interrupt 
  */
  myDMA->DMA_Channel[0].CCR=0x0007AC2;
}
/*DMA Channel 1 Start*/

void DMA_voidStart(u32  Copy_SourceAddress,u32  Copy_DestinationAddress,u16 Copy_BlockKength)
{
  myDMA->DMA_Channel[0].CPAR=Copy_SourceAddress;
  myDMA->DMA_Channel[0].CMAR=Copy_DestinationAddress;
  myDMA->DMA_Channel[0].CNDTR=Copy_BlockKength;
  /*Enable DMA ch1 */
   myDMA->DMA_Channel[0].CCR |=1;
}

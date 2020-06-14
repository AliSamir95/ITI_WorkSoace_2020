#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DMA_interface.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"


u32 ARR_SRC[1000]={0}; 
u32 ARR_DES[1000]; 

void main (void)
{
u16 i;
/*Enable RCC for DMA */
  RCC_EnableClock(AHB,0);
  /*ENABLE DMA CHANNEL 1 interrupt*/
  NVIC_EnableINT(11);
  /*DMA init*/
   DMA_Init();
   /*DMA Start*/
   DMA_voidStart((u32)ARR_SRC,(u32)ARR_DES,1000);
  
  for (i=0;i<1000;i++)
  {
    ARR_DES[i]=ARR_SRC[i];
  }
 
}


void DM1_Channel1_IRQ(void)
{
  asm("NOP");
}
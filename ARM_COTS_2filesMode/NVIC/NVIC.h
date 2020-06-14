/*
 * NVIC.h
 *
 *  Created on: Feb 26, 2020
 *      Author: Ali Samir
 */

#ifndef NVIC_H_
#define NVIC_H_


typedef enum
{
	OK,
	NOT_OK
}Error_Status_t;

inline volatile void NVIC_EnableGlobalInterrupt(u32 Copy_u32InterruptNumber){
	//asm("CPSIE I");
	asm("MOV R0, #0");
	asm("MSR PRIMASK, R0");
}
inline volatile void NVIC_DisableGlobalInterrupt(u32 Copy_u32InterruptNumber){
	//asm("CPSID I");
	asm("MOV R0, #1");
	asm("MSR PRIMASK, R0");
}

Error_Status_t NVIC_EnableInterrupt(u32 Copy_u32InterruptNumber);
Error_Status_t NVIC_DisableInterrupt(u32 Copy_u32InterruptNumber);

Error_Status_t NVIC_SetInterruptPending(u32 Copy_u32InterruptNumber);
Error_Status_t NVIC_ClearInterruptPending(u32 Copy_u32InterruptNumber);


Error_Status_t NVIC_GetInterruptActive(u32 Copy_u32InterruptNumber, u32 *Copy_u32InterruptActivePin);


Error_Status_t NVIC_SetInterruptGoupBits(u8 Copy_u8GroupBits);

Error_Status_t NVIC_SetInterruptPrioty(u32 Copy_u32InterruptNumber, u8 Copy_u8Priorty);
Error_Status_t NVIC_GetInterruptPrioty(u32 Copy_u32InterruptNumber);



inline volatile void  NVIC_EnableFaultException(void)
{
  asm("CPSID F;");
}
inline volatile void  NVIC_DisableFaultException(void)
{
    asm("CPSIE F;");

}

Error_Status_t NVIC_InterruptPriortyFilter(u8 Copy_u8Priorty);

Error_Status_t NVIC_GenerateSoftwareInterrupt(void);


#endif /* NVIC_H_ */

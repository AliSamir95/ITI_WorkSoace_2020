/*
 * NVIC.c
 *
 *  Created on: Feb 26, 2020
 *      Author: Ali Samir
 */

#include <stdint.h>
#include "NVIC.h"

#define NVIC_BASE_ADDRESS  (0xE000E100UL)
#define SCB_BASE_ADDRESS   (0xE000ED00UL)
#define NVIC2_BASE_ADDRESS (0xE000EF00UL)

typedef struct {
    
    uint32_t ISER[8];
    uint32_t ICER[8];
    uint32_t ISPR[8];
    /////////rest of registers/////////
    uint8_t IPR[240]
}peri_t;

/*A pointer to each set of registers(8 register for each set)*/
#define NVIC_ISER  ((volatile uint32_t *)(NVIC_BASE_ADDRESS+0x00))
#define NVIC_ICER  ((volatile uint32_t *)(NVIC_BASE_ADDRESS+0x80))
#define NVIC_ISPR  ((volatile uint32_t *)(NVIC_BASE_ADDRESS+0x100))
#define NVIC_ICPR  ((volatile uint32_t *)(NVIC_BASE_ADDRESS+0x180))
#define NVIC_IABR  ((volatile uint32_t *)(NVIC_BASE_ADDRESS+0x200))
#define NVIC_IPR   ((volatile uint32_t *)(NVIC_BASE_ADDRESS+0x300))
#define NVIC_SITR  ((volatile uint32_t *)(NVIC2_BASE_ADDRESS+0xE00))

/*SCB needed register*/
#define SCB_AIRCR  ((volatile uint32_t *)SCB_BASE_ADDRESS+0x0C)

//#define GET_REG(Interrupt_Number) (Interrupt_Number/32)
#define GET_REG(INT_NUM)      (INT_NUM>>5)
#define GET_BIT(INT_BIT)      (INT_BIT & 0x1F)


#define GET_REG(INT_NUM)      (INT_NUM/32)
#define GET_BIT(INT_BIT)      (INT_BIT % 32)



Error_Status_t NVIC_EnableInterrupt(u32 Copy_u32InterruptNumber){
	Error_Status_t ErrorStatus = OK;
	if (Copy_u32InterruptNumber>240)
	{
		ErrorStatus = NOT_OK;
	}
	else
	{
		NVIC_ISER[GET_REG(Copy_u32InterruptNumber)] = (1<<GET_BIT(Copy_u32InterruptNumber));
	}
	return ErrorStatus;
}
Error_Status_t NVIC_DisableInterrupt(u32 Copy_u32InterruptNumber){
	Error_Status_t ErrorStatus = OK;
	if (Copy_u32InterruptNumber>240)
	{
		ErrorStatus = NOT_OK;
	}
	else
	{
		NVIC_ICER[GET_REG(Copy_u32InterruptNumber)] = (1<<GET_BIT(Copy_u32InterruptNumber));
	}
	return ErrorStatus;
}

Error_Status_t NVIC_SetInterruptPending(u32 Copy_u32InterruptNumber){
	Error_Status_t ErrorStatus = OK;
	if (Copy_u32InterruptNumber>240)
	{
		ErrorStatus = NOT_OK;
	}
	else
	{
		NVIC_ISPR[GET_REG(Copy_u32InterruptNumber)] = (maskArr[GET_BIT(Copy_u32InterruptNumber)];
    1<<GET_BIT(Copy_u32InterruptNumber));
	}
	return ErrorStatus;
}
Error_Status_t NVIC_ClearInterruptPending(u32 Copy_u32InterruptNumber){
	Error_Status_t ErrorStatus = OK;
	if (Copy_u32InterruptNumber>240)
	{
		ErrorStatus = NOT_OK;
	}
	else
	{
		NVIC_ICPR[GET_REG(Copy_u32InterruptNumber)] = (1<<GET_BIT(Copy_u32InterruptNumber));
	}
	return ErrorStatus;
}


Error_Status_t NVIC_GetInterruptActive(u32 Copy_u32InterruptNumber, u8 *Copy_u32InterruptActiveState){
	Error_Status_t ErrorStatus = OK;
	if (Copy_u32InterruptNumber>240)
	{
		ErrorStatus = NOT_OK;
	}
	else
	{
		u32 Local_u32ActiveReg;
		Local_u32ActiveReg=NVIC_IABR[GET_REG(Copy_u32InterruptNumber)];
		*Copy_u32InterruptActiveState = (Local_u32ActiveReg >> GET_BIT(Copy_u32InterruptNumber))&1;
	}
	return ErrorStatus;
}


Error_Status_t NVIC_SetInterruptGoupBits(u8 Copy_u8GroupBits)
{
  	Error_Status_t ErrorStatus = OK;
    	if (Copy_u32InterruptNumber>240)
	{
		ErrorStatus = NOT_OK;
	}
	else
	{
    
  }

}

Error_Status_t NVIC_SetInterruptPrioty(u32 Copy_u32InterruptNumber, u8 Copy_u8Priorty)
{
  
  	Error_Status_t ErrorStatus = OK;
    	if (Copy_u32InterruptNumber>240)
	{
		ErrorStatus = NOT_OK;
	}
	else
	{
    NVIC_ICPR[(Copy_u32InterruptNumber)>>2] =  Copy_u8Priorty<<((Copy_u32InterruptNumber & 0x03)*8;
  }
}

Error_Status_t NVIC_InterruptPriortyFilter(u8 Copy_u8Priorty)
{
  ERROR_STATUS STATUS=OK;
	//moved the priority level value to R0
	asm("MOV R0" :: "r" (Copy_u8Priorty) : "memory");
	asm("MSR BASEPRI,R0");
	return STATUS;

}

Error_Status_t NVIC_GenerateSoftwareInterrupt(void)
{
  	ERROR_STATUS STATUS=OK;
	//hardware priority assigned in STIR
	//INTERRUPT IS GENERATED BY SOFTWARE
	STIR_PTR=IRQ_NUMBER;
	return STATUS;

}
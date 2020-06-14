/*
 * NVIC.h
 *
 *  Created on: Feb 20, 2020
 *      Author: salma
 */

#ifndef NVIC_H_
#define NVIC_H_


/*group periority & subpriority implementations in system control block register*/
#define PRIGROUP_4BITS 0X00000300
#define PRIGROUP_3BITS 0X00000400
#define PRIGROUP_2BITS 0X00000500
#define PRIGROUP_1BITS 0X00000600
#define PRIGROUP_0BITS 0X00000700


typedef enum{
	OK,
	NOK

}ERROR_STATUS;

/*RESET SPECIAL REGISTER "PRIMASK" */
inline void NVIC_GLBEnable(void)
{
	asm("CPSIE I");
}
/*SET SPECIAL REGISTER "PRIMASK" */
inline void NVIC_GLBDisable(void)
{
	asm("CPSID I");
}
extern ERROR_STATUS NVIC_Enable(uint8_t IRQ_NUMBER , uint8_t PREEMPT, uint8_t SUBGROUP );
extern ERROR_STATUS NVIC_Disable(uint8_t IRQ_NUMBER);

extern ERROR_STATUS NVIC_Set_Pending(uint8_t IRQ_NUMBER);
extern ERROR_STATUS NVIC_Clear_Pending(uint8_t IRQ_NUMBER);

extern ERROR_STATUS IRQ_Set_Priority(uint8_t IRQ_NUMBER,uint8_t PRIORITY_NUMBER);
/*RESET SPECIAL REGISTER "FAULTMASK" */
inline void NVIC_Enable_ALLException(void)
{
	asm("CPSIE F");
}
/*SET SPECIAL REGISTER "FAULTMASK" */
inline void NVIC_Disable_ALLException(void)
{
	asm("CPSID F");
}

extern ERROR_STATUS NVIC_SW_IRQ_Enable(uint8_t IRQ_NUMBER);
/*Level of piority to implement */
extern ERROR_STATUS NVIC_Level_Filter_based_Priority(uint8_t Priority_Level);

extern ERROR_STATUS NVIC_ISActive_IRQ(uint8_t IRQ_NUMBER, uint8_t *IRQ_PTR);

extern ERROR_STATUS NVIC_Set_GROUPBITS(uint8_t GROUPBITS);




#endif /* NVIC_H_ */

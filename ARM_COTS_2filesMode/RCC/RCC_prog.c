#include"RCC_interface.h"


#define  RCC_BASE_ADDRESS  (*(volatile uint_32t*)0x40021000)

#define RCC_CR          (*(volatile uint_32t *)(RCC_BASE_ADDRESS + 0X00))
#define RCC_CFGR        (*(volatile uint_32t *)(RCC_BASE_ADDRESS + 0X04))
#define RCC_CIR         (*(volatile uint_32t *)(RCC_BASE_ADDRESS + 0X08))
#define RCC_APB2RSTR    (*(volatile uint_32t *)(RCC_BASE_ADDRESS + 0X0C))
#define RCC_APB1RSTR    (*(volatile uint_32t *)(RCC_BASE_ADDRESS + 0X10))
#define RCC_AHBENR      (*(volatile uint_32t *)(RCC_BASE_ADDRESS + 0X14))
#define RCC_APB2ENR     (*(volatile uint_32t *)(RCC_BASE_ADDRESS + 0X18))
#define RCC_APB1ENR     (*(volatile uint_32t *)(RCC_BASE_ADDRESS + 0X1C))
#define RCC_BDCR        (*(volatile uint_32t *)(RCC_BASE_ADDRESS + 0X20))
#define RCC_CSR         (*(volatile uint_32t *)(RCC_BASE_ADDRESS + 0X24))



Error_Status HSI_ON(uint_8t Status)
{
  Error_Status result = NOK;
  
switch(Status)
{
	case ON:
		RCC_CR |= RCC_HSI_ON;
		result = OK;
    break;
    
	case OFF:
		RCC_CR &= ~RCC_HSI_ON;
		result =  OK;
    break;
	}
  
  return result;
}

Error_Status HSI_RDY(void)
{
	if (RCC_CR&RCC_HSI_RDY){
		return OK;
	}
	return NOK;
}



Error_Status HSE_ON(uint_8t Status){
	switch(Status){
	case ON:
		RCC_CR |= RCC_HSE_ON;
		return OK;
	case OFF:
		RCC_CR &= ~RCC_HSE_ON;
		return OK;
	default:
		return NOK;
	}
}
Error_Status HSE_RDY(void){
	if (RCC_CR&&RCC_HSE_RDY){
		return OK;
	}
	return NOK;
}

Error_Status PLL_ON(uint_8t Status){
	switch(Status){
	case ON:
		RCC_CR |= RCC_PLL_ON;
		return OK;
	case OFF:
		RCC_CR &= ~RCC_PLL_ON;
		return OK;
	default:
		return NOK;
	}
}
Error_Status PLL_RDY(void){
	if (RCC_CR&&RCC_PLL_RDY){
		return OK;
	}
	return NOK;
}


Error_Status SET_SYSCLKSRC(uint_32t CLK)
{
	uint_32t LOC_tmp = RCC_CFGR & RCC_SW_CLR;
	LOC_tmp |=CLK;
	RCC_CFGR = LOC_tmp;
	switch(CLK)
  {
	case RCC_SW_HSI:
		while(!((RCC_CFGR&0x0000000C)==RCC_SWS_HSI));
		return OK;
	case RCC_SW_HSE:
		while(!((RCC_CFGR&0x0000000C)==RCC_SWS_HSE));
		return OK;
	case RCC_SW_PLL:
		while(!((RCC_CFGR&0x0000000C)==RCC_SWS_PLL));
		return OK;
	default:
		return NOK;
	}
}

Error_Status PLL_CONFIG(uint_32t SRC,uint_32t HSE_PRE,uint_32t MULL)
{
	if(!(RCC_CFGR & RCC_SWS_PLL))
  {
		switch(SRC)   
 {
			case RCC_PLL_SRC_HSI:
				RCC_CFGR |= RCC_PLL_SRC_HSI;
				RCC_CFGR |=MULL;
				return OK;
			case RCC_PLL_SRC_HSE:
          switch(HSE_PRE)
        {
					case RCC_PLL_SRC_HSE_PRE_2:
						RCC_CFGR |= RCC_PLL_SRC_HSE;
						RCC_CFGR |= RCC_PLL_SRC_HSE_PRE_2;
						RCC_CFGR |=MULL;
						return OK;
					default:
						RCC_CFGR |= RCC_PLL_SRC_HSE;
						RCC_CFGR |=MULL;
						return OK;
				}
			default:
				return NOK;
		}
	}
	return NOK;
}


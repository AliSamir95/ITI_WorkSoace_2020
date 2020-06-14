#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

typedef unsigned char uint_8t;
typedef unsigned short int uint_16t;
typedef unsigned long int uint_32t;
typedef signed char sint_8t;
typedef signed short int sint_16t;
typedef signed long int sint_32t;

/*
typedef enum{
	status_ok,
	status_nok,
}status_t;
*/
typedef uint_8t Error_Status;


#define OK 0
#define NOK 1

#define ON 1
#define OFF 0

#define RCC_HSI_ON 		    	0x1
#define RCC_HSI_RDY  	    	0x2
#define RCC_HSE_ON   	    	0X10000
#define RCC_HSE_RDY 	    	0x20000
#define RCC_HSE_BYP		    	0x40000
#define RCC_HSE_CSS_ON     	0X80000
#define RCC_PLL_ON		    	0X1000000
#define RCC_PLL_RDY         0X2000000

/* System clock switch*/

#define RCC_SW_HSI			0
#define RCC_SW_HSE			1
#define RCC_SW_PLL			2
#define RCC_SW_CLR			0xFFFFFFFC

/* System clock switch status */
#define RCC_SWS_HSI			0
#define RCC_SWS_HSE			1
#define RCC_SWS_PLL			2



#define RCC_AHB_PRE_OFF		   0X00
#define RCC_AHB_PRE_2		   0X80
#define RCC_AHB_PRE_4		   0X90
#define RCC_AHB_PRE_8          0XA0
#define RCC_AHB_PRE_16         0XB0
#define RCC_AHB_PRE_64         0XC0
#define RCC_AHB_PRE_128        0XD0
#define RCC_AHB_PRE_256        0XE0
#define RCC_AHB_PRE_512        0XF0


#define RCC_APB1_PRE_OFF        0X000
#define RCC_APB1_PRE_2          0X400
#define RCC_APB1_PRE_4          0X500
#define RCC_APB1_PRE_8          0X600
#define RCC_APB1_PRE_16         0X700

#define RCC_APB2_PRE_OFF        0X0000
#define RCC_APB2_PRE_2          0X2000
#define RCC_APB2_PRE_4          0X2800
#define RCC_APB2_PRE_8          0X3000
#define RCC_APB2_PRE_16         0X3800

#define RCC_ADC_PRE_2               0X0000
#define RCC_ADC_PRE_4               0X4000
#define RCC_ADC_PRE_8               0X8000
#define RCC_ADC_PRE_16              0XC000

/* PLL Source */
#define RCC_PLL_SRC_HSI				0X00000
#define RCC_PLL_SRC_HSE				0X10000
#define RCC_PLL_SRC_HSE_PRE_2		0X30000

/* PLL DIVIDER */
#define RCC_PLL_MULL_2               0X000000
#define RCC_PLL_MULL_3               0X040000
#define RCC_PLL_MULL_4               0X080000
#define RCC_PLL_MULL_5               0X0C0000
#define RCC_PLL_MULL_6               0X100000
#define RCC_PLL_MULL_7               0X140000
#define RCC_PLL_MULL_8               0X180000
#define RCC_PLL_MULL_9               0X1C0000
#define RCC_PLL_MULL_10              0X200000
#define RCC_PLL_MULL_11              0X240000
#define RCC_PLL_MULL_12              0X280000
#define RCC_PLL_MULL_13              0X2C0000
#define RCC_PLL_MULL_14              0X300000
#define RCC_PLL_MULL_15              0X340000
#define RCC_PLL_MULL_16              0X380000
#define RCC_PLL_MULL_16_2            0X3C0000

#define RCC_USB_PRE_1.5				       0X000000
#define RCC_USB_PRE_OFF				       0X400000

#define RCC_MCO_OFF 				         0X0000000
#define RCC_MCO_SYSCLK               0X0400000
#define RCC_MCO_HSI                  0X0500000
#define RCC_MCO_HSE                  0X0600000
#define RCC_MCO_PLL                  0X0700000

#endif

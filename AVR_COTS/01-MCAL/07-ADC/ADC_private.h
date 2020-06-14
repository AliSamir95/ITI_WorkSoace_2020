#*ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H



void __vector_11(void)  __attribute__(signal);

/*macros FOR ADMUX REG PINS*/



/*macros FOR ADCSRA REG PINS*/


/*macros FOR RESOLUTIN*/


/*ADC_STATE*/

#define ADC_u8_STATE_IDLE   0
#define ADC_u8_STATE_BUSY   1

/*ISR State*/

#define ADC_u8_SINGLE_CONVERSION   0
#define ADC_u8_CHAIN_CONVERSION   1



#endif

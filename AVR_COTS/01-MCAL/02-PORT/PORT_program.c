#include <STD_TYPES.h>
#include <BIT_MATH.h>

#include <PORT_interface.h>
#include <PORT_register.h>
#include <PORT_config.h>
#include <PORT_private.h>


void PortInitialize(void)
 {
  
	DDRA = PORTA_Dir;
	DDRB = PORTB_Dir;
	DDRC = PORTC_Dir;
	DDRD = PORTD_Dir;
  
  PORTA=PORTA_INITIALVALUE ;
  PORTB=PORTB_INITIALVALUE ;
  PORTC=PORTC_INITIALVALUE ;
  PORTD=PORTD_INITIALVALUE ;

  }


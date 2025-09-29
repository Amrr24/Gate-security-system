#include "gpio.h"
#include "common_macros.h"
#include "timer0.h"
#include <avr/delay.h>
#include "std_types.h"
#include <avr/interrupt.h>
void wait_3(void);
int tick = 0 ;
int main (void ){
	SREG  |= (1<<7);
	GPIO_setupPinDirection(PORTB_ID,PIN6_ID, PIN_OUTPUT);
	Timer0_config config = {CLOCK_1024,CTC,0,250};
	Timer0_init(&config);
	Timer0_SetcallBack(&wait_3);
	GPIO_writePin(PORTB_ID,PIN6_ID, LOGIC_HIGH);
	while (1){
	}




	return 0 ;
}
void wait_3(void){

	if (tick == 50){

		GPIO_writePin(PORTB_ID,PIN6_ID, LOGIC_LOW);
		tick = 0 ;
	}
	tick ++ ;
}

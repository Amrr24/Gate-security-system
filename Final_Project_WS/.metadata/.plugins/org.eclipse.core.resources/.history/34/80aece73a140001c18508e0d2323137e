
#include "std_types.h"
#ifndef TIMER0_H_
#define TIMER0_H_
typedef enum {
	NO_CLOCK , CLOCK_1,CLOCK_8,CLOCK_64,CLOCK_256,CLOCK_1024,EX_CLOCK_FALL ,EX_CLOCK_RISE
}Prescaler;
typedef enum {
	NORMAL , PWM_PH , CTC , FAT_PWM
}Mode;
typedef struct {
	Prescaler clock ;
	Mode mode ;
	uint16 init_value ;
	uint16 comp_value ;
}Timer0_config;
void Timer0_init(const Timer0_config *ptr);
void Timer0_SetcallBack(void(*a_ptr)(void));
void Time0_deinit(void);

#endif /* TIMER0_H_ */

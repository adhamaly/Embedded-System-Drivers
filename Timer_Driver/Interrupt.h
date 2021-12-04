/*
 * Interrupt.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

// interrupt vector numbers..

#define INT0_VECT 1
#define INT1_VECT 2
#define INT2_VECT 3
#define TIMER2_COMP_VECT 4
#define TIMER2_OVF_VECT 5
#define TIMER1_CAPT_VECT 6
#define TIMER1_COMPA_VECT 7
#define TIMER1_COMPB_VECT 8
#define TIMER1_OVF_VECT 9
#define TIMER0_COMP_VECT 10
#define TIMER0_OVF_VECT 11


typedef enum{
	_ISC00 = 0,
	_ISC01,
	_ISC10,
	_ISC11
}MCUCR_R;

typedef enum{
	_ISC2 = 6
}MCUCSR_R;

typedef enum{
	_INT2 = 5,
	_INT1,
	_INT0,
}GICR_R;

typedef enum{
	_INTF2 = 5,
	_INTF1,
	_INTF0,
}GIFR_R;

typedef enum{
	_I_BIT = 7,
}SREG_R;

void __vector_x(void) __attribute__((signal,naked,INTR_ATTRS));
#endif /* INTERRUPT_H_ */

/*
 *  memmap.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */

#ifndef MEMMAP_H_
#define MEMMAP_H_

// PORTS interface
#define PORTA (*((volatile uint8*)0x3B ))
#define DDRA (*((volatile uint8*)0x3A ))
#define PINA (*((volatile uint8*)0x39))
#define PORTB (*((volatile uint8*)0x38 ))
#define DDRB (*((volatile uint8*)0x37 ))
#define PINB (*((volatile uint8*)0x36))
#define PORTC (*((volatile uint8*)0x35 ))
#define DDRC (*((volatile uint8*)0x34 ))
#define PINC (*((volatile uint8*)0x33))
#define PORTD (*((volatile uint8*)0x32 ))
#define DDRD (*((volatile uint8*)0x31 ))
#define PIND (*((volatile uint8*)0x30))

// ADC registers..
#define ADCMUX (*((volatile uint8*)0x27))
#define ADCSRA (*((volatile uint8*)0x26))
#define ADCH (*((volatile uint8*)0x25))
#define ADCL (*((volatile uint8*)0x24))
#define SFIOR (*((volatile uint8*)0x50))

// External Interrupt Register..
#define MCUCR (*((volatile uint8*)0x55))
#define MCUCSR (*((volatile uint8*)0x54))
#define SREG (*((volatile uint8*)0x5F))
#define GICR (*((volatile uint8*)0x5B))
#define GIFR (*((volatile uint8*)0x5A))


#endif /* MEMMAP_H_ */

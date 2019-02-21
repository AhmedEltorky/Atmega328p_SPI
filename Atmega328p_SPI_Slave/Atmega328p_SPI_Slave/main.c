/*
 * Atmega328p_SPI_Slave.c
 *
 * Created: 2/18/19 11:12:18 PM
 * Author : Ahmed El-Torky
 */ 

#define F_CPU 1000000ul
#include <avr/io.h>
#include <avr/interrupt.h>

#define SS DDB2
#define MOSI DDB3
#define MISO DDB4
#define SCK DDB5


int main(void)
{
	DDRD = 0xFF; // set port D as output
	// SPI initialization
	DDRB |= (1 << MISO); // Set MISO output, all others input
	SPCR |= (1 << SPE); // Enable SPI
	SPCR |= (1 << SPIE); // Enable SPI interrupt
	sei(); // set global interrupt
	
	PORTD = 0xFF; 
	
    while (1) 
    {	
    }
}

ISR (SPI_STC_vect){	
	PORTD = ~SPDR; // set port D as SPI data Register
}

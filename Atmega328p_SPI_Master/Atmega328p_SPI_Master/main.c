/*
 * Atmega328p_SPI_Master.c
 *
 * Created: 2/18/19 10:57:32 PM
 * Author : Ahmed El-Torky
 */ 

#define F_CPU 1000000ul
#include <avr/io.h>

#define SS DDB2
#define MOSI DDB3
#define MISO DDB4
#define SCK DDB5


int main(void)
{
	DDRD = 0x00; // set port D as input
	// SPI initialization
	DDRB |= (1 << MOSI) | (1 << SCK) | (1 << SS); // Set MOSI, SCK and SS as output
	SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0); // Enable SPI, set SPI Master mode, set clock rate fck/16
	char oldData = 0;
	
    while (1) 
    {
		char SPIData = PIND; // read user data  from port D
		if (SPIData != oldData) { // if data changed
			PORTB &= ~(1 << SS); // enable slave
			SPDR = SPIData; // start transmission			
			while(!(SPSR & (1 << SPIF))); // Wait for transmission complete
			oldData = SPIData;
			PORTB |= (1 << SS); // disable slave
		}
    }
}



#include "registers.h"
#include "adc.h"
#include "serial.h"
#include <stdlib.h>
#include <unistd.h>
#include <string>

void delay() {
	for (int i = 0; i<200000; i++);
}

SerialPort serial;
Adc adc;

int main()
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER |= 1<<28;
	serial.write ("Hello \n");
	for(;;){
		adc.start();
		int n = adc.read();
		serial.write((char*)n);
		serial.write ("Hello \n");
		GPIOD->BSRR = 1<<14;
		delay();
	}
	return 0;
}

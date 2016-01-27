
#include "registers.h"
#include "serial.h"
#include <stdlib.h>
#include <unistd.h>

//PD14: red led
void delay() {
	for (int i = 0; i<200000; i++);
}
SerialPort serial;

int main()
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER |= 1<<24;
	GPIOD->MODER |= 1<<26;
	GPIOD->MODER |= 1<<28;
	GPIOD->MODER |= 1<<30;
	for(int n =0; n<4; n++){
		GPIOD->BSRR=1<<12+n;
		delay();
	}
	int n=0;

	while(1)
	{
		if(n==0) GPIOD->BSRR=1<<(15);
		else GPIOD->BSRR=1<<(12+n-1);
		serial.write("Hello world\r\n");
		if (n==4){
			GPIOD->BSRR=1<<(12+16);
			n=1;
		}
		else {
			GPIOD->BSRR=1<<(12+n+16);	
			n++;
		}
		delay();
	}
}

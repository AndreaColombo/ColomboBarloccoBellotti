
#include "registers.h"
#include "serial.h"
#include <stdlib.h>
#include <unistd.h>
#include <stm32f407xx.h>
#include "tm_stm32f4_adc.h"

//PD14: red led
void delay() {
	for (int i = 0; i<200000; i++);
}
SerialPort serial;

int main()
{
	tm_ADC_InitADC (ADC1);
}

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
	for(;;){
		int n = adc.read();
		serial.write((char*)n);
		delay();
	}
	return 0;
}

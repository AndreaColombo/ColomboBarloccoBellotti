#include "adc.h"
#include <stm32f407xx.h>
//we will be using only ADC1

Adc::Adc(){
	//pc1 = canale 11 adc
	//setup canale 11 adc analog input
	ADC1->CR1 = 1<<3;
	ADC1->CR1 |= 1<<1;
	ADC1->CR1 |= 1<<0;
	ADC1->CR2 |= ADC_CR2_ADON;
	
	
}

void Adc::init(){
	
}

void Adc::start(){
	//cr1 bit 8 scan
	//cr2 bit 30 start
}

int read(){
	return (int) ADC1->DR;
}
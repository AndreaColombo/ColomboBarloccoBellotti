#include "adc.h"
#include "registers.h"
//we will be using only ADC1

Adc::Adc(){
	//pc1 = canale 11 adc
	//setup canale 11 adc analog input
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	RCC->APB1ENR |= RCC_APB2ENR_ADC1EN;
	
	ADC1->CR1 = 1<<3;
	ADC1->CR1 |= 1<<1;
	ADC1->CR1 |= 1<<1;
	ADC1->CR2 |= ADC_CR2_ADON;
	
	GPIOC->MODER |= 1<<2;
	GPIOC->MODER |= 1<<3;
	
}

void Adc::init(){
	return;
}

void Adc::start(){
	//cr1 bit 8 scan
	//cr2 bit 30 start
	ADC1->CR1 = 1<<8;
	ADC1->CR2 = 1<<30;
}

int Adc::read(){
	//while ((ADC1->SR & 1<<1)==0);
	return (int) ADC1->DR;
}
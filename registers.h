
/*
 * Extremely simplified code to allow accessing peripheral registers from C/C++
 * In a real application one would use the register definition in the CMSIS.
 */

#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdint.h>

/*
 * Reset and Clock Control. This peripheral is used to turn on the other peripherals
 */

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t PLLCFGR;
  volatile uint32_t CFGR;
  volatile uint32_t CIR;
  volatile uint32_t AHB1RSTR;
  volatile uint32_t AHB2RSTR;
  volatile uint32_t AHB3RSTR;
  uint32_t          RESERVED0;
  volatile uint32_t APB1RSTR;
  volatile uint32_t APB2RSTR;
  uint32_t          RESERVED1[2];
  volatile uint32_t AHB1ENR;
  volatile uint32_t AHB2ENR;
  volatile uint32_t AHB3ENR;
  uint32_t          RESERVED2;
  volatile uint32_t APB1ENR;
  volatile uint32_t APB2ENR;
} RCC_TypeDef;

#define RCC ((RCC_TypeDef *)0x40023800)
#define RCC_AHB1ENR_GPIOAEN  (0x00000001)
#define RCC_AHB1ENR_GPIODEN  (0x00000008)
#define RCC_APB1ENR_USART2EN (0x00020000)

/*
 * GPIOD. This peripheral controls port D of the GPIOs
 */

typedef struct
{
  volatile uint32_t MODER;
  volatile uint32_t OTYPER;
  volatile uint32_t OSPEEDR;
  volatile uint32_t PUPDR;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t LCKR;
  volatile uint32_t AFR[2];
} GPIO_TypeDef;

#define GPIOA ((GPIO_TypeDef *)0x40020000)
#define GPIOD ((GPIO_TypeDef *)0x40020C00)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000)
#define  RCC_AHB1ENR_GPIOCEN                 ((uint32_t)0x00000004)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)

/*
 * USART2. This peripheral is a serial port
 */

typedef struct
{
  volatile uint16_t SR;
  uint16_t          RESERVED0;
  volatile uint16_t DR;
  uint16_t          RESERVED1;
  volatile uint16_t BRR;
  uint16_t          RESERVED2;
  volatile uint16_t CR1;
  uint16_t          RESERVED3;
  volatile uint16_t CR2;
  uint16_t          RESERVED4;
  volatile uint16_t CR3;
  uint16_t          RESERVED5;
  volatile uint16_t GTPR;
  uint16_t          RESERVED6;
} USART_TypeDef;

#define USART2 ((USART_TypeDef *)0x40004400)

#define  USART_SR_RXNE    (0x0020)
#define  USART_SR_TXE     (0x0080)

#define  USART_CR1_RE     (0x0004)
#define  USART_CR1_TE     (0x0008)
#define  USART_CR1_RXNEIE (0x0020)
#define  USART_CR1_UE     (0x2000)

/*
 * NVIC. Nested vectored interrupt controller.
 * This peripheral controls all interrupts in the microcontroller
 */

typedef struct
{
   volatile uint32_t ISER[8];
} NVIC_Type;

typedef struct
{
  volatile uint32_t SR;     /*!< ADC status register,                         Address offset: 0x00 */
  volatile uint32_t CR1;    /*!< ADC control register 1,                      Address offset: 0x04 */      
  volatile uint32_t CR2;    /*!< ADC control register 2,                      Address offset: 0x08 */
  volatile uint32_t SMPR1;  /*!< ADC sample time register 1,                  Address offset: 0x0C */
  volatile uint32_t SMPR2;  /*!< ADC sample time register 2,                  Address offset: 0x10 */
  volatile uint32_t JOFR1;  /*!< ADC injected channel data offset register 1, Address offset: 0x14 */
  volatile uint32_t JOFR2;  /*!< ADC injected channel data offset register 2, Address offset: 0x18 */
  volatile uint32_t JOFR3;  /*!< ADC injected channel data offset register 3, Address offset: 0x1C */
  volatile uint32_t JOFR4;  /*!< ADC injected channel data offset register 4, Address offset: 0x20 */
  volatile uint32_t HTR;    /*!< ADC watchdog higher threshold register,      Address offset: 0x24 */
  volatile uint32_t LTR;    /*!< ADC watchdog lower threshold register,       Address offset: 0x28 */
  volatile uint32_t SQR1;   /*!< ADC regular sequence register 1,             Address offset: 0x2C */
  volatile uint32_t SQR2;   /*!< ADC regular sequence register 2,             Address offset: 0x30 */
  volatile uint32_t SQR3;   /*!< ADC regular sequence register 3,             Address offset: 0x34 */
  volatile uint32_t JSQR;   /*!< ADC injected sequence register,              Address offset: 0x38*/
  volatile uint32_t JDR1;   /*!< ADC injected data register 1,                Address offset: 0x3C */
  volatile uint32_t JDR2;   /*!< ADC injected data register 2,                Address offset: 0x40 */
  volatile uint32_t JDR3;   /*!< ADC injected data register 3,                Address offset: 0x44 */
  volatile uint32_t JDR4;   /*!< ADC injected data register 4,                Address offset: 0x48 */
  volatile uint32_t DR;     /*!< ADC regular data register,                   Address offset: 0x4C */
} ADC_TypeDef;

#define ADC1_BASE             (APB2PERIPH_BASE + 0x2000)
#define ADC1                ((ADC_TypeDef *) ADC1_BASE)
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000)
#define PERIPH_BASE           ((uint32_t)0x40000000) /*!< Peripheral base address in the alias region                                */
#define  RCC_AHB1ENR_GPIOCEN                 ((uint32_t)0x00000004)
#define  RCC_APB2ENR_ADC1EN                  ((uint32_t)0x00000100)
#define  ADC_CR2_ADON                        ((uint32_t)0x00000001) 

#define NVIC ((NVIC_Type*)0xE000E100)

#endif //REGISTERS_H

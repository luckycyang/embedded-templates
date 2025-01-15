#include "py32f030x8.h"
#include <py32f0xx.h>
#include <stdint.h>
int main() {
  RCC->IOPENR &= ~RCC_IOPENR_GPIOAEN;
  RCC->IOPENR |= RCC_IOPENR_GPIOAEN;
  GPIOA->MODER &= ~GPIO_MODER_MODE2;
  GPIOA->MODER |= GPIO_MODER_MODE2 & (1U << GPIO_MODER_MODE2_Pos);
  GPIOA->OTYPER &= ~GPIO_OTYPER_OT2;
  GPIOA->OTYPER |= GPIO_OTYPER_OT2 & (1U << GPIO_OTYPER_OT2_Pos);
  while (1) {
    GPIOA->ODR = GPIO_ODR_OD2 ^ GPIOA->ODR;
    __WFI();
  }
}


#include "SEGGER_RTT.h"
#include "py32f030x8.h"
#include "py32f0xx_hal_cortex.h"
#include "py32f0xx_hal_gpio.h"
#include "py32f0xx_hal_rcc.h"
#include <py32f0xx_hal.h>

static void KEY_Init(void);
int main() {
  HAL_Init();
  KEY_Init();
  HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);
  while (1) {
    SEGGER_RTT_printf(0, "6\r\n");
  }
}

static void KEY_Init(void) {
  __HAL_RCC_GPIOA_CLK_ENABLE();
  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin = GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  NVIC_SetPriority(EXTI4_15_IRQn, 1);
  HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
}

void EXTI4_15_IRQHandler(void) {
  SEGGER_RTT_printf(0, "Release Key\r\n");
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);
}

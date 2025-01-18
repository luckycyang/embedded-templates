#include "SEGGER_RTT.h"
#include "py32f030x8.h"
#include "py32f0xx_hal_cortex.h"
#include "py32f0xx_hal_gpio.h"
#include "py32f0xx_hal_rcc.h"
#include <py32f0xx_hal.h>

static void KEY_Init(void);
int main() {
  // 有个问题是 使用 HAL_Init() 会造成卡死，IPSR 值为 15
  // HAL_Init();
  KEY_Init();
  HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);
  while (1) {
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
  uint32_t result;
  __asm__ volatile("MRS %0, ipsr" : "=r"(result));
  SEGGER_RTT_printf(0, "Press Key, IPSR: %d\r\n", result);
  NVIC_ClearPendingIRQ(EXTI4_15_IRQn);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);
}


#include "py32f0xx_hal.h"
#include "py32f0xx_hal_gpio.h"
#include "py32f0xx_hal_rcc.h"
#include <stdint.h>

typedef struct Output {
  GPIO_TypeDef *port;
  uint32_t Pin;
  void (*set_hight)(struct Output *);
  void (*set_low)(struct Output *);
  void (*toggle)(struct Output *);
} Output;

// 函数声明
void _set_hight(Output *pin);
void _set_low(Output *pin);
void _toggle(Output *pin);
void LED_Init(Output *led);
void Output_Init(Output *pin);

int main() {
  HAL_Init();

  Output led;
  LED_Init(&led);
  Output_Init(&led);

  while (1) {
    HAL_Delay(500);
    led.toggle(&led);
  }
}

void _set_hight(Output *pin) {
  HAL_GPIO_WritePin(pin->port, pin->Pin, GPIO_PIN_SET);
}

void _set_low(Output *pin) {
  HAL_GPIO_WritePin(pin->port, pin->Pin, GPIO_PIN_RESET);
}

void _toggle(Output *pin) { HAL_GPIO_TogglePin(pin->port, pin->Pin); }

void LED_Init(Output *led) {
  __HAL_RCC_GPIOA_CLK_ENABLE();
  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin = GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  led->Pin = GPIO_PIN_2;
  led->port = GPIOA;
  Output_Init(led);
}

void Output_Init(Output *pin) {
  pin->set_hight = _set_hight;
  pin->set_low = _set_low;
  pin->toggle = _toggle;
}

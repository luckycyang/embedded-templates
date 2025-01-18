#include "py32f0xx_hal.h"
#include <SEGGER_RTT.h>
#include <py32f0xx_hal_rcc.h>
#include <stdint.h>

int main() {
  uint32_t counter = 0;
  HAL_Init();
  while (1) {
    counter = HAL_GetTick();
    /*SEGGER_RTT_printf(0, "Tick: %d", counter);*/
  }
}

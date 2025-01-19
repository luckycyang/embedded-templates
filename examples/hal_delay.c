#include "py32f0xx_hal.h"
#include "py32f0xx_hal_def.h"
#include <SEGGER_RTT.h>
#include <py32f0xx_hal_rcc.h>
#include <stdint.h>

int main() {
  uint32_t counter = 0;
  if (HAL_Init() == HAL_OK) {
    SEGGER_RTT_printf(0, "HAL Init Passed\r\n");
  } else {
    SEGGER_RTT_printf(0, "HAL Init Failed\r\n");
  }

  while (1) {
    HAL_Delay(250);
    /*SEGGER_RTT_printf(0, "Tick: %d", counter);*/
  }
}

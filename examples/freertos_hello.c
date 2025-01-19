#include "py32f0xx_hal.h"
#include <FreeRTOS.h>
#include <SEGGER_RTT.h>
#include <task.h>

TaskHandle_t TaskHandle;

static void hello(void *pvParameters) {
  SEGGER_RTT_printf(0, "Hello, FreeRTOS\r\n");
}

int main() {
  HAL_Init();
  SEGGER_RTT_Init();
  xTaskCreate(hello, "task0", 128, NULL, 1, NULL);
  SEGGER_RTT_printf(0, "Created task0\r\n");

  vTaskStartScheduler();
  while (1)
    ;
}

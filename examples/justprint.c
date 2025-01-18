#include <SEGGER_RTT.h>
#include <stdint.h>
int main() {
  uint32_t i = 0;
  SEGGER_RTT_Init();

  while (1) {
    SEGGER_RTT_printf(0, "Hello: %d\r\n", i++);
  }
}

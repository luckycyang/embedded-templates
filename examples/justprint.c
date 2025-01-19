#include <SEGGER_RTT.h>
#include <stdint.h>

const char *handlers[] = {
    "Reset_Handler",                  // Reset Handler
    "NMI_Handler",                    // NMI Handler
    "HardFault_Handler",              // Hard Fault
    "BusFault_Handler",               // Bus Fault
    "UsageFault_Handler",             // Usage Fault
    "SVC_Handler",                    // SVCall Handler
    "(void (*)(void))0",              // Reserved
    "(void (*)(void))0",              // Reserved
    "PendSV_Handler",                 // PendSV Handler
    "SysTick_Handler",                // SysTick Handler External Interrupts
    "WWDG_IRQHandler",                // Window Watchdog
    "PVD_IRQHandler",                 // PVD
    "RTC_IRQHandler",                 // RTC
    "FLASH_IRQHandler",               // Flash
    "RCC_IRQHandler",                 // RCC
    "EXTI0_1_IRQHandler",             // EXTI Line 0 and 1
    "EXTI2_3_IRQHandler",             // EXTI Line 2 and 3
    "EXTI4_15_IRQHandler",            // EXTI Line 4 to 15
    "(void (*)(void))0",              // Reserved
    "DMA1_Channel1_IRQHandler",       // DMA1 Channel 1
    "DMA1_Channel2_3_IRQHandler",     // DMA1 Channel 2 and 3
    "(void (*)(void))0",              // Reserved
    "ADC_COMP_IRQHandler",            // ADC and Comparator
    "TIM1_BRK_UP_TRG_COM_IRQHandler", // TIM1 Break, Update, Trigger and
                                      // Commutation
    "TIM1_CC_IRQHandler",             // TIM1 Capture Compare
    "(void (*)(void))0",              // Reserved
    "TIM3_IRQHandler",                // TIM3
    "LPTIM1_IRQHandler",              // LPTIM1
    "(void (*)(void))0",              // Reserved
    "TIM14_IRQHandler",               // TIM14
    "(void (*)(void))0",              // Reserved
    "TIM16_IRQHandler",               // TIM16
    "TIM17_IRQHandler",               // TIM17
    "I2C1_IRQHandler",                // I2C1
    "(void (*)(void))0",              // Reserved
    "SPI1_IRQHandler",                // SPI1
    "SPI2_IRQHandler",                // SPI2
    "USART1_IRQHandler",              // USART1
    "USART2_IRQHandler",              // USART2
    "(void (*)(void))0",              // Reserved
    "LED_IRQHandler",                 // LED
    "(void (*)(void))0"               // Reserved
};

int main() {
  uint32_t i = 0;
  extern uint32_t isr_vector;
  SEGGER_RTT_Init();
  while (1) {
    while (i < 42) {
      SEGGER_RTT_printf(0, "%-35s: \t0x%08X\r\n", handlers[i],
                        (&isr_vector)[i]);
      i += 1;
    }
  }
}

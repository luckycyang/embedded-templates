#include <stdint.h>

extern uint32_t _sidata, _sdata, _edata, _sbss, _ebss;

void reset_handler(void);
void default_handler(void);
extern int main(void);
void nmi_handler(void) __attribute__((weak, alias("default_handler")));
void hardfault_handler(void) __attribute__((weak, alias("default_handler")));
void busfault_handler(void) __attribute__((weak, alias("default_handler")));
void usagefault_handler(void) __attribute__((weak, alias("default_handler")));
void svc_handler(void) __attribute__((weak, alias("default_handler")));
void pend_sv_handler(void) __attribute__((weak, alias("default_handler")));
void systick_handler(void) __attribute__((weak, alias("default_handler")));

void wwdg_irqhandler(void) __attribute__((weak, alias("default_handler")));
void pvd_irqhandler(void) __attribute__((weak, alias("default_handler")));
void rtc_irqhandler(void) __attribute__((weak, alias("default_handler")));
void flash_irqhandler(void) __attribute__((weak, alias("default_handler")));
void rcc_irqhandler(void) __attribute__((weak, alias("default_handler")));
void exti0_1_irqhandler(void) __attribute__((weak, alias("default_handler")));
void exti2_3_irqhandler(void) __attribute__((weak, alias("default_handler")));
void exti4_15_irqhandler(void) __attribute__((weak, alias("default_handler")));
void dma1_channel1_irqhandler(void)
    __attribute__((weak, alias("default_handler")));
void dma1_channel2_3_irqhandler(void)
    __attribute__((weak, alias("default_handler")));
void adc_comp_irqhandler(void) __attribute__((weak, alias("default_handler")));
void tim1_brk_up_trg_com_irqhandler(void)
    __attribute__((weak, alias("default_handler")));
void tim1_cc_irqhandler(void) __attribute__((weak, alias("default_handler")));
void tim3_irqhandler(void) __attribute__((weak, alias("default_handler")));
void lptim1_irqhandler(void) __attribute__((weak, alias("default_handler")));
void tim14_irqhandler(void) __attribute__((weak, alias("default_handler")));
void tim16_irqhandler(void) __attribute__((weak, alias("default_handler")));
void tim17_irqhandler(void) __attribute__((weak, alias("default_handler")));
void i2c1_irqhandler(void) __attribute__((weak, alias("default_handler")));
void spi1_irqhandler(void) __attribute__((weak, alias("default_handler")));
void spi2_irqhandler(void) __attribute__((weak, alias("default_handler")));
void usart1_irqhandler(void) __attribute__((weak, alias("default_handler")));
void usart2_irqhandler(void) __attribute__((weak, alias("default_handler")));
void led_irqhandler(void) __attribute__((weak, alias("default_handler")));

void (*const isr_vector[])(void) __attribute__((section(".isr_vector"))) = {
    reset_handler,      // Reset Handler
    nmi_handler,        // NMI Handler
    hardfault_handler,  // Hard Fault
    busfault_handler,   // Bus Fault
    usagefault_handler, // Usage Fault
    svc_handler,        // SVCall Handler
    (void (*)(void))0,  // Reserved
    (void (*)(void))0,  // Reserved
    pend_sv_handler,    // PendSV Handler
    systick_handler,    // SysTick Handler
    // External Interrupts
    wwdg_irqhandler,                // Window Watchdog
    pvd_irqhandler,                 // PVD
    rtc_irqhandler,                 // RTC
    flash_irqhandler,               // Flash
    rcc_irqhandler,                 // RCC
    exti0_1_irqhandler,             // EXTI Line 0 and 1
    exti2_3_irqhandler,             // EXTI Line 2 and 3
    exti4_15_irqhandler,            // EXTI Line 4 to 15
    (void (*)(void))0,              // Reserved
    dma1_channel1_irqhandler,       // DMA1 Channel 1
    dma1_channel2_3_irqhandler,     // DMA1 Channel 2 and 3
    (void (*)(void))0,              // Reserved
    adc_comp_irqhandler,            // ADC and Comparator
    tim1_brk_up_trg_com_irqhandler, // TIM1 Break, Update, Trigger and
                                    // Commutation
    tim1_cc_irqhandler,             // TIM1 Capture Compare
    (void (*)(void))0,              // Reserved
    tim3_irqhandler,                // TIM3
    lptim1_irqhandler,              // LPTIM1
    (void (*)(void))0,              // Reserved
    tim14_irqhandler,               // TIM14
    (void (*)(void))0,              // Reserved
    tim16_irqhandler,               // TIM16
    tim17_irqhandler,               // TIM17
    i2c1_irqhandler,                // I2C1
    (void (*)(void))0,              // Reserved
    spi1_irqhandler,                // SPI1
    spi2_irqhandler,                // SPI2
    usart1_irqhandler,              // USART1
    usart2_irqhandler,              // USART2
    (void (*)(void))0,              // Reserved
    led_irqhandler,                 // LED
    (void (*)(void))0               // Reserved
};

void reset_handler(void) {
  uint32_t data_size = (uint32_t)&_edata - (uint32_t)&_sdata;
  uint8_t *flash_data = (uint8_t *)&_sidata;
  uint8_t *sram_data = (uint8_t *)&_sdata;

  for (uint32_t i = 0; i < data_size; i++) {
    sram_data[i] = flash_data[i];
  }

  // Zero-fill .bss section in SRAM
  uint32_t bss_size = (uint32_t)&_ebss - (uint32_t)&_sbss;
  uint8_t *bss = (uint8_t *)&_sbss;

  for (uint32_t i = 0; i < bss_size; i++) {
    bss[i] = 0;
  }
  main();
}
void default_handler(void) {
  while (1) {
  }
}

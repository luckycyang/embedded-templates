#include <stdint.h>

extern uint32_t _sidata, _sdata, _edata, _sbss, _ebss;

void reset_handler(void);
void default_handler(void);
extern int main(void);
void nmi_handler(void) __attribute__((weak, alias("default_handler")));
void hardfault_handler(void) __attribute__((weak, alias("default_handler")));
void busfault_handler(void) __attribute__((weak, alias("default_handler")));
void usagefault_handler(void) __attribute__((weak, alias("default_handler")));

void (*const isr_vector[])(void) __attribute__((section(".isr_vector"))) = {
    reset_handler,    nmi_handler,        hardfault_handler,
    busfault_handler, usagefault_handler,
    // wait to add
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

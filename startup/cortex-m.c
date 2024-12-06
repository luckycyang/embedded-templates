#include <stdint.h>

void reset_handler(void);
void default_handler(void);
extern int main(void);
void nmi_handler(void) __attribute__((weak, alias("default_handler")));
void hardfault_handler(void) __attribute__((weak, alias("default_handler")));
void busfault_handler(void) __attribute__((weak, alias("default_handler")));
void usagefault_handler(void) __attribute__((weak, alias("default_handler")));

void (*const isr_vector[])(void) __attribute__((section(".isr_vector"))) = {
    (void (*)(void))(0x20000000 + 20 * 1024), // stack point

    reset_handler,
    nmi_handler,
    hardfault_handler,
    busfault_handler,
    usagefault_handler,
    // wait to add
};

void reset_handler(void) { main(); }
void default_handler(void) {
  while (1) {
  }
}

#include <stdint.h>

#define RCC_BASE 0x40021000
#define RCC_APB2ENR (volatile uint32_t *)(RCC_BASE + 0x18)

#define GPIOC_BASE 0x40011000
#define GPIOC_CRH (volatile uint32_t *)(GPIOC_BASE + 0x04)
#define GPIOC_ODR (volatile uint32_t *)(GPIOC_BASE + 0x0C)

// data
uint32_t tdata[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
uint32_t t1[10];
int main(void) {
  // Enable APB2
  *RCC_APB2ENR |= 0x010;
  // Set PC13 as output
  *GPIOC_CRH &= 0xff0fffff;
  *GPIOC_CRH |= 0x00200000;

  *GPIOC_ODR |= 0x2000;
  //*GPIOC_ODR &= ~0x2000;

  *t1 = *tdata;

  while (1) {
    for (int i = 0; i < 10; i++) {
      *(t1 + i) = *(tdata + i);
    }
  }
}

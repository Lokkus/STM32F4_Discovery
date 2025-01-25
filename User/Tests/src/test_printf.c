#include "test_printf.h"
#include "stm32f4xx_uart_u.h"

void test_printf(void) {
    float f = 3.14;
    printf("Wartosc liczby zmiennoprzecinkowej: %f\r\n", f);
    const char* s = "Hello, World!";
    printf("Napis: %s\r\n", s);
}
#ifndef TEST_UART_H
#define TEST_UART_H

#ifdef __cplusplus
extern "C" {
#endif

#include "app_peripherial.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>

void test_uart_send_data(void);

#ifdef __cplusplus
}
#endif

#endif // TEST_UART_H

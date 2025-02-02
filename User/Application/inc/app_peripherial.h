#ifndef APP_PERIPHERIAL_H
#define APP_PERIPHERIAL_H

#include "stm32f4xx_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

// Function declarations for peripheral handling
void app_gpio_init(void);
void app_uart_init(void);
void app_timer_init(void);

void app_peripherial_init(void);
UART_HandleTypeDef* app_get_uart1_handle();
TIM_HandleTypeDef* app_get_tim6_handle();

#ifdef __cplusplus
}
#endif

#endif // APP_PERIPHERIAL_H

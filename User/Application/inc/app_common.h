#ifndef APP_COMMON_H
#define APP_COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

#include "test_uart.h"
#include "test_gpio.h"
#include "app_ds18B20_timer.h"

void app_tests(void);
void app_ds18B20_test(void);

#ifdef __cplusplus
}
#endif

#endif // APP_COMMON_H

#include "app_ds18B20_timer.h"


static void delay_us(uint32_t us)
{
    uint32_t start = __HAL_TIM_GET_COUNTER(app_get_tim6_handle());
    while ((__HAL_TIM_GET_COUNTER(app_get_tim6_handle()) - start) < us);
}
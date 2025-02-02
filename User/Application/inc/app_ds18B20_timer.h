#ifndef APP_DS18B20_TIMER_H
#define APP_DS18B20_TIMER_H

#include "stm32f4xx_hal.h"
#include "app_peripherial.h"

#ifdef __cplusplus
extern "C" {
#endif


// /**
//  * @brief Initializes the DS18B20 temperature sensor with timer-based reading.
//  */
// void DS18B20_Timer_Init(void);

// /**
//  * @brief Starts the temperature measurement process.
//  */
// void DS18B20_Start_Conversion(void);

// /**
//  * @brief Reads the temperature value asynchronously.
//  * @return Temperature in Celsius as a float.
//  */
// float DS18B20_Read_Temperature(void);

// /**
//  * @brief Timer callback function to handle DS18B20 operations.
//  */
// void DS18B20_Timer_Callback(void);

//temp
void test_time(void);


#ifdef __cplusplus
}
#endif

#endif /* APP_DS18B20_TIMER_H */

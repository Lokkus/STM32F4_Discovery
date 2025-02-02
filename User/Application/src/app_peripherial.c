#include "app_peripherial.h"

/**
 * @brief Initializes the UART peripheral.
 * 
 * This function configures the GPIO pins and the UART peripheral for USART1.
 * It sets up the GPIO pins PB6 and PB7 for alternate function push-pull mode,
 * and configures the USART1 peripheral with the following settings:
 * - Baud rate: 115200
 * - Word length: 8 bits
 * - Stop bits: 1
 * - Parity: None
 * - Mode: TX/RX
 * - Hardware flow control: None
 * - Oversampling: 16
 * 
 * @note This function is static and intended to be used only within this file.
 */

static UART_HandleTypeDef huart1;
static TIM_HandleTypeDef htim6;

static void UART1_Init(void);
static void GPIOA_Init(void);
static void GPIOB_Init(void);
static void GPIOD_Init(void);
static void TIM6_Init(void);

static void UART1_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // Enable clock
    __HAL_RCC_USART1_CLK_ENABLE();

    // Configure USART1
    huart1.Instance = USART1;
    huart1.Init.BaudRate = 115200;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.Mode = UART_MODE_TX_RX;
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;
    HAL_UART_Init(&huart1);
}

/* 
GPIO Initialization
*/

static void GPIOA_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // Enable clock
    __HAL_RCC_GPIOA_CLK_ENABLE();

    // Configure GPIO pin for button
    GPIO_InitStruct.Pin = GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

static void GPIOB_Init(void) 
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // Enable clock
    __HAL_RCC_GPIOB_CLK_ENABLE();

    // Configure GPIO pins for USART1 TX (PB6) and RX (PB7)
    GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

static void GPIOD_Init(void) 
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // Enable clock
    __HAL_RCC_GPIOD_CLK_ENABLE();

    // Configure GPIO pin for LED
    GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}


//timer initialization
static void TIM6_Init(void)
{
    __HAL_RCC_TIM6_CLK_ENABLE();

    htim6.Instance = TIM6;
    htim6.Init.Prescaler = 83;  // 1 MHz (1 tick = 1 us)
    htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim6.Init.Period = 65535;  // 16-bitowy licznik → max 65.535 ms
    htim6.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
    HAL_TIM_Base_Init(&htim6);
}

void app_timer_init(void)
{
    TIM6_Init();
}

// GPIO initialization
void app_gpio_init(void)
{
    GPIOA_Init();
    GPIOB_Init();
    GPIOD_Init();
}

// UART initialization
void app_uart_init(void)
{
    UART1_Init();
}

// Peripheral initialization
void app_peripherial_init(void) 
{
    app_gpio_init();
    app_uart_init();
    app_timer_init();
}

UART_HandleTypeDef* app_get_uart1_handle()
{
    return &huart1;
}

TIM_HandleTypeDef* app_get_tim6_handle()
{
    return &htim6;
}
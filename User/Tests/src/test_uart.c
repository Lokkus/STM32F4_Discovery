#include "test_uart.h"

//static functions
static void test_printf(void);
static void test_send_uart_data(uint8_t data);

//test functions
static void test_printf(void)
{
    printf("Test printf\r\n");
    printf("Test printf %d\r\n", 123);
    printf("Test printf %s\r\n", "string");
    printf("Test printf %c\r\n", 'c');
    printf("Test printf %f\r\n", 123.456);
    printf("Test printf %x\r\n", 0x12345678);
    printf("Test printf %X\r\n", 0x12345678);
    printf("Test printf %u\r\n", 123);
    printf("Test printf %o\r\n", 123);
}

static void test_send_uart_data(uint8_t data)
{
    HAL_UART_Transmit(app_get_uart1_handle(), &data, 1, HAL_MAX_DELAY);
}

void test_uart_send_data(void)
{
    test_printf();
    test_send_uart_data(0x55); //173
}


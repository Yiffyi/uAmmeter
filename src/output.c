#include "usart.h"
#include <string.h>

void write(char s[])
{
    HAL_UART_Transmit(&huart1, (uint8_t *)s, strlen(s), HAL_MAX_DELAY);
}

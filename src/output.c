#include <string.h>
#include <stdio.h>

#include "usart.h"

#include "iadc.h"
#include "eadc.h"

void W(char s[])
{
    HAL_UART_Transmit(&huart1, (uint8_t *)s, strlen(s), HAL_MAX_DELAY);
}

void ToSerialStudio()
{
    static char buffer[256];
    PullEADCValue();
    PullIADCValue();
    snprintf(buffer, 256, "/*%.6f,%.4f,%.4f*/\n\r", EADC0, IADC4, IADC5);
    W(buffer);
}
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
    // mV, mV, mV, mA, mA, uA
    float I100 = EADC0/100, I1k = EADC0/1000, I10k = EADC0/10.025E3, I100k = EADC0/100E3*1000;
    snprintf(buffer, 256, "/*%.6f,%.4f,%.4f,%.6f,%.6f,%.6f,%.6f*/\n", EADC0, IADC4, IADC5, I100, I1k, I10k, I100k);
    W(buffer);
}
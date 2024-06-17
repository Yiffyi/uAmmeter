#include <stdio.h>

#include "main.h"
#include "adc.h"
#include "i2c.h"
#include "usart.h"

#include "output.h"
#include "iadc.h"
#include "eadc.h"

void MX_main(void);

int main()
{
    MX_main();

    // HAL_GPIO_WritePin(GPIOA, 1, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_PIN_SET);

    StartInternalADC();
    StartExternalADC();

    while (1)
    {
        HAL_Delay(700);
        ToSerialStudio();
        // write("Main loop\n\r");
        // PullEADCValue();
        // PullIADCValue();
    }
    return 0;
}

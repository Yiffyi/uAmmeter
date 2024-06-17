#include "adc.h"
#include "output.h"

uint16_t iadcBuffer[256], nSamples = 128;
uint32_t sumIn5 = 0, sumIn4 = 0;

void StartInternalADC()
{
    HAL_ADCEx_Calibration_Start(&hadc1);
    HAL_ADC_Start_DMA(&hadc1, (uint32_t *)iadcBuffer, 256);
}

float IADCValue(uint32_t x)
{
    return (float)x * 3288.0f / 4096;
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    if (hadc == &hadc1)
    {
        uint32_t t4 = 0, t5 = 0;
        for (int i = 0; i <= 254; i += 2)
        {
            t5 += iadcBuffer[i];
            t4 += iadcBuffer[i + 1];
        }
        sumIn5 = t5;
        sumIn4 = t4;
    }
    else
    {
        Error_Handler();
    }
}

float PullIADCValue()
{
    float in5 = IADCValue(sumIn5) / nSamples, in4 = IADCValue(sumIn4) / nSamples;
    static char buffer[128];
    sprintf(buffer, "ADC1: in4=%.4f mV, in5=%.4f mV\n\r", in4, in5);
    write(buffer);
    return in4;
}
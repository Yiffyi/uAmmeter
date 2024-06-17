#include "i2c.h"
#include "output.h"

#define MCP_Addr_Write 0xD0
#define MCP_Addr_Read 0xD1

uint8_t eadcBuffer[4];

void StartExternalADC()
{
	static uint8_t mode_data[1];
	mode_data[0] = 0x1C;
	HAL_I2C_Master_Transmit(&hi2c1, MCP_Addr_Write, mode_data, 1, HAL_MAX_DELAY);
}

float EADCValue(uint32_t x)
{
	return (float)x * 15.625f * 0.001;
}

float PullEADCValue()
{
	HAL_I2C_Master_Receive(&hi2c1, MCP_Addr_Read, eadcBuffer, 4, HAL_MAX_DELAY);
	uint32_t x = (uint32_t) eadcBuffer[0] << 16 | (uint32_t) eadcBuffer[1] << 8 | (uint32_t) eadcBuffer[2];
	float out = EADCValue(x);
	static char buffer[128];
	sprintf(buffer, "MCP: raw:%ld, float:%.6f mV\n\r", x, out);
	write(buffer);
	return out;
}
#ifndef _OLED_H_
#define _OLED_H_ 1
// ---------- //

#define OLED_ADDR 0x78

void OLED_Refresh(uint8_t n, uint8_t p);
void OLED_Clear();
void OLED_Init(I2C_HandleTypeDef *hi2c);
void OLED_Cmd(I2C_HandleTypeDef *hi2c, uint8_t cmdlist[], uint8_t cmd_count);



// ---------- //
#endif


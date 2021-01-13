#ifndef __VI2C_H__
#define __VI2C_H__

#define MCU_I2C_MODE_W 0
#define MCU_I2C_MODE_R 1
#ifdef __cplusplus
extern "C" {
#endif
#include "stm32h7xx.h"
#include "mcu.h"
void mcu_vi2c_sda_input(void);
void mcu_vi2c_sda_output(void);
void mcu_vi2c_start(void);
void mcu_vi2c_stop(void);
s32 mcu_vi2c_wait_ack(void);
void mcu_vi2c_ack(void);
s32 mcu_vi2c_writebyte(u8 data);
u8 mcu_vi2c_readbyte(void);
s32 mcu_vi2c_init(void);
s32 mcu_vi2c_transfer(u8 addr, u8 rw, u8* data, s32 datalen);
s32 mcu_vi2c_transfer_reg(u8 addr, u8* reg, u8 reglen, u8 rw, u8* data, s32 datalen);
#ifdef __cplusplus
}
#endif
#endif



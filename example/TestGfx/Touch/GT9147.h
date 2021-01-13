#ifndef __GT9146_H
#define __GT9146_H
#ifdef __cplusplus
extern "C" {
#endif
#include "main.h"

int gt9147_init(void);
int gt9147_task(void);
uint16_t ReturnTx(void);
uint16_t ReturnTy(void);
#ifdef __cplusplus
}
#endif
#endif

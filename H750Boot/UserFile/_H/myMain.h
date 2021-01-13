#ifndef __MY_MAIN
#define __MY_MAIN
#include "main.h"
#include "quadspi.h"
#define READ_ID_CMD                          0x90
#define DUAL_READ_ID_CMD                     0x92
#define QUAD_READ_ID_CMD                     0x94
#define READ_JEDEC_ID_CMD                    0x9F
#define QUAD_OUT_FAST_READ_CMD               0x6B

void UserMain(void);
#endif // !__MY_MAIN

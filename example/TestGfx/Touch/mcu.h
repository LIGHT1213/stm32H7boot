#ifndef __MCU_H__
#define __MCU_H__

#include "stm32h7xx.h"

typedef int32_t  s32;
typedef int16_t s16;
typedef int8_t  s8;

typedef const int32_t sc32;  /*!< Read Only */
typedef const int16_t sc16;  /*!< Read Only */
typedef const int8_t sc8;   /*!< Read Only */

typedef __IO int32_t  vs32;
typedef __IO int16_t  vs16;
typedef __IO int8_t   vs8;

typedef __I int32_t vsc32;  /*!< Read Only */
typedef __I int16_t vsc16;  /*!< Read Only */
typedef __I int8_t vsc8;   /*!< Read Only */

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

typedef const uint32_t uc32;  /*!< Read Only */
typedef const uint16_t uc16;  /*!< Read Only */
typedef const uint8_t uc8;   /*!< Read Only */

typedef __IO uint32_t  vu32;
typedef __IO uint16_t vu16;
typedef __IO uint8_t  vu8;

typedef __I uint32_t vuc32;  /*!< Read Only */
typedef __I uint16_t vuc16;  /*!< Read Only */
typedef __I uint8_t vuc8;   /*!< Read Only */

typedef enum {
    MCU_PORT_NULL = 0x00,
    MCU_PORT_A,
    MCU_PORT_B,
    MCU_PORT_C,
    MCU_PORT_D,
    MCU_PORT_E,
    MCU_PORT_F,
    MCU_PORT_G,
    MCU_PORT_MAX
} MCU_PORT;

typedef enum {
    MCU_IO_STA_0 = 0x00,
    MCU_IO_STA_1,
} MCU_IO_STA;

typedef enum {
    MCU_IO_0 = 0x00,
    MCU_IO_1,
    MCU_IO_2,
    MCU_IO_3,
    MCU_IO_4,
    MCU_IO_5,
    MCU_IO_6,
    MCU_IO_7,
    MCU_IO_8,
    MCU_IO_9,
    MCU_IO_10,
    MCU_IO_11,
    MCU_IO_12,
    MCU_IO_13,
    MCU_IO_14,
    MCU_IO_15,
    MCU_IO_MAX,
} MCU_IO;


#endif

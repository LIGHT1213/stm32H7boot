#include "myMain.h"
#define VECT_TAB_OFFSET      0x00000000UL
#define APPLICATION_ADDRESS  (uint32_t)0x90000000

typedef void (*pFunction)(void);
pFunction JumpToApplication;

void UserMain(void)
{


    W25QXX_Init();

    W25Q_Memory_Mapped_Enable();

    SCB_DisableICache();
    SCB_DisableDCache();

    SysTick->CTRL = 0;

    JumpToApplication = (pFunction)(*(__IO uint32_t *)(APPLICATION_ADDRESS + 4));
    __set_MSP(*(__IO uint32_t *)APPLICATION_ADDRESS);

    JumpToApplication();
}

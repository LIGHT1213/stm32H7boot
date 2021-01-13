#include "myMain.h"
//QSPI_CommandTypeDef s_command;
//uint8_t pData[3];
//volatile uint32_t spvalue, reseth;
#define VECT_TAB_OFFSET      0x00000000UL
#define APPLICATION_ADDRESS  (uint32_t)0x90000000

typedef void (*pFunction)(void);
pFunction JumpToApplication;
//void myQspiMemoryMap(void)
//{
//	/* 内存映射模式 https://www.jianshu.com/p/77f7bd0817e9 */
//  QSPI_CommandTypeDef s_command;
//  QSPI_MemoryMappedTypeDef s_mem_mapped_cfg;
// 
//  /* Configure the command for the read instruction */
//  s_command.InstructionMode = QSPI_INSTRUCTION_4_LINES;
//  s_command.Instruction = 0xEB;
//  s_command.AddressMode = QSPI_ADDRESS_4_LINES;
//  s_command.AddressSize = QSPI_ADDRESS_24_BITS;
//  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
//  s_command.DataMode = QSPI_DATA_4_LINES;
//  s_command.DummyCycles = 8;
//  s_command.DdrMode = QSPI_DDR_MODE_DISABLE;
//  s_command.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
//  s_command.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;
// 
//  /* Configure the memory mapped mode */
//  s_mem_mapped_cfg.TimeOutActivation = QSPI_TIMEOUT_COUNTER_DISABLE;
//  s_mem_mapped_cfg.TimeOutPeriod = 0;
// 
//  if (HAL_QSPI_MemoryMapped(&hqspi, &s_command, &s_mem_mapped_cfg) != HAL_OK)
//  {

//  }
//}
//void mcu_jump_address(void)
//{
//	uint32_t i;

//	//Uprintf(" jump to firmware\r\n");

//	//myQspiMemoryMap();


//    SysTick->CTRL = 0;

//    JumpToApplication = (pFunction)(*(__IO uint32_t *)(APPLICATION_ADDRESS + 4));
//    __set_MSP(*(__IO uint32_t *)APPLICATION_ADDRESS);

//    JumpToApplication();
//}
//uint8_t myFlashInit(void)
//{
//   uint8_t tmp[3];
//    //myQspiInit();
//        /* Read Manufacture/Device ID */
//    s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
//    s_command.Instruction       = READ_ID_CMD;
//    s_command.AddressMode       = QSPI_ADDRESS_1_LINE;
//    s_command.AddressSize       = QSPI_ADDRESS_24_BITS;
//    s_command.Address           = 0;
//    s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
//    s_command.DataMode          = QSPI_DATA_1_LINE;
//    s_command.DummyCycles       = 0;
//    s_command.NbData            = 2;
//    s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
//    s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
//    s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;
//     
//    if (HAL_QSPI_Command(&hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//    {
//        Error_Handler();
//    }
//    if (HAL_QSPI_Receive(&hqspi, pData, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//    {
//        Error_Handler();
//    }
//    //uart_printf("SPI  I/0 Read Device ID : 0x%2X 0x%2X\r\n", pData[0],pData[1]);
//     
//    /* Read Manufacture/Device ID Dual I/O*/
//    s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
//    s_command.Instruction       = DUAL_READ_ID_CMD;
//    s_command.AddressMode       = QSPI_ADDRESS_2_LINES;
//    s_command.AddressSize       = QSPI_ADDRESS_24_BITS;
//    s_command.Address           = 0x000000;
//    s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_2_LINES;
//    s_command.AlternateBytesSize= QSPI_ALTERNATE_BYTES_8_BITS;
//    s_command.AlternateBytes    = 0;
//    s_command.DataMode          = QSPI_DATA_2_LINES;
//    s_command.DummyCycles       = 0;
//    s_command.NbData            = 4;
//    s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
//    s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
//    s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;
// 
//    if (HAL_QSPI_Command(&hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK){
//        Error_Handler();
//    }
//	
//    if (HAL_QSPI_Receive(&hqspi, pData, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK){
//        Error_Handler();
//    }
//	
//    //uart_printf("Dual I/O Read Device ID : 0x%2X 0x%2X\r\n",pData[0],pData[1]);
// 
//    /* Read Manufacture/Device ID Quad I/O*/
//    s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
//    s_command.Instruction       = QUAD_READ_ID_CMD;
//    s_command.AddressMode       = QSPI_ADDRESS_4_LINES;
//    s_command.AddressSize       = QSPI_ADDRESS_24_BITS;
//    s_command.Address           = 0;
//    s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_4_LINES;
//    s_command.AlternateBytesSize= QSPI_ALTERNATE_BYTES_8_BITS;
//    s_command.AlternateBytes    = 0x00;
//    s_command.DataMode          = QSPI_DATA_4_LINES;
//    s_command.DummyCycles       = 4;
//    s_command.NbData            = 2;
//    s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
//    s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
//    s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;
// 
//    if (HAL_QSPI_Command(&hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//    {
//        Error_Handler();
//    }
//    if (HAL_QSPI_Receive(&hqspi, pData, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//    {
//        Error_Handler();
//    }
//   // uart_printf("Quad I/O Read Device ID : 0x%2X 0x%2X\r\n",pData[0],pData[1]);
// 
//    /* Read JEDEC ID */
//    s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
//    s_command.Instruction       = READ_JEDEC_ID_CMD;
//    s_command.AddressMode       = QSPI_ADDRESS_NONE;
//    s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
//    s_command.DataMode          = QSPI_DATA_1_LINE;
//    s_command.DummyCycles       = 0;
//    s_command.NbData            = 3;
//    s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
//    s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
//    s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;
// 
//    if (HAL_QSPI_Command(&hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//    {
//        Error_Handler();
//    }
//    if (HAL_QSPI_Receive(&hqspi, pData, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//    {
//        Error_Handler();
//    }
//    //uart_printf("Read JEDEC ID :  0x%2X 0x%2X 0x%2X\r\n\r\n",pData[0],pData[1],pData[2]);

//	return 0;
//}
void UserMain(void)
{
    //rt_pin_mode(LED0_PIN, PIN_MODE_OUTPUT);

    W25QXX_Init();

    W25Q_Memory_Mapped_Enable();

    SCB_DisableICache();
    SCB_DisableDCache();

    SysTick->CTRL = 0;

    JumpToApplication = (pFunction)(*(__IO uint32_t *)(APPLICATION_ADDRESS + 4));
    __set_MSP(*(__IO uint32_t *)APPLICATION_ADDRESS);

    JumpToApplication();
}

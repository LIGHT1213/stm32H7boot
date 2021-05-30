/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : stm32h7xx_hal_msp.c
  * Description        : This file provides code for the MSP Initialization
  *                      and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */
#include "Loader_Src.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */

/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */

/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* USER CODE BEGIN 1 */
/**
* @brief QSPI MSP Initialization
* This function configures the hardware resources used in this example
* @param hqspi: QSPI handle pointer
* @retval None
*/
void HAL_QSPI_MspInit(QSPI_HandleTypeDef* hqspi)
{
	  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(hqspi->Instance==QUADSPI)
  {
  /* USER CODE BEGIN QUADSPI_MspInit 0 */

  /* USER CODE END QUADSPI_MspInit 0 */
    /* QUADSPI clock enable */
    __HAL_RCC_QSPI_CLK_ENABLE();

    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    /**QUADSPI GPIO Configuration
    PE2     ------> QUADSPI_BK1_IO2
    PB2     ------> QUADSPI_CLK
    PD11     ------> QUADSPI_BK1_IO0
    PD12     ------> QUADSPI_BK1_IO1
    PD13     ------> QUADSPI_BK1_IO3
    PB6     ------> QUADSPI_BK1_NCS
    */
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_QUADSPI;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_QUADSPI;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_QUADSPI;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF10_QUADSPI;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//  GPIO_InitTypeDef GPIO_InitStruct = {0};
//  if(hqspi->Instance==QUADSPI)
//  {
//  /* USER CODE BEGIN QUADSPI_MspInit 0 */
//    __HAL_RCC_QSPI_FORCE_RESET();
//    __HAL_RCC_QSPI_RELEASE_RESET();
//  /* USER CODE END QUADSPI_MspInit 0 */
//    /* Peripheral clock enable */
//    __HAL_RCC_QSPI_CLK_ENABLE();
//      
//    __HAL_RCC_GPIOF_CLK_ENABLE();
//    __HAL_RCC_GPIOB_CLK_ENABLE();
//    /**QUADSPI GPIO Configuration
//    PF6     ------> QUADSPI_BK1_IO3
//    PF7     ------> QUADSPI_BK1_IO2
//    PF8     ------> QUADSPI_BK1_IO0
//    PF9     ------> QUADSPI_BK1_IO1
//    PB2     ------> QUADSPI_CLK
//    PB6     ------> QUADSPI_BK1_NCS
//    */
//    GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
//    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//    GPIO_InitStruct.Pull = GPIO_PULLUP;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//    GPIO_InitStruct.Alternate = GPIO_AF9_QUADSPI;
//    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

//    GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9;
//    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//    GPIO_InitStruct.Pull = GPIO_PULLUP;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//    GPIO_InitStruct.Alternate = GPIO_AF10_QUADSPI;
//    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

//    GPIO_InitStruct.Pin = GPIO_PIN_2;
//    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//    GPIO_InitStruct.Pull = GPIO_PULLUP;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//    GPIO_InitStruct.Alternate = GPIO_AF9_QUADSPI;
//    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

//    GPIO_InitStruct.Pin = GPIO_PIN_6;
//    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//    GPIO_InitStruct.Pull = GPIO_PULLUP;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//    GPIO_InitStruct.Alternate = GPIO_AF10_QUADSPI;
//    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

//  /* USER CODE BEGIN QUADSPI_MspInit 1 */
//  HAL_NVIC_SetPriority(QUADSPI_IRQn, 0x0F, 0);
//  HAL_NVIC_EnableIRQ(QUADSPI_IRQn);
//  /* USER CODE END QUADSPI_MspInit 1 */
  }

}

/**
* @brief QSPI MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hqspi: QSPI handle pointer
* @retval None
*/
void HAL_QSPI_MspDeInit(QSPI_HandleTypeDef* hqspi)
{
//  if(hqspi->Instance==QUADSPI)
//  {
//  /* USER CODE BEGIN QUADSPI_MspDeInit 0 */
//    __HAL_RCC_QSPI_FORCE_RESET();
//    __HAL_RCC_QSPI_RELEASE_RESET();
//  /* USER CODE END QUADSPI_MspDeInit 0 */
//    /* Peripheral clock disable */
//    __HAL_RCC_QSPI_CLK_DISABLE();

//    /**QUADSPI GPIO Configuration
//    PF6     ------> QUADSPI_BK1_IO3
//    PF7     ------> QUADSPI_BK1_IO2
//    PF8     ------> QUADSPI_BK1_IO0
//    PF9     ------> QUADSPI_BK1_IO1
//    PB2     ------> QUADSPI_CLK
//    PB6     ------> QUADSPI_BK1_NCS
//    */
//    HAL_GPIO_DeInit(GPIOF, GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9);

//    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_2|GPIO_PIN_6);

//  /* USER CODE BEGIN QUADSPI_MspDeInit 1 */

//  /* USER CODE END QUADSPI_MspDeInit 1 */
//  }
  if(hqspi->Instance==QUADSPI)
  {
  /* USER CODE BEGIN QUADSPI_MspDeInit 0 */

  /* USER CODE END QUADSPI_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_QSPI_CLK_DISABLE();

    /**QUADSPI GPIO Configuration
    PE2     ------> QUADSPI_BK1_IO2
    PB2     ------> QUADSPI_CLK
    PD11     ------> QUADSPI_BK1_IO0
    PD12     ------> QUADSPI_BK1_IO1
    PD13     ------> QUADSPI_BK1_IO3
    PB6     ------> QUADSPI_BK1_NCS
    */
    HAL_GPIO_DeInit(GPIOE, GPIO_PIN_2);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_2|GPIO_PIN_6);

    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13);

  /* USER CODE BEGIN QUADSPI_MspDeInit 1 */

  /* USER CODE END QUADSPI_MspDeInit 1 */
  }

}
/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

/**
  ******************************************************************************
  * File Name          : CRC.c
  * Description        : This file provides code for the configuration
  *                      of the CRC instances.
  ******************************************************************************
  */
#include "crc.h"
#include "errors.h"

CRC_HandleTypeDef hcrc;

/* CRC init function */
void MX_CRC_Init(void)
{
  hcrc.Instance = CRC;
  if (HAL_CRC_Init(&hcrc) != HAL_OK)
  {
    Error_Handler(__FILE__, __LINE__);
  }
}

void HAL_CRC_MspInit(CRC_HandleTypeDef* crcHandle)
{
  if(crcHandle->Instance==CRC)
  {
    /* CRC clock enable */
    __HAL_RCC_CRC_CLK_ENABLE();
  }
}

void HAL_CRC_MspDeInit(CRC_HandleTypeDef* crcHandle)
{
  if(crcHandle->Instance==CRC)
  {
    /* Peripheral clock disable */
    __HAL_RCC_CRC_CLK_DISABLE();
  }
} 

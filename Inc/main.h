/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Touch_Pwr_Pin GPIO_PIN_13
#define Touch_Pwr_GPIO_Port GPIOC
#define Rfid_Rst_Pin GPIO_PIN_14
#define Rfid_Rst_GPIO_Port GPIOC
#define Sys_5v_En_Pin GPIO_PIN_15
#define Sys_5v_En_GPIO_Port GPIOC
#define Touch_Wkup_Pin GPIO_PIN_0
#define Touch_Wkup_GPIO_Port GPIOA
#define Touch_Wkup_EXTI_IRQn EXTI0_IRQn
#define Vbat_adc_Pin GPIO_PIN_1
#define Vbat_adc_GPIO_Port GPIOA
#define SPI1_NSS_Pin GPIO_PIN_4
#define SPI1_NSS_GPIO_Port GPIOA
#define ADC_EN_Pin GPIO_PIN_0
#define ADC_EN_GPIO_Port GPIOB
#define SPI2_NSS_Pin GPIO_PIN_12
#define SPI2_NSS_GPIO_Port GPIOB
#define LORA_REST_Pin GPIO_PIN_15
#define LORA_REST_GPIO_Port GPIOA
#define LORA_DIO0_Pin GPIO_PIN_3
#define LORA_DIO0_GPIO_Port GPIOB
#define LORA_DIO1_Pin GPIO_PIN_4
#define LORA_DIO1_GPIO_Port GPIOB
#define LORA_DIO3_Pin GPIO_PIN_5
#define LORA_DIO3_GPIO_Port GPIOB
#define DATA_Pin GPIO_PIN_7
#define DATA_GPIO_Port GPIOB
#define BUSY_SEPAK_Pin GPIO_PIN_8
#define BUSY_SEPAK_GPIO_Port GPIOB
#define BEEP_SD_Pin GPIO_PIN_9
#define BEEP_SD_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

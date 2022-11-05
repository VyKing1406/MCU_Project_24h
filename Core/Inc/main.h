/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f1xx_hal.h"

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
#define Led_red_Pin GPIO_PIN_5
#define Led_red_GPIO_Port GPIOA
#define RESET_Pin GPIO_PIN_0
#define RESET_GPIO_Port GPIOB
#define INC_Pin GPIO_PIN_1
#define INC_GPIO_Port GPIOB
#define DEC_Pin GPIO_PIN_2
#define DEC_GPIO_Port GPIOB
#define seg1_Pin GPIO_PIN_8
#define seg1_GPIO_Port GPIOA
#define seg2_Pin GPIO_PIN_9
#define seg2_GPIO_Port GPIOA
#define seg3_Pin GPIO_PIN_10
#define seg3_GPIO_Port GPIOA
#define seg4_Pin GPIO_PIN_11
#define seg4_GPIO_Port GPIOA
#define seg5_Pin GPIO_PIN_12
#define seg5_GPIO_Port GPIOA
#define seg6_Pin GPIO_PIN_13
#define seg6_GPIO_Port GPIOA
#define seg7_Pin GPIO_PIN_14
#define seg7_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

//=========================================================================
// @file   main.c
//
// @Author Kunj Patel
//
// @brief Main drivers for the project
//=========================================================================

//-------------------------------------------------------------------------
// Include Files
//-------------------------------------------------------------------------
#include "main.h"
#include "stm32f4xx_hal_gpio.h"

//-------------------------------------------------------------------------
// Include Files
//-------------------------------------------------------------------------
// (none)

//-------------------------------------------------------------------------
// Global Variables
//-------------------------------------------------------------------------
// (none)

//-------------------------------------------------------------------------
// Forward Declaration
//-------------------------------------------------------------------------
void SystemClock_Config(void);

//-------------------------------------------------------------------------
// Function Definition
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
//
// @brief Entry for the program
//
// @param (none)
//
// @retval integer
//-------------------------------------------------------------------------

int main(void)
{

  HAL_Init();

  __HAL_RCC_GPIOA_CLK_ENABLE();
  GPIO_InitTypeDef GpioHandle;
  GpioHandle.Mode = GPIO_MODE_OUTPUT_PP;
  GpioHandle.Pin = GPIO_PIN_5;
  GpioHandle.Pull = GPIO_NOPULL;

  HAL_GPIO_Init(GPIOA, &GpioHandle);

  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);

  SystemClock_Config();

  while (1)
  {

  }
}

//-------------------------------------------------------------------------
//
// @brief System Clock Configuration
//
// @param (none)
//
// @retval (none)
//
//-------------------------------------------------------------------------
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

void Error_Handler(void) {
	__disable_irq();
	while(1)
	{

	}
}



#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

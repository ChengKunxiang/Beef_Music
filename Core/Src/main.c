/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "songs.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
int index = 0;  // 当前音符索引
int is_start = 0;  // 是否开始播放
int song_index = 0;  // 当前歌曲索引
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void Delay_Ms(uint32_t ms) {
    SysTick->LOAD = SystemCoreClock / 1000 - 1;  // 重装载值
    SysTick->VAL = 0;                           // 清空计数器
    SysTick->CTRL = SysTick_CTRL_ENABLE_Msk;    // 启动SysTick

    for (uint32_t i = 0; i < ms; i++) {
        while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)); // 等待计数完成
    }
    SysTick->CTRL = 0;  // 关闭SysTick
}

void playTone(uint16_t freq) {
  if(freq != NOTE_REST) {
    uint32_t arr = (1000000 / freq) - 1;  // 计算ARR值
    TIM3->ARR = arr;             // 设置频率
    TIM3->CCR1 = arr / 4;        // 占空比
    TIM3->EGR |= TIM_EGR_UG;     // 强制更新寄存器
  }else {
    TIM3->CCR1 = 0;              // 休止符时关闭PWM
  }
}

int switch_song() {
  int which_song; // 检测按键状态，选择不同的歌曲
  if (!song_index)
  {
      if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15))
    {
      which_song = 1;  // 选择第一首歌
    } else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3)) {
      which_song = 2;  // 选择第二首歌
    } else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4)) {
      which_song = 3;  // 选择第三首歌
    } else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5)) {
      which_song = 4;   // 选择第四首歌
    } else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6)) {
      which_song = 5;  // 选择第五首歌
    } else {
      which_song = 0;  // 没有按键被按下
    }
  } else {
    which_song = song_index;  // 如果已经有歌曲在播放，则保持当前歌曲
  }
  song_index = which_song;  // 更新当前歌曲索引
  return which_song;  // 返回选择的歌曲编号
}

int is_button_pressed() {
  if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15) || 
      HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) || 
      HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) || 
      HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5) || 
      HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6))  // 检测按键是否被按下
  {
    return switch_song();  // 按键被按下
  }
  return 0;  // 按键未被按下
}

void play_song() {
  // 根据 song_index 播放对应的歌曲
  switch (song_index) {
    case 1:
      is_start = 1;  // 切换播放状态
      if (Stars_song[index].tone != 1000) {
        playTone(Stars_song[index].tone);  // 播放音符
        Delay_Ms(Stars_song[index].duration * BEAT_DURATION);  // 延时
        playTone(NOTE_REST);  // 停止音符
        Delay_Ms(BEAT_DURATION * 0.2);  // 延时
    } else {
        playTone(NOTE_REST);  // 播放休止符
        Delay_Ms(BEAT_DURATION);  // 延时
    }
    index++;  // 移动到下一个音符
    if (Stars_song[index].tone == 0) {  // 如果到达最后一个音符
        is_start = 0;  // 停止播放
        index = 0;  // 重置索引
        song_index = 0;  // 重置歌曲索引
      }
      break;

    case 2:
      is_start = 1;  // 切换播放状态
      if (OrdinaryRoad_song[index].tone != 1000) {
        playTone(OrdinaryRoad_song[index].tone);  // 播放音符
        Delay_Ms(OrdinaryRoad_song[index].duration * BEAT_DURATION);  // 延时
        playTone(NOTE_REST);  // 停止音符
        Delay_Ms(BEAT_DURATION * 0.2);  // 延时
    } else {
        playTone(NOTE_REST);  // 播放休止符
        Delay_Ms(BEAT_DURATION);  // 延时
    }
    index++;  // 移动到下一个音符
    if (OrdinaryRoad_song[index].tone == 0) {  // 如果到达最后一个音符
        is_start = 0;  // 停止播放
        index = 0;  // 重置索引
        song_index = 0;  // 重置歌曲索引
      }
    break;

    case 3:
      is_start = 1;  // 切换播放状态
      if (Mario[index].tone != 1000) {
        playTone(Mario[index].tone);  // 播放音符
        Delay_Ms(Mario[index].duration * BEAT_DURATION);  // 延时
        playTone(NOTE_REST);  // 停止音符
        Delay_Ms(BEAT_DURATION * 0.2);  // 延时
      } else {
          playTone(NOTE_REST);  // 播放休止符
          Delay_Ms(BEAT_DURATION);  // 延时
      }
      index++;  // 移动到下一个音符
      if (Mario[index].tone == 0) {  // 如果到达最后一个音符
          is_start = 0;  // 停止播放
          index = 0;  // 重置索引
          song_index = 0;  // 重置歌曲索引
      }
      break;
    case 4:

      break;
    case 5:

    default:

      break;
  }

}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
  // uint16_t pwmVal=0;   //PWM占空比  
  // uint8_t dir_1=1;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    if(is_start != 0 || is_button_pressed()){
      is_start = 1;  // 切换播放状态
      switch_song();
      play_song();  // 切换歌曲
      // HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13, HIGH);
      HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14, HIGH);
    }else{
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14, LOW);
    HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
    // HAL_Delay(50);
  }
  /* USER CODE END 3 */
}
}
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
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

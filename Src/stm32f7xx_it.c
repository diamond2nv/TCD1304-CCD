/**
 *******************************************************************************
 * @file    stm32f7xx_it.c
 * @author  Dung Do Dang
 * @version V1.0.0
 * @date    2018-06-26
 * @brief   Handles interrupt requests
 *******************************************************************************
 *
 * COPYRIGHT(c) 2018 Dung Do Dang
 *
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"
#include "stm32f7xx.h"
#include "stm32f7xx_it.h"

/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_usart1_tx;
extern DMA_HandleTypeDef hdma_usart1_rx;
extern UART_HandleTypeDef huart1;

/******************************************************************************/
/*            Cortex-M7 Processor Interruption and Exception Handlers         */
/******************************************************************************/

/**
 * @brief This function handles System tick timer.
 */
void SysTick_Handler(void)
{
    HAL_IncTick();
    HAL_SYSTICK_IRQHandler();
}

/******************************************************************************/
/* STM32F7xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f7xx.s).                    */
/******************************************************************************/

/**
 * @brief This function handles DMA2 stream2 global interrupt.
 */
void DMA2_Stream2_IRQHandler(void)
{
    HAL_DMA_IRQHandler( &hdma_usart1_rx );
}

/**
 * @brief This function handles DMA2 stream7 global interrupt.
 */
void DMA2_Stream7_IRQHandler(void)
{
    HAL_DMA_IRQHandler( &hdma_usart1_tx );
    huart1.gState = HAL_UART_STATE_READY;
}

/****************************** END OF FILE ***********************************/

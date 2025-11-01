#include "main.h"

int main(void)
{
  HAL_Init();                   // Initialisation du HAL
  SystemClock_Config();         // Configuration de l’horloge

  __HAL_RCC_GPIOA_CLK_ENABLE(); // Active l'horloge du port A

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = GPIO_PIN_5;          // PA5 = LED sur Nucleo
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // Sortie push-pull
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  while (1)
  {
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);  // Inversion de l’état de la LED
    HAL_Delay(500);                         // Attendre 500 ms
  }
}

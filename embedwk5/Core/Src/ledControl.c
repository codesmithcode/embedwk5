#include "ledControl.h"
#include "stm32f3xx_hal.h"

bool ledBlinkState[MAX_LED_INDEX];

typedef struct sLedGPIOTable
{
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
} sLedGPIOTable_T;

static const sLedGPIOTable_T mLedGPIOTable[] =
{
    {GPIOE, GPIO_PIN_8},
    {GPIOE, GPIO_PIN_9},
    {GPIOE, GPIO_PIN_10},
    {GPIOE, GPIO_PIN_11},
    {GPIOE, GPIO_PIN_12},
    {GPIOE, GPIO_PIN_13},
    {GPIOE, GPIO_PIN_14},
    {GPIOE, GPIO_PIN_15},
};

void toggleLED(int led){
	if(led <0 || led >= MAX_LED_INDEX) {
		return;
	}

    HAL_GPIO_TogglePin(mLedGPIOTable[led].GPIOx, mLedGPIOTable[led].GPIO_Pin);
}

void blinkLED(int led) {
	if(led <0 || led >= MAX_LED_INDEX) {
			return;
	}
	ledBlinkState[led] = true;

    HAL_GPIO_TogglePin(mLedGPIOTable[led].GPIOx, mLedGPIOTable[led].GPIO_Pin);
}

bool isLEDBlinking(int led) {
	if(led <0 || led >= MAX_LED_INDEX) {
		return false;
	}
	return ledBlinkState[led];
}

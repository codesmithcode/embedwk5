/*
 * ledControl.h
 *
 *  Created on: Oct 30, 2023
 *      Author: datat
 */

#ifndef SRC_LEDCONTROL_H_
#define SRC_LEDCONTROL_H_

#include <stdbool.h>

#define MAX_LED_INDEX 8

void toggleLED(int led);
void blinkLED(int led);
bool isLEDBlinking(int led);

#endif /* SRC_LEDCONTROL_H_ */

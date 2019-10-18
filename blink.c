/*
 * This file is part of the Nucleo32-L432kc-blink project.
 *
 * Copyright (C) 2019 Fabien Proriol <fabien.proriol@saint-pal.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This exemple is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <libopencm3/stm32/gpio.h>
#include <FreeRTOS.h>
#include <task.h>
#include <init.h>

extern uint64_t millis();

void vLedFlash(void *dummy)
{
    printf("Enter task\n");
	while (1) {
		printf("tick: %llu\n", millis());
		gpio_toggle(LED_USER_PORT, LED_USER_PIN);
		vTaskDelay(1000 / portTICK_RATE_MS);
	}
}

int main(void)
{
	clock_setup();
	gpio_setup();
	usart_setup();
	systick_setup(1000); /* systick 1 ms */

	xTaskCreate(vLedFlash, (const char *) "vLedFlash", 256, NULL, tskIDLE_PRIORITY + 1, NULL);

	printf("Start Scheduler\n");

	vTaskStartScheduler();

	return 0;
}

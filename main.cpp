/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "platform/mbed_thread.h"
#include "USBSerial.h"

USBSerial usbs;

// Blinking rate in milliseconds
#define BLINKING_RATE_MS                                                    500


int main()
{
    int cnt = 0;
    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);
    usbs.printf("hello, USBDevice\n");

    while (true) {
        usbs.printf("%d\n", cnt++);
        led = !led;
        thread_sleep_for(BLINKING_RATE_MS);
    }
}

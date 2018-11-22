/* SDT-example-pmic-led
 * 
 * Copyright (c) 2018 Sigma Delta Technologies Inc.
 * 
 * MIT License
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include "mbed.h"
#include "MAX32620SDT.h"

/* Serial */
#define BAUDRATE        9600
Serial serial_pc(USBTX, USBRX, BAUDRATE);

/* DigitalOut */
#define LED_ON          0
#define LED_OFF         1
DigitalOut do_ledBlue(LED_BLUE, LED_OFF);

/* VDDIOH */
#define VDDIOH_1P8      0
#define VDDIOH_3P3      1
MAX32620SDT max32620sdt;



void vddioh_test(bool vddioh_level) {
    serial_pc.printf("[%s] Start\n", __FUNCTION__);

    /* Init port */
    if(max32620sdt.init() == MAX32620SDT_ERROR) {
        serial_pc.printf("[%s] Error initializing MAX32620SDT\n", __FUNCTION__);
    }

    /* Set VDDIOH of this port */
    if(vddioh_level) {
        max32620sdt.set_vddioh(LED_RED, MAX32620SDT::VIO_3V3);
    }
    else {
        max32620sdt.set_vddioh(LED_RED, MAX32620SDT::VIO_1V8);
    }
    wait(1);
    serial_pc.printf("[%s] Check LED_RED(= GPIO0) whether high level is 1.8V or 3.3V\n", __FUNCTION__);
}

int main(void)
{
    serial_pc.printf("< Sigma Delta Technologies Inc. >\n\r");

    vddioh_test(VDDIOH_3P3);    // You can set a parameter of this function to VDDIOH_1P8 or VDDIOH_3P3.
    
    // Cycle MAX32620FTHR LED's
    while(true) {
        serial_pc.printf("LED Toggle\n");
        do_ledBlue = !do_ledBlue;
        wait(1);                // 1sec
    }
}

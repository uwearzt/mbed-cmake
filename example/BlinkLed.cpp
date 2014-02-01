/*
 * This is the original mbed example
 */

#include "mbed.h"

DigitalOut myled(LED1);
Serial pc(USBTX, USBRX);

int main() {
  int i = 0;
  while(1) {
    myled = 1;
    wait(0.3);
    myled = 0;
    wait(0.3);
    pc.printf("i: %i\n\r", i);
    ++i;
  }
}

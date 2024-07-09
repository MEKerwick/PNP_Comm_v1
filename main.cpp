/**************************************************************************
*** PNP Comm Program v0.0 7/09/2024
*** 
*** This program handles Communication between the PC and PNP Control
*** Nucleo.
*** 
**************************************************************************/

#include "mbed.h"

// For Debug
DigitalOut myled(LED1); // LED1 = D13?
Serial pc(USBTX,USBRX);

int inBuff;

int main() {
    myled = 0;

    while(1) {
        // PC USB Serial Starts Here...
        if (pc.readable()) {                            
            inBuff = pc.getc();  
            if (inBuff == 0xAA) myled = 1;
            else myled = 0;
        }                
        pc.putc(inBuff);                     
    }
}

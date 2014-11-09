//hw4 
//master 

#include "mbed.h"
Serial async_port(p9, p10);
DigitalOut red_led(p25);
DigitalOut green_led(p26);
DigitalOut strobe(p7); 
DigitalIn switch_ip1(p5);
DigitalIn switch_ip2(p6);
char switch_word ;
char recd_val ;

int main() {
    async_port.baud(9600);
    while(1) {
        switch_word=0xa0 ;
        if (switch_ip1 == 1) 
            switch_word = switch_word|0x01 ;
        if (switch_ip2 == 1) 
            switch_word = switch_word|0x02 ; 
        //wait_us(10);
//      async_port.putc(switch_word);
        if (async_port.readable() == 1) {
            recd_val = async_port.getc();
            strobe = 1;
        }
        
        red_led = 0 ;
        green_led = 0 ;
        recd_val = recd_val&0x03 ; 
        if (recd_val == 1) 
            red_led = 1;
        if (recd_val == 2)
            green_led = 1;
        if (recd_val == 3) {
            red_led = 1;
            green_led = 1;
        }
    }
}

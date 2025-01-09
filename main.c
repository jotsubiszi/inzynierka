#include "lineFollower.h"
#include <avr/io.h>
#include <stdio.h>

#define USART0_CLOCK_HZ 1000000
#define BAUD_RATE_HZ 9600
#define UBRR_VALUE (USART0_CLOCK_HZ / BAUD_RATE_HZ)

// Send a character over USART0.
int USART0_tx(char data, struct __file *_f) {
  while (!(UCSR0A & (1 << UDRE0)))
    ;          // wait for the data buffer to be empty
  UDR0 = data; // write the character to the data buffer
  return 0;
}

// Create a stream associated with transmitting data over USART0 (this will be
// used for stdout so we can print to a terminal with printf).
static FILE uartout = FDEV_SETUP_STREAM(USART0_tx, NULL, _FDEV_SETUP_WRITE);

void USART0_init(void) {
  UBRR0H = (UBRR_VALUE >> 8) & 0xF; // set the high byte of the baud rate
  UBRR0L = UBRR_VALUE & 0xFF;       // set the low byte of the baud rate
  UCSR0B = 1 << TXEN0;              // enable the USART0 transmitter
  UCSR0C = 3 << UCSZ00;             // use 8-bit characters
  stdout = &uartout;
}

PIDVals pid;
Motors moto;
sensorsPins sens;

int main(void) {
  USART0_init();
  followerInit(1, 2, 3, 4, 18, 12, 5, 6, 7, 8, 9, 0, 10, 3, 5, &moto, &sens,
               &pid);
  printf("PORTB: %i\r\n", PORTB);
  printf("PORTC: %i\r\n", PORTC);
  printf("PORTD: %i\r\n", PORTD);
  printf("DDRB: %i\r\n", DDRB);
  printf("DDRC: %i\r\n", DDRC);
  printf("DDRD: %i\r\n", DDRD);
  printf("OCR0A: %i\r\n", OCR0A);
  printf("OCR0B: %i\r\n", OCR0B);
  while (1 == 1) {
    followerUpdate(&sens, &pid);
    // printf("APWM: %i BPWM: %i\n", moto.APwmVal, moto.BPwmVal);
    //  printf();
    printf("OCR0A: %i OCR0B: %i\r\n", OCR0A, OCR0B);
    // printf("PORTD: %i\r\n", PORTD);
    // printf("PORTB: %i\r\n", PORTB);
    printf("error: %i\r\n", pid.error);
    printf("P: %i\r\n", pid.pOut);
    printf("I: %i\r\n", pid.iOut);
    printf("D: %i\r\n", pid.dOut);
    printf("integral: %i\r\n", pid.integral);
    printf("derivative: %i\r\n", pid.derivative);
    printf("sensVal: %i\r\n", getSensorsVals(&sens));
    printf("-------------------------------------\r\n");
  }
  return 0;
}

#include <avr/io.h>
#include "buzzWords.h"

void writePortB(uint8_t, uint8_t);
void writePortC(uint8_t, uint8_t);
void writePortD(uint8_t, uint8_t);

void setPortB(uint8_t, uint8_t, uint8_t);
void setPortC(uint8_t, uint8_t, uint8_t);
void setPortD(uint8_t, uint8_t, uint8_t);

uint8_t portCheck(uint8_t);
uint8_t pinCheck(uint8_t);

void setPortPin(uint8_t, uint8_t, uint8_t);

uint8_t isOutput(uint8_t);
uint8_t isInput(uint8_t);

void writePinValue(uint8_t, uint8_t);
uint8_t readPinValue(uint8_t);

void setCounter0PWM(uint8_t, uint8_t);

#include "buzzWords.h"
#include <avr/io.h>
#include <stdint.h>

// Writes given port pin as HIGH or LOW
void writePortB(uint8_t portPinNumber, uint8_t value);
// Writes given port pin as HIGH or LOW
void writePortC(uint8_t portPinNumber, uint8_t value);
// Writes given port pin as HIGH or LOW
void writePortD(uint8_t portPinNumber, uint8_t value);

// Sets given port pin as input or output and with given mode
void setPortB(uint8_t portPinNumber, uint8_t inputOrOutput, uint8_t mode);
// Sets given port pin as input or output and with given mode
void setPortC(uint8_t portPinNumber, uint8_t inputOrOutput, uint8_t mode);
// Sets given port pin as input or output and with given mode
void setPortD(uint8_t portPinNumber, uint8_t inputOrOutput, uint8_t mode);

// Checks on which port is given Arduino pin and returns this port
uint8_t portCheck(uint8_t arduinoPinNumber);
// Checks which port pin is assigned to given Arduino pin
uint8_t pinCheck(uint8_t arduinoPinNumber);

// Sets given Arduino pin as input or output and with given mode
void setPortPin(uint8_t arduinoPinNumber, uint8_t inputOrOutput, uint8_t mode);

// Checks if given Arduino pin is set as output
uint8_t isOutput(uint8_t arduinoPinNumber);
// Checks if given Arduino pin is set as input
uint8_t isInput(uint8_t arduinoPinNumber);

// Writes Arduino pin as HIGH or LOW
void writePinValue(uint8_t arduinoPinNumber, uint8_t value);
// Reads value from Aduino pin and returns 0 or 1
uint8_t readPinValue(uint8_t arduinoPinNumber);

// Initialize necessary registers for PWM on pins 5, 6
void setCounter0PWM();
// Sets PWM "speed" on two pins an once
void set0PWMVal(uint8_t valueForPin6, uint8_t valueForPin5);

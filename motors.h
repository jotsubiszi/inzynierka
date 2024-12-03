#include "pinConfig.h"
#include <stdint.h>

typedef struct {
  uint8_t APwmVal;
  uint8_t BPwmVal;
  uint8_t AIN1;
  uint8_t AIN2;
  uint8_t BIN1;
  uint8_t BIN2;

} Motors;

// Require creating Motors struct first!
void motorsInit(Motors *mPins, uint8_t Ain1, uint8_t Ain2, uint8_t Bin1,
                uint8_t Bin2, uint8_t Apwm, uint8_t Bpwm);

void setMotorsSpeed(uint8_t arduinoPin5PwmValue, uint8_t arduinoPin6PwmValue);

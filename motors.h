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

void motorsInit(Motors *mPins, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t,
                uint8_t);

void setMotorsSpeed(uint8_t, uint8_t);

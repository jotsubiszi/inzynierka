#include "pinConfig.h"
#include <avr/io.h>

typedef struct {
  uint8_t farLeftSensorPin;
  uint8_t leftSensorPin;
  uint8_t midSensorPin;
  uint8_t rightSensorPin;
  uint8_t farRightSensorPin;
} sensorsPins;

void sensorInit(sensorsPins *sPins, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t,
                uint8_t);

int8_t getSensorsVals(sensorsPins *sPins);

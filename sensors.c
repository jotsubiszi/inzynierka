#include "sensors.h"

void sensorInit(sensorsPins *sPins, uint8_t farLeftSensorPin,
                uint8_t leftSensorPin, uint8_t midSensorPin,
                uint8_t rightSensorPin, uint8_t farRightSensorPin,
                uint8_t internalPullUp) {
  sPins->farRightSensorPin = farRightSensorPin;
  sPins->farLeftSensorPin = farLeftSensorPin;
  sPins->leftSensorPin = leftSensorPin;
  sPins->rightSensorPin = rightSensorPin;
  sPins->midSensorPin = midSensorPin;

  setPortPin(farLeftSensorPin, INPUT, internalPullUp);
  setPortPin(leftSensorPin, INPUT, internalPullUp);
  setPortPin(midSensorPin, INPUT, internalPullUp);
  setPortPin(rightSensorPin, INPUT, internalPullUp);
  setPortPin(farRightSensorPin, INPUT, internalPullUp);
}

int8_t getSensorsVals(sensorsPins *sPins, uint8_t invertedLogic) {
  int8_t sensorsVal = 0;
  if (readPinValue(sPins->farLeftSensorPin) ==
      (invertedLogic == TRUE ? LOW : HIGH)) {
    sensorsVal += 2;
  }
  if (readPinValue(sPins->leftSensorPin) ==
      (invertedLogic == TRUE ? LOW : HIGH)) {
    sensorsVal += 1;
  }
  if (readPinValue(sPins->midSensorPin) ==
      (invertedLogic == TRUE ? LOW : HIGH)) {
    sensorsVal += -1;
  }
  if (readPinValue(sPins->rightSensorPin) ==
      (invertedLogic == TRUE ? LOW : HIGH)) {
    sensorsVal += -2;
  }
  if (readPinValue(sPins->farRightSensorPin) ==
      (invertedLogic == TRUE ? LOW : HIGH)) {
    sensorsVal += 0;
  }
  return sensorsVal;
}

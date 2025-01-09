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
// my trc's are reversed logic!!!!!!
int8_t getSensorsVals(sensorsPins *sPins) {
  int8_t sensorsVal = 0;
  if (readPinValue(sPins->farLeftSensorPin) == LOW) {
    sensorsVal += 3;
  }
  if (readPinValue(sPins->leftSensorPin) == LOW) {
    sensorsVal += 1;
  }
  if (readPinValue(sPins->midSensorPin) == LOW) {
    sensorsVal += 0;
  }
  if (readPinValue(sPins->rightSensorPin) == LOW) {
    sensorsVal += -1;
  }
  if (readPinValue(sPins->farRightSensorPin) == LOW) {
    sensorsVal += -3;
  }
  return sensorsVal;
}

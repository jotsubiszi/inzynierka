#include "lineFollower.h"
#include <stdint.h>

void followerInit(uint8_t Ain1, uint8_t Ain2, uint8_t Bin1, uint8_t Bin2,
                  uint8_t Apwm, uint8_t Bpwm, uint8_t farLeftSensorPin,
                  uint8_t leftSensorPin, uint8_t midSensorPin,
                  uint8_t rightSensorPin, uint8_t farRightSensorPin,
                  uint8_t internalPullUp, float valP, float valI, float valD,
                  Motors *followerMotors, sensorsPins *followerSensorsPins,
                  PIDVals *followerPID) {
  motorsInit(followerMotors, Ain1, Ain2, Bin1, Bin2, Apwm, Bpwm);
  sensorInit(followerSensorsPins, farLeftSensorPin, leftSensorPin, midSensorPin,
             rightSensorPin, farRightSensorPin, internalPullUp);
  PID_init(followerPID, valP, valI, valD);
}

uint8_t makeItPositive(uint8_t val) {
  if (val < 0) {
    return val * -1;
  }
  return val;
}

uint8_t slowerSpeedVal(uint8_t pidOut) {
  if (BASESPEED - makeItPositive(pidOut) <= 0) {
    return 0;
  }
  return BASESPEED - makeItPositive(pidOut);
}

uint8_t fasterSpeedVal(uint8_t pidOut) {
  if (BASESPEED + makeItPositive(pidOut) >= 255) {
    return 254;
  }
  return BASESPEED + makeItPositive(pidOut);
}

void followerUpdate(sensorsPins *followerSensorsPins, PIDVals *followerPID) {

  PID_updateError(followerPID, getSensorsVals(followerSensorsPins, FALSE));
  PID_calculatePID(followerPID);
  PID_updateOutput(followerPID);

  if (followerPID->output < 0) {
    setMotorsSpeed(fasterSpeedVal(followerPID->output),
                   slowerSpeedVal(followerPID->output));

  } else if (followerPID->output > 0) {
    setMotorsSpeed(slowerSpeedVal(followerPID->output),
                   fasterSpeedVal(followerPID->output));

  } else if (followerPID->output == 0) {
    setMotorsSpeed(BASESPEED, BASESPEED);
  }
}

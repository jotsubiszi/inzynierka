#include "lineFollower.h"

void followerInit(uint8_t Ain1, uint8_t Ain2, uint8_t Bin1, uint8_t Bin2,
                  uint8_t Apwm, uint8_t Bpwm, uint8_t farLeftSensorPin,
                  uint8_t leftSensorPin, uint8_t midSensorPin,
                  uint8_t rightSensorPin, uint8_t farRightSensorPin,
                  uint8_t internalPullUp, int valP, int valI, int valD,
                  Motors *followerMotors, sensorsPins *followerSensorsPins,
                  PIDVals *followerPID) {
  motorsInit(followerMotors, Ain1, Ain2, Bin1, Bin2, Apwm, Bpwm);
  sensorInit(followerSensorsPins, farLeftSensorPin, leftSensorPin, midSensorPin,
             rightSensorPin, farRightSensorPin, internalPullUp);
  PID_init(followerPID, valP, valI, valD);
}

void followerUpdate(sensorsPins *followerSensorsPins, PIDVals *followerPID) {

  PID_updateError(followerPID, getSensorsVals(followerSensorsPins));
  PID_calculatePID(followerPID);
  PID_updateOutput(followerPID);

  if (followerPID->output > 127) {
    followerPID->output = 127;
  }

  if (followerPID->output > 0) {
    setMotorsSpeed(128, followerPID->output);
  } else if (followerPID->output < 0) {
    setMotorsSpeed(followerPID->output, 128);
  } else {
    setMotorsSpeed(128, 128);
  }
}

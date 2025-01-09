#include "PID.h"
#include "motors.h"
#include "sensors.h"

void followerInit(uint8_t Ain1, uint8_t Ain2, uint8_t Bin1, uint8_t Bin2,
                  uint8_t Apwm, uint8_t Bpwm, uint8_t farLeftSensorPin,
                  uint8_t leftSensorPin, uint8_t midSensorPin,
                  uint8_t rightSensorPin, uint8_t farRightSensorPin,
                  uint8_t internalPullUp, float valP, float valI, float valD,
                  Motors *followerMotors, sensorsPins *followerSensorsPins,
                  PIDVals *followerPID);

void followerUpdate(sensorsPins *followerSensorsPins, PIDVals *followerPID);

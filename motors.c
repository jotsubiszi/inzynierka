#include "motors.h"

void motorsInit(Motors *mPins, uint8_t Ain1, uint8_t Ain2, uint8_t Bin1,
                uint8_t Bin2, uint8_t Apwm, uint8_t Bpwm) {
  mPins->AIN1 = Ain1;
  mPins->AIN2 = Ain2;
  mPins->BIN1 = Bin1;
  mPins->BIN2 = Bin2;
  mPins->APwmVal = Apwm;
  mPins->BPwmVal = Bpwm;

  setPortPin(Ain1, OUTPUT, LOW);
  setPortPin(Bin1, OUTPUT, LOW);
  setPortPin(Ain2, OUTPUT, HIGH);
  setPortPin(Bin2, OUTPUT, HIGH);

  setCounter0PWM();
  set0PWMVal(Apwm, Bpwm);
}

void setMotorsSpeed(uint8_t Apwm, uint8_t Bpwm) { set0PWMVal(Apwm, Bpwm); }

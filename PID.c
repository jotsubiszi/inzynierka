#include "PID.h"

void PID_init(PIDVals *pid, int valP, int valI, int valD) {

  pid->Kp = valP;
  pid->Ki = valI;
  pid->Kd = valD;

  pid->error = 0;
  pid->output = 0;
  pid->prevError = 0;
  pid->prevOutput = 0;
}

void PID_calculateP(PIDVals *pid) { pid->pOut = pid->Kp * pid->error; }

void PID_calculateI(PIDVals *pid) {
  pid->integral = pid->integral + pid->error;
  pid->iOut = pid->Ki * pid->integral;
}

void PID_calculateD(PIDVals *pid) {
  pid->derivative = pid->error - pid->prevError;
  pid->dOut = pid->Kd * pid->derivative;
}

void PID_calculatePID(PIDVals *pid) {
  PID_calculateP(pid);
  PID_calculateI(pid);
  PID_calculateD(pid);
}

void PID_updateOutput(PIDVals *pid) {
  pid->prevOutput = pid->output;
  pid->output = pid->pOut + pid->iOut + pid->dOut;
}

void PID_updateError(PIDVals *pid, int offset) {
  pid->prevError = pid->error;
  pid->error = offset - pid->prevError + pid->prevOutput;
}

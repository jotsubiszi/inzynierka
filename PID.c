#include "PID.h"

void PID_init(PIDVals *pid, int valP, int valI, int valD){

    pid->Kp = valP;
    pid->Ki = valI;
    pid->Kd = valD;

    pid->tau = 0;
    pid->t = 0;
    pid->error = 0;
    pid->output = 0;
    pid->prevError = 0;
    pid->prevOutput = 0;

    pid->setPoint = 0;
}


void PID_calculateP(PIDVals *pid){
    pid->pOut = pid->Kp * pid->error;
}

void PID_calculateI(PIDVals *pid){
    pid->integral = pid->integral + pid->error;
    pid->iOut = pid->Ki * pid->integral;
}

void PID_calculateD(PIDVals *pid){
    pid->derivative = pid->error - pid->prevError;
    pid->dOut = pid->Kd * pid->derivative;
}


void PID_updateOutput(PIDVals *pid){
    pid->prevOutput = pid->output;
    pid->output = pid->pOut + pid->iOut + pid->dOut;
    pid->prevError = pid->error;
}

void PID_updateError(PIDVals *pid, int currentDistance){
    pid->error = currentDistance - pid->prevError + pid->prevOutput;
}

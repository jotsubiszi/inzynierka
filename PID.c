#include "PID.h"

void PID_init(PIDVals *pid, int valP, int valI, int valD){
    pid->Kp = valP;
    pid->Ki = valI;
    pid->Kd = valD;

    pid->tau = 0;
    pid->t = 0;
    pid-> error = 0;
    pid-> output = 0;
    pid-> prevError = 0;
    pid-> prevOutput = 0;
}


int PID_calculateP(PIDVals *pid){
    return 0;
}

int PID_calculateI(PIDVals *pid){
    return 0;
}

int PID_calculateD(PIDVals *pid){
    return 0;
}


int PID_updateOutput(PIDVals *pid){
    return 0;
}

int PID_updateError(PIDVals *pid){
    return 0;
}

typedef struct {
  /*gains*/
  float Kp;
  float Ki;
  float Kd;

  int integral;
  int derivative;

  int pOut;
  int iOut;
  int dOut;

  int error;
  int prevError;

  int output;
  int prevOutput;

} PIDVals;

void PID_init(PIDVals *pid, float, float, float);

void PID_calculateP(PIDVals *pid);
void PID_calculateI(PIDVals *pid);
void PID_calculateD(PIDVals *pid);

void PID_calculatePID(PIDVals *pid);

void PID_updateError(PIDVals *pid, int);
void PID_updateOutput(PIDVals *pid);

typedef struct {
  /*gains*/
  int Kp;
  int Ki;
  int Kd;

  int integral;
  int derivative;

  int pOut;
  int iOut;
  int dOut;

  /*derivative low-pass filter*/
  int tau;

  /*time*/
  int t;

  int error;
  int prevError;

  int output;
  int prevOutput;

  int setPoint;

} PIDVals;

void PID_init(PIDVals *pid, int valP, int valI, int valD);

void PID_calculateP(PIDVals *pid);
void PID_calculateI(PIDVals *pid);
void PID_calculateD(PIDVals *pid);

void PID_updateError(PIDVals *pid, int currentDistance);
void PID_updateOutput(PIDVals *pid);

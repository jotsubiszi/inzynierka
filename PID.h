typedef struct {
	/*gains*/
	int Kp;
	int Ki;
	int Kd;

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
} PIDVals;

void PID_init(PIDVals *pid, int valP, int valI, int valD);

int PID_calculateP(PIDVals *pid);
int PID_calculateI(PIDVals *pid);
int PID_calculateD(PIDVals *pid);

int PID_updateError(PIDVals *pid);
int PID_updateOutput(PIDVals *pid);

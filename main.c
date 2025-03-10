#include "buzzWords.h"
#include "lineFollower.h"

int main(void) {
  PIDVals pid;
  Motors moto;
  sensorsPins sens;

  followerInit(7, 8, 9, 10, 255, 255, 14, 15, 16, 17, 18, 0, VALP, VALI, VALD,
               &moto, &sens, &pid);

  while (1) {
    followerUpdate(&sens, &pid);
  }
  return 0;
}

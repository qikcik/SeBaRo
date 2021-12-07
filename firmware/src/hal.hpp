#include "../lib/Motor/src/Motor.h"
#include "../lib/DOFSensor/src/DOFSensor.h"

#define AIN1 (uint8_t)13
#define AIN2 (uint8_t)12
#define BIN1 (uint8_t)8
#define BIN2 (uint8_t)7
#define PWMA (uint8_t)6
#define PWMB (uint8_t)3

namespace hal
{
    driver::Motor motorA(AIN1, AIN2, PWMA);
    driver::Motor motorB(BIN1, BIN2, PWMB);
    driver::DOFSensor dofSensor = driver::DOFSensor();
}
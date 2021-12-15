// Author: Qikcik (Dominik Rudnik - dominikrudnik01@gmail.com)
// License: MIT

#include "DOFSensor.h"

using namespace driver;

DOFSensor::DOFSensor()
{

}

DOFSensor::~DOFSensor()
{

}

bool DOFSensor::tryEstablishConnection(int16_t maxWait)
{
    while(!mpu.begin())
    {
        delay(EstablishConnectionStep);
        maxWait -= EstablishConnectionStep;
        if(maxWait < 0) return false;
    }

    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

    return true;
}

void DOFSensor::update()
{
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    
    actualState.acceleration.x = a.acceleration.x;
    actualState.acceleration.y = a.acceleration.y;
    actualState.acceleration.z = a.acceleration.z;
    actualState.gyroscope.x = a.gyro.x;
    actualState.gyroscope.y = a.gyro.y;
    actualState.gyroscope.z = a.gyro.z;
}

const DOFState& DOFSensor::getActualState()
{
    return actualState;
}
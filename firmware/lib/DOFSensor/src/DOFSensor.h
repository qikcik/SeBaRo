// Author: Qikcik (Dominik Rudnik - dominikrudnik01@gmail.com)
// License: MIT

#pragma once
#include <Adafruit_MPU6050.h>



namespace driver
{
    struct DOFState
    {
        struct {float x, y, z;} acceleration;
        struct {float x, y, z;} gyroscope; 
    };

    class DOFSensor
    {
    public:
        DOFSensor();
        ~DOFSensor();

        bool tryEstablishConnection(int16_t maxWait);
        void update();
        const DOFState& getActualState();

    protected:
        const int EstablishConnectionStep = 50;

        DOFState actualState;

    private:
        Adafruit_MPU6050 mpu;
    };
}

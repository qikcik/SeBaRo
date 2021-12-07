#pragma once

class Pid
{
    public:
        double kp = 25;
        double ki = 0;
        double kd = 0.8;

        double compute(double input);
        
    protected:
        unsigned long currentTime, previousTime;
        double elapsedTime;
        double error;
        double lastError;
        double input, output; 
        double setPoint = 0;
        double cumError, rateError;
};
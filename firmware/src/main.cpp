// Author: Qikcik (Dominik Rudnik - dominikrudnik01@gmail.com)
// License: MIT

#include <Arduino.h>
#include <hal.hpp>
#include "utils/pid.hpp"
#include "utils/communiaction.hpp"

double z_offset = 0;
bool enable_pid = false;
Pid pid;

// commands
void SET_MOTOR(Communication::Parser::Argument *args, char *response);
void ENABLE_PID(Communication::Parser::Argument *args, char *response);
void SET_PID(Communication::Parser::Argument *args, char *response);
void SET_OFFSET(Communication::Parser::Argument *args, char *response);

// comunniaction
void send_dfo(float x,float y,float z);
void recieve_command();

void setup() 
{
    Communication::parser.registerCommand("SET_MOTOR", "ii", &SET_MOTOR);
    Communication::parser.registerCommand("SET_PID", "ddd", &SET_PID);
    Communication::parser.registerCommand("ENABLE_PID", "i", &ENABLE_PID);
    Communication::parser.registerCommand("SET_OFFSET", "d", &SET_OFFSET);
    Communication::begin();


    if( hal::dofSensor.tryEstablishConnection( 60000 ) )
    {
        Serial.println("Established Connection with 6dof");
    }
}

void loop() 
{
    Communication::recieve();

    hal::dofSensor.update();
    auto& Result = hal::dofSensor.getActualState();
    Communication::send_dfo(Result.gyroscope.x,Result.gyroscope.y,Result.gyroscope.z);


    if(enable_pid)
    {
        double output = pid.compute(Result.gyroscope.y+z_offset);
        hal::motorA.setSpeed(-output);
        hal::motorB.setSpeed(-output);

    }
    else
        delay(25);
}


void SET_MOTOR(Communication::Parser::Argument *args, char *response) 
{
    hal::motorA.setSpeed(args[0].asInt64);
    hal::motorB.setSpeed(args[1].asInt64);
}

void ENABLE_PID(Communication::Parser::Argument *args, char *response) 
{
    enable_pid = args[0].asInt64;
    if(!enable_pid)
    {
        hal::motorA.setSpeed(0);
        hal::motorB.setSpeed(0);
    }
}

void SET_PID(Communication::Parser::Argument *args, char *response) 
{
    pid.kp = args[0].asDouble;
    pid.ki = args[1].asDouble;
    pid.kd = args[2].asDouble;
}

void SET_OFFSET(Communication::Parser::Argument *args, char *response) 
{
    z_offset = args[0].asDouble;
}

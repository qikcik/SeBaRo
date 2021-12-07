#pragma once
#include <CommandParser.h>
#include <Arduino.h>


namespace Communication
{
    typedef CommandParser<5, 3, 10, 64, 64> Parser;
    Parser parser;

    void begin()
    {
        Serial.begin(9600);
    }

    
    void recieve()
    {
        if (Serial.available()) {
            char line[128];
            size_t lineLength = Serial.readBytesUntil('\n', line, 127);
            line[lineLength] = '\0';

            char response[Parser::MAX_RESPONSE_SIZE];
            parser.processCommand(line, response);
        }
    }

    void send_dfo(float x,float y,float z)
    {
        Serial.print("DOF_STATE ");  
        Serial.print(x);
        Serial.print(" ");
        Serial.print(y);
        Serial.print(" ");
        Serial.println(z);
    }
}
//
// Created by Robin Ellingsen on 2022-04-05.
//

#ifndef ARDUINO_CPP_CONVERTTOLITRES_H
#define ARDUINO_CPP_CONVERTTOLITRES_H

class Convert{
private:
    int X;
    int Y;
    float TIME = 0;
    float FREQUENCY = 0;
    float WATER = 0;
    float LS = 0;
    float TOTAL = 0;
public:
    float convertToLitres(float inflow);

};

#endif //ARDUINO_CPP_CONVERTTOLITRES_H

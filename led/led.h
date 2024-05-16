#ifndef LED_H
#define LED_H

#include <chrono>
#include <iostream>

const int gpsLedPin{ 18 };
const int gpsLedDelayDurationMs{ 500 };

class Led {
public:
    Led(int pin);
    void update(bool isConnected);   

private:
    void turnOn();
    void turnOff();
    void toggle();

    int pinNumber;
    bool isBlinking;
    std::chrono::steady_clock::time_point lastUpdateTime;

    void checkAndToggle(); // Method to check elapsed time and toggle LED if needed
};

// -----------------------------------------------------------------------------------------------

class RGBLed {
public:
    RGBLed(int pinRed, int pinGreen, int pinBlue);
    void update(bool isConnected);   

private:
    void turnOn();
    void turnOff();
    void toggle();

    int pinRedNumber;
    int pinGreenNumber;
    int pinBlueNumber;

    bool isBlinking;
    std::chrono::steady_clock::time_point lastUpdateTime;

    void checkAndToggle(); // Method to check elapsed time and toggle LED if needed
};



#endif // LED_H
#ifndef RGBLED_H
#define RGBLED_H

#include <chrono>

const int configChangeLedDelayMs{ 400 };
const int hazardChangeLedDelayMs{ 1000 };

class RgbLed{
public:

    RgbLed(int redPin, int greenPin, int bluePin);

    void bumpDetected();
    void pitDetected();
    void configurationChanged(int configNumber);

    void update();

private:

    enum class Color { Red, Green, Blue};

    void setColor(int red, int green, int blue);
    void setColor(Color color);
    void resetColor();

    int redPin, greenPin, bluePin;
    std::chrono::steady_clock::time_point lastEventTime;

    enum class Event { None, Bump, Pit, ConfigChange };
    
    Event currentEvent;
    int configNumber;
};


#endif // RGBLED_H
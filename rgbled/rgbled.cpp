#include "rgbled.h"


RgbLed::RgbLed(int r, int g, int b) : redPin(r), greenPin(g), bluePin(b), lastEventTime(std::chrono::steady_clock::now()), currentEvent(Event::None) {
    // pinMode(redPin, OUTPUT)
    // pinMode(greenPin, OUTPUT)
    // pinMode(bluePin, OUTPUT)

    RgbLed::resetColor();
}

void RgbLed::setColor(int red, int green, int blue) {
    // You can set the color by controlling the GPIO pins:

    // digitalWrite(redPin, red ? HIGH : LOW);
    // digitalWrite(greenPin, green ? HIGH : LOW);
    // digitalWrite(bluePin, blue ? HIGH : LOW);
}

void RgbLed::resetColor() {
    // Turn off all colors
    RgbLed::setColor(0, 0, 0);
}

void RgbLed::bumpDetected() {
    currentEvent = Event::Bump;
    lastEventTime = std::chrono::steady_clock::now();
}

void RgbLed::pitDetected() {
    currentEvent = Event::Pit;
    lastEventTime = std::chrono::steady_clock::now();
}

void RgbLed::configurationChanged(int configNum) {
    currentEvent = Event::ConfigChange;
    configNumber = configNum;
    lastEventTime = std::chrono::steady_clock::now();
}


void RgbLed::update() {
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastEventTime).count();

    switch (currentEvent){

        case Event::Bump:
            if (elapsed <= hazardChangeLedDelayMs) {
                RgbLed::setColor(0, 1, 0); // Green
            } else {
                RgbLed::resetColor();
                currentEvent = Event::None;
            }
            break;
        
        case Event::Pit:
            if (elapsed <= hazardChangeLedDelayMs) {
                RgbLed::setColor(1, 0, 0); // Red
            } else {
                RgbLed::resetColor();
                currentEvent = Event::None;
            }
            break;
        
        case Event::ConfigChange:
            if (elapsed % configChangeLedDelayMs*2 < configChangeLedDelayMs) {
                RgbLed::setColor(0, 0, 1); // Blue
            } else {
                RgbLed::resetColor();
            }
            if (elapsed > configChangeLedDelayMs * configNumber) {
                currentEvent = Event::None;
            }
            break;
        
        default:
            RgbLed::resetColor();
            break;
    }
}

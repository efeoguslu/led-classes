#include "rgbled.h"

const int redPinNumber{ 9 };
const int greenPinNumber{ 10 };
const int bluePinNumber{ 11 };

int main() {

    RgbLed rgbLed(redPinNumber, greenPinNumber, bluePinNumber);

    while (true) {

        // Simulate events
        rgbLed.bumpDetected(); // Trigger a bump event

        rgbLed.pitDetected(); // Trigger a pit event

        rgbLed.configurationChanged(2); // Trigger a configuration change event



        // ...

        rgbLed.update(); // Update the LED state based on elapsed time
    }

    return 0;
}
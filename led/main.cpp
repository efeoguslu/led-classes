#include "led.h"

int main(){
    // Initialization code remains the same...

    Led gpsLed{ gpsLedPin }; // Create an LED object for the GPS LED

    // Rest of your initialization code...

    while (true) {
        // Existing code to read from the GPS module...

        
        std::string validity = "V";

        if (validity == "A") {
            gpsLed.update(true);
        }

        else if (validity == "V") {
            gpsLed.update(false);
        }
        
    }

    // Cleanup code...
}
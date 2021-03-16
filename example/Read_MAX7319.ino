/*
 * In this sketch the MAX7319 is read and the 
 * resulting port and transition states are
 * returned to the parameter values of the 
 * read-function.
 */

#include "iotec_MAX7319.h"

// Create instance
iotec_MAX7319 inputs(0x68);
uint32_t now = 0;
uint16_t lastSend = 0;
 
void setup() {
    // Init serial interface for debugging
    Serial.begin(115200);
    delay(100);
    Serial.println("This is iotec_MAX7319 lib!")

    // Init I2C interface
    inputs.begin();
}

void loop() {
    // update millis
    now = millis();

    // Run into each sekond
    if (now - lastSend > 1000) {
        // reset last send var
        lastSend = now;

        // read whole port and corresponding flag
        if (inputs.read(&ports, &flags)) {
            // print port and flag state
            Serial.print("Port: ");
            Serial.print(ports);
            Serial.print("; Flags: ");
            Serial.println(flags);
        } else {
            Serial.println("Read failed!");
        }
    }
}

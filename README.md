# iotec_MAX7319

With the iotec_MAX7319 library you are able to read the IO and its transition states from the MAX7319.

## Usage

Here is an example on how to use the library and reading the port and transition states each second.

```cpp
#include "iotec_MAX7319.h"

// Create instance
iotec_MAX7319 inputs(0x68); // AD0 & AD2 to gnd
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
```

## Repository Contents

- /example – example sketch for the library
- /src – source files for the library (.cpp, .h)

## Features

- Read IO port state
- Read IO port transition state 

The input states returned via an uint8_t parameter of the `read-funtion` where the MSB matches the I7 and the LSB the I0 input.
The transition states also returned via an uint8_t parameter of the `read-funtion` where the MSB matches the F7 and the LSB the F0. The flags will be resetted after reading.

## Contribute

We look forward to contributions, reports or comments on the library.

If you have any question feel free to contact us: info@iotec-gmbh.de

## License

See LICENSE file for more information.

Copyright (c) 2021 iotec GmbH

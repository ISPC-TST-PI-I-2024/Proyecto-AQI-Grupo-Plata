#include "ML8511Sensor.h"

ML8511Sensor::ML8511Sensor(int pin, int refPin) : uvPin(pin), ref3V3Pin(refPin) {}

void ML8511Sensor::begin() {
    pinMode(uvPin, INPUT);
    pinMode(ref3V3Pin, INPUT);
}

float ML8511Sensor::readUV() {
    int uvLevel = analogRead(uvPin);
    int refLevel = analogRead(ref3V3Pin);

    float outputVoltage = 3.3 / refLevel * uvLevel;
    float uvIntensity = map(outputVoltage, 0.99, 2.9, 0.0, 15.0);

    return uvIntensity;
}

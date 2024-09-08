#include "ML8511sensor.h"

ML8511Sensor::ML8511Sensor(int pin, int refPin) : uvPin(pin), ref3V3Pin(refPin) {}

void ML8511Sensor::begin() {
    pinMode(uvPin, INPUT);
    pinMode(ref3V3Pin, INPUT);
}

float ML8511Sensor::readUV() {
    int uvLevel = analogRead(uvPin);
    int refLevel = analogRead(ref3V3Pin);

    // Verificar que refLevel no sea cero para evitar división por cero
    if (refLevel == 0) {
        return NAN; // Retorna NaN si hay un error
    }

    float outputVoltage = 3.3 / refLevel * uvLevel;
    float uvIntensity = mapFloat(outputVoltage, 0.99, 2.9, 0.0, 15.0);

    return uvIntensity;
}

// Función personalizada para mapear valores flotantes
float ML8511Sensor::mapFloat(float x, float in_min, float in_max, float out_min, float out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

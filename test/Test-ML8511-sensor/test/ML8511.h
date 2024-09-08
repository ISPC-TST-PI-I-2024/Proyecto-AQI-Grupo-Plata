#ifndef ML8511SENSOR_H
#define ML8511SENSOR_H

#include <Arduino.h>

class ML8511Sensor {
public:
    ML8511Sensor(int pin, int refPin);
    void begin();
    float readUV();

private:
    int uvPin;
    int ref3V3Pin;
    float mapFloat(float x, float in_min, float in_max, float out_min, float out_max); // Declaración de la función mapFloat
};

#endif

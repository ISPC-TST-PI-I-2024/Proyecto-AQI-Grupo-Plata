#include "MQ135Sensor.h"

MQ135Sensor::MQ135Sensor(int pin) : mq135(pin) {}

void MQ135Sensor::begin() {
    for (int i = 0; i < NUM_READINGS; i++) {
        mq135Readings[i] = 0;
    }
}

float MQ135Sensor::readFilteredData() {
    float gas = mq135.getPPM();

    // Actualizar la media móvil
    mq135Total -= mq135Readings[mq135ReadIndex];
    mq135Readings[mq135ReadIndex] = gas;
    mq135Total += mq135Readings[mq135ReadIndex];
    mq135ReadIndex = (mq135ReadIndex + 1) % NUM_READINGS;
    mq135Average = mq135Total / NUM_READINGS;

    // Filtrado de datos erróneos
    if (mq135Average < 10 || mq135Average > 1000) {
        return -1;
    }

    return mq135Average;
}
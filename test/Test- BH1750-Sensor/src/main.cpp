#include <Wire.h>
#include "BH1750Sensor.h"

BH1750Sensor sensor;

void setup() {
    // Inicializamos la comunicación serial para ver los resultados en el monitor serie
    Serial.begin(9600);
    
    // Inicializamos el sensor BH1750
    sensor.begin();
    Serial.println("Sensor BH1750 iniciado");
}

void loop() {
    // Leemos el nivel de luz en lux
    float lux = sensor.leerLux();
    
    // Imprimimos el valor en el monitor serie
    Serial.print("Nivel de luz: ");
    Serial.print(lux);
    Serial.println(" lx");

    // Esperamos 1 segundo antes de hacer otra lectura
    delay(1000);
}
#include <Arduino.h>
#include "BH1750_Sensor.h"
#include "myFunctions.h"  


BH1750_Sensor sensor;

void setup() {
    Serial.begin(115200);
    sensor.begin();  // Iniciar el sensor BH1750
}

void loop() {
    float lux = sensor.readLightLevel();  // Leer nivel de luz en lux
    Serial.print("Luz: ");
    Serial.print(lux);
    Serial.println(" lux");

    // Ejemplo de uso de la función myFunction()
    int resultado = myFunction(3, 4);  // Llama a la función con valores 3 y 4
    Serial.print("Resultado de myFunction(3, 4): ");
    Serial.println(resultado);  // Imprime el resultado (3 + 4 = 7)

    delay(1000);  // Leer cada segundo


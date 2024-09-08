#include <Arduino.h>
#include <ML8511.h>


ML8511Sensor uvSensor(GPIO34, 3.3);

void setup() {
    Serial.begin(115200);
    uvSensor.begin();
}

void loop() {
    float uvIntensity = uvSensor.readUV();
    Serial.print("Intensidad UV: ");
    Serial.print(uvIntensity);
    Serial.println(" mW/cm²");
    delay(1000);
}

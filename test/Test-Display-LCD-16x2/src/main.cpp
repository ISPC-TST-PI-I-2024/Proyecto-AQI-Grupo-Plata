#include <Arduino.h>
#include "lcd_display.h"

// Creamos una instancia de LCDDisplay, pasando la dirección I2C y el tamaño del display
LCDDisplay lcd(0x27, 16, 2);

void setup() {
    lcd.begin();             // Inicializamos la pantalla LCD
    lcd.printMessage("Grupo Plata!!");  // Mostramos el mensaje "Hola Mundo!" en la pantalla
}

void loop() {
    // Aquí puedes agregar más código si lo necesitas en el futuro
}

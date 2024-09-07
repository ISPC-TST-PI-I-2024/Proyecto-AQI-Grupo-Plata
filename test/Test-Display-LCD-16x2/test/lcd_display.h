#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

// Incluimos las librerías necesarias
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Definimos una clase llamada LCDDisplay
class LCDDisplay {
public:
    // Constructor de la clase: se usa para crear una instancia de LCDDisplay
    LCDDisplay(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows);

    // Función para inicializar la pantalla LCD
    void begin();

    // Función para imprimir un mensaje en la pantalla LCD
    void printMessage(const char* message);

private:
    // Creamos un objeto de la clase LiquidCrystal_I2C que representa nuestro display LCD
    LiquidCrystal_I2C lcd;
};

#endif

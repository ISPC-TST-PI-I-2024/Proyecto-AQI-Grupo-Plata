## Archivos del Proyecto
```cpp

main.cpp

#include <Arduino.h>           // Esta librería permite usar las funciones básicas de Arduino
#include "lcd_display.h"       // Incluimos nuestro archivo de cabecera, donde definimos la clase LCDDisplay

// Creamos una instancia de LCDDisplay, pasando la dirección I2C (0x27) y el tamaño del display (16 columnas, 2 filas)
LCDDisplay lcd(0x27, 16, 2);

void setup() {
    lcd.begin();                 // Inicializamos la pantalla LCD
    lcd.printMessage("Grupo Plata!!");  // Mostramos el mensaje "Grupo Plata!!" en la pantalla LCD
}

void loop() {
    // Aquí puedes agregar más código si lo necesitas en el futuro
}

Explicación:

main.cpp es el archivo principal del proyecto. Aquí se llaman las funciones definidas en las otras partes del código.
En setup(), se inicializa la pantalla y se muestra un mensaje de bienvenida.
loop() está vacío porque no se necesita repetir ninguna acción continuamente, pero se puede usar para agregar más funcionalidades en el futuro.


//----------------------------------------------------------------------------------

lcd_display.cpp

#include "lcd_display.h"  // Incluimos la cabecera de la clase LCDDisplay

// Constructor: Configura la dirección I2C y el tamaño de la pantalla LCD
LCDDisplay::LCDDisplay(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows) 
    : lcd(lcd_addr, lcd_cols, lcd_rows) {}

// Función begin: Inicializa la pantalla LCD
void LCDDisplay::begin() {
    lcd.init();         // Inicializa la pantalla LCD
    lcd.backlight();    // Activa la luz de fondo para que sea visible
}

// Función printMessage: Imprime un mensaje en la pantalla LCD
void LCDDisplay::printMessage(const char* message) {
    lcd.clear();          // Limpia la pantalla antes de mostrar un nuevo mensaje
    lcd.setCursor(0, 0);  // Establece el cursor en la primera línea y primera columna
    lcd.print(message);   // Imprime el mensaje en la pantalla LCD
}

Explicación:

lcd_display.cpp contiene la implementación de la clase LCDDisplay.
El constructor recibe la dirección I2C, el número de columnas y filas del LCD, y usa estos valores para inicializar el objeto lcd.
La función begin() inicializa la pantalla y enciende la luz de fondo.
La función printMessage() limpia la pantalla y luego imprime un mensaje en la primera línea de la pantalla LCD.  

//----------------------------------------------------------------------------------  

lcd_display.h

#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

// Incluimos las librerías necesarias para controlar el display LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Definimos la clase LCDDisplay para gestionar el display LCD
class LCDDisplay {
public:
    // Constructor de la clase, que inicializa el LCD con su dirección I2C, número de columnas y filas
    LCDDisplay(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows);

    // Función para inicializar el LCD
    void begin();

    // Función para imprimir un mensaje en el LCD
    void printMessage(const char* message);

private:
    // Objeto de la clase LiquidCrystal_I2C que controla el display LCD
    LiquidCrystal_I2C lcd;
};
#endif

Explicación:

lcd_display.h es el archivo de cabecera que define la clase LCDDisplay.
Este archivo contiene las declaraciones de las funciones y el constructor de la clase.
La clase LCDDisplay encapsula la funcionalidad para interactuar con el LCD utilizando el protocolo I2C.

¿Cómo usar y probar este programa?

Lo que debes hacer es copiar los archivos lcd_display.cpp, y lcd_display.h que estan la carpeta de "test" y pegarlos en la carpeta de "src" junto con el archivo main.cpp.

Compila y sube el código al ESP32.

Después de subir el código, el display LCD mostrará el mensaje "Grupo Plata!!" en la primera línea de la pantalla.

Personalización
Puedes cambiar el mensaje en el método lcd.printMessage() dentro de setup() para mostrar cualquier texto que desees.



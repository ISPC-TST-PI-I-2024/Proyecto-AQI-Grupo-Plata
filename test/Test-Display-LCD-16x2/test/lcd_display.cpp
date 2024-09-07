#include "lcd_display.h"

// Constructor: Configura la dirección I2C y el tamaño de la pantalla LCD
LCDDisplay::LCDDisplay(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows) 
    : lcd(lcd_addr, lcd_cols, lcd_rows) {}

// Función begin: Inicializa la pantalla LCD
void LCDDisplay::begin() {
    lcd.init();       // Inicia la pantalla
    lcd.backlight();  // Activa la luz de fondo para que sea visible
}

// Función printMessage: Imprime un mensaje en la pantalla
void LCDDisplay::printMessage(const char* message) {
    lcd.clear();       // Limpia la pantalla
    lcd.setCursor(0, 0); // Establece el cursor en la primera línea y primera columna
    lcd.print(message); // Imprime el mensaje en la pantalla
}



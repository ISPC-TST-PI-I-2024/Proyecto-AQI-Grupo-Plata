#ifndef WS2812_H
#define WS2812_H

#include <Adafruit_NeoPixel.h>

// Definición del pin donde está conectado el anillo WS2812
#define PIN_WS2812 4   
// Definición del número de LEDs en el anillo
#define NUM_LEDS 18    

// Definición de la clase WS2812 para controlar el anillo de LEDs
class WS2812 {
public:
    // Constructor: inicializa el objeto con el pin de datos y el número de LEDs
    WS2812(int pin, int numLeds);
    
    // Método para configurar el anillo de LEDs
    void setup();
    
    // Método para establecer un color RGB en todos los LEDs
    void setColor(uint8_t r, uint8_t g, uint8_t b);
    
    // Método para apagar todos los LEDs
    void clear();

private:
    // Objeto Adafruit_NeoPixel para manejar los LEDs WS2812
    Adafruit_NeoPixel strip;
};

#endif

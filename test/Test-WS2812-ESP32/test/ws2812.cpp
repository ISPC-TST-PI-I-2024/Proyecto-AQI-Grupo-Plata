#include "ws2812.h"

// Constructor de la clase WS2812, se inicializa el objeto strip con el número de LEDs y el pin de datos
WS2812::WS2812(int pin, int numLeds) : strip(numLeds, pin, NEO_GRB + NEO_KHZ800) {}

void WS2812::setup() {
    // Inicializa el anillo de LEDs
    strip.begin();
    strip.show();  // Asegura que todos los LEDs se inicien apagados
}

void WS2812::setColor(uint8_t r, uint8_t g, uint8_t b) {
    // Establece el color RGB en todos los LEDs del anillo
    for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(r, g, b));
    }
    // Actualiza los LEDs para mostrar el nuevo color
    strip.show();
}

void WS2812::clear() {
    // Apaga todos los LEDs del anillo
    strip.clear();
    strip.show();
}

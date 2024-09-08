#include <Arduino.h>
#include "ws2812.h"

// Instancia del controlador WS2812, se pasa el pin de conexión y la cantidad de LEDs
WS2812 ws2812(PIN_WS2812, NUM_LEDS);

// Definición de una matriz de colores RGB predefinidos
uint8_t colores[8][3] = {
    {255, 0, 0},   // Rojo
    {255, 128, 0}, // Naranja
    {255, 255, 0}, // Amarillo
    {0, 255, 0},   // Verde
    {0, 255, 255}, // Cian
    {0, 0, 255},   // Azul
    {128, 0, 255}, // Morado
    {255, 0, 255}  // Magenta
};

// Índice para seleccionar el color actual de la matriz
int indiceColorActual = 0;

void setup() {
    // Inicializa el controlador WS2812
    ws2812.setup();
}

void loop() {
    // Establece el color actual en el anillo de LEDs
    ws2812.setColor(colores[indiceColorActual][0], colores[indiceColorActual][1], colores[indiceColorActual][2]);

    // Espera 1 segundo antes de cambiar al siguiente color
    delay(1000);

    // Incrementa el índice del color, reiniciando si llega al final de la lista
    indiceColorActual = (indiceColorActual + 1) % 8;
}

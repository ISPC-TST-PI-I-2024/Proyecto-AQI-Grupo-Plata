# Descripción

El código está estructurado en tres archivos principales:

- **main.cpp**: Contiene la lógica principal del programa. Utiliza una clase `WS2812` para controlar un anillo de LEDs WS2812 y cambiar su color en bucle.
- **ws2812.cpp**: Implementa los métodos para controlar los LEDs usando la librería `Adafruit_NeoPixel`.
- **ws2812.h**: Define la clase `WS2812` y sus métodos principales.

## Funcionalidad

El proyecto controla un anillo de LEDs WS2812 conectado al pin GPIO 4 (definido como `PIN_WS2812`) y que contiene 18 LEDs (definido como `NUM_LEDS`). Los LEDs cambian de color automáticamente entre una serie de 8 colores predefinidos, actualizando el color cada segundo.

### Colores predefinidos

1. Rojo
2. Naranja
3. Amarillo
4. Verde
5. Cian
6. Azul
7. Morado
8. Magenta

El color actual se configura utilizando el método `setColor(r, g, b)` de la clase `WS2812`, el cual establece el color RGB en todos los LEDs del anillo.

## Requisitos

- [PlatformIO](https://platformio.org/) instalado en tu sistema
- Un microcontrolador compatible con Arduino
- Un anillo de LEDs WS2812
- La librería `Adafruit_NeoPixel` instalada en PlatformIO

## Instalación de librerías

El proyecto utiliza la librería `Adafruit_NeoPixel` para controlar los LEDs WS2812. Puedes instalarla en PlatformIO mediante el archivo `platformio.ini`, añadiendo la siguiente línea bajo `[env]`:

**lib_deps = adafruit/Adafruit NeoPixel@^1.10.7**

## Conexión de Hardware

1. Conecta el pin de datos del anillo WS2812 al pin GPIO 4 del microcontrolador.
2. Conecta VCC a una fuente de 5V y GND a tierra.

## ¿Cómo usar y probar este programa?

Lo que debes hacer es copiar los archivos **ws2812.cpp** y **ws2812.h** que estan la carpeta de "test" y pegarlos en la carpeta de "src" junto con el archivo **main.cpp**.

## Compilación y Carga

1. Clona este repositorio en tu entorno local.
2. Abre el proyecto en PlatformIO.
3. Conecta tu ESP32.
4. Compila y carga el programa en la placa utilizando PlatformIO.  

Una vez cargado el programa en tu microcontrolador:

- Los LEDs en el anillo WS2812 empezarán a cambiar de color cada segundo.
- Si deseas cambiar la secuencia de colores, puedes modificar la matriz `colores` en `main.cpp`.
- Para detener la animación, puedes utilizar el método `clear()` de la clase `WS2812`.

## Archivos

- **main.cpp**: Controlador principal del programa.
- **ws2812.cpp**: Implementación de la clase `WS2812`.
- **ws2812.h**: Declaración de la clase `WS2812`.

## Créditos

Este proyecto utiliza la librería [Adafruit NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel) para controlar el anillo de LEDs WS2812.

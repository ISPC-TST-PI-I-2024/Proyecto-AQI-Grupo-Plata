
[![imagen-ispc-AQI.jpg](https://i.postimg.cc/VNLgnVq1/imagen-ispc-AQI.jpg)](https://postimg.cc/QFwcrSYn)

## Descripción General

Este proyecto tiene como objetivo desarrollar un microservicio utilizando un ESP32-Wroom de 38 pines para la recolección de datos de varios sensores: **MQ135, AHT25, BMP280, BH1750, ML8511,** la gestión de un módulo LED **WS2812**.
El sistema está diseñado para ser escalable y fácil de mantener, con cada sensor gestionado por un módulo independiente. Los datos recogidos son filtrados y mostrados en el monitor serie.  

## Estructura del Proyecto

**test/**  
archivos.cpp  
archivos.h  
**src/**  
main.cpp   

## Descripción de los Módulos

 [![1-2-1.jpg](https://i.postimg.cc/4xBCz44n/1-2-1.jpg)](https://postimg.cc/DSJYhTXK) 

### 1. **main.cpp**

En este módulo se maneja la ejecución del programa, inicializando cada uno de los módulos de sensores y gestionando el bucle principal donde se realizan las lecturas de datos. Los datos obtenidos de cada sensor se filtran para eliminar valores erróneos y se muestran en el monitor serie.

#### Flujo de trabajo en `main.cpp`:

- Inicializa el sistema de sensores en `setup()`.
- Realiza lecturas cíclicas en el `loop()`, llamando a los métodos de cada módulo sensor.
- Muestra los datos en el monitor serie y maneja la lógica básica de filtrado.

### 2. **MQ135Sensor.h y MQ135Sensor.cpp**

Estos archivos implementan la clase `MQ135Sensor`, encargada de gestionar el sensor **MQ135** que mide la calidad del aire.

#### Funciones clave:

- `begin()`: Inicializa el sensor y configura el filtro de media móvil para suavizar las lecturas.
- `readFilteredData()`: Lee los datos del sensor, aplica un filtro de media móvil y devuelve el valor filtrado o -1 si la lectura es inválida.

### 3. **AHT25Sensor.h y AHT25Sensor.cpp**

Estos archivos implementan la clase `AHT25Sensor`, responsable de gestionar el sensor **AHT25** que mide temperatura y humedad relativa.

#### Funciones clave:

- `begin()`: Inicializa el sensor y verifica su disponibilidad en el bus I2C.
- `readData(float &temperature, float &humidity)`: Lee los datos de temperatura y humedad, aplicando filtros de validación.

### 4. **BMP280Sensor.h y BMP280Sensor.cpp**

Estos archivos implementan la clase `BMP280Sensor`, que gestiona el sensor **BMP280** para la medición de temperatura y presión barométrica.

#### Funciones clave:

- `begin()`: Inicializa el sensor y verifica su disponibilidad en el bus I2C.
- `readData(float &temperature, float &pressure)`: Lee los datos de temperatura y presión del sensor, aplicando filtros para descartar valores fuera de rangos predefinidos.

### 5. **LCDDisplay.h y LCDDisplay.cpp**

Estos archivos implementan la clase `LCDDisplay`, que se encarga de gestionar la pantalla **LCD de 16x2** con conexión I2C.

#### Funciones clave:

- `begin()`: Inicializa la pantalla LCD utilizando el bus I2C.
- `printMessage(const String &message)`: Muestra un mensaje personalizado en la pantalla LCD.
- `clear()`: Limpia el contenido de la pantalla.

### 6. **BH1750Sensor.h y BH1750Sensor.cpp**

Estos archivos implementan la clase `BH1750Sensor`, encargada de gestionar el sensor **BH1750** que mide la intensidad lumínica.

#### Funciones clave:

- `begin()`: Inicializa el sensor BH1750 y configura su modo de operación en el bus I2C.
- `readLightLevel()`: Lee el nivel de luz en luxes del sensor y devuelve el valor. Aplica un filtro para descartar lecturas fuera del rango.

#### Características del BH1750:

- **Tipo**: Sensor digital (I2C)
- **Conexión**: I2C (GPIO21 - SDA, GPIO22 - SCL)
- **Rango**: 1 a 65,535 lux

### 7. **ML8511Sensor.h y ML8511Sensor.cpp**

Estos archivos implementan la clase `ML8511Sensor`, responsable de gestionar el sensor **ML8511** que mide la radiación ultravioleta.

#### Funciones clave:

- `begin()`: Inicializa el sensor ML8511.
- `readUVIntensity()`: Lee el nivel de radiación UV y devuelve el valor en mW/cm².

#### Características del ML8511:

- **Tipo**: Sensor analógico
- **Conexión**: Pin analógico (GPIO34)
- **Rango**: 0 a 15 mW/cm²

### 8. **WS2812.h y WS2812.cpp**

Estos archivos implementan la clase `WS2812`, que gestiona el módulo LED **WS2812** para control de iluminación RGB.

#### Funciones clave:

- `begin()`: Inicializa el módulo LED.
- `setColor(uint8_t r, uint8_t g, uint8_t b)`: Configura el color del LED.
- `cycleColors()`: Realiza una animación de colores cíclica (rojo, amarillo, verde).

#### Características del WS2812:

- **Tipo**: LED direccionable
- **Conexión**: Pin digital (GPIO14)
- **Colores**: RGB

# Esquema de Implementacion del ESP32 con sus Conexiones**  


![Esquema de coneccion](https://github.com/user-attachments/assets/5f5cb24f-54a3-4713-b13c-3904172625a3)


En el esquema del proyecto de monitoreo de calidad del aire con el ESP32, se están utilizando varios sensores y dispositivos conectados al microcontrolador ESP32 mediante diferentes protocolos.

**<u> Sensor de Gas MQ135 (conexión analógica):**</u>

- Este sensor mide la calidad del aire midiendo la concentración de gases. Está conectado a un pin analógico del ESP32 (marcado en rosa), que leerá las variaciones de voltaje que el sensor produce.

**<u> Sensor de Luz BH1750 (conexión I2C):**</u>

- Este sensor mide la intensidad lumínica y está conectado a los pines SCL y SDA del ESP32 (protocolos I2C, marcados en amarillo). Usa comunicación I2C, lo que permite compartir los mismos pines con otros dispositivos I2C.

**<u> Sensor de Presión BMP280 (conexión I2C):**</u>

- El BMP280 mide la presión y la temperatura. También usa comunicación I2C (pines SCL y SDA compartidos).

**<u> Sensor de Temperatura y Humedad AM2320 (conexión I2C):**</u>

- Similar al BH1750, este sensor usa I2C para medir temperatura y humedad. Comparte los pines I2C (SCL y SDA).

**<u>Sensor UV ML8511 (conexión analógica):**</u>

- El sensor mide los niveles de radiación ultravioleta. Está conectado a un pin analógico del ESP32.

**<u> LED WS2812:**</u>

- Este es un LED RGB direccionable. Su control se realiza por un pin digital del ESP32. Permite controlar la iluminación con diferentes colores.

**<u>Pulsadores Touch:**</u>

- Los botones táctiles están conectados a pines digitales del ESP32, permitiendo la interacción manual.

**<u> Pantalla LCD 2x16 (conexión I2C):**</u>

- La pantalla se conecta a los pines I2C (SCL y SDA), permitiendo mostrar información de los sensores.

Todos estos dispositivos están conectados a través de protocolos analógicos y digitales (I2C para varios sensores), mientras que el ESP32 procesa los datos y controla las salidas como la pantalla y el LED.

## **Librerías necesarias**

Para que el programa funcione es necesario instalar las siguientes librerías en el IDE:

- **Adafruit BMP280.h**
- **Adafruit AHTX0.h**
- **MQ135.h**
- **LiquidCrystal_I2C.h**

Para el caso de PlatformIO, las mismas pueden instalarse desde el gestor de librerías buscando el nombre de cada una y haciendo click en `install`.

# **Configuración de Hardware**

Los sensores se conectan al ESP32-Wroom según las siguientes especificaciones:

- **MQ135 (Analógico):**
  - **VCC:** 3.3V
  - **GND:** GND
  - **Salida de señal:** GPIO34 (ADC1_CH6)
  
- **AHT25 (I2C):**
  - **VCC:** 3.3V
  - **GND:** GND
  - **SDA:** GPIO21
  - **SCL:** GPIO22
  
- **BMP280 (I2C):**
  - **VCC:** 3.3V
  - **GND:** GND
  - **SDA:** GPIO21
  - **SCL:** GPIO22

- **Display LCD 16x2 (I2C):**
  - **VCC:** 5V (o 3.3V, dependiendo del módulo)
  - **GND:** GND
  - **SDA:** GPIO21
  - **SCL:** GPIO22 

- **BH1750 (I2C):**
  - **VCC:** 3.3V
  - **GND:** GND
  - **SDA:** GPIO21
  - **SCL:** GPIO22

- **ML8511 (Analógico):**
  - **VCC:** 3.3V
  - **GND:** GND
  - **Salida de señal:** GPIO36 (ADC1_CH0)
  
- **WS2812 (LED RGB direccionable):**
  - **VCC:** 5V
  - **GND:** GND
  - **Datos:** GPIO14


### 3. **Compilación y Carga del Código**

Seguir los siguientes pasos:  

1. Abrir el proyecto en el IDE Platformio o en VScode con Platformio integrado.
2. Seleccionar la placa **ESP32 Dev Module** en el menú **Tools > Board**.
3. Seleccionar el puerto correcto donde está conectado el ESP32.
4. Compilar y cargar el código en el ESP32.

### 4. **Monitoreo de Datos**

Abrir el **Monitor Serie** en el IDE y configurarlo a **115200 baudios** para observar las lecturas de los sensores. Los datos se mostrarán en tiempo real y se indicará si alguna lectura es inválida debido a valores fuera de los rangos definidos.

## Futuras Expansiones

Este proyecto está diseñado para ser fácilmente escalable.   
Se puedes agregar más sensores o funcionalidades, como enviar los datos a una plataforma en la nube o a un servidor remoto.   
El código modular facilita la incorporación de nuevas características sin afectar la estructura existente.

## Contribuciones

Si deseas contribuir a este proyecto, por favor, abre un issue o un pull request. Todas las contribuciones son bienvenidas.

## Licencia

Este proyecto está licenciado bajo la Licencia Creative Commons Atribución-NoComercial (CC BY-NC). Esta licencia permite que otros remixen, adapten y construyan sobre el trabajo de forma no comercial y, aunque sus nuevos trabajos deben también reconocer al autor original y ser no comerciales, no tienen que licenciar sus obras derivadas en los mismos términos.

Esta licencia es adecuada para un uso educativo y de aprendizaje, permitiendo la libre distribución y utilización del material mientras se protege contra el uso comercial sin autorización previa. Para usos comerciales, es necesario contactar a los autores para obtener permiso.

Para obtener más información sobre esta licencia y ver una copia completa de sus términos, visite [Creative Commons Atribución-NoComercial (CC BY-NC)](https://creativecommons.org/licenses/by-nc/4.0/).

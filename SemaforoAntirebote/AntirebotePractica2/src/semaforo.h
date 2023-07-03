// Librerias 
#include <Arduino.h>

// Declaración del tipo de estructura de la información considerando los 3 estados a manejar en el MEF
typedef enum  {
  ESTADO_ARRANQUE,
  ESTADO_PRECAUCION,
  ESTADO_DETENCION
  }estadoMEF_t;

// Declaración del tipo de estructura para las màquinas de estado de los modos del semaforo
typedef enum {
  NORMAL,
  DESCONECTADO,
  ALARMA,
} fsmTrafficLightMode_t;

// Variables externas
extern fsmTrafficLightMode_t fsmTrafficMode;
extern int16_t baseTime;     // Tiempo de base de operación

estadoMEF_t estadoActual;

// Funcion de arranque de la maquina de estados de semaforo
void fsmTrafficLightInit(int16_t LED_GREEN, int16_t LED_YELLOW, int16_t LED_RED) {
  fsmTrafficMode = NORMAL;
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);  
}

// Funcion de presentación de semaforo al arranque
void setTrafficLightMode(fsmTrafficLightMode_t mode,int16_t LED_GREEN, int16_t LED_YELLOW, int16_t LED_RED) {
  fsmTrafficMode = mode;
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);
}

// Funcion de cambio de modos de semaforo basandose en las maquinas de estado del semaforo
void changeTrafficLightMode(int16_t LED_GREEN, int16_t LED_YELLOW, int16_t LED_RED) {
  switch (fsmTrafficMode) {
    case NORMAL:
      setTrafficLightMode(DESCONECTADO, LED_GREEN, LED_YELLOW, LED_RED);
      break;
    case DESCONECTADO:
      setTrafficLightMode(ALARMA, LED_GREEN, LED_YELLOW, LED_RED);
      break;
    case ALARMA:
      setTrafficLightMode(NORMAL, LED_GREEN, LED_YELLOW, LED_RED);
      break;
  }
}

// Funcion de arranque del MEF considerando el estado normal 
void InicializarMEF() {
  estadoActual = ESTADO_ARRANQUE;
}

/****** Function to update state of FEM traffic light in normal mode ******/
void ActualizarMEF(int16_t baseTime,int16_t LED_GREEN, int16_t LED_YELLOW, int16_t LED_RED) {
  switch (estadoActual) {
    case ESTADO_ARRANQUE:
      if (nbDelay(baseTime*4)) {              //tiempo que durará en ESTADO_ARRANQUE antes de pasar a ESTADO_PRECAUCION
        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_RED, LOW);
        estadoActual = ESTADO_PRECAUCION;
      }
      break;
    case ESTADO_PRECAUCION:
      if (nbDelay(baseTime*6)) {            //tiempo que durará en ESTADO_PRECAUCION antes de pasar a ESTADO_DETENCION
        digitalWrite(LED_GREEN, LOW);
        digitalWrite(LED_YELLOW, HIGH);
        digitalWrite(LED_RED, LOW);
        estadoActual = ESTADO_DETENCION;
      }
      break;
    case ESTADO_DETENCION:
      if (nbDelay(baseTime)) {              //tiempo que durará en ESTADO_PRECAUCION antes de pasar a ESTADO_ARRANQUE
        digitalWrite(LED_GREEN, LOW);
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_RED, HIGH);
        estadoActual = ESTADO_ARRANQUE;
      }
      break;
  }
}

// Función de actualziación del estado del MEF del semaforo
void fsmTrafficLightUpdate(int16_t LED_GREEN, int16_t LED_YELLOW, int16_t LED_RED) {
  switch (fsmTrafficMode) {
    case NORMAL:
    ActualizarMEF(baseTime, LED_GREEN, LED_YELLOW, LED_RED);
    break;
    case DESCONECTADO:
    if (nbDelay(baseTime)){
        digitalWrite(LED_YELLOW, !digitalRead(LED_YELLOW)); // Parpadear el led naranja en funcion de la base de tiempo estipulada
    }
    break;
    case ALARMA:
    if (nbDelay(baseTime)){
        digitalWrite(LED_RED, !digitalRead(LED_RED)); //Parpadear el led rojo con un tiempo en función de la base de tiempo
    }
    break;
  }
}



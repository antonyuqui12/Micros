// Librerias
#include <Arduino.h>
#include <stdio.h>


// Declarar la enumeración de la función
typedef enum {
  BUTTON_UP,
  BUTTON_DOWN,
  BUTTON_FALLING,
  BUTTON_RISING,
} fsmButtonState_t;


// Declarar la estructura de la función
typedef struct {
  int16_t tecla;
  int16_t delay;
  fsmButtonState_t estado;
} dbn_t;

// Declaración de las variables externas
extern dbn_t dbnSW1;
extern dbn_t dbnSW2;
extern int16_t baseTime;                  // Tiempo de base para el arranque

// Definición de la función de impresión de información
typedef void (*PrintFunction)(dbn_t* data);

// Definición de la función de cambio de modo de iluminación
void changeTrafficLightMode(int16_t LED_GREEN, int16_t LED_YELLOW, int16_t LED_RED);

// Función de retardo antibloqueo
int16_t nbDelay(int16_t t_delay) {
  int16_t t_base = 1;
  static int16_t count = 0;
  int16_t n_time = t_delay / t_base;

  if (count >= n_time) {
    count = 0;
    return 1;
  } else {
    delay(t_base);
    count++;
    return 0;
  }
}



// Inicion de la máquina de estados del inicio del boton 
void fsmButtonInit(dbn_t* data) {
  data->estado = BUTTON_UP;
}

// Funcion de definición de error del botón
void fsmButtonError(dbn_t* data) {
  data->estado = BUTTON_UP;
}


// Función de guardado del estado del botón
void buttonPressed(dbn_t* data, int16_t SW1, int16_t SW2,int16_t LED_GREEN, int16_t LED_YELLOW, int16_t LED_RED, PrintFunction printFunc) {
  if (data->tecla == SW1) {
    
// Cambio del tiempo base al estado normal
    baseTime = baseTime / 2;

    if (baseTime < 250) {
      baseTime = 1000;
    }
    printFunc(data);
  } else if (data->tecla == SW2) {
    
// Cambio del modo de operación del semáforo
    changeTrafficLightMode(LED_GREEN,LED_YELLOW,LED_RED);
    printFunc(data);
  }
}


//Función de actualización del estado del botón
void buttonReleased(dbn_t* data, int16_t SW1, int16_t SW2, PrintFunction printFunc) {
    printFunc(data);
}

// Ingresar actualización del estado nuevo del botón
void fsmButtonUpdate(dbn_t* data,int16_t SW1, int16_t SW2,int16_t LED_GREEN, int16_t LED_YELLOW, int16_t LED_RED, PrintFunction printFunc) {
  switch (data->estado) {
    case BUTTON_UP:
      if (!digitalRead(data->tecla)) {
        data->estado = BUTTON_FALLING; //Si el estado del Swicth cambia se manda a falling
      }
      break;
    case BUTTON_DOWN:
      if (digitalRead(data->tecla)) {
        data->estado = BUTTON_RISING; //El cambio en el Swicth manda a rising 
      }
      break;
    case BUTTON_FALLING:
      if (nbDelay(data->delay)) {
        if (!digitalRead(data->tecla)) { // Pasado el tiempo de la interrupción el estado del swicth pasa a down 
          data->estado = BUTTON_DOWN;
          buttonPressed(data, SW1,SW2,LED_GREEN,LED_YELLOW,LED_RED, printFunc);
        } else {
          data->estado = BUTTON_UP;// Pasado el tiempo de la interrupción el estado del swicth pasa a up
        }
      }
      break;

    case BUTTON_RISING:
      if (nbDelay(data->delay)) {
        if (digitalRead(data->tecla)) { 
          data->estado = BUTTON_UP;
          buttonReleased(data, SW1, SW2, printFunc);
        } else {
          data->estado = BUTTON_DOWN; 
        }
      }
      break;
    default:
      fsmButtonError(data);
      break;
  }
}


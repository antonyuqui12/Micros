// Librerias
#include "teclas.h"
#include <Arduino.h>


// Funcion correspondientes a las teclas
typedef void (*PrintFunction)(dbn_t* data);

// Máquina de estados para el botón de inicio
void fsmButtonInit(dbn_t* data);

// Máquina de estados para la actualziación de la máquina de estados
void fsmButtonUpdate(dbn_t* data,int16_t SW1, int16_t SW2,int16_t LED_GREEN, int16_t LED_YELLOW, int16_t LED_RED, PrintFunction printFunc);

// Máquina de estados para el error de las teclas
void fsmButtonError(dbn_t* data);

// Guardar los estados 
void buttonPressed(dbn_t* data ,int16_t SW1, int16_t SW2,int16_t LED_GREEN, int16_t LED_YELLOW, int16_t LED_RED, PrintFunction printFunc);

// Actualizar los estados
void buttonReleased(dbn_t* data, int16_t SW1, int16_t SW2, PrintFunction printFunc);

// Entero de 16 bits para espera
int16_t nbDelay(int16_t t_delay);

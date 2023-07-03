#include "semaforo.h"

// Funciones correspondientes a semaforo.h 
int16_t nbDelay(int16_t t_delay);

// Máquina destado de inicio del semaforo con la actualziación de estado del modo de operación
void fsmTrafficLightInit(int16_t LED_GREEN, int16_t LED_YELLOW, int16_t LED_RED);
void setTrafficLightMode(fsmTrafficLightMode_t mode,int16_t LED_GREEN, int16_t LED_YELLOW, int16_t LED_RED);

// Máquina de estados de actualziación de semaforo con actualización del modo de operación
void fsmTrafficLightUpdate(int16_t LED_GREEN, int16_t LED_YELLOW, int16_t LED_RED);
void changeTrafficLightMode(int16_t LED_GREEN, int16_t LED_YELLOW, int16_t LED_RED);

//Actualziación del MEF
void ActualizarMEF(int16_t baseTime,int16_t LED_GREEN, int16_t LED_YELLOW, int16_t LED_RED);
void InicializarMEF();


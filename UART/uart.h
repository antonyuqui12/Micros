#ifndef UART_H
#define UART_H

#include <stdint.h>
#include "teclas.h"  // Incluir el archivo teclas.h para acceder a las definiciones de la MEF antirrebote

// Función de inicialización de UART
void uart_init(void);

// Función para enviar un mensaje por UART
void uart_sendMessage(const char *message);

// Función para enviar el estado actual de la MEF antirrebote por UART
void uart_sendAntirreboteState(TeclaState state);

// Función para enviar el modo de funcionamiento actual del controlador de semáforos por UART
void uart_sendSemaforoMode(uint8_t mode);

#endif

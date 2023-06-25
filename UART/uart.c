#include "uart.h"

// Función de inicialización de UART
void uart_init(void) {
  // Configurar y habilitar la comunicación UART
  // ...
}

// Función para enviar un mensaje por UART
void uart_sendMessage(const char *message) {
  // Enviar el mensaje por UART
  // ...
}

// Función para enviar el estado actual de la MEF antirrebote por UART
void uart_sendAntirreboteState(TeclaState state) {
  const char *tecla;
  switch (state) {
    case UP:
      tecla = "Tecla liberada";
      break;
    case BOUNCING:
      tecla = "Antirrebote en progreso";
      break;
    case DOWN:
      tecla = "Tecla presionada";
      break;
  }
  // Construir el mensaje con el estado de la MEF antirrebote
  char message[50];
  snprintf(message, sizeof(message), "MEF Antirrebote: %s", tecla);
  // Enviar el mensaje por UART
  uart_sendMessage(message);
}

// Función para enviar el modo de funcionamiento actual del controlador de semáforos por UART
void uart_sendSemaforoMode(uint8_t mode) {
  // Construir el mensaje con el modo de funcionamiento del controlador de semáforos
  char message[50];
  snprintf(message, sizeof(message), "Modo de funcionamiento: %u", mode);
  // Enviar el mensaje por UART
  uart_sendMessage(message);
}

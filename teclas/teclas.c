#include "teclas.h"

// Variables internas del módulo
static ButtonState buttonState[2]; // Estados de las dos teclas
static int16_t buttonHistory[2] = {0}; // Historial de estados de las dos teclas

// Inicializa la MEF de las teclas
void initButtons(void) {
  // Inicializar los estados de las teclas
  buttonState[0] = BUTTON_UP;
  buttonState[1] = BUTTON_UP;
}

// Actualiza el estado de la MEF de las teclas
void updateButtons(void) {
  // Actualizar el estado de la primera tecla
  switch (buttonState[0]) {
    case BUTTON_UP:
      if (buttonHistory[0] == 0) {
        buttonState[0] = BUTTON_UP;
      } else if (buttonHistory[0] == 1) {
        buttonState[0] = BUTTON_DEBOUNCING;
      }
      break;
      
    case BUTTON_DOWN:
      if (buttonHistory[0] == 0) {
        buttonState[0] = BUTTON_RELEASED;
      } else if (buttonHistory[0] == 1) {
        buttonState[0] = BUTTON_DOWN;
      }
      break;
      
    case BUTTON_DEBOUNCING:
      if (buttonHistory[0] == 0) {
        buttonState[0] = BUTTON_RELEASED;
      } else if (buttonHistory[0] == 1) {
        buttonState[0] = BUTTON_PRESSED;
      }
      break;
      
    case BUTTON_PRESSED:
      if (buttonHistory[0] == 0) {
        buttonState[0] = BUTTON_RELEASED;
      } else if (buttonHistory[0] == 1) {
        buttonState[0] = BUTTON_PRESSED;
      }
      break;
      
    case BUTTON_RELEASED:
      if (buttonHistory[0] == 0) {
        buttonState[0] = BUTTON_UP;
      } else if (buttonHistory[0] == 1) {
        buttonState[0] = BUTTON_DEBOUNCING;
      }
      break;
  }
  
  // Actualizar el estado de la segunda tecla
  switch (buttonState[1]) {
    case BUTTON_UP:
      if (buttonHistory[1] == 0) {
        buttonState[1] = BUTTON_UP;
      } else if (buttonHistory[1] == 1) {
        buttonState[1] = BUTTON_DEBOUNCING;
      }
      break;
      
    case BUTTON_DOWN:
      if (buttonHistory[1] == 0) {
        buttonState[1] =

// ------------------------------------------------------------------------------------------------

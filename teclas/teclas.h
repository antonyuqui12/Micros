#ifndef TECLAS_H
#define TECLAS_H

#include <stdint.h>

// Definición de los estados posibles de la MEF
typedef enum {
  BUTTON_UP,
  BUTTON_DOWN,
  BUTTON_DEBOUNCING,
  BUTTON_PRESSED,
  BUTTON_RELEASED
} ButtonState;

// Inicializa la MEF de las teclas
void initButtons(void);

// Actualiza el estado de la MEF de las teclas
void updateButtons(void);

// Acciones correspondientes al flanco descendente
void buttonPressed(int16_t tecla);

// Acciones correspondientes al flanco ascendente
void buttonReleased(int16_t tecla);

#endif

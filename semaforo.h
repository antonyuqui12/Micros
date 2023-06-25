#ifndef SEMAFORO_H
#define SEMAFORO_H

// Enumeración de los posibles estados del semáforo
typedef enum {
    NORMAL,
    DESCONECTADO,
    ALARMA
} EstadoSemaforo;

// Inicializar la MEF del semáforo
void inicializarSemaforo();

// Actualizar el estado de la MEF del semáforo
void actualizarSemaforo();

// Cambiar la base de tiempo de la condición de operación normal
void cambiarBaseTiempo(float factor);

// Cambiar el modo de operación del semáforo
void cambiarModoOperacion();

#endif

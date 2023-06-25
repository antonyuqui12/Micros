#include "semaforo.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

// Definición de los pines o LEDs del semáforo
#define LED_VERDE    1
#define LED_AMARILLO 2
#define LED_ROJO     3

// Variables globales
EstadoSemaforo estado;
float baseTiempo;
float baseTiempoNormal;
int contadorModo;

// Función para encender un LED
void encenderLed(int led) {
    printf("Encender LED: %d\n", led);
    // Lógica para encender el LED
}

// Función para apagar un LED
void apagarLed(int led) {
    printf("Apagar LED: %d\n", led);
    // Lógica para apagar el LED
}

// Función para realizar un retardo en milisegundos
void retardo(int milisegundos) {
    usleep(milisegundos * 1000);
}

// Función de inicialización de la MEF del semáforo
void inicializarSemaforo() {
    estado = NORMAL;
    baseTiempo = 1.0;
    baseTiempoNormal = 3.0;
    contadorModo = 0;

    // Lógica de inicialización del semáforo
}

// Función de actualización del estado de la MEF del semáforo
void actualizarSemaforo() {
    switch (estado) {
        case NORMAL:
            encenderLed(LED_VERDE);
            retardo((int)(baseTiempoNormal * baseTiempo * 1000));

            encenderLed(LED_AMARILLO);
            retardo((int)(0.5 * baseTiempo * 1000));

            apagarLed(LED_VERDE);
            apagarLed(LED_AMARILLO);
            encenderLed(LED_ROJO);
            retardo((int)(2.0 * baseTiempo * 1000));
            apagarLed(LED_ROJO);
            break;
        case DESCONECTADO:
            apagarLed(LED_VERDE);
            apagarLed(LED_AMARILLO);
            encenderLed(LED_ROJO);
            retardo(500);
            apagarLed(LED_ROJO);
            retardo(500);
            break;
        case ALARMA:
            apagarLed(LED_VERDE);
            apagarLed(LED_AMARILLO);
            encenderLed(LED_ROJO);
            retardo(1000);
            apagarLed(LED_ROJO);
            retardo(1000);
            break;
    }
}

// Función para

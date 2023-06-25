#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// Definición de la estructura para cada tecla
typedef struct {
    char nombre;
    unsigned int delay;
    bool estado;
    clock_t tiempoUltimoEvento;
} Tecla;

// Función de actualización de la MEF
void actualizarMEF(Tecla *tecla) {
    clock_t tiempoActual = clock();
    unsigned int tiempoTranscurrido = (unsigned int)(tiempoActual - tecla->tiempoUltimoEvento) / CLOCKS_PER_SEC;

    switch (tecla->estado) {
        case false:
            if (tiempoTranscurrido >= tecla->delay) {
                if (tecla->nombre == 'A')
                    printf("La tecla A ha sido presionada\n");
                else if (tecla->nombre == 'B')
                    printf("La tecla B ha sido presionada\n");

                tecla->estado = true;
                tecla->tiempoUltimoEvento = tiempoActual;
            }
            break;
        case true:
            if (tiempoTranscurrido >= tecla->delay) {
                if (tecla->nombre == 'A')
                    printf("La tecla A ha sido liberada\n");
                else if (tecla->nombre == 'B')
                    printf("La tecla B ha sido liberada\n");

                tecla->estado = false;
                tecla->tiempoUltimoEvento = tiempoActual;
            }
            break;
    }
}

int main() {
    // Crear las estructuras para las dos teclas
    Tecla teclaA = {'A', 2, false, clock()};
    Tecla teclaB = {'B', 3, false, clock()};

    // Ejecutar la actualización de la MEF en un bucle infinito
    while (true) {
        // Actualizar la MEF para la tecla A
        actualizarMEF(&teclaA);

        // Actualizar la MEF para la tecla B
        actualizarMEF(&teclaB);

        // Simular un retardo para evitar un bucle infinito
        // y permitir que la MEF se actualice correctamente
        // en función de los tiempos de delay establecidos
        // Puedes ajustar el valor del retardo según tus necesidades
        clock_t retardo = 100000;
        clock_t tiempoInicio = clock();
        while ((clock() - tiempoInicio) < retardo) {}
    }

    return 0;
}

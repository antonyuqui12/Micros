// Librerias a usar
// Archivos asociados al inicio del archivo 
// Considerarse los archivos requeridos teclas, semaforo, uart
// Libreria arduino.h correspondiente a la comunicación existente entre 
// Para la respectiva programación de arduino con vscode.

#include "teclas.h"
#include "semaforo.h"
#include <Arduino.h>
#include <stdio.h>
#include "uart.h"

// Decalaracion de constantes 

const int16_t LED_GREEN = 10;   //LED_GREEN entero de 16 bits
const int16_t LED_YELLOW = 9;  //LED_YELLOW entero de 16 bits
const int16_t LED_RED = 8;     //LED_RED entero de 16 bits
const int16_t SW1 = 2;          //Switch de cambio de velocidad de operación -- Pines 2 y 3 son de PWM
const int16_t SW2 = 3;          //Switch del cambio de estado de semaforo -- Pines 2 y 3 son de PWM


// Condiciones de arranque
fsmTrafficLightMode_t fsmTrafficMode = NORMAL_MODE;    // Modo de operación inicial del semaforo
int16_t baseTime = 500;                                // Tiempo base arranque
dbn_t dbnSW1 = {SW1, 30, BUTTON_UP};
dbn_t dbnSW2 = {SW2, 30, BUTTON_UP};

// Consideraciones de operación del puertos de entrada y de salida
// No escribas las funcionalidades principales aquí, sólo el código de inicialización. 

void setup() {
  pinMode(SW1, INPUT);            //Switchs como variables de ingreso
  pinMode(SW2, INPUT);
  pinMode(LED_YELLOW, OUTPUT);    //Leds como salidas del programa 
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  Serial.begin(9600);             // Velocidad de transferencia a 9600 baudios
}


//La función de bucle o «Void Loop» es la función principal, el punto de entrada a nuestro programa. 
//Es el lugar donde tenemos que poner los comandos que se ejecutarán mientras la placa Arduino esté habilitada. 

void loop() {
  InicializarMEF();         //Iniciar el MEF para modos de semaforo 
  fsmButtonInit(&dbnSW1);   //Inicializar MEF para modo 1 -- Considerando el uso de máquinas de estado (fsm)
  fsmButtonInit(&dbnSW2);   //Inicializar MEF para modo 2 -- Considerando el uso de máquinas de estado (fsm)
  fsmTrafficLightInit(LED_GREEN, LED_YELLOW, LED_RED);    
  while (1) {
    fsmButtonUpdate(&dbnSW1,SW1,SW2,LED_GREEN, LED_YELLOW, LED_RED, myPrint);   //MEF para actualizar el modo 1
    fsmButtonUpdate(&dbnSW2,SW1,SW2,LED_GREEN, LED_YELLOW, LED_RED, myPrint);   //MeF para actualizar el modo 2
    fsmTrafficLightUpdate(LED_GREEN, LED_YELLOW, LED_RED);                      //MEF para actualizar el semaforo
  }
}

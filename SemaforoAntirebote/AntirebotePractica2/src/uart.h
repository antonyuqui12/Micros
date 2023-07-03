// Librerias
#include "Arduino.h"

// Funcion de impresión de estado
void myPrint(dbn_t* data){
  if (data->estado == 1){
    Serial.print("Tecla: ");
    Serial.print(data->tecla-1);    //Impresión del estado correspondiente de la clave
    Serial.print("\t Estado: Presionado\n");
  } else if (data->estado == 0){
    Serial.print("Tecla: ");
    Serial.print(data->tecla-1);    //Impresión del estado correspondiente de la clave
    Serial.print("\t Estado: Liberado\n");
  }
  
}


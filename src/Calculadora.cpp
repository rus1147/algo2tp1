#include "Calculadora.h"

using namespace::std;

Calculadora::Calculadora(Programa programa){
    _programa; //@rus:creo que esta mal, porque esta pasando el programa, pero constuye la calculadora?
}


void Calculadora::asignarVariable(Id idVariable, int valor){
    //lo hice pensando que la variable podría ya existir
    Variables v = Variables();
    v._idVariable = idVariable;
    v._valor = valor;
    int i = 0;
    while (i < memoria.size()){
        if (memoria[i]._idVariable == idVariable){
            memoria[i]._valor = valor;
            break;
        }
        i++;
    }
    memoria.push_back(v);
}

/* dejo la idea porque me tira errores con _programa
 *
void Calculadora::ejecutar(Id idRutina){
    if(_programa.esRutinaExistente(idRutina)){
        int i = 0;
        while(i < _programa.size()){
            if(_programa[i]._idRutina == idRutina){
                for(int j = 0; j < _programa[i]._instrucciones.size(); j++){
                    _programa[i]._instrucciones[j];
                }
            }
            i++;
        }
    } else {
        //cómo termina una ejecución?
    }
} */

int Calculadora::valorVariable(Id idVariable) const {
    for (int i = 0; i < memoria.size(); i++) {
        if (memoria[i]._idVariable == idVariable) {
            return memoria[i]._valor;
        }
    }
    return 0;
}
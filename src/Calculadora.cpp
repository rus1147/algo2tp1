#include "Calculadora.h"

using namespace::std;

Calculadora::Calculadora(Programa programa) : _programa(programa) {};


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

void Calculadora::ejecutar(Id idRutina){
    if(_programa.esRutinaExistente(idRutina)){
        int i = 0;
        while(i < _programa.longitud(idRutina)){
            Instruccion h = _programa.instruccion(idRutina, i);
            Id v = h.nombre();
            if (h.operacion() == 1){
                PUSH(h.valor());
            } else if (h.operacion() == 2){
                ADD();
            } else if (h.operacion() == 3){
                SUB();
            } else if(h.operacion() == 4){
                MUL();
            } else if (h.operacion() == 5){
                WRITE(v);
            } else if (h.operacion() == 6){
                READ(v);
            } else if (h.operacion() == 7){
                //aumento el índice: si la rutina no existe, sale del ciclo y termina la ejecución
                i = _programa.longitud(idRutina)+1;
                JUMP(v);
            } else if (h.operacion() == 8){
                int pilaTop = pila[pila.size()];
                if(_programa.esRutinaExistente(idRutina)){
                    if(pilaTop == 0 or pila.empty()){
                        JUMP(v);
                    }
                } else {
                    i = _programa.longitud(idRutina)+1;
                }
            }
            i++;
        }
    }
}


int Calculadora::valorVariable(Id idVariable) const {
    for (int i = 0; i < memoria.size(); i++) {
        if (memoria[i]._idVariable == idVariable) {
            return memoria[i]._valor;
        }
    }
    return 0;
}
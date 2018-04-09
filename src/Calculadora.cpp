#include "Calculadora.h"

using namespace::std;

Calculadora::Calculadora(Programa programa): _programa(programa){};

void Calculadora::asignarVariable(Id idVariable, int valor){
    //lo hice pensando que la variable podría ya existir
    Variables v = Variables();
    v._idVariable = idVariable;
    v._valor = valor;
    int i = 0;
    while (i < _memoria.size()){
        if (_memoria[i]._idVariable == idVariable){
            _memoria[i]._valor = valor;
            break;
        }
        i++;
    }
    _memoria.push_back(v);
}

void Calculadora::ejecutar(Id idRutina){}

int Calculadora::valorVariable(Id idVariable) const {
    for (int i = 0; i < _memoria.size(); i++) {
        if (_memoria[i]._idVariable == idVariable) {
            return _memoria[i]._valor;
        }
    }
    return 0;
}
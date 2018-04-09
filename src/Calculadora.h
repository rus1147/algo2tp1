#ifndef __CALCULADORA_H__
#define __CALCULADORA_H__

#include "Programa.h"


class Calculadora {
public:
    Calculadora(Programa programa);

    void asignarVariable(Id idVariable, int valor);

    void ejecutar(Id idRutina);

    int valorVariable(Id idVariable) const;

private:
    struct Variables{
        Id _idVariable;
        int _valor;
    };
    vector<Variables> _memoria;

    Programa _programa;

};


#endif //__CALCULADORA_H__

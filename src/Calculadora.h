#ifndef __CALCULADORA_H__
#define __CALCULADORA_H__

#include "Programa.h"
#include <stack>


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

    stack<int> pila;

    Programa _programa;


    //las operaciones van acá??
    void push(int n){
        pila.push(n);
    }

    void add(){
        if (pila.empty()){
            pila.push(0);
        } else if (pila.size() > 1){
            int n = pila.top();
            pila.pop();
            int m = pila.top();
            pila.pop();
            pila.push(n+m);
        }
    }

    void sub(){
        if (pila.empty()){
            pila.push(0);
        } else if (pila.size() > 1){
            int n = pila.top();
            pila.pop();
            int m = pila.top();
            pila.pop();
            pila.push(abs(n-m));
        }
    }

    void mul(){
        if (pila.empty()){
            pila.push(0);
        } else if (pila.size() > 1){  //no sé bien qué pasa si sólo hay un elemento
            int n = pila.top();
            pila.pop();
            int m = pila.top();
            pila.pop();
            pila.push(n*m);
        }
    }

};




#endif //__CALCULADORA_H__

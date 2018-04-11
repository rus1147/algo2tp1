#ifndef __CALCULADORA_H__
#define __CALCULADORA_H__

#include <iostream>
#include <vector>
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

    Programa _programa; //@rus:creo que no va porque lo sacamos de la clase programa.


    //las operaciones van acá??
    //@rus: Las que implementemos(que no fueron soliciadas), osea, las aux.
    //@rus: segun el enunciado van en la parte privada. Asi que si.
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

    void write(Id idVariable){

        for(int i = 0; i < _memoria.size(); i++){
            if(_memoria[i]._idVariable == idVariable){
                if(pila.empty()){
                    _memoria[i]._valor = 0;
                    break;
                } else {
                    _memoria[i]._valor = pila.top();
                    pila.pop();
                    break;
                }
            }
        }
    }

    void READ(Id idVariable){
        for(int i = 0; i < _memoria.size(); i++){
            if(_memoria[i]._idVariable == idVariable){
                pila.push(_memoria[i]._valor);
                break;
            }
        }
        pila.push(0);
    }

};




#endif /*__CALCULADORA_H__*/

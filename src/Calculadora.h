#ifndef __CALCULADORA_H__
#define __CALCULADORA_H__

#include <iostream>
#include <vector>
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
    vector<Variables> memoria;

    vector<int> pila;

    Programa _programa; //@rus:creo que no va porque lo sacamos de la clase programa.


    //las operaciones van acá??
    //@rus: Las que implementemos(que no fueron soliciadas), osea, las aux.
    //@rus: segun el enunciado van en la parte privada. Asi que si.
    void push(int n){
        pila.push_back(n);
    }

    void ADD(){
        int topPila = pila[pila.size()];
        if (pila.empty()){
            pila.push_back(0);
        } else if (pila.size() > 1){
            int n = topPila;
            pila.pop_back();
            int m = topPila;
            pila.pop_back();
            pila.push_back(n+m);
        }
    }

    void SUB(){
        int topPila = pila[pila.size()];
        if (pila.empty()){
            pila.push_back(0);
        } else if (pila.size() > 1){
            int n = topPila;
            pila.pop_back();
            int m = topPila;
            pila.pop_back();
            pila.push_back(abs(n-m));
        }
    }

    void MUL(){
        int topPila = pila[pila.size()];
        if (pila.empty()){
            pila.push_back(0);
        } else if (pila.size() > 1){  //no sé bien qué pasa si sólo hay un elemento
            int n = topPila;
            pila.pop_back();
            int m = topPila;
            pila.pop_back();
            pila.push_back(n*m);
        }
    }

    void WRITE(Id idVariable){

        for(int i = 0; i < memoria.size(); i++){
            if(memoria[i]._idVariable == idVariable){
                if(pila.empty()){
                    memoria[i]._valor = 0;
                    break;
                } else {
                    memoria[i]._valor = pila[pila.size()];;
                    pila.pop_back();
                    break;
                }
            }
        }
    }

    void READ(Id idVariable){
        for(int i = 0; i < memoria.size(); i++){
            if(memoria[i]._idVariable == idVariable){
                pila.push_back(memoria[i]._valor);
                break;
            }
        }
        pila.push_back(0);
    }

    void JUMP(Id idRutina){
        if(_programa.esRutinaExistente(idRutina)){
            ejecutar(idRutina);
        } else {
            //??
        }
    }

    void JUMPZ(Id idRutina){
        int pilaTop = pila[pila.size()];
        if(_programa.esRutinaExistente(idRutina)){
            if (pilaTop == 0 or pila.empty()){
                ejecutar(idRutina);
            }
        } else {
            //??
        }
    }

};




#endif /*__CALCULADORA_H__*/

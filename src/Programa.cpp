#include "Programa.h"

using namespace::std;

Programa::Programa(){
    _programa;
}

void Programa::agregarInstruccion(Id idRutina, Instruccion instruccion) {
    Asocacion p= Asocacion();
    p._idRutina=idRutina;
    p._instruciones.push_back(instruccion);
    int i=0;
    if(_programa.size()==0){
        _programa.push_back(p);
    }else {
        while(i<_programa.size()){
            if(_programa[i]._idRutina==idRutina){
                _programa[i]._instruciones.push_back(instruccion);
                break;
            }
            i++;
        }if(_programa.size()==i) {
            _programa.push_back(p);
        }
    }
    
}

bool Programa::esRutinaExistente(Id idRutina) const{
    int i=0;
    while(i<_programa.size()){
        if(_programa[i]._idRutina==idRutina){
            return true;
        }
        i++;
    }
    return false;
}


int Programa::longitud(Id idRutina) const{
    int i=0;
    if(esRutinaExistente(idRutina)){
        while(i<_programa.size()){
            if(_programa[i]._idRutina==idRutina){
                return (int)_programa[i]._instruciones.size();
            }
            i++;
         }
    }else{
        return 0;
    }
}

Instruccion Programa::instruccion(Id idRutina, int i) const{
    if(esRutinaExistente(idRutina) && 0<=i && i<longitud(idRutina)){
        int j=0;
        while(j<_programa.size()){
            if(_programa[j]._idRutina==idRutina){
                return _programa[j]._instruciones[i];
            }
            j++;
        }
    }
}
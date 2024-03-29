#ifndef __PROGRAMA_H__
#define __PROGRAMA_H__

#include <iostream>
#include <vector>
#include <string>

#include "Instruccion.h"

using namespace::std;

// La clase Programa sirve para representar una secuencia de instrucciones.
//
//     Programa programa;
//
//     programa.agregarInstruccion("A", Instruccion(OP_PUSH, 10));
//     programa.agregarInstruccion("A", Instruccion(OP_PUSH, 20));
//     programa.agregarInstruccion("A", Instruccion(OP_ADD));
//     programa.agregarInstruccion("A", Instruccion(OP_JUMP, "A"));
//
//     programa.agregarInstruccion("B", Instruccion(OP_PUSH, 30));
//     programa.agregarInstruccion("B", Instruccion(OP_WRITE, "x"));
//
// Corresponde a las siguientes rutinas:
//
//     --- A ---
//       push(10)
//       push(20)
//       add
//       jump(A)
//
//     --- B ---
//       push(30)
//       write(x)

class Programa {
public:
	// Inicialmente no hay ninguna rutina.
	Programa();

	// Agrega una instrucción a la rutina indicada.
	// Si la rutina indicada no existe, crea una nueva rutina
	// con dicho nombre.
	void agregarInstruccion(Id idRutina, Instruccion instruccion);

	// Devuelve True si idRutina representa una rutina existente.
	bool esRutinaExistente(Id idRutina) const;

	// Devuelve la longitud (cantidad de instrucciones) de la rutina
	// indicada.
	//
	// Precondición: esRutinaExistente(idRutina)
	int longitud(Id idRutina) const;

	// Devuelve la i-ésima instrucción de la rutina indicada.
	//
	// Precondición:
	//   esRutinaExistente(idRutina) && 0 <= i && i < longitud(idRutina)
	Instruccion instruccion(Id idRutina, int i) const;
private:
	struct Rutinas{
		Id _idRutina;
		vector<Instruccion> _instrucciones;
	};
	vector<Rutinas> _programa;
};

#endif /*__PROGRAMA_H__*/


#include "gtest/gtest.h"
#include "../src/Instruccion.h"
#include "../src/Calculadora.h"

TEST(test_calculadora, ejemploDePrueba) {
    Programa p;
    p.agregarInstruccion("MAIN", Instruccion(READ, "x"));
    p.agregarInstruccion("MAIN", Instruccion(PUSH, 2));
    p.agregarInstruccion("MAIN", Instruccion(ADD));
    p.agregarInstruccion("MAIN", Instruccion(WRITE, "x"));
    Calculadora c(p);
    c.asignarVariable("x", 38);
    c.ejecutar("MAIN");
    EXPECT_EQ(c.valorVariable("x"),40);
    c.ejecutar("MAIN");
    EXPECT_EQ(c.valorVariable("x"),42);
}
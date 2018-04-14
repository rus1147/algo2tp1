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

TEST(test_calculadora, mulSub) {
    Programa p;
    p.agregarInstruccion("A", Instruccion(PUSH, 5));
    p.agregarInstruccion("A", Instruccion(MUL));
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));
    p.agregarInstruccion("A", Instruccion(READ, "x"));
    Calculadora c(p);
    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 5);
    p.agregarInstruccion("A", Instruccion(PUSH, 2));
    p.agregarInstruccion("A", Instruccion(MUL));
    p.agregarInstruccion("A", Instruccion(PUSH, 3));
    p.agregarInstruccion("A", Instruccion(SUB));
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));
    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 7);
}

TEST(test_calculadora, dosRutinas) {
    Programa p;
    p.agregarInstruccion("A", Instruccion(PUSH, 2));
    p.agregarInstruccion("A", Instruccion(PUSH, 8));
    p.agregarInstruccion("A", Instruccion(ADD));
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));
    p.agregarInstruccion("A", Instruccion(JUMP, "B"));
    p.agregarInstruccion("B", Instruccion(SUB));
    Calculadora c(p);
    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 10);
}

TEST(test_calculadora, jumpRutinaNoExistente){
    Programa p;
    p.agregarInstruccion("R", Instruccion(READ, "y"));
    p.agregarInstruccion("R", Instruccion(PUSH, 7));
    p.agregarInstruccion("R", Instruccion(SUB));
    p.agregarInstruccion("R", Instruccion(JUMP, "N"));
    Calculadora c(p);
    c.asignarVariable("y", 11);
    EXPECT_EQ(c.valorVariable("y"), 4);
}
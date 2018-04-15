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
    p.agregarInstruccion("A", Instruccion(PUSH, 2));
    p.agregarInstruccion("A", Instruccion(SUB));
    p.agregarInstruccion("A", Instruccion(WRITE, "y"));
    Calculadora c(p);
    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 5);
    EXPECT_EQ(c.valorVariable("y"), 3);
}

TEST(test_calculadora, dosRutinas) {
    Programa p;
    p.agregarInstruccion("A", Instruccion(PUSH, 2));
    p.agregarInstruccion("A", Instruccion(PUSH, 8));
    p.agregarInstruccion("A", Instruccion(ADD));
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));
    p.agregarInstruccion("A", Instruccion(READ, "x"));
    p.agregarInstruccion("A", Instruccion(JUMP, "B"));
    p.agregarInstruccion("B", Instruccion(PUSH, 2));
    p.agregarInstruccion("B", Instruccion(SUB));
    p.agregarInstruccion("B", Instruccion(WRITE, "x"));
    Calculadora c(p);
    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 8);
}

TEST(test_calculadora, jumpRutinaNoExistente){
    Programa p;
    p.agregarInstruccion("R", Instruccion(READ, "y"));
    p.agregarInstruccion("R", Instruccion(PUSH, 7));
    p.agregarInstruccion("R", Instruccion(SUB));
    p.agregarInstruccion("R", Instruccion(WRITE, "y"));
    p.agregarInstruccion("R", Instruccion(JUMP, "N"));
    p.agregarInstruccion("R", Instruccion(PUSH, 5));
    p.agregarInstruccion("R", Instruccion(MUL));
    p.agregarInstruccion("R", Instruccion(WRITE, "y"));
    Calculadora c(p);
    c.asignarVariable("y", 11);
    c.ejecutar("R");
    EXPECT_EQ(c.valorVariable("y"), 4);
}

TEST(test_calculadora, jumpz){
    Programa p;
    p.agregarInstruccion("A", Instruccion(READ, "x"));
    p.agregarInstruccion("A", Instruccion(PUSH, 2));
    p.agregarInstruccion("A", Instruccion(MUL));
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));
    p.agregarInstruccion("A", Instruccion(JUMPZ, "B"));
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));
    p.agregarInstruccion("B", Instruccion(READ, "x"));
    p.agregarInstruccion("B", Instruccion(PUSH, 2));
    p.agregarInstruccion("B", Instruccion(ADD));
    p.agregarInstruccion("B", Instruccion(WRITE, "x"));
    Calculadora c(p);
    c.asignarVariable("x", 5);
    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 12);
    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 26);
}

TEST(test_calculadora, readYJumpz) {
    Programa p;
    p.agregarInstruccion("A", Instruccion(PUSH, 10));
    p.agregarInstruccion("A", Instruccion(READ, "x"));
    p.agregarInstruccion("A", Instruccion(PUSH, 20));
    p.agregarInstruccion("A", Instruccion(ADD));
    p.agregarInstruccion("A", Instruccion(WRITE, "y"));
    p.agregarInstruccion("A", Instruccion(READ, "y"));
    p.agregarInstruccion("A", Instruccion(PUSH, 2));
    p.agregarInstruccion("A", Instruccion(MUL));
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));
    p.agregarInstruccion("A", Instruccion(JUMPZ, "B"));
    p.agregarInstruccion("B", Instruccion(WRITE, "y"));
    p.agregarInstruccion("A", Instruccion(PUSH, 2));
    p.agregarInstruccion("A", Instruccion(ADD));
    p.agregarInstruccion("A", Instruccion(WRITE, "y"));
    Calculadora c(p);
    c.asignarVariable("x", 30);
    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 100);
    EXPECT_EQ(c.valorVariable("y"), 12);
}

TEST(test_calculadora, saltoHastaJumpz) {
    Programa p;
    p.agregarInstruccion("A", Instruccion(READ, "x"));
    p.agregarInstruccion("A", Instruccion(PUSH, 1));
    p.agregarInstruccion("A", Instruccion(SUB));
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));
    p.agregarInstruccion("A", Instruccion(READ, "x"));
    p.agregarInstruccion("A", Instruccion(JUMPZ, "FIN"));
    p.agregarInstruccion("A", Instruccion(JUMP, "A"));
    Calculadora c(p);
    c.asignarVariable("x", 2);
    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 1);
    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 0);
}
TEST(test_calculadora, saltoHastaJumpzNIgualA0) {
    Programa p;
    p.agregarInstruccion("A", Instruccion(READ, "x"));
    p.agregarInstruccion("A", Instruccion(PUSH, 1));
    p.agregarInstruccion("A", Instruccion(SUB));
    p.agregarInstruccion("A", Instruccion(WRITE, "x"));
    p.agregarInstruccion("A", Instruccion(READ, "x"));
    p.agregarInstruccion("A", Instruccion(JUMPZ, "FIN"));
    p.agregarInstruccion("A", Instruccion(JUMP, "A"));
    Calculadora c(p);
    c.asignarVariable("x", 0);
    c.ejecutar("A");
    c.ejecutar("A"); //
    EXPECT_EQ(c.valorVariable("x"), -2);
}
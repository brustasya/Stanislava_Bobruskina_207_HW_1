//------------------------------------------------------------------------------
// parallelepiped.cpp - содержит функции обработки параллелепипеда
//------------------------------------------------------------------------------

#include "parallelepiped.h"
#include <iostream>

//------------------------------------------------------------------------------
// Ввод параметров параллелепипеда из потока
void In(parallelepiped& p, ifstream& ifst) {
    ifst >> p.a >> p.b >> p.c >> p.density;
}

// Случайный ввод параметров параллелепипеда
void InRnd(parallelepiped& p) {
    p.a = Random();
    p.b = Random();
    p.c = Random();
    p.density = DoubleRandom();
}

//------------------------------------------------------------------------------
// Вывод параметров параллелепипеда в поток
void Out(parallelepiped& p, FILE* outputFile) {
    fprintf(outputFile, "It is Parallelepiped: a = %d. b = %d. c = %d. Volume = %f. Density = %f.\n",
            p.a, p.b, p.c, Volume(p), p.density);
    std::cout << "It is Parallelepiped: a = "
              << p.a << ", b = " << p.b
              << ", c = " << p.c
              << ". Volume = " << Volume(p) << ". Density = " << p.density << "\n";
}

//------------------------------------------------------------------------------
// Вычисление объёма параллелепипеда
double Volume(parallelepiped& p) {
    return double(p.a * p.b * p.c);
}

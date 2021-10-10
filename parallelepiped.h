#ifndef __parallelepiped__
#define __parallelepiped__

//------------------------------------------------------------------------------
// parallelepiped.h - содержит описание параллелепипеда и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "rnd.h"

// Параллелепипед
struct parallelepiped {
    int a, b, c; // три целочисленных ребра
    double density; // плотность материала фигуры
};

// Ввод параметров параллелепипеда из файла
void In(parallelepiped& p, ifstream& ifst);

// Случайный ввод параметров параллелепипеда
void InRnd(parallelepiped& p);

// Вывод параметров параллелепипеда в форматируемый поток
void Out(parallelepiped& p, FILE* outputFile);

// Вычисление объёма параллелепипеда
double Volume(parallelepiped& p);

#endif //__parallelepiped__

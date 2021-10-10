#ifndef __tetrahedron__
#define __tetrahedron__

//------------------------------------------------------------------------------
// tetrahedron.h - содержит описание правильного тетраэдра и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "rnd.h"

// Правильный тетраэдр
struct tetrahedron {
    int a; // длина ребра
    double density; // плотность материала фигуры
};

// Ввод параметров тетраэдра из файла
void In(tetrahedron& r, ifstream& ifst);

// Случайный ввод параметров тетраэдра
void InRnd(tetrahedron& r);

// Вывод параметров тетраэдра в форматируемый поток
void Out(tetrahedron& r, FILE* outputFile);

// Вычисление объёма тетраэдра
double Volume(tetrahedron& r);

#endif //__tetrahedron__


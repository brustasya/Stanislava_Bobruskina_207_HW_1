//------------------------------------------------------------------------------
// tetrahedron.cpp - содержит функции обработки тетраэдра
//------------------------------------------------------------------------------

#include "tetrahedron.h"
#include <iostream>

//------------------------------------------------------------------------------
// Ввод параметров тетраэдра из потока
void In(tetrahedron& t, ifstream& ifst) {
    ifst >> t.a >> t.density;
}

// Случайный ввод параметров тетраэдра
void InRnd(tetrahedron& t) {
    t.a = Random();
    t.density = DoubleRandom();
}

//------------------------------------------------------------------------------
// Вывод параметров тетраэдра в поток
void Out(tetrahedron& t, FILE* outputFile) {
    fprintf(outputFile, "It is Tetrahedron: a = %d. Volume = %f. Density = %f.\n",
            t.a, Volume(t), t.density);
    std::cout << "It is Tetrahedron: a = "
              << t.a
              << ". Volume = " << Volume(t) << ". Density = " << t.density << "\n";
}

//------------------------------------------------------------------------------
// Вычисление объёма тетраэдра
double Volume(tetrahedron& t) {
    return double(1.0 / 6.0 * t.a);
}

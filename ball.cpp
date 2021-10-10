//------------------------------------------------------------------------------
// ball.cpp - содержит функции обработки шара
//------------------------------------------------------------------------------

#include "ball.h"
#include <iostream>

//------------------------------------------------------------------------------
// Ввод параметров шара из потока
void In(ball& b, ifstream& ifst) {
    ifst >> b.radius >> b.density;
}

// Случайный ввод параметров шара
void InRnd(ball& b) {
    b.radius = Random();
    b.density = DoubleRandom();
}

//------------------------------------------------------------------------------
// Вывод параметров шара в поток
void Out(ball& b, FILE* outputFile) {
    fprintf(outputFile, "It is Ball: ");
    fprintf(outputFile, "Radius = %d. ", b.radius);
    fprintf(outputFile, "Volume = %f. ", Volume(b));
    fprintf(outputFile, "Density = %f.\n", b.density);
    std::cout << "It is Ball: radius = " << b.radius
              << ". Volume = " << Volume(b) << ". Density = " << b.density << "\n";
}

//------------------------------------------------------------------------------
// Вычисление объёма шара
double Volume(ball& b) {
    return double(4.0 / 3.0 * 3.1415926 * b.radius * b.radius * b.radius);
}

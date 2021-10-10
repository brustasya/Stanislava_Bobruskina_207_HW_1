#ifndef __figure__
#define __figure__

//------------------------------------------------------------------------------
// figure.h - содержит описание обобщающей объёмной геометрической фигуры,
//------------------------------------------------------------------------------

#include "ball.h"
#include "parallelepiped.h"
#include "tetrahedron.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся фигуры
struct figure {
    // значения ключей для каждой из фигур
    enum key { BALL, PARALLELEPIPED, TETRAHEDRON };
    key k; // ключ

    // используемые альтернативы
    union { // используем простейшую реализацию
        ball b;
        parallelepiped p;
        tetrahedron t;
    };
};

// Ввод обобщенной фигуры
bool In(figure& s, ifstream& ifdt);

// Случайный ввод обобщенной фигуры
bool InRnd(figure& s);

// Вывод обобщенной фигуры
void Out(figure& s, FILE* outputFile);

// Вычисление периметра обобщенной фигуры
double Volume(figure& s);

#endif
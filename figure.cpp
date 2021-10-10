//------------------------------------------------------------------------------
// figure.cpp - содержит процедуры, связанные с обработкой обобщенной фигуры
// и созданием произвольной фигуры
//------------------------------------------------------------------------------

#include "figure.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
bool In(figure& f, ifstream& ifst) {
    int k;
    ifst >> k;
    switch (k) {
        case 1:
            f.k = figure::BALL;
            In(f.b, ifst);
            return true;
        case 2:
            f.k = figure::PARALLELEPIPED;
            In(f.p, ifst);
            return true;
        case 3:
            f.k = figure::TETRAHEDRON;
            In(f.t, ifst);
            return true;
        default:
            return false;
    }
}

// Случайный ввод обобщенной фигуры
bool InRnd(figure& f) {
    auto k = rand() % 3 + 1;
    switch (k) {
        case 1:
            f.k = figure::BALL;
            InRnd(f.b);
            return true;
        case 2:
            f.k = figure::PARALLELEPIPED;
            InRnd(f.p);
            return true;
        case 3:
            f.k = figure::TETRAHEDRON;
            InRnd(f.t);
            return true;
        default:
            return false;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void Out(figure& f, FILE* outputFile) {
    switch (f.k) {
        case figure::BALL:
            Out(f.b, outputFile);
            break;
        case figure::PARALLELEPIPED:
            Out(f.p, outputFile);
            break;
        case figure::TETRAHEDRON:
            Out(f.t, outputFile);
            break;
        default:
            fprintf(outputFile, "Incorrect figure!\n");
            printf("Incorrect figure!\n");
    }
}

//------------------------------------------------------------------------------
// Вычисление Объёма фигуры
double Volume(figure& f) {
    switch (f.k) {
        case figure::BALL:
            return Volume(f.b);
            break;
        case figure::PARALLELEPIPED:
            return Volume(f.p);
            break;
        case figure::TETRAHEDRON:
            return Volume(f.t);
            break;
        default:
            return 0.0;
    }
}

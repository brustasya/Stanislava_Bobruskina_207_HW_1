#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "figure.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
struct container {
    enum { max_len = 10000 }; // максимальная длина
    int len; // текущая длина
    figure cont[max_len];
};

// Инициализация контейнера
void Init(container& c);

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container& c);

// Ввод содержимого контейнера из указанного потока
void In(container& c, ifstream& ifst);

// Случайный ввод содержимого контейнера
void InRnd(container& c, int size);

// Вывод содержимого контейнера в указанный поток
void Out(container& c, FILE* outputFile);

// Слияние
void Merge(struct container *a, int first, int last);

// Сортировка слиянием по убыванию
void MergeSort(struct container *a, int first, int last);

#endif

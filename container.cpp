//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container& c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container& c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void In(container& c, ifstream& ifst) {
    while (!ifst.eof()) {
        if (In(c.cont[c.len], ifst)) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRnd(container& c, int size) {
    while (c.len < size) {
        if (InRnd(c.cont[c.len])) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Out(container& c, FILE* outputFile) {
    fprintf(outputFile, "Container contains %d elements.\n", c.len);
    printf("Container contains %d elements.\n", c.len);
    for (int i = 0; i < c.len; i++) {
        fprintf(outputFile, "%d: ", i + 1);
        printf("%d: ", i + 1);
        Out(c.cont[i], outputFile);
    }
}

// Слияние
void Merge(struct container *c, int first, int last) {
    int middle, start, final, j;
    figure mas[100];
    middle = (first + last) / 2; //вычисление среднего элемента
    start = first; //начало левой части
    final = middle + 1; //начало правой части
    for(j = first; j <= last; j++) {
        if ((start <= middle) && ((final > last) || (Volume(c->cont[start]) > Volume(c->cont[final])))) {
            mas[j] = c->cont[start];
            start++;
        } else {
            mas[j] = c->cont[final];
            final++;
        }
    }
//возвращение результата в список
    for (j = first; j <= last; j++)
        c->cont[j] = mas[j];

}

// Сортировка слиянием по убыванию
void MergeSort(struct container *c, int first, int last) {
    if (first < last)
    {
        MergeSort(c, first, (first + last) / 2); //сортировка левой части
        MergeSort(c, (first + last) / 2 + 1, last); //сортировка правой части
        Merge(c, first, last); //слияние двух частей
    }
}


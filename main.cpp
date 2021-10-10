//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <cstring>

#include "container.h"

void errMessage1() {
    cout << "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

void errMessage2() {
    cout << "incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}


//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    clock_t time_start = clock();
    if (argc != 5) {
        errMessage1();
        return 1;
    }

    cout << "Start" << endl;
    container c;
    Init(c);

    if (!strcmp(argv[1], "-f")) {
        ifstream ifst(argv[2]);
        In(c, ifst);
    }
    else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            cout << "incorrect numer of figures = "
                 << size
                 << ". Set 0 < number <= 10000\n";
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        InRnd(c, size);
    }
    else {
        errMessage2();
        return 2;
    }

    // Открытие первого файла для записи.
    FILE *outputFile1;
    if(!(outputFile1 = fopen(argv[3], "w+"))) {
        perror("Невозможно открыть файл");
        exit(EXIT_FAILURE);
    }

    // Вывод содержимого контейнера в файл
    fprintf(outputFile1, "Filled container:\n");
    printf("Filled container:\n");
    Out(c, outputFile1);
    fclose(outputFile1);

    // Открытие второго файла для записи.
    FILE *outputFile2;
    if(!(outputFile2 = fopen(argv[4], "w+"))) {
        perror("Невозможно открыть файл");
        exit(EXIT_FAILURE);
    }

    // Вывод результатов выполнения дополнительной функции и содержимого измененного контейнера в файл.
    fprintf(outputFile2, "Changed container:\n");
    printf("\nChanged container:\n");
    //merge(&c);
    MergeSort(&c, 0, c.len - 1);
    Out(c, outputFile2);
    fclose(outputFile2);

    Clear(c);
    cout << "Stop" << endl;
    printf("Seconds: %f\n", ((double)(clock() - time_start)) / CLOCKS_PER_SEC);
    return 0;
}

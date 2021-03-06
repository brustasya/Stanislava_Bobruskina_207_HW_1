#ifndef __rnd__
#define __rnd__

#include <cstdlib>

//--------------------------------------------------------------------------------------------------------------------
// rnd.h - содержит генератор случайных чисел в диапазоне от 1 до 20 и вещественных чисел в диапазоне от 1.1 до 1000.1
//--------------------------------------------------------------------------------------------------------------------

inline auto Random() {
    return rand() % 20 + 1;
}

inline auto DoubleRandom() {
    return (double)rand() / RAND_MAX * (1000.1 - 1.1) + 1.1;
}

#endif //__rnd__

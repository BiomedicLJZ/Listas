

#ifndef LISTA_LIBRERIA_H
#define LISTA_LIBRERIA_H

#define M_PI 3.14159265358979323846

#include <iostream>
#include <cmath>

long double factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

#endif//LISTA_LIBRERIA_H

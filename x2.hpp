#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>

class x2
{
public:
    void imprimirSistema2x2(float x[], float y[], float c[]);
    void metodoJacobi2x2(float x[], float y[], float c[], int Iteraciones, int decimales, float xInicial, float yInicial);
};
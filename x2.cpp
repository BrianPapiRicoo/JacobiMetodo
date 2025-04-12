#include "x2.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void x2::imprimirSistema2x2(float x[], float y[], float c[]) {
    cout << "Sistema de ecuaciones:" << endl;
    for (int i = 0; i < 2; i++) {
        cout << x[i] << "x + " << y[i] << "y = " << c[i] << endl;
    }
}

void x2::metodoJacobi2x2(float x[], float y[], float c[], int Iteraciones, int decimales, float xInicial, float yInicial) {
    float xAnt = xInicial;
    float yAnt = yInicial;
    float xNuevo, yNuevo;
    float xPrev = 0.0, yPrev = 0.0;
    bool repetido = false;
    float toleranciaFija = 1e-6;

    cout << "Despeje de las variables:" << endl;
    cout << "x = (" << c[0] << " - (" << y[0] << " * y)) / " << x[0] << endl;
    cout << "y = (" << c[1] << " - (" << x[1] << " * x)) / " << y[1] << endl;

    cout << endl << "Iteraciones:" << endl;
    for (int i = 1; i <= Iteraciones; i++) {
        xNuevo = (c[0] - (y[0] * yAnt)) / x[0];
        yNuevo = (c[1] - (x[1] * xAnt)) / y[1];

        cout << fixed << setprecision(decimales);
        cout << "Itt " << i << ": x = " << xNuevo << ", y = " << yNuevo << endl;

        
        if (repetido && abs(xNuevo - xPrev) < toleranciaFija && abs(yNuevo - yPrev) < toleranciaFija) {
            cout << "Valores repetidos en la iteracion " << i << ", terminando iteraciones." << endl;
            break;
        }

        repetido = (abs(xNuevo - xAnt) < toleranciaFija && abs(yNuevo - yAnt) < toleranciaFija);

        xPrev = xAnt;
        yPrev = yAnt;

        xAnt = xNuevo;
        yAnt = yNuevo;
    }

    cout << "Resultado final: x = " << xNuevo << ", y = " << yNuevo << endl;

  
    cout << "Regresando al menu principal..." << endl;
}
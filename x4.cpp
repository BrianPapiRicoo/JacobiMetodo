#include "x4.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void x4::imprimirSistema4x4(float w[], float x[], float y[], float z[], float c[]) {
    cout << "Sistema de ecuaciones (4x4):" << endl;
    for (int i = 0; i < 4; i++) {
        cout << w[i] << "w + " << x[i] << "x + " << y[i] << "y + " << z[i] << "z = " << c[i] << endl;
    }
}

void x4::metodoJacobi4x4(float w[], float x[], float y[], float z[], float c[], int Iteraciones, int decimales, float wInicial, float xInicial, float yInicial, float zInicial) {
    wAnt = wInicial;
    xAnt = xInicial;
    yAnt = yInicial;
    zAnt = zInicial;

    cout << "Despeje de las variables (4x4):" << endl;
    cout << "w = (" << c[0] << " - (" << x[0] << " * x) - (" << y[0] << " * y) - (" << z[0] << " * z)) / " << w[0] << endl;
    cout << "x = (" << c[1] << " - (" << w[1] << " * w) - (" << y[1] << " * y) - (" << z[1] << " * z)) / " << x[1] << endl;
    cout << "y = (" << c[2] << " - (" << w[2] << " * w) - (" << x[2] << " * x) - (" << z[2] << " * z)) / " << y[2] << endl;
    cout << "z = (" << c[3] << " - (" << w[3] << " * w) - (" << x[3] << " * x) - (" << y[3] << " * y)) / " << z[3] << endl;

    cout << "Iteraciones:" << endl;
    for (int i = 1; i <= Iteraciones; i++) {
        wNuevo = (c[0] - (x[0] * xAnt) - (y[0] * yAnt) - (z[0] * zAnt)) / w[0];
        xNuevo = (c[1] - (w[1] * wAnt) - (y[1] * yAnt) - (z[1] * zAnt)) / x[1];
        yNuevo = (c[2] - (w[2] * wAnt) - (x[2] * xAnt) - (z[2] * zAnt)) / y[2];
        zNuevo = (c[3] - (w[3] * wAnt) - (x[3] * xAnt) - (y[3] * yAnt)) / z[3];

        cout << fixed << setprecision(decimales);
        cout << "Itt " << i << ": w = " << wNuevo << ", x = " << xNuevo << ", y = " << yNuevo << ", z = " << zNuevo << endl;

        
        if (wNuevo == wPrev && xNuevo == xPrev && yNuevo == yPrev && zNuevo == zPrev) {
            if (repetido) {
                cout << "Terminando iteraciones, valores repetidos." << endl;
                break;
            }
            repetido = true;
        }
        else {
            repetido = false;
        }

        if (abs(wNuevo - wAnt) < toleranciaFija && abs(xNuevo - xAnt) < toleranciaFija && abs(yNuevo - yAnt) < toleranciaFija && abs(zNuevo - zAnt) < toleranciaFija) {
            cout << "Valores encontrados en la iteracion " << i << "." << endl;
            break;
        }

        wPrev = wNuevo;
        xPrev = xNuevo;
        yPrev = yNuevo;
        zPrev = zNuevo;

        wAnt = wNuevo;
        xAnt = xNuevo;
        yAnt = yNuevo;
        zAnt = zNuevo;
    }

    cout << "Resultado final: w = " << wNuevo << ", x = " << xNuevo << ", y = " << yNuevo << ", z = " << zNuevo << endl;

    cout << "Regresando al menu principal..." << endl;
}

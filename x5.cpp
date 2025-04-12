#include "x5.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void x5::imprimirSistema5x5(float v[], float w[], float x[], float y[], float z[], float c[]) {
    cout << "Sistema de ecuaciones:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << v[i] << "v + " << w[i] << "w + " << x[i] << "x + " << y[i] << "y + " << z[i] << "z = " << c[i] << endl;
    }
}

void x5::metodoJacobi5x5(float v[], float w[], float x[], float y[], float z[], float c[], int Iteraciones, int decimales,
    float vInicial, float wInicial, float xInicial, float yInicial, float zInicial) {
    vAnt = vInicial;
    wAnt = wInicial;
    xAnt = xInicial;
    yAnt = yInicial;
    zAnt = zInicial;

    cout << "Despeje de las variables:" << endl;
    cout << "v = (" << c[0] << " - (" << w[0] << " * w) - (" << x[0] << " * x) - (" << y[0] << " * y) - (" << z[0] << " * z)) / " << v[0] << endl;
    cout << "w = (" << c[1] << " - (" << v[1] << " * v) - (" << x[1] << " * x) - (" << y[1] << " * y) - (" << z[1] << " * z)) / " << w[1] << endl;
    cout << "x = (" << c[2] << " - (" << v[2] << " * v) - (" << w[2] << " * w) - (" << y[2] << " * y) - (" << z[2] << " * z)) / " << x[2] << endl;
    cout << "y = (" << c[3] << " - (" << v[3] << " * v) - (" << w[3] << " * w) - (" << x[3] << " * x) - (" << z[3] << " * z)) / " << y[3] << endl;
    cout << "z = (" << c[4] << " - (" << v[4] << " * v) - (" << w[4] << " * w) - (" << x[4] << " * x) - (" << y[4] << " * y)) / " << z[4] << endl;

    cout << "Iteraciones:" << endl;
    for (int i = 1; i <= Iteraciones; i++) {
        vNuevo = (c[0] - (w[0] * wAnt) - (x[0] * xAnt) - (y[0] * yAnt) - (z[0] * zAnt)) / v[0];
        wNuevo = (c[1] - (v[1] * vAnt) - (x[1] * xAnt) - (y[1] * yAnt) - (z[1] * zAnt)) / w[1];
        xNuevo = (c[2] - (v[2] * vAnt) - (w[2] * wAnt) - (y[2] * yAnt) - (z[2] * zAnt)) / x[2];
        yNuevo = (c[3] - (v[3] * vAnt) - (w[3] * wAnt) - (x[3] * xAnt) - (z[3] * zAnt)) / y[3];
        zNuevo = (c[4] - (v[4] * vAnt) - (w[4] * wAnt) - (x[4] * xAnt) - (y[4] * yAnt)) / z[4];

        cout << fixed << setprecision(decimales);
        cout << "Itt " << i << ": v = " << vNuevo << ", w = " << wNuevo << ", x = " << xNuevo
            << ", y = " << yNuevo << ", z = " << zNuevo << endl;

      
        if (vNuevo == vPrev && wNuevo == wPrev && xNuevo == xPrev && yNuevo == yPrev && zNuevo == zPrev) {
            if (repetido) {
                cout << "Terminando iteraciones debido a valores repetidos." << endl;
                break;
            }
            repetido = true;
        }
        else {
            repetido = false;
        }

        if (abs(vNuevo - vAnt) < toleranciaFija && abs(wNuevo - wAnt) < toleranciaFija &&
            abs(xNuevo - xAnt) < toleranciaFija && abs(yNuevo - yAnt) < toleranciaFija &&
            abs(zNuevo - zAnt) < toleranciaFija) {
            cout << "Convergencia alcanzada en la iteracion " << i << "." << endl;
            break;
        }

        vPrev = vNuevo;
        wPrev = wNuevo;
        xPrev = xNuevo;
        yPrev = yNuevo;
        zPrev = zNuevo;

        vAnt = vNuevo;
        wAnt = wNuevo;
        xAnt = xNuevo;
        yAnt = yNuevo;
        zAnt = zNuevo;
    }

    cout << "Resultado final: v = " << vNuevo << ", w = " << wNuevo << ", x = " << xNuevo
        << ", y = " << yNuevo << ", z = " << zNuevo << endl;

  
    cout << "Regresando al menu principal..." << endl;
}

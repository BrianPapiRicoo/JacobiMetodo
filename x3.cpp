#include "x3.hpp"

void x3::imprimirSistema3x3(float x[], float y[], float z[], float c[])
{
    cout << "Sistema de ecuaciones:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << x[i] << "x + " << y[i] << "y + " << z[i] << "z = " << c[i] << endl;
    }
}

void x3::metodoJacobi(float x[], float y[], float z[], float c[], int Iteraciones, int decimales, float xInicial, float yInicial, float zInicial)
{
    xAnt = xInicial;
    yAnt = yInicial;
    zAnt = zInicial;

    cout << "Despeje de las variables:" << endl;
    cout << "x = (" << c[0] << " - (" << y[0] << " * y) - (" << z[0] << " * z)) / " << x[0] << endl;
    cout << "y = (" << c[1] << " - (" << x[1] << " * x) - (" << z[1] << " * z)) / " << y[1] << endl;
    cout << "z = (" << c[2] << " - (" << x[2] << " * x) - (" << y[2] << " * y)) / " << z[2] << endl;

    cout << "Iteraciones:" << endl;
    for (int i = 1; i <= Iteraciones; i++) {

        xNuevo = (c[0] - (y[0] * yAnt) - (z[0] * zAnt)) / x[0];
        yNuevo = (c[1] - (x[1] * xAnt) - (z[1] * zAnt)) / y[1];
        zNuevo = (c[2] - (x[2] * xAnt) - (y[2] * yAnt)) / z[2];

        cout << fixed << setprecision(decimales);
        cout << "Itt " << i << ": x = " << xNuevo << ", y = " << yNuevo << ", z = " << zNuevo << endl;

        if (xNuevo == xPrev && yNuevo == yPrev && zNuevo == zPrev) {
            if (repetido) {
                cout << "Terminando iteraciones, valores repetidos" << endl;
                break;
            }
            repetido = true;
        }
        else {
            repetido = false;
        }

        xPrev = xNuevo;
        yPrev = yNuevo;
        zPrev = zNuevo;

        if (abs(xNuevo - xAnt) < toleranciaFija && abs(yNuevo - yAnt) < toleranciaFija && abs(zNuevo - zAnt) < toleranciaFija) {
            cout << "Valores encontrados en la iteracion " << i << endl;
            break;
        }

        xAnt = xNuevo;
        yAnt = yNuevo;
        zAnt = zNuevo;
    }
    cout << "Resultado final: x = " << xNuevo << ", y = " << yNuevo << ", z = " << zNuevo << endl;

    cout << "Regresando al menu principal..." << endl;
}
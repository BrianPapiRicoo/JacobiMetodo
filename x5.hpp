#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class x5 {
private:
    float vNuevo, wNuevo, xNuevo, yNuevo, zNuevo;
    float vAnt, wAnt, xAnt, yAnt, zAnt;
    float vPrev, wPrev, xPrev, yPrev, zPrev;
    bool repetido = false;
    const float toleranciaFija = 0.0001;

public:
    void imprimirSistema5x5(float v[], float w[], float x[], float y[], float z[], float c[]);
    void metodoJacobi5x5(float v[], float w[], float x[], float y[], float z[], float c[], int Iteraciones, int decimales,
        float vInicial, float wInicial, float xInicial, float yInicial, float zInicial);
};
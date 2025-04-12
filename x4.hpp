#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class x4 {
private:
    float wAnt, xAnt, yAnt, zAnt;
    float wNuevo, xNuevo, yNuevo, zNuevo;
    float wPrev, xPrev, yPrev, zPrev;
    bool repetido = false;
    const float toleranciaFija = 1e-5;

public:
    void imprimirSistema4x4(float w[], float x[], float y[], float z[], float c[]);
    void metodoJacobi4x4(float w[], float x[], float y[], float z[], float c[], int Iteraciones, int decimales, float wInicial, float xInicial, float yInicial, float zInicial);
};
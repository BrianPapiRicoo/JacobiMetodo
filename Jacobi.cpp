#include "x2.hpp"
#include "x3.hpp"
#include "x4.hpp"
#include "x5.hpp"
#include <iostream>
using namespace std;

//////////// Instancia de Objetos ///////////////////////////////
x2 Dos;
x3 Tres;
x4 Cuatro;
x5 Cinco;

int main() {
    float v[5], w[5], x[5], y[5], z[5], c[5];
    int Iteraciones = 100;
    int decimales = 0, resp;
    float vInicial = 0, wInicial = 0, xInicial = 0, yInicial = 0, zInicial = 0;
    char opcion; 
    ////////////////// Ciclo do-While //////////////////////////
    do {
      
        system("cls"); 
        cout << "Previamente organiza el sistema de ecuaciones donde:" << endl;
        cout << "- La PRIMER ecuacion sea la que tenga el coficiente mas grande en *V*" << endl;
        cout << "- La SEGUNDA ecuacion sea la que tenga el coficiente mas grande en *W*" << endl;
        cout << "- La TERCERA ecuacion sea la que tenga el coficiente mas grande en *X*" << endl;
        cout << "y asi sucesivamente..." << endl;
        cout << endl;

        cout << "Sistema de Ecuaciones Disponibles:" << endl;
        cout << " 1. 2x2 " << endl;
        cout << " 2. 3x3 " << endl;
        cout << " 3. 4x4 " << endl;
        cout << " 4. 5x5 " << endl;
        cout << "Opcion: ";
        cin >> resp;

        if (resp == 0) {
            cout << "Saliendo del programa..." << endl;
            break; 
        }


        /////////////////////// Switch Case //////////////////////////////////////
        switch (resp) {
        case 1:
            cout << "Ingresa el FIX (1-9): ";
            cin >> decimales;
            for (int i = 0; i < 2; i++) {
                cout << "Ingresa los valores para X" << i + 1 << ", Y" << i + 1 << " = C" << i + 1 << endl;
                cin >> x[i] >> y[i] >> c[i];
            }
            cout << "Ingresa las condiciones iniciales para X, Y: ";
            cin >> xInicial >> yInicial;
            Dos.imprimirSistema2x2(x, y, c);
            Dos.metodoJacobi2x2(x, y, c, Iteraciones, decimales, xInicial, yInicial);
            break;

        case 2:
            cout << "Ingresa el FIX (1-9): ";
            cin >> decimales;
            for (int i = 0; i < 3; i++) {
                cout << "Ingresa los valores para X" << i + 1 << ", Y" << i + 1 << ", Z" << i + 1 << " = C" << i + 1 << endl;
                cin >> x[i] >> y[i] >> z[i] >> c[i];
            }
            cout << "Ingresa las condiciones iniciales para X, Y, Z: ";
            cin >> xInicial >> yInicial >> zInicial;
            Tres.imprimirSistema3x3(x, y, z, c);
            Tres.metodoJacobi(x, y, z, c, Iteraciones, decimales, xInicial, yInicial, zInicial);
            break;

        case 3:
            cout << "Ingresa el FIX (1-9): ";
            cin >> decimales;
            for (int i = 0; i < 4; i++) {
                cout << "Ingresa los valores para W" << i + 1 << ", X" << i + 1 << ", Y" << i + 1 << ", Z" << i + 1 << " = C" << i + 1 << endl;
                cin >> w[i] >> x[i] >> y[i] >> z[i] >> c[i];
            }
            cout << "Ingresa las condiciones iniciales para W, X, Y, Z: ";
            cin >> wInicial >> xInicial >> yInicial >> zInicial;
            Cuatro.imprimirSistema4x4(w, x, y, z, c);
            Cuatro.metodoJacobi4x4(w, x, y, z, c, Iteraciones, decimales, wInicial, xInicial, yInicial, zInicial);
            break;

        case 4:
            cout << "Ingresa el FIX (1-9): ";
            cin >> decimales;
            for (int i = 0; i < 5; i++) {
                cout << "Ingresa los valores para V" << i + 1 << ", W" << i + 1 << ", X" << i + 1 << ", Y" << i + 1 << ", Z" << i + 1 << " = C" << i + 1 << endl;
                cin >> v[i] >> w[i] >> x[i] >> y[i] >> z[i] >> c[i];
            }
            cout << "Ingresa las condiciones iniciales para V, W, X, Y, Z: ";
            cin >> vInicial >> wInicial >> xInicial >> yInicial >> zInicial;
            Cinco.imprimirSistema5x5(v, w, x, y, z, c);
            Cinco.metodoJacobi5x5(v, w, x, y, z, c, Iteraciones, decimales, vInicial, wInicial, xInicial, yInicial, zInicial);
            break;

        default:
            cout << "Opcion no valida. Intenta de nuevo." << endl;
            break;
        }

        
        cout << "Deseas realizar otra operacion? (s/n): " << endl;
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S'); 
    //////////////// Fin del programa ////////////////////
    cout << "Adioooos :)";
    return 0;
}
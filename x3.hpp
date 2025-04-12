#pragma once
#include <iostream>
#include <cmath>
#include <iomanip> 
using namespace std;
class x3
{
protected: 
	float xAnt=0;
	float yAnt=0;
	float zAnt=0;
	float xNuevo = 0;
	float yNuevo = 0;
	float zNuevo = 0;
	float xPrev = 0;
	float yPrev = 0;
	float zPrev = 0;
	bool repetido = false;
	const float toleranciaFija = 0.001;
public: 
	void imprimirSistema3x3(float x[], float y[], float z[], float c[]);
	void metodoJacobi(float x[], float y[], float z[], float c[], int Iteraciones, int decimales, float xInicial, float yInicial, float zInicial);

};


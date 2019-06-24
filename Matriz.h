#pragma once
#include <string>
#include <iostream>
using namespace std;
class Matriz{
    protected:
        char name;
        int size;
        double determinante;
        double** matrix;
    public:
        Matriz(char,int,double**);
        ~Matriz();
        double** Suma(double**);
        void Incremento();
        void Decremento();
        double** MultiplicacionEscalar(double);
        double** ProductoMatrices(double**);
        double** SumaEspacio(double**);
        double** MultiplicacionEspacio(double);
        double Determinante();
        double** Traspuesta();
        double** crearMatriz();
        void Imprimir();
        char getName();
        double** getMatriz();
        int getSize();
};
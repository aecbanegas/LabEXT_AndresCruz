#pragma once
#include <string>
#include <iostream>
using std::string;
class Matriz{
    private:
        string name;
        int size;
        double determinante;
        double** matrix;
    public:
        Matriz(string,int);
        ~Matriz();
        double** Suma();
        void Incremento();
        void Decremento();
        double** MultiplicacionEscalar();
        double** ProductoMatrices();
        double** SumaEspacio();
        double** MultiplicacionEspacio();
        double Determinante();
        void Traspuesta();
        double** crearMatriz();
};
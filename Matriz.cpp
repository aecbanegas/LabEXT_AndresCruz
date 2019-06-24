#include "Matriz.h"
using std::cout;
using std::cin;
Matriz::Matriz(string nombre,int tam){
    name=nombre;
    size=tam;
}
double** crearMatriz(){
    matrix=new double*[size];
    for (int i = 0; i < size; i++){
        matrix=new double[size];
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){

        }
    }
    
}
/* ~Matriz();
double** Suma();
void Incremento();
void Decremento();
double** MultiplicacionEscalar();
double** ProductoMatrices();
double** SumaEspacio();
double** MultiplicacionEspacio();
double Determinante();
void Traspuesta();*/

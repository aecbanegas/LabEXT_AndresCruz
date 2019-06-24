#include "Matriz.h"
Matriz::Matriz(char nombre,int tam,double** matriz){
    name=nombre;
    size=tam;
    matrix=matriz;
    determinante=Determinante();
}
double Matriz::Determinante(){
    double det=0;
    if(size==2){
        det=(matrix[0][0]*matrix[1][1])-(matrix[0][1]*matrix[1][0]);
    }else if(size==3){
        det=matrix[0][0]*matrix[1][1]*matrix[2][2] + matrix[1][0]*matrix[2][1]*matrix[0][2] +matrix[2][0]*matrix[0][1]*matrix[1][2];
        det=det+(matrix[0][2]*matrix[1][1]*matrix[2][0])*-1 + (matrix[1][2]*matrix[2][1]*matrix[0][0])*-1 + (matrix[2][2]*matrix[0][1]*matrix[1][0])*-1;
    }
    return det;
}
void Matriz::Imprimir(){
    cout<<"Matriz= "<<name<<endl;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout<<"["<<matrix[i][j]<<"]";
        }
        cout<<endl;
    }
}
double** Matriz::Suma(double** matrizB){
    double** NewMatriz=new double*[size];
    for (int i = 0; i < size; i++){
        NewMatriz[i]=new double[size];
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            NewMatriz[i][j]=matrix[i][j]+matrizB[i][j];
        }
    }
    return NewMatriz;
}
void Matriz::Incremento(){
    double temp=Determinante()-size;
    if(temp<0){
        temp=temp*-1;
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            matrix[i][j]=matrix[i][j]+temp;
        }
    }
}
void Matriz::Decremento(){
    double temp=Determinante()-size;
    if(temp<0){
        temp=temp*-1;
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            matrix[i][j]=matrix[i][j]-temp;
        }
    }
}
double** Matriz::MultiplicacionEscalar(double escalar){
    double** NewMatriz=new double*[size];
    for (int i = 0; i < size; i++){
        NewMatriz[i]=new double[size];
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            NewMatriz[i][j]=escalar*matrix[i][j];
        }
    }
    return NewMatriz;    
}
char Matriz::getName(){
    return name;
}
Matriz::~Matriz(){
    for (int i = 0; i < size; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}
int Matriz::getSize(){
    return size;
}
double** Matriz::ProductoMatrices(double** matrizB){
    double** NewMatriz=new double*[size];
    for (int i = 0; i < size; i++){
        NewMatriz[i]=new double[size];
    }
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            NewMatriz[i][j]=0;         
            for(int k=0; k<size; k++){
                NewMatriz[i][j]= NewMatriz[i][j]+matrix[i][k]*matrizB[k][j];
            }
        }
    }
    return NewMatriz;
}
double** Matriz::SumaEspacio(double** matrizB){
    double** NewMatriz=new double*[size];
    for (int i = 0; i < size; i++){
        NewMatriz[i]=new double[size];
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if(i==j){
                NewMatriz[i][j]=size*(matrix[i][j]-matrizB[i][j]);
            }else{
                NewMatriz[i][j]=matrix[i][j]+matrizB[i][j];
            }
        }
    }
    return NewMatriz;
}
double** Matriz::MultiplicacionEspacio(double num){
    double** NewMatriz=new double*[size];
    for (int i = 0; i < size; i++){
        NewMatriz[i]=new double[size];
    }
    NewMatriz=Traspuesta();
    double escalar=determinante/num;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            NewMatriz[i][j]=escalar*NewMatriz[i][j];
        }
    }
    return NewMatriz;
}
double** Matriz::Traspuesta(){
    double** NewMatriz=new double*[size];
    for (int i = 0; i < size; i++){
        NewMatriz[i]=new double[size];
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            NewMatriz[i][j]=matrix[j][i];
        }
    }
    return NewMatriz;
}
double** Matriz::getMatriz(){
    return matrix;
}
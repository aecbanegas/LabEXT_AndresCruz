#include <iostream>
#include <vector>
#include "Matriz.h"
using namespace std;
int main(){
    vector<Matriz*> matrices;
    vector<int> tamaños;
    int opcmenu=0;
    while (opcmenu!=4){
        cout<<"     Menu de Matrices"<<endl
            <<"1. Crear Matrices"<<endl
            <<"2. Listar Matrices"<<endl
            <<"3. Eliminar Matrices"<<endl
            <<"4. Operar Matrices"<<endl
            <<"5. Salir"<<endl
            <<"Ingrese una opcion:"<<endl;
        cin>>opcmenu;
    }
       
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Matriz.h"
#include <cstdlib>
using namespace std;
double** crearMatriz(int);
bool seRepite(vector<Matriz*> matrices, char name){
    for (int i = 0; i < matrices.size(); i++){
        if(name==matrices[i]->getName()){
            return true;
        }
    }
    return false;
}
int main(){
    vector<Matriz*> matrices;
    int opcmenu=0;
    while (opcmenu!=5){
        cout<<"     Menu de Matrices"<<endl
            <<"1. Crear Matrices"<<endl
            <<"2. Listar Matrices"<<endl
            <<"3. Eliminar Matrices"<<endl
            <<"4. Operar Matrices"<<endl
            <<"5. Salir"<<endl
            <<"Ingrese una opcion:"<<endl;
        cin>>opcmenu;
        if(opcmenu==1){
            char name;
            cout<<"Ingrese el nombre con que se identificara la matriz: *Debe ser caracter"<<endl;
            cin>>name;
            while(seRepite(matrices,name)){
                cout<<"Ingrese el nombre con que se identificara la matriz: *Debe ser caracter **Nombre repetido es invalido"<<endl;
                cin>>name;
            }
            int size;
            cout<<"Ingrese el tamaño de la matriz cuadrada: Permitidos 2 y 3"<<endl;
            cin>>size;
            while(size!=3&&size!=2){
                cout<<"Ingrese el tamaño de la matriz cuadrada: Permitidos 2 y 3"<<endl;
                cin>>size;
            }
            matrices.push_back(new Matriz(name,size,crearMatriz(size)));
            cout<<"Se creo la matriz de manera satisfactoria."<<endl;
        }else if(opcmenu==2){
            for (int i = 0; i < matrices.size(); i++){
                cout<<"Matriz: "+matrices[i]->getName()<<endl;
                matrices[i]->Imprimir();
                cout<<endl;
            }
        }else if(opcmenu==3){
            int poseliminar;
            cout<<"Ingrese la posicion de la matriz que desea eliminar: "<<endl;
            cin>>poseliminar;
            if(poseliminar<0||poseliminar>=matrices.size()){
                cout<<"Posicion invalida o no existente. Intente de nuevo!"<<endl;
            }else{
                //Liberar memoria
                delete matrices[poseliminar];
                matrices.erase(matrices.begin()+poseliminar);
                cout<<"Se elimino de manera correcta la matriz!"<<endl;
            }
        }else if (opcmenu==4){
            string operacion;
            cout<<"Ingrese la operacion que desea ejecutar: "<<endl;
            getline(cin,operacion);
            getline(cin,operacion);
            bool secompleto=false;
            bool varincompleta=false;
            for (int i = 0; i < operacion.length(); i++){
                if(operacion[i]=='|'&&i!=operacion.length()-1){
                    Matriz* Proceso;
                    Matriz* temporal;
                    for (int j = 0; j < matrices.size(); j++){
                        if(operacion[i-1]==matrices[j]->getName()){
                            Proceso=matrices[j];
                            break;
                        }
                    }
                    if(Proceso==NULL){
                        varincompleta=true;
                        break;
                    }
                    for (int j = 0; j < matrices.size(); j++){
                        if(operacion[i+1]==matrices[j]->getName()){
                            temporal=matrices[j];
                            break;
                        }
                    }
                    if (temporal==NULL){
                        varincompleta=true;
                        break;
                    }
                    if(temporal->getSize()!=Proceso->getSize()){
                        break;
                    }
                    char name;
                    cout<<"Ingrese el nombre con que se identificara la matriz: *Debe ser caracter"<<endl;
                    cin>>name;
                    while(seRepite(matrices,name)){
                        cout<<"Ingrese el nombre con que se identificara la matriz: *Debe ser caracter **Nombre repetido es invalido"<<endl;
                        cin>>name;
                    }
                    matrices.push_back(new Matriz(name,Proceso->getSize(),Proceso->Suma(temporal->getMatriz())));
                    cout<<"Se ha creado una nueva matriz con el nombre seleccionado!"<<endl;
                    secompleto=true;
                }
                //bueno
                if(i!=operacion.length()-1){
                    if(operacion[i]=='+'&&operacion[i+1]=='+'){
                        Matriz* Proceso;
                        for (int j = 0; j < matrices.size(); j++){
                            if(operacion[i-1]==matrices[j]->getName()){
                                Proceso=matrices[j];
                                break;
                            }
                        }
                        if(Proceso==NULL){
                            varincompleta=true;
                            break;
                        }
                        bool sonletras=true;
                        string validacion=operacion.substr(0,i);
                        for (int i = 0; i < validacion.length(); i++){
                            if(isdigit(validacion[i])){
                                cout<<"Se un caracter incorrecto!"<<endl;
                                cout<<"Intente de nuevo!"<<endl;
                                sonletras=false;
                                break;
                            }
                        }
                        if(sonletras==false){
                            break;
                        }    
                        Proceso->Incremento();
                        secompleto=true;
                        break;
                    }
                    if(operacion[i]=='-'&&operacion[i+1]=='-'){
                        Matriz* Proceso;
                        for (int j = 0; j < matrices.size(); j++){
                            if(operacion[i-1]==matrices[j]->getName()){
                                Proceso=matrices[j];
                                break;
                            }
                        }
                        if(Proceso==NULL){
                            varincompleta=true;
                            break;
                        }
                        bool sonletras=true;
                        string validacion=operacion.substr(0,i);
                        for (int i = 0; i < validacion.length(); i++){
                            if(isdigit(validacion[i])){
                                cout<<"Se un caracter incorrecto!"<<endl;
                                cout<<"Intente de nuevo!"<<endl;
                                sonletras=false;
                                break;
                            }
                        }
                        if(sonletras==false){
                            break;
                        }
                        Proceso->Decremento();
                        secompleto=true;
                        break;
                    }   
                }
                //bueno
                if (operacion[i]=='>'&&i!=operacion.length()-1){
                    Matriz* Proceso;
                    for (int j = 0; j < matrices.size(); j++){
                        if(operacion[i+1]==matrices[j]->getName()){
                            Proceso=matrices[j];
                            break;
                        }
                    }
                    if(Proceso==NULL){
                        varincompleta=true;
                        break;
                    }
                    bool sonnumeros=true;
                    string validacion=operacion.substr(0,i);
                    for (int i = 0; i < validacion.length(); i++){
                        if(isalpha(validacion[i])){
                            cout<<"Se un caracter incorrecto!"<<endl;
                            cout<<"Intente de nuevo!"<<endl;
                            sonnumeros=false;
                            break;
                        }
                    }
                    if (sonnumeros==false){
                        break;
                    }
                    int escalar=atoi(operacion.c_str());
                    char name;
                    cout<<"Ingrese el nombre con que se identificara la matriz: *Debe ser caracter"<<endl;
                    cin>>name;
                    while(seRepite(matrices,name)){
                        cout<<"Ingrese el nombre con que se identificara la matriz: *Debe ser caracter **Nombre repetido es invalido"<<endl;
                        cin>>name;
                    }
                    matrices.push_back(new Matriz(name,Proceso->getSize(),Proceso->MultiplicacionEscalar(escalar)));
                    cout<<"Se ha creado una nueva matriz con el nombre seleccionado!"<<endl;
                    secompleto=true;
                    break;
                }
                //bueno
                if(operacion[i]=='&'&&i!=operacion.length()-1){
                    Matriz* Proceso;
                    Matriz* temporal;
                    for (int j = 0; j < matrices.size(); j++){
                        if(operacion[i-1]==matrices[j]->getName()){
                            Proceso=matrices[j];
                            break;
                        }
                    }
                    if(Proceso==NULL){
                        varincompleta=true;
                        break;
                    }
                    for (int j = 0; j < matrices.size(); j++){
                        if(operacion[i+1]==matrices[j]->getName()){
                            temporal=matrices[j];
                            break;
                        }
                    }
                    if(temporal==NULL){
                        varincompleta=true;
                        break;
                    }
                    if(temporal->getSize()!=Proceso->getSize()){
                        break;
                    }
                    bool sonletras=true;
                    string validacion=operacion.substr(0,i);
                    for (int i = 0; i < validacion.length(); i++){
                        if(isdigit(validacion[i])){
                            cout<<"Se un caracter incorrecto!"<<endl;
                            cout<<"Intente de nuevo!"<<endl;
                            sonletras=false;
                            break;
                        }
                    }
                    if(sonletras==false){
                        break;
                    }
                    validacion=operacion.substr(i+1,operacion.length()-(operacion.length()-i));
                    for (int i = 0; i < validacion.length(); i++){
                        if(isdigit(validacion[i])){
                            cout<<"Se un caracter incorrecto!"<<endl;
                            cout<<"Intente de nuevo!"<<endl;
                            sonletras=false;
                            break;
                        }
                    }
                    if(sonletras==false){
                        break;
                    }
                    char name;
                    cout<<"Ingrese el nombre con que se identificara la matriz: *Debe ser caracter"<<endl;
                    cin>>name;
                    while(seRepite(matrices,name)){
                        cout<<"Ingrese el nombre con que se identificara la matriz: *Debe ser caracter **Nombre repetido es invalido"<<endl;
                        cin>>name;
                    }
                    matrices.push_back(new Matriz(name,Proceso->getSize(),Proceso->ProductoMatrices(temporal->getMatriz())));
                    cout<<"Se ha creado una nueva matriz con el nombre seleccionado!"<<endl;
                    secompleto=true;
                }
                //bueno
                if(operacion[i]=='+'&&i!=operacion.length()-1){
                    Matriz* Proceso;
                    Matriz* temporal;
                    for (int j = 0; j < matrices.size(); j++){
                        if(operacion[i-1]==matrices[j]->getName()){
                            Proceso=matrices[j];
                            break;
                        }
                    }
                    if(Proceso==NULL){
                        varincompleta=true;
                        break;
                    }
                    for (int j = 0; j < matrices.size(); j++){
                        if(operacion[i+1]==matrices[j]->getName()){
                            temporal=matrices[j];
                            break;
                        }
                    }
                    if (temporal==NULL){
                        varincompleta=true;
                        break;
                    }
                    if(temporal->getSize()!=Proceso->getSize()){
                        break;
                    }
                    bool sonletras=true;
                    string validacion=operacion.substr(0,i);
                    for (int i = 0; i < validacion.length(); i++){
                        if(isdigit(validacion[i])){
                            cout<<"Se un caracter incorrecto!"<<endl;
                            cout<<"Intente de nuevo!"<<endl;
                            sonletras=false;
                            break;
                        }
                    }
                    if(sonletras==false){
                        break;
                    }
                    validacion=operacion.substr(i+1,operacion.length());
                    for (int i = 0; i < validacion.length(); i++){
                        if(isdigit(validacion[i])){
                            cout<<"Se un caracter incorrecto!"<<endl;
                            cout<<"Intente de nuevo!"<<endl;
                            sonletras=false;
                            break;
                        }
                    }
                    if(sonletras==false){
                        break;
                    }
                    char name;
                    cout<<"Ingrese el nombre con que se identificara la matriz: *Debe ser caracter"<<endl;
                    cin>>name;
                    while(seRepite(matrices,name)){
                        cout<<"Ingrese el nombre con que se identificara la matriz: *Debe ser caracter **Nombre repetido es invalido"<<endl;
                        cin>>name;
                    }
                    matrices.push_back(new Matriz(name,Proceso->getSize(),Proceso->SumaEspacio(temporal->getMatriz())));
                    cout<<"Se ha creado una nueva matriz con el nombre seleccionado!"<<endl;
                    secompleto=true;
                }
                //bueno
                if (operacion[i]=='*'&&i!=operacion.length()-1){
                    Matriz* Proceso;
                    for (int j = 0; j < matrices.size(); j++){
                        if(operacion[i+1]==matrices[j]->getName()){
                            Proceso=matrices[j];
                            break;
                        }
                    }
                    if(Proceso==NULL){
                        varincompleta=true;
                        break;
                    }
                    bool sonnumeros=true;
                    string validacion=operacion.substr(0,i);
                    for (int i = 0; i < validacion.length(); i++){
                        if(isalpha(validacion[i])){
                            cout<<"Se un caracter incorrecto!"<<endl;
                            cout<<"Intente de nuevo!"<<endl;
                            sonnumeros=false;
                            break;
                        }
                    }
                    if (sonnumeros==false){
                        break;
                    }
                    int escalar=atoi(operacion.c_str());
                    char name;
                    cout<<"Ingrese el nombre con que se identificara la matriz: *Debe ser caracter"<<endl;
                    cin>>name;
                    while(seRepite(matrices,name)){
                        cout<<"Ingrese el nombre con que se identificara la matriz: *Debe ser caracter **Nombre repetido es invalido"<<endl;
                        cin>>name;
                    }
                    matrices.push_back(new Matriz(name,Proceso->getSize(),Proceso->MultiplicacionEspacio(escalar)));
                    cout<<"Se ha creado una nueva matriz con el nombre seleccionado!"<<endl;
                    secompleto=true;
                    break;
                }
                
            }
            if(secompleto==false){
                cout<<"Se ingresaron datos de manera incorrecta!"<<endl;
            }
        }
    }
    for (int i = 0; i < matrices.size(); i++){//liberar memoria
        delete matrices[i];
    }
    return 0;
}
double** crearMatriz(int size){
    double** matrix=new double*[size];
    for (int i = 0; i < size; i++){
        matrix[i]=new double[size];
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            int valor;
            cout<<"Ingrese el valor que tomara la matriz en ["<<i<<"]["<<j<<"]"<<endl;
            cin>>valor;
            matrix[i][j]=valor;
        }
    }
    return matrix;
}
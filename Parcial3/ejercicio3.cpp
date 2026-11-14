#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    ofstream texto ("alumnos.txt", ios::app);
    if(!texto){
        cout << "No se abrio correctamente."<<endl;
        return 1;
    }
    string nombre;
    string matricula;
    float calif[3]; 

    cout << "Ingrese nombre a agregar: "<<endl;
    getline(cin, nombre);
    cout << "Ingresa matricula del alumno: "<<endl;
    getline(cin, matricula);

    for (int i = 0; i<3;i++){
        cout << "ingrese calificacion " <<i+1<<": "<<endl;
        cin >> calif[i];
        if (cin.fail()) {
            cout << "Entrada invalida." << endl;
            return 1;
        }
    }
    texto <<endl << nombre << " ";
    texto << matricula <<" ";
    for (int i = 0; i<3;i++){
        texto << calif[i]<<" ";
    }
    texto.close();
}
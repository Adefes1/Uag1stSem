/*Struct Alumno. Define struct Alumno { string nombre; string matricula; float calif[3]; } 
y crea un arreglo de 5 alumnos. Captura sus datos y muestra el promedio de cada uno.*/

#include <iostream>
#include <string>
using namespace std;

struct alumno {
    string nombre;
    string matricula;
    float calif[3];
};

int main(){
    alumno Alumnos [5];

    for (int i = 0; i < 5;i++){
        cout << "Ingrese nombre de alumno " << i+1 << ": " <<endl;
        getline(cin, Alumnos[i].nombre);

        Alumnos[i].matricula = to_string(i+1);

        for (int j = 0; j < 3; j++){
            cout << "Ingrese calificacion " << j+1 << ": " <<endl;
            cin >> Alumnos[i].calif[j];
        }
    cin.ignore(); //Evita que el getline tome el \n como string vacio.
    }

    for (int i = 0;i<5;i++){
        float sumaParaPromedio = 0;
        for (int j = 0; j < 3;j++){
            sumaParaPromedio += Alumnos[i].calif[j];
        }
        float promedio = sumaParaPromedio/3;

        cout << "Nombre: " << Alumnos[i].nombre <<endl;
        cout << "Matricula: " << Alumnos[i].matricula << endl;
        cout << "Promedio: " << promedio <<endl;
    }
    
}


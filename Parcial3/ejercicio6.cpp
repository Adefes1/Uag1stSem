#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
struct Alumno {
    string nombre;
    string matricula;
    float calif [3];
    float promedio; //Agregado para facilitar el trabajo a diferencia del proyecto 2
};
void intercambiar(Alumno *a, Alumno *b) {
    Alumno aux = *a;
    *a = *b;
    *b = aux;
}
int main(){
    const int N = 4;
    Alumno alumnos[N];
    fstream texto("alumnos.txt", ios::in);
    if (!texto.is_open()){
        cout << "Error al abrir el archivo"<<endl;
        return 1;
    }
    for (int i = 0; i<N;i++){
        texto >> alumnos[i].nombre;
        texto >> alumnos[i].matricula;
        for (int j = 0; j<3;j++){
            texto >> alumnos[i].calif[j];
        }
        alumnos[i].promedio = 0;
        for (int j = 0; j<3;j++){
            alumnos[i].promedio += alumnos[i].calif[j];
        }
        alumnos[i].promedio = alumnos[i].promedio/3;
    }
    texto.close();

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (alumnos[j].promedio < alumnos[j + 1].promedio) {
                intercambiar(&alumnos[j], &alumnos[j + 1]);
            }
        }
    }
    fstream reportePrueba("pruebaReporte.txt", ios::out);
    if (!reportePrueba.is_open()){
        cout << "No se pudo crear el archivo."<<endl;
        return 1;
    }
    reportePrueba << "Reporte de promedio de alumnos de mayor a menor:" <<endl<<endl;
    for (int i = 0; i<N; i++){
        reportePrueba << "Nombre: " << alumnos[i].nombre << ". Promedio: " << fixed <<setprecision(2)<< alumnos[i].promedio <<endl<<endl; 
    }
    reportePrueba.close();
}
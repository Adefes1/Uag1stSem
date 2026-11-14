#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
struct Alumno {
    string nombre;
    string matricula;
    float calif[3];
};
int main() {
    int N;
    cout << "Ingrese la cantidad de alumnos a leer: " << endl;
    cin >> N;
    vector<Alumno> alumnos(N);
    ifstream texto("alumnos.txt");
    if (!texto) {
        cout << "No se encontro.";
        return 1;
    }
    for (int i = 0; i < N; i++) {
        if (!(texto >> alumnos[i].nombre >> alumnos[i].matricula)) {
            cout << "Error al leer los datos.";
            return 1;
        }
        for (int j = 0; j < 3; j++) {
            if (!(texto >> alumnos[i].calif[j])) {
                cout << "Error al leer las calificaciones.";
                return 1;
            }
        }
    }
    texto.close();
    for (int i = 0; i < N; i++) {
        cout << "Nombre: " << alumnos[i].nombre << endl;
        cout << "Matricula: " << alumnos[i].matricula << endl;
        cout << "Calificaciones: ";
        for (int j = 0; j < 3; j++) {
            cout << alumnos[i].calif[j] << " ";
        }
        cout << endl;
    }
}

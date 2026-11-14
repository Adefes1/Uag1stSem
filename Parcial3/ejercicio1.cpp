#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct Alumno {
    string nombre;
    string matricula;
    float calif[3];
};
int main (){
    int n;
    cout << "Ingrese cuantos alumnos va a agregar: " << endl;
    cin >> n;
    if (cin.fail()) {
        cout << "No se puede leer ese dato.";
        return 1;
    }
    cin.ignore();
    vector<Alumno> alumnos(n);
    ofstream texto("alumnos.txt");
    for (int i = 0; i < n; i++) {
        cout << "Ingrese nombre del alumno: " << endl;
        getline(cin, alumnos[i].nombre);
        cout << "Ingrese la matricula del alumno: " << endl;
        getline(cin, alumnos[i].matricula);

        for (int j = 0; j < 3; j++) {
            cout << "Ingrese la calificacion " << j + 1 << ": " << endl;
            cin >> alumnos[i].calif[j];
            if (cin.fail()) {
                cout << "No se puede leer ese dato.";
                return 1;
            }
        }
        cin.ignore();
        texto << alumnos[i].nombre << " "
              << alumnos[i].matricula << " ";
        for (int j = 0; j < 3; j++) {
            texto << alumnos[i].calif[j] << " ";
        }
        texto << endl;
    }
    texto.close();
}

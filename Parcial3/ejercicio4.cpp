#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Alumno {
    string nombre;
    string matricula;
    float calif[3];
};

int main() {
    const int N = 4;
    Alumno alumnos[N];
    fstream texto("alumnos.txt", ios::in);
    if (!texto) {
        cout << "No se abrio correctamente." << endl;
        return 1;
    }
    for (int i = 0; i < N; i++) {
        texto >> alumnos[i].nombre;
        texto >> alumnos[i].matricula;

        for (int j = 0; j < 3; j++) {
            texto >> alumnos[i].calif[j];
        }
    }
    texto.close();
    fstream binario("alumnos.bin", ios::out | ios::binary);

    if (!binario) {
        cout << "No se pudo crear el archivo." << endl;
        return 1;
    }
    for (const auto &alumno : alumnos) {
        size_t nombreLong = alumno.nombre.length(); //Ayuda de GeeksForGeeks desde aqui a las siguientes lineas
        size_t matriculaLong = alumno.matricula.length();

        binario.write(reinterpret_cast<const char*>(&nombreLong), sizeof(nombreLong)); 
        binario.write(reinterpret_cast<const char*>(&matriculaLong), sizeof(matriculaLong));

        binario.write(reinterpret_cast<const char*>(alumno.calif), sizeof(alumno.calif));

        binario.write(alumno.nombre.c_str(), nombreLong);
        binario.write(alumno.matricula.c_str(), matriculaLong);
    }

    binario.close();
    cout << "Archivo binario creado correctamente." << endl;
}


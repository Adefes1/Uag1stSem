#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Alumno {
    string nombre;
    string matricula;
    float calif[3];
    int grupo;
};
struct Maestro {
    string nombre;
    string materia;
};
struct Grupo {
    string nombre;
    string carrera;
};

vector<Alumno> alumnos;
vector<Maestro> maestros;
vector<Grupo> grupos;

void capturarGrupos() {
    Grupo g;
    int grupoCantidad;
    cout << "Ingrese cantidad de grupos a registrar: ";
    cin >> grupoCantidad;
    cin.ignore();

    cout << "Grupos existentes: " << endl;

    for (int i = 0; i < grupos.size(); i++) {
    cout << grupos[i].nombre << endl;
    }

    cout << "No ingrese nombres de grupos que ya existen." << endl;

    //Los grupos se enumeran desde el 1 - N para el usuario pero se trabaja desde 0 en el programa
    for (int i = 0; i < grupoCantidad; i++) {
        cout << "Ingrese el nombre del grupo " << i + 1 << " a agregar: ";
        getline(cin, g.nombre);
        cout << "Ingrese nombre de la carrera relacionada a este grupo: ";
        getline(cin, g.carrera);
        grupos.push_back(g);
    }
}

void capturarAlumnos() {
    if (grupos.empty()){
        cout << "Primero cree un grupo.";
        return;
    }
    int numeroAlumnos;
    cout << "Ingrese la cantidad de alumnos a capturar: " << endl;
    cin >> numeroAlumnos;
    cin.ignore();

    for (int i = 0; i < numeroAlumnos; i++) {
        Alumno x;
        cout << "Ingrese el nombre del alumno " << i + 1 << ": " << endl;
        getline(cin, x.nombre);

        x.matricula = to_string(alumnos.size()+1);

        cout << "Ingrese las 3 calificaciones: " << endl;
        for (int j = 0; j < 3; j++) {
            cout << "Calificacion " << j + 1 << ": " << endl;
            cin >> x.calif[j];
        }
        cin.ignore();

        cout << "Grupos disponibles:" << endl;

        for (int i = 0; i < grupos.size(); i++) {
            cout << i + 1 << ". " << grupos[i].nombre << " - carrera: " << grupos[i].carrera << endl;
}

    do {
        cout << "Ingrese el NUMERO del grupo en el que esta el alumno: " << endl;
        cin >> x.grupo;
        cin.ignore();
    } while (x.grupo < 1 || x.grupo > grupos.size());

        alumnos.push_back(x);
    }
}

void capturarMaestros() {
    if (grupos.empty()){
        cout << "Primero cree un grupo.";
        return;
    }
    Maestro m;
    int numeroMaestros;
    cout << "Ingrese la cantidad de maestros a agregar: " << endl;
    cin >> numeroMaestros;
    cin.ignore();

    cout << "materias disponibles:" << endl;

    for (int i = 0; i < grupos.size(); i++) {
        cout << i+1 << ". " << grupos[i].carrera<<endl; //Carreras disponibles para el profe
    }

    for (int i = 0; i < numeroMaestros; i++) {
        cout << "Ingrese el nombre del maestro: " << endl;
        getline(cin, m.nombre);
        cout << "Ingrese el nombre de la asignatura que da: ";
        getline(cin, m.materia);

        maestros.push_back(m);
    }
}

void mostrarReportes(){
    //Calificacion individual del alumno
    cout << "Calificacion de los alumnos" <<endl;
    for (int i = 0; i < alumnos.size(); i++){
            float sumaParaPromedio = 0;
        for (int j = 0; j < 3; j++){
            sumaParaPromedio += alumnos[i].calif[j];
        }
        float promedio = sumaParaPromedio/3;

        cout << "Alumno: " << alumnos[i].nombre <<endl;
        cout << "Promedio: " << promedio <<endl;
    }
    //Mostrar al mejor de cada grupo
    cout << "Mejor alumno de cada grupo" <<endl;
    for (int i = 0; i < grupos.size();i++){
        float mejorPromedio = -1;
        string mejorAlumno = "";

        for (int j = 0; j < alumnos.size();j++){
            if (alumnos[j].grupo == i+1){
                float sumaParaPromedio = 0;
                for (int k = 0; k < 3; k++){
                    sumaParaPromedio += alumnos[j].calif[k];
                }
                float promedio = sumaParaPromedio/3;

                if (promedio > mejorPromedio){
                    mejorPromedio = promedio;
                    mejorAlumno = alumnos[j].nombre;
                }
            }
        }
        cout << "Grupo " << grupos[i].nombre << ": ";
        if (mejorAlumno == "") cout << "(sin alumnos)" << endl;
        else cout << mejorAlumno << " con " << mejorPromedio << endl;
    }
    // Alumnos por carrera
    cout << "Alumnos por carrera" << endl;

    for (int i = 0; i < grupos.size(); i++) {
        int contadorAlumnos = 0;

        for (int j = 0; j < alumnos.size(); j++) {
            if (alumnos[j].grupo == i + 1) {
                contadorAlumnos++;
            }
        } 

        cout << "Carrera: " << grupos[i].carrera << " tiene "
             << contadorAlumnos << " alumnos." << endl;
    }
}   

int main() {
    int opcion;
    do {
        cout << "Proyecto - V2" <<endl;
        cout << "Seleccione una opcion: "<< endl;
        cout << "Capturar alumnos(1)"<<endl;
        cout << "Capturar grupos y carreras(2)"<<endl;
        cout << "Capturar maestros(3)"<<endl;
        cout << "Mostrar reportes(4)"<<endl;
        cout << "Salir(5)"<< endl;

        cout << "seleccione una opcion de acuerdo a los numeros mostrados arriba: "<<endl;
        cin >> opcion;

        if (cin.fail()){ //En caso de escribir caracteres, el programa los rechaza
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Ingrese un numero de los mencionados";
            opcion = 0;
            continue;
        }

        switch (opcion) {
            case 1: capturarAlumnos();
                break;
             case 2: capturarGrupos();
                break;
            case 3: capturarMaestros();
                break;
            case 4: mostrarReportes();
                break;
            case 5: cout << "adios T-T";
                break;
            default: cout << "Error."<<endl;
                break;
        }
    } while (opcion != 5);
}
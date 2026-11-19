#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

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

float calcularPromedio(Alumno a) {
    float sumaParaPromedio = 0;
    for (int j = 0; j < 3; j++) {
        sumaParaPromedio += a.calif[j];
    }
    return sumaParaPromedio / 3;
}

void capturarGrupos(vector<Grupo>& grupos) {
    Grupo g;
    int grupoCantidad;
    do {
        cout << "Ingrese cantidad de grupos a registrar: ";
        cin >> grupoCantidad;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            grupoCantidad = 0;
            cout << "Ingrese un NUMERO mayor a 0." << endl;
        }
    } while (grupoCantidad < 1);
    cin.ignore(1000, '\n');
    cout << "Grupos existentes: " << endl;
    for (int i = 0; i < grupos.size(); i++) {
        cout << grupos[i].nombre << endl;
    }
    cout << "No ingrese nombres de grupos que ya existen." << endl;
    for (int i = 0; i < grupoCantidad; i++) {
        cout << "Ingrese el nombre del grupo " << i + 1 << " a agregar: ";
        getline(cin, g.nombre);
        cout << "Ingrese nombre de la carrera relacionada a este grupo: ";
        getline(cin, g.carrera);
        grupos.push_back(g);
    }
}

void capturarAlumnos(vector<Alumno>& alumnos, vector<Grupo>& grupos) {
    if (grupos.empty()) {
        cout << "Primero cree un grupo." << endl;
        return;
    }
    int numeroAlumnos;
    do {
        cout << "Ingrese la cantidad de alumnos a capturar: " << endl;
        cin >> numeroAlumnos;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            numeroAlumnos = 0;
            cout << "Ingrese un NUMERO mayor a 0." << endl;
        }
    } while (numeroAlumnos < 1);
    cin.ignore(1000, '\n');
    for (int i = 0; i < numeroAlumnos; i++) {
        Alumno x;
        cout << "Ingrese el nombre del alumno " << i + 1 << ": " << endl;
        getline(cin, x.nombre);
        x.matricula = to_string(alumnos.size() + 1);
        cout << "Ingrese las 3 calificaciones (de 0 a 10): " << endl;
        for (int j = 0; j < 3; j++) {
            do {
                cout << "Calificacion " << j + 1 << ": " << endl;
                cin >> x.calif[j];
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    x.calif[j] = -1;
                }
                if (x.calif[j] < 0 || x.calif[j] > 10) {
                    cout << "La calificacion debe ser un numero de 0 a 10." << endl;
                }
            } while (x.calif[j] < 0 || x.calif[j] > 10);
        }
        cin.ignore(1000, '\n');
        cout << "Grupos disponibles:" << endl;
        for (int i = 0; i < grupos.size(); i++) {
            cout << i + 1 << ". " << grupos[i].nombre << " - carrera: " << grupos[i].carrera << endl;
        }
        do {
            cout << "Ingrese el NUMERO del grupo en el que esta el alumno: " << endl;
            cin >> x.grupo;
            if (cin.fail()) {
                cin.clear();
                x.grupo = 0;
                cout << "Ingrese el NUMERO del grupo, no caracteres." << endl;
            }
            cin.ignore(1000, '\n');
        } while (x.grupo < 1 || x.grupo > grupos.size());
        alumnos.push_back(x);
    }
}

void capturarMaestros(vector<Maestro>& maestros, vector<Grupo>& grupos) {
    if (grupos.empty()) {
        cout << "Primero cree un grupo." << endl;
        return;
    }
    Maestro m;
    int numeroMaestros;
    do {
        cout << "Ingrese la cantidad de maestros a agregar: " << endl;
        cin >> numeroMaestros;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            numeroMaestros = 0;
            cout << "Ingrese un NUMERO mayor a 0." << endl;
        }
    } while (numeroMaestros < 1);
    cin.ignore(1000, '\n');
    cout << "Carreras disponibles:" << endl;
    int numeroCarrera = 1;
    for (int i = 0; i < grupos.size(); i++) {
        bool repetida = false;
        for (int j = 0; j < i; j++) {
            if (grupos[j].carrera == grupos[i].carrera) {
                repetida = true;
            }
        }
        if (!repetida) {
            cout << numeroCarrera << ". " << grupos[i].carrera << endl; //Carreras disponibles para el profe
            numeroCarrera++;
        }
    }
    for (int i = 0; i < numeroMaestros; i++) {
        cout << "Ingrese el nombre del maestro: " << endl;
        getline(cin, m.nombre);
        cout << "Ingrese el nombre de la asignatura que da: ";
        getline(cin, m.materia);
        maestros.push_back(m);
    }
}

void mostrarReportes(vector<Alumno>& alumnos, vector<Grupo>& grupos) {
    //Calificacion individual del alumno
    cout << "Calificacion de los alumnos" << endl;
    for (int i = 0; i < alumnos.size(); i++) {
        cout << "Alumno: " << alumnos[i].nombre << endl;
        cout << "Promedio: " << calcularPromedio(alumnos[i]) << endl;
    }
    //Mostrar al mejor de cada grupo
    cout << "Mejor alumno de cada grupo" << endl;
    for (int i = 0; i < grupos.size(); i++) {
        float mejorPromedio = -1;
        string mejorAlumno = "";
        for (int j = 0; j < alumnos.size(); j++) {
            if (alumnos[j].grupo == i + 1) {
                float promedio = calcularPromedio(alumnos[j]);
                if (promedio > mejorPromedio) {
                    mejorPromedio = promedio;
                    mejorAlumno = alumnos[j].nombre;
                }
            }
        }
        cout << "Grupo " << grupos[i].nombre << ": ";
        if (mejorAlumno == "") cout << "(sin alumnos)" << endl;
        else cout << mejorAlumno << " con " << mejorPromedio << endl;
    }
    // Alumnos por carrera - Me falta corregir esta cosa, quitar comentario luego. NO SE TE OLVIDE
    cout << "Alumnos por carrera" << endl;
    for (int i = 0; i < grupos.size(); i++) {
        bool repetida = false;
        for (int j = 0; j < i; j++) {
            if (grupos[j].carrera == grupos[i].carrera) {
                repetida = true;
            }
        }
        if (repetida) {
            continue;
        }
        int contadorAlumnos = 0;
        for (int j = 0; j < alumnos.size(); j++) {
            if (grupos[alumnos[j].grupo - 1].carrera == grupos[i].carrera) {
                contadorAlumnos++;
            }
        }
        cout << "Carrera: " << grupos[i].carrera << " tiene "
             << contadorAlumnos << " alumnos." << endl;
    }
}

void guardarDatos (vector<Alumno>& alumnos, vector <Maestro>& maestros, vector<Grupo>&grupos){
    ofstream texto ("Escuela.txt");
    if (!texto){
        cout << "error"<<endl;
        return;
    }
    texto << grupos.size()<<endl; //Para validar despues
    for (int i = 0; i<grupos.size();i++){
        texto << grupos[i].nombre <<endl;
        texto << grupos[i].carrera <<endl;
    }
    texto<< alumnos.size()<<endl;
    for (int i = 0; i<alumnos.size();i++){
        texto << alumnos[i].nombre<<endl;
        texto <<alumnos[i].matricula<<endl;
        texto << alumnos[i].calif[0] << " " << alumnos[i].calif[1] << " " << alumnos[i].calif[2]<< " "<<  alumnos[i].grupo<<endl;
    }
    texto <<maestros.size()<<endl;
    for (int i = 0; i<maestros.size();i++){
        texto << maestros[i].nombre<<endl;
        texto <<maestros[i].materia<<endl;
    }
    cout << "Guardado" <<endl;
}
void cargarDatos (vector<Alumno>& alumnos, vector <Maestro>& maestros, vector<Grupo>&grupos){
    ifstream texto ("Escuela.txt");
    if (!texto){
        cout << "No se encontraron datos o no existe."<<endl;
        return;
    }
        alumnos.clear(); //Ayuda de IA por los errores que me daba la falta de estas lineas
        grupos.clear();
        maestros.clear();

        int cantidad = 0;
        texto >> cantidad;
        texto.ignore(1000, '\n');
        for (int i = 0;  i< cantidad;i++){
            Grupo g;
            getline(texto, g.nombre);
            getline(texto, g.carrera);
            grupos.push_back(g);
        }
        cantidad = 0;
        texto >> cantidad;
        texto.ignore(1000, '\n');
        for (int i = 0; i<cantidad;i++){
            Alumno a;
            getline(texto, a.nombre);
            getline(texto, a.matricula);
            texto >> a.calif[0] >> a.calif[1] >> a.calif[2]>>a.grupo;
            texto.ignore(1000, '\n');
            alumnos.push_back(a);

        }
        cantidad = 0;
        texto >> cantidad;
        texto.ignore(1000, '\n');
        for (int i = 0; i < cantidad; i++) {
            Maestro m;
            getline(texto, m.nombre);
            getline(texto, m.materia);
            maestros.push_back(m);
    }
    cout << "Cargados"<<endl;
}

void generarReporte(vector <Alumno>& alumnos, vector<Grupo>& grupos){
    if (alumnos.empty() && grupos.empty()){
        cout << "No existen datos para generar el reporte." <<endl;
        return;
    }

    for (int i = 0; i<alumnos.size();i++){
        for (int j = i+1;j<alumnos.size();j++){
            if (calcularPromedio(alumnos[i])<calcularPromedio(alumnos[j])){
                Alumno aux = alumnos[i]; //IA en esta linea en especifico
                alumnos[i] = alumnos[j];
                alumnos[j]= aux;
            }
        }
    }
    ofstream texto ("reporte.txt");
    if (!texto){
        cout << "No se pudo abrir el archivo."<<endl;
        return;
    }    
    texto << fixed <<setprecision(2);
    texto << "Reporte de alumnos"<<endl;
    for (int i = 0; i<alumnos.size();i++){
        texto << i +1<< "- "<< alumnos[i].nombre << " / ";
        texto << "Matricula; "<<alumnos[i].matricula << " / ";
        texto << "Promedio: " << calcularPromedio(alumnos[i])<<endl;
    }
    texto.close();
    cout << "Reporte listo."<<endl;

}

int main() {
    vector<Alumno> alumnos;
    vector<Maestro> maestros;
    vector<Grupo> grupos;
    int opcion;
    do {
        cout << "Proyecto - V2" << endl;
        cout << "Seleccione una opcion: " << endl;
        cout << "Capturar alumnos(1)" << endl;
        cout << "Capturar grupos y carreras(2)" << endl;
        cout << "Capturar maestros(3)" << endl;
        cout << "Mostrar reportes(4)" << endl;
        cout << "Guardar(5)" << endl;
        cout << "Cargar datos(6)" << endl;
        cout << "Generar Reporte (7))" << endl;
        cout << "Salir (8)" << endl;
        cout << "seleccione una opcion de acuerdo a los numeros mostrados arriba: " << endl;
        cin >> opcion;
        if (cin.fail()) { //En caso de escribir caracteres, el programa los rechaza
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Ingrese un numero de los mencionados" << endl;
            opcion = 0;
            continue;
        }
        switch (opcion) {
            case 1: capturarAlumnos(alumnos, grupos);
                break;
            case 2: capturarGrupos(grupos);
                break;
            case 3: capturarMaestros(maestros, grupos);
                break;
            case 4: mostrarReportes(alumnos, grupos);
                break;
            case 5: guardarDatos(alumnos, maestros, grupos);
                break;
            case 6: cargarDatos(alumnos, maestros, grupos);
                break;
            case 7: generarReporte(alumnos, grupos);
                break;
            case 8: cout << "adios T-T";
                break;
            default: cout << "Error." << endl;
                break;
        }
    } while (opcion != 8);
}
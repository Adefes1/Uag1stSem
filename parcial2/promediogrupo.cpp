#include <iostream>

float calcPromedioMayor (float calificaciones[]){
    float promedioMayor = calificaciones[0];
    for (int i = 0; i < 5; i++){
        if (calificaciones[i] > promedioMayor){
            promedioMayor = calificaciones[i];
        }
    }
    return promedioMayor;
}

using namespace std;
int main (){
    float calGrupo1 [5];
    float calGrupo2 [5];
    float mayoresPromedios[2];

    for (int i = 0; i < 5; i++){
        cout << "Ingrese promedio del alumno " << i + 1  << " del grupo 1: " << endl;
        cin >> calGrupo1[i];
    }
    for (int i = 0; i < 5; i++){
        cout << "Ingrese promedio del alumno " << i + 1 << " para grupo 2: " << endl;
        cin >> calGrupo2[i];
        
    }
    mayoresPromedios[0] = calcPromedioMayor(calGrupo1);
    mayoresPromedios[1] = calcPromedioMayor(calGrupo2);

    for (int i = 0; i < 5; i++){
        cout << "Promedio del alumno " << i + 1 << " del grupo 1: " << calGrupo1[i] <<endl;
    }
    cout << "Promedio mayor: " << mayoresPromedios[0] << endl;

    for (int i = 0; i < 5; i++){
    cout << "Promedio del alumno " << i + 1 << " del grupo 2: " << calGrupo2[i] <<endl;
    }
        cout << "Promedio mayor: " << mayoresPromedios[1] << endl;
}
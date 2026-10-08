/*Matriz de alumnos. Usa una matriz de 10x3: las primeras dos columnas
 son los promedios de 10 alumnos de dos grupos (A y B), 
la tercera almacena el promedio más alto de cada fila. */

#include <iostream>
using namespace std;

void acomodar(float cals1[], float cals2[], float tabla [10][3]){
    for (int i = 0; i < 10;i++){
        tabla[i][0] = cals1[i];
        tabla[i][1] = cals2[i];

        if (cals1[i] > cals2[i]){
            tabla[i][2] = cals1[i];
        }
        else if ( cals2[i] > cals1[i]){
                tabla[i][2] = cals2[i];
        }
        else {
            tabla[i][2] = cals1[i];
        }
    }
}

int main(){
    float tablapromedios [10][3];
    float calGrupo1[10];
    float calGrupo2[10];

    for (int i = 0; i < 10; i++){
        cout << "Ingrese calificacion " << i+1 << " del grupo 1 y 2 (en ese orden): " << endl;
        cin >> calGrupo1[i] >> calGrupo2[i];
    }

    acomodar(calGrupo1, calGrupo2, tablapromedios);

    cout << "grupo 1\t grupo2\t promedio mayor de la fila" << endl;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 3;j++){
        cout << tablapromedios[i][j] << "\t";
        }
    cout << endl;
    }
}
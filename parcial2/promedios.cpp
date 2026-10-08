#include <iostream>

using namespace std;

float promedio (float calificaciones[]){
    float suma = 0;
    for (int i = 0; i < 5; i++){
        suma += calificaciones[i];
    }
    return suma/5;
}

int main(){
    float cal;
    float calificaciones [5];
    for (int i=0; i < 5; i++){
        cout << "Ingrese la calificacion " << i + 1.0 << ": " <<endl;
        cin >> calificaciones[i];
    }
    cout << "promedio: " << promedio(calificaciones);
}
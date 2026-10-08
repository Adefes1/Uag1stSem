/*Intercambio por referencia. Escribe una función que reciba dos variables
 por referencia (o por puntero) y las intercambie.
  Demuestra que el cambio persiste fuera de la función.*/

#include <iostream>

using namespace std;

void cambioValores(int* a, int* b){
    int variable_temporal = *a;
    *a = *b;
    *b = variable_temporal;
}

int main(){
    int x;
    int y;
    cout << "Ingrese valores enteros para X y Y en ese orden: " <<endl;
    cin >> x >> y;

    cout << x << " " << y << endl << "Se hace cambio de valores con una variable temporal y punteros." <<endl;
    cambioValores(&x,&y);
    cout << x << " " << y;
}
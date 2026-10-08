#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main (){
    const int n = 100;
    double ventas[n];
    double total = 0;

    srand(time(0));

    for (int i = 0; i < n;i++){
        ventas[i] = 1 + (rand()%200000)/100.0;
    }
    for (int i = 0;i < n; i++){
        total+= ventas[i];
    }

    cout << fixed << setprecision(2);
    cout << "El total es: " << total;
}
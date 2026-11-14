#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream saludo("saludo.txt", ios::in);

    if (!saludo.is_open()){
        cout << "No se ha podido abrir el archivo. Verifique que exista.."<<endl;
        return 1;
    }
    cout << "Se pudo abrir tu archivo";
    saludo.close();
}
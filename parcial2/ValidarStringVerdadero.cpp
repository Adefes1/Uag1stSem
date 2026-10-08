#include <iostream>
#include <cctype>
#include <string>

using namespace std;

bool validarTexto(const string& texto){
    for (char letra : texto){
        if(isdigit(static_cast<unsigned char>(letra))){
            return true;
        }
    }
    return false;
}

int main(){
    string nombreApellido;
    cout << "Ingrese nombre y apellido separado por - : " <<endl;
    getline(cin, nombreApellido);
    size_t separador = nombreApellido.find('-');

    if (separador == string::npos){
        cout << "Debe ingresar separador.";
        return 1;
    }

    string nombre = nombreApellido.substr(0, separador);
    string apellido = nombreApellido.substr(separador+1);

    if (validarTexto(nombre) || validarTexto(apellido)){
        cout << "No puede ingresar numeros.";
        return 1;
    }

    cout << "Nombre: " << nombre <<endl << "Apellido: " << apellido;

}
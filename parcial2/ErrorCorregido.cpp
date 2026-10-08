#include <iostream>
using namespace std;

int main (){
    int* punteroBueno;
    punteroBueno = new int(6);
    cout << *punteroBueno << endl << punteroBueno;
    delete punteroBueno;
    punteroBueno = nullptr;
    return 0;
}
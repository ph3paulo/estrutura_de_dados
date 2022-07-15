#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


using namespace std;
bool pode_colocar(string Linha, int max, int indice, char value) {
    for(int i = indice - max; i < indice + max + 1; i++ )
        if(Linha[i] == value) return false;
    return true;
}

bool distancia_calc(string& Linha, int indice, int max){

    if((int)Linha.size() == indice) return true;
    if(Linha[indice] != '.') return distancia_calc(Linha, max, indice + 1);

    for(char value = '0'; value <= max + '0'; value++){
        if(pode_colocar(Linha, max, indice, value)){
            Linha[indice] = value;
            cout << Linha << "\n";

            if(distancia_calc(Linha, max, indice + 1)) return true;
        }   
    }

    Linha[indice] = '.';
    cout << Linha << "\n";
    return false;
}

int main() {

    string Linha;
    ifstream arq("input.txt");

    int max = 0;
    arq >> Linha >> max;

    distancia_calc(Linha, 0, max);
}
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
bool inserir(string linha, int index, int valor, int proximidade){
    for(int i = index + 1; i < index + 1  + proximidade; i++){
        if(i < (int)linha.size() && linha[i] == valor + '0'){
            return false;
        }
    }
     for(int i = index - proximidade; i < index; i++){
        if(i >= 0 && linha[i] == valor + '0'){
            return false;
        }
    }
    return true;
}

bool preencher(string& linha, int index, int limite, int proximidade){
    if((int)linha.size() == index){
        return true;
    }
    if(linha[index] != '.'){
        return preencher(linha, index + 1, limite, proximidade);
    }
    for(int valor = 0; valor <= limite; valor++){
        if(inserir(linha, index, valor, proximidade)){
            linha[index] = valor + '0';
            cout << linha << "\n";
            if(preencher(linha, index + 1, limite, proximidade)){
                return true;
            }
        }   
    }
    linha[index] = '.';
    cout << linha << "\n";
    return false;
}

int main() {
    string linha;
    ifstream arq("input.txt");
    int proximidade = 0;
    arq >> linha >> proximidade;
    int limite = 3;
    preencher(linha, 0, proximidade, limite);
}
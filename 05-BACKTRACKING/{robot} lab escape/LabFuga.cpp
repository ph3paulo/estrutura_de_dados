#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

struct Posi{
    int l;
    int c;
};

vector<Posi> get_vizinhos(Posi p){
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

void show(vector<string> &matriz){
    for(string line : matriz){
        cout << line << endl;
    }
    Sleep(200);
    system("cls");
}

bool procurar(vector<string> &matriz, Posi atual, Posi dest){
    if(atual.l == dest.l && atual.c == dest.c)  return true;

    if(matriz[atual.l][atual.c] != '_') return false;

    matriz[atual.l][atual.c] = '.';

    show(matriz);

    for(auto viz : get_vizinhos(atual)){
        if(procurar(matriz, viz, dest)) return true;
    }

    matriz[atual.l][atual.c] = '_';

    show(matriz);

    return false;
}

int main(){
    ifstream arquivo("input.txt");

    int nl = 0, nc = 0;
    arquivo >> nl >> nc;

    vector<string> matriz(nl, "");
    string temp;

    getline(arquivo, temp);
    Posi inicio, fim;

    //carregando matriz
    for(int i = 0; i < nl; i++){
        getline(arquivo, matriz[i]);
    }

    
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(matriz[l][c] == 'I'){
                matriz[l][c] = '_';
                inicio = Posi {l, c};
            }
            if(matriz[l][c] == 'F'){
                matriz[l][c] = '_';
                fim = Posi {l, c};
            }
        }
    }

    procurar(matriz, inicio, fim);

    for(string line : matriz) cout << line << endl;
}
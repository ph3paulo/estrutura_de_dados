#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <random>

using namespace std;
void imprimir(vector<string> matriz, int nl, int nc);

struct Pos{
    int l, c;
    Pos(int l,int c): l(l), c(c){}
};

vector<Pos> pegar_vizinhos(Pos p){
    auto l = p.l;
    auto c = p.c;

    return {{l,c-1}, {l-1,c},{l,c+1},{l+1,c}};

}

vector<Pos> random_shuffle(vector<Pos> vet){
    random_device rd;
    mt19937 g(rd());
    shuffle(begin(vet),end(vet),g);
    return vet;
}

bool pode_furar(vector<string> matriz, int nl, int nc, Pos p){
    int cont{0};
    for(auto vizinho : pegar_vizinhos(p)){
        auto l = vizinho.l;
        auto c = vizinho.c;
        if(l<0 || l>=nl || c<0 || c>=nc){
            continue;
        }else if(matriz[vizinho.l][vizinho.c] == '#'){
            cont+=1;
        }
    }
    return (cont>=3);
}

void derrubar_parede(vector<string> matriz,int nl,int nc,Pos p){
    auto l = p.l;
    auto c = p.c;

    if(l < 0 || l>=nl || c < 0 || c>=nc){
        return;
    }
    if(matriz[l][c] != '#'){
        return;
    }
    if(!pode_furar(matriz,nl,nc,p)){
        return;
    }
        matriz[l][c] = '.';
        imprimir(matriz,nl,nc);
        
        for(auto vizinho : random_shuffle(pegar_vizinhos(p))){
            derrubar_parede(matriz,nl,nc,vizinho);
        }
}

int inicio(vector<string>matriz,int nl,int nc){
    int iniciou;
    cin >> iniciou;
    if(iniciou <= nc){
        derrubar_parede(matriz,nl,nc,Pos(1,iniciou));
    }else{
        cout << "Local de inicio nao existe, ele deve estar entre 0 e " << nc-1 << ", tente novamente :" << " \n";
        inicio(matriz,nl,nc);
    }
}

void imprimir(vector<string> matriz, int nl, int nc){
    for(int i = 0; i<nl; i++){
        for(int j = 0; j<nc;j++){
            cout << matriz[i][j];
        }

        cout << '\n';
    }
    getchar();
}

vector<string> criar_matriz(int argc, char * argv[]){
    int nl{0}, nc{0};

    stringstream(argv[1]) >> nl;
    stringstream(argv[2]) >> nc;

    vector<string> matriz(nl, string(nc, '#'));
    imprimir(matriz,nl,nc);
    cout << "Qual coluna deseja iniciar o labirinto ? \n";
    inicio(matriz,nl,nc);
}

int main(int argc, char * argv[]) {
    
    criar_matriz(argc, argv);
    
}
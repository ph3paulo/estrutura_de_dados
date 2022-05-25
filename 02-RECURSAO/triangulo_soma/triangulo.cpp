#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void print(vector<int> piramide) {
    for(int vet : piramide)
        cout << vet << " ";
    cout << endl;
}

vector<int> soma_elementos(vector<int>& piramide, vector<int> out_somado = {}, int posi = 0 ){
   if(out_somado.size() == piramide.size() - 1){
       return out_somado;
   }

   out_somado.push_back(piramide[posi] + piramide[posi + 1]);
   return soma_elementos(piramide, out_somado, posi + 1);

}

void piramide_soma_elementos(vector<int>& piramide){
    if(piramide.size() == 0){
        return;
    }

    vector<int> resultado = soma_elementos(piramide);
    
    piramide_soma_elementos(resultado);
    print(piramide);
}



int main() {

    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> piramide;

    int entrada;
    while(ss >> entrada)
        piramide.push_back(entrada);

    piramide_soma_elementos(piramide);

 }

#include <iostream>
#include <vector>
using namespace std;

void Rotacao_Direita(vector<int>& vet, int voltas){
  int aux;
  for(int i =0; i < voltas; i++){
    for(int z = ((sizeof(vet) / sizeof(int)) - 2); z >= 0; z--){
      
      if(z == ((sizeof(vet) / sizeof(int)) - 2)){
        aux = vet[z];
      }
      vet[z] = vet[ z-1];
      if(z == 0) vet[z] = aux;
      
    }
  }
}

void Print(vector<int> &vet) {
    cout << "[ ";
    for(int value : vet)
        cout << value << " ";
    cout << "]\n";
}

int main(){
    int size, voltas;
    cin >> size >> voltas;
    vector<int> vet(size);
    for(int i = 0; i < size; i++)
        cin >> vet[i];
    
    Rotacao_Direita(vet, voltas);
    Print(vet);
}
#include <iostream>

using namespace std;
void matar(int size, int vet[], int pos);
void print(int size, int vet[]);
int main(){
    int size{ 10 }, espada{ 0 }, next{};
    int size_bug{ size };
    
    int vet[size];
    for(int i = 1; i <= size; i++){
        vet[i -1] = i;
    }

    print(size, vet);
    while(true){
        espada = (espada + 1) % size_bug;
        matar(size, vet, espada);
        size_bug -= 1;
        print(size_bug, vet);
        if(vet[1] == -1)
            break;
    }
    return 0;
}

void matar(int size, int vet[], int pos){
    for(int i{ pos }; i < size; i++){
        vet[i] = vet[i + 1];
        if(i == size -1)
            vet[i] = -1;
    }
}

void print(int size, int vet[]){
    for(int i{}; i < size; i++){
        cout << vet[i] << " ";
    }
    cout << endl;

}
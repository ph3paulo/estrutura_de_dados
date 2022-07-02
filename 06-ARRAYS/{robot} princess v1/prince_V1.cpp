#include <iostream>

using namespace std;

void print(int size, int vet[], bool vet_mark[]);
int prox_survivor(int size, bool vet_mark[], int position);
void matar(int size, bool vet_mark[], int pos);
bool alguem_vivo(int size, bool vet_mark[]);
int main(){
    int size{ 9 }, espada{ 0 };
    int vet[size];
    bool vet_mark[size];

    for(int i{ 1 }; i <= size; i++){
        vet[i - 1] = i;
        vet_mark[i - 1] = true;
    }

    print(size, vet, vet_mark);
    while(true){
        matar(size, vet_mark, prox_survivor(size, vet_mark, espada));
        print(size, vet, vet_mark);
        espada = prox_survivor(size, vet_mark, espada);
        if(!alguem_vivo(size, vet_mark))
            break;

    }

    return 0;
}

void print(int size, int vet[], bool vet_mark[]){
    for(int i{}; i < size; i++){
        cout << vet[i] << ' ';
    }
    cout << endl;
    for(int i{}; i < size; i++){
        cout << vet_mark[i] << ' ';
    }
    cout << endl << endl;
}

int prox_survivor(int size, bool vet_mark[], int position){
    int cont{};
    while(true){
        position = (position + 1) % size;
        if(vet_mark[position] == true)
            return position;
        cont ++;
        if(cont == size)
            break;
    }
    return -1;
}

void matar(int size, bool vet_mark[], int pos){
    vet_mark[pos] = false;
}

bool alguem_vivo(int size, bool vet_mark[]){
    int cont{};
    for(int i{}; i < size; i++){
        if(vet_mark[i] == true)
            cont += 1;
    }
    if(cont > 1)
        return true;
    return false;
}
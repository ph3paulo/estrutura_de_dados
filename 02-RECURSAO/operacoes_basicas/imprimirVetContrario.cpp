#include<iostream>

using namespace std;

int imprimir(int vet[], int size, int a){
    if(size == 0){
        return 0;
    }
    else{
        cout << vet[a] << " ";
        a --;
        return vet[size - 1] + imprimir(vet, size - 1, a);
    } 
}

int main()
{
    int size{10}, vet[size], a = size - 1;

    for(int i = 1 ; i <= size; i++){
        vet[i-1] = i;
    }

    imprimir(vet,size, a);

    return 0;
}

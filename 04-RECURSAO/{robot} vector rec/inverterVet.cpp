#include<iostream>

using namespace std;

void inverter(int vet[], int size,int init){
    int aux = 0;
    int end = size -1;
    if(init < end){
        aux = vet[init];
        vet[init] = vet[end];
        vet[end] = aux;

        inverter(vet, size - 1, init + 1);
    }
}

void imprimir(int vet[], int size, int a){
    if(size == 0){
        return;
    }
    else{
        imprimir(vet, size - 1, a);
        cout << vet[size- 1] << " ";
    } 
}

int main()
{
    int size{10};
    //int vet[size];
    int init = 0;
    int a = 0;
    int vet[size] = {11,258,13,445,58,67,700,78,9,10};

    //for(int i = 1 ; i <= size; i++){
    //     vet[i-1] = i;
    //}

    inverter(vet,size, init);
    imprimir(vet,size, a);

    return 0;
}

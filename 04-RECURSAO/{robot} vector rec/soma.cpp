#include<iostream>

using namespace std;

int soma(int vet[], int size){
    if(size == 0){
        return 0;
    }
    else{
        return vet[size - 1] + soma(vet, size - 1);
    } 
}

int main()
{
    int size{10}, vet[size];

    for(int i = 1 ; i <= size; i++){
        vet[i-1] = i;
    }

    cout << soma(vet,size) << endl;

    return 0;
}

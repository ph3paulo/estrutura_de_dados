#include<iostream>

using namespace std;

int multip(int vet[], int size){
    if(size == 0){
        return 1;
    }
    else{
        return vet[size - 1] * multip(vet, size - 1);
    } 
}

int main()
{
    int size{4}, vet[size];

    for(int i = 1 ; i <= size; i++){
        vet[i-1] = i;
    }

    cout << multip(vet,size) << endl;

    return 0;
}

#include<iostream>

using namespace std;

int min(int vet[], int size,int menor){
    if(size == 0){
        return vet[menor];
    }
    else{
        if(vet[size -1] < vet[menor])
            return min(vet, size - 1, size -1);
        else
            return min(vet, size - 1, menor);
    }
}

int main()
{
    int size{10};
    //int vet[size];
    int a = 0;
    int vet[size] = {11,258,13,445,58,67,700,78,9,10};

    //for(int i = 1 ; i <= size; i++){
    //     vet[i-1] = i;
    //}

    cout << min(vet,size, a) << endl;

    return 0;
}

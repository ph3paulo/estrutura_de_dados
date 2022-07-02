#include <iostream>

using namespace std;

void imprimir_vetor(int v[], int size){
    for(int  i = 0; i<size; i++){
        if(v[i] != -1){
            cout << v[i] << " ";
        }
    }
    cout << endl;  
}

void fila(int vetId[], int np, int vetDf[], int df){
    for(int i = 0; i<df; i++){
        for(int j = 0; j<np; j++){
            if(vetDf[i] == vetId[j]){
                vetId[j] = -1;
            }
        }
    }
    imprimir_vetor(vetId,np);
}

int main(){
    int np,df;
    cin >> np;
    int vetId[np];
    for(int i = 0; i<np; i++){
        cin >> vetId[i];
    }
    cin >> df;
    int vetDf[df];
    for(int i = 0; i<df; i++){
        cin >> vetDf[i];
    }

    fila(vetId, np, vetDf, df);
}
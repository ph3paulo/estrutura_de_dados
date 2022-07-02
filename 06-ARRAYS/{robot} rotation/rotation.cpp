#include <iostream>
#include <string>

using namespace std;

int imprimir_vetor(int v[], int size, int aux){
    if(size == 0){
        return 0;
    }else{
        cout << v[aux] << " ";
    }
    return imprimir_vetor(v,size-1,aux+1);
}

int main(){

int tam,rot;

cin >> tam >> rot;


int vet[tam];
for(int i = 0; i<tam;i++){
    cin >> vet[i]; 
}

int aux = 0;
    
    if(rot == 0){
        imprimir_vetor(vet,tam,0);
        return 0;    
    }else{
        for(int j = 0; j < rot; j++){
		    for(int i = tam - 2; i > 0; i--){
			    if(i == tam - 2){
				    aux = vet[0];
				    vet[0] = vet[tam - 1];
				    vet[tam-1] = vet[tam-2];
			    }else{
				    vet[i+1] = vet[i];
				    if(i == 1){
					    vet[1] = aux;
				    }
			    }
		    }
	    }

        imprimir_vetor(vet,tam,0);
    }
}
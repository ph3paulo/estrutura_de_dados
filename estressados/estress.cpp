#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;
//existe: Alguém com o valor X está na fila?
bool existe(int size, int vet[], int x){
    for(int i = 0; i < size; i++){
        if(vet[i] == x) return true;
    }
    return false;
}

//contar: Quantas vezes o valor X apareceu na fila?
int contar(int size, int vet[], int x){
     int cont = 0;
     for(int i = 0; i < size; i++){
         if(vet[i] == x) cont++;
    }
    return cont;
}

//procurar: Em que posição da fila aparece X pela primeira vez?
int procurar(int size, int vet[], int x){
    for(int i = 0; i < size; i++){
        if(vet[i] == x) {
            return i;
        }
        return -1;
    }
}

//procurar_apartir: Dada a posição para iniciar a busca, qual a próxima posição em que aparece X?
int procurar_apartir(int size, int vet[], int x, int inicio){
    for(int i = inicio; i < size; i++){
       if(vet[i] == x) {
           return i;
        }
        return -1;
   }
}

//Melhor caso: 4 funções
//procurar_menor: qual o menor valor da lista?
int procurar_menor(int size, int vet[], int x){
    int aux = vet[0];
    for(int i = 0; i < size; i++){
        if(vet[i] < aux) aux = vet[i];
    }
    return aux;
}

//procurar_pos_menor: qual a posição do menor valor da lista?
int procurar_pos_menor(int size, int vet[], int x){
    int aux = vet[0], pos{};
    for(int i = 0; i < size; i++){
       if(vet[i] < aux){
           aux = vet[i];
           pos = i;
        }
    }
   return pos;
}

// //procurar_pos_menor_apartir: Dada a posição para iniciar a busca, qual a posição do menor valor da lista?
int procurar_pos_menor_apartir(int size, int vet[], int x, int inicio){
    int aux = vet[0], pos{};
    for(int i = inicio; i < size; i++){
        if(vet[i] > aux){
           aux = vet[i];
           pos = i;
       }
   }
    return pos;
}

//procurar_pos_melhor_se: qual a posição do HOMEM mais calmo? (menor valor maior que 0)
int procurar_pos_melhor_se(int size, int vet[], int x){
    int menorPositivo = vet[0], pos = 0, cont=0;
    for(int i = 0; i < size; i++){
        if(vet[i] > 0){
            cont++;
            if(vet[i]*-1 < menorPositivo) {
                menorPositivo = vet[i];
                pos = i;
            }
        }
    }
    if(cont == 0) {
        return -1;
    }
    return pos;
}

//Contagem: 4 funções
//calcular_stress_medio: qual a média de stress da fila? (abs)
int calcular_stress_medio(int size, int vet[]){
    int result = 0;
    for(int i = 0; i < size; i++){
        if(vet[i] > 0) result += vet[i];
        else result += (vet[i] * -1);
    }
    return result / size;
}

//mais_homens_ou_mulheres: Na fila existem mais homens ou mulheres?
string mais_homens_ou_mulheres(int size, int vet[]){
    int h = 0, m = 0;
    for( int i = 0; i < size; i++){
        if(vet[i] > 0) h++;
        else m++;
    }

    if(h > m) return "homens";

    else return "mulheres";

    return "empate";
}

//qual_metade_eh_mais_estressada: O nível de stress somado de todas as pessoas da primeira metade é maior que o nível de stress somado das pessoas da segunda metade da fila? (abs)
string qual_metade_eh_mais_estressada(int size, int vet[]){
    int result1 = 0, result2 = 0;
    for(int i = 0; i < size; i++){
        if(vet[i] > 0){
            if(i <= size/2)  result1 += vet[i];
            else result2 += vet[i];
        }
        else{
            if(i <= size/2) result1 += (vet[i] * -1);
            else result2 += (vet[i] * -1);
        }
    }
    if(result1 == result2) return "empate";
    else if(result1 > result2) return "primeira";
    return "Segunda";
}

//BLOCO II
//clonar: retorna um novo vetor copiando os valores do vetor de entrada
vector<int> clonar(int size, vector<int> vet){
    vector<int> v(size);
    for (int i = 0; i < (vet.size()); i++) {
        v[i] = vet[i];
    }
    return  v;
}

//pegar_homens: retorne uma lista com os homens (valores positivos)
vector<int> pegar_homens(int size, vector<int> vet){
    vector<int> v(size)
    int n = 0;
    for(int i = 0; i < size; i++){
        if(vet[i] > 0){
            v[n] = vet[i];
            n = n + 1;
        }
    }
    return  v;

}

//pegar_calmos: retorne uma lista com as pessoas com stress menor que 10 (abs)
vector<int> pegar_calmos(int size, vector<int> vet){
    vector<int> v(size)
    int n = 0;
    for(int i=0 ; i < size ;i++){
        if(vet[i] < 0){
            if((vet[i] * (-1)) =< 10){
                v[n] = vet[i];
                n = n + 1;
            }
        }
        else{
            if(vet[i] =< 10){
                v[n] = vet[i];
                n = n + 1;
            }
        }
    }

    return  v;
}

//pegar_mulheres_calmas: retorne uma lista com as mulheres com nível de stress menor que 10.(negativos menor que 10)
vector<int> pegar_mulheres_calmas(int size, vector<int> vet){
vector<int> v(size)
    int n = 0;
    for(int i=0 ; i < size ;i++){
        if(vet[i] < 0){
            if((vet[i] * (-1)) =< 10){
                v[n] = vet[i];
                n = n + 1;
            }
        }
    }
}

//Acesso: 5 funções
//inverter_com_copia
vector<int> inverter_com_copia(int size, vector<int> vet){
    vector<int> v(size);
    a = size -1;
    for (int i = 0; i < (vet.size()); i++) {
        v[a] = vet[i];
        a--;
    }
    return  v;
}

//inverter_inplace
void inverter_inplace(int size, vector<int>vet){
    int aux = 0;
    int j = size;
    for(int i = 0; i < (size); i++){
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
        j--;

        if(j == i) break;
    }
}

//sortear
int sortear(int size, vector<int>& v){
    srand( (unsigned)time(NULL) );
    return vet[rand() % size];
}

//embaralhar
void embaralhar(vector<int>& v){

}

//ordenar - selection sort utilizando
void ordenar(vector<int>& v){
}

//Conjuntos: 3 funções
//exclusivos: O fiscal permitiu a entrada de um único representante de cada valor, ou seja, uma lista dos valores que aparecem na fila sem repetição. Que conjunto foi formado?
vector<int> exclusivos(int size, vector<int> vet)[
    vector<int> v(size);
    int m = 0;
    for(int i = 0; i < size; i++){
        int cont = 0;
        for(int j = aux; j < size;j++){
            if(vet[i] == v[j])cont++;
        }
        if(cont < 1){
            v[m]=vet[i];
            m++;
        }
    }
    return v;
]

//diferentes: Qual a lista dos diferentes níveis de stress que aparecem?
vector<int> diferentes(int size vector<int> vet){
    vector<int> v(size);
    int aux = 0;
    int m = 0;
    for(int i = 0; i < size; i++){
        int cont = 0;
        for(int j = aux; j < size;j++){
            if(vet[i] < 0){
                aux = vet[i]*(-1);
                if(aux == v[j])cont++;
            }
        }
        if(cont < 1){
            if(vet[i] < 0) v[m]=vet[i]*(-1);
            else v[m]=vet[i];
            m++;
        }
    }
    return v;
}

//abandonados: quais pessoas ficaram na fila após remover um exemplar de cada valor?
vector<int> abandonados(int size, vector<int> vet){
    vector<int> v(size);
    int cont = 0;
    for(int i = 1; i < size; i++){
        for( int j= 0; j < size; j++){
            if(vet[i] == vet[j]){
                v[cont] = vet[i];
                cont++;
            }
        }
    }
}
//BLOCO III
//sozinhos: Quais PESSOAS eram as únicas representantes do seu nível de stress na fila? (abs)


int main(){
    int size{}, x{};

    scanf("%d", &size);
    // int *vet2 = clonar(size, vet);
    vector<int> vet1(size);

    for(int i = 0; i < size; i++) {
        scanf("%d", &vet1[i]);
    }

    vector<int> vet2 = clonar(size, vet1);
    cout << "Vetor copiado: ";

    for (size_t i = 0; i < vet2.size(); i++) {
        cout << vet2.at(i) << " ";
    }
    cout << endl;
    // printf("%d", contar(size, vet, 0));
    // for(int i = 0; i < size; i++) {
    //     printf("%d\n", &vet2[i]);
    // }
    return 0;
}

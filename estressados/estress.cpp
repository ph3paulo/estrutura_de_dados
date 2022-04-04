#include <iostream>

using namespace std;

bool existe(int size, int vet[], int x){
    for(int i{}; i < size; i++){
        if(vet[i] == x){
            return true;
        }
    }
    return false;
}

int contar(int size, int vet[], int x){
    int cont{};
    for(int i{}; i < size; i++){
        if(vet[i] == x){
            cont +=1;
        }
    }
    return cont;
}

int procurar(int size, int vet[], int x){
    int aux{ -1 };
    for(int i{}; i < size; i++){
        if(vet[i] == x){
            aux = i;
        }
    }
    return aux;
}

int procurar_valor(int size, int vet[], int x, int inicio){
    int aux{ -1 };
    for(int i{ inicio }; i < size; i++){
        if(vet[i] == x){
            aux = i;
        }
    }
    return aux;
}

int procurar_menor(int size, int vet[], int x){
    int aux{ vet[0] };
    for(int i{}; i < size; i++){
        if(vet[i] > aux){
            aux = vet[i];
        }
    }
    return aux;
}

int procurar_pos_menor(int size, int vet[], int x){
    int aux{ vet[0] }, pos{};
    for(int i{}; i < size; i++){
        if(vet[i] > aux){
            aux = vet[i];
            pos = i;
        }
    }
    return pos;
}


int procurar_pos_menor_apartir(int size, int vet[], int x, int inicio){
    int aux{ vet[0] }, pos{};
    for(int i{ inicio }; i < size; i++){
        if(vet[i] > aux){
            aux = vet[i];
            pos = i;
        }
    }
    return pos;
}


int procurar_melhor_pos_se(int size, int vet[], int x){
    int aux{ vet[0] }, pos{};
    for(int i{}; i < size; i++){
        if(vet[i] > aux && vet[i > 0]){
            aux = vet[i];
            pos = i;
        }
    }
    return pos;
}

int calcular_stress_medio(int size, int vet[]){
    int soma{}, result{};
    for(int i{}; i < size; i++){
        if(vet[i] > 0){
            soma += vet[i];
        } else {
            soma += (vet[i] * -1);
        }
        
    }

    result = soma / size;

    return result;
}


string mais_homens_ou_mulheres(int size, int vet[]){
    int h{}, m{};
    string result{};
    for(int i{}; i < size; i++){
        if(vet[i] > 0){
            h += 1;
        } else {
            m += 1;
        }

    }
    if(h > m)
        return "Homens";
    else if(m > h)
        return ",ulheres";

    return "empate";
}


string estress_das_metades(int size, int vet[]){
    int meio { size / 2 }, primeira{}, segunda{};

    for(int i{}; i < size; i++){
        if(i <= meio){
            if(vet[i] < 0)
                primeira += (vet[i] * -1);
            if(vet[i] > 0)
                primeira += vet[i];
        } else {
            if(vet[i] < 0)
                segunda += (vet[i] * -1);
            if(vet[i] > 0)
                segunda+= vet[i];
        }
    }
    if(primeira > segunda)
        return "primeira";
    if(primeira < segunda)
        return "segunda";

    return "empate";
}


string homens_sao_mais_estressados_que_mulheres(int size, int vet[]){
    int h{}, cont_h{}, m{}, cont_m{}, result{};

    for(int i{}; i < size; i++){
        if(vet[i] > 0){
            h += vet[i];
            cont_h += 1;
        } else {
            m = (vet[i] * -1); 
            cont_m += 1;
        }
    }

    if((h / cont_h) > (m / cont_m))
        return "homens mais estressados";
    if((h / cont_h) < (m / cont_m))
        return "mulheres mais estressadas";
    return "empate";
}


int clonar(int size, int vet[]){
    int vet_dois[size];

    for(int i{}; i < 0; i++){
        vet_dois[i] =vet[i];
    }
    return vet_dois[0];
}

int main(){
    int size{}, x{};
    int vet[size];
}
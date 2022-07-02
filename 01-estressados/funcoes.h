#include <iostream>
#include <vector>

using namespace std;

bool existe(vector<int> fila, int x){
    for (int i = 0; i < fila.size(); i++){
        if (fila[i] == x){
            cout << "true" << endl;
            return true;
        }
    }
    cout << "false" << endl;
    return false;
}

int contar(vector<int> fila, int x){
    int count = 0;
    for (int i = 0; i < fila.size(); i++)
    {
        if (fila[i] == x)
        {
            count += 1;
        }
    }
    cout << "Contou: "<< count<< endl; 
    return count;
}

int procurar(vector<int> fila, int x){
    int count = 0;

    for (int i = 0; i < fila.size(); i++){
        if(fila[i] == x ){
            cout <<"Posicao: " << i << endl;
            return i;
        }
    }
    cout << "Posicao: " << -1 << endl;
    return -1;

}

int procurar_apartir(vector<int> fila, int x,int inicio){
    int count = 0;

    for (int i = inicio; i < fila.size(); i++){
        if(fila[i] == x ){
            cout <<"Posicao(Apartir): " << i << endl;
            return i;
        }
    }
    cout << "Posicao(Apartir): " << -1 << endl;
    return -1;

}

int procurar_menor(vector<int> fila){
    int count = fila[0];

    for (int i = 0; i < fila.size(); i++){
        if(fila[i] < count  ){
            count = fila[i];
        }
    }
    cout << "Posicao(Menor): " << count << endl;
    return count;

}

int procurar_pos_menor(vector<int> fila){
    int count = fila[0];
    int posicao = 0;
    for (int i = 0; i < fila.size(); i++){
        if(fila[i] < count  ){
            count = fila[i];
            posicao = i;
        }
    }
    cout << "Posicao(Pos_Menor): " << posicao << endl;
    return posicao;

}

int procurar_pos_menor_apartir(vector<int> fila,int inicio){
    int count = fila[0];
    int posicao = 0;
    for (int i = inicio; i < fila.size(); i++){
        if(fila[i] < count  ){
            count = fila[i];
            posicao = i;
        }
    }
    cout << "Posicao(Pos_Menor_Apartir): " << posicao << endl;
    return posicao;

}

int procurar_melhor_pos_se(vector<int> fila){
    int count = 0;
    int posicao = 0;
    for(int i =0; i<fila.size();i++){
        if(fila[i]>0){
            count = fila[i];
            break;
        }else
            posicao = -1;
    }
   
    if(posicao == -1){
        cout << "Posicao(procurar_melhor_pos_se): " << posicao << endl;
        return posicao;
    }else{
    for (int i = 0; i < fila.size(); i++){
        if(fila[i] < count && fila[i] > 0 ){
            count = fila[i];
            posicao = i;
        }
    }
    cout << "Posicao(procurar_melhor_pos_se): " << posicao << endl;
    return posicao;
    }
}

float calcular_stress_medio(vector<int> fila){
    int count = 0;
    for (int i = 0; i < fila.size(); i++){
        if(fila[i]<0){
            fila[i] = fila[i]*-1;
        }
        count += fila[i];    
    }

    float media = count/fila.size();

    cout << "Media de stress: " << media << endl;
    return media;

}

string mais_homens_ou_mulheres(vector<int> fila){
    int countH = 0;
    int countM = 0;
    for (int i = 0; i < fila.size(); i++){
        if(fila[i]<0)
            countM += 1;
        else
            countH+=1;  
    }

    if(countM>countH){
         cout << "Mulheres" << endl;
         return "Mulheres";
    }
    else if(countH>countM){
         cout << "Homens" << endl;
         return "Homens";
    }else{
        cout << "Empate" << endl;
         return "Empate";
    }

}

string qual_metade_eh_mais_estressada(vector<int> fila){
    int primeira = fila.size()/2;
    int segunda = fila.size();
    int countP = 0, countS = 0;
    for (int i = 0; i < primeira; i++){
        if(fila[i]<0){
            fila[i] *= -1;
            countP += fila[i];
        }else{
            countP+=fila[i];
        }   
    }
    for (int i = primeira; i < segunda; i++){
        if(fila[i]<0){
            fila[i] *= -1;
            countS += fila[i];
        }else
            countS+=fila[i];
    }

    if(countP>countS){
         cout << "Primeira" << endl;
         return "Primeira";
    }else if(countS>countP){
         cout << "Segunda" << endl;
         return "Segunda";
    }else{
        cout << "Empate" << endl;
         return "Empate";
    }

}

string homens_sao_mais_estressados_que_mulheres(vector<int> fila){
    int countM = 0;
    int countH = 0;
    for (int i = 0; i < fila.size(); i++){
        if(fila[i]<0){
            countM += fila[i];
        }else{
            countH+=fila[i];
        }   
    }
    countM *= -1;
    if(countM>countH){
         cout << "Mulheres" << endl;
         return "Mulheres";
    }else if(countH>countM){
         cout << "Homens" << endl;
         return "Homens";
    }else{
        cout << "Empate" << endl;
         return "Empate";
    }
}

vector<int> clonar(const vector<int>& v){
    std::vector<int> vetNovo;

    for (int i = 0; i < v.size(); i++){
        vetNovo.push_back(v[i]);
    }
    cout << "Vetor novo: ";
    for(int i = 0; i<v.size();i++){
        cout << vetNovo[i] << " ,";
    }
    cout << endl;
    return vetNovo;
}


vector<int> pegar_homens(const vector<int>& v){
    vector<int> vetNovo;
    for (int i = 0; i < v.size(); i++){
        if(v[i] > 0){
            vetNovo.push_back(v[i]);
        }
    }
    cout << "Homens: ";
    for(int i = 0; i<vetNovo.size();i++){
        cout << vetNovo[i] << " ,";
    }
    cout << endl;
    return vetNovo;
}

vector<int> pegar_mulheres(const vector<int>& v){
    vector<int> vetNovo;
    for (int i = 0; i < v.size(); i++){
        if(v[i] < 0){
            vetNovo.push_back(v[i]);
        }
    }
    cout << "Mulheres: ";
    for(int i = 0; i<vetNovo.size();i++){
        cout << vetNovo[i] << " ,";
    }
    cout << endl;
    return vetNovo;
}

vector<int> pegar_calmos(const vector<int>& v){
    vector<int> vetNovo;
    for (int i = 0; i < v.size(); i++){
        if( v[i] < 10 && v[i] > -10){
             vetNovo.push_back(v[i]);
        }
    }
    cout << "Calmos: ";
    for(int i = 0; i<vetNovo.size();i++){
        cout << vetNovo[i] << " ,";
    }
    cout << endl;
    return vetNovo;
}

vector<int> pegar_mulheres_calmas(const vector<int>& v){
    vector<int> vetNovo;
    for (int i = 0; i < v.size(); i++){
        if( v[i] < 0 && v[i] > -10){
             vetNovo.push_back(v[i]);
        }
    }
    cout << "Mulheres calmas: ";
    for(int i = 0; i<vetNovo.size();i++){
        cout << vetNovo[i] << " ,";
    }
    cout << endl;
    return vetNovo;
}

vector<int> inverter_com_copia(const vector<int>& v){
    vector<int> vetNovo;
    for(int i = v.size()-1; i>=0;i--){
        vetNovo.push_back(v[i]);
    }
    cout << "Vetor invertido: ";
    for(int i = 0; i<vetNovo.size();i++){
        cout << vetNovo[i] << " ,";
    }
    cout << endl;
    return vetNovo;
}

void inverter_inplace(vector<int> v){
     int aux = 0;
     for(int i = v.size()-1;i>=v.size()/2;i--){
        v[aux] = v[i];
        aux+=1;
     }
     cout << "Vetor invertido sem vetor auxiliar: ";
    for(int i = 0; i<v.size();i++){
        cout << v[i] << " ,";
    }
    cout << endl;
}


int sortear(const vector<int>& v){
    int size = v.size() - 1;
    cout << "Sorteado: " << v[rand() % size] << endl;
    return v[rand() % size];
}


void ordenar(vector<int> v){
    int indice_menor = 0;
    for (int i = 0; i < v.size(); i++){
        
            if(v[i] < v[indice_menor]){
                indice_menor = i;
            }
            int aux = v[i];
            v[i]= v[indice_menor];
            v[indice_menor] = aux;
        }
        
    cout << "Ordenado: ";
    for(int i = 0; i<v.size();i++){
        cout << v[i] << " ,";
    }
    cout << endl;
}

vector<int> exclusivos(const vector<int>& v){
    vector<int> vetNovo;
    vetNovo.push_back(v[0]);
    for(int i = 0; i<v.size();i++){
        for(int j = 0;j<v.size();j++){
            if(vetNovo[i] != v[j]){
            vetNovo[i] = v[j];
            }
        
        }
    }
    

    cout << "Exclusivos: " ;
    for(int i = 0; i<v.size();i++){
        cout << vetNovo[i];
    }
    
    cout << endl;
    return v;
}

vector<int> diferentes(const vector<int>& v){
    vector<int> n;
    int count = 0;
    for(int i = 0; i<v.size();i++){
        for(int j = v.size()-1; j>=0;j--){
            if(v[i] == v[j]){
                break;
            }else{
             count = 1;   
            }
        }
        if(count = 1){
            n[i] = v[i];
        }
    }
}

vector<int> ocorrencias(vector<int> v){
    vector<int> count;
    for(int i = 0; i<v.size();i++){
        count.push_back(0);
    }
    for(int i = 0; i< v.size();i++){
        int aux = v[i];
        for(int j = 0; j<v.size();j++){
            if(aux == v[j]){
                count[i]++;
            }
        }
    }
    
    cout << "Ocorrencias: ";
    for(int i = 0; i< v.size(); i++){
        cout << "O nivel de estresse " << v[i] << " aparece " << count[i] << " vez(es), ";
    }
    cout << endl;

    cout << "Sozinhos: ";
    for(int i = 0; i< v.size(); i++){
        if(count[i] == 1){
        cout << v[i] << ", ";
        }
    }
    cout << endl;
int aux = 0;
for(int i = 0; i<count.size();i++){
    if(count[i] > aux){
        aux = count[i];
    }
}

cout << "Mais ocorrencia: " << aux << endl;

int aux2 = 0;
vector<int> recorrentes;
for(int j = 0; j<count.size();j++){
    for(int i = 0; i<count.size();i++){
            if(count[j] >= count[i]){
                aux2++;
            }    
    }
    if(aux2 == count.size()){
        recorrentes.push_back(v[j]);
        aux2 = 0;
    }else{
        aux2 = 0;
    }
}
cout << "Mais recorrentes: ";
for(int i = 0; i<recorrentes.size(); i++){
    cout << recorrentes[i] << ", ";
}
cout << endl;
}


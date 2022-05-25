#include <iostream>
#include <vector>

using namespace std;


void fogo_na_floresta(vector<string>& mapa, int n_l, int n_c){
    int l = mapa.size(), c = mapa[0].size();
    if(n_l >= l || n_l < 0 || n_c >= c || n_c < 0){
        return;
    } else if(mapa[n_l][n_c] != '#'){
        return;
    }

    mapa[n_l][n_c] = '*';

    fogo_na_floresta(mapa, n_l + 1, n_c);
    fogo_na_floresta(mapa, n_l - 1, n_c);
    fogo_na_floresta(mapa, n_l, n_c + 1);
    fogo_na_floresta(mapa, n_l, n_c - 1);
}

void print(vector<string>& mapa){
    cout << endl;
        for(auto line : mapa){

        cout << line << '\n';
    }
}

int main(){
    int n_l, n_c, l_fire_ignite, c_fire_ignite; 

    cin >> n_l >> n_c >> l_fire_ignite >> c_fire_ignite;

    vector<string> mapa(n_l);

    for(int i = 0; i < n_l; i++){
        cin >> mapa[i];
    }
    
    fogo_na_floresta(mapa, l_fire_ignite, c_fire_ignite);
    print(mapa);


    return 0;
}
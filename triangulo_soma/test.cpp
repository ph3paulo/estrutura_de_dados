#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> read_vector() {
    string line;
    vector<int> vet;
    int input;
    getline(   cin, line);
    stringstream ss(line);
    
    while (ss >> input) {
        vet.push_back(input);
    }

    return vet;
}

void show_vector(const vector<int>& vet, int pos = 0) {
    if (pos >= vet.size()) {
        return;
    }

    if (pos == 0) {
        cout << "[ ";
    }

    cout << vet[pos];

    if (pos == vet.size() - 1) {
        cout << " ]" <<    endl;
    } else {
        cout << " ";
    }
    
    show_vector(vet, pos + 1);
}

vector<int> collapse_vector(const  vector<int>& vet,    vector<int> out_vet = {}, int pos = 0) {
    if (out_vet.size() == vet.size() - 1) {
        return out_vet;
    }

    out_vet.push_back(vet[pos] + vet[pos + 1]);
    return collapse_vector(vet, out_vet, pos + 1);
}

void calcular_triangulo_da_soma(const  vector<int>& vet) {
    if (vet.size() == 0) {
        return;
    }

    vector<int> next_layer = collapse_vector(vet);

    calcular_triangulo_da_soma(next_layer);
    show_vector(vet);
}

int main() {
    auto vet = read_vector();
    calcular_triangulo_da_soma(vet);
}
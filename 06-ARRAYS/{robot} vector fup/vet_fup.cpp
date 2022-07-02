#include <iostream>
#include <sstream>
#include <ostream>
using namespace std;

struct Vector{
    int capacity;//capacidade total
    int size;//quantos elementos estao inseridos 
    int *data;//bloco de dados 

    Vector(int capacity){
        this->capacity = capacity;
        this->size = 0;
        this->data = new int[capacity];
    
    }

    int * end(){
        return &this->data[this->size-1];
    }

    int * begin(){
        return &this->data[0];
    }

    int& back(){
        return this->data[this->size-1];
    }

    int& front(){
        return this->data[0];
    }

    int& at(int referencia){
        if(referencia < 0 || referencia >= this->size){
            throw string("indice inválido");
        }else{
            return this->data[referencia];
        }
        
    }

    void reserve(int capacidade){
        int * new_data = new int[capacidade];
        int qtd = min(this->size, capacidade);
        for (int i = 0; i < qtd; i++){
            new_data[i] = this->data[i];
        }
        this->size = qtd;               
        this->capacity = capacidade;
        
        delete [] this->data;           
        this->data = new_data;         
    }

    void push_back(int value){ 
        if(this->size == this->capacity){
            reserve(this->capacity== 0 ? 1 : 2*this->capacity);
        }else{
            this->data[this->size] = value;
            this->size += 1;
        }
    }

    void pop_back(){
        if(this->size == 0){
            return;
        }else{
            this->data[size] = 0; //serve para zerar a ultima posição antes de "remove-lá"
            this->size -= 1;
        }
    }

};

Vector * vector_create(int capacity){
    //crie um vetor dinâmicamente
    //cria a struct
    //crie o vetor data
    //inicialize size e capacity
    Vector * data = new Vector(capacity);
    return data;
}

void vector_destroy(Vector * vector){
    //destrua data
    //destrua a struct
    delete[] vector->data;
    delete vector;
}

void vector_add(Vector * vector, int value){
    //utilize capacity e size para verificar se ainda existe espaço
    vector->push_back(value);
}

//retorne a string no formato 
// [ a b c ]
string vector_show(Vector * vector){
    //retorne uma string com os dados do vetor
    //você pode usar uma stringstream como buffer
    //stringstream ss;
    //ss << 5 << " eh inteiro";
    //ss.str() será "5 eh inteiro"
    stringstream ss;
    ss << "[";
    for(int i = 0; i<vector->size;i++){
        ss << vector->data[i] << " ";
    }
    ss << "]";
    return ss.str();


}


/* NAO MEXA DAQUI PRA BAIXO */

int main(){
    string line, cmd;
    int value;
    Vector * v = vector_create(0);
    while(true){
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        } else if(cmd == "init"){
            ss >> value;
            if(v != nullptr)
                vector_destroy(v);
            v = vector_create(value);
        } else if(cmd == "status"){
            cout << "size:" << v->size << " capacity:" << v->capacity << "\n";
        } else if(cmd == "add"){
            while(ss >> value)
                vector_add(v, value);
        } else if(cmd == "show"){
            cout << vector_show(v) << endl;
        } else {
            cout << "fail: comando invalido\n";
        }
    }
    vector_destroy(v);
}
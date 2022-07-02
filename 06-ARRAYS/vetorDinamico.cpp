#include <iostream>
#include <sstream>
#include<vector>
using namespace std;

struct Vector{
    int _capacity;
    int _size;
    int * _data;

    Vector(int capacity = 0, int valor = 0){
        _capacity = capacity;
        _size = capacity;
        new int[capacity];

        for (int i = 0; i < capacity; i++){
            _data[i] = valor;
        }
    }

    void push_back(int valor){
        if(_size == _capacity){
            this->reserve(_capacity == 0 ? 1 : 2 * _capacity);
        }
        _data[_size] = valor;
        _size += 1;
    }

    void pop_back(){
        if(_size == 0){
            return;
        }
        _size -= 1;
    }

    int& at(int indice){
        if(indice < 0 || indice >= _size){
            throw string("indice invalido");
        }
        return _data[indice];
    }

    void reserve(int capacity){
        
        int * _new_data = new int[capacity];
        int qtd = min(_size, capacity);
        for (int i = 0; i < qtd; i++){
            _new_data[i] = _data[i];
        }
        _size = qtd;               //qtd de elementos do vetor
        _capacity = capacity;
        
        delete [] _data;           //devolve o bloco antigo
        _data = _new_data;         //atualiza a referencia
    }

    int& operator[](int posi){
        return _data[posi];
    }

    int capacity(){
        return _capacity;
    }

    int size(){
        return _size;
    }

    int& front(){
        return _data[0];
    }

    int& back(){
        return _data[_size - 1];
    }

    int * begin(){
        return &_data[0];
    }

    int * end(){
        return &_data[_size];
    }
};

Vector * vector_create(int capacity){
    //crie um vetor dinâmicamente
    Vector * vet = new Vector(capacity);
    //cria a struct
    //crie o vetor data
    //inicialize size e capacity
    return vet;
}   

void vector_destroy(Vector * vector){
    delete [] vector->_data;
    delete vector;
}

void vector_add(Vector * vector, int valor){
    //utilize capacity e size para verificar se ainda existe espaço
    vector->push_back(valor);
}

//retorne a string no formato 
// [ a b c ]
string vector_show(Vector * vector){
    stringstream ss;
    ss << "[ ";
    for(int i = 0; i < vector->_size; i++)
        ss << vector->_data[i] << " ";
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
            cout << "size:" << v->_size << " capacity:" << v->_capacity << "\n";
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
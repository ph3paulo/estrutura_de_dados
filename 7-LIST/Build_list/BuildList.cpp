#include <iostream>
#include <sstream>
using namespace std;

struct Node{
    int valor;
    Node * proximo;
    Node * anteriror;
    Node(int valor = 0, Node * proximo = nullptr, Node * anteriror = nullptr):
        valor(valor), proximo(proximo), anteriror(anteriror){}
};


struct BuildList{
    Node * head;
    Node * tail;

    BuildList(){
        head = new Node(0);
        tail = new Node(0);
        head->proximo = tail;
        tail->anteriror = head;
    }

    bool empty(){
        return head->proximo == tail;
    }

    void push_front(int valor){
        insert(head, valor);
    }

    void push_back(int valor){
        insert(tail->anteriror, valor);
    }

    void insert(Node * node, int valor){
        Node * novo = new Node(valor, node->proximo, node);
        node->proximo->anteriror = novo;
        node->proximo = novo;
    }

    void byebye(Node * node){
        node->anteriror->proximo = node->proximo;
        node->proximo->anteriror = node->anteriror;
        delete node;
    }

    void pop_back(){
        if(!this->empty()) this->byebye(tail->anteriror);
    }

    void pop_front(){
        if(!this->empty()) this->byebye(tail->proximo);
    }

    string show(){
        stringstream out;
        out << "[ ";
        for(auto node = head->proximo; node != tail; node = node->proximo){
            out << node->valor << " ";
        }
        out << "]";
        return out.str();
    }
};

int main(){
    BuildList lista;
    lista.push_front(1);
    lista.push_back(9);
    cout << lista.show() << "\n";
}
#include <iostream>
#include <list>
#include <vector>

using namespace std;

void imprimir_pessoas(list<int> &pessoas, list<int>::iterator it_pessoa_espada) {
  cout << "[ ";
  for (auto it_pessoa = pessoas.begin(); it_pessoa != pessoas.end(); ++it_pessoa) {
    if (it_pessoa == it_pessoa_espada) {
      cout << (*it_pessoa) << "> ";
    } else {
      cout << (*it_pessoa) << " ";
    }
  }
  cout << "]\n";
}

list<int>::iterator executar(list<int> &pessoas, list<int>::iterator it_pessoa_espada) {
  list<int>::iterator it_pessoa = it_pessoa_espada;

  advance(it_pessoa, 1);

  if (it_pessoa == pessoas.end()) {
    it_pessoa = pessoas.begin();
  }

  pessoas.erase(it_pessoa);
  
  list<int>::iterator it_nova_pessoa = it_pessoa_espada;

  advance(it_nova_pessoa, 1);

  if (it_nova_pessoa == pessoas.end()) {
    it_nova_pessoa = pessoas.begin();
  }

  return it_nova_pessoa;
}

int main() {
  int n, e;

  cin >> n >> e;

  list<int> pessoas;

  for (int i = 1; i <= n; i++) 
  {
    pessoas.push_back(i);
  }

  list<int>::iterator it_pessoa_espada = pessoas.begin();

  advance(it_pessoa_espada, e-1);

  while (pessoas.size() >= 1) {
    imprimir_pessoas(pessoas, it_pessoa_espada);
    it_pessoa_espada = executar(pessoas, it_pessoa_espada);
  }
}
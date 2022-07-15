#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>

using namespace std;

//variaveis globais
int tamanho, t;

int recebe_tamanho(){
    cout << "Digite 4 ou 9 para ver a resolução do seu sudoku  : " << "\n";
    cin >> t;
    if(t == 4 || t == 9){
        tamanho = t*t;
        return t;
    }else{
        cout << "Tamanho invalido digite 4 ou 9 para inserir seu sudoku : " << "\n";
        recebe_tamanho();
    }
}

void imprimir_4x4(int sudoku[4][4]){
    for(int j = 0; j<t; j++){
        for(int i = 0; i < t; i++){
            cout << sudoku[j][i];
        }   
        cout << "\n";
    }
}
void imprimir_9x9(int sudoku[9][9]){
    for(int j = 0; j<t; j++){
        for(int i = 0; i < t; i++){
            cout << sudoku[j][i];
        }   
        cout << "\n";
    }
}

void testar_4x4(int sudoku[4][4]){
      vector<int> valores;
      for(int i = 1; i<=4;i++)
        valores.push_back(i);

      for(int i = 0; i<4;i++){

        //quadrante 1 
        if(sudoku[0][0] == 0){
            if(/*quadrante*/ valores[i] != sudoku[0][1] && valores[i] != sudoku[1][0] && valores[i] != sudoku[1][1] && /*coluna*/ valores[i] != sudoku[0][1] && valores[i] != sudoku[0][2] && valores[i] != sudoku[0][3] && /*linha*/valores[i] != sudoku[1][0] && valores[i] != sudoku[2][0] && valores[i] != sudoku[3][0]){
                sudoku[0][0] = valores[i];
            }
        }
        if(sudoku[0][1] == 0){
            if(/*quadrante*/ valores[i] != sudoku[0][0] && valores[i] != sudoku[1][0] && valores[i] != sudoku[1][1] && /*coluna*/ valores[i] != sudoku[0][0] && valores[i] != sudoku[0][2] && valores[i] != sudoku[0][3] && /*linha*/valores[i] != sudoku[1][1] && valores[i] != sudoku[2][1] && valores[i] != sudoku[3][1]){
                sudoku[0][1] = valores[i];
            }
        }
        if(sudoku[1][0] == 0){
            if(/*quadrante*/ valores[i] != sudoku[0][0] && valores[i] != sudoku[0][1] && valores[i] != sudoku[1][1] && /*coluna*/ valores[i] != sudoku[1][1] && valores[i] != sudoku[2][1] && valores[i] != sudoku[3][1] && /*linha*/valores[i] != sudoku[0][0] && valores[i] != sudoku[2][0] && valores[i] != sudoku[3][0]){
                sudoku[1][0] = valores[i];
            }
        }
        if(sudoku[1][1] == 0){
            if(/*quadrante*/ valores[i] != sudoku[0][0] && valores[i] != sudoku[1][0] && valores[i] != sudoku[0][1] && /*coluna*/ valores[i] != sudoku[1][0] && valores[i] != sudoku[1][2] && valores[i] != sudoku[1][3] && /*linha*/valores[i] != sudoku[0][1] && valores[i] != sudoku[2][1] && valores[i] != sudoku[3][1]){
                sudoku[1][1] = valores[i];
            }
        }

        //quadrante 2
        if(sudoku[2][0] == 0){
            if(/*quadrante*/ valores[i] != sudoku[3][0] && valores[i] != sudoku[2][1] && valores[i] != sudoku[3][1] && /*coluna*/ valores[i] != sudoku[0][0] && valores[i] != sudoku[1][0] && valores[i] != sudoku[3][0] && /*linha*/valores[i] != sudoku[2][1] && valores[i] != sudoku[2][2] && valores[i] != sudoku[2][3]){
                sudoku[2][0] = valores[i];
            }
        }
        if(sudoku[3][0] == 0){
            if(/*quadrante*/ valores[i] != sudoku[2][0] && valores[i] != sudoku[2][1] && valores[i] != sudoku[3][1] && /*coluna*/ valores[i] != sudoku[0][0] && valores[i] != sudoku[1][0] && valores[i] != sudoku[2][0] && /*linha*/valores[i] != sudoku[3][1] && valores[i] != sudoku[3][2] && valores[i] != sudoku[3][3]){
                sudoku[3][0] = valores[i];
            }
        }
        if(sudoku[2][1] == 0){
            if(/*quadrante*/ valores[i] != sudoku[2][0] && valores[i] != sudoku[3][0] && valores[i] != sudoku[3][1] && /*coluna*/ valores[i] != sudoku[0][1] && valores[i] != sudoku[1][1] && valores[i] != sudoku[3][1] && /*linha*/valores[i] != sudoku[2][0] && valores[i] != sudoku[2][2] && valores[i] != sudoku[2][3]){
                sudoku[2][1] = valores[i];
            }
        }
        if(sudoku[3][1] == 0){
            if(/*quadrante*/ valores[i] != sudoku[2][0] && valores[i] != sudoku[3][0] && valores[i] != sudoku[2][1] && /*coluna*/ valores[i] != sudoku[0][1] && valores[i] != sudoku[1][1] && valores[i] != sudoku[2][1] && /*linha*/valores[i] != sudoku[3][0] && valores[i] != sudoku[3][2] && valores[i] != sudoku[3][3]){
                sudoku[3][1] = valores[i];
            }
        }

        //quadrante 3
        if(sudoku[2][2] == 0){
            if(/*quadrante*/ valores[i] != sudoku[3][2] && valores[i] != sudoku[2][3] && valores[i] != sudoku[3][3] && /*coluna*/ valores[i] != sudoku[0][2] && valores[i] != sudoku[1][2] && valores[i] != sudoku[3][2] && /*linha*/valores[i] != sudoku[2][0] && valores[i] != sudoku[2][1] && valores[i] != sudoku[2][3]){
                sudoku[2][2] = valores[i];
            }
        }
        if(sudoku[3][2] == 0){
            if(/*quadrante*/ valores[i] != sudoku[2][2] && valores[i] != sudoku[2][3] && valores[i] != sudoku[1][3] && /*coluna*/ valores[i] != sudoku[0][2] && valores[i] != sudoku[1][2] && valores[i] != sudoku[2][2] && /*linha*/valores[i] != sudoku[3][0] && valores[i] != sudoku[3][1] && valores[i] != sudoku[3][3]){
                sudoku[3][2] = valores[i];
            }
        }
        if(sudoku[2][3] == 0){
            if(/*quadrante*/ valores[i] != sudoku[2][2] && valores[i] != sudoku[3][2] && valores[i] != sudoku[3][3] && /*coluna*/ valores[i] != sudoku[0][3] && valores[i] != sudoku[1][3] && valores[i] != sudoku[3][3] && /*linha*/valores[i] != sudoku[2][0] && valores[i] != sudoku[2][1] && valores[i] != sudoku[2][2]){
                sudoku[2][3] = valores[i];
            }
        }
        if(sudoku[3][3] == 0){
            if(/*quadrante*/ valores[i] != sudoku[2][2] && valores[i] != sudoku[3][2] && valores[i] != sudoku[3][3] && /*coluna*/ valores[i] != sudoku[0][3] && valores[i] != sudoku[1][3] && valores[i] != sudoku[2][3] && /*linha*/valores[i] != sudoku[3][0] && valores[i] != sudoku[3][1] && valores[i] != sudoku[3][2]){
                sudoku[3][3] = valores[i];
            }
        }

        //quadrante 4
        if(sudoku[0][2] == 0){
            if(/*quadrante*/ valores[i] != sudoku[0][3] && valores[i] != sudoku[1][2] && valores[i] != sudoku[1][3] && /*coluna*/ valores[i] != sudoku[1][2] && valores[i] != sudoku[2][2] && valores[i] != sudoku[3][2] && /*linha*/valores[i] != sudoku[0][0] && valores[i] != sudoku[0][1] && valores[i] != sudoku[0][3]){
                sudoku[0][2] = valores[i];
            }
        }
        if(sudoku[1][2] == 0){
            if(/*quadrante*/ valores[i] != sudoku[0][2] && valores[i] != sudoku[0][3] && valores[i] != sudoku[1][3] && /*coluna*/ valores[i] != sudoku[0][2] && valores[i] != sudoku[2][2] && valores[i] != sudoku[3][2] && /*linha*/valores[i] != sudoku[1][0] && valores[i] != sudoku[1][1] && valores[i] != sudoku[1][3]){
                sudoku[1][2] = valores[i];
            }
        }
        if(sudoku[0][3] == 0){
            if(/*quadrante*/ valores[i] != sudoku[0][2] && valores[i] != sudoku[1][2] && valores[i] != sudoku[1][3] && /*coluna*/ valores[i] != sudoku[1][3] && valores[i] != sudoku[2][3] && valores[i] != sudoku[3][3] && /*linha*/valores[i] != sudoku[0][0] && valores[i] != sudoku[0][1] && valores[i] != sudoku[0][2]){
                sudoku[0][3] = valores[i];
            }
        }
        if(sudoku[1][3] == 0){
            if(/*quadrante*/ valores[i] != sudoku[0][2] && valores[i] != sudoku[0][3] && valores[i] != sudoku[1][2] && /*coluna*/ valores[i] != sudoku[0][3] && valores[i] != sudoku[2][3] && valores[i] != sudoku[3][3] && /*linha*/valores[i] != sudoku[1][0] && valores[i] != sudoku[1][1] && valores[i] != sudoku[1][2]){
                sudoku[1][3] = valores[i];
            }
        }

        
        
      }

      imprimir_4x4(sudoku);
      
}

void testar_9x9(int sudoku[9][9]){
    cout << "Codigo inacabado";
}

void preenchendo_matriz(vector<int> transformado){
    if(t == 4){
        int sudoku[4][4];
        int x = 0;
        for(int i = 0; i<t;i++){
            for(int j = 0; j<t; j++){
                sudoku[i][j] = transformado[x];
                x++;
            }
        }

        testar_4x4(sudoku);
        
    }else{
        int sudoku[9][9];
        int x = 0;
        for(int i = 0; i<t;i++){
            for(int j = 0; j<t; j++){
                sudoku[i][j] = transformado[x];
                x++;
            }
        }

        imprimir_9x9(sudoku);
    }
}

void transformando(char* data){
    vector<int> transformado;
    for(int i = 0; i<tamanho;i++){
        if(data[i] == '.'){
            transformado.push_back(0);
        }else if(data[i] == '1'){
            transformado.push_back(1);
        }else if(data[i] == '2'){
            transformado.push_back(2);    
        }else if(data[i] == '3'){
            transformado.push_back(3);    
        }else if(data[i] == '4'){
            transformado.push_back(4);    
        }else if(data[i] == '5'){
            transformado.push_back(5);    
        }else if(data[i] == '6'){
            transformado.push_back(6);    
        }else if(data[i] == '7'){
            transformado.push_back(7);    
        }else if(data[i] == '8'){
            transformado.push_back(8);    
        }else{
            transformado.push_back(9);
        }
    }
    preenchendo_matriz(transformado);
}

void preencher(){
    char* data;
    for(int i = 0; i<tamanho;i++){
        cin >> data[i];
    }
    transformando(data);
}

int main() {

    //recebendo e testando o tamanho da matriz
    recebe_tamanho();
    
    //preenchendo a matriz;
    preencher();

    return 0;

}
#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool verificar_validacao(string expressao){
    if (expressao.empty()){
        return false;
    }
    stack<char> pilha;
    for (size_t i = 0; i < expressao.length(); i++){
        char atual = expressao[i];
        if (atual  == '(' || atual ==  '{' || atual == '['){
            pilha.push(atual);
        }
        else if (atual == ')' || atual == '}' || atual == ']'){
            if (pilha.empty()){
                cout << "Erro de delimitacao "<< atual <<" na posicao " << i << endl;
                return false;
            }
            char topo = pilha.top();
            if ((atual == ')' && topo != '(') ||
                (atual == '}' && topo != '{') ||
                (atual == ']' && topo != '[')){
                cout << "Erro: delimitador de fechamento " << atual << " na posição " << i << " não corresponde ao de abertura " << topo << endl;
                return false;
            }
            pilha.pop();
        }
    }
    if(!pilha.empty()){
        cout << "Erro: delimitadores de abertura restantes sem fechamento." << endl;
        return false;
    }
    return true;
}

int main(){
    string expressao;
    cout << "Digite: ";
    cin >> expressao;
    if (verificar_validacao(expressao)){
        cout << "Expressao balanceada!!" << endl;
    }
    return 0;
}
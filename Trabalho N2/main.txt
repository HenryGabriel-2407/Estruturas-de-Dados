#include <stack>
#include <iostream>
#include <list>
#include <fstream>

using namespace std;

bool verificar_item_na_lista(list <string> &lista, string valor){
    auto aux = lista.begin();
    for (; aux != lista.end(); aux++){
        if (*aux == valor){
            return true;
        }    
    }
    return false;
}

int main(){
    std::ofstream resultado("resultado.txt");
    if (!resultado.is_open()) {
        std::cerr << "Erro ao abrir arquivo de saída." << std::endl;
        return 1;
    }
    stack<string> pilha;
    list <string> lista;
    char opcao;
    int quantidade;
    string valor;
    cin >> quantidade;
    for(int i = 0; i < quantidade; i++){
        cin >> opcao;
        switch(opcao){
            case 'V':
            case 'v':
                cin >> valor;
                pilha.push(valor);
                if(!verificar_item_na_lista(lista, valor)){
                    lista.push_back(valor);
                }
                resultado << pilha.top() << " " << pilha.size() << endl;
                break;
            case 'B':
            case 'b':
                cin >> valor;
                if(!pilha.empty()){
                    pilha.pop();
                    if(pilha.empty()){
                        resultado << "VAZIA" << endl;
                    } else{
                        resultado << pilha.top() << " " << pilha.size() << endl;
                    }
                } else{
                    resultado << "UNDERFLOW" << endl;
                }
                break;
            case 'H':
            case 'h':
                cin >> valor;
                if(!lista.empty()){
                    auto interador = lista.begin();
                    for (; interador != prev(lista.end()); ++interador){
                        resultado << *interador << " - ";
                    }
                    resultado << lista.back() << endl;
                } else{
                    resultado << "VAZIA" << endl;
                }
                break;
            default:
                resultado << "Opcao invalida!" << endl;
                break;
        }
    }
    resultado.close();
    return 0;
}
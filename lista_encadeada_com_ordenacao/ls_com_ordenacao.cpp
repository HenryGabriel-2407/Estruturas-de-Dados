#include <iostream>
#include <string>

using namespace std;

struct nodo {
    string info; //informação armazenada
    nodo *elo; // endereço do próximo elemento
};

struct lista {
    nodo *inicio; //endereço do primeiro
    nodo *fim; // endereço do ultimo elemento
    int tamanho;
};

// Definição do Descritor
void inicializacao(lista &lo) {
    lo.inicio = NULL;
    lo.fim = NULL;
    lo.tamanho = 0;
}

// Função de mostrar na tela as informações da lista
void mostrar(lista lo) {
    nodo *it = lo.inicio;
    while (it != NULL) {
        cout << it->info << endl;
        it = it->elo;
    }
}

bool inclusao_ord(lista &lo, string valor){
    nodo *novo = new nodo;
    novo->info = valor;
    novo->elo = NULL;

    if (lo.inicio == NULL){  //a lista é vazia??
        lo.inicio = lo.fim = novo;
        lo.tamanho++;
        return true;
    }
    
    // o valor é menor do que o primeiro?
    if (valor <= lo.inicio->info){
        novo->elo = lo.inicio;
        lo.inicio = novo;
        lo.tamanho++;
        return true;
    }
        // o valor é o maior
    if (valor >= lo.fim->info){
        lo.fim->elo = novo;
        novo->elo = NULL;
        lo.fim = novo;
        lo.tamanho++;
        return true;
    }
    
    // valor é intermediário
    nodo *it = lo.inicio;
    nodo *ant = NULL;
    while (it != NULL && valor > it->info){
        ant = it;
        it = it->elo;
    }
    ant->elo = novo;
    novo->elo = it;
    lo.tamanho++;
    return true;
}

bool retirada_valor(lista &lo, string valor){
    nodo *it = lo.inicio;
    nodo *ant = NULL;
    while (it != NULL) {
        if (valor == it->info) break;
        ant = it;
        it = it->elo;
    }
    if (it == NULL) return false;

    if (it == lo.inicio && it == lo.fim) {
        lo.inicio = lo.fim = NULL;
    } else if (it == lo.inicio) {
        lo.inicio = it->elo;
    } else if (it == lo.fim) {
        ant->elo = NULL;
        lo.fim = ant;
    } else {
        ant->elo = it->elo;
    }
    lo.tamanho--;
    delete it;
    return true;

}

int main() {
    lista lo;
    inicializacao(lo);

    int opcao;
    string valor;

    while (true) {
        cout << "\n\nMENU\n\n";
        cout << "------\n";
        cout << "1 - Incluir ordenada \n";
        cout << "2 - Mostrar\n";
        cout << "3 - Retirar um elemento\n";
        cout << "0 - Sair\n";
        cout << "Sua opcao: ";

        cin >> opcao;
        switch (opcao) {
            case 0:
                return 0;
            case 1:
                cout << "INCLUSAO\n\nValor a ser incluido: ";
                cin >> valor;
                if (inclusao_ord(lo, valor)) {
                    cout << "\nINCLUSAO EFETUADA\n";
                } else {
                    cout << "\nINCLUSAO NAO EFETUADA\n";
                }
                break;
            case 2:
                cout << "\nMOSTRAR\n";
                mostrar(lo);
                break;
            case 3:
                cout <<"DIGITE O VALOR PARA RETIRAR: ";
                cin >> valor;
                if (retirada_valor(lo, valor)){
                    cout << "Item removido";
                } else{
                    cout << "Item nao removido";
                }
                break;
        }
    }
    return 0;
}

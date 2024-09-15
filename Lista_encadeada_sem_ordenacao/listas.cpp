#include <iostream>
#include <stack>
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
void inicializacao(lista &l) {
    l.inicio = NULL;
    l.fim = NULL;
    l.tamanho = 0;
}

// Função de inclusão no fim da lista
bool incluir_fim(lista &l, string valor) {
    nodo *novo = new nodo;
    if (novo == NULL) {
        return false;
    }
    novo->info = valor;
    novo->elo = NULL;

    if (l.inicio == NULL) {
        l.inicio = novo;
    } else {
        l.fim->elo = novo;
    }
    l.fim = novo;
    l.tamanho++;
    return true;
}

// Buscar o elemento
bool buscar(lista l, string valor) {
    nodo *it = l.inicio;
    while (it != NULL) {
        if (it->info == valor)
            return true;
        it = it->elo;
    }
    return false;
}

// Função de mostrar na tela as informações da lista
void mostrar(lista l) {
    nodo *it = l.inicio;
    while (it != NULL) {
        cout << it->info << endl;
        it = it->elo;
    }
}

bool inclusao_apos(lista &l, string valor, string refe) {
    nodo *it = l.inicio;
    while (it != NULL) {
        if (refe == it->info) {
            nodo *novo = new nodo;
            novo->info = valor;
            novo->elo = it->elo;
            it->elo = novo;
            if (novo->elo == NULL) {
                l.fim = novo;
            }
            l.tamanho++;
            return true;
        }
        it = it->elo;
    }
    return false;
}

bool retirada_valor(lista &l, string valor) {
    nodo *it = l.inicio;
    nodo *ant = NULL;
    while (it != NULL) {
        if (valor == it->info) break;
        ant = it;
        it = it->elo;
    }
    if (it == NULL) return false;

    if (it == l.inicio && it == l.fim) {
        l.inicio = l.fim = NULL;
    } else if (it == l.inicio) {
        l.inicio = it->elo;
    } else if (it == l.fim) {
        ant->elo = NULL;
        l.fim = ant;
    } else {
        ant->elo = it->elo;
    }
    l.tamanho--;
    delete it;
    return true;
}

bool retirar_todos_item(lista &l, string valor) {
    bool removed = false;
    while (retirada_valor(l, valor)) {
        removed = true;
    }
    return removed;
}

int num_lista(lista &l){
    int elementos = 0;
    nodo *it = l.inicio;
    while (it != NULL){
        elementos++;
        it = it->elo;
    }
    return elementos;
}

bool retirar_ult(lista &l){
    if(l.inicio == NULL){ // a lista é vazia?
        return false;
    }
    nodo *it = l.inicio;
    nodo *ant = NULL;
    if(it->elo == NULL){ // há apenas um elemento na lista?
        delete it;
        l.inicio = NULL;
        l.tamanho--;
        return true;
    }
    while (it->elo != NULL){
        ant = it;
        it = it->elo;
    }
    if(ant != NULL){
        ant->elo = NULL;
    }
    delete it;
    l.tamanho--;
    return true;
}

bool inserir_inicio(lista &l, string valor){
    if(l.inicio == NULL){ // a lista é vazia?
        incluir_fim(l, valor);
        return true;
    }
    // criar um novo nó
    nodo *novo = new nodo;
    novo->elo = l.inicio;
    novo->info = valor;
    l.inicio = novo;
    l.tamanho++;
    return true;
}

bool remover_apos(lista &l, string valor, string refer){
    nodo *it = l.inicio;
    nodo *ant = NULL;
    while (it != NULL) {
        if (valor == it->info && refer == ant->info) break;
        ant = it;
        it = it->elo;
    }
    if (it == NULL) return false;

    if (it == l.inicio && it == l.fim) {
        l.inicio = l.fim = NULL;
    } else if (it == l.inicio) {
        l.inicio = it->elo;
    } else if (it == l.fim) {
        ant->elo = NULL;
        l.fim = ant;
    } else {
        ant->elo = it->elo;
    }
    l.tamanho--;
    delete it;
    return true;
}

void lista_invertida(lista &l){
    stack<string> pilha;
    nodo *it = l.inicio;
    while (it != NULL){
        pilha.push(it->info);
        it = it->elo;
    }
    while (!pilha.empty()){
        cout << pilha.top() + "\n";
        pilha.pop();
    }
}

int main() {
    lista l;
    inicializacao(l);

    int opcao;
    string valor;

    while (true) {
        cout << "\n\nMENU\n\n";
        cout << "------\n";
        cout << "1 - Incluir no fim da lista \n";
        cout << "2 - Mostrar\n";
        cout << "3 - Buscar\n";
        cout << "4 - Inserir novo valor apos uma referencia\n";
        cout << "5 - Retirada de um item\n";
        cout << "6 - Retirar todos os elementos de um item\n";
        cout << "7 - Mostrar numero de elementos na lista\n";
        cout << "8 - Retirar o ultimo elemento\n";
        cout << "9 - Inserir elemento no incio\n";
        cout << "10 - Remover um elemento apos um valor\n";
        cout << "11 - Mostrar a lista invertida\n";
        cout << "0 - Sair\n";
        cout << "Sua opcao: ";

        cin >> opcao;
        string refe;
        int num_elementos;
        switch (opcao) {
            case 0:
                return 0;
            case 1:
                cout << "INCLUSAO\n\nValor a ser incluido: ";
                cin >> valor;
                if (incluir_fim(l, valor)) {
                    cout << "\nINCLUSAO EFETUADA\n";
                } else {
                    cout << "\nINCLUSAO NAO EFETUADA\n";
                }
                break;
            case 2:
                cout << "\nMOSTRAR\n";
                mostrar(l);
                break;
            case 3:
                cout << "Digite o valor a ser buscado: ";
                cin >> valor;
                if (buscar(l, valor)) {
                    cout << "Informacao buscada!";
                } else {
                    cout << "Nao encontrada...";
                }
                break;
            case 4:
                cout << "Digite o novo valor: ";
                cin >> valor;
                cout << "Digite o valor de referencia: ";
                cin >> refe;
                if (inclusao_apos(l, valor, refe)) {
                    cout << "Inclusao apos a referencia efetuada.";
                } else {
                    cout << "Referencia nao encontrada.";
                }
                break;
            case 5:
                cout << "Digite o valor a ser retirado: ";
                cin >> valor;
                if (retirada_valor(l, valor)) {
                    cout << "Valor retirado com sucesso.";
                } else {
                    cout << "Valor nao encontrado.";
                }
                break;
            case 6:
                cout << "Digite o valor a ser retirado: ";
                cin >> valor;
                if (retirar_todos_item(l, valor)) {
                    cout << "Todos os " + valor + " foram retirados.";
                } else {
                    cout << "Este elemento nao existe.";
                }
                break;
            case 7:
                num_elementos = num_lista(l);
                cout << "Ha "+ to_string(num_elementos) + " elementos na lista";
                break;
            case 8:
                if(retirar_ult(l)){
                    cout << "Ultimo elemento retirado!";
                } else{
                    cout << "A lista eh vazia";
                }
                break;
            case 9:
                cout << "INCLUSAO INICIO\nDigite o valor a ser incluido: ";
                cin >> valor;
                if(inserir_inicio(l, valor)){
                    cout << "Valor inserido no comeco!";
                } else{
                    cout << "ERRO!";
                }
                break;
            case 10:
                cout << "Digite o valor a ser removido: ";
                cin >> valor;
                cout << "Digite o valor de referencia: ";
                cin >> refe;
                if(remover_apos(l, valor, refe)){
                    cout << "Valor removido com sucesso!";
                } else{
                    cout << "Este valor ou valor de referencia nao existe";
                }
                break;
            case 11:
                cout << "Lista invertida:\n";
                lista_invertida(l);
                break;
            default:
                cout << "Opcao invalida.";
                break;
        }
    }
    return 0;
}

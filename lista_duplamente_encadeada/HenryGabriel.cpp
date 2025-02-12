#include <iostream>

using namespace std;

struct nodo{
    string info;
    nodo *eloa;
    nodo *elop;
};

struct lista_dupla{
    nodo *inicio;
    nodo *fim;
    int tamanho;
};

//definição do Descritor
void inicializacao(lista_dupla &ld){
    ld.inicio = ld.fim = NULL;
    ld.tamanho = 0;
}

//I - Incluir no Início da lista: Faz a leitura de um valor e inclui ele no início da lista.
bool incluir_inicio(lista_dupla &ld, string valor){
    nodo *novo = new nodo;  // Criando novo nodo
    if (novo == NULL){
        return false;
    }
    // Atribuindo valores do nodo
    novo->info = valor;
    novo->elop = ld.inicio;

    if(ld.inicio == NULL && ld.fim == NULL){ // A lista é vazia?
        ld.inicio = ld.fim = novo;
    }
    // Atribuindo valores
    ld.inicio = novo;
    ld.tamanho++;
    return true;
}

//F – Incluir no Fim da lista: Faz a leitura de um valor e inclui ele no fim da lista
bool incluir_fim(lista_dupla &ld, string valor){
    nodo *novo = new nodo; // Criando novo nodo
    if (novo == NULL){
        return false;
    }
    // Atribuindo valores do nodo
    novo->info = valor;
    novo->elop = NULL;
    novo->eloa = ld.fim;

    if(ld.inicio == NULL && ld.fim == NULL){ //A lista é vazia?
        ld.inicio = novo;
    } else{
        ld.fim->elop = novo;
    }
    ld.fim = novo;
    ld.tamanho++;
    return true;
}

//V – Incluir antes de um determinado valor: Faz a leitura de um valor e de um valor de referência. Inclui o valor lido antes do valor de
//referência, se este existe.
bool incluir_antes_do_valor(lista_dupla &ld, string valor, string refer){
    nodo *novo = new nodo;  // Criando novo nodo
    nodo *it = new nodo;  // Interador
    it = ld.inicio; // Começa com o início
    while (it != NULL){
        if (it->info == refer){ // Valor do interador é igual da referência
            break;
        }
        it = it->elop; // nodo interador receberá seu elo posterior
    }
    if(it == NULL){ // não encontrou o valor de referência
        return false;
    } 
    novo->info = valor; // Atribuindo valores 
    if(it == ld.inicio){ // O valor de referência é o primeiro da lista?
        novo->elop = ld.inicio;
        novo->eloa = NULL;
        ld.inicio->eloa = novo;
        ld.inicio = novo;
    }else{
        novo->elop = it;
        novo->eloa = it->eloa;
        it->eloa->elop = novo;
        it->eloa = novo;
    }
    ld.tamanho++;
    return true;
}

//A – Mostrar a lista do início para o fim: Mostra na tela toda as informações da lista, percorrendo-a do início até o fim
void mostrar_lista(lista_dupla ld){
    nodo *it;
    it = ld.inicio;
    while(it != NULL){
        cout << it->info << endl;
        it = it->elop;
    }
}

//R – Retirar de um valor da lista: Faz a leitura de um valor e o retira da lista. Deve retirar somente a primeira ocorrência
//deste valor na lista.
bool retirada_valor(lista_dupla &ld, string valor){
    nodo *it = ld.inicio;
    nodo *ant = NULL;

    while(it != NULL){
        if(valor == it->info) break;
        ant = it;
        it = it->elop;
    }
    if (it == NULL)return false; // Não encontrou o valor

    if (it == ld.inicio && it == ld.fim){ // O valor a retirar é o único valor da lista?
        ld.inicio = ld.fim = NULL;
    } else{
        if(it == ld.inicio){ // O valor a ser retirado é o primeiro da lista?
            ld.inicio = it->elop;
            if(ld.inicio != NULL){
                ld.inicio->eloa = NULL;
            }
        } else if (it == ld.fim){ // O valor a ser retirado é o último da lista?
            ant->elop = NULL;
            ld.fim = ant;
        } else{
            ant->elop = it->elop;
            it->elop->eloa = ant;
        } 
    }
    ld.tamanho--;
    delete it;
    return true;
}

//E – Esvaziar a lista: Esvazia a lista, retirando os valores, um a um, do início para o fim. Cada valor que for
//sendo retirado deve ser mostrado na tela.
void esvaziar_lista(lista_dupla &ld){
    nodo *it = new nodo;
    it = ld.inicio;    
    while (ld.inicio != NULL && ld.fim != NULL){
        cout << "Removendo... " + it->info + "\n";
        ld.inicio = it->elop;
        delete it;
        it = it->elop;
        ld.tamanho--;
    }
    ld.inicio = ld.fim = NULL;
}

int main(){
    lista_dupla ld;
    inicializacao(ld);

    char opcao;
    string valor;
    string refer;

    while(1){
        cout << "\n\nMENU\n\n";
        cout << "------\n";
        cout << "I - Incluir no Inicio da lista \n";
        cout << "F - Incluir no Fim da lista\n";
        cout << "V - Incluir antes de um determinado valor\n";
        cout << "A - Mostrar a lista do inicio para o fim\n";
        cout << "R - Retirar um valor da lista\n";
        cout << "E - Esvaziar a lista\n";
        cout << "X - Finalizar\n";
        cout << "Sua opcao:";

        cin >> opcao;
        cin.ignore(); 
        switch(opcao){
            case 'I': 
            case 'i':
                cout << "INCLUSAO NO INICIO DA LISTA\n\nValor a ser incluido: ";
                getline(cin, valor);
                if (incluir_inicio(ld, valor)){
                    cout << "Inclusao efetuada com sucesso!";
                } else{
                    cout << "Inclusao nao efetuada!";
                }
                break;

            case 'F': 
            case 'f':
                cout <<"INCLUSAO NO FIM DA LISTA\n\nValor a ser incluido: ";
                getline(cin, valor);
                if(incluir_fim(ld, valor)){
                    cout << "\nInclusao efetuada com sucesso!";
                } else{
                    cout << "\nInclusao nao efetuada!";
                }
                break;

            case 'V':
            case 'v': 
                if (ld.inicio == NULL){
                    cout << "A lista esta vazia, por favor, adiciona um elemento antes.";
                    break;
                }
                cout << "Digite o valor a ser incluido: ";
                getline(cin, valor);
                cout << "Digite o valor de referencia: ";
                getline(cin, refer);
                if(incluir_antes_do_valor(ld, valor, refer)){
                    cout<<"Elemento adicionado com sucesso!";
                } else{
                    cout<<"Elemento de referencia nao existe";
                }
                break;
                    
            case 'A':
            case 'a': 
                cout << "\nLISTA:\n";
                if (ld.inicio == NULL){
                    cout << "Lista vazia";
                } else{
                    mostrar_lista(ld);
                }
                break;

            case 'R': 
            case 'r':
                if (ld.inicio == NULL){
                    cout << "Nao ha nada a ser retirado. Lita VAZIA!\n";
                    break;
                }
                cout << "Digite  valor a ser retirado: ";
                getline(cin, valor);
                if(retirada_valor(ld, valor)){
                    cout << "Elemento retirado com sucesso!";
                } else{
                    cout << "Elemento nao foi possivel ser retirado!";
                }
                break;

            case 'E':
            case 'e': 
                if(ld.inicio == NULL){
                    cout << "Lista VAZIA";
                    break;
                }
                cout << "\nESVAZIANDO A LISTA:\n";
                esvaziar_lista(ld);
                break;

            // X – Finalizar: Termina o programa.
            case 'X': 
            case 'x':
                return 0;
        }
    }
    return 0;
}
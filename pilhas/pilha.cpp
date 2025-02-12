#include <iostream>
#include <string>
using namespace std;

struct nodo{
    string info;
    nodo *elo;
};
struct pilha{
    nodo *topo;
    nodo *base;
    int tamanho;
};
bool inclusao(pilha &p, string valor){
    nodo *novo = new nodo;
    if(novo == NULL){
        return false;
    }
    if (p.topo == NULL){
        p.base = novo;
    }
    novo->info = valor;
    novo->elo = p.topo;
    p.topo = novo;
    p.tamanho++;
    return true;
}
bool retirar(pilha &p){
    if(p.topo == NULL){
        return false;
    }
    nodo *aux = p.topo->elo;
    delete p.topo;
    p.topo = aux;
    p.tamanho--;
    return true;
}

void inicializacao(pilha &p){
        p.base = NULL;
        p.topo = NULL;
        p.tamanho = 0;
}
void mostrar(pilha p){
    if(p.topo == NULL){
        cout << "Lista Vazia!!!\n";
        return;
    }
    nodo *aux = p.topo;
    cout << "Itens na pilha, comecando pelo topo...\n";
    while (aux != NULL){
        cout << aux->info + " \n";
        aux = aux->elo;
    }
    cout << "\n";
}

void consulta(pilha p){
    if(p.topo == NULL){
        cout << "Lista Vazia!!!\n\n";
        return;
    }
    cout << "Valor no topo da pilha: " + p.topo->info + "\n\n";
    return;
}

int main(){
    pilha p;
    inicializacao(p);
    cout << "Agora letesgo\n";
    string valor = "Batata";
    if (inclusao(p, valor)){
        cout << valor + " foi incluido na pilha com sucesso\n";
    }
    valor = "Espinafre";
    if (inclusao(p, valor)){
        cout << valor + " foi incluido na pilha com sucesso\n";
    }
    valor = "Tomate";
    if (inclusao(p, valor)){
        cout << valor + " foi incluido na pilha com sucesso\n\n";
    }
    mostrar(p);
    consulta(p);
    if(retirar(p)){
        cout << "Elemento removido com sucesso\n";
    }
    mostrar(p);
    return 0;
}

/*
Pilhas são estruturas de dados que armazenam os elementos em um formato sequencial, empilhando um item acima do outro (imagine uma pilha de pratos, por exemplo). Sempre que um novo elemento é inserido (ou empilhado) damos a ele o nome de “topo”, pois é o primeiro elemento ao qual teremos acesso.

Segue um padrão conhecido como LIFO (Last In First Out), onde o último a entrar será o primeiro a sair. Imagine uma pilha de pratos, sempre que um prato é “empilhado” sob o outro, este último prato empilhado é o mais próximo (ou o topo da pilha) e, caso precisarmos remover um prato, é o prato do topo que será removido da estrutura.

Entre os exemplos de uso de uma pilha em um sistema, podemos citar a navegação entre páginas web ou até mesmo o mecanismo de desfazer/refazer dos editores de texto.
*/
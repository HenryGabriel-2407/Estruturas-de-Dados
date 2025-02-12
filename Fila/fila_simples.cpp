#include <iostream>
using namespace std;

struct nodo{
    string info;
    nodo* next;
};
struct fila{
    nodo* inicio;
    nodo* fim;
    int tamanho;
};

void inicializar(fila &fila){
    fila.inicio = NULL;
    fila.fim = NULL;
    fila.tamanho = 0;
};

bool inclusao(fila &fila, string valor){
    nodo* novo = new nodo;
    if(novo == NULL){
        return false;
    }
    novo->info = valor;
    novo->next = NULL;
    if(fila.inicio == NULL){
        fila.inicio = novo;
    }
    else{
        fila.fim->next = novo;
    }
    fila.fim = novo;
    fila.tamanho++;
    return true;
}
bool retirar(fila &fila){
    nodo* aux = fila.inicio;
    if(aux == NULL){
        return false;
    }
    fila.inicio = fila.inicio->next;
    if(fila.inicio == NULL){
        fila.fim = NULL;
    }
    fila.tamanho--;
    delete aux;
    return true;
}
void mostrar(fila fila){
    nodo* aux = fila.inicio;
    while(aux != NULL){
        cout << aux->info << endl;
        aux = aux->next;
    }
}
void consulta(fila fila){
    if(fila.inicio == NULL){
        cout << "Fila vazia" << endl;
        return;
    }
    cout << fila.inicio->info << endl;
}

int main(){
    fila fila;
    inicializar(fila);
    string valor;
    char opcao;
    while(1){
        cout << "\n\nMENU\n\n";
        cout << "------\n";
        cout << "I - Incluir\n";
        cout << "M - Mostrar\n";
        cout << "R - Retirar um valor da lista\n";
        cout << "C - Consultar\n";
        cout << "X - Finalizar\n";
        cout << "Sua opcao:";

        cin >> opcao;
        cin.ignore(); 
        switch(opcao){
            case 'I': 
            case 'i':
                cout << "INCLUSAO\n\nValor a ser incluido: ";
                getline(cin, valor);
                if (inclusao(fila, valor)){
                    cout << "Inclusao efetuada com sucesso!";
                } else{
                    cout << "Inclusao nao efetuada!";
                }
                break;

            case 'M': 
            case 'm':
                cout <<"Mostar: " << endl;
                mostrar(fila);
                break;

            case 'R':
            case 'r': 
                if(retirar(fila)){
                    cout << "Remocao efetuada com sucesso!"<<endl;
                }
                else{
                    cout << "Remocao nao efetuada!"<<endl;
                }
                break;
                    
            case 'C':
            case 'c': 
                consulta(fila);
                break;

            // X – Finalizar: Termina o programa.
            case 'X': 
            case 'x':
                return 0;
        }
    }
    return 0;
}
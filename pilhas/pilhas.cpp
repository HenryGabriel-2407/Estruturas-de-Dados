#include <iostream>
#include <stack>

using namespace std;

struct nodo{
    int matricula;
    string nome;
    float notas[3];
};


int main(){
    stack<nodo> pilha;
    nodo aux;
    char opcao;
    while (true){
        cout <<"\n\nMENU\n\nI - Incluir\nR - Retirar\nC - Consultar\nF-Finaliza\n";
        cin >> opcao;
        switch (opcao)
        {
        case 'i':
        case 'I':
            cout << "\nDigite Matricula: ";
            cin >> aux.matricula;
            cout << "\nDigite seu nome: ";
            cin >> aux.nome;
            for(int i=0;i< 3; i++){
                cout << "Digite nota "<< i <<":";
                cin >> aux.notas[i];
            }
            pilha.push(aux);
            cout << "\n\n***Empilhado***\n\n";
            break;
        case 'R':
        case 'r':
            if (pilha.empty()){
                cout << "A pilha está vazia.\n";
                break;
            }
            cout << "\n\nRetirando o item...\n\n";
            if (!pilha.empty()){
                nodo consult = pilha.top();
                cout << "Matricula: " << consult.matricula << "\n";
                cout << "Nome: " << consult.nome << "\n";
                cout << "Notas: ";
                for (int i = 0; i < 3; i++){
                    cout << consult.notas[i] <<"; ";
                }
                cout << "\n";
            }
            pilha.pop();
            cout << "\n Matricula retirada!!!...\n\n";
            break;
        case 'C':
        case 'c':
            if (!pilha.empty()){
                nodo consult = pilha.top();
                cout << "Matricula: " << consult.matricula << "\n";
                cout << "Nome: " << consult.nome << "\n";
                cout << "Notas: ";
                for (int i = 0; i < 3; i++){
                    cout << consult.notas[i] <<"; ";
                }
                cout << "\n";
            }else {
                cout << "A pilha está vazia.\n"; 
            }
            break;
        case 'F':
        case 'f':
            return false;
            break;
        default:
            continue;
        }
    }
    
    return 0;
}
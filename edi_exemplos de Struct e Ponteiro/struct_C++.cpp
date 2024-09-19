#include <iostream>
#include <string>

using namespace std;

#define TAM 5

int main() {
    struct reg {
        string nome;
        int    idade;
        char   sexo;
        float  altura;
        bool   status;
    };

    struct reg tabela[ TAM ];
    
    int opcao, i, indice;

    for (i = 0; i < TAM; i++)
        tabela[i].status = false; // false eh vazio

    while (true) {
        cout << "\nMENU\n----\n";
        cout << "1 - Incluir\n";
        cout << "2 - Mostrar\n";
        cout << "3 - Retirar\n";
        cout << "0 - Sair\n";
        cout << "----\nDigite sua opcao :";
        cin >> opcao;

        if (opcao == 0)
            break;

        if (opcao == 1) {
            for (i = 0; i < TAM; i++) { // busca 1 livre
                if (tabela[i].status == false)
                    break;
            }
            if (i == TAM)
                cout << "\n\nTABELA CHEIA\n\n";
            else {
                cout << "\nINCLUIR\n";
                cout << "Nome  : ";
                cin >> tabela[i].nome;
                cout << "Idade : ";
                cin >> tabela[i].idade;
                cout << "Sexo  : ";
                cin >> tabela[i].sexo;
                cout << "Altura: ";
                cin >> tabela[i].altura;
                tabela[i].status = true;
                cout << "\nInclusao no indice [" << i << "]\n\n";
            }
        }

        if (opcao == 2) {
            cout << "\nMOSTRAR\n\n";
            for (i = 0; i < TAM; i++) {
                if (tabela[i].status == true) {
                    cout << "Indice  : [" << i << "]\n";
                    cout << "Nome    :  " << tabela[i].nome << "\n";
                    cout << "Idade   :  " << tabela[i].idade << "\n";
                    cout << "Sexo    :  " << tabela[i].sexo << "\n";
                    cout << "Altura  :  " << tabela[i].altura << "\n\n";
                }
            }
        }

        if (opcao == 3) {
            cout << "\nRETIRAR\n\n";
            cout << "\n\nDe qual indice retirar? ";
            cin >> i;
            if (i < 0 || i >= TAM)
                cout << "\nIndice invalido\n";
            else {
                if (tabela[i].status == true) {
                    tabela[i].status = false;
                    cout << "\n\nExcluido\n\n";
                } else
                    cout << "\n\nIndice ja vazio\n\n";
            }
        }
    }
    return 0;
}

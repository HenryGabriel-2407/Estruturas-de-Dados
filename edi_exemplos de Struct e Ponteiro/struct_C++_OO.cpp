#include <iostream>
#include <string>

using namespace std;

#define TAM 5

struct Registro {
    string nome;
    int    idade;
    char   sexo;
    float  altura;
    bool   status;
};

class TabelaRegistros {
private:
    Registro tabela[ TAM ];
public:
    TabelaRegistros() {
        for (int i = 0; i < TAM; i++)
            tabela[i].status = false;
    }

    bool incluir(Registro aux) {
        int i;
        for (i = 0; i < TAM; i++) {
            if (tabela[i].status == false)
                break;
        }
        if (i == TAM)
            return false;
        else {
            tabela[ i ] = aux;
            tabela[ i ].status = true;
            cout << "\nInclusao no indice [" << i << "]\n\n";
        }
        return true;
    }

    void mostrar() {
        cout << "\nMOSTRAR\n\n";
        for (int i = 0; i < TAM; i++) {
            if (tabela[i].status == 1) {
                cout << "\nIndice  : [" << i << "]\n";
                cout << "Nome    : " << tabela[i].nome << "\n";
                cout << "Idade   : " << tabela[i].idade << "\n";
                cout << "Sexo    : " << tabela[i].sexo << "\n";
                cout << "Altura  : " << tabela[i].altura << "\n";
            }
        }
    }

    bool retirar( int i ) {
       
         if (tabela[i].status == true) {
             tabela[i].status = false;
             cout << "\n\nExcluido\n\n";
         } else
            return false;
        return true;
    }
};

int main() {
    TabelaRegistros tabela;
    Registro aux;
    int i;

    while (true) {
        cout << "\nMENU\n----\n";
        cout << "1 - Incluir\n";
        cout << "2 - Mostrar\n";
        cout << "3 - Retirar\n";
        cout << "0 - Sair\n";
        cout << "----\nDigite sua opcao : ";        int opcao;
        cin >> opcao;

        if (opcao == 0)
            break;

        switch (opcao) {
            case 1:
                cout << "Nome  : "; cin >> aux.nome;
                cout << "Idade : "; cin >> aux.idade;
                cout << "Sexo  : "; cin >> aux.sexo;
                cout << "Altura: "; cin >> aux.altura;

                if( tabela.incluir( aux ) == false )
                    cout << "\nErro na inclusao!\n";
                break;
                
            case 2:
                tabela.mostrar();
                break;
                
            case 3:
                cout << "\nRETIRAR\n\n";
                cout << "\n\nDe qual indice retirar? ";
                cin >> i;
                if (i < 0 || i >= TAM)
                    cout << "\nIndice invalido\n";
                else {
                    if( tabela.retirar( i ) == false )
                        cout << "\nErro na retirada!\n";
                }
                break;
                    
            default:
                cout << "Opcao invalida\n";
        }
    }

    return 0;
}

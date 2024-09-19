//  main.c
//  exemplo_struct
//
//  Created by Evandro Luis Viapiana on 14/08/23.
//
// - utiliza tipo de dados definido pelo usuário (o reg)
// - utiliza alocação estática de memória (tamanho definido e imutável do vetor)
// - utiliza contiguidade física

#define TAM 5

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {

    // definicao de um tipo de dado de nome reg, composto por 4 campos
    struct reg{
        char  nome[ 128 ];
        int   idade;
        char  sexo;
        float altura;
        int   status;
    };
    
    struct reg tabela[ TAM ];
    int opcao, i, indice;
    
    //inicializar o status de todos os registros da tabela para 0 - registro vazio
    for( i = 0 ; i < TAM ; i++ )
        tabela[ i ].status = 0;
    
    while( 1 )
    {
        printf("\nMENU\n----\n");
        printf("1 - Incluir\n");
        printf("2 - Mostrar\n");
        printf("3 - Retirar\n");
        printf("0 - Sair\n");
        printf("----\nDigite sua opcao : ");
        fflush(stdin);
        scanf("%d",&opcao);
        
        if( opcao == 0 )
            break;
        
        if( opcao == 1 )
        {
            for( i = 0 ; i < TAM ; i++ ) // achar um registro vazio para colocar nele
            {
               if( tabela[ i ].status == 0 )
                   break;
            }
            if( i == TAM )
                printf("\n\nTABELA CHEIA\n\n");
            else
            {
                printf("\nINCLUIR\n");
                fflush(stdin);
                printf("Nome  : ");scanf("%s",tabela[i].nome );
                fflush(stdin);
                printf("Idade : ");scanf("%d",&tabela[i].idade );
                fflush(stdin);
                printf("Sexo  : ");scanf("%c",&tabela[i].sexo );
                fflush(stdin);
                printf("Altura: ");scanf("%f",&tabela[i].altura );
                tabela[ i ].status = 1;
                printf("\nInclusao no indice [%d]\n\n", i );
            }
        }
        
        if( opcao == 2 )
        {
            printf("\nMOSTRAR\n\n");
            for( i = 0 ; i < TAM ; i++ )
            {
                if( tabela[ i ].status == 1 )
                {
                    printf("Indice  : [%d]\n"   , i );
                    printf("Nome    :  %s\n"   , tabela[i].nome );
                    printf("Idade   :  %d\n"   , tabela[i].idade );
                    printf("Sexo    :  %c\n"   , tabela[i].sexo );
                    printf("Altura  :  %f\n\n" , tabela[i].altura );
                }
            }
        }
        
        if( opcao == 3 )
        {
            printf("\nRETIRAR\n\n");
            printf("\n\nDe qual indice retirar? ");
            fflush(stdin);
            scanf("%d",&i);
            if( i < 0 || i >= TAM )
                printf("\nIndice invalido\n");
            else{
                    if( tabela[ i ].status == 1  )
                    {
                        tabela[ i ].status = 0;
                        printf("\n\nExcluido\n\n");
                    }
                    else
                        printf("\n\nIndice ja vazio\n\n");
            }
        }
    }
    return 0;
}

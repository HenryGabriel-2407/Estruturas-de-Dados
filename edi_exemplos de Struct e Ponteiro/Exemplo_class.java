
package exemplo_class;

import java.util.Scanner;

public class Exemplo_class {
    
    public static void main(String[] args) {
        
        final int TAM = 5;

        class Registro {
            String  nome;
            int     idade;
            char    sexo;
            float   altura;
            boolean status;
        }

        Registro[] tabela = new Registro[TAM];
        int opcao, i, indice;

        for (i = 0; i < TAM; i++)
            tabela[i] = new Registro();

        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\nMENU\n----\n");
            System.out.println("1 - Incluir");
            System.out.println("2 - Mostrar");
            System.out.println("3 - Retirar");
            System.out.println("0 - Sair\n");
            System.out.println("----\nDigite sua opcao : ");

            opcao = scanner.nextInt();

            if (opcao == 0)
                break;

            if (opcao == 1) {
                for (i = 0; i < TAM; i++) {
                    if (tabela[i].status == false)
                        break;
                }
                if (i == TAM)
                    System.out.println("\n\nTABELA CHEIA\n\n");
                else {
                    System.out.println("\nINCLUIR");
                    scanner.nextLine();
                    System.out.print("Nome  : "); tabela[i].nome = scanner.nextLine();
                    System.out.print("Idade : "); tabela[i].idade = scanner.nextInt();
                    scanner.nextLine();
                    System.out.print("Sexo  : "); tabela[i].sexo = scanner.next().charAt(0);
                    scanner.nextLine();
                    System.out.print("Altura: "); tabela[i].altura = scanner.nextFloat();
                    tabela[i].status = true;
                    System.out.println("\nInclusao no indice [" + i + "]\n");
                }
            }

            if (opcao == 2) {
                System.out.println("\nMOSTRAR\n");
                for (i = 0; i < TAM; i++) {
                    if (tabela[i].status == true) {
                        System.out.println("Indice  : [" + i + "]");
                        System.out.println("Nome    :  " + tabela[i].nome);
                        System.out.println("Idade   :  " + tabela[i].idade);
                        System.out.println("Sexo    :  " + tabela[i].sexo);
                        System.out.println("Altura  :  " + tabela[i].altura + "\n");
                    }
                }
            }

            if (opcao == 3) {
                System.out.println("\nRETIRAR\n");
                System.out.print("\n\nDe qual indice retirar? ");
                i = scanner.nextInt();
                if (i < 0 || i >= TAM)
                    System.out.println("\nIndice invalido\n");
                else {
                    if (tabela[i].status == true) {
                        tabela[i].status = false;
                        System.out.println("\n\nExcluido\n");
                    } else
                        System.out.println("\n\nIndice ja vazio\n");
                }
            }
        }

        scanner.close();
    }
}

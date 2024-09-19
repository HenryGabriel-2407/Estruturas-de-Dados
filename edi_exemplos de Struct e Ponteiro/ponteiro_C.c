#include <stdio.h>

int main( void ) {

    int a , b , *ptr1 , *ptr2 , *ptr3;
    
    a = 8;
    printf("Valor de a    : %d\n" , a );
    printf("Endereco de a : %x\n\n" , &a ); //o uso do & indica que deseja-se acessar o endereço em hexadecimal da variável a
    
    ptr1 = &a; // ptr1 recebe o endereço hexadecimal da variável a
    printf("End apontado por ptr                           : %x\n" , ptr1 ); // mostra o conteúdo do ponteiro ptr1, que é endereço hexadecimal da variável a
    printf("Valor que esta no end apontado por ptr (*ptr1) : %d\n\n" , *ptr1 ); // o astrerisco antes de ptr1 indica que deve ser acessado o endereço hexadecimal que está em ptr1 e a partir deste endereço mostrar o valor contido naquele endereço, que neste caso é o valor da variável a

    ptr2 = ptr1; // ptr2 recebe o endereço hexadecimal que está em ptr1. é uma atribuição simples de endereço para uma variável ponteiro, que é um endereço
    printf("End apontado por ptr2                          : %x\n" , ptr2 ); // mostra o conteúdo do ponteiro ptr2, que é o mesmo endereço de ptr1, que por sua vez é endereço hexadecimal da variável a
    printf("Valor que esta no end apontado por ptr (*ptr2) : %d\n\n" , *ptr2 );// o astrerisco antes de ptr2 indica que deve ser acessado o endereço hexadecimal que está em ptr2 e a partir deste endereço mostrar o valor contido naquele endereço, que é o mesmo endereço de ptr1, que por sua vez é endereço hexadecimal da variável a

    b = 100;
    
    ptr3 = &b; // ptr3 recebe o endereço hexadecimal da variável b
    printf("End apontado por ptr3                          : %x\n" , ptr3 ); // mostra o conteúdo do ponteiro ptr3, que é endereço hexadecimal da variável b
    printf("Valor que esta no end apontado por ptr (*ptr3) : %d\n\n" , *ptr3 ); // o astrerisco antes de ptr3 indica que deve ser acessado o endereço hexadecimal que está em ptr3 e a partir deste endereço mostrar o valor contido naquele endereço, que neste caso é o valor da variável b
    
    *ptr1 = *ptr3; // ptr1 recebe o valor contigo no endereço apontado por ptr3, que neste caso é o valor da variável b. como ambos os ponterios tem o asterisco antes da variável significa que é uma atribuição de valor e não de endereço
    
    printf("Valor de a : %d\n\n" , a );
    
    return 0;
}


#include <iostream>
using namespace std;

int main() {

    int a , b , *ptr1 , *ptr2 , *ptr3;
    
    a = 8;
    
    cout << "Valor de a    : " << a  << endl;
    cout << "Endereco de a : " << &a << endl << endl; //o uso do & indica que deseja-se acessar o endereço em hexadecimal da variável a
    
    ptr1 = &a; // ptr1 recebe o endereço hexadecimal da variável a
    cout << "End apontado por ptr                           : " << ptr1 << endl; // mostra o conteúdo do ponteiro ptr1, que é endereço hexadecimal da variável a
    cout << "Valor que esta no end apontado por ptr (*ptr1) : " << *ptr1 << endl<<endl; // o astrerisco antes de ptr1 indica que deve ser acessado o endereço hexadecimal que está em ptr1 e a partir deste endereço mostrar o valor contido naquele endereço, que neste caso é o valor da variável a

    ptr2 = ptr1; // ptr2 recebe o endereço hexadecimal que está em ptr1. é uma atribuição simples de endereço para uma variável ponteiro, que é um endereço
    cout << "End apontado por ptr2                          : " << ptr2 << endl; // mostra o conteúdo do ponteiro ptr2, que é o mesmo endereço de ptr1, que por sua vez é endereço hexadecimal da variável a
    cout << "Valor que esta no end apontado por ptr (*ptr2) : " << *ptr2 << endl<<endl;// o astrerisco antes de ptr2 indica que deve ser acessado o endereço hexadecimal que está em ptr2 e a partir deste endereço mostrar o valor contido naquele endereço, que é o mesmo endereço de ptr1, que por sua vez é endereço hexadecimal da variável a

    b = 100;
    
    ptr3 = &b; // ptr3 recebe o endereço hexadecimal da variável b
    cout << "End apontado por ptr3                          : " << ptr3 << endl; // mostra o conteúdo do ponteiro ptr3, que é endereço hexadecimal da variável b
    cout << "Valor que esta no end apontado por ptr (*ptr3) : " << *ptr3 << endl<<endl; // o astrerisco antes de ptr3 indica que deve ser acessado o endereço hexadecimal que está em ptr3 e a partir deste endereço mostrar o valor contido naquele endereço, que neste caso é o valor da variável b
    
    *ptr1 = *ptr3; // ptr1 recebe o valor contigo no endereço apontado por ptr3, que neste caso é o valor da variável b. como ambos os ponterios tem o asterisco antes da variável significa que é uma atribuição de valor e não de endereço
        
    cout << "Valor de a : " << a  << endl;
    
    return 0;
}

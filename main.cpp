#include <iostream>
#include "FilaSequencial.hpp"

using std::cout;
using std::endl;

int main()
{
    int tamanhoMax = 10;
    FilaSequencial<int> fila(tamanhoMax);

    cout << "A Fila esta vazia: " << fila.isVazia() << "\n";
    cout << "A Fila esta cheia: " << fila.isCheia() << "\n";
    
    for (int i = 0; i < tamanhoMax; ++i)
    {
        cout << "Inserindo no final da Fila: " << i+1 << "\n";
        fila.inserir(i+1);
    }

    cout << "A Fila esta vazia: " << fila.isVazia() << "\n";
    cout << "A Fila esta cheia: " << fila.isCheia() << "\n";

    for (int i = 0; i < 2; ++i)
    {
        cout << "Primeiro elemento da Fila: " << fila.primeiro() << "\n";
        cout << "Removendo do inicio da Fila: " << fila.remover() << "\n";
    }

    cout << "Primeiro elemento da Fila: " << fila.primeiro() << "\n";

    return 0;
}
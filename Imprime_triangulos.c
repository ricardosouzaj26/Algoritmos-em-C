#include <stdio.h>
#include <stdlib.h>

// Fun��o recursiva que imprime 'n' asteriscos na mesma linha
void imprimeAsterisco(int n)
{
    if(n <= 0) return;
    printf("*");
    imprimeAsterisco(n - 1);
}

// Fun��o recursiva que imprime um tri�ngulo crescente
void triangulo(int n)
{
    if(n <= 0) return;
    triangulo(n - 1);   // chama para linhas menores primeiro
    printf("\n");
    imprimeAsterisco(n);
}

// Fun��o recursiva que imprime um tri�ngulo decrescente
void trianguloInvertido(int n)
{
    if(n <= 0) return;
    imprimeAsterisco(n);
    printf("\n");
    trianguloInvertido(n - 1); // chama para linhas menores depois
}

int main()
{
    int indice = 12;
    trianguloInvertido(indice); // imprime tri�ngulo invertido
    printf("\n");
    triangulo(indice);          // imprime tri�ngulo normal
    return 0;
}

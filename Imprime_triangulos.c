#include <stdio.h>
#include <stdlib.h>

// Função recursiva que imprime 'n' asteriscos na mesma linha
void imprimeAsterisco(int n)
{
    if(n <= 0) return;
    printf("*");
    imprimeAsterisco(n - 1);
}

// Função recursiva que imprime um triângulo crescente
void triangulo(int n)
{
    if(n <= 0) return;
    triangulo(n - 1);   // chama para linhas menores primeiro
    printf("\n");
    imprimeAsterisco(n);
}

// Função recursiva que imprime um triângulo decrescente
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
    trianguloInvertido(indice); // imprime triângulo invertido
    printf("\n");
    triangulo(indice);          // imprime triângulo normal
    return 0;
}

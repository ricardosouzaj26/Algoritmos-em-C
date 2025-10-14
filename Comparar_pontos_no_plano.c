#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

#define Quantidade_pontos 2

// Estrutura que representa um ponto no plano cartesiano
struct pos
{
    char ponto;
    float posx;
    float posy;
};

//Cria um ponto com coordenadas e r�tulo definidos
struct pos criarpontos(char ponto, float posx, float posy)
{
    struct pos p;
    p.ponto = ponto;
    p.posx = posx;
    p.posy = posy;
    return p;
}

//Compara dois pontos e imprime a dire��o e a dist�ncia entre eles
void comparapontos(struct pos p1, struct pos p2)
{
    int direcao;
    float distancia;
    if(p1.posx > p2.posx)
    {
        direcao = 1;//p2 � direita de p1
    }
    else if(p1.posx < p2.posx)
    {
        direcao = -1;//p2 est� � esquerda p1
    }
    else direcao = 0;//p2 est� alinhado em X com p1

    distancia = sqrt(pow(p2.posx - p1.posx, 2)+pow(p2.posy - p1.posy, 2));//Calcula a dist�ncia Euclidiana

    //Resultados
    if(direcao < 0)
    {
        printf("O ponto %c est� a %.2f � esquerda do ponto %c\n\n", p2.ponto, distancia, p1.ponto);
    }
    else if(direcao > 0)
    {
        printf("O ponto %c est� a %.2f � direita do ponto %c\n\n", p2.ponto, distancia, p1.ponto);
    }
    else printf("Os pontos %c e %c est�o alinhados em X, com dist�ncia %.2f\n\n", p2.ponto, p1.ponto, distancia);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    //Cria os pontos
    struct pos pontos[Quantidade_pontos]=
    {
        criarpontos('A', 1, 100),
        criarpontos('B', 10, 10)
    };

    //Compara os pontos
    comparapontos(pontos[0], pontos[1]);
    return 0;
}

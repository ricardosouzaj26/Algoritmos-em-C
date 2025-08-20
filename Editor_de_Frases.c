#include <stdio.h>   // Biblioteca padrão para entrada e saída
#include <stdlib.h>  // Biblioteca padrão (usada aqui para system("cls||clear"))
#include <string.h>  // Biblioteca para manipulação de strings
#define MaxCaracteres 100 // Define o tamanho máximo da frase

// Declaração das funções utilizadas
void escolha(int entrada, char *frase);
int pergunta();
void subFrase(char *frase);
void subLetra(char *frase);

// Função que direciona a ação de acordo com a escolha do usuário
void escolha(int entrada, char *frase)
{
    switch(entrada)
    {
        case 1: // Substituir frase inteira
            subFrase(frase);
            printf("Frase atualizada: %s\n", frase);
        break;

        case 2: // Substituir letra específica
            subLetra(frase);
            printf("Frase atualizada: %s\n", frase);
        break;

        case 3: // Encerrar programa
            break;
    }
}

// Exibe o menu e garante que o usuário escolha uma opção válida
int pergunta()
{
    int entrada;
    do
    {
        printf("\n1 - Substituir frase inteira.\n2 - Substituir alguma letra da frase.\n3 - Encerrar Programa\n\n");
        scanf("%d", &entrada);
    }while(entrada != 1 && entrada != 2 && entrada != 3); // Só aceita 1, 2 ou 3
    return entrada;
}

// Substitui a frase inteira digitada pelo usuário
void subFrase(char *frase)
{
    char novaFrase[MaxCaracteres];
    getchar(); // Limpa o buffer do teclado (evita que o '\n' atrapalhe o fgets)

    printf("\nDigite a nova frase: ");
    fgets(novaFrase, MaxCaracteres, stdin); // Lê nova frase
    novaFrase[strcspn(novaFrase, "\n")] = '\0'; // Remove o '\n' do final
    strcpy(frase, novaFrase); // Copia nova frase para a variável principal

    printf("\n");
    system("cls||clear"); // Limpa a tela (funciona no Windows ou Linux)
}

// Substitui todas as ocorrências de uma letra por outra
void subLetra(char *frase)
{
    char alvo, alternativo, substituto;

    // Pergunta qual letra substituir
    printf("\nQual letra deseja substituir: ");
    scanf(" %c", &alvo);

    // Pergunta qual letra colocar no lugar
    printf("Qual letra deseja colocar no local: ");
    scanf(" %c", &substituto);
    printf("\n");

    // Se o usuário digitou letra maiúscula, gera alternativa minúscula
    if(alvo <= 'Z' && alvo >= 'A')
    {
        alternativo = alvo + 32; // Converte para minúscula
    }
    // Se o usuário digitou letra minúscula, gera alternativa maiúscula
    else if(alvo <= 'z' && alvo >= 'a')
    {
        alternativo = alvo - 32; // Converte para maiúscula
    }

    // Percorre a frase substituindo todas as ocorrências
    for(int i = 0; i < MaxCaracteres; i++)
    {
        if(frase[i] == alvo || frase[i] == alternativo)
        {
            frase[i] = substituto;
        }
    }
    system("cls||clear"); // Limpa a tela
}

int main()
{
    int entrada;
    char frase[MaxCaracteres];

    // Usuário digita a frase inicial
    printf("Digite uma frase: ");
    fgets(frase, MaxCaracteres, stdin);
    frase[strcspn(frase, "\n")] = '\0'; // Remove o '\n' do final

    // Loop principal do programa
    do
    {
        entrada = pergunta();      // Mostra menu e pega escolha
        escolha(entrada, frase);   // Executa ação correspondente
    }while(entrada != 3);          // Repete até usuário escolher sair

    return 0;
}

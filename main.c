#include <stdio.h>   // Biblioteca padr�o para entrada e sa�da
#include <stdlib.h>  // Biblioteca padr�o (usada aqui para system("cls||clear"))
#include <string.h>  // Biblioteca para manipula��o de strings
#define MaxCaracteres 100 // Define o tamanho m�ximo da frase

// Declara��o das fun��es utilizadas
void escolha(int entrada, char *frase);
int pergunta();
void subFrase(char *frase);
void subLetra(char *frase);

// Fun��o que direciona a a��o de acordo com a escolha do usu�rio
void escolha(int entrada, char *frase)
{
    switch(entrada)
    {
        case 1: // Substituir frase inteira
            subFrase(frase);
            printf("Frase atualizada: %s\n", frase);
        break;

        case 2: // Substituir letra espec�fica
            subLetra(frase);
            printf("Frase atualizada: %s\n", frase);
        break;

        case 3: // Encerrar programa
            break;
    }
}

// Exibe o menu e garante que o usu�rio escolha uma op��o v�lida
int pergunta()
{
    int entrada;
    do
    {
        printf("\n1 - Substituir frase inteira.\n2 - Substituir alguma letra da frase.\n3 - Encerrar Programa\n\n");
        scanf("%d", &entrada);
    }while(entrada != 1 && entrada != 2 && entrada != 3); // S� aceita 1, 2 ou 3
    return entrada;
}

// Substitui a frase inteira digitada pelo usu�rio
void subFrase(char *frase)
{
    char novaFrase[MaxCaracteres];
    getchar(); // Limpa o buffer do teclado (evita que o '\n' atrapalhe o fgets)

    printf("\nDigite a nova frase: ");
    fgets(novaFrase, MaxCaracteres, stdin); // L� nova frase
    novaFrase[strcspn(novaFrase, "\n")] = '\0'; // Remove o '\n' do final
    strcpy(frase, novaFrase); // Copia nova frase para a vari�vel principal

    printf("\n");
    system("cls||clear"); // Limpa a tela (funciona no Windows ou Linux)
}

// Substitui todas as ocorr�ncias de uma letra por outra
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

    // Se o usu�rio digitou letra mai�scula, gera alternativa min�scula
    if(alvo <= 'Z' && alvo >= 'A')
    {
        alternativo = alvo + 32; // Converte para min�scula
    }
    // Se o usu�rio digitou letra min�scula, gera alternativa mai�scula
    else if(alvo <= 'z' && alvo >= 'a')
    {
        alternativo = alvo - 32; // Converte para mai�scula
    }

    // Percorre a frase substituindo todas as ocorr�ncias
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

    // Usu�rio digita a frase inicial
    printf("Digite uma frase: ");
    fgets(frase, MaxCaracteres, stdin);
    frase[strcspn(frase, "\n")] = '\0'; // Remove o '\n' do final

    // Loop principal do programa
    do
    {
        entrada = pergunta();      // Mostra menu e pega escolha
        escolha(entrada, frase);   // Executa a��o correspondente
    }while(entrada != 3);          // Repete at� usu�rio escolher sair

    return 0;
}

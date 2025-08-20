#include <stdio.h>   // Biblioteca para entrada/sa�da padr�o
#include <stdlib.h>  // Biblioteca usada aqui para system("cls||clear")
#include <string.h>  // Biblioteca usada para manipula��o de strings

#define MaxProdutos 10  // Quantidade m�xima de produtos que podem ser cadastrados
#define Tamanho 50      // Tamanho m�ximo do nome de cada produto

// Fun��o que mostra o menu principal
void menu()
{
    printf("1 - Cadastrar Produto\n2 - Visualizar Produtos Cadastrados\n3 - Sair\n\n");
}

// Fun��o para cadastrar um produto (nome, quantidade e valor)
void CadastrarProduto(char nome[MaxProdutos][Tamanho], int quantidade[], double valor[], int indice)
{
    printf("\nQuantidade do Produto: ");
    scanf("%d", &quantidade[indice]);   // L� a quantidade
    printf("Valor do Produto: ");
    scanf("%lf", &valor[indice]);       // L� o valor unit�rio

    getchar(); // Limpa o buffer para n�o atrapalhar o fgets()
    printf("Nome do Produto: ");
    fgets(nome[indice], Tamanho, stdin); // L� o nome do produto
    nome[indice][strcspn(nome[indice], "\n")] = '\0'; // Remove o '\n' do final

    // Se a primeira letra do nome for min�scula, converte para mai�scula
    if(nome[indice][0] <= 'z' && nome[indice][0] >= 'a')
    {
        nome[indice][0] = nome[indice][0] - 32;
    }

    printf("\n");
    system("cls||clear"); // Limpa a tela (funciona no Windows e Linux)
}

// Fun��o que exibe todos os produtos cadastrados
void visualizarProdutos(char nome[MaxProdutos][Tamanho], int quantidade[], double valor[], int indice)
{
    printf("\n%-12s|%-20s|%-14s|%-14s|%-14s|" , "Produtos" , "Nome" , "Quantidade" , "Valor Unidade", "Valor Total");
    for(int i = 0; i < indice; i++)
    {
        printf("\n-------------------------------------------------------------------------------\n");
        printf("Produto %d   |%-20s|%-14d|R$%-12.2lf|R$%-12.2lf|\n",
               i + 1, nome[i], quantidade[i], valor[i], valor[i]*quantidade[i]);
    }
}

// Fun��o que pede ao usu�rio o n�mero do produto a ser alterado
int AlterarProdutos(char nome[MaxProdutos][Tamanho], int quantidade[], double valor[], int indice)
{
    printf("\nDigite o Numero do Produto a Ser Alterado (1 a %d): ", MaxProdutos);
    scanf("%d", &indice);
    return indice;
}

// Fun��o para mostrar mensagem de erro em caso de entrada inv�lida
void ErroDeEntrada()
{
    printf("\nDigito Invalido, Tente Novamente.\n\n");
}

// Fun��o principal
int main()
{
    int entrada, indice = 0; // entrada = op��o do menu, indice = n�mero de produtos cadastrados
    int quantidade[MaxProdutos];
    double valor[MaxProdutos];
    char nome[MaxProdutos][Tamanho];

    // Loop principal do programa (enquanto n�o sair e ainda n�o atingiu limite de produtos)
    do
    {
        menu();                // Mostra menu
        scanf("%d", &entrada); // L� a op��o escolhida

        switch(entrada)
        {
            case 1: // Cadastrar novo produto
            {
                CadastrarProduto(nome, quantidade, valor, indice);
                indice++; // Aumenta o contador de produtos
                break;
            }
            case 2: // Visualizar produtos cadastrados
            {
                if(indice != 0) // S� mostra se tiver produtos
                {
                    system("cls||clear");
                    visualizarProdutos(nome, quantidade, valor, indice);
                }
                else
                {
                    system("cls||clear");
                    printf("\nSem Produtos Cadastrados.\n");
                }
                printf("\n");
                break;
            }
            case 3: // Sair
                break;

            default: // Entrada inv�lida
            {
                system("cls||clear");
                ErroDeEntrada();
            }
        }
    }while(entrada != 3 && indice < MaxProdutos);

    // Se atingir o limite de produtos (MaxProdutos)
    if(indice == MaxProdutos)
    {
        do
        {
            visualizarProdutos(nome, quantidade, valor, MaxProdutos);

            printf("\n1 - Substituir Produto Previamente Cadastrado\n2 - Visualizar Produtos Cadastrados\n3 - Sair\n\n");
            scanf("%d", &entrada);

            switch(entrada)
            {
                case 1: // Alterar um produto existente
                    do
                    {
                        indice = AlterarProdutos(nome, quantidade, valor, MaxProdutos);
                        if(indice < 1 || indice > MaxProdutos)
                            ErroDeEntrada();
                    }while(indice < 1 || indice > MaxProdutos);

                    // Substitui o produto escolhido pelo usu�rio
                    CadastrarProduto(nome, quantidade, valor, indice - 1);
                    break;

                case 2: // Visualizar produtos novamente
                    visualizarProdutos(nome, quantidade, valor, MaxProdutos);
                    break;

                case 3: // Sair
                    break;

                default:
                    ErroDeEntrada();
            }
        }while(entrada != 3);
    }

    return 0;
}

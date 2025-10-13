#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define QUANTIDADE_ALUNOS 7

// Estrutura que armazena informações de um aluno
struct Alunoinfo {
    char nome[51];
    char RA[51];
    float n1, n2, media;
};

// Cria e retorna um aluno com base nos dados informados
struct Alunoinfo criaAluno(char *nome, char *RA, float n1, float n2) {
    struct Alunoinfo a;
    strcpy(a.nome, nome);
    strcpy(a.RA, RA);
    a.n1 = n1;
    a.n2 = n2;
    a.media = (n1 + n2) / 2;
    return a;
}

// Exibe as informações de um aluno
void descreveAluno(struct Alunoinfo a) {
    printf("Nome  : %s\n", a.nome);
    printf("RA    : %s\n", a.RA);
    printf("Nota 1: %.2f\n", a.n1);
    printf("Nota 2: %.2f\n", a.n2);
    printf("Média : %.2f\n\n", a.media);
}

void maiorMedia(struct Alunoinfo a[], int qtd) {
    int indice = 0;
    for (int i = 1; i < qtd; i++) {
        if (a[i].media > a[indice].media) {
            indice = i;
        }
    }
    printf("------- Aluno com Maior Média -------\n\n");
    descreveAluno(a[indice]);
}

void menorMedia(const struct Alunoinfo a[], int qtd) {
    int indice = 0;
    for (int i = 1; i < qtd; i++) {
        if (a[i].media < a[indice].media) {
            indice = i;
        }
    }
    printf("------- Aluno com Menor Média -------\n\n");
    descreveAluno(a[indice]);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    struct Alunoinfo alunos[QUANTIDADE_ALUNOS] = {
        criaAluno("Jorge",   "133ee", 10, 2.5),
        criaAluno("Ane",     "222tt", 10, 2.23),
        criaAluno("Dirce",   "333mk", 10, 7.1),
        criaAluno("Jadson",  "444el", 10, 9.5),
        criaAluno("Xandres", "666xx", 10, 2.1),
        criaAluno("Marcos",  "777zz", 10, 3.51),
        criaAluno("Sarah",   "888qq", 10, 6.51)
    };

    printf("=========== Lista de Alunos ===========\n\n");
    for (int i = 0; i < QUANTIDADE_ALUNOS; i++) {
        descreveAluno(alunos[i]);
    }

    maiorMedia(alunos, QUANTIDADE_ALUNOS);
    menorMedia(alunos, QUANTIDADE_ALUNOS);

    return 0;
}



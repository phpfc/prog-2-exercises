// 4) Faça um programa que leia os dados relativos a N pessoas
// (o valor de N é definido pela diretiva #define),
// cada pessoa contendo as seguintes informações:
// nome: até 50 caracteres;
// peso em quilogramas (int)
// altura em metros (float)
// Após a entrada dos dados o programa deverá escrever o nome e o IMC
// das N pessoas, em ordem decrescente de IMC. Para o cálculo do IMC
// basta dividir o peso pela altura ao quadrado. Por exemplo, considerando
// um N=6 e para a entrada (nome,  peso e altura)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 2

struct pessoa {
    char nome[50];
    int peso;
    float altura;
};
typedef struct pessoa pessoa;

pessoa le_pessoas(pessoa pessoas[N]) {
    for (int i = 0; i < N; i++) {
        printf("Insira o nome do pessoa: ");
        fgets(pessoas[i].nome, sizeof(pessoas[i].nome), stdin);
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = '\0';

        printf("Insira o peso: ");
        scanf("%d", &pessoas[i].peso);

        printf("Insira a altura: ");
        scanf("%f", &pessoas[i].altura);

        while (getchar() != '\n');
    }
}

float calculaImc(int peso, float altura) {
    return (peso) / (altura * altura);
}

void ordena_imcs(pessoa pessoas[N]) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i; j++) {
            if (calculaImc(pessoas[j].peso, pessoas[j].altura) < calculaImc(pessoas[j + 1].peso, pessoas[j + 1].altura)) {
                pessoa const aux = pessoas[j];
                pessoas[j] = pessoas[j + 1];
                pessoas[j + 1] = aux;
            }
        }
    }
}

void escreve_imcs(pessoa pessoas[N]) {
    ordena_imcs(pessoas);
    for (int i = 0; i < N; i++) {
        printf("Nome: %s\n", pessoas[i].nome);
        printf("IMC: %f\n", calculaImc(pessoas[i].peso, pessoas[i].altura));
    }
}

int main() {
    pessoa pessoas[N];

    le_pessoas(pessoas);
    escreve_imcs(pessoas);
}


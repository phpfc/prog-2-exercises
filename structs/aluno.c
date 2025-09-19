#include <stdio.h>
#include<string.h>
#define N 3
struct aluno {
    char nome[50];
    float notas[3];
};
typedef struct aluno ALUNO;

void le_alunos(ALUNO v[N]) {
    for(int i = 0; i<N; i++) {
        printf("Digite o nome\n");
        fgets(v[i].nome, sizeof(v[i].nome), stdin);
        v[i].nome[strcspn(v[i].nome, "\n")] = '\0';
        // v[i].nome[strlen(v[i].nome) - 1] = '\0';
        
        printf("Digite as notas\n");
        scanf("%f %f %f", &v[i].notas[0], &v[i].notas[1], &v[i].notas[2]);
        
        while (getchar() != '\n');
    }
}

float calc_media(ALUNO a) {
    return (a.notas[0] + a.notas[1] + a.notas[2]) / 3;
}

void escreve_aluno(ALUNO v[N]) {
    for(int i = 0; i < N; i++) {
        printf("%s %.2f\n", v[i].nome, calc_media(v[i]));
    }
}

void ordena_por_medias(ALUNO v[N]) {
    ALUNO aux;
    for(int i = 0; i < N - 1; i ++) {
        for(int j = 0; j < N - i; j++) {
            if (calc_media(v[j]) < calc_media(v[j + 1])) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            } else if(calc_media(v[j]) == calc_media(v[j + 1]) && strcasecmp(v[j].nome, v[j + 1].nome) > 0) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

int main()
{
    ALUNO v[N];
    le_alunos(v);
    ordena_por_medias(v);
    escreve_aluno(v);
}
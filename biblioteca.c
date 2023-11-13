// biblioteca.c
#include "biblioteca.h"
#include <stdio.h>
#include <string.h>

void salvarTarefas(struct tarefa tarefas[], int numTarefas) {
    FILE *arquivo = fopen("tarefas.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de tarefas para escrita.\n");
        return;
    }

    fwrite(tarefas, sizeof(struct tarefa), numTarefas, arquivo);
    fclose(arquivo);
}

int carregarTarefas(struct tarefa tarefas[]) {
    FILE *arquivo = fopen("tarefas.bin", "rb");
    if (arquivo == NULL) {
        printf("Arquivo de tarefas nao encontrado. Criando novo arquivo.\n");
        return 0;
    }

    int numTarefas = 0;
    while (fread(&tarefas[numTarefas], sizeof(struct tarefa), 1, arquivo) == 1) {
        numTarefas++;
    }
    fclose(arquivo);
    return numTarefas;
}

void cadastrarTarefa(struct tarefa tarefas[], int *numTarefas) {
    if (*numTarefas >= MAX_TAREFAS) {
        printf("Limite maximo de tarefas atingido.\n");
        return;
    }

    struct tarefa novaTarefa;
    printf("Prioridade da tarefa (0 a 10): ");
    scanf("%d", &novaTarefa.prioridade);

    printf("Descricao da tarefa (ate 300 letras): ");
    getchar(); // Lê o caractere de nova linha pendente
    fgets(novaTarefa.descricao, sizeof(novaTarefa.descricao), stdin);

    printf("Categoria da tarefa (ate 100 letras): ");
    fgets(novaTarefa.categoria, sizeof(novaTarefa.categoria), stdin);

    printf("Estado da tarefa (completo/em andamento/não iniciado): ");
    fgets(novaTarefa.estado, sizeof(novaTarefa.estado), stdin);

    tarefas[*numTarefas] = novaTarefa;
    (*numTarefas)++;
    salvarTarefas(tarefas, *numTarefas);
    printf("Tarefa cadastrada com sucesso!\n");
}

void listarTarefas(struct tarefa tarefas[], int numTarefas) {
    printf("Lista de Tarefas:\n");
    for (int i = 0; i < numTarefas; i++) {
        printf("Prioridade: %d\n", tarefas[i].prioridade);
        printf("Descricao: %s", tarefas[i].descricao);
        printf("Categoria: %s", tarefas[i].categoria);
        printf("Estado: %s", tarefas[i].estado);
        printf("\n");
    }
}

void deletarTarefa(struct tarefa tarefas[], int *numTarefas, int prioridade, char categoria[]) {
    int tarefaEncontrada = 0;

    for (int i = 0; i < *numTarefas; i++) {
        if (tarefas[i].prioridade == prioridade &&
            strcmp(tarefas[i].categoria, categoria) == 0 &&
            strcmp(tarefas[i].estado, "completo") == 0) {
            tarefaEncontrada = 1;

            for (int j = i; j < *numTarefas - 1; j++) {
                tarefas[j] = tarefas[j + 1];
            }
            (*numTarefas)--;
            salvarTarefas(tarefas, *numTarefas);
            printf("Tarefa com prioridade %d e categoria '%s' deletada com sucesso!\n", prioridade, categoria);
            break;
        }
    }

    if (!tarefaEncontrada) {
        printf("Tarefa nao encontrada ou já está completa.\n");
    }
}

void alterarTarefa(struct tarefa tarefas[], int numTarefas, int prioridade, char categoria[]) {
    int tarefaEncontrada = 0;

    for (int i = 0; i < numTarefas; i++) {
        if (tarefas[i].prioridade == prioridade && strcmp(tarefas[i].categoria, categoria) == 0 &&
            strcmp(tarefas[i].estado, "completo") != 0) {
            tarefaEncontrada = 1;

            printf("Digite o novo valor para a prioridade da tarefa: ");
            scanf("%d", &tarefas[i].prioridade);

            printf("Digite o novo valor para a descrição da tarefa: ");
            getchar(); // Lê o caractere de nova linha pendente
            fgets(tarefas[i].descricao, sizeof(tarefas[i].descricao), stdin);

            printf("Digite o novo valor para a categoria da tarefa: ");
            fgets(tarefas[i].categoria, sizeof(tarefas[i].categoria), stdin);

            printf("Digite o novo valor para o estado da tarefa: ");
            fgets(tarefas[i].estado, sizeof(tarefas[i].estado), stdin);

            salvarTarefas(tarefas, numTarefas);
            printf("Tarefa alterada com sucesso!\n");
            break;
        }
    }

    if (!tarefaEncontrada) {
        printf("Tarefa não encontrada ou já está completa.\n");
    }
}

// biblioteca.c
#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

void salvarTarefas(struct tarefa tarefas[], int numTarefas) {
    FILE *arquivo = fopen("tarefas.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < numTarefas; i++) {
        fprintf(arquivo, "%d\n", tarefas[i].prioridade);
        fprintf(arquivo, "%s", tarefas[i].descricao);
        fprintf(arquivo, "%s", tarefas[i].categoria);
        fprintf(arquivo, "%s\n", tarefas[i].estado);
    }

    fclose(arquivo);
}

int carregarTarefas(struct tarefa tarefas[]) {
    FILE *arquivo = fopen("tarefas.txt", "r");

    if (arquivo == NULL) {
        printf("Arquivo de tarefas não encontrado. Criando novo arquivo...\n");
        return 0;
    }

    int numTarefas = 0;
    while (fscanf(arquivo, "%d", &tarefas[numTarefas].prioridade) == 1) {
        // Limpar o buffer após a leitura da prioridade
        fgetc(arquivo);

        fgets(tarefas[numTarefas].descricao, sizeof(tarefas[numTarefas].descricao), arquivo);
        fgets(tarefas[numTarefas].categoria, sizeof(tarefas[numTarefas].categoria), arquivo);
        fgets(tarefas[numTarefas].estado, sizeof(tarefas[numTarefas].estado), arquivo);

        // Remover caracteres de nova linha
        tarefas[numTarefas].descricao[strcspn(tarefas[numTarefas].descricao, "\n")] = '\0';
        tarefas[numTarefas].categoria[strcspn(tarefas[numTarefas].categoria, "\n")] = '\0';
        tarefas[numTarefas].estado[strcspn(tarefas[numTarefas].estado, "\n")] = '\0';

        numTarefas++;
    }

    fclose(arquivo);

    return numTarefas;
}

void cadastrarTarefa(struct tarefa tarefas[], int *numTarefas) {
    printf("Cadastrar Nova Tarefa:\n");

    if (*numTarefas < MAX_TAREFAS) {
        printf("Digite a prioridade da tarefa: ");
        scanf("%d", &tarefas[*numTarefas].prioridade);

        printf("Digite a descricao da tarefa: ");
        getchar(); // Limpar o buffer do teclado
        fgets(tarefas[*numTarefas].descricao, sizeof(tarefas[*numTarefas].descricao), stdin);

        printf("Digite a categoria da tarefa: ");
        fgets(tarefas[*numTarefas].categoria, sizeof(tarefas[*numTarefas].categoria), stdin);

        // Remover o caractere de nova linha (\n) da categoria
        tarefas[*numTarefas].categoria[strcspn(tarefas[*numTarefas].categoria, "\n")] = '\0';

        printf("Digite o estado da tarefa: ");
        fgets(tarefas[*numTarefas].estado, sizeof(tarefas[*numTarefas].estado), stdin);

        // Remover o caractere de nova linha (\n) do estado
        tarefas[*numTarefas].estado[strcspn(tarefas[*numTarefas].estado, "\n")] = '\0';

        (*numTarefas)++;
        printf("Tarefa cadastrada com sucesso!\n");
    } else {
        printf("Limite de tarefas atingido.\n");
    }
}

void listarTarefas(struct tarefa tarefas[], int numTarefas) {
    if (numTarefas > 0) {
        printf("Lista de Tarefas:\n");
        for (int i = 0; i < numTarefas; i++) {
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Descrição: %s\n", tarefas[i].descricao);
            printf("Categoria: %s\n", tarefas[i].categoria);
            printf("Estado: %s\n", tarefas[i].estado);
            printf("----------------------------\n");
        }
    } else {
        printf("Não há tarefas cadastradas.\n");
    }
}

void deletarTarefa(struct tarefa tarefas[], int *numTarefas, int prioridade, const char categoria[]) {
    // Implementação para deletar uma tarefa
    // ...
}

void alterarTarefa(struct tarefa tarefas[], int numTarefas, int prioridade, const char categoria[]) {
    // Implementação para alterar uma tarefa
    // ...
}

void filtrarTarefasPorPrioridade(struct tarefa tarefas[], int numTarefas, int prioridade) {
    printf("\nTarefas com Prioridade %d:\n", prioridade);

    int encontrou = 0;

    for (int i = 0; i < numTarefas; i++) {
        if (tarefas[i].prioridade == prioridade) {
            printf
                    ("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Descrição: %s\n", tarefas[i].descricao);
            printf("Categoria: %s\n", tarefas[i].categoria);
            printf("Estado: %s\n", tarefas[i].estado);
            printf("----------------------------\n");

            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma tarefa encontrada com a prioridade %d.\n", prioridade);
    }
}

void filtrarTarefasPorEstado(struct tarefa tarefas[], int numTarefas, const char estado[]) {
    printf("\nTarefas com Estado %s:\n", estado);

    int encontrou = 0;

    for (int i = 0; i < numTarefas; i++) {
        if (strcmp(tarefas[i].estado, estado) == 0) {
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Descrição: %s\n", tarefas[i].descricao);
            printf("Categoria: %s\n", tarefas[i].categoria);
            printf("Estado: %s\n", tarefas[i].estado);
            printf("----------------------------\n");

            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma tarefa encontrada com o estado %s.\n", estado);
    }
}
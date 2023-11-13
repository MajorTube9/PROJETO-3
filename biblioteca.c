// biblioteca.c
#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

void salvarTarefas(struct tarefa tarefas[], int numTarefas) {
    // Implementação para salvar as tarefas em um arquivo, se necessário
    // ...
}

int carregarTarefas(struct tarefa tarefas[]) {
    // Implementação para carregar as tarefas de um arquivo, se necessário
    // ...

    // Retorna um valor fictício para evitar erro no main
    return 0;
}

void cadastrarTarefa(struct tarefa tarefas[], int *numTarefas) {
    printf("Cadastrar Nova Tarefa:\n");

    if (*numTarefas < MAX_TAREFAS) {
        printf("Digite a prioridade da tarefa: ");
        scanf("%d", &tarefas[*numTarefas].prioridade);

        printf("Digite a descricao da tarefa: ");
        getchar(); // Limpa o buffer do teclado
        fgets(tarefas[*numTarefas].descricao, sizeof(tarefas[*numTarefas].descricao), stdin);

        printf("Digite a categoria da tarefa: ");
        fgets(tarefas[*numTarefas].categoria, sizeof(tarefas[*numTarefas].categoria), stdin);

        // Remova o caractere de nova linha (\n) da categoria
        tarefas[*numTarefas].categoria[strcspn(tarefas[*numTarefas].categoria, "\n")] = '\0';

        printf("Digite o estado da tarefa: ");
        fgets(tarefas[*numTarefas].estado, sizeof(tarefas[*numTarefas].estado), stdin);

        // Remova o caractere de nova linha (\n) do estado
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
            printf("Descrição: %s", tarefas[i].descricao);
            printf("Categoria: %s", tarefas[i].categoria);
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
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Descrição: %s", tarefas[i].descricao);
            printf("Categoria: %s", tarefas[i].categoria);
            printf("Estado: %s\n", tarefas[i].estado);

            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma tarefa encontrada com a prioridade %d.\n", prioridade);
    }
}
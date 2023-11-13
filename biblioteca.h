//
// Created by Pedro Satoru on 12/09/2023.
//

#ifndef PROJETO1_BIBLIOTECA_H
#define PROJETO1_BIBLIOTECA_H
#define MAX_TAREFAS 100
struct tarefa {
    int prioridade;
    char descricao[300];
    char categoria[100];
};

void salvarTarefas(struct tarefa tarefas[], int numTarefas);

int carregarTarefas(struct tarefa tarefas[]);

void cadastrarTarefa(struct tarefa tarefas[], int *numTarefas);

void listarTarefas(struct tarefa tarefas[], int numTarefas);

void deletarTarefa(struct tarefa tarefas[], int *numTarefas, int prioridade, char categoria[]);

void alterarTarefa(struct tarefa tarefas[], int numTarefas, int prioridade, char categoria[]);









#endif //PROJETO1_BIBLIOTECA_H

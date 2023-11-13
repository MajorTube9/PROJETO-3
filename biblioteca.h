// biblioteca.h
#ifndef PROJETO1_BIBLIOTECA_H
#define PROJETO1_BIBLIOTECA_H

#define MAX_TAREFAS 100

struct tarefa {
    int prioridade;
    char descricao[300];
    char categoria[100];
    char estado[20];
};

void salvarTarefas(struct tarefa tarefas[], int numTarefas);

int carregarTarefas(struct tarefa tarefas[]);

void cadastrarTarefa(struct tarefa tarefas[], int *numTarefas);

void listarTarefas(struct tarefa tarefas[], int numTarefas);

void deletarTarefa(struct tarefa tarefas[], int *numTarefas, int prioridade, const char categoria[]);

void alterarTarefa(struct tarefa tarefas[], int numTarefas, int prioridade, const char categoria[]);

void filtrarTarefasPorPrioridade(struct tarefa tarefas[], int numTarefas, int prioridade);

void filtrarTarefasPorEstado(struct tarefa tarefas[], int numTarefas, const char estado[]);

void filtrarTarefasPorCategoria(struct tarefa tarefas[], int numTarefas, const char categoria[]);

void filtrarTarefasPorPrioridadeECategoria(struct tarefa tarefas[], int numTarefas, int prioridade, const char categoria[]);

#endif // PROJETO1_BIBLIOTECA_H

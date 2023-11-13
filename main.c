// main.c
#include <stdio.h>
#include "biblioteca.h"

int main() {
    struct tarefa tarefas[MAX_TAREFAS];
    int numTarefas = carregarTarefas(tarefas);

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Tarefa\n");
        printf("2. Listar Tarefas\n");
        printf("3. Deletar Tarefa\n");
        printf("4. Sair\n");
        printf("5. Alterar Tarefa\n");
        printf("6. Filtrar Tarefas por Prioridade\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarTarefa(tarefas, &numTarefas);
                break;
            case 2:
                listarTarefas(tarefas, numTarefas);
                break;
            case 3:
                if (numTarefas > 0) {
                    int prioridade;
                    printf("Digite a prioridade da tarefa a ser deletada: ");
                    scanf("%d", &prioridade);

                    char categoria[100];

                    printf("Digite a categoria da tarefa: ");
                    getchar(); // Lê o caractere de nova linha pendente
                    fgets(categoria, sizeof(categoria), stdin);

                    deletarTarefa(tarefas, &numTarefas, prioridade, categoria);
                } else {
                    printf("Não há tarefas para deletar.\n");
                }
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            case 5:
                if (numTarefas > 0) {
                    int prioridade;
                    printf("Digite a prioridade da tarefa a ser alterada: ");
                    scanf("%d", &prioridade);

                    char categoria[100];

                    printf("Digite a categoria da tarefa: ");
                    getchar(); // Lê o caractere de nova linha pendente
                    fgets(categoria, sizeof(categoria), stdin);

                    alterarTarefa(tarefas, numTarefas, prioridade, categoria);
                } else {
                    printf("Não há tarefas para alterar.\n");
                }
                break;
            case 6:
                if (numTarefas > 0) {
                    int prioridadeFiltrar;
                    printf("Digite a prioridade para filtrar as tarefas: ");
                    scanf("%d", &prioridadeFiltrar);
                    filtrarTarefasPorPrioridade(tarefas, numTarefas, prioridadeFiltrar);
                } else {
                    printf("Não há tarefas para filtrar.\n");
                }
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

    } while (opcao != 4);

    return 0;
}

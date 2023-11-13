// main.c
#include <stdio.h>
#include "biblioteca.h"
#include <string.h>

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
        printf("7. Filtrar Tarefas por Estado\n");
        printf("8. Filtrar Tarefas por Categoria\n");
        printf("9. Filtrar Tarefas por Prioridade e Categoria\n"); // Nova opção
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
                // ... (restante do código permanece o mesmo)
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            case 5:
                // ... (restante do código permanece o mesmo)
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
            case 7:
                if (numTarefas > 0) {
                    char estadoFiltrar[20];
                    printf("Digite o estado para filtrar as tarefas: ");
                    scanf("%s", estadoFiltrar);
                    filtrarTarefasPorEstado(tarefas, numTarefas, estadoFiltrar);
                } else {
                    printf("Não há tarefas para filtrar.\n");
                }
                break;
            case 8:
                if (numTarefas > 0) {
                    char categoriaFiltrar[100];
                    printf("Digite a categoria para filtrar as tarefas: ");
                    getchar(); // Limpar o buffer do teclado
                    fgets(categoriaFiltrar, sizeof(categoriaFiltrar), stdin);
                    // Remover o caractere de nova linha (\n) da categoria
                    categoriaFiltrar[strcspn(categoriaFiltrar, "\n")] = '\0';
                    filtrarTarefasPorCategoria(tarefas, numTarefas, categoriaFiltrar);
                } else {
                    printf("Não há tarefas para filtrar.\n");
                }
                break;
            case 9:
                if (numTarefas > 0) {
                    int prioridadeFiltrar;
                    printf("Digite a prioridade para filtrar as tarefas: ");
                    scanf("%d", &prioridadeFiltrar);

                    char categoriaFiltrar[100];
                    printf("Digite a categoria para filtrar as tarefas: ");
                    getchar(); // Limpar o buffer do teclado
                    fgets(categoriaFiltrar, sizeof(categoriaFiltrar), stdin);
                    // Remover o caractere de nova linha (\n) da categoria
                    categoriaFiltrar[strcspn(categoriaFiltrar, "\n")] = '\0';

                    filtrarTarefasPorPrioridadeECategoria(tarefas, numTarefas, prioridadeFiltrar, categoriaFiltrar);
                } else {
                    printf("Não há tarefas para filtrar.\n");
                }
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

    } while (opcao != 4);

    // Salvar as tarefas de volta no arquivo ao encerrar o programa
    salvarTarefas(tarefas, numTarefas);

    return 0;
}

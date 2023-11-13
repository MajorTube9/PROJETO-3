# PROJETO-3
Projeto 3 da aula de algoritmo do segundo semestre

Este código é um programa simples de gerenciamento de tarefas (to-do list) em linguagem C. Ele consiste em um conjunto de funções que interagem com um arquivo de texto chamado "tarefas.txt" para realizar operações como cadastrar, listar, deletar e alterar tarefas. O programa possui um menu interativo que permite ao usuário escolher entre várias opções.

Aqui está uma breve explicação do que cada função faz:

salvarTarefas: Salva as tarefas atuais no arquivo "tarefas.txt".
carregarTarefas: Carrega as tarefas existentes do arquivo "tarefas.txt" para a memória.
cadastrarTarefa: Adiciona uma nova tarefa à lista, solicitando informações como prioridade, descrição, categoria e estado.
listarTarefas: Exibe na tela todas as tarefas cadastradas, mostrando detalhes como prioridade, descrição, categoria e estado.
deletarTarefa: Remove uma tarefa com base na prioridade e categoria fornecidas pelo usuário.
alterarTarefa: Modifica os detalhes de uma tarefa com base na prioridade e categoria fornecidas pelo usuário.
filtrarTarefasPorPrioridade: Exibe tarefas filtradas por prioridade.
filtrarTarefasPorEstado: Exibe tarefas filtradas por estado.
filtrarTarefasPorCategoria: Exibe tarefas filtradas por categoria.
filtrarTarefasPorPrioridadeECategoria: Exibe tarefas filtradas por prioridade e categoria.
A função main contém um loop que exibe um menu ao usuário, permitindo que ele escolha entre as diversas opções disponíveis. O programa continua em execução até que o usuário opte por sair (opção 4 no menu). Ao final, as tarefas são salvas de volta no arquivo "tarefas.txt" antes de encerrar o programa.

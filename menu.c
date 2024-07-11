#include <stdio.h>
//#include <stdlib.h>
#include "menu.h"

int imprimeMenu(){

  int opcao;

  printf("\n\nEscolha uma das seguintes opções: \n\n");
  printf("1 - Cadastrar um novo curso; \n");
  printf("2 - Excluir um curso cadastrado; \n");
  printf("3 - Imprimir todos os cursos cadastrados; \n");
  printf("4 - Cadastrar um novo aluno (curso a ser informado); \n");
  printf("5 - Excluir o registro de um aluno matriculado (curso a ser informado); \n");
  printf("6 - Imprimir todos os alunos matriculados (curso a ser informado); \n");
  printf("7 - Sair do programa; \n\n");
  scanf("%d", &opcao);

  return opcao;
}
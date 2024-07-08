#include <stdio.h>
#include <stdlib.h>
#include "abbCursos.h"
#include "listaAlunos.h"
#include "menu.c"

int main(){

  int opcaoMenu;
  abbCursos *abb;

  printf("\nBem vindos ao sistema de gerenciamento dos cursos de graduação da UFSM! \n");

  while (1){
    opcaoMenu = imprimeMenu();
    if (opcaoMenu == 1){
      // insere curso na abb
    }
    else if (opcaoMenu == 2){
      // exclui curso da abb (um nó pra cada curso)
    }
    else if (opcaoMenu == 3){
      // imprime abb dos cursos
    }
    else if (opcaoMenu == 4){
      // insere aluno na lista de matriculados (uma pra cada curso) (tem que pedir de qual curso)
    }
    else if (opcaoMenu == 5){
      // exclui aluno da lista de matriculados (tem que pedir de qual curso)
    }
    else if (opcaoMenu == 6){
      // imprime lista de alunos (tem que pedir de qual curso)
    }
    else if (opcaoMenu == 7){
      return 0;
    }
    else {
      printf("\nOpção inválida inserida; \n");
    }
  }

  system("pause");
  return 0;
}
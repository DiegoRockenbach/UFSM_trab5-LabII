#include <stdio.h>
#include <stdlib.h>
#include "abbCursos.h"
#include "listaAlunos.h"
#include "menu.c"

int main(){

  int opcaoMenu, codInsert, matriculaInsert, anoIngressoInsert;
  char nomeInsert[50], nomeCentroInsert[50];
  abbCursos *cursos = NULL, *cursoFound;

  printf("\nBem vindos ao sistema de gerenciamento dos cursos de graduação da UFSM! \n");

  while (1){
    opcaoMenu = imprimeMenu();
    if (opcaoMenu == 1){
        printf("\nInsira o código do curso a ser inserido: \n");
        scanf("%d", &codInsert);
        printf("\nInsira o nome do curso a ser inserido: \n");
        bufferCursos();
        gets(nomeInsert);
        printf("\nInsira o nome do centro à qual este curso pertence: \n");
        gets(nomeCentroInsert);

        cursos = insereCurso(cursos, codInsert, nomeInsert, nomeCentroInsert);
        printf("\nInserção bem sucedida! Agora o curso de código %d pode ser escolhido para cadastrar alunos matriculados! \n\n", codInsert);
    }
    else if (opcaoMenu == 2){
      // exclui curso da abb (um nó pra cada curso)
    }
    else if (opcaoMenu == 3){
      printf("\n\n");
      imprimeABBCursosComAlunos(cursos);
    }
    else if (opcaoMenu == 4){
      if (cursos != NULL){
        printf("\nEstes são os cursos cadastrados no banco de dados: \n\n");
        imprimeABBCursosSemAlunos(cursos);
        printf("\n");

        printf("\nInsira o código do curso no qual deseja inserir o aluno: \n");
        scanf("%d", &codInsert);
        cursoFound = buscaCurso(cursos, codInsert);
        if (cursoFound != NULL){
          printf("\nInsira a matrícula do(a) aluno(a) a ser inserido(a): \n");
          scanf("%d", &matriculaInsert);
          printf("\nInsira o nome do(a) aluno(a) a ser inserido(a): \n");
          bufferCursos();
          gets(nomeInsert);
          printf("\nInsira em que ano este aluno ingressou no curso: \n");
          scanf("%d", &anoIngressoInsert);

          cursoFound->matriculados = insereAluno(cursoFound->matriculados, matriculaInsert, nomeInsert, anoIngressoInsert);
          printf("\nInserção bem sucedida! \n\n");
        }
        else {
          printf("\nNão foi possível encontrar o curso de código %d; Inserção falhou! \n\n", codInsert);
        }
      }
      else {
        printf("\nNão há nenhum curso cadastrado no banco de dados, portanto não é possível realizar a inserção de alunos! \n\n");
      }
    }
    else if (opcaoMenu == 5){
      // exclui aluno da lista de matriculados (tem que pedir de qual curso)
    }
    else if (opcaoMenu == 6){
      if (cursos != NULL){
        printf("\nEstes são os cursos cadastrados no banco de dados: \n\n");
        imprimeABBCursosSemAlunos(cursos);
        printf("\n");

        printf("\nInsira o código do curso do qual deseja imprimir a lista de alunos matriculados: \n");
        scanf("%d", &codInsert);
        cursoFound = buscaCurso(cursos, codInsert);
        if (cursoFound != NULL){
          imprimeListaAlunos(cursoFound->matriculados);
        }
        else {
          printf("\nNão foi possível encontrar o curso de código %d; \n\n", codInsert);
        }
      }
      else {
        printf("\nNão há nenhum curso cadastrado no banco de dados, portanto não é possível imprimir a lista de alunos matriculados! \n\n");
      }
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
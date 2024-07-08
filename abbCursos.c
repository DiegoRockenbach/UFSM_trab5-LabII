#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "abbCursos.h"
#include "listaAlunos.h"

abbCursos* buscaCurso(abbCursos *cursos, int codBusca){
  
  if (cursos != NULL){
    buscaCurso(cursos->esq, codBusca);
    if (codBusca == cursos->cod){
      return cursos;
    }
    buscaCurso(cursos->dir, codBusca);
  }

  return NULL; // se não achar ou se cursos for vazio retorna NULL
}

void imprimeABBCursosSemAlunos(abbCursos *cursos){

  if (cursos != NULL){
    imprimeABBCursosSemAlunos(cursos->esq);
    printf("%d - %s (%s);\n", cursos->cod, cursos->nome, cursos->nomeCentro);
    imprimeABBCursosSemAlunos(cursos->dir);
  }

}

void imprimeABBCursosComAlunos(abbCursos *cursos){

  if (cursos != NULL){
    imprimeABBCursosComAlunos(cursos->esq);
    printf("%d - %s (%s);\n", cursos->cod, cursos->nome, cursos->nomeCentro);
    if (cursos->matriculados != NULL){
      imprimeListaAlunos(cursos->matriculados);
    }
    imprimeABBCursosComAlunos(cursos->dir);
  }

}

abbCursos* insereCurso(abbCursos *cursos, int codInsert, char nomeInsert[50], char nomeCentroInsert[50]){

  abbCursos *novo;

  novo = (abbCursos*) malloc(sizeof(abbCursos));
  if (novo == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  novo->cod = codInsert;
  strcpy(novo->nome, nomeInsert);
  strcpy(novo->nomeCentro, nomeCentroInsert);
  novo->matriculados = NULL;
  novo->esq = NULL;
  novo->dir = NULL;
  
  if (cursos == NULL){
    return novo;
  }
  if (codInsert < cursos->cod){
    cursos->esq = insereCurso(cursos->esq, codInsert, nomeInsert, nomeCentroInsert);
  }
  else {
    cursos->dir = insereCurso(cursos->dir, codInsert, nomeInsert, nomeCentroInsert);
  }

  return cursos;
}

void bufferCursos(){
  
  int c;
  while((c = getchar()) != '\n' && c != EOF) {}

}

// func deletaNó

// etc
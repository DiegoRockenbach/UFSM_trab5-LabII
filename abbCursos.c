#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abbCursos.h"
#include "listaAlunos.h"

abbCursos* buscaCurso(abbCursos *cursos, int codBusca){
  
  if (cursos == NULL){
    return NULL;
  }
  else {
    if (codBusca < cursos->cod){
      buscaCurso(cursos->esq, codBusca);
    }
    else if (codBusca > cursos->cod){
      buscaCurso(cursos->dir, codBusca);
    }
    else {
      return cursos;
    }
  }
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

abbCursos* arv_libera(abbCursos* a){
  if(a != NULL){
      a->esq = arv_libera(a->esq);
      a->dir = arv_libera(a->dir);
      listaAlunos* p = a->matriculados;
      while(p != NULL){ //desalocar lista de alunos
          a->matriculados = p->prox;
          free(p);
          p = a->matriculados;
      }
      free(a);
  }
  return NULL;
}

abbCursos* removeCurso(abbCursos *cursos, abbCursos *cursoFound){

  abbCursos *temp;

  if (cursos != NULL){
    /* nó sem filhos */
    if (cursoFound->esq == NULL && cursoFound->dir == NULL) {
      cursoFound = NULL;
    }
    /* nó só tem filho à direita */
    else if (cursoFound->esq == NULL) {
      cursoFound = cursoFound->dir;
    }
    /* só tem filho à esquerda */
    else if (cursoFound->dir == NULL) {
      cursoFound = cursoFound->esq;
    }
    /* nó tem os dois filhos */
    else {
      temp = cursoFound->esq;
      while (temp->dir != NULL) {
        temp = temp->dir;
      }
      
      /* troca as informações */
      cursoFound->cod = temp->cod;
      strcpy(cursoFound->nome, temp->nome);
      strcpy(cursoFound->nomeCentro, temp->nomeCentro);
      cursoFound->matriculados = temp->matriculados;

      cursoFound->esq = removeCurso(cursoFound->esq, temp);
    }
  }

  return cursoFound;
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
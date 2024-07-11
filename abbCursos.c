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
      a = NULL;
  }
  return NULL;
}

abbCursos* removeCurso(abbCursos *cursos, abbCursos *cursoFound){

  if(cursoFound == NULL)
      return NULL;
  else if (cursos->cod > cursoFound->cod )
      cursos->esq = removeCurso(cursos->esq, cursoFound);
  else if (cursos->cod < cursoFound->cod)
      cursos->dir = removeCurso(cursos->dir, cursoFound);
  else{ /*achou o nó a remover */
      /* nó sem filhos*/
      if(cursos->esq == NULL && cursos->dir == NULL){
          listaAlunos* p = cursos->matriculados;
          while(p != NULL){ //desalocar lista de alunos
              cursos->matriculados = p->prox;
              free(p);
              p = cursos->matriculados;
          }
          free(cursos);
          cursos = NULL;
      }
//      nó só tem filho à direita
    else if(cursos->esq == NULL){
        abbCursos* t = cursos;

        cursos = cursos->dir;
        listaAlunos* p = t->matriculados;
        while(p != NULL){ //desalocar lista de alunos
          t->matriculados = p->prox;
          free(p);
          p = t->matriculados;
        }
        free(t);
        t = NULL;
    }
    //só tem filho à esquerda
    else if(cursos->dir == NULL){
        abbCursos* t = cursos;
        cursos = cursos->esq;
          listaAlunos* p = cursos->matriculados;
        while(p != NULL){ //desalocar lista de alunos
          cursos->matriculados = p->prox;
          free(p);
          p = cursos->matriculados;
        }
        free(t);
        t = NULL;
    }
    //nó tem dois filhos
    else{
        abbCursos* f = cursos->esq;
        while(f->dir != NULL){
            f = f->dir;
        }
        cursos->cod = f->cod; //troca as informações
        strcpy(cursos->nome, f->nome);
        strcpy(cursos->nomeCentro, f->nomeCentro);
        cursos->matriculados = f->matriculados;
        f->cod = cursoFound->cod;
        cursos->esq = removeCurso(cursos->esq, cursoFound);
    }
  }

  return cursos;
}

abbCursos* insereCurso(abbCursos *cursos, int codInsert, char nomeInsert[50], char nomeCentroInsert[50]){

//  abbCursos *novo;


  if (cursos == NULL){

      cursos = (abbCursos*) malloc(sizeof(abbCursos));
      if (cursos == NULL){
          printf("\nErro de alocação de memória!\n\n");
          system("pause");
          return NULL;
      }
      cursos->cod = codInsert;
      strcpy(cursos->nome, nomeInsert);
      strcpy(cursos->nomeCentro, nomeCentroInsert);
      cursos->matriculados = NULL;
      cursos->esq = NULL;
      cursos->dir = NULL;
  }
  else if (codInsert < cursos->cod){
    cursos->esq = insereCurso(cursos->esq, codInsert, nomeInsert, nomeCentroInsert);
  }
  else if(codInsert > cursos->cod){
    cursos->dir = insereCurso(cursos->dir, codInsert, nomeInsert, nomeCentroInsert);
  }

  return cursos;
}

void bufferCursos(){
  
  int c;
  while((c = getchar()) != '\n' && c != EOF) {}

}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaAlunos.h"

listaAlunos* buscaAluno(listaAlunos *matriculados, int matriculaBusca){

  listaAlunos *p;

  if (matriculados != NULL){
    p = matriculados;
    while (p != NULL){
      if (matriculaBusca == p->matricula){
        return p;
      }
      if (p->prox != NULL){
        p = p->prox;
      }
      else {
        break;
      }
    }
  }

  return NULL; // se não achar ou se a lista dos alunos matriculados for vazia retorna NULL
}

void imprimeListaAlunos(listaAlunos *matriculados){

  listaAlunos *p;

  printf("\n");
  for (p = matriculados; p != NULL; p = p->prox){
    printf("NOME: %s   |   MATRÍCULA: [%d] | Ingressou no curso em %d; \n", p->nome, p->matricula, p->anoIngresso);
    if (p->prox == NULL){
      break;
    }
  }
  printf("\n");

}

listaAlunos* removeAluno(listaAlunos *matriculados, listaAlunos *alunoFound){

  listaAlunos *p;

  p = matriculados;
  while (p != NULL){
    if (p == alunoFound && p->prox == NULL){
      return NULL;
    }
    if (p == alunoFound && p->prox != NULL){
      return p->prox;
    }
    if (p->prox != NULL){
      if (p->prox == alunoFound){
        p->prox = alunoFound->prox;
        break;
      }
      p = p->prox;
    }
  }

  return matriculados;
}

listaAlunos* insereAluno(listaAlunos *matriculados, int matriculaInsert, char nomeInsert[50], int anoIngressoInsert){

  listaAlunos *novo, *p;

  novo = (listaAlunos*) malloc(sizeof(listaAlunos));
  if (novo == NULL){
    printf("\nErro de alocação de memória!\n\n");
    return NULL;
  }
  novo->prox = NULL;
  novo->matricula = matriculaInsert;
  strcpy(novo->nome, nomeInsert);
  novo->anoIngresso = anoIngressoInsert;

  if (matriculados == NULL){
    return novo;
  }
  else {
    p = matriculados;
    while (p != NULL){

      if (p->matricula > matriculaInsert){
        novo->prox = p;
        return novo;
      }
      else {
        if (p->prox != NULL){
          if (p->matricula < matriculaInsert && p->prox->matricula > matriculaInsert){
            novo->prox = p->prox;
            p->prox = novo;
            return matriculados;
          }
          else if (p->matricula < matriculaInsert && p->prox->matricula < matriculaInsert){
            p = p->prox;
          }
        }
        else {
          p->prox = novo;
          return matriculados;
        }
      }
    }
  }

  return matriculados;
}
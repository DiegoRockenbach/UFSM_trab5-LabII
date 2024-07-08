#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaAlunos.h"

void imprimeListaAlunos(listaAlunos *matriculados){

  listaAlunos *p;

  printf("\n");
  for (p = matriculados; p != NULL; p = p->prox){
    printf("%s [%d] - Ingressou no curso em %d; \n", p->nome, p->matricula, p->anoIngresso);
    if (p->prox == NULL){
      break;
    }
  }
  printf("\n");

}

listaAlunos* insereAluno(listaAlunos *matriculados, int matriculaInsert, char nomeInsert[50], int anoIngressoInsert){

  listaAlunos *novo, *p;

  novo = (listaAlunos*) malloc(sizeof(listaAlunos));
  if (novo == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
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
    while (p->prox != NULL){
      p = p->prox;
    }
    p->prox = novo;
  }

  return matriculados;
}

// func remove aluno da lista

// etc sei la mais o que
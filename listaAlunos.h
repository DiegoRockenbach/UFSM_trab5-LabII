#ifndef __LISTAALUNOSH_INCLUDED__
#define __LISTAALUNOSH_INCLUDED__

#include <stdio.h>
#include <stdlib.h>

struct listaAlunos_t {
  int matricula;
  char nome[50];
  int anoIngresso;
  struct listaAlunos_t *prox;
}; typedef struct listaAlunos_t listaAlunos;
//função para imprimir a lista de alunos de um determinado curso
void imprimeListaAlunos(listaAlunos *matriculados);
//função para inserir um aluno à lista de um determinado curso
listaAlunos* insereAluno(listaAlunos *matriculados, int matriculaInsert, char nomeInsert[50], int anoIngressoInsert);

#endif
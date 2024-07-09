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
//função de busca de aluno pela matrícula do aluno
listaAlunos* buscaAluno(listaAlunos *matriculados, int matriculaBusca);
//função para imprimir a lista de alunos matriculados de um determinado curso
void imprimeListaAlunos(listaAlunos *matriculados);
//função para remover um aluno da lista de matriculados de um determinado curso
listaAlunos* removeAluno(listaAlunos *matriculados, listaAlunos *alunoFound);
//função para inserir um aluno à lista de matriculados de um determinado curso
listaAlunos* insereAluno(listaAlunos *matriculados, int matriculaInsert, char nomeInsert[50], int anoIngressoInsert);

#endif
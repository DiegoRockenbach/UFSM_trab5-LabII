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

#endif
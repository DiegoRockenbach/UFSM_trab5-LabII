#ifndef __ABBCURSOSH_INCLUDED__
#define __ABBCURSOSH_INCLUDED__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaAlunos.h"

struct abbCursos_t {
  int cod; // chave (o que tem que comparar pra ver se é < ou >=)
  char nome[50];
  char nomeCentro[50];
  listaAlunos* matriculados;
  struct abbCursos_t* esq;
  struct abbCursos_t* dir;
}; typedef struct abbCursos_t abbCursos;

#endif
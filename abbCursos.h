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

//função de busca de cursos pelo código do curso
abbCursos* buscaCurso(abbCursos *cursos, int codBusca);
//função para imprimir cursos sem nenhum aluno cadastrado
void imprimeABBCursosSemAlunos(abbCursos *cursos);
//função para imprimir cursos com alunos
void imprimeABBCursosComAlunos(abbCursos *cursos);
//função para inserir cursos à árvore
abbCursos* insereCurso(abbCursos *cursos, int codInsert, char nomeInsert[50], char nomeCentroInsert[50]);
//função para liberar a memória da árvore
abbCursos* arv_libera(abbCursos* a);
//função para limpar o buffer
void bufferCursos();

#endif
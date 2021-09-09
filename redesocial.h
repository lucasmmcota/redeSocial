#ifndef REDESOCIAL_H_INCLUDED
#define REDESOCIAL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    int dia;
    int mes;
    int ano;
} TData;

typedef struct usuarios
{
    int ID;
    char nome[100];
    char email[200];
    char login[50];
    char senha[50];
    TData data_de_nascimento;
} TUsuarios;

typedef struct redeSocial
{
    TUsuarios vetor[100];
    int matrix[100][100];
    int indice;
    int IDintermediarios[2];
    int matrizAmigosEmComum[100][100];
    int semAmigosEmComum[2];
} TRedeSocial;

void ler(TUsuarios *user);
void imprimir(TUsuarios user);
void inicializar(TRedeSocial *rede);

void cadastrar(TRedeSocial *rede, TUsuarios user);
void imprimirDois(TRedeSocial rede);
int pesquisar(TRedeSocial rede, TUsuarios user);
void alterar(TRedeSocial *rede, TUsuarios user, int indice);
void excluir(TRedeSocial *rede, int indice);

#endif

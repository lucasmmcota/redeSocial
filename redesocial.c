#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "redesocial.h"

void ler(TUsuarios *user)
{
    printf("\n\tDigite o nome do usuario: ");
    fflush(stdin);
    fgets(user->nome, 100, stdin);

    printf("\n\tDigite o email do usuario: ");
    fflush(stdin);
    fgets(user->email, 200, stdin);

    printf("\n\tDigite o login do usuario: ");
    fflush(stdin);
    fgets(user->login, 50, stdin);

    printf("\n\tDigite a senha do usuario: ");
    fflush(stdin);
    fgets(user->senha, 50, stdin);

    printf("\n\tDigite o dia de nascimento do usuario: ");
    fflush(stdin);
    scanf("%d", &user->data_de_nascimento.dia);

    printf("\tDigite o mes de nascimento do usuario: ");
    fflush(stdin);
    scanf("%d", &user->data_de_nascimento.mes);

    printf("\tDigite o ano de nascimento do usuario: ");
    fflush(stdin);
    scanf("%d", &user->data_de_nascimento.ano);
}

void imprimir(TUsuarios user)
{
    printf("\n\n\t---------- Dados do Usuario ----------\n\n");
    printf("\tNome: %s", user.nome);
    printf("\tID: %d", user.ID);
    printf("\n\tEmail: %s", user.email);
    printf("\tLogin: %s", user.login);
    printf("\tSenha: %s", user.senha);
    printf("\tData de nascimento: %d / %d / %d\n\n", user.data_de_nascimento.dia, user.data_de_nascimento.mes, user.data_de_nascimento.ano);
}

void inicializar(TRedeSocial *rede)
{
    int linha, coluna;

    for(linha = 0; linha < 100; linha++)
    {
        for(coluna = 0; coluna < 100; coluna++)
        {
            rede->matrix[linha][coluna] = 0;
            rede->matrizAmigosEmComum[linha][coluna] = 0;
        }
    }

    rede->indice = 0;
}

void cadastrar(TRedeSocial *rede, TUsuarios user)
{
    rede->vetor[rede->indice] = user;
    rede->vetor[rede->indice].ID = rede->indice;
    rede->indice++;
}

void imprimirDois(TRedeSocial rede)
{
    int i;

    for(i = 0; i < rede.indice; i++)
    {
        imprimir(rede.vetor[i]);
    }
}

int pesquisar(TRedeSocial rede, TUsuarios user)
{
    int i;

    for(i = 0; i < rede.indice; i++)
    {
        if(strcmp(user.nome, rede.vetor[i].nome) == 0 && rede.vetor[i].ID != -1)
        {
            return i;
        }
    }

    return -1;
}

void alterar(TRedeSocial *rede, TUsuarios user, int indice)
{
    rede->vetor[indice] = user;
    rede->vetor[indice].ID = indice;
}

void excluir(TRedeSocial *rede, int indice)
{
    int linhaColuna;

    rede->vetor[indice].ID = -1;

    for(linhaColuna = 0; linhaColuna < rede->indice; linhaColuna++)
    {
        if(rede->matrix[linhaColuna][indice] == 1)
        {
            rede->matrix[linhaColuna][indice] = 0;
            rede->matrix[indice][linhaColuna] = 0;
        }
    }
}

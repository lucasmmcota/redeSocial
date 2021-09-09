#include <stdio.h>
#include <stdlib.h>

#include "exercicios.h"
#include "amizades.h"

/* Retorna o ID do usuario com mais amigos da rede social */
int maisPopular(TRedeSocial rede)
{
    int i, j, idMaisPopular = 0, maiorNumeroDeAmigos = -1;

    for(i = 0; i < rede.indice; i++)
    {
        int numeroDeAmigos = 0;
        for(j = 0; j < rede.indice; j++)
        {
            if(rede.matrix[i][j] == 1)
            {
                numeroDeAmigos++;
            }
        }
        if(numeroDeAmigos > maiorNumeroDeAmigos)
        {
            maiorNumeroDeAmigos = numeroDeAmigos;
            idMaisPopular = i;
        }
    }

    return idMaisPopular;
}

/* Retorna a quantidade de amigos em comum dos usuarios de ID1 e ID2 */
int amizadesEmComum(TRedeSocial rede, int id1, int id2)
{
    int i, amigosEmComum = 0;

    for(i = 0; i < rede.indice; i++)
    {
        if(rede.matrix[id1][i] == 1 && rede.matrix[id2][i] == 1)
        {
            amigosEmComum++;
        }
    }

    return amigosEmComum;
}

/* Faz uma matriz de amigos em comum da rede social */
void matrizDeAmigosEmComum(TRedeSocial *rede)
{
    int i, j;

    for(i = 0; i < rede->indice; i++)
    {
        printf("\t");
        for(j = 0; j < rede->indice; j++)
        {
            rede->matrizAmigosEmComum[i][j] = amizadesEmComum(*rede, i, j);
            printf(" %d ", rede->matrizAmigosEmComum[i][j]);
        }
        printf("\n");
    }
}

/* Retorna por referência dois usuários que não são amigos e não tem amigos em comum */
/* Retorna por valor se foi possivel ou não realizar a operacao */
int nenhumAmigoEmComum(TRedeSocial *rede, TUsuarios user1, TUsuarios user2)
{
    if(rede->matrizAmigosEmComum[user1.ID][user2.ID] == 0)
    {
        rede->semAmigosEmComum[0] = user1.ID;
        rede->semAmigosEmComum[1] = user2.ID;
        return 1;
    }

    return 0;
}

/* Retorna por referência o ID do usuário intermediador */
/* Retorna por valor se foi possível realizar a operação */
int amizadeIndiretaNivelUm(TRedeSocial *rede, TUsuarios user1, TUsuarios user2)
{
    int i;

    for(i = 0; i < rede->indice; i++)
    {
        if(pesquisarAmizades(*rede, user1, rede->vetor[i]) == 1 && pesquisarAmizades(*rede, user2, rede->vetor[i]) == 1)
        {
            rede->IDintermediarios[0] = i;
            return i;
        }
    }

    return -1;
}

/* Retorna por referência os IDs dos usuários intermediadores */
/* Retorna por valor se foi possível realizar a operação */
int amizadeIndiretaNivelDois(TRedeSocial *rede, TUsuarios user1, TUsuarios user2)
{
    int i, j;

    for(i = 0; i < rede->indice; i++)
    {
        if(pesquisarAmizades(*rede, user1, rede->vetor[i]))
        {
            for(j = 0; j < rede->indice; j++)
            {
                if(pesquisarAmizades(*rede, rede->vetor[i], rede->vetor[j]) && pesquisarAmizades(*rede, user2, rede->vetor[j]))
                {
                    rede->IDintermediarios[0] = i;
                    rede->IDintermediarios[1] = j;
                    return 1;
                }
            }
        }
    }

    return 0;
}



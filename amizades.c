#include <stdio.h>
#include <stdlib.h>

#include "amizades.h"


void cadastrarAmizades(TRedeSocial *rede, TUsuarios user1, TUsuarios user2)
{
    int indiceUser1 = pesquisar(*rede, user1);
    int indiceUser2 = pesquisar(*rede, user2);

    rede->matrix[indiceUser1][indiceUser2] = 1;
    rede->matrix[indiceUser2][indiceUser1] = 1;
}

int pesquisarAmizades(TRedeSocial rede, TUsuarios user1, TUsuarios user2)
{
    int indiceUser1 = pesquisar(rede, user1);
    int indiceUser2 = pesquisar(rede, user2);

    if(indiceUser1 == -1 || indiceUser2 == -1)
    {
        printf("\n\n\tO(S) USUARIO(S) NAO ESTA(O) CADASTRADO(S) NA REDE SOCIAL !");
        return -1;
    }
    else if(rede.matrix[indiceUser1][indiceUser2] == 1 && rede.matrix[indiceUser2][indiceUser1] == 1)
    {
        return 1;
    }

    return 0;
}

void excluirAmizades(TRedeSocial *rede, TUsuarios user1, TUsuarios user2)
{
    int indiceUser1 = pesquisar(*rede, user1);
    int indiceUser2 = pesquisar(*rede, user2);

    rede->matrix[indiceUser1][indiceUser2] = 0;
    rede->matrix[indiceUser2][indiceUser1] = 0;
}

void imprimirAmizades(TRedeSocial rede, TUsuarios user)
{
    int indice = pesquisar(rede, user);

    if(indice >= 0)
    {
        int i;

        for(i = 0; i < rede.indice; i++)
        {
            if(rede.matrix[indice][i] == 1)
            {
                imprimir(rede.vetor[i]);
            }
        }
    }
}

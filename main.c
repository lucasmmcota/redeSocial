#include <stdio.h>
#include <stdlib.h>

#include "redesocial.h"
#include "interface.h"
#include "amizades.h"
#include "exercicios.h"

int main()
{
    TRedeSocial rede;
    TUsuarios user;
    int opcao;

    inicializar(&rede);

    do
    {
        mensagemMenu();
        printf("\n\n\tDIGITE UMA OPCAO: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            moduloUm(&rede, user);
            break;

        case 2:
            moduloDois(&rede, user);
            break;

        case 3:
            //system("cls");
            printf("\n\n\tAPERTE ENTER PARA FECHAR O PROGRAMA !");
            fflush(stdin);
            getchar();
            //system("pause);
            break;

        default:
            //system("cls");
            printf("\n\n\tOPCAO INVALIDA !");
            printf("\n\n\tPRESSIONE UMA TECLA PARA CONTINUAR !");
            fflush(stdin);
            getchar();
            //system("pause);
        }
    }
    while(opcao != 3);

    return 0;
}

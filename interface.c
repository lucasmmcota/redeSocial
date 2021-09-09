#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface.h"
#include "amizades.h"
#include "exercicios.h"

void mensagemMenu()
{
    printf("\n\n\t------------------ MENU ------------------");
    printf("\n\n\t1. MODULO 1 - GERENCIAMENTO DE USUARIOS");
    printf("\n\t2. MODULO 2 - GERENCIAMENTO DE AMIZADES");
    printf("\n\t3. SAIR");
}

void mensagemSubMenu(int modulo)
{
    // system("cls");
    switch (modulo)
    {
    case 1:
        printf("\n\n\t---------------- MODULO %d ----------------", modulo);
        printf("\n\n\t1. CADASTRAR");
        printf("\n\t2. PESQUISAR");
        printf("\n\t3. ALTERAR");
        printf("\n\t4. EXCLUIR");
        printf("\n\t5. IMPRIMIR");
        printf("\n\t6. MENU PRINCIPAL");
        break;

    case 2:
        printf("\n\n\t---------------- MODULO %d ----------------", modulo);
        printf("\n\n\t1. CADASTRAR");
        printf("\n\t2. PESQUISAR");
        printf("\n\t3. EXCLUIR");
        printf("\n\t4. IMPRIMIR");
        printf("\n\t5. USUARIO COM MAIS AMIGOS");
        printf("\n\t6. AMIGOS EM COMUM");
        printf("\n\t7. MATRIZ DE AMIGOS EM COMUM");
        printf("\n\t8. SEM AMIGOS EM COMUM");
        printf("\n\t9. RELACAO DE AMIZADE INDIRETA NIVEL 1");
        printf("\n\t10. RELACAO DE AMIZADE INDIRETA NIVEL 2");
        printf("\n\t11. MENU PRINCIPAL");
        break;
    }
}

void moduloUm(TRedeSocial *rede, TUsuarios user)
{
    int opcao, indiceDaPessoa;

    do
    {
        mensagemSubMenu(1);
        printf("\n\n\tDIGITE UMA OPCAO: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            //system("cls");
            if(rede->indice < 100)
            {
                ler(&user);
                cadastrar(rede, user);
                printf("\n\n\tO USUARIO FOI CADASTRADO COM SUCESSO !");
            }
            else
            {
                printf("\n\n\tNAO FOI POSSIVEL CADASTRAR O USUARIO, A REDE SOCIAL ESTA NA SUA CAPACIDADE MAXIMA !");
            }
            printf("\n\n\tPRESSIONE UMA TECLA PARA CONTINUAR !");
            fflush(stdin);
            getchar();
            //system("pause);
            break;

        case 2:
            //system("cls");
            printf("\n\n\tDIGITE O NOME DA PESSOA QUE VOCE ESTA PROCURANDO: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            indiceDaPessoa = pesquisar(*rede, user);
            if(indiceDaPessoa >= 0)
            {
                printf("\n\n\tUSUARIO ENCONTRADO: !");
                imprimir(rede->vetor[indiceDaPessoa]);
            }
            else
            {
                printf("\n\n\tESTE USUARIO NAO ESTA CADASTRADO NA REDE SOCIAL !");
            }
            printf("\n\n\tPRESSIONE UMA TECLA PARA CONTINUAR !");
            fflush(stdin);
            getchar();
            //system("pause);
            break;

        case 3:
            //system("cls");
            printf("\n\n\tDIGITE O NOME DO USUARIO QUE VOCE DESEJA ALTERAR: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            indiceDaPessoa = pesquisar(*rede, user);
            if(indiceDaPessoa >= 0)
            {
                ler(&user);
                alterar(rede, user, indiceDaPessoa);
                printf("\n\n\tO USUARIO FOI ALTERADO COM SUCESSO. \n\n");
                imprimir(rede->vetor[indiceDaPessoa]);
            }
            else
            {
                printf("\n\n\tESTE USUARIO NAO ESTA CADASTRADO NA REDE SOCIAL !");
            }
            printf("\n\n\tPRESSIONE UMA TECLA PARA CONTINUAR !");
            fflush(stdin);
            getchar();
            //system("pause);
            break;

        case 4:
            //system("cls");
            printf("\n\n\tDIGITE O NOME DO USUARIO QUE VOCE DESEJA EXCLUIR: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            indiceDaPessoa = pesquisar(*rede, user);
            if(indiceDaPessoa >= 0)
            {
                excluir(rede, indiceDaPessoa);
                printf("\n\n\tO USUARIO FOI EXCLUIDO COM SUCESSO !\n\n");
            }
            else
            {
                printf("\n\n\tESTE USUARIO NAO ESTA CADASTRADO NA REDE SOCIAL !");
            }
            printf("\n\n\tPRESSIONE UMA TECLA PARA CONTINUAR !");
            fflush(stdin);
            getchar();
            //system("pause);
            break;

        case 5:
            //system("cls");
            if(rede->indice > 0)
            {
                printf("\n\n\tLISTA DE USUARIOS DA REDE SOCIAL: ");
                imprimirDois(*rede);
            }
            else
            {
                printf("\n\n\tA REDE SOCIAL NAO POSSUI NENHUM USUARIO CADASTRADO !");
            }
            printf("\n\n\tPRESSIONE UMA TECLA PARA CONTINUAR !");
            fflush(stdin);
            getchar();
            //system("pause);
            break;

        case 6:
            //system("cls");
            printf("\n\n\tPRESSIONE UMA TECLA PARA VOLTAR AO MENU PRINCIPAL!");
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
    while(opcao != 6);
}

void moduloDois(TRedeSocial *rede, TUsuarios user)
{
    TUsuarios user_aux;
    int opcao;

    do
    {
        mensagemSubMenu(2);
        printf("\n\n\tDIGITE UMA OPCAO: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            //system("cls");
            printf("\n\n\tDIGITE O NOME DE UM DOS USUARIOS: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            printf("\n\n\tDIGITE O NOME DO OUTRO USUARIO: ");
            fflush(stdin);
            fgets(user_aux.nome, 100, stdin);
            if(pesquisar(*rede, user) != -1 && pesquisar(*rede, user_aux) != -1)
            {
                printf("\n\n\tAMIZADE CADASTRADA COM SUCESSO !");
                cadastrarAmizades(rede, user, user_aux);
            }
            else
            {
                printf("\n\n\tUSUARIO(S) NAO CADASTRADO(S), NAO FOI POSSIVEL CADASTRAR AMIZADE !");
            }
            printf("\n\n\tPRESSIONE UMA TECLA PARA CONTINUAR !");
            fflush(stdin);
            getchar();
            //system("pause);
            break;

        case 2:
            //system("cls");
            printf("\n\n\tDIGITE O NOME DE UM DOS USUARIOS: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            printf("\n\n\tDIGITE O NOME DO OUTRO USUARIO: ");
            fflush(stdin);
            fgets(user_aux.nome, 100, stdin);
            if(pesquisarAmizades(*rede, user, user_aux) == 1)
            {
                printf("\n\n\tOS DOIS USUARIOS SAO AMIGOS !");
            }
            else
            {
                printf("\n\n\tOS USUARIOS NAO SAO AMIGOS !");
            }
            printf("\n\n\tPRESSIONE UMA TECLA PARA CONTINUAR !");
            fflush(stdin);
            getchar();
            //system("pause);
            break;

        case 3:
            //system("cls");
            printf("\n\n\tDIGITE O NOME DE UM DOS USUARIOS: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            printf("\n\n\tDIGITE O NOME DO OUTRO USUARIO: ");
            fflush(stdin);
            fgets(user_aux.nome, 100, stdin);
            if(pesquisarAmizades(*rede, user, user_aux) == 1)
            {
                printf("\n\n\tAMIZADE EXCLUIDA COM SUCESSO !");
                excluirAmizades(rede, user, user_aux);
            }
            else
            {
                printf("\n\n\tOS USUARIOS NAO SAO AMIGOS !");
            }
            printf("\n\n\tPRESSIONE UMA TECLA PARA CONTINUAR !");
            fflush(stdin);
            getchar();
            //system("pause);
            break;

        case 4:
            //system("cls");
            printf("\n\n\tDIGITE O NOME DO USUARIO: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            if(pesquisar(*rede, user) != -1)
            {
                printf("\n\n\tLISTA DE AMIGOS DO USUARIO DIGITADO: ");
                imprimirAmizades(*rede, user);
            }
            else
            {
                printf("\n\n\tESTE USUARIO NAO ESTA CADASTRADO NA REDE SOCIAL !");
            }
            printf("\n\n\tPRESSIONE UMA TECLA PARA CONTINUAR !");
            fflush(stdin);
            getchar();
            //system("pause);
            break;

        case 5:
            //system("cls");
            if(rede->indice > 0)
            {
                printf("\n\n\tUSUARIO MAIS POPULAR DA REDE SOCIAL: ");
                imprimir(rede->vetor[maisPopular(*rede)]);
            }
            else
            {
                printf("\n\n\tA REDE SOCIAL NAO POSSUI NENHUM USUARIO !");
            }
            printf("\n\n\tPRESSIONE UMA TECLA PARA CONTINUAR !");
            fflush(stdin);
            getchar();
            //system("pause);
            break;

        case 6:
            //system("cls");
            printf("\n\n\tDIGITE O ID DE UM USUARIO: ");
            fflush(stdin);
            scanf("%d", &user.ID);
            printf("\n\n\tDIGITE O ID DO OUTRO USUARIO: ");
            fflush(stdin);
            scanf("%d", &user_aux.ID);
            if(pesquisarAmizades(*rede, user, user_aux) == 0)
            {
                printf("\n\n\tOS DOIS USUARIOS POSSUEM %d AMIGOS EM COMUM !", amizadesEmComum(*rede, user.ID, user_aux.ID));
            }
            else
            {
                printf("\n\n\tOS DOIS USUARIOS SAO AMIGOS !");
            }
            printf("\n\n\tPRESSIONE UMA TECLA PARA CONTINUAR !");
            fflush(stdin);
            getchar();
            //system("pause);
            break;

        case 7:
            //system("cls");
            printf("\n\n\tMATRIZ DE AMIGOS EM COMUM: \n\n");
            matrizDeAmigosEmComum(rede);
            printf("\n\n\tPRESSIONE UMA TECLA PARA CONTINUAR !");
            fflush(stdin);
            getchar();
            //system("pause);
            break;

        case 8:
            //system("cls");
            printf("\n\n\tDIGITE O NOME DE UM DOS USUARIOS: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            printf("\n\n\tDIGITE O NOME DO OUTRO USUARIO: ");
            fflush(stdin);
            fgets(user_aux.nome, 100, stdin);
            int id1 = pesquisar(*rede, user);
            int id2 = pesquisar(*rede, user_aux);
            if((id1 != -1) && (id2 != -1) && pesquisarAmizades(*rede, user, user_aux) == 0)
            {
                user.ID = id1;
                user_aux.ID = id2;
                if(nenhumAmigoEmComum(rede, user, user_aux) == 1)
                {
                    printf("\n\n\tUSUARIOS SEM NENHUM AMIGO EM COMUM: ");
                    imprimir(rede->vetor[rede->semAmigosEmComum[0]]);
                    imprimir(rede->vetor[rede->semAmigosEmComum[1]]);
                }
                else
                {
                    printf("\n\n\tOS USUARIOS POSSUEM AMIGOS EM COMUM !");
                }
            }
            else
            {
                printf("\n\n\tOS USUARIOS SAO AMIGOS !");
            }
            printf("\n\n\tPRESSIONE UMA TECLA PARA CONTINUAR !");
            fflush(stdin);
            getchar();
            //system("pause);
            break;

        case 9:
            //system("cls");
            printf("\n\n\tDIGITE O NOME DE UM DOS USUARIOS: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            printf("\n\n\tDIGITE O NOME DO OUTRO USUARIO: ");
            fflush(stdin);
            fgets(user_aux.nome, 100, stdin);
            if(pesquisarAmizades(*rede, user, user_aux) == 0)
            {
                printf("\n\n\tOS USUARIOS NAO SAO AMIGOS !");
                if(amizadeIndiretaNivelUm(rede, user, user_aux) >= 0)
                {
                    printf("\n\n\tUSUARIO INTERMEDIARIO DA AMIZADE: ");
                    imprimir(rede->vetor[rede->IDintermediarios[0]]);
                }
                else
                {
                    printf("\n\n\tELES NAO POSSUEM AMIGOS EM COMUM !");
                }
            }
            else
            {
                printf("\n\n\tOS USUARIOS SAO AMIGOS !");
            }
            printf("\n\n\tPRESSIONE UMA TECLA PARA CONTINUAR !");
            fflush(stdin);
            getchar();
            //system("pause);
            break;

        case 10:
            //system("cls");
            printf("\n\n\tDIGITE O NOME DE UM DOS USUARIOS: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            printf("\n\n\tDIGITE O NOME DO OUTRO USUARIO: ");
            fflush(stdin);
            fgets(user_aux.nome, 100, stdin);
            if(pesquisarAmizades(*rede, user, user_aux) == 0)
            {
                printf("\n\n\tOS USUARIOS NAO SAO AMIGOS !");
                if(amizadeIndiretaNivelDois(rede, user, user_aux))
                {
                    printf("\n\n\tUSUARIOS INTERMEDIARIOS DA AMIZADE: ");
                    imprimir(rede->vetor[rede->IDintermediarios[0]]);
                    imprimir(rede->vetor[rede->IDintermediarios[1]]);
                }
                else
                {
                    printf("\n\n\tELES NAO POSSUEM RELACAO DE AMIZADE INDIRETA NIVEL 2 !");
                }
            }
            else
            {
                printf("\n\n\tOS USUARIOS SAO AMIGOS !");
            }
            printf("\n\n\tPRESSIONE UMA TECLA PARA CONTINUAR !");
            fflush(stdin);
            getchar();
            //system("pause);
            break;


        case 11:
            //system("cls");
            printf("\n\n\tPRESSIONE UMA TECLA PARA VOLTAR AO MENU PRINCIPAL!");
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
    while(opcao != 11);
}


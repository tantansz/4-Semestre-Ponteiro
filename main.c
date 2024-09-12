#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{

    int code;
    char nome[20];
    struct no *next;

} no;

struct no *inicio, *corrt, *auxil, *auxil2;


void enterdata()
{
    printf("Informe o codigo: ");
    scanf("%d", &corrt->code);
    printf("Informe o nome: ");
    scanf("%s",&corrt->nome);
}

void classinsert()
{

    if(inicio == NULL)
    {

        corrt = (no*)malloc(sizeof(no));

        enterdata();

        inicio = corrt;
        auxil = corrt;


    }
    else
    {
        auxil = inicio;
        while(auxil->next != NULL)
        {
            auxil = auxil->next;
        }

        corrt = auxil;

        corrt = (no*)malloc(sizeof(no));
        enterdata();

        auxil = inicio;

        if(strcmp(corrt->nome, auxil->nome) < 0)
        {

            corrt->next = auxil;
            inicio = corrt;

        }
        else
        {

            if(auxil2 == NULL || strcmp(corrt->nome, auxil2->nome) >= 0)
            {

                auxil2 = corrt;
                auxil2->next = NULL;

                auxil = inicio;
                while(auxil->next != NULL)
                {
                    auxil = auxil->next;
                }
                auxil->next = auxil2;

            }
            else
            {

                auxil = inicio;

                while(strcmp(corrt->nome, auxil->next->nome) > 0)
                {
                    auxil = auxil->next;
                }

                auxil2 = auxil->next;
                if(auxil2 == NULL)
                {
                    auxil2 = auxil;
                }
                auxil->next = corrt;
                corrt->next = auxil2;

            }
        }
    }
}

void class()
{

    int achou = 0;
    corrt = (no*)malloc(sizeof(no));
    enterdata();
    auxil = inicio;
    achou = 0;

    if(inicio == NULL)
    {

        auxil = corrt;
        corrt->next = NULL;
        inicio = corrt;
        printf("\n Instalado primeiro na lista\n");
        system("pause");
        achou = 1;

    }
    else
    {

        if(strcmp(corrt->nome, auxil->nome) <= 0)
        {

            corrt->next = auxil;
            inicio = corrt;
            printf("\n Elemento antecede o primeiro da lista\n");
            system("pause");
            achou = 1;

        }
        else
        {

            auxil2 = auxil->next;

            while(auxil2 != NULL)
            {

                if(strcmp(corrt->nome, auxil->nome) >= 0 && strcmp(corrt->nome, auxil2->nome) <= 0)
                {

                    auxil->next = corrt;
                    corrt->next = auxil2;
                    achou = 1;
                    printf("\n Elemento foi inserido no meio da lista\n");
                    system("pause");
                    break;

                }
                else
                {

                    auxil2 = auxil2->next;
                    auxil = auxil->next;

                }

            }

        }

    }

    if(strcmp(corrt->nome, auxil->nome) >= 0 && achou == 0)
    {

        auxil->next = corrt;
        corrt->next = NULL;
        printf("\n Elemento inserido no final da lista\n");
        system("pause");

    }

}

/*void insert(){

    if(inicio == NULL){

        corrt = (no*)malloc(sizeof(no));
        auxil = corrt;
        inicio = corrt;
        corrt->next = NULL;
        enterdata();

    }else{

        auxil = inicio;
        while(auxil->next != NULL){
            auxil = auxil->next;
        }
        corrt = auxil;

        corrt = (no*)malloc(sizeof(no));
        auxil->next = corrt;
        auxil = corrt;
        corrt->next = NULL;
        enterdata();

    }

}*/


void exibir()
{

    if(inicio == NULL)
    {

        printf("\n Lista vazia.\n");
        system("pause");

    }
    else
    {

        auxil = inicio;

        while(auxil != NULL)
        {

            printf("\nCodigo: %d", auxil->code);
            printf("\nNome: %s", auxil->nome);
            printf("\nEndereco next: %p", auxil->next);
            printf("\nEndereco do auxiliar (atual): %p\n", auxil);

            auxil = auxil->next;

        }

        printf("\n");
        system("pause");

    }
}

void consultar()
{

    char xnome[20];
    int achou = 0;

    if (inicio == NULL)
    {

        printf("\n Lista vazia.\n");
        system("pause");

    }
    else
    {

        printf("\n Informe o nome a ser consultado: ");
        scanf("%s", &xnome);

        auxil = inicio;
        achou = 0;

        while(auxil != NULL)
        {

            if(strcmp(auxil->nome, xnome) == 0)
            {

                printf("\n Elemento encontrado na lista.\n");
                system("pause");

                achou = 1;
                break;

            }
            else
            {

                auxil = auxil->next;

            }

        }


        if (achou == 0)
        {

            printf("\n Registro nao encontrado na lista.\n");
            system("pause");

        }
    }
}

void remover()
{

    if(inicio == NULL)
    {

        printf("\nLista vazia.\n");
        system("pause");

    }
    else
    {

        int xcode = 0;
        int removeu = 0;

        printf("Informe o codigo do elemento a ser removido: ");
        scanf("%d", &xcode);

        auxil = inicio;

        while(auxil != NULL)
        {

            if(auxil->code == xcode)
            {
                if(auxil->code == inicio->code)
                {

                    inicio = inicio->next;
                    free(auxil);
                    removeu = 1;
                    break;

                }
                else
                {

                    auxil->next = corrt->next;
                    auxil = auxil->next;
                    free(corrt);
                    removeu = 1;
                    break;

                }
            }

        }

        if(removeu != 1)
        {

            printf("\nElemento nao encontrado.\n");
            system("pause");

        }
    }
}

void alterar()
{


    int xcode;
    int achou = 0;

    if (inicio == NULL)
    {

        printf("\n Lista vazia.\n");
        system("pause");

    }
    else
    {

        printf("\n Informe o codigo do elemento a ser alterado: ");
        scanf("%d", &xcode);

        auxil = inicio;
        achou = 0;

        while(auxil != NULL)
        {

            if(auxil->code == xcode)
            {

                enterdata();

                achou = 1;
                break;

            }
            else
            {

                auxil = auxil->next;

            }

        }


        if (achou == 0)
        {

            printf("\n Registro nao encontrado na lista.\n");
            system("pause");

        }
    }

}

int main()
{
    auxil = NULL;
    auxil2 = NULL;
    corrt = NULL;
    inicio = NULL;

    int op;

    do
    {

        system("cls");

        printf("\n [1] - Inserir elemento na lista em ordem alfabetica.");
        printf("\n [2] - Exibir dados da lista.");
        printf("\n [3] - Consultar elemento na lista.");
        printf("\n [4] - Remover elemento na lista.");
        printf("\n [5] - Alterar elemento na lista.");

        printf("\n Informe a opcao: ");
        scanf("%d", &op);

        switch(op)
        {

        case 1:
            class();
            break;

        case 2:
            exibir();
            break;

        case 3:
            consultar();
            break;

        case 4:
            remover();
            break;

        case 5:
            alterar();
            break;

        default:
            printf("\n Opcao invalida");
            system("pause");

        }

    }
    while(op != 0);
    return 0;

}

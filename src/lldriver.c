/*
  Arquivo: LLDRIVER.C
  Autor: Roberto Bauer
  Observacoes:
              Le textos de um arquivo especifico da linha de comando
              e o coloca em duas listas encadeadas. Entaoh executa uma
              variedade de atividades de lista encadeada, imprimindo o
              resultado a cada passo.
*/

#define __LLDRIVER_C__

#include "main.h"


int LLDriver(int argc, char *argv[])
{
    char name[128];              // bufer de leitura da palavra no arquivo
    int count;

    SLIST *L1, *L2;             // duas listas encadeadas diferentes
    SLINK w1, w2, w3;           // cursores p/ percorrer as lista

    FILE *fin;                  // arquivo de entrada


    if (argc != 2)
    {
        fprintf(stderr, "ERRO! Uso: LinkedListGen arquivo.ext\n");
        exit(EXIT_FAILURE);
    }

    fin = fopen(argv[1], "rt");
    if (fin == NULL) 
    {
        fprintf(stderr, "Naoh conseguir encontrar/abrir o arquivo %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // configura a estrutura de dados da lista encadeada
    L1 = CreateLList(   CreateData1,
                        DeleteData1,
                        DuplicatedNode1,
                        NodeDataCmp1);

    L2 = CreateLList(   CreateData2,
                        DeleteData2,
                        DuplicatedNode2,
                        NodeDataCmp2);

    if ((L1 == NULL) || (L2 == NULL))
    {
        fprintf(stderr, "Erro criando lista encadeada\n");
        exit(EXIT_FAILURE);
    }

    // comecah a processar o arquivo
    while (fgets(name, 128, fin) != NULL)
    {
        if (strlen(name) > 0)
        {
            name[strlen(name) - 1] = '\0';  // elimina o \n
        }

        // adiciona a palavra em ambas as lista
        if (!AddNodeAscend(L1, name))
        {
            fprintf(stderr, "AVISO! Erro ao adicionar noh em L1.\n");
        }
        if (!AddNodeAtHead(L2, name))
        {
            fprintf(stderr, "AVISO! Erro ao adicionar noh em L2.\n");
        }

    }
    fclose(fin);

    // agora, percorre as listas
    printf("L1 contem %u item(ns):\n", L1->uiCount);
    for (w1 = L1->slkHead; w1 != NULL; w1 = w1->next) {
        printf(" %s ocorre %d vez(es).\n", ((pND1) (w1->pdata))->pName,  ((pND1) (w1->pdata))->uCont);
    }
    printf("\n\n");

    printf("L2 contem %u item(ns):\n", L2->uiCount);
    for (w1 = L2->slkHead; w1 != NULL; w1 = w1->next) {
        printf(" %s\n", ((pND2) (w1->pdata))->pName);
    }
    printf("\n\n");

    // ambas ao mesmo tempo
    printf("L2 contem %u item(ns):\n", L2->uiCount);
    w1 = L2->slkHead;
    w2 = L2->slkTail;
    for (; w1 != NULL && w2 != NULL; w1 = w1->next,  w2 = w2->prior) {
        printf(" %30s %30s\n", ((pND2) (w1->pdata))->pName, ((pND2) (w2->pdata))->pName);
    }   
    printf("\n\n");

    // "Encontra" cada noh e apaga os outros
    count = 0;
    w1 = L2->slkHead;
    while (w1 != NULL) 
    {
        w3 = FindNode(L2, w1->pdata);
        if (w3 != 0)
        {
            printf("Encontrou noh %s", ((pND2) (w3->pdata))->pName);
            ++count;
            w1 = w3->next;
            if (count & 1)
            {
                DeleteNode(L2, w3);
                printf(" e apagou o mesmo.");
            }
            printf("\n");
        }
        else
            w1 = NULL;
    }
    printf("\n\n");

    printf("L2 contem %u item(ns):\n", L2->uiCount);
    w1 = L2->slkHead;
    w2 = L2->slkTail;
    for ( ; w1 != NULL && w2 != NULL; w1 = w1->next, w2 = w2->prior)
    {
        printf(" %30s %30s\n", ((pND2)(w1->pdata))->pName, ((pND2)(w2->pdata))->pName);
    }
    printf("\n\n");

    // "Encontra" cada noh e apaga os outros
    count = 0;
    w1 = L1->slkHead;
    while (w1 != NULL) 
    {
        w3 = FindNode(L1, w1->pdata);
        if (w3 != 0)
        {
            printf("Encontrou noh %s", ((pND1) (w3->pdata))->pName);
            ++count;
            w1 = w3->next;
            if (count & 1)
            {
                DeleteNode(L1, w3);
                printf(" e apagou o mesmo.");
            }
            printf("\n");
        }
        else
            w1 = NULL;
    }
    printf("\n\n");

    printf("L1 contem %u item(ns):\n", L1->uiCount);
    w1 = L1->slkHead;
    w2 = L1->slkTail;
    for ( ; w1 != NULL && w2 != NULL; w1 = w1->next, w2 = w2->prior)
    {
        printf(" %30s %30s\n", ((pND1)(w1->pdata))->pName, ((pND1)(w2->pdata))->pName);
    }
    printf("\n\n");
    return (EXIT_SUCCESS);
}



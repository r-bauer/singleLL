/*
  Arquivo: LLAPP.C
  Autor: Roberto Bauer
  Observacoes:
              Dados especificos da aplicacaoh p/ lista encadeada
*/

#define __LLAPP_C__

#include "main.h"


void *CreateData1(void *data)
{
    SNODEDATA1 *pNewData;

    // aloca sua estrutura de dados
    pNewData = (SNODEDATA1 *) malloc(sizeof(SNODEDATA1));
    if (pNewData == NULL)
        return (NULL);

    // move os valores para a estrutura de dados
    pNewData->uCont = 1;
    pNewData->pName = strdup((char *) data);

    if (pNewData->pName == NULL)     // erro copiando a string
    {
        free(pNewData);
        return (NULL);
    }
    else
    {
        return (pNewData);            // retorna o endereco da estrutura
    }
}

BOOL  DeleteData1(void *data)
{
    // neste caso NodeData1 consiste em : um ponteiro e um inteiro.
    // O inteiro retorna para a memoria quando o noh eh liberado
    // Sendo nescessario liberar a string manualmente
    free( ((pND1) data)->pName);
    return TRUE;
}

// Estah funcaoh determina o que fazer quando se insere um noh na lista
// onde jah se encontra outro noh com a mesma informacaoh.
// Neste caso estamos contando as palavras, se uma palavra duplicada eh
// encontrada, incrementa-se o contador.
//
// Note que estah funcaoh deve retornar um dos seguintes valores
//      0   um erro aconteceu
//      1   apagar o noh duplicado
//      2   inserir o noh duplicado
// Qualquer outro processamento na informacaoh duplicada deve ser 
// feito dentro desta funcaoh.
//
int   DuplicatedNode1(SLINK slkNewNode, SLINK slkListNode)
{
    pND1 pnd;

    // transforma o ponteiro de dados do noh, no ponteiro da aplicacaoh
    pnd = slkListNode->pdata;
    // adiciona-se uma ocorrencia para a palavra existente
    pnd->uCont += 1;

    return 1;
}

int   NodeDataCmp1(void *first, void *second)
{
    return (strcmp( ((pND1) first)->pName, ((pND1) second)->pName));
}



//***************************************************************************//
//***************************************************************************//


void *CreateData2(void *data)
{
    SNODEDATA2 *pNewData;

    // aloca sua estrutura de dados
    pNewData = (SNODEDATA2 *) malloc(sizeof(SNODEDATA2));
    if (pNewData == NULL)
        return (NULL);

    // move os valores para a estrutura de dados
    pNewData->pName = strdup((char *) data);

    if (pNewData->pName == NULL)     // erro copiando a string
    {
        free(pNewData);
        return (NULL);
    }
    else
    {
        return (pNewData);            // retorna o endereco da estrutura
    }
}

BOOL  DeleteData2(void *data)
{
    // neste caso NodeData2 consiste em : um ponteiro e um inteiro.
    // Sendo nescessario libera a string manualmente
    free( ((pND2) data)->pName);
    return TRUE;
}

// esta lista insere nohs duplicados
int   DuplicatedNode2(SLINK slkNewNode, SLINK slkListNode)
{
    return (2);
}

int   NodeDataCmp2(void *first, void *second)
{
    return (strcmp( ((pND2) first)->pName, ((pND2) second)->pName));
}

/*
  Arquivo: LLAPP.H
  Autor: Roberto Bauer
  Observacoes:
              Dados especificos da aplicacaoh p/ lista encadeada
*/


#ifndef __LLAPP_H__
#define __LLAPP_H__

#undef EXTERN
#ifdef __LLAPP_C__
    #define EXTERN
#else
    #define EXTERN  extern
#endif


// A primeira lista de noh consiste em:
typedef struct tagSNODEDATA1
{
    char *pName;         //  ponteiros para palavras
    unsigned int uCont;     // e a contagem de ocorrencias
}SNODEDATA1;

typedef SNODEDATA1 *      pND1;

EXTERN void *CreateData1( void * );
EXTERN BOOL  DeleteData1( void * );
EXTERN int   DuplicatedNode1( SLINK, SLINK );
EXTERN int   NodeDataCmp1( void *, void * );


// A segunda lista de noh consiste em:
typedef struct tagSNODEDATA2
{
    char *pName;         //  ponteiros para palavras

}SNODEDATA2;

typedef SNODEDATA2 *      pND2;



EXTERN void *CreateData2( void * );
EXTERN BOOL  DeleteData2( void * );
EXTERN int   DuplicatedNode2( SLINK, SLINK );
EXTERN int   NodeDataCmp2( void *, void * );


#endif  // #define __LLAPP_H__

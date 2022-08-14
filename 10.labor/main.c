#include <stdio.h>
#include <stdlib.h>

typedef struct ListaElem {
    int adat;
    struct ListaElem *kov;
} ListaElem;

typedef struct list_elem
{

}

int hossza(ListaElem *eleje)
{
    ListaElem *mozgo;
    int meret = 0;
    for(mozgo = eleje;mozgo != NULL;mozgo = mozgo->kov)
    {
        meret++;
    }
    return meret;
}
/* létrehoz egy listát, benne egy csomó számmal */
ListaElem *lista_letrehoz(void) {
    int szamok[] = { 8, 14, 13, 17, 1, 19, 16, 5, 3, 11, 2,
                     15, 9, 10, 6, 22, 4, 7, 18, 27, -1 };
    ListaElem *lis = NULL;

    for (int i = 0; szamok[i] != -1; ++i) {
        ListaElem *u;
        u = (ListaElem*) malloc(sizeof(ListaElem));
        u->kov = lis;
        u->adat = szamok[i];
        lis = u;
    }
    return lis;
    /*mert elore tölti fel adatokkal*/
}
void felsz(ListaElem *eleje)
{
    ListaElem *torolt = eleje;
    ListaElem *proba;
    while(torolt != NULL)
    {
        proba = torolt->kov;
        free(torolt);
        torolt = proba;
    }
}

ListaElem *beszur(ListaElem *eleje, int szam)
{
    ListaElem *uj;
    uj = (ListaElem*) malloc(sizeof(ListaElem));
    uj->adat = eleje->adat;
    uj->kov = eleje->kov;
    eleje->kov = uj;
    eleje->adat = szam;
    return eleje;

}
void hozza(ListaElem *eleje, int szam)
{
    ListaElem *mozgo = eleje;
    while(mozgo->kov != NULL)
    {
        mozgo = mozgo->kov;
    }
    ListaElem *uj;
    uj = (ListaElem*) malloc(sizeof(ListaElem));
     mozgo->kov = uj;
     uj->kov = NULL;
     uj->adat = szam;
}
ListaElem *keres(ListaElem *eleje,int szam)
{
    ListaElem *mozgo = eleje;
    while(mozgo->adat != szam)
    {
        mozgo = mozgo->kov;
    }
    if(mozgo->adat == szam)
    {
        return mozgo;
    }
    else
    {
        return NULL;
    }
}
int main(void) {
    ListaElem *eleje;
    ListaElem *mozgo;
    eleje = lista_letrehoz();
    eleje = beszur(eleje, 98);
    hozza(eleje,111);
    for(mozgo = eleje;mozgo != NULL;mozgo = mozgo ->kov)
        printf("%d ",mozgo->adat);
        printf("\n");
        int meret = hossza(eleje);
    printf("%d ",meret);
    ListaElem *talal;
    talal = keres(eleje,111);
    printf("%p",talal);

    felsz(eleje);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct BiFa {
    int ertek;
    struct BiFa *bal, *jobb;
} BiFa;

BiFa *beszur(BiFa *gyoker, int ertek) {
    if (gyoker == NULL) {
        BiFa *uj = (BiFa*) malloc(sizeof(BiFa));
        uj->ertek = ertek;
        uj->bal = uj->jobb = NULL;
        return uj;
    }
    if (ertek < gyoker->ertek) {        /* balra szur */
        gyoker->bal = beszur(gyoker->bal, ertek);
    }
    else if (ertek > gyoker->ertek) {   /* jobbra szur */
        gyoker->jobb = beszur(gyoker->jobb, ertek);
    }
    else {
        /* mar benne van */
    }
    return gyoker;
}
void kiir(BiFa *gyoker)
{
    if(gyoker != NULL)
    {
        kiir(gyoker->bal);
        printf("%d ",gyoker->ertek);
        kiir(gyoker->jobb);
    }
}

void felszab(BiFa *gyoker)
{
   if(gyoker != NULL)
    {
        felszab(gyoker->bal);
        felszab(gyoker->jobb);
        free(gyoker);
    }
}
int oszad(BiFa *gyoker)
{
    if(gyoker != NULL)
    {
        return oszad(gyoker->bal) + oszad(gyoker->jobb)+gyoker->ertek;
    }
    return 0;
}
int dab(BiFa *gyoker)
{
    if(gyoker != NULL)
    {
        return dab(gyoker->bal) +dab(gyoker->jobb) +1;
    }
     return 0;

}
int *keres(BiFa *gyoker,int elem)
{
    if(gyoker == NULL)
        return NULL;
    if(gyoker->ertek == elem) return gyoker;
    else if(elem<=gyoker->bal->ertek)
        keres(gyoker->bal,elem);
    else if(elem>=gyoker->jobb->ertek)
        keres(gyoker->jobb,elem);
}
void negal(BiFa *gyoker)
{
    if(gyoker != NULL)
    {
        negal(gyoker->bal);
        gyoker->ertek = gyoker->ertek *(-1);
        negal(gyoker->jobb);
    }
}
void tukor(BiFa *gyoker)
{
    if(gyoker != NULL)
    {

        BiFa *csere;
        csere = gyoker->bal;
        gyoker->bal = gyoker->jobb;
        gyoker->jobb = csere;
        tukor(gyoker->bal);
        tukor(gyoker->jobb);

    }
}

int main(void) {
    int minta[] = {15, 96, 34, 12, 14, 56, 21, 11, 10, 9, 78, 43, 0};
    BiFa *gyoker = NULL;
    for (int i = 0; minta[i] > 0; i++)
        gyoker = beszur(gyoker, minta[i]);
    kiir(gyoker);
    int osszeg =0;
    int db = 0;
    db = dab(gyoker);
    osszeg = oszad(gyoker);
    printf("\n%d\n%d",osszeg,db);
    int elem;
    scanf("%d",&elem);
    int *vissza = keres(gyoker,elem);
    printf("\nElem: %d\n",*vissza);
    negal(gyoker);
    kiir(gyoker);
    tukor(gyoker);
    printf("\n");
    kiir(gyoker);
    /* Ide tedd be a kipróbálandó függvények hívásait! */
    felszab(gyoker);
    printf("\n");
    return 0;
}

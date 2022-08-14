#include <stdlib.h>
#include <stdio.h>
#include "debugmalloc.h"
#include "memory_management.h"

int **foglal(int p_meret)                           //amikor a függvény meghívódik akkor megkapja a pályaméretét
{
    int **tomb;                                     //létrehozzunk a pointerre mutató pointert
    tomb = (int**) malloc(p_meret * sizeof(int*));  //lefoglaljuk a mátrix törzsének a helyet
    if(tomb == NULL)
    {
        perror("Nem a program nem tud lefutni. Nem all rendelkezesre eleg memoria.");
    }
    for(int i = 0; i< p_meret;i++)
    {
        tomb[i] = (int*)malloc(p_meret*sizeof(int));    //lefoglaljuk a mátrix elemein számára fenn tartott memória teruleteket
        if(tomb[i] == NULL)
            {
                perror("Nem a program nem tud lefutni. Nem all rendelkezesre eleg memoria.");
            }
    }

    for(int i = 0; i<p_meret;i++)
    {
        for(int j = 0; j<p_meret;j++)
        {
            tomb[i][j] = 0;
        }
    }
    return tomb;                                        //visszatérünk a mátrix "pointerével"
}

void felszab(int **palya,int meret)
{
    for(int i = 0; i < meret ;i++)
    {
        free(palya[i]);
    }
    free(palya);
}

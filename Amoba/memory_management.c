#include <stdlib.h>
#include <stdio.h>
#include "debugmalloc.h"
#include "memory_management.h"

int **foglal(int p_meret)                           //amikor a f�ggv�ny megh�v�dik akkor megkapja a p�lyam�ret�t
{
    int **tomb;                                     //l�trehozzunk a pointerre mutat� pointert
    tomb = (int**) malloc(p_meret * sizeof(int*));  //lefoglaljuk a m�trix t�rzs�nek a helyet
    if(tomb == NULL)
    {
        perror("Nem a program nem tud lefutni. Nem all rendelkezesre eleg memoria.");
    }
    for(int i = 0; i< p_meret;i++)
    {
        tomb[i] = (int*)malloc(p_meret*sizeof(int));    //lefoglaljuk a m�trix elemein sz�m�ra fenn tartott mem�ria teruleteket
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
    return tomb;                                        //visszat�r�nk a m�trix "pointer�vel"
}

void felszab(int **palya,int meret)
{
    for(int i = 0; i < meret ;i++)
    {
        free(palya[i]);
    }
    free(palya);
}

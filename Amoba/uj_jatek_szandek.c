#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "econio.h"
#include "uj_jatek_szandek.h"


bool uj_jatek_szandek(int meret)
{
    //amikor a jatek v�get �r a felhaszn�l�t�l mmegk�rdezz�k, hogy szeretn�-e folytatni a program haszn�lat�t �s j�tszani egy �jabbb j�t�kot
    char valasz_uj_jatekra[10];
    int iq = 1;
    while(1)
    {
        if(iq != 1)
        {
            econio_clrscr();
        }
        iq--;
        printf("\nSzeretne uj jatekot kezdeni?\n(igen/nem)\n");
        scanf("%s",&valasz_uj_jatekra);
        if(!(strcmp("igen",valasz_uj_jatekra))||!(strcmp("IGEN",valasz_uj_jatekra)))
            {
                return true;
            }
        else if(!(strcmp("nem",valasz_uj_jatekra))||!(strcmp("NEM",valasz_uj_jatekra)))
            {
                return false;
            }
    }
}

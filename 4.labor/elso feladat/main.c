#include <stdio.h>
#include <stdlib.h>

int main()
{
    double tomb[10] = {2.5,-69,5.4,-8,-7.7,6,2.9,-10,-3,9.8};
    int idx[10];
    int sv= 0;
    int all = 0;

    for(int i = 0;i<10;++i)
    {
        if(tomb[i]<0)
        {
            idx[sv] = i;
            sv++;
        }
        all++;
    }

    sv--;
    printf("Osszesen %d szam van.\n",all);

    for(int i = 0; i <all;i++)
    {
        printf("[%d]=%g  ",i,tomb[i]);
    }

    printf("\n\nEbbol %d szam negativ.\n",sv+1);

    for(int i = 0; i <=sv;i++)
    {
        printf("[%d]=%g ",idx[i],tomb[idx[i]]);
    }

    return 0;
}

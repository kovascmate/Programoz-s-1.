#include <stdio.h>
#include "filekezeles.h"
#include "debugmalloc.h"
#include "memory_management.h"
//kiir függvény elmenti fájlba az aktuális játéállapotot
void kiir(char *nev,int meret,int szint,int **palya)
{
    FILE *fk;
    fk = fopen("jatek.txt","w");
    if(fk != NULL)
    {
        fprintf(fk,"%d\n%s\n%d\n",meret,nev,szint);
        for(int i =0;i<meret;i++)
        {
            for(int j = 0; j <meret;j++)
            {
                fprintf(fk,"%d ",palya[j][i]);
            }
            fprintf(fk,"\n");
        }
    fclose(fk);
    }
    else
    {
        perror("Hiba, nem lehet megnyitni a fajlt");
    }
   felszab(palya,meret);
}
//a beol függvény mentett játék visszatöltését és elinditásának meghívásáért felelõs
void beol()
{
    int meret;
    char nev[13];
    int szint;
    int kov;
    FILE *fb;
    fb = fopen("jatek.txt","r");
    if(fb != NULL)
    {
        fscanf(fb,"%d\n%s\n%d\n",&meret,&nev,&szint);
        int **palya = foglal(meret);
        for(int i =0;i<meret;i++)
        {
            for(int j = 0; j <meret;j++)
            {
                fscanf(fb,"%d ",&palya[j][i]);
            }
            fscanf(fb,"\n");
        }
        fclose(fb);
        if(csomopont(palya,meret,nev,szint)==true)
        {
            adatbe();
        }
    }
    else
    {
        perror("Hiba, nem lehet megnyitni a fajlt");
    }
}

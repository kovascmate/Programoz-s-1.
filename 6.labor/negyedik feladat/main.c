#include <stdio.h>
#include <stdlib.h>

int keres(int *tomb, int ad,int meret, int *talal)
{
    *talal = NULL;
    for(int i = 0; i <meret;i++)
    {
        if(*tomb == ad)
        {
            talal = tomb;
        }
    }
    return 0;
}
int main()
{
    int *talalat;
    int szamok[10] = {2,6,7,9,10,11,16,20,69,100};
    int adott = 69;
    keres(&szamok,10,&adott,&talalat);
    if(talalat != NULL)
    {
        printf("A(z) %d a %p memoria helyen talalhato.",adott,talalat);
    }
    else
        printf("Nem talalhato a(z) %d",adott);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
void ki(int szam)
{
    szam = szam/1000;
    if(szam%1000 <1000)
    {
        printf("%d ",szam);
        return;
    }
    else
    {
        ki(szam);
        if(szam%1000 == 0)
        {
            printf("000 ");
        }
        else
        printf("%d ",(szam%1000));
    }
}
int main()
{
    int szam;
    printf("Adja meg a szamot:\n");
    scanf("%d",&szam);
    szam = szam *1000;
    ki(szam);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
valto(int szam,int szr)
{
    szam = szam /szr;
    if(szam<szr)
    {if(9<szam%szr)
        {
            printf("%c",'A'+(szam%szr)-10);
        }
        else
        printf("%d",szam%szr);
        return;
    }
    else
    {
        valto(szam,szr);
        if(9<szam%szr)
        {
            printf("%c",'A'+(szam%szr)-10);
        }
        else
        printf("%d",szam%szr);
    }
}
int main()
{
    int szam;
    int szr;
    int ered;
    printf("Szam:");
    scanf("%d",&szam);
    printf("Szamrendszer:");
    scanf("%d",&szr);
    printf("\n");
    szam =szam*szr;
    ered = valto(szam,szr);
    return 0;
}

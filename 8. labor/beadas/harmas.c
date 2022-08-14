#include <stdio.h>
#include <stdlib.h>
//alapbol ugy alltam neki hogy fuggvenyben
char* asd(char *pista,int meret)
{   meret+=1;
    char *p =(char*)malloc(meret*sizeof(char));

    for(int i = 0; i < meret-1;i++)
    {
        p[i] = pista[i];
    }
    free(pista);
    scanf("%c",&p[meret-1]);
    if(p[meret-1] != '\n')
    {
      return asd(p,meret);
    }
    else
    {
        p[meret-1] = '\0';
        return p;
        }
}

int main()
{
    char *sor=asd(NULL,0);
    printf("%s",sor);
    free(sor);
    return 0;
}

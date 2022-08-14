#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nev[13] = {0};
    printf("Adja meg a keresztnevet:");
    scanf("%s",nev);
    for(int i = 0; i < strlen(nev);++i)
    {
        printf("%c\n",nev[i]);
    }
    return 0;

}

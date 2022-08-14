#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tomb[10] ={25, 69, 54, 8, 77, 6, 29, 10, 3, 98};
    int kicsi = tomb[0];
    int minhely = 0;

    printf("A tömb: ");

    for(int i = 0; i<10; ++i)
    {
        if(tomb[i]<kicsi)
        {
            kicsi = tomb[i];
            minhely = i;
        }
    }

    for(int i = 0; i<10;++i)
    {
        if(minhely != i)
        {
            printf("%d ",tomb[i]);
        }
        else
        {
            printf("%d[MIN] ",tomb[i]);
        }
    }
    printf("\nA legkisebb szam: %d\nA legkisebb indexe: %d",kicsi,minhely);
    return 0;
}

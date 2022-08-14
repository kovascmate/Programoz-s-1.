#include <stdio.h>
#include <stdlib.h>

int main()
{
    char tomb[10] = {'P','i','t','a','g','o','r','a','s','z'};
    char betu;
    for(int i = 0; i<10; ++i)
    {
        for(int k = 0; k < 10;++k)
        {
        printf("%c ",tomb[k]);
        }
        printf("\n");
        betu = tomb[0];
        for(int j = 0; j<10;++j)
        {

            tomb[j] = tomb[j+1];
            if(j == 9)
            {
                tomb[9] = betu;
            }
        }
    }
    return 0;
}

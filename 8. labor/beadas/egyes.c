#include <stdio.h>
#include <stdlib.h>

int main()
{
    int meret;
    printf("Hany elemu lesz a tomb?\t");
    scanf("%d",&meret);
    double *tomb = (double*) malloc(meret* sizeof(double));
    if(tomb == NULL)
    {
        printf("Sikertelen");
    }
    for(int i = 0; i < meret;i++)
    {
        scanf("%lf",&tomb[i]);
    }
    printf("---------------------------");
        for(int i = meret-1; i >=0;i--)
    {
        printf("\n%g",tomb[i]);
    }
    free(tomb);
    return 0;
}

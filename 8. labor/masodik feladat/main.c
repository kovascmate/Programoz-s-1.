#include <stdio.h>
#include <stdlib.h>

double *olvas(int *meret,double *regi)
{
    double elem;
    double *tomb;
    scanf("%lf",&elem);
    if(elem == -1)
        {
            return tomb;
        }
    else
        {
        *meret++;
        tomb = (double*) malloc(*meret* sizeof(double));
        for(int i  = 0; i < *meret-1; i++)
            {
                tomb[i] = regi[i];
            }
        tomb[*meret] = elem;
        free(regi);
        if(tomb == NULL)
            {
                printf("Hiba");
            }
            olvas(meret,tomb);
        }
}
int main()
{
    double *p;
    int meret = 0;
    p = olvas(&meret,NULL);
    for( int i = meret-1;i >=0;i--)
    {
        printf("%g\n",p[i]);
    }
    return 0;
}

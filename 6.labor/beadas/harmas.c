#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void szamolo(double oldal,double *ter,double *fel)
{
    *ter = pow(oldal,3);
    *fel = 6*pow(oldal,2);
}

int main()
{
    double *terfogat, *felulet;
    double oldal;
    printf("Adja meg a kocka oldal hosszusagat:");
    scanf("%lf",&oldal);
    szamolo(oldal,&terfogat,&felulet);
    printf("\nA kocka terfogata: %g\nA felulete: %g",terfogat,felulet);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double kob(double x)
    {
        return x*x*x;
    }
    double abszolut(double x)
    {
        return sqrt(x*x);
    }

    printf("a\t\ta^3\t\t|a|\t\tsin(a)\n");
        for(double i = -1;i<=1;i+=0.1)
    {
        printf("%.4f\t\t%.4f\t\t%.4f\t\t%.4f\n",i,kob(i),abszolut(i),sin(i));

    }
    return 0;
}

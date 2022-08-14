#include <stdio.h>
#include <stdlib.h>
void interativ_e(int *tomb,int meret)
{
    printf("Interativ elore:\n");
    for(int i = 0;i < meret; ++i)
    {
        printf("%d, ",tomb[i]);
    }
    printf("\n");
}
void rekurziv_e(int *tomb,int meret)
{
    if(meret == 0)
        return;
    else
    {

        rekurziv_e(tomb,meret-1);
        printf("%d, ", tomb[meret-1]);
    }
}

void interativ_h(int *tomb,int meret)
{
    printf("Interativ hatra:\n");
    for(int i = meret-1;i >= 0; --i)
    {
       printf("%d, ",tomb[i]);
    }
    printf("\n");
}
void rekurziv_h(int *tomb,int meret)
{
     if(meret == 0)
        return;
    else
    {
        printf("%d, ", tomb[meret-1]);
        rekurziv_h(tomb,meret-1);
    }
}

int main()
{
    int a_tomb[10] ={23,21,19,17,15,14,12,9,6,1};
    int b_tomb[5]={3,6,8,12,20};
    interativ_e(a_tomb,10);
    interativ_h(a_tomb,10);
    interativ_e(b_tomb,5);
    interativ_h(b_tomb,5);
    printf("rekurzív elore:\n");
    rekurziv_e(a_tomb,10);
    printf("\n");
    rekurziv_e(b_tomb,5);
    printf("\n");
    printf("rekurzív hatra:\n");
    rekurziv_h(a_tomb,10);
    printf("\n");
    rekurziv_h(b_tomb,5);
    printf("\n");
    return 0;
}

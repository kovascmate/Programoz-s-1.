#include <stdio.h>
#include <stdlib.h>
int fibo(int n)
{
    if(n<2)
    {
        return n;
    }
    else
    {
        return fibo(n-2)+fibo(n-1);
    }

}

int main()
{
    int elem = 0;
    int ertek = 0;
    printf("Adja meg hanyadik elemig akarja megkapni a Fibonacci sorozstnak:");
    scanf("%d",&elem);
    ertek = fibo(elem);
    printf("A Fibonacci soroazat %d. eleme: %d",elem,ertek);
    return 0;
}

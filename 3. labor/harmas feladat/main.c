#include<stdio.h>
int main(){

int n = 1;
int szorzat = 1;

while(n<=8){
szorzat = szorzat * n;
//printf("%d\t%d\n",n,szorzat);
++n;
}
printf("\n%d",szorzat);
return 0;
}
/*
#include <stdio.h>

int main() {
    int szorzat = 1;
    int n = 8;
    while (n > 1) {
        szorzat *= n;
        n -= 1;
    }
    printf("%d\n", szorzat);
    return 0;
}
*/
/*
#include <stdio.h>

int main() {
    int a = 11220;
    int b = 2002;
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    printf("lnko = %d\n", a);
    return 0;
}
*/

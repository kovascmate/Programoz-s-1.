#include <stdio.h>
#include <stdlib.h>

int nulla(int b)
{
    return 1;
}
int egy(int b)
{
    b=b+1;
    return b;
}
int ketto(int b)
{
    b=b*(-1);
    return b;
}
int harom(int b)
{
    b=b*2;
    return b;
}
int kilenc(int b)
{
    return ;
}
int main()
{
int bm = 0;
int a = 1;
printf("0. Alapertek visszaallitasa (a = 1)\n""1. Hozzaad 1-et\n""2. Megforditja az elojelet\n""3. Szorozza 2-vel\n""9. Kilepes\n");
scanf("%c",&bm);
    do{
    printf("0. Alapertek visszaallitasa (a = 1)\n""1. Hozzaad 1-et\n""2. Megforditja az elojelet\n""3. Szorozza 2-vel\n""9. Kilepes\n");

    switch(bm){
case 0:
    a=nulla(a);
case 1:
    a=egy(a);
case'2':
    a=ketto(a);
case 3:
    a=harom(a);
    }
    printf("\na=%d\n",a);

    }while(bm!='9'&&scanf("%c",&bm) !=EOF);



    return 0;
}

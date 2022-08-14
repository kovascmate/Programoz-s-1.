#include <stdio.h>
#include <stdbool.h>

bool maganhang(char betu)
{
    int ascii=betu;
    if(ascii==97||ascii==101||ascii==105||ascii==111||ascii==117)
    return true;
    ascii=ascii+('a'-'A');
    if(ascii==97||ascii==101||ascii==105||ascii==111||ascii==117)
        return true;
    else
        return false;
}
int main(void) {
    char c;
    while (scanf("%c", &c) != EOF){
    if(maganhang(c) == true)
            printf("%cv%c", c, tolower(c));
        else
            printf("%c", c);
    }
    return 0;
}


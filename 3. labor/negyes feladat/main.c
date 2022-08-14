#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int tomb[10];

    for (int i = 0; i < 10; i += 1){

    tomb[i] = i * 10;
    }

    int a = 0;
    while (true) {
        printf("%d. elem: %d\n", a, tomb[a]);
        a += 1;
    }

    return 0;
}

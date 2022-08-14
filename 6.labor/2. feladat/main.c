#include <stdio.h>

void func1(int i2) {
    i2 *= 2;
    printf("func1()... i2 = %d\n", i2);     /* 4 */
}

void func2(int *p3) {
    *p3 *= 2;
    printf("func2()... *p3 = %d\n", *p3);
    p3 = NULL;                              /* 5, 6 */
    printf("func2()... p3 = %p\n", p3);
}

int main(void) {
    int i1 = 2;
    int *p1 = NULL;
    int *p2 = NULL;
    printf("Hova mutat p1 es p2?\n");       /* 1 */


    p1 = &i1;
    printf("&i1 = %p, p1 = %p\n", &i1, p1);
    printf("i1 = %d, *p1 = %d\n", i1, *p1); /* 2 */

    i1 = 3;  printf("*p1 = %d\n", *p1);
    *p1 = 4; printf("i1 = %d\n", i1);

    p2 = p1;
    *p2 = 5;
    printf("i1 = %d, p2 = %p\n", i1, p2);   /* 3 */
    printf("-----\n");

    func1(i1);
    printf("main()... i1 = %d - de miert?\n", i1);
    printf("-----\n");

    func2(&i1);
    printf("main()... i1 = %d - miert?\n", i1);
    printf("-----\n");

    func2(p2);
    printf("main()... i1 = %d - miert?\n", i1);
    printf("main()... p2 = %p - miert?\n", p2);

    return 0;
}

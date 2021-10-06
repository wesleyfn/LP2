#include <stdio.h>

int main(void)
{
    int x, *p;
    x = 100;
    //Falta do &
    p = &x;
    printf("Valor de p: %d.\n", *p);

    return 0;
}
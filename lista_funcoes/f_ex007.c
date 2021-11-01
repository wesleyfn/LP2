#include <stdio.h>

int perfeito(int);

int main(void)
{
    int i, j, flag;

    for (i = 0; i < __INT64_MAX__; i++)
    {
        flag = perfeito(i);
        if (flag)
        {
            printf("Perfeito: %d = ", i);
            for (j = i; j > 1; j--)
                if (i%j == 0) printf("%d ", i/j);
            printf("\n");
        }
    }
    return 0;
}

int perfeito(int num)
{
    int i, acumulo;
    if (num != 0){
        acumulo = 0;
        for (i = num; i > 1; i--)
            if (num%i == 0) acumulo += num/i;
    }
    return acumulo == num ? 1 : 0;
}
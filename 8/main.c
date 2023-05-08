#include <stdio.h>
#include <stdlib.h>

void del (int, int*, int*, int*);

void del (int L, int* c, int* price, int* parts)
{
    int i, q, j;

    price[0]=0;
    for (j = 1; j<=L; j++)
    {
        q = -1;

        for (i = 1; i<=j; i++)
        {
            if ( q <= (c[i]+price[j-i]))
            {
                q = (c[i]+price[j-i]);
                parts [j] = i;
            }
        }

        price[j] = q;
    }

    printf ("Optimal price: %d \n", price[L]);
    printf ("Optimal parts:");
    int n = L;
    while (n>0)
    {
        printf (" %d", parts [n]);
        n = n - parts [n];
    }
}

int main()
{
    int L, i;
    int* price, *parts;

    scanf("%d", &L);

    int *cost = (int*)malloc(sizeof(int) * (L+1));
    price = (int*)malloc(sizeof(int)*(L+1));
    parts = (int*)malloc(sizeof(int)*(L+1));

    *cost = 0;
    for( i = 1; i <= L; i++)
    {
        scanf("%d", (cost + i));
    }

    printf("\n");
    printf("Length\tCost\n");
    for(i = 0; i <= L; i++)
    {
        printf("%d\t%d\n", i, *(cost +i));
    }

    printf("\n");

    del (L, cost, price, parts);

    return 0;
}


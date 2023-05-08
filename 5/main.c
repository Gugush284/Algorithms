#include <bits/stdc++.h>

int main()
{
 srand(time(NULL));
 double n = 1000.0;
 long long i, j;
 unsigned long long sum, max;
 unsigned long long r1, r2;
 unsigned long long *mas;
 int k;

 for ( int b = 0; b < 10; b++)
 {
    for(i = 10; i <= 1000000; i*= 10)
    {
        free (mas);
        mas = (unsigned long long*)malloc(i * sizeof(unsigned long long));
        sum = 0;
        for(k = 0; k < n; k++)
        {
            max = 0;
            for(j = 0; j < i; j++)
            {
                r1 = rand() % 18446744073709551613;
                r2 = rand() % 18446744073709551613;
                mas[j] = r1*65536 + r2;
                if (mas[j] > max)
                {
                    max = mas[j];
                    sum++;
                }
            }
        }
        printf("%lld %f\n", i, sum/n);
    }
 }
}

#include <stdio.h>
#include <stdlib.h>

void menu();
int* Zapoln (int*, int, int, int);
void print (int*, int);
int* Plus (int*, int, int, struct condition);
struct condition moving (struct condition, int*, int);
void printS (struct condition, int*, int);
int* multiplication (int*, int, int, struct condition);
int* Zapol (int*, int, int);
void printZ (int*, int);
struct condition startN (struct condition, int*, int);
struct condition startM (struct condition, int*);
int* Subtraction (int*, int, int, struct condition);
int* Division (int*, int, int, struct condition);
void printD (int*, int, struct condition);


struct condition
{
    int* p;
    int zn;
    char s;
    int sost;
};

void printS (struct condition q, int* L, int size)
{
    int *l;

    printf ("q%d %d %c\n", q.sost, q.zn, q.s);

    for (l = L; l < size + L; l++)
    {
        if (q.p == l) printf ("q");
        else printf (" ");
    }

    printf("\n");

    for (l = L; l < size + L; l++)
    {
        printf ("%d", *l);
    }

    printf("\n");
    printf("\n");
}

int* Zapoln (int* L, int n, int m, int size)
{
    int* l;

    for (l = L; l < L + size; l++)
        *l = 0;

    l = L + n + 5;

    while (n)
    {
        *l = 1;
        l++;
        n--;
    }

    l++;

    while (m)
    {
        *l = 1;
        l++;
        m--;
    }

    return L;
}

void menu()
{
    puts ("menu:");
    puts ("1: first + second");
    puts ("2: first * 2");
    puts ("3: second * 2");
    puts ("4: first - 2");
    puts ("5: second - 2");
    puts ("6: first / 2");
    puts ("7: second / 2");
    puts ("other - end of work");
}

void print (int* L, int size)
{
    int *l;
    int c = 0;

    for (l = L; l < size + L; l++)
        if (*l == 1)
            c++;
    printf ("\n%d", c);

}

struct condition moving (struct condition q, int*L, int size)
{
    if (q.s == 'L')
    {
        while (q.zn == *(q.p) && (q.p) != L && q.p < L + size - 1)
        {
            (q.p)--;
            printS (q, L, size);
        }
    }

    if (q.s == 'R')
    {
        while (q.zn == *(q.p) && (q.p) != L && q.p < L + size - 1)
        {
            (q.p)++;
            printS (q, L, size);
        }
    }

    return q;
}

struct condition startN (struct condition q, int*L, int nach)
{
    q.sost = 1;
    q.s = 'N';

    q.p = L + nach + 5;
    q.zn = 1;

    while (*(q.p))
        (q.p)++;

    (q.p)++;

    while (*(q.p))
        (q.p)++;

    (q.p)--;
    return q;
}

int* Plus (int* L, int nach, int size, struct condition q)
{

    if (q.sost == 0) q = startN (q, L, nach);
    printS (q, L, size);

    q.s = 'L';
    printS (q, L, size);
    q = moving (q, L, size);

    q.s = 'N';
    q.zn = 0;
    printS (q, L, size);

    *(q.p) = 1;
    q.sost ++;
    q.zn = 1;
    printS (q, L, size);

    q.s = 'L';
    q = moving (q, L, size);


    q.zn = 0;
    q.s = 'N';
    printS (q, L, size);

    q.s = 'R';
    q.sost ++;
    printS (q, L, size);

    q = moving (q, L, size);
    q.s = 'N';
    q.zn = 1;
    printS (q, L, size);

    q.s = 'N';
    q.sost ++;
    *(q.p) = 0;
    q.zn = 0;
    printS (q, L, size);

    q.s = 'R';
    printS (q, L, size);

    q = moving (q, L, size);

    q.zn = 1;
    printS (q, L, size);

    q = moving (q, L, size);
    printS (q, L, size);

    q.s = 'N';
    q.zn = 0;
    printS (q, L, size);

    q.zn = 0;
    q.sost = 0;
    q.s = 'L';
    printS (q, L, size);

    q = moving (q, L, size);

    q.zn = 1;
    q.s = 'N';
    printS (q, L, size);

    return L;
}

int* Zapol (int* L, int first, int size)
{
    int* l;
    int n;

    for (l = L; l < L + size; l++)
        *l = 0;

    n = abs(first);
    l = L + n + 5;
    n*= 2;
    if (first < 0) n--;

    while (n)
    {
        *l = 1;
        l++;
        n--;
    }

    return L;
}

void printZ (int* L, int size)
{
    int *l;
    int c = 0;

    for (l = L; l < size + L; l++)
        if (*l == 1)
            c++;
    if (c % 2 == 1) c = (c+1) * (-1);
    printf ("\n%d", c/2);
}

struct condition startM (struct condition q, int*L)
{
    q.sost = 1;
    q.s = 'N';

    q.p = L;
    q.zn = 1;

    while (!*(q.p))
        (q.p)++;

    while (*(q.p))
        (q.p)++;

    (q.p)--;

    return q;
}

int* multiplication (int* L, int n, int size, struct condition q)
{
    int i;

    L = Zapol (L, n, size);

    if (n == 0)
        return L;

    q = startM (q, L);
    printS (q, L, size);

    q.sost++;
    q.s = 'L';
    q.zn = 1;
    i = q.sost;

    while (*(q.p) == 1)
    {
        q.sost = i;
        (q.p)--;
        printS (q, L, size);
        if (*(q.p) == 0) break;

        q.sost ++;
        (q.p)--;
        printS (q, L, size);
    }

    if (q.sost == 3)
    {
        q.sost = 4;
        q.s = 'R';
        q.zn = 0;
        q = moving (q, L, size);

        q.zn = 1;
        q = moving (q, L, size);

        q.sost++;
        q.zn = 0;
        q.s = 'L';
        (q.p)--;
        printS (q, L, size);
    }
    else
    {
        q.sost = 6;
        q.s = 'R';
        q.zn = 0;
        (q.p)++;
        printS (q, L, size);

        q.zn = 1;
        q = moving (q, L, size);

        q.sost++;
        q.zn = 1;
        q.s = 'N';
        *(q.p) = 1;
        printS (q, L, size);

        q.s = 'L';
        q.p--;
        q.sost = 5;
        printS (q, L, size);
    }

    while (1)
    {
    q.sost = 8;
    q.zn = 0;
    q.s = 'N';
    *(q.p) = 0;

    q.sost ++;
    q.s = 'R';
    q.p++;
    printS (q, L, size);

    q.zn = 1;
    q = moving (q, L, size);

    q.sost ++;
    q.zn = 1;
    q.s = 'N';
    *(q.p) = 1;
    printS (q, L, size);

    q.s = 'R';
    q = moving (q, L, size);

    q.sost ++;
    q.zn = 1;
    q.s = 'N';
    *(q.p) = 1;
    printS (q, L, size);

    q.s = 'L';
    q = moving (q, L, size);

    q.sost ++;
    q.zn = 0;
    q.s = 'L';
    q = moving (q, L, size);
    if (q.p == L) break;
    }

    return L;
}

int* Subtraction (int* L, int n, int size, struct condition q)
{

    L = Zapol (L, n, size);

    q = startM (q, L);
    printS (q, L, size);

    q.sost ++;
    q.zn = 1;
    q.s = 'L';
    q.p --;
    printS (q, L, size);

    q.sost ++;
    q.zn = 1;
    q.s = 'L';
    q.p --;
    printS (q, L, size);

    if (*(q.p) == 0)
    {
        q.sost ++;
        q.zn = 0;
        q.s = 'R';
        q.p++;
        printS (q, L, size);

        q.sost ++;
        q.zn = 0;
        q.s = 'N';
        *(q.p) = 0;
        printS (q, L, size);

        q.sost = 0;
        q.zn = 0;
        q.s = 'R';
        q.p++;
        printS (q, L, size);
    }
    else
    {
        q.sost = 6;
        q.zn = 0;
        q.s = 'R';
        q.p++;
        printS (q, L, size);

        q.zn = 1;
        q = moving (q, L, size);

        q.s = 'L';
        q.zn = 0;
        while (q.sost != 10)
        {
            q.sost++;
            *(q.p) = 0;
            q.p--;
            printS (q, L, size);
        }

        q.sost = 0;
        *(q.p) = 0;
        q.p--;
        printS (q, L, size);
    }

    return L;
}


int* Division (int* L, int n, int size, struct condition q)
{

    L = Zapol (L, n, size);
    int flag = 0;

    q = startM (q, L);
    printS (q, L, size);
    q.s = 'L';

    while (1)
    {
        q.sost = 2;
        q.p --;
        printS (q, L, size);
        if (*(q.p) == 0) break;

        q.sost ++;
        q.p --;
        printS (q, L, size);
        if (*(q.p) == 0) break;

        q.sost ++;
        q.p --;
        printS (q, L, size);
        if (*(q.p) == 0) break;

        q.sost ++;
        q.p --;
        printS (q, L, size);
        if (*(q.p) == 0) break;
    }

    switch (q.sost)
        {
            case 3:
            flag = 1;

            q.sost = 22;
            q.zn = 0;
            q.s = 'L';
            q.p --;
            printS (q, L, size);

            q.sost = 23;
            q.zn = 1;
            q.s = 'L';
            *(q.p) = 1;
            q.p --;
            printS (q, L, size);

            q.sost = 24;
            q.zn = 1;
            q.s = 'R';
            *(q.p) = 1;
            q.p ++;
            printS (q, L, size);

            q = moving (q, L, size);

            case 2:
            if (flag == 0)
            {
            q.sost = 18;
            q.zn = 0;
            q.s = 'L';
            q.p --;
            printS (q, L, size);

            q.sost = 19;
            q.zn = 1;
            q.s = 'R';
            *(q.p) = 1;
            q.p ++;
            printS (q, L, size);

            q.sost = 20;
            q.zn = 0;
            q.s = 'R';
            *(q.p) = 0;
            q.p ++;
            printS (q, L, size);
            }

            q.sost = 21;
            q.zn = 0;
            q.s = 'R';
            *(q.p) = 0;
            q.p ++;
            printS (q, L, size);

            *(q.p) = 0;

            case 4:;

            case 5:

            q.sost = 6;
            q.zn = 0;
            q.s = 'R';
            q.p ++;
            printS (q, L, size);

            q.zn = 1;
            q = moving (q, L, size);

            q.sost++;
            q.zn = 0;
            q.s = 'L';
            q.p --;
            if (*(q.p) == 0)
            {
                return L;
            }
            printS (q, L, size);

            q.sost++;
            q.zn = 1;
            q.s = 'L';
            q.p --;
            printS (q, L, size);

            q.sost ++;
            q.zn = 0;
            q.s = 'L';
            *(q.p) = 0;
            q.p --;
            printS (q, L, size);

            while (1)
            {

                q.sost = 10;
                q.zn = 1;
                q.s = 'L';
                *(q.p) = 0;
                q.p --;
                printS (q, L, size);

                if (*q.p == 1)
                {
                q.sost++;
                q.zn = 0;
                q.s = 'R';
                *(q.p) = 0;
                q.p ++;
                printS (q, L, size);

                q = moving (q, L, size);

                q.sost++;
                q.zn = 0;
                q.s = 'R';
                while (*q.p == 1) q.p++;

                q.sost++;
                q.zn = 1;
                q.s = 'L';
                *(q.p) = 1;
                q.p --;
                printS (q, L, size);

                q = moving (q, L, size);

                q.sost++;
                q.zn = 0;
                q.s = 'L';
                *(q.p) = 0;
                q.p --;
                printS (q, L, size);

                q = moving (q, L, size);

                if (q.p == L)
                {
                    break;
                }
                }
                else
                {
                    q.sost = 15;
                    q.zn = 0;
                    q.s = 'L';
                    *(q.p) = 0;
                    q.p --;
                    printS (q, L, size);

                    q.sost = 16;
                    q.zn = 0;
                    q.s = 'R';
                    q = moving (q, L, size);

                    q.sost = 17;
                    q.zn = 1;
                    q.s = 'R';
                    q = moving (q, L, size);

                    q.sost = 0;
                    q.p--;
                    printS (q, L, size);
                    break;
                }
            }

            default: return L;
        };

    return L;
}

int main()
{
    int n,m, size, small, big;
    struct condition q;

    printf ("Vvedite chisla:\n");
    scanf ("%d%d", &n, &m);

    if (abs(n) < abs(m))
    {
        small = abs(n) + 1;
        big = abs(m);
    }
    else
    {
        big = abs(n);
        small = abs(m) + 1;
    }

    int *lenta;

    size = (2*big + small)*4;

    lenta = (int*)malloc(sizeof(int)*size);
    if (lenta == NULL)
        return -1;

    int option;

    do
    {
        q.sost = 0;
        menu();
        printf ("\n");
        scanf ("%d", &option);
        printf ("\n");

        switch (option)
        {
            case 1:
            if (n > 0 && m > 0)
            {
                lenta = Zapoln (lenta, n, m, size);
                lenta = Plus (lenta, n, size, q);
                print (lenta, size);
            }
            else printf ("Only natural numbers");
            break;

            case 2:
            lenta = multiplication (lenta, n, size, q);
            printZ (lenta, size);
            break;

            case 3:
            lenta = multiplication (lenta, m, size, q);
            printZ (lenta, size);
            break;

            case 4:
            if (n > 0)
            {
                lenta = Subtraction (lenta, n, size, q);
                printZ (lenta, size);
            }
            else printf ("Only natural numbers");
            break;

            case 5:
            if (m > 0)
            {
                lenta = Subtraction (lenta, m, size, q);
                printZ (lenta, size);
            }
            else printf ("Only natural numbers");
            break;

            case 6:
            lenta = Division (lenta, n, size, q);
            break;

            case 7:
            lenta = Division (lenta, m, size, q);
            break;

            default: option = 0;
        };

        printf ("\n");
        printf ("\n");
        printf ("Ishod: %d %d\n", n, m);

    } while (option != 0);
}

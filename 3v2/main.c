#include <stdio.h>
#include <stdlib.h>

struct condition
{
    struct condition* prev;
    int node;
    int node0;
    int node1;
    int position1;
    int sost1;
    int position0;
    int sost0;
    struct condition* next;
};
struct cond
{
    int node;
    int position;
    int sost;
};

void Printingtables (struct condition*);
struct condition* reading (struct condition*, int*, int*, int*);
int* Completion (int*, int, int, int, int);
int* Accomplishment (int*, struct condition*, int);
int* recfun (int*, struct condition*, int*, struct condition*, int);
void printS (struct cond, int*, int*, int);

struct condition* reading (struct condition* head, int *num, int *num2, int* flag)
{
    FILE* f;
    int n, coun;
    struct condition *p, *q;
    coun = 0;

    f = fopen ("in.txt", "r");

    printf ("Enter the numbers\n");
    fscanf(f, "%d", &n);
    scanf("%d", num);
    if (n > 1) scanf("%d", num2);
    else *flag = 0;


    while (fscanf(f, "%d", &n) == 1)
    {
        coun++;

        p = (struct condition*)malloc(sizeof(struct condition));

        (*p).node = coun;
        (*p).node1 = n;

        fscanf(f, "%d", &n);
        (*p).sost1 = n;

        fscanf(f, "%d", &n);
        (*p).position1 = n;

        fscanf(f, "%d", &n);
        (*p).node0 = n;

        fscanf(f, "%d", &n);
        (*p).sost0 = n;

        fscanf(f, "%d", &n);
        (*p).position0 = n;

        (*p).next = NULL;

        if (head == NULL)
        {
            (*p).prev = NULL;
            head = p;
        }
        else
        {
            q = head;
            while ((*q).next != NULL)
                q = (*q).next;
            (*q).next = p;
            (*p).prev = q;
        }
    }

    fclose(f);
    return head;
}

void Printingtables (struct condition* head)
{
    struct condition* p;
    char c;

    p = head;

    while (p != NULL)
    {
        if ((*p).position1 > 0) c = 'R';
        else if ((*p).position1 < 0) c = 'L';
        else c = 'N';
        printf ("%d) \tq%d\t%d\t%c  ", (*p).node, (*p).node1, (*p).sost1, c);

        if ((*p).position0 > 0) c = 'R';
        else if ((*p).position0 < 0) c = 'L';
        else c = 'N';
        printf ("\tq%d\t%d\t%c\n", (*p).node0, (*p).sost0, c);

        p = (*p).next;
    }
    printf ("\n");
    printf("\n");
}

int* Completion (int* L, int m, int m2, int f, int s)
{
    int* l;
    int n;

    for (l = L; l < L + s; l++)
        *l = 0;

    n = abs(m);
    l = L + n + 5;
    n*= 2;
    if (m < 0) n--;

    while (n)
    {
        *l = 1;
        l++;
        n--;
    }

    if (f == 1)
    {
        l++;
        n = abs(m2);
        n*= 2;
        if (m2 < 0) n--;

        while (n)
        {
            *l = 1;
            l++;
            n--;
        }
    }

    return L;
}

void printS (struct cond x, int* L, int* q, int size)
{
    int *l;
    char c;

    if (x.position > 0) c = 'R';
        else if (x.position < 0) c = 'L';
        else c = 'N';
    printf ("q%d %d %c\n", x.node, x.sost, c);

    for (l = L; l < size + L; l++)
    {
        if (q == l) printf ("q");
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

int* recfun (int*L, struct condition* head, int* q, struct condition* p, int size)
{
    struct cond x;
    int n, m;

    if (*q == 1)
    {
        *q = (*p).sost1;
        q = q + (*p).position1;

        x.node = (*p).node1;
        x.position = (*p).position1;
        x.sost = (*p).sost1;

        if (x.node == 0)
        {
            printS (x, L, q, size);
            return L;
        }

        n = (*p).node;
        m = (*p).node1;
        if (n < m)
            while (n != m)
            {
                p = (*p).next;
                n++;
            }
        else while (n != m)
            {
                p = (*p).prev;
                n--;
            }
    }
    else
    {
        *q = (*p).sost0;
        q = q + (*p).position0;

        x.node = (*p).node0;
        x.position = (*p).position0;
        x.sost = (*p).sost0;

        if (x.node == 0)
        {
            printS (x, L, q, size);
            return L;
        }

        n = (*p).node;
        m = (*p).node0;
        if (n < m)
            while (n != m)
            {
                p = (*p).next;
                n++;
            }
        else while (n != m)
            {
                p = (*p).prev;
                n--;
            }
    }

    printS (x, L, q, size);

    if (q == L) return L;
    L = recfun (L, head, q, p, size);

    return L;
}

int* Accomplishment (int* L, struct condition* head, int size)
{
    struct cond x;

    struct condition* p;
    p = head;

    int* q;
    q = L;
    while (*q != 1)
        q++;
    while (*q != 0)
        q++;
    q++;
    if (*q == 1)
        while (*q != 0)
            q++;
    else q--;
    q--;

    x.node = 1;
    x.position = 0;
    x.sost = *q;
    printS (x, L, q, size);

    L = recfun (L, head, q, p, size);

    return L;
}

int main()
{
    int num1, num2, flag, size;
    struct condition* head;
    flag = 1;
    int* lenta;

    head = NULL;

    head = reading (head, &num1, &num2, &flag);

    Printingtables (head);

    if (flag == 1)
    {
        if (num1 == 0 && num2 == 0)
        {
            printf("0000");
            return 1;
        }
        size = (abs(num1)+abs(num2))*6 + 5;
    }
    else
    {
        if (num1 == 0)
        {
            printf("0000");
            return 1;
        }
        size = abs(num1)*6 + 5;
    }
    lenta = (int*)malloc(sizeof(int)*size);

    lenta = Completion(lenta, num1, num2, flag, size);

    lenta = Accomplishment (lenta, head, size);

    return 1;
}

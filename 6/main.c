#include <stdio.h>
#include <stdlib.h>

int position (int, int, int*);
int prov (int, int, int*);
void print (int*, int*);
void menu();
void ferz();
int Horse();
int circumvention (int, int);

int N = 8;
int board[8][8];
int NUM = N*N;
int curr = 0;

void print (int* queen, int*v)
{
    int i,j;

    for(i = 1; i < N + 1; i++)
    {
        for(j = 1; j < N + 1 ; j++)
        {
            if (queen[i] == j) printf ("1 ");
            else printf ("0 ");
        }
        printf ("\n");
    }

    (*v)++;
    printf ("\n");
}

int prov (int i, int f, int* queen)
{
    int flag, j, n;

    flag = 0;

    for (j = 1; j < f + 1; j++)
        if ((queen[j] == i)) flag = 1;

    j = f - 1;
    n = 1;
    while (j)
    {
        if (queen[j] == i - n) flag = 2;
        n++;
        j--;
    }

    j = f - 1;
    n = 1;
    while (j)
    {
        if (queen[j] == i + n) flag = 3;
        n++;
        j--;
    }

    return flag;
}

int position (int* v, int f, int* queen) // f - םמלונ פונחÿ
{
    f++;

    int i, flag;

    for(i = 1; i < N+1; i++)
    {
        flag = prov (i, f, queen);
        //printf ("1)%d\n",flag);

        if (flag == 0)
        {
            queen[f] = i;
            //printf("2)%d\n",queen[f]);

            if (f < N)
                position (v, f, queen);
            else
            {
                print (queen, v);
            }
        }
    }

    queen[f] = 0;
}

void ferz ()
{
    int i, j;
    int queen[N+1];

    for(i = 0; i < N + 1; i++)
    {
        queen[i] = -1;
    }

    int variants = 0;

    position (&variants, 0, queen);

    printf ("%d", variants);
}

void menu()
{
    puts ("menu:");
    puts ("1 - Queen");
    puts ("2 - Horse");
    puts ("other - end of work");
}

int circumvention (int x, int y)
{
    curr++;
    board[x][y] = curr;
    bool is_true;

    if (x < N - 1 && y < N - 2 && board[x + 1][y + 2] == 0)
    {
        is_true = circumvention (x + 1, y + 2);
        if (is_true)
        {
            return 1;
        }
    }

    if (x < N - 1 && y > 1 && board[x + 1][y - 2] == 0)
    {
        is_true = circumvention (x + 1, y - 2);
        if (is_true)
        {
            return 1;
        }
    }

    if (x < N - 2 && y < N - 1 && board[x + 2][y + 1] == 0)
    {
        is_true = circumvention (x + 2, y + 1);
        if (is_true)
        {
            return 1;
        }
    }

    if (x < N - 2 && y > 0 && board[x + 2][y - 1] == 0)
    {
        is_true = circumvention (x + 2, y - 1);
        if (is_true)
        {
            return 1;
        }
    }

    if (x > 0 && y > 1 && board[x - 1][y - 2] == 0)
    {
        is_true = circumvention (x - 1, y - 2);
        if (is_true)
        {
            return 1;
        }
    }

    if (x > 0 && y < N - 2 && board[x - 1][y + 2] == 0)
    {
        is_true = circumvention (x - 1, y + 2);
        if (is_true)
        {
            return 1;
        }
    }

    if (x > 1 && y > 0 && board[x - 2][y - 1] == 0)
    {
        is_true = circumvention (x - 2, y - 1);
        if (is_true)
        {
            return 1;
        }
    }

    if (x > 1 && y < N - 1 && board[x - 2][y + 1] == 0)
    {
        is_true = circumvention (x - 2, y + 1);
        if (is_true)
        {
            return 1;
        }
    }

    if (curr == NUM)
        return 1;
    board[x][y] = 0;
    curr--;
    return 0;
}

int Horse ()
{
    printf ("Vvedite chisla\n");

    int startx = 0, starty = 0;
    scanf("%d", &startx);
    scanf("%d", &starty);

    printf ("\n");

    for(int x = 0; x < N; x++)
    {
        for(int y = 0; y < N; y++)
        {
            board[x][y] = 0;
        }
    }

    int check;
    check = circumvention (startx - 1, starty - 1);
    if (!check)
    {
        printf("Impossible");
        return 0;
    }

    for(int x = 0; x < N; x++)
    {
        for(int y = 0; y < N; y++)
            printf("%d\t", board[x][y]);
        printf("\n");
    }

    return 0;
}

int main()
{

    int option;

    do
    {
        menu();
        printf ("\n");
        scanf ("%d", &option);
        switch (option)
        {
            case 1:
            ferz();
            printf ("\n");
            break;

            case 2:
            printf ("\n");
            Horse ();
            printf ("\n");
            break;

            default: option = 0;
        };
    } while (option != 0);
}

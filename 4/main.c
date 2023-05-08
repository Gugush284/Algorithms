#include <stdio.h>
#include <stdlib.h>

int SUM (int, int);
int O (int);
int S ( int );
int I (int, int, int);
int MUL (int, int);
int EXP (int, int);
int TETR (int, int);
int FAC (int);
int PRED (int, int);
int DIFF (int, int);
int ABS (int, int);
int sg (int);
int anti_sg (int);
int REM(int, int);
int MOD (int,int);

int O (int x)
{
    return 0;
}

int S ( int x )
{
    x++;
    return x;
}

int I (int n, int x, int y)
{
    if (n == 1)
        return x;
    else
        return y;
}

int PRED (int x, int n)
{
    if (x <= n)
        return O(x);
    if (S(n) == x)
        return I(2, x, n);
    return PRED(x, S(n));
}

int SUM (int x, int y)
{
    if (y == O(y))
        return I (1, x, y);
    return S(SUM (x, PRED (y, 0)));
}

int MUL (int x, int y)
{
   if (y == O(y))
        return I (2, x, y);
    return SUM(x, MUL(x, PRED (y, 0)));
}

int EXP (int x, int y)
{
    if (y == O(y))
        return S(y);
    return MUL(x, EXP(x,PRED (y, 0)));
}

int TETR (int x, int y)
{
    if (y == O(y))
        return S(y);
    return EXP(x, TETR(x,PRED (y, 0)));
}

int FAC (int x)
{
    if (x == S(O(x)) || x == O(x))
        return S(O(x));
    return MUL(x, FAC(PRED (x, 0)));
}

int DIFF (int x, int y)
{
    if (x<y)
        return O(x);
    if (y == O(y))
        return I(1, x, y);
    return DIFF(PRED(x, 0), PRED(y, 0));
}

int ABS (int x, int y)
{
    if (x == O(x))
        return I(2, x, y);
    if (y == O(y))
        return I(1, x, y);
    return ABS (PRED (x, 0), PRED (y, 0));
}

int sg (int x)
{
    if(x <= O(x))
        return O(x);
    if(x == S(O(x)))
        return S(O(x));
    return sg(PRED(x, 0));
}


int anti_sg (int x)
{
    if(x <= O(x))
        return S(O(x));
    if(x == S(O(x)))
        return O(x);
    return anti_sg(PRED(x, 0));
}

int REM(int x, int y)
{
    if(DIFF(x, PRED(y, 0)))
        return REM(DIFF(x, y), y);
    return I(1, x, y);
}

int MOD (int x, int y)
{
    if(DIFF(x, PRED(y, 0)) == 0)
        return O(x);
    return S(MOD(DIFF(x, y), y));
}


int main()
{
    int x, y, n;

    scanf("%d%d", &x, &y);

    printf("SUM(%d, %d) = %d\n", x, y, SUM(x, y));  // сделать switch case
    printf("MUL(%d, %d) = %d\n", x, y, MUL(x, y));
    printf("EXP(%d, %d) = %d\n", x, y, EXP(x, y));
    printf("PRED(%d) = %d\n", x, PRED(x, 0));
    printf("DIFF(%d, %d) = %d\n", x, y, DIFF(x, y));
    printf("ABS(%d, %d) = %d\n", x, y, ABS(x, y));
    printf("sg(%d) = %d\n", x, sg(x));
    printf("anti_sg(%d) = %d\n", x, anti_sg(x));
    printf("REM(%d, %d) = %d\n", x, y, REM(x, y));
    printf("MOD(%d, %d) = %d\n", x, y, MOD(x, y));

    printf("\n");
    printf("Vvedite 1 dly prodolzhenia\n");
    scanf("%d", &n);
    if (n==1)
        {printf("TETR(%d, %d) = %d\n", x, y, TETR(x, y));
        printf("FAC(%d) = %d\n", x, FAC(x));}

    return 1;
}

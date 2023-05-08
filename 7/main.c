#include <stdio.h>
#include <stdlib.h>


int sozd (int**, int);
int Sort (int*);
void put (int*, int);

void bubbleSort(int *A, int Size)
{
  int smen, i, j;

  for (i = 0; i < Size - 1; i++)
  {
    for (j = (Size - 1); j > i; j--)
    {
      if (A[j - 1] > A[j])
      {
        smen = A[j - 1];
        A[j - 1] = A[j];
        A[j] = smen;
      }
    }
  }
}

int* Sort (int *A, int Size)
{
    if (Size<5)
        {
            bubbleSort (A, Size);
            return A;
        }

    Sort (A, Size/2);
    Sort (A+Size/2, (Size+1)/2);

    int *first, *second;
    int * mass;
    int *tek;

    first = A;
    second = A + Size/2;

    mass = (int*)malloc(sizeof(int) * Size);
    tek = mass;

    while((first != A + Size/2) && (second != A + Size))
    {
        if(*first < *second)
        {
            *tek = *first;
            first++;
        }
        else
        {
            *tek = *second;
            second++;
        }
        tek++;
    }

    while(!(first == A + Size/2))
    {
        *tek = *first;
        tek++;
        first++;
    }

    while(!(second == A + Size))
    {
        *tek = *second;
        tek++;
        second++;
    }

    tek = mass;
    for(first = A; first < A + Size; first++)
    {
        *first = *tek;
        tek++;
    }

    free (mass);
}

int sozd (int **A, int Size)
{
    int *i;
    int n = 0;
    FILE *f;

    f = fopen("input.txt", "r");
    fscanf (f, "%d", &Size);

    *A =(int*)malloc(sizeof(int)*(Size+1));
    i = *A;

    while (n<Size)
    {
        fscanf (f, "%d", i);
        i++;
        n++;
    }

    return Size;
}

void put (int*A, int Size)
{
    int *i;
    for (i = A; i != (A+(Size)); i++)
    {
        printf ("%d ", *i);
        if (((i - A + 1) % 10) == 0) printf ("\n");
    }
    printf ("\n");
}

int main()
{
    int *mass;
    int Size;

    Size = sozd (&mass, Size);

    Sort (mass, Size);

    printf ("Sort ishod massives\n");
    put (mass, Size);
}

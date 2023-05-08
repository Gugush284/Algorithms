#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct activity
{
    int start;
    int End;
    struct activity *next;
};

int print (struct activity *);
struct activity *Spisok(struct activity *, int);
struct activity *add (struct activity *);
struct activity *new_elem ();
struct activity *sort (struct activity *);
struct activity * vbor (struct activity *);

struct activity *new_elem ()
{
    struct activity *p;
    p = (struct activity *)malloc(sizeof(struct activity));

    p->start = rand() % 500;
    p->End = p->start + rand() % 500 + 1;
    p->next = NULL;

    return p;
}

struct activity *add (struct activity *head)
{
    struct activity *p, *q;
    p = new_elem ();

    if (head == NULL)
    {
        head = p;
    }
    else
    {
        q = head;
        while ( (*q).next != NULL )
            q = (*q).next;
        (*q).next = p;
    }

    return head;
}

struct activity *Spisok(struct activity *A, int n)
{
    int i;

    for (i = 0; i<n; i++)
    {
        A = add (A);
    }

    return A;
}

struct activity *sort (struct activity *root)
{
    struct activity *p, *key;
    struct activity *result = root;
    root = root->next;
    result->next = NULL;

    while(root != NULL)
    {
        key = root;
        root = root->next;

        if(key->End < result->End)
        {
            key->next = result;
            result = key;
        }
        else
        {
            p = result;
            while(p->next != NULL)
            {
                if(p->next->End > key->End)
                    break;
                p = p->next;
            }
            key->next = p->next;
            p->next = key;
        }
    }

    root = result;
    return root;
}

struct activity * vbor (struct activity *head)
{
    struct activity *p, *q;
    p = head;

    while (p->next)
    {
        q = p->next;
        if (p->End > q->start)
        {
            p->next = q->next;
            free (q);
        }
        else p = p->next;
    }

    return head;
}

int print (struct activity *head)
{
  struct activity *p;
  int n = 1;
  p = head;

  while (p)
  {
    printf("%d) start: %d end: %d \n", n, (*p).start, (*p).End);
    n++;
    p = (*p).next;
  }

  n--;
  return n;
}

int main()
{
    int n, i;
    struct activity *events;
    struct activity *now;

    srand(time(NULL));

    n = rand () % 100 + 5;
    events = NULL;
    events = Spisok (events, n);

    printf ("Ishod\n");
    print (events);

    events = sort (events);

    printf ("\n");
    printf ("Sort\n");
    print (events);

    events = vbor (events);

    printf ("\n");
    printf ("Itog\n");
    i = print (events);
    printf ("Kolichestvo: %d", i);
}

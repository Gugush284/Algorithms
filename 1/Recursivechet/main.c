#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct tnode
{
    char* word;
    int C;
    struct tnode* left;
    struct tnode* right;
};

int prov (char *s)
{
    char *q;
    char *p;
    int n = 1;
    q = (s + strlen (s) - n);
    *(q + 1) = '\0';

    if
    (
        !isalpha(*q) && !isdigit(*q))
    {
        q --;
        if
        (
            !isalpha(*q) && !isdigit(*q)
        )
        {
            q--;
            if
            (
                !isalpha(*q) && !isdigit(*q)
            ) q--;
        }
        q++;
        *q = '\0';
    }


    p = s + 1;
    q = s;
    if
    (
        !isalpha(*q) && !isdigit(*q)
    )
        {
            while (*p != '\0')
            {
                *(p-1) = *p;
                p++;
            }
            *(p-1) = *p;
        }

    if (*s == '\0') return 0;
    return 1;
}
struct tnode *add (char *s)
{
    struct tnode *str;
    str = (struct tnode *)malloc(sizeof(struct tnode)+2);
    if ( str == NULL )
        {
            printf ("Error of memory");
            getchar ();
            exit (0);
        }

    (*str).word = (char *)malloc(sizeof(char)*(strlen(s)+1));
    if ( (*str).word == NULL )
        {
            printf ("Error of memory");
            getchar ();
            exit (0);
        }
    strcpy ((*str).word, s);
    *((*str).word + 1 + strlen(s)) = '\0';

    (*str).C = 1;
    (*str).left = NULL;
    (*str).right = NULL;
    return str;
}

void srav (char *s, struct tnode *str)
{
    int m;

    m = strcmp ((*str).word, s);

    if ( m == 0)
        (*str).C ++;
    else
        {
            if (m < 0)
                {
                    if ((*str).right == NULL) (*str).right = add (s);
                    else srav (s, (*str).right);
                }
            else
                {
                    if ((*str).left == NULL) (*str).left = add (s);
                    else srav (s, (*str).left);
                }
        }
}


void tprint (struct tnode *str, FILE *f)
{

    if ((*str).left != NULL) tprint ((*str).left, f);

    fprintf (f, "%d: %s\n", (*str).C, str->word);

    if ((*str).right != NULL) tprint ((*str).right, f);
}

int main()
{
    char *s, buff [100];
    struct tnode *root;
    FILE *f;

    f = fopen ("in.txt","r");

    fscanf (f, "%s", buff);
    s = buff;
    prov (s);
    root = add (s);

    while (fscanf (f, "%s", buff) == 1)
    {
        s = buff;
        if (prov (s) == 1)
            srav (s, root);
    }

    fclose (f);

    f = fopen ("out.txt","w");

    tprint (root, f);

    fclose (f);

    return 1;
}

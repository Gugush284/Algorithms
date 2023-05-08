#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Fun_0_10 (char* word);
void Fun10 (char* word);
void Fun3 (char* word);

void Fun_0_10 (char* word)
{
    int q = 0;
    char *pointer;
    pointer = word;

    while ( *pointer != '\0' )
    {
        switch (q)
        {
            case(0):
                if(*pointer == '0')
                    q = 1;
                else
                    q = 2;
                break;
            case(1):
                q = 3;
                break;
            case(2):
                if(*pointer == '0')
                    q = 4;
                else
                    q = 3;
                break;
            case(3):
                q = 3;
                break;
            case(4):
                q = 3;
                break;
            default:
                break;
        }
        pointer++;
    }

    if(q == 4 || q==1)
        printf("Sootvetstvie alfavity {0,10}: Yes\n");
    else
        printf("Sootvetstvie alfavity {0,10}: No\n");
}

void Fun10 (char* word)
{
    int q = 0;
    char *pointer;
    pointer = word;

    while ( *pointer != '\0' )
    {
        switch (q)
        {
            case(0):
                if(*pointer == '0')
                    q = 1;
                else
                    q = 2;
                break;
            case(1):
                q = 1;
                break;
            case(2):
                if(*pointer == '0')
                    q = 3;
                else
                    q = 1;
                break;
            case(3):
                q = 3;
                break;
            default:
                break;
        }
        pointer++;
    }

    if(q == 3)
        printf("Sootvetstvie 10...: Yes\n");
    else
        printf("Sootvetstvie 10...: No\n");
}

void Fun3 (char* word)
{
    int q = 0;
    char* pointer = word;

    while((*pointer != '\0') && (q < 4))
    {
        q++;
        pointer++;
    }

    if(q == 3)
        printf("Dlina ravna 3: Yes\n");
    else
        printf("Dlina ravna 3: No\n");
}

int main()
{
    FILE* f = fopen("input.txt", "r");
    char word[100];

    f = fopen("input.txt", "r");

    while(fscanf (f, "%s", word) == 1)
    {
        printf("Word: %s\n", word);

        Fun_0_10 (word);
        Fun10 (word);
        Fun3 (word);
        printf("\n");
    }

    fclose (f);

    return 1;
}

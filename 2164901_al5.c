#include<stdio.h>
#include<stdlib.h>  /* for func4            */
#include<time.h>    /* for func4            */
#define ASC1  32    /* space ( for func 1 ) */
#define ASC2 126    /* ~     ( for func 1 ) */
void func1( char st[] );
void func2( char st[] );
void func3( char st[] );
void func4( char st[] );

int main(void)
{
    /* Lyrics of "Yesterday" by Beatles */
    char str1[] = "Yesterday, all my troubles seemed so far away.";
    char str2[] = "Now it looks as though they are here to stay.";
    char str3[] = "Oh, I believe in yesterday.";
    char str4[256];

    printf("--- func1 ---\n");
    printf("%s\n\n",str1);
    func1( str1 );

    printf("--- func2 ---\n");
    printf("%s\n\n",str2);
    func2( str2 );

    printf("--- func3 ---\n");
    printf("%s\n\n",str3);
    func3( str3 );

    printf("--- func4 ---\n");
    printf("input a word:");
    scanf("%s",str4);
    func4( str4 );

    return 0;
}

void func1( char st[] )
{
    int i = 0, ascii[128] ={0, }, gyou = 0;
    do
    {
        ascii[st[i]]++;
        i++;
    }while(st[i] != '.');
    for (int j = 0; j < 128; ++j)
    {
        if (ascii[j] != 0)
        {
            printf("%c: %d\t", j, ascii[j]);
            gyou++;
        }
        if (gyou == 7)
        {
            gyou = 0;
            printf("\n");
        }
    }
    printf("\n\n");
}

void func2( char st[] )
{
    int j = 0;
    do
    {
        j++;
    }while(st[j] != '.');
    for (int i = 0; i <= j; ++i)
        printf("%c", st[j-i]);
    printf("\n\n");
}

void func3( char st[] )
{
    int i = 0, j = 0;
    do
    {
        j++;
        if (st[j] == ' ')
            i++;
    }while(st[j] != '.');
    printf("number of characters \t= %d\n", j+1);
    printf("number of words \t= %d\n", i+1);
    printf("\n\n");
}

void func4( char st[] )
{
    int a, k;
    srand(time(NULL));
    for (int h = 0; h < 10; ++h)
    {
        a = 0, k = 0;
        printf("%d: ",h+1);
        char rst[256] = {0, };
        while(st[k] != '\0')
        {
            a = rand() % 256;
            if(rst[a] == 0)
            {
                rst[a] = st[k];
                k++;
            }
        }
        for (int i = 0; i < 256; ++i)
        {
            if (rst[i] != 0)
                printf("%c", rst[i]);
        }
        printf("\n");
    }
}
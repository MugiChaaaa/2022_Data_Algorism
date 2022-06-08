#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void rand_1_1000(char f1[], char f2[]);
void sort(char f1[], char f2[]);
void mergesort(char f1[],char f2[],char f3[]);

int main(void)
{
    rand_1_1000("rand1.txt", "rand2.txt");
    sort("rand1.txt", "data1.txt");
    sort("rand2.txt", "data2.txt");
    mergesort("data1.txt", "data2.txt", "data3.txt");
    return 0;
}

void rand_1_1000(char f1[], char f2[])
{
    FILE *fp1 = fopen(f1, "wt");
    FILE *fp2 = fopen(f2, "wt");
    int temp[1001]={0, };
    srand(time(NULL));
    int a = 0;
    for (int i = 0; i < 200; ++i)
    {
        do
        {
            a = rand()%1000 + 1;
        }
        while(temp[a] != 0);
        temp[a] = 1;
        if(i<100)
        {
            fprintf(fp1, " %4d", a);
            if (i%10 == 9)
                fprintf(fp1, "\n");
        }
        else if(i<200)
        {
            fprintf(fp2, " %4d", a);
            if (i%10 == 9)
                fprintf(fp2, "\n");
        }
    }
    fclose(fp1);
    fclose(fp2);
}

void sort(char f1[], char f2[])
{
    FILE *fpr = fopen(f1, "rt");
    FILE *fpw = fopen(f2, "wt");
    int temp[100] = {0, }, count = 0;
    for (int i = 0; i < 100; ++i)
        fscanf(fpr, " %4d", &temp[i]);

    for (int i = 1; i <= 1000; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            if(temp[j] == i)
            {
                fprintf(fpw, " %4d", temp[j]);
                count++;
                break;
            }
        }
        if(count == 10)
        {
            fprintf(fpw, "\n");
            count = 0;
        }
    }
    fclose(fpr);
    fclose(fpw);
}

void mergesort(char f1[],char f2[],char f3[])
{
    FILE *fpr1 = fopen(f1, "rt");
    FILE *fpr2 = fopen(f2, "rt");
    FILE *fpw = fopen(f3, "wt");

    int res[1001] = {0, };
    int a = 0, count = 0;

    for (int i = 0; i < 100; ++i)
    {
        fscanf(fpr1, " %4d", &a);
        res[a]++;
        fscanf(fpr2, " %4d", &a);
        res[a]++;
    }
    for (int i = 0; i < 1001; ++i)
    {
        if(res[i] == 1)
        {
            fprintf(fpw, " %4d", i);
            count++;
        }
        if(count == 10)
        {
            fprintf(fpw, "\n");
            count = 0;
        }
    }
    fclose(fpr1);
    fclose(fpr2);
    fclose(fpw);
}
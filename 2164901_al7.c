#include <stdio.h>

struct patient{
    int date1;
    int date2[2];
    int age;
    int gen;
};

int main()
{
    int i = 0, count = 0;
    int AGEGEN[10][2] = {{0, }, {0, }};
    FILE *fp = fopen("patients.txt", "rt");
    struct patient info[10000];
    printf("▩東京都の新型コロナウィルスの感染者データ▩\n");
    while(fscanf(fp, "%d %d %d", &info[i].date1, &info[i].age, &info[i].gen) != EOF)
    {
        info[i].date2[0] = info[i].date1/100;
        info[i].date2[1] = info[i].date1%100;
        AGEGEN[(info[i].age)/10][(info[i].gen)-1]++;
        i++;
    }
    fclose(fp);

    for (int j = 9999; j >= 0; --j)
    {
        for (int k = 0; k < 10; ++k)
        {
            for (int l = 0; l < 2; ++l)
            {
                if(j == AGEGEN[k][l])
                {
                    printf("NO.%02d: ", ++count);
                    if(k==0)
                        printf("%2d代 ", 1);
                    else
                        printf("%2d代 ", k*10);
                    if(l==0)
                        printf("男性 ");
                    else
                        printf("女性 ");
                    printf("= %4d人\n", j);
                }
            }
        }
    }


    return 0;
}
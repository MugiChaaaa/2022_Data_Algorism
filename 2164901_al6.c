#include <stdio.h>

int main()
{
    FILE *fp = fopen("kuku.csv", "rt");
    int kuku[9][9];
    printf("column size = %d\n", 9);
    printf("row size = %d\n", 9);

    for (int i = 0; i < 9; ++i)
    {
        fscanf(fp, "%d", &kuku[i][0]);
        printf("%5d", kuku[i][0]);
        for (int j = 1; j < 9; ++j)
        {
            fscanf(fp, ",%d", &kuku[i][j]);
            printf("%5d", kuku[i][j]);
        }
        printf("\n");
    }
    fclose(fp);
    return 0;
}
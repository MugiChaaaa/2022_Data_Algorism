#include <stdio.h>

struct score
        {int a, b, c;
         float avg;
         };

int main()
{
    struct score st[3];

    for (int i = 0; i < 3; ++i)
    {
        printf("%dつ目の人:", i+1);
        scanf("%d %d %d", &st[i].a, &st[i].b, &st[i].c);
        st[i].avg = ((float)st[i].a + (float)st[i].b + (float)st[i].c) / 3;
    }
    for (int i = 0; i < 3; ++i)
    {
        printf("\n %dつ目の人の成績の平均：%.2f", i+1, st[i].avg);
    }

    return 0;
}
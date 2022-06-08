#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, random;
    srand(time(NULL));
    random = (rand() % 1000) + 1;

    printf("1~1000の中、指定の数字を探せ！\n");
    for (int i = 20; i > 0; --i)
    {
        if(random != n)
        {
            do
            {
                printf("[残り：%d] 数字は何？：", i);
                scanf("%d", &n);
                if(n >= 1000 || n <= 0)
                    printf("1~1000の数字だけを入れてください！\n");
            }
            while(n >= 1000 || n <= 0);
            if(n < random)
                printf("UP!\n");
            else if(n > random)
                printf("DOWN!\n");
        }
        else
        {
            printf("★☆★ 数字を探しましたね！  あなたが勝ちました！★☆★\n");
            printf("回数：%d", 20-i);
            return 0;
        }
    }
    printf("数字は%dでした…  次回はもっと頑張ってね！", random);

    return 0;
}
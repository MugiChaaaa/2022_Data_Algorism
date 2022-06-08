#include <stdio.h>
#include <math.h>

int main()
{
    int rand_num = 0, num[20], i = 0, choice = 0;
    num[0] = 25000;

    while(1 > rand_num || rand_num > 50000)
    {
        printf("Please enter the number... (1~50000):");
        scanf("%d", &rand_num);
    }
    printf("\n---Game Start---\n大きい(1)／小さい(2)／アタリ！(3)\n");
    while(choice != 3)
    {
        printf("計算機：%d?\n", num[i]);
        scanf("%d", &choice);
        if (choice == 1)
        {
            i++;
            num[i] = num[i-1] + (int)(25000/pow(2, i));
            if ((int)(25000/pow(2, i)) == 0)
                num[i]++;
        }
        else if (choice == 2)
        {
            i++;
            num[i] = num[i-1] - (int)(25000/pow(2, i));
            if ((int)(25000/pow(2, i)) == 0)
                num[i]--;
        }
        else if (choice == 3)
        {
            if (rand_num == num[i])
            {
                printf("当たった！ 回数：%d\n", i+1);
            }
            else
            {
                printf("当たっていないはずですよ…\n");
                choice = 0;
                printf("適切な選択肢を選んでください\n");
            }
        }
        else
            printf("適切な選択肢を選んでください\n");
    }
    return 0;
}
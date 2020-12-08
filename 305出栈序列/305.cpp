#include <stdio.h>

int main()
{
    int n;// 表示序列长度
    scanf("%d", &n);// 输入序列的长度
    int a[11] = {};
    int i, k, j, l = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);// 输入需要判断的出栈序列
    }
    int b[11] = {};
    int change = 0;

    int p, q = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (k = i + 1, j = 0; j < a[i] - 1; k++)
        {
            if (a[k] < a[i])
            {
                b[j] = a[k];
                j++;// 把首小的存入b数组
            }
        }
        /*for(p = 0; p < a[i]-1; p++)
     {
      if(b[p] == 0) break;
      printf("%d ",b[p]);
     }
    printf("\n");*/
        for (l = j - 1; l > 0; l--)// 从对头往对尾
        {
            if (b[l] > b[l - 1])
            {
                change = 1;
                break;
            }
        }
    }
    if (change == 0)
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
    return 0;
}

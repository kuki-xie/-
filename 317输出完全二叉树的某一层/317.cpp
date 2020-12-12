//
//  main.cpp
//  317输出完全二叉树的某一层
//
//  Created by 谢容海 on 2020/12/12.
//

#include <iostream>
using namespace std;
int main(){
    int n,i,level;
    while (scanf("%d",&n),n != 0) {// 第一行输入一个数n，当n = 0时，表示输入结束
        int data[10001];// 存储结点的值
        for (i = 0; i < n; i++) {
            scanf("%d",&data[i]);// 第二行将这n个结点依次输入
        }
        scanf("%d",&level);// 第三行输入代表深度
        // 开始处理
        if(n < pow(2,level - 1)){// 如果结点数比所要深度上一层还少，那所要深度层为空
            printf("empty");
        }
        else{
            if (n > pow(2, level)) {// 如果这层满的
                for (i = pow(2,level - 1) - 1; i < pow(2, level) - 1; i++) {// 对这一层全部输出
                    printf("%d ",data[i]);
                }
            }
            if (n < pow(2, level)) {// 如果该层不是满的
                for (i = pow(2, level - 1) - 1; i < n; i++) {// 因为序号是从0，而结点值从1
                    printf("%d ",data[i]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}

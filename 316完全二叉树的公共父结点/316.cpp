//
//  main.cpp
//  316完全二叉树的公共父结点
//
//  Created by 谢容海 on 2020/12/11.
//

#include <iostream>
using namespace std;
int main(){
    int m,n;// 定义两个结点
    while(scanf("%d %d",&m,&n),m,n){// 循环输入两个结点，返回值是m和n的值，当m和n为0时停止
        while(m != n){// 未找到公共结点
            if(m > n){// 如果m大,说明它的深度更大
                m = m / 2;
            }
            else{
                n = n / 2;
            }
        }
        printf("%d\n",m);// 当相等时，说明找到，输出结果
    }
    return 0;
}


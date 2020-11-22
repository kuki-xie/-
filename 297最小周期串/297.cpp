//
//  main.cpp
//  297最小周期串
//
//  Created by 谢容海 on 2020/11/20.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    
    
    char a[81];
    int T;
    while(scanf("%d",&T)!=EOF)
    {
        scanf("%s",a);//输入一个长度不超过80的串
        int len = (int)strlen(a);//len——字符串长度
        for(int i = 1 ; i <= len ; i++)//循环读取字符串,寻找最小周期
        if(!(len % i)){//比如len是9，寻找质数，如果是4，就不可能形成周期
            for(int j = 0;j < len;j++){//在假设周期i的条件下
                if(a[j]!=a[j % i])//判断后面每一段字符是否都等于第一段字符
                    break;
                if(j == len-1)//判断是否到最后一位，到了就可以输出结果
                {
                    printf("%d\n",i);
                    i = len+1;//中断外层循环，因为结果已经找到了，再循环没有意义了。
                }
            }
        }
        return 0;
        
    }
}

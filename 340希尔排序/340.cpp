//
//  main.cpp
//  340希尔排序
//
//  Created by 谢容海 on 2020/12/19.
//

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cin >> n;// n个整数
    int a[100],i;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    int temp;
    int d = floor(n / 2);
    for(i=0;i<d;i++)
    {
        if(a[i] > a[i+d])
        {
            temp = a[i+d];
            a[i+d] = a[i];
            a[i] = temp;
        }
    }
    for(i = 0;i < n; i++)
        cout << a[i] << ' ';;
    return 0;
}

//
//  main.cpp
//  339冒泡排序
//
//  Created by 谢容海 on 2020/12/18.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;// 包含n个整数
    int i,j,temp,count = 0,a[100];
    for (i = 0; i < n; i++) {
        cin >> a[i];// 输入n个整数
    }
    for (i = 1; i <= n - 1; i++) {// 针对所有元素重复以下操作，除了最后一个
        for (j = 0; j < n - i; j++) {// 从前往后，22比较
            if (a[j] > a[j + 1]) {// 如果第一个比第二个大
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;// 交换次序
                count++;// 记录次数
            }
        }
    }
    cout << count;
    return 0;
}

//
//  main.cpp
//  338快速排序
//
//  Created by 谢容海 on 2020/12/18.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int i,n;
    cin >> n;// n个整数
    int a[100];
    for (i = 0; i < n; i++) {
        cin >> a[i];// 输入序列
    }
    int piv = a[0];// 枢轴为数组的第一个数
    int low = 0, high = n - 1;// 分别从头和尾开始
    int temp;
    while(low < high){// 直到i == j
        while (low < high && a[high] >= piv) {// 当一直大于基准值时
            high--;// 向前移动
        }
        temp = a[low];
        a[low] = a[high];
        a[high] = temp;// 当high所指的数 小于 基准值 将low指的数据放到high的坑
        while (low < high && a[low] <= piv) {
            low++;// 当low指的值小于基准值
        }
        temp = a[high];
        a[high] = a[low];
        a[low] = temp;// 当low指的数据大于基准值，将high所指的值放到low的坑
    }
    for (i = 0; i < n; i++) {
        cout << a[i] << ' ';// 按序输出
    }
    return 0;
}

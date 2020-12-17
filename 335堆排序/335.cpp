//
//  main.cpp
//  335堆排序
//
//  Created by 谢容海 on 2020/12/17.
//

#include <iostream>
using namespace std;
int a[100];// 待排序数据元素个数，小于100
void HeapSort(int b[],int i,int n){
    int rc,j;
    rc = b[i];
    for (j = 2 * i; j <= n; j = j * 2) {
        if (j < n && b[j] > b[j + 1]) {// 如果该元素比其后元素大
            ++j;
        }
        if (!(rc > b[j])) {
            break;
        }
        b[i] = b[j];
        i = j;
    }
    b[i] = rc;
}
int main(int argc, const char * argv[]) {
    int n,i;
    cin >> n;// 输入n个顶点
    for (i = 1; i <= n; i++) {
        cin >> a[i];// 输入待排序的元素
    }
    for (i = n/2; i > 0; i--) {
        HeapSort(a, i, n);
    }
    for (i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}

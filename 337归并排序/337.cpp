//
//  main.cpp
//  337归并排序
//
//  Created by 谢容海 on 2020/12/18.
//

#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    int i,j;
    int n1,n2;
    int a1[100],a2[100],a[200];
    cin >> n1 >> n2;// 输入两个数组的长度
    for (i = 0; i < n1; i++) {
        cin >> a1[i];// 输入第一个序列
        a[i] = a1[i];// 加入待输出序列
    }
    for (i = 0; i < n2; i++) {
        cin >> a2[i];
        a[i + n1] = a2[i];
    }
    sort(a,a + n1 + n2);
    for (i = 0; i < n1 + n2; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}

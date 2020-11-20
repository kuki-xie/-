//
//  main.cpp
//  297最小周期串
//
//  Created by 谢容海 on 2020/11/20.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int a,b;//分别表示第一个线性表L1和第二个线性表L2的长度
    cin >> a >> b;//第一行输入两个整数数a,b,元素值小于100个
    int i;
    int L1[100];
    int L2[100];
    for (i = 0; i < a; i++) {//第二行依次输入L1中单调递增的a个正整数
        cin >> L1[i];
    }
    for (i = 0; i < b; i++) {//第三行依次输入L2中单调递增的b个正整数
        cin >> L2[i];
    }
    /*for (i = 0; i < a; i++) {//检查输入是否正确
        cout << L1[i];
    }
    for (i = 0; i < b; i++) {
        cout << L2[i];
    }*/
    int fin[200];//输出用
    return 0;
}

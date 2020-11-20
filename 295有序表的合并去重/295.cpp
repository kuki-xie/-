//
//  main.cpp
//  295有序表的合并去重
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
    int count = 0;//用来记输出数组fin的长度
    int fin[200];//合并去重后输出用
    int len = (a < b) ? a : b;//三元运算符,取L1和L2之间最短的长度
    for (i = 0; i < len; i++) {//先比较各自的前len项
        if(L1[i] < L2[i] || L1[i] == L2[i]){//如果相应位置L1元素比L2小或相等，则存入L1的元素
            fin[count++]=L1[i];
        }
        else if(L1[i] > L2[i])//相应位置L1元素比L2元素大，则存入L2的元素
            fin[count++]=L2[i];
    }
    if(a < b){//L1数组比L2数组短
        for (i = len; i < b; i++) {
            fin[count++]=L2[i];
        }
    }
    else if(a > b){//L2数组比L1数组短
        for (i = len; i < a; i++) {
            fin[count++]=L1[i];
        }
    }
    for (i = 0; i < count; i++) {//输出合并去重后的结果。
        cout << fin[i] << ' ';
    }
    return 0;
}

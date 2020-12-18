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
    rc = b[i];// 将当前非叶子节点的值赋过去
    for (j = 2 * i; j <= n; j = j * 2) {// 找其孩子节点
        if (j < n && b[j] > b[j + 1]) {// 如果该元素比其兄弟节点大
            ++j;
        }
        if (!(rc > b[j])) {// 如果rc也就是父亲节点比其孩子节点小
            break;
        }
        b[i] = b[j];// 否则，将孩子节点的值赋值给其
        i = j;//改变编号
    }
}
int main(int argc, const char * argv[]) {
    int n,i;
    cin >> n;// 输入n个顶点
    for (i = 1; i <= n; i++) {
        cin >> a[i];// 输入待排序的元素
    }
    for (i = n/2; i > 0; i--) {// 找到其最后一个非叶子节点
        HeapSort(a, i, n);// 依次对其进行排序
    }
    for (i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}

/*#include <iostream>
using namespace std;
int a[100];// 待排序数据元素个数，小于100
int parent(int n){
    return (n - 1) / 2;
}
void HeapSort(int n, int data[]){
    for (int i = 0; i < n; i++) {
        int t = i;
        while (t != 0 && data[parent(t)] > data[t]) {
            int temp = data[t];
            data[t] = data[parent(t)];
            data[parent(t)] = temp;
            t = parent(t);
        }
    }
}
int main(int argc, const char * argv[]) {
    int n,i;
    cin >> n;// 输入n个顶点
    for (i = 0; i < n; i++) {
        cin >> a[i];// 输入待排序的元素
    }
    HeapSort(n,a);
    for (i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}*/

//
//  main.cpp
//  329相同二叉排序树
//
//  Created by 谢容海 on 2020/12/15.
//

#include <iostream>
#include <string>
using namespace std;
#define MAX 100
int a[MAX];// 用来存储第一行序列
int b[MAX];// 用来存储需要被比较的序列
void createTree(string s, int c[])// 根据获得的序列创建二叉排序树
{
    int len = s.length();// 获得序列的长度
    for (int i = 0; i < len; i++)
    {
        int temp = s[i] - '0';// 得到序列中对应位置string类型数字所对应的int型
        for (int j = 1; j <= MAX;)// j为结点的位置
        {
            if (c[j] == -1)// 如果此处为空
            {
                c[j] = temp;// 直接将序列中的该值插入
                break;
            }
            else if (temp < c[j])// 如果要插入的值小于根结点c的值，则插入的位置改变为c的左子树
                j = j * 2;
            else// 否则插入到它的右子树的位置
            {
                j = j * 2 + 1;
            }
        }
    }
    
}
int main()
{
    int n, i;// n代表有n个需要判断
    string s;
    string t;
    while (cin >> n && n)// 输入第一个数n，同时当输入0时停止
    {
        cin >> s;// 输入创建二叉树所根据的序列
        for (i = 0; i < MAX; i++)// 对被用来比较的数组进行初始化
            a[i] = -1;
        createTree(s, a);
        while (n--)// 输入需要判断的序列
        {
            for (i = 0; i < MAX; i++)
                b[i] = -1;// 初始化需要判断的序列数组
            cin >> t;// 输入需要判断的数组
            createTree(t, b);// 创建二叉树
            for (i = 0; i < MAX; i++){
                if (a[i] != b[i])// 如果有不相同的
                    break;// 退出循环
            }
            if (i == MAX)// 判断是否读到了最后
                cout << "YES" << endl;// 若读到了最后，说明二叉排序树相同
            else
                cout << "NO" << endl;// 否则不相同
        }
    }
    return 0;
}

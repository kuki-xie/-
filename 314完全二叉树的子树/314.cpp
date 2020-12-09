//
//  main.cpp
//  314完全二叉树的子树
//
//  Created by 谢容海 on 2020/12/9.
//

#include<iostream>
#include<deque>
using namespace std;
int main() {
    int m,n,right,left,temp;// 结点m所在子树，树的最后一个结点是n
    deque <int> cnt; // 设置双向队列
    while((cin>>m>>n) && (m != 0 && n != 0)) {// 当未读到0 0时，输入m和n
        temp = 0;// 计算结点个数
        left = right = m;// 左右结点赋初值m
        while(left <= n) { // 当左结点未到n（最后一个结点时）
            temp = temp + right - left + 1;// 找规律得，比如头结点1 = 3 - 3 + 1
            left = 2 * left;// 左结点和头结点的关系
            right = 2 * right + 1;// 右结点和头结点的关系
            if(right > n) right = n;// 比如 15 > 12 ; 4 = 3 + 12 - 12 + 1
        }
        cnt.push_back(temp);// 将第一行结果压栈
    }
    while(!cnt.empty()) {
        cout<<cnt.front()<<endl; // 读取栈顶
        cnt.pop_front();// 弹栈
    }
    return 0;
}

/*#include <iostream>
#include <stack>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m,sum;;// 树的最后一个结点是n，结点m所在子树
    stack<int> ans;
    int num;// m结点所在子树的结点数
    while ((cin >> m >> n) && (n != 0 && m != 0)) {
        num = 0;
        int first = m;// 结点是m
        int left = 2 * first;// m的左结点
        int k = 1;
        sum = 0;// 用来记录满层的结点数
        while (!(first <= n && n < left)) {
            first = left;// 向左结点找
            left = first * 2;// 左结点，所有结点必须集中在左边
            k++;// i为n所在层数的上一层，first为n所在层的第一个
        }
        sum = sum + pow(2, k - 1);// i为n所在层数上一层
        if (first + sum - 1 <= n) {
            num = pow(2,k) - 1;
        }
        else
            num = pow(2,k - 1) + n - first;
        ans.push(num);
    }
    while (!ans.empty()) {
        cout << ans.top() << endl;
        ans.pop();
    }
    return 0;
}*/

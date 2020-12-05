//
//  main.cpp
//  292huffman编码2
//
//  Created by 谢容海 on 2020/11/28.
//

//#include<bits/stdc++.h>
#include<iostream>
#include <queue>
using namespace std;
int main() {
    int sum = 0;
    int n;//n个字符（4<n<30)
    cin >> n;//输入一个整数，表示所构成哈夫曼树的带权路径长度
    int i;
    int temp;//字符的出现频度
    int poptemp;
    priority_queue<int,vector<int>,greater<int> >q;
    //优先队列,数据类型，容器类型，比较方式；升序队列
    for(i = 0; i < n; i++) {
        cin >> temp;//依次输入字符的出现频度temp
        q.push(temp);//压入队列中
    }
    while(!q.empty()){//当队列非空
        poptemp = q.top();//栈顶元素赋给poptemp
        q.pop();//从小到大依次弹出当前最小的两个元素 poptemp,temp
        if(!q.empty()){
            int temp = q.top();
            q.pop();
            int s = temp + poptemp;//记录两者总和
            q.push(s);//重新压入队列中
            sum += s;//总代价加上这个值
        }
    }
    cout << sum << endl;
    return 0;
}

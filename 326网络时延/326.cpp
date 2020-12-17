//
//  main.cpp
//  326网络时延
//
//  Created by 谢容海 on 2020/12/17.
//

#include <iostream>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;
typedef struct edge{
    int v,w;// v为目标节点，w为权值
}Edge;
list<Edge> E[21];// 创建一个列表
queue<int> q;// 创建一个队列
int flag[21] = {0},an[21] = {0};
int main(int argc, const char * argv[]) {
    int m,n,k;
    cin >> m >> n >> k;// m为二维数组的，n个网络节点，当前节点k
    int i;
    for (i = 1; i <= n; i++) {
        an[i] = INT_MAX;// 无穷大
    }
    for (i = 1; i <= m; i++) {
        int u;// u是源节点
        Edge e;// 创建一个结构体对象
        cin >> u;// 输入当前节点
        cin>> e.v >> e.w; // 输入目标节点和权值
        E[u].push_back(e);// 将节点信息压入结构体
    }
    q.push(k);// 将第一个接受信号的节点k压入队列中
    flag[k] = 0;// 标志集，初始化表示未访问过该节点
    an[k] = 0;// 存储节点权值，初始化为0
    while (!q.empty()) {// 当队列不为空时
        int t = q.front();// 定义t为队头，第一个就是k节点
        q.pop();// 弹队列
        flag[k] = 1;// 弹出，表示已经访问过该节点
        for (list<Edge>::iterator it = E[t].begin(); it != E[t].end(); it++) {// list可重复 使用迭代器，遍历链表
            if(an[it -> v] > an[t] + it -> w){// 找到距离k最近的节点作为跳板
                an[it -> v] = an[t] + it -> w;// 更新路径weight
                if (!flag[it -> v]) {// 若节点未访问，可以作为跳板
                    q.push(it -> v);// 讲下一个节点压入栈中
                    flag[it -> v] = 0;
                }
            }
        }
    }
    int sum = 0;
    for (i = 1; i <= n; i++) {
        sum = max(sum, an[i]);// 找到最大的返回
    }
    if (sum == INT_MAX) {// 说明加入了权值为无穷大的，也就是有节点不能相连
        cout << "-1";// 输出-1，表示不能使所有节点收到信号
    }
    else
        cout << sum;// 输出最小权值和
    return 0;
}

//
//  main.cpp
//  325图的深度优先遍历
//
//  Created by 谢容海 on 2020/12/16.
//

#include <iostream>
#define MAX 100 // 顶点数<100
using namespace std;
int a[MAX][MAX] = {0};// 邻接矩阵
bool visited[MAX] = {0};// 标记数组，是否访问过
int Count = 0;// 连通分量个数，全局变量
void DFS_Whole(int G[MAX][MAX], int vexnum);//深度优先搜索全部顶点
void DFS(int G[MAX][MAX], int v, int vexnum);//深度优先搜索该顶点

int main(int argc, const char * argv[]) {
    int n;// 顶点个数 < 100
    cin >> n;// 输入n
    int a[MAX][MAX];// 领接矩阵
    int i,j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    /*for (i = 1; i <= n; i++) {// 检查输出
        for (j = 1; j <= n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }*/
    DFS_Whole(a,n);// 深度搜索该邻接矩阵
    cout<< endl;// 换行
    cout << Count << endl;// 输出连通分量的个数
    return 0;
}
void DFS_Whole(int G[MAX][MAX],int vexnum){// 参数为领接矩阵，顶点个数
    int i;
    for (i = 1; i <= vexnum; i++) {
        if (!visited[i]) {// 若未曾访问该顶点
            Count++;// 连通分量个数增加
            cout << i << ' ';// 输出该点
            DFS(G, i, vexnum);// 深度优先搜索该顶点
        }
    }
}
void DFS(int G[MAX][MAX],int v,int vexnum){
    int j;
    visited[v] = 1;// 该顶点已经访问
    for (j = 1; j <= vexnum; j++) {// 使用领接矩阵，找下一个顶点
        if (G[v][j] && !visited[j]) {// 如果此顶点与待比较的顶点有路径，且该顶点未被访问
            cout << j << ' ';// 输出顶点编号
            DFS(G,j,vexnum);// 继续深度优先搜索该顶点
        }
    }
}


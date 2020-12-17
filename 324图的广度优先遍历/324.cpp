//
//  main.cpp
//  324图的广度优先遍历
//
//  Created by 谢容海 on 2020/12/16.
//

#include <iostream>
#define MAX 100 // 顶点数<100
using namespace std;
int a[MAX][MAX] = {0};// 邻接矩阵
bool visited[MAX] = {0};// 标记数组，是否访问过
int Count = 0;// 连通分量个数，全局变量
int vs[MAX] = {0};// 存储已读顶点位置，
void BFS_Whole(int G[MAX][MAX], int vexnum);//广度优先搜索全部顶点
void BFS(int G[MAX][MAX], int v, int vexnum);//广度优先搜索该顶点

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
    BFS_Whole(a,n);// 广度搜索该邻接矩阵
    cout<< endl;// 换行
    cout << Count << endl;// 输出连通分量的个数
    return 0;
}
int b = 1,c = 0;
void BFS_Whole(int G[MAX][MAX],int vexnum){// 参数为领接矩阵，顶点个数
    int i;
    for (i = 1; i <= vexnum; i++) {
        if (!visited[i]) {// 若未曾访问该顶点
            Count++;// 连通分量个数增加
            cout << i << ' ';// 输出该点
            BFS(G, i, vexnum);// 广度优先搜索该顶点
        }
    }
}
void BFS(int G[MAX][MAX],int v,int vexnum){
    int j,k;
    c++;// 从0开始++
    visited[v] = 1;// 该顶点已经访问
    for (j = 1; j <= vexnum; j++) {// 使用领接矩阵，找下一个顶点
        if (G[v][j] && !visited[j]) {// 如果此顶点与待比较的顶点有路径，且该顶点未被访问
            cout << j << ' ';// 输出顶点编号
            visited[j] = 1;// 将此节点标为已读
            vs[b++] = j;// 放入已读节点数组中
        }
    }
    if(c <= b){// 如果还有节点未读
        BFS(G, vs[c], vexnum);// 广度遍历
    }
    
}


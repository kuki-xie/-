//
//  main.cpp
//  303无向图连通子图
//
//  Created by 谢容海 on 2020/11/29.
//

#include <iostream>
#include <algorithm>
#define MAX 101//边数最大为101
using namespace std;

int Graph[MAX][MAX] = {0};//图表
bool visited[MAX + 1] = {0};//访问标志数组
int Count = 0;//计数，连通子图的个数
void DFS_Whole(int G[MAX][MAX], int vexnum);//深度优先搜索全部顶点
void DFS(int G[MAX][MAX], int v, int vexnum);//深度优先搜索该顶点
int size[MAX] = {0};//每个子图的结点的个数
int j = 0;//j是全局变量
int comp(const void* a, const void* b){
    return *(int *)a - *(int *)b;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m;//n表示顶点数，m表示边数
    cin >> n >> m;//输入两个正整数
    int i;
    int src,dest;//表示该边关联的两个顶点
    for (i = 0; i < m; i++) {//对边操作，输入边信息
        cin >> src >> dest;//边的信息，表示该边关联的两个顶点
        Graph[src][dest] = 1;//顶点src到dest之间有路径
        Graph[dest][src] = 1;//则dest到src之间也有路径
    }
    DFS_Whole(Graph, n);//深度优先搜索全部顶点
    cout << Count << endl;//输出连通子图的个数
    sort(size, size + Count);
    for(i = 0; i < Count; i++){
        printf("%d ",size[i]);
    }
    return 0;
}
void DFS_Whole(int G[MAX][MAX],int vexnum){//深度优先搜索所有顶点
    int i;
    for(i = 1; i <= vexnum; i++){//对所有顶点
        if (!visited[i]) {//若未曾访问
            size[j] = 1;//每个子图的结点个数初始设为1
            DFS(G,i,vexnum);//深度优先搜索该顶点
            Count++;//连通子图的个数
            j++;//每次访问完一个连通分量后，j++，遍历下一个连通子集
        }
    }
}
void DFS(int G[MAX][MAX],int v,int vexnum){//深度优先搜索某顶点
    int i;
    visited[v] = 1;//该顶点已被访问
    for (i = 1; i <= vexnum; i++) {//拿所有顶点，和这个顶点比较
        if (G[v][i] && !visited[i]) {//如果此顶点与待比较的顶点间有路径，并且该顶点未被访问
            size[j]++;//每个子图的结点个数++
            DFS(G,i,vexnum);//深度优先该顶点
        }
    }
    
}

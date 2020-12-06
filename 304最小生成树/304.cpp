//
//  main.cpp
//  304最小生成树
//
//  Created by 谢容海 on 2020/12/5.
//

#include <iostream>
#include <algorithm>
#include <set>
#define MAX 100//n,m最大都不超过100
using namespace std;

typedef struct edge{
    int v1;// 分别表示第一顶点，
    int v2;// 第二个顶点
    int wei;// 边上的权值
}Edge[MAX];//存储边的信息
typedef struct {
    int value;// 顶点的数据
    int camp;// 表示每个顶点所属的集合
}vex[MAX];

int count_e;//记录最小生成树的边数

bool cmp(const void * a, const void * b){//排序函数，定义按边的权值大小从小到大排序
    return ((struct edge *)a) -> wei - ((struct edge *)b) -> wei;
}
int f[MAX];// 判断是否形成回路时使用
/*int find_vex(int vexnum, int point){
    for (int i = 0; i < vexnum; i++) {
        if(vex[i].value == point)
            return i;
    }
    return -1;
}
*/
int main(int argc, const char * argv[]) {
    /**
     完成输入操作
     */
    int n,m;//分别表示顶点数和边数
    int i;
    int fv,lv,weight;
    set<int> vex_t;//使用set容器去重储存输入的顶点
    //int v1,v2,wei;
    cin >> n >> m;//第一行为两个正整数n和m,分别表示顶点数和边数
    for (i = 0; i < m; i++) {//输入m行边的信息
        scanf("%d %d %d",&(*edge)[i].v1, &(*edge)[i].v2,&(*edge)[i].wei);//第一个顶点，第二个顶点，权值
        
        vex_t.insert(fv);
        vex_t.insert(lv);
    }
    for (i = 0; i < m; i++) {
        cout << edge[i].v1 << ' ' << edge[i].v2 << edge[i].wei << endl;
    }
    /*
    //进行处理
    sort(edge, edge + m, cmp);//对无向网中所有的边按边的权值进行升序排列，结果仍存储在edge中
    for (i = 0; i < n; i++) {
        int initial = find_vex(n, edge[i].v1);
    }*/
    //std::cout << "Hello, World!\n";
    return 0;
}

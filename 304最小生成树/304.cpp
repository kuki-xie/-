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

struct Edge{
    int v1;// 分别表示第一顶点，
    int v2;// 第二个顶点
    int wei;// 边上的权值
}edge[MAX];//存储边的信息
typedef struct {
    int value;// 顶点的数据
    int camp;// 表示每个顶点所属的集合
}assist[MAX];

int count_e;//记录最小生成树的边数

bool cmp(const void * a, const void * b){//排序函数，定义按边的权值大小从小到大排序
    return ((struct Edge *)a) -> wei - ((struct Edge *)b) -> wei;
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
    set<int> vex_t;//使用set容器去重储存输入的顶点
    //int v1,v2,wei;
    cin >> n >> m;//第一行为两个正整数n和m,分别表示顶点数和边数
    for (i = 0; i < m; i++) {//输入m行边的信息
        cin >> edge[i].v1 >> edge[i].v2 >> edge[i].wei;
        
        vex_t.insert(edge[i].v1);
        vex_t.insert(edge[i].v2);
    }
    /*for (i = 0; i < m; i++) {//检查输入的边信息
        cout << edge[i].v1 << ' ' << edge[i].v2 << ' ' << edge[i].wei << endl;
    }*/
    int count_v = 0;
    set<int>::iterator iter;// 检查set是否存储顶点成功
    for (iter = vex_t.begin(); iter != vex_t.end(); iter++) {// 已给了顶点数为n，所以也可以直接i < n作为判断条件
         assist[count_v++] = *iter;
    }
    /**
     进行处理
     */
    
    sort(edge, edge + m, cmp);//对无向网中所有的边按边的权值进行升序排列，结果仍存储在edge中
    for (i = 0; i < n; i++) {
        int initial = find_vex(n, edge[i].v1);
    }
    //std::cout << "Hello, World!\n";
    return 0;
}

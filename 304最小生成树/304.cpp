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
struct {
    int value;// 顶点的数据
    int camp;// 表示每个顶点所属的集合
}assist[MAX];

int count_e;//记录最小生成树的边数

bool cmp(Edge a,Edge b){//排序函数，定义按边的权值大小从小到大排序
    return a.wei < b.wei;
}
 
int find_vex(int vexnum,int point){//寻找边的两个顶点
    for (int i = 0; i < vexnum; i++) {//对所有顶点遍历
        if (assist[i].value == point) {//若找到所找的顶点，返回编号
            return i;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    /**
     完成输入操作
     */
    int vexnum,arcnum;//分别表示顶点数和边数
    int i;
    set<int> vex_t;//使用set容器去重储存输入的顶点
    //int v1,v2,wei;
    cin >> vexnum >> arcnum;//第一行为两个正整数n和m,分别表示顶点数和边数
    Edge edges[MAX];//创建一个结构体数组用来存储输入的边的信息
    for (i = 0; i < arcnum; i++) {//输入m行边的信息
        cin >> edges[i].v1 >> edges[i].v2 >> edges[i].wei;
        vex_t.insert(edges[i].v1);
        vex_t.insert(edges[i].v2);
    }
    sort(edges, edges + arcnum, cmp);//对无向网中所有的边按边的权值进行升序排列，结果仍存储在edge中
    
    /*for (i = 0; i < arcnum; i++) {//检查输入和sort排序后的边信息
        cout << edges[i].v1 << ' ' << edges[i].v2 << ' ' << edges[i].wei << endl;
    }*/
    int count_v = 0;
    set<int>::iterator iter;// 将set中顶点的信息存入assist结构体数组，后面判断是否形成回路用
    for (iter = vex_t.begin(); iter != vex_t.end(); iter++) {// 已给了顶点数为n，所以也可以直接i < n作为判断条件
        assist[count_v].value = *iter;// 将顶点信息存入assist中
        assist[count_v].camp = count_v;// 该顶点的初始标记
        count_v++;
    }
    /*for (i = 0; i < count_v; i++) {//检查存入assist是否正确
        cout << assist[i].value << ' ' << assist[i].camp << endl;
    }*/
    
    Edge miniTree[MAX];//创建一个空的结构体数组，用来存储最小生成树的
    int num = 0;//用来记录最小生成树

    for (i = 0; i < arcnum; i++) {//对所有的边进行遍历
        int initial = find_vex(vexnum,edges[i].v1);//找到该边的第一个顶点的编号
        int end = find_vex(vexnum, edges[i].v2);
        //如果顶点位置存在且顶点的标记不同，说明不在一个集合中
        if(initial != -1 && end != -1 && assist[i].camp != assist[i].camp){
            miniTree[num] = edges[i];//将该边作为最小生成树的组成部分
            num++;//计数+1
            for(int j = 0; j < vexnum; j++){//将新加入的顶点的标记全部更改为一样
                if(assist[j].camp == assist[end].camp){//如果有顶点标记与新加入边尾的标记相同
                    assist[j].camp = assist[initial].camp;// 将该顶点标记改为边的第一个顶点的标记
                }
            }
            if (num == vexnum-1) {//如果选择的边的数量和顶点数相差1，说明最小生成树已经形成，退出循环
                break;
            }
        }
        
    }
    //输出
    for(i = 0; i < vexnum - 1; i++){
        cout << miniTree[i].v1 << ' '<< miniTree[i].v2 << miniTree[i].wei << endl;
    }
    
    //std::cout << "Hello, World!\n";
    return 0;
}

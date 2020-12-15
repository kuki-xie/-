//
//  main.cpp
//  321高铁网络
//
//  Created by 谢容海 on 2020/12/14.
//

#include <iostream>
using namespace std;
int v[1000];
int find(int x){// 并查集查找
    int r = x;
    while (v[r] != -1) {// 如果它不是独自的
        r = v[r];// 再找下去
    }
    return r;// 返回头
}
int main(){// 并查集查找连通分量
    int cinum,ranum;// 城市数目，高铁数目
    cin >> cinum >> ranum;// 输入城市数目，高铁数目
    int i;
    for (i = 0; i < cinum; i++) {// 初始化
        v[i] = -1;
    }
    int a,b;
    int va,vb;// 用来存放并查集的头
    for (i = 0; i < ranum; i++) {
        cin >> a >> b;// 输入线路两侧城市编号
        va = find(a);
        vb = find(b);
        if (va != vb) {// 如果两个城市连通头不一样 join
            v[va] = vb;// 自定义vb为va的头
        }
    }
    int count = 0;
    for (i = 0; i < cinum; i++) {
        if (v[i] == -1) {// 说明城市独立
            count++;//连通分量个数++
        }
    }
    cout << count - 1 << endl;// 输出连通分量的个数-1
}
/*#include<stdio.h>
#include<stdlib.h>
int vset[100];
int findset(int x)
{
    while (vset[x] != 0)
        x = vset[x];
    return x;
}
int main()
{
    int m, n, i, a, b, va, vb, count;
    scanf("%d", &n);// 输入城市数目
    for (i = 0; i < n; i++)
        vset[i] = 0;// 初始化数组
    scanf("%d", &m);// 输入高铁线路数量
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);// 每行输入线路两侧城市编号
        va = findset(a);
        vb = findset(b);
        if (va != vb)
            vset[va] = vb;
    }
    count = 0;
    for (i = 0; i < n; i++)
    {
        if (vset[i] == 0)
            count++;
    }
    printf("%d", count-1);
    return 0;
 
}*/
/*#include <iostream>
#include <vector>
using namespace std;
struct city{
    int num;
    int cl;
    city(int n):num(n),cl(0){}
};
int c = 0, cnt = 0, cnt1 = 0;
vector<city*> v;//构造一个容器
void merge(int cl1,int cl2){
    for (int i = 0; i < v.size(); i++) {// 遍历城市
        if (v[i] -> cl == cl1) {
            v[i] -> cl = cl2;
        }
    }
}
int main(int argc, const char * argv[]) {
    int citynum,railnum,t1,t2;// 城市数目citynum,高铁线路数目railnum,t1,t2代表每行给出的城市编号
    cin >> citynum >> railnum;// 输入城市数目，高铁线路数目
    for (int i = 0; i < citynum; i++) {//
        city* p = new city(i);
        v.push_back(p);
    }
    for (int i = 0; i < railnum; i++) {
        cin >> t1 >> t2;// 每行输入一对整数，分别是高铁连接的两个城市的编号
        if (v[t1 - 1] -> cl == 0 && v[t2 - 1] -> cl == 0) {
            v[t1- 1] -> cl = v[t2 - 1] -> cl = ++c;
            cnt1++;// 还需修建的线数目+1
            cnt += 2;// 未连通高铁的城市数目+2个
        }
        else if(v[t1 - 1] -> cl == 0 && v[t2 - 1] -> cl != 0){// 如果t1无，t2有
            v[t1- 1] -> cl = v[t2 - 1] -> cl;// 将t2的线赋值给t1
            cnt++;// 连通线路的城市数目+1
        }
        else if (v[t1 - 1] -> cl != 0 && v[t2 - 1] -> cl == 0){// 如果t1有，t2无
            v[t2 - 1] -> cl = v[t1 - 1] -> cl;// 将t1的线赋值给t2
            cnt++;// 连通线路的城市数目+1
        }
        else if (v[t1 - 1] -> cl < v[t2 - 1] -> cl){// 如果t1的连接的线路数目小于t2
            merge(v[t1 - 1] -> cl,v[t2 - 1] -> cl);
            cnt1--;// 还需建设的数目-1
        }
        else if(v[t1 - 1] -> cl > v[t2 - 1] -> cl){// 如果t1连接的线路数目大于t2
            merge(v[t1 - 1] -> cl,v[t2 - 1] -> cl);
            cnt1--;
        }
    }
    if (cnt < citynum) {// 如果数目 < 城市数目
        cnt1 += citynum - cnt;
    }
    cout << cnt1 - 1 << endl;// 输出还需要建设的高铁线路数量
    return 0;
}*/

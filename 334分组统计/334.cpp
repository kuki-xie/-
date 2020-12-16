//
//  main.cpp
//  334分组统计
//
//  Created by 谢容海 on 2020/12/16.
//

#include <iostream>
#include <set>
#include <map>
using namespace std;
int main(){
    int m;// 样例数m
    cin >> m;// 输入样例数
    while (m--) {
        int n;
        cin >> n;// 个数n
        int an[105] = {0},ans[105][105] = {0};// 初始化数组，an存储第二行的数字
        set<int> s,g;// 创建两个set容器
        map<int,int> mp,group;// 创建2个map数组
        for (int i = 1; i <= n; i++) {
            cin >> an[i];// 依次输入第二行的数字
            if (mp[an[i]]) {//如果map中有此key-value,也就是已经未读进这个2/3/8的数字的位置
                continue;// 则终止此次循环，继续下一个循环
            }
            else{
                mp[an[i]] = i;// 如果map中没有此key，也就是还未读进2/3/8这样的数字，就将序号i的value读入key-value
                s.insert(an[i]);// 第二行数字插入set容器s中，剔除重复的数字
            }
        }
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;// 输入值第三行组（各值所属的组）
            if(!group[a]){// 如果key-组数-value对还未在map中
                g.insert(a);// 将组数插入set中，剔除重复的组序号
                group[a] = i;// 将value-i位置，放入key-value中
            }
            ans[group[a]][mp[an[i]]]++;// 同一组的相同数字个数++
        }
        set<int>::iterator it;// 构造set的迭代器
        for(it = g.begin();it != g.end(); it++){
            printf("%d={",*it);// g中存放的是组数（由小到大）
            set<int>:: iterator in;
            for (in = s.begin(); in != s.end(); in++) {// s中存放的是第二行的数字
                if (in != s.begin()) {// 如果不是第一个数
                    putchar(',');// 输出一个逗号
                }
                printf("%d=%d",*in,ans[group[*it]][mp[*in]]);// 输出*in即第二行数字
            }
            printf("}\n");
        }
    }
    return 0;
}

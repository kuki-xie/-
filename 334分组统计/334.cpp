//
//  main.cpp
//  334分组统计
//
//  Created by 谢容海 on 2020/12/16.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int main()
{
    int m;// 样例数m
    cin >> m;// 输入样例数
    while(m--)// 依次输入m个样例
    {
        int n;
        cin >> n;// 个数为n
        int an[105]={0},ans[105][105]={0};// 初始化数组
        set<int> s,g;// 两个set容器
        map<int,int> mp,group;// 两个map容器
        for(int i=1;i<=n;i++)
        {
            cin >> an[i];// 将第三行的数存入数组
            if(mp[an[i]])// 如果key:an[i]已经存在值
                continue;
            else
            {
                mp[an[i]] = i;// 将值i存入对应key：an[i]
                s.insert(an[i]);// 将其插入set容器的s中，s中存数字2 3 8 ....
            }
        }
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;// 输入值对应的组
            if(!group[a])// 如果key：a未在map
            {
                g.insert(a);// 插入set容器，g中存组数1-3...
                group[a] = i;// 将位置赋值进去
            }
            ans[group[a]][mp[an[i]]]++;
        }
        set<int>::iterator it;// 构造set的迭代器
        for(it=g.begin();it!=g.end();it++)
        {
            printf("%d={",*it);// 输出组数
            set<int>::iterator in;
            for(in=s.begin();in!=s.end();in++)
            {
                if(in!=s.begin())
                    putchar(',');// 输出一个字符
                printf("%d=%d",*in,ans[group[*it]][mp[*in]]);
            }
            printf("}\n");
        }
    }
    return 0;
}

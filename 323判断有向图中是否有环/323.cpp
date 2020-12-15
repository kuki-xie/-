//
//  main.cpp
//  323判断有向图中是否有环
//
//  Created by 谢容海 on 2020/12/15.
//

#include <iostream>
#include <vector>
using namespace std;
struct node{
    int num;
    int visit;
    vector<int> adj;
    node(int i): num(i),visit(0){}
};
int dfs(node* p,vector<node*>& map,int& code){
    if (p -> adj.size() == 0) {
        return 0;
    }
    for (int i = 0; i < p -> adj.size(); i++) {
        if (p -> visit == 0) {
            p -> visit = code;
        }
        else if(p -> visit != code){
            p -> visit = code;
        }
        else return 1;
        int t = dfs(map[p -> adj[i]], map, code);
        if (t == 1) {
            return 1;
        }
        return 0;
    }
}
int main(int argc, const char * argv[]) {
    int n,t,m;
    vector<int> ans;//全局
    cin >> m;// 表示有m个有向图
    for(int k = 0;k < m;k++){
        cin >> n;// 表示图中顶点个数
        vector<node*> nodes;// local
        for (int i = 0; i< n; i++) {
            node* ptr = new node(i);
            nodes.push_back(ptr);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> t;
                if (t) {
                    nodes[i] -> adj.push_back(j);
                }
            }
        }
        int flag = 0, code = 0;
        for (int i = 0; i < n; i++) {
            if (nodes[i] -> visit == 0) {
                code++;
                t = dfs(nodes[i], nodes, code);
                if (t == 1) {
                    flag = 1;
                }
            }
        }
        ans.push_back(flag);
    }
    for (int k = 0; k < m; m++) {
        cout << ans[k];
    }
    cout << endl;
    return 0;
}

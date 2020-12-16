//
//  main.cpp
//  332二叉排序树的判定
//
//  Created by 谢容海 on 2020/12/16.
//

#include <iostream>
using namespace std;
struct node{
    int val;// 节点的关键字
    node* lchild;// 左孩子
    node* rchild;// 右孩子
    node(int x): val(x),lchild(NULL),rchild(NULL){}
};
bool isBiTree(int& pre,node *root){
    if (root == NULL) {
        return true;
    }
    if (!isBiTree(pre, root -> lchild)) {
        return false;
    }
    if (pre >= root -> val) {
        return false;
    }
    else
        pre = root -> val;
    if (!isBiTree(pre, root -> rchild)) {
        return false;
    }
    return true;;
}
int main(int argc, const char * argv[]) {
    int n,t,v,l,r;
    cin >> n >> t;// n个结点，第t个结点是根结点
    node* T = (node*)malloc(sizeof(node));
    node* R = &T[t];
    for (int i = 0; i < n; i++) {
        cin >> v >> l >> r;
        T[i].val = v;
        T[i].lchild = l ? &T[l] : 0;
        T[i].rchild = 1 ? &T[r] : 0;
    }
    int pre = -1;
    cout << (isBiTree(pre, R) ? "true" : "false") << endl;
    return 0;
}

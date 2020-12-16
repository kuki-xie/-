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
    node(int x): val(x),lchild(NULL),rchild(NULL){}// 把x赋给val，left和right赋值NULL
};
bool isBiTree(int& pre,node *root){// 判断是否为二叉排序树
    if (root == NULL) {// 如果为空
        return true;
    }
    if (!isBiTree(pre, root -> lchild)) {// 如果左子树不是二叉排序树
        return false;
    }
    if (pre >= root -> val) {// 如果
        return false;
    }
    else
        pre = root -> val;
    if (!isBiTree(pre, root -> rchild)) {// 如果右子树不是二叉排序树
        return false;
    }
    return true;;
}
int main(int argc, const char * argv[]) {
    int n,t; // n个结点，第t个结点为根结点
    int v,l,r;// 定义结点的值为v,第l个为左孩子，第r个为右孩子
    cin >> n >> t;// n个结点，第t个结点是根结点
    node* T = (node*)malloc(sizeof(node)*(n + 1));//
    node* R = &T[t];
    for (int i = 1; i <= n; i++) {
        cin >> v >> l >> r;
        T[i].val = v;// 输入结点的值v
        T[i].lchild = l ? &T[l] : 0;// 若l不为0,其左孩子为第l个结点，否则为空
        T[i].rchild = r ? &T[r] : 0;// 若r不为0,其右孩子为第r个结点，否则为空
    }
    int pre = -1;
    cout << (isBiTree(pre, R) ? "true" : "false") << endl;
    return 0;
}

//
//  main.cpp
//  320二叉树的不同形态
//
//  Created by 谢容海 on 2020/12/14.
//

#include <iostream>
using namespace std;
#define MAX 1024// 结点个数<1024
int layer[MAX];// 储存层次遍历序列
int inoreder[MAX];// 储存中序遍历序列
int n;// 表示二叉树中的结点数目
typedef struct NODE{
    int data;// 结点的值
    int level;// 深度
    struct NODE* lchild;// 其左孩子
    struct NODE* rchild;// 其右孩子
}node, *Tree;
void PreOrderTraverse(Tree T){// 先序遍历
    if (T == NULL) {
        return;
    }
    cout << T -> data << ' ';// 输出结点的值
    PreOrderTraverse(T -> lchild);// 遍历其左子树
    PreOrderTraverse(T -> rchild);// 遍历其右子树
}
void PostOrderTraverse(Tree T){// 后序遍历
    if (T == NULL) {
        return;
    }
    PostOrderTraverse(T -> lchild);// 遍历其左子树
    PostOrderTraverse(T -> rchild);// 遍历其右子树
    cout << T -> data << ' ';// 输出结点的值
}
Tree BaseLevelInCreateTree(int* layer,int* inoreder,int n){// 基于层次遍历序列创建树
    node* root;
    root = new node;// 分配内存
    root -> data = layer[0];// 根据层次遍历，将根结点的值赋值
    int i,k;
    int l,r;
    int lcnt = 0,rcnt = 0;// 根节点两端节点数统计
    int left[1024];// 左子树节点存放数组
    int right[1024];// 右子树节点存放数组
    lcnt = rcnt = 0;// 左右两端节点数初始化为0
    if(n == 0)
        return NULL;// 如果没节点需要被加入，返回空值
    for (i = 0; i < n; i++) {
        if (layer[0] == inoreder[i]) {// 找到对应根节点
            break;
        }
    }
    for (k = 0; k < n; k++) {// 左右子树划分
        for (l = 0; l < i; l++) {// 中序序列中左子树部分
            if (inoreder[l] == layer[k]) {
                left[lcnt++] = layer[k];// 相当于入栈
            }
        }
        for (r = 0; r < n - 1 - i; r++) {
            if (inoreder[r + i + 1] == layer[k]) {// 中序序列中相当于右子树的部分
                right[rcnt++] = layer[k];// 相当于入栈
            }
        }
    }
    root -> lchild = BaseLevelInCreateTree(left, inoreder,lcnt);// 左孩子创建
    root -> rchild = BaseLevelInCreateTree(right, inoreder + i + 1,rcnt);// 右孩子创建
    return root;
}
void TellLeaf(Tree T){
    if(T != NULL){
        if (T -> lchild == NULL && T -> rchild == NULL) {
            cout << T -> data << ' ';
        }
        TellLeaf(T -> lchild);
        TellLeaf(T -> rchild);
    }
}
int main(int argc, const char * argv[]) {
    
    cin >> n;
    int i;
    for (i = 0; i < n; i++) {
        cin >> layer[i];// 输入层次序列
    }
    for (i = 0; i < n; i++) {
        cin >> inoreder[i];// 输入中序序列
    }
    Tree T = NULL;
    T = BaseLevelInCreateTree(layer,inoreder,n);
    TellLeaf(T);
    cout << endl;
    PreOrderTraverse(T);
    cout << endl;
    PostOrderTraverse(T);
    return 0;
}

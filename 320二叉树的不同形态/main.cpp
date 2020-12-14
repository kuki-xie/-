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
void BaseLevelInCreateTree(Tree T,int val){// 基于层次遍历序列创建树
    node* root;
    root = new node;// 分配内存
    root -> data = layer[0];// 根据层次遍历，将根结点的值赋值
    /*Tree root = new node;// 分配内存
    root -> lchild = root -> rchild = NULL;// 初始化左右孩子
    root -> data = layer[0];// 给结点赋值
    int i = 0, nodei = 0;
    for(i = 0; i <= n; i++){// 找到层次遍历该值在中序序列中的位置
        if(val == inoreder[i]){
            nodei = i;// 记录结点位置
            break;
        }
    }
    int rooti = 0;
    for (i = 0; i <= n; i++) {// 对中序序列遍历
        if (root -> data == inoreder[i]) {// 如果发现有结点的值等于根结点的值
            rooti = i;// 则将序号赋值给根结点的位置
            break;
        }
    }
    if (nodei < rooti) {// 插入的结点在根结点左侧
        BaseLevelInCreateTree(root -> lchild, val);// 左子树插入
    }
    if (nodei > rooti) {// 插入的结点在根结点的右侧
        BaseLevelInCreateTree(root -> rchild, val);// 右子树插入
    }*/
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
    for (i = 0; i < n; i++) {
        BaseLevelInCreateTree(T,layer[i]);
    }
    PreOrderTraverse(T);
    PostOrderTraverse(T);
    return 0;
}

//
//  main.cpp
//  331二叉树的遍历
//
//  Created by 谢容海 on 2020/12/15.
//

#include <iostream>
using namespace std;
struct NODE{
    int key;// 记录节点的关键字
    struct NODE* lchild;// 节点的左孩子
    struct NODE* rchild;// 节点的右孩子
}node,*Tree;
void initTree(Tree &T,int data){
    if (!T) {// 如果树为初始化
        T = (Tree)malloc(sizeof(node));
        T -> key = data;// 将关键字存入节点的data
        T -> lchild = NULL;// 初始化左孩子
        T -> rchild = NULL;// 初始化右孩子
    }
    if (data < T -> key) {// 如果待插入的值小于节点的值
        initTree(T -> lchild,data);
    }
    if (data > T -> key) {
        init(T -> rchild,data);
    }
}
void PreOrderTraverse(Tree T){
    if (T == NULL) {
        return;
    }
    cout << T -> key << ' ';
    PreOrderTraverse(T -> lchild);// 遍历其左子树
    PreOrderTraverse(T -> rchild);// 遍历右子树
}
void InOrderTraverse(Tree T){
    if (T == NULL) {
        return;
    }
    InOrderTraverse(T -> lchild);// 遍历起左孩子
    cout << T -> key << ' ';//输出根结点
    InOrderTraverse(T -> rchild);// 遍历其右孩子
}
void PostOrderTraverse(Tree T){
    if (T == NULL) {
        return;
    }
    PostOrderTraverse(T -> lchild);// 遍历其左孩子
    PostOrderTraverse(T -> rchild);// 遍历其右孩子
    cout << T -> key << ' ';//输出根结点
}
int main(int argc, const char * argv[]) {
    int n;// 表示待插入的节点数
    cin >> n;// 输入待插入的节点数
    int i;
    int a[101];// 数组用来存储输入的数字
    Tree T = NULL;// 声明一个树
    for (i = 0; i < n; i++) {
        cin >> a[i];
        initTree(T,a[i]);// 构建二叉排序树
    }
    PreOrderTraverse(T);
    cout << endl;
    InOrderTraverse(T);
    cout << endl;
    PostOrderTraverse(T);
    cout << endl;
    //initTree(a[n]);
    return 0;
}

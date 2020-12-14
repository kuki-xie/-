//
//  main.cpp
//  318二叉树遍历
//
//  Created by 谢容海 on 2020/12/12.
//

#include <iostream>
using namespace std;
#define MAX 27
char str1[MAX];// 先序序列
char str2[MAX];// 中序序列
typedef struct NODE{
    char data;// 代表字母
    struct NODE* lchild;// 左孩子
    struct NODE* rchild;// 右孩子
}node,*Tree;

void PostOrderTraverse(Tree T){
    if (T == NULL) {// 如果树为空
        return;
    }
    PostOrderTraverse(T -> lchild);// 遍历左子树
    PostOrderTraverse(T -> rchild);// 遍历右子树
    printf("%c",T -> data);// 输出结点值
}
Tree BuildTree(int start1, int end1, int start2, int end2){
    Tree root = (Tree)malloc(sizeof(node)); // 分配内存
    root -> lchild = root -> rchild = NULL;// 初始化左子树
    root -> data = str1[start1];// 通过先序序列对根结点值进行赋值
    int i = 0, rooti = 0;
    for (i = start2; i <= end2; i++) {// 遍历中序遍历
        if (str2[i] == str1[start1]) {// 当结点值相等时，说明找打了根结点
            rooti = i;//
            break;
        }
    }
    if (rooti != start2) {// 如果结点的位置不是根结点的左孩子
        root -> lchild = BuildTree(start1 + 1, start1 + (rooti - start2), start2, rooti - 1);// 建立左子树，从根结点下一个位置
    }
    if (rooti != end2) {// 结点的位置不是根结点的右孩子
        root -> rchild = BuildTree(start1 + (rooti - start2) + 1, end1, rooti + 1, end2);// 建立根结点的右子树
    }
    return root;
}
int main(int argc, const char * argv[]) {
    cin >> str1;//
    cin >> str2;
    int len1 = strlen(str1);// 输入先序遍历序列
    int len2 = strlen(str2);// 输入中序遍历序列
    Tree T;// 创建结构体
    T = BuildTree(0, len1 - 1, 0, len2 - 1);// 创建树，将序列第一个位置和最后一个位置作为参数
    PostOrderTraverse(T);
    return 0;
}

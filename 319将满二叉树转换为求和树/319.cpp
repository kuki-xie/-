//
//  main.cpp
//  319将满二叉树转换为求和树
//
//  Created by 谢容海 on 2020/12/14.
//

#include <iostream>
using namespace std;
#define MAX 100
int prestr[MAX];// 储存先序序列的值
int instr[MAX];// 储存中序序列的值
typedef struct NODE{
    int data;
    int sum;
    struct NODE* lchild;
    struct NODE* rchild;
}node,*Tree;
void InOrderTraverse(Tree T){// 定义中序序列
    if (T == NULL) {
        return;// 如果是空树
    }
    InOrderTraverse(T -> lchild);// 中序遍历左子树
    cout << (T -> sum) << ' ';// 输出结点值
    InOrderTraverse(T -> rchild);// 中序遍历右子树
}
Tree BasePreInCreateTree(int s1, int e1,int s2,int e2){// 根据先序和中序序列创建树
    Tree root;
    root = (Tree)malloc(sizeof(node));
    root -> lchild = root -> rchild = NULL;// 对左右子树初始化
    root -> data = prestr[s1];// 根据先序序列，将根结点的值赋过去
    int i = 0,rooti = 0;// rooti用来记录根结点在中序遍历序列中的位置
    for (i = s2; i <= e2; i++) {// 对中序序列进行遍历
        if (prestr[s1] == instr[i]) {// 如果中序序列中有一个结点的值等于先序序列的第一个结点即根结点的值
            rooti = i;// 那么i就是此时根结点在中序序列中的位置
            break;// 退出循环
        }
    }
    if(rooti != s2){// 如果该树有左子树
        root -> lchild = BasePreInCreateTree(s1 + 1, s1 + (rooti - s2), s2, rooti - 1);
    }
    if (rooti != e2) {// 如果该树有右子树
        root -> rchild = BasePreInCreateTree(s1 + (rooti - s2) + 1, e1, rooti + 1, e2);
    }
    return root;// 返回结点
}
void SumCreateTree(Tree T){// 转换求和树
    if (T -> lchild == NULL && T -> rchild == NULL) {// 如果树的左右孩子都是空,说明到了叶子结点
        T -> sum = 0;
        return;
    }
    SumCreateTree(T -> lchild);// 递归看其左孩子的值
    SumCreateTree(T -> rchild);// 递归看其右孩子的值
    if(T -> lchild != NULL && T -> rchild != NULL){//是满二叉树
        T -> sum = (T -> lchild -> data) +(T -> lchild -> sum) + (T -> rchild -> data) + (T -> rchild -> sum);// 求和
    }
}
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;// 输入满二叉树结点个数n
    int i;
    for (i = 0; i < n; i++) {
        cin >> prestr[i];// 输入先序遍历序列值，空格隔开
    }
    for (i = 0; i < n; i++) {
        cin >> instr[i];// 输入中序遍历序列值，空格隔开
    }
    Tree T;
    T = BasePreInCreateTree(0, n - 1, 0, n - 1);
    SumCreateTree(T);// 转换为求和树
    InOrderTraverse(T);// 中序遍历求和树
    return 0;
}
/*#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int int1[MAX_SIZE];
int int2[MAX_SIZE];

typedef struct NODE{
    int data;
    int sum;
    struct NODE* lchild;
    struct NODE* rchild;
}node,*Tree;

void InOrderTraverse(Tree T){
    if(T==NULL){
        return;
    }
    InOrderTraverse(T->lchild);
    printf("%d ",T->sum);
    InOrderTraverse(T->rchild);
}

Tree BasePreInCreatTree(int s1,int e1,int s2,int e2){
    Tree root;
    root = (Tree)malloc(sizeof(node));
    root->lchild = root->rchild = NULL;
    root->data = int1[s1];
    int i,RootIdx;
    for(i=s2;i<=e2;i++){
        if(int2[i]==int1[s1]){
            RootIdx = i;
            break;
        }
    }
    //Ω®¡¢◊Û◊” ˜
    if(RootIdx!=s2){
        root->lchild = BasePreInCreatTree(s1+1,s1+(RootIdx-s2),s2,RootIdx-1);
    }
    //Ω®¡¢”“◊” ˜
    if(RootIdx!=e2){
        root->rchild = BasePreInCreatTree(s1+(RootIdx-s2)+1,e1,RootIdx+1,e2);
    }
    return root;
}

void SumCreatTree(Tree T){
    if(T->lchild==NULL&&T->rchild==NULL){
        T->sum = 0;
        return;
    }
    SumCreatTree(T->lchild);
    SumCreatTree(T->rchild);
    if(T->lchild!=NULL&&T->rchild!=NULL){
        T->sum = T->lchild->data +T->lchild->sum + T->rchild->data + T->rchild->sum;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&int1[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d",&int2[i]);
    }
    Tree T;
    T = BasePreInCreatTree(0,n-1,0,n-1);
    SumCreatTree(T);
    InOrderTraverse(T);
    return 0;
}

*/

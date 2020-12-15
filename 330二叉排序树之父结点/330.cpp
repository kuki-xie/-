//
//  main.cpp
//  330二叉排序树之父结点
//
//  Created by 谢容海 on 2020/12/15.
//

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct node{
    int key;// 记录节点的关键字值
    struct node * lchild;// 记录其左孩子
    struct node * rchild;// 记录其右孩子
}Node, * Tree;
int s;// 表示待插入节点的关键字值
int n;// 表示待插入的节点数
int fdata = -1;// 将父结点的关键字值初始为-1
void ins(Tree &T ,int data){// 寻找插入节点的父结点的关键字值
    if(!T){// 如果树未分配内存
        T = (Tree)malloc(sizeof(Node));// 为树分配内存
        cout << fdata << endl;// 输出父节点的关键字值
        T -> key = data;// 将关键字值存入该节点
        T -> lchild = NULL;// 初始化左孩子
        T -> rchild = NULL;// 初始化右孩子
    }
    if(data < T -> key){// 如果待插入的的值小于节点的值
        fdata = T -> key;// 插入的同时保存父节点的数值
        ins(T -> lchild, data);// 将其插到节点的左子树上
    }
    if(data > T -> key){// 如果待插入的值大于节点
        fdata = T->key;// 记录父结点的值
        ins(T -> rchild, data);// 将其插入到它的右子树
    }
}
int main(){
    while(cin >> n){// n是待插入的节点数
        Tree T = NULL;// 声明树
        for(int i = 0; i < n; i++){// 循环输入
            cin >> s;// 插入节点的关键字值
            ins(T, s);// 输出其父结点的关键字值
        }
    }
}



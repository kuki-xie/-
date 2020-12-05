//
//  main.cpp
//  292huffman编码
//
//  Created by 谢容海 on 2020/11/23.
//

#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;//表示权值
    struct node *next;//下一个结点的地址
}Linklist;
//创建链表
Linklist* create(int array[],int n){//创建哈夫曼树
    int i;
    Linklist *head,*p,*q;//分别表示头结点和左孩子，右孩子
    head=(Linklist *)malloc(sizeof(Linklist));//分配内存
    head->next=p=q=NULL;//初始化
    for(i=0;i<n;i++){
        q=(Linklist *)malloc(sizeof(Linklist));//分配内存
        q->data=array[i];//将链表中的每一个权值都赋给q
        q->next=NULL;
        if(head->next==NULL){
            head->next=q;
            p=q;
        }else{
            p->next=q;
            p=q;
        }
    }
    return head;
}
//将数字有序插入
Linklist * insert(Linklist *head,int num){
    Linklist *p,*q;
    q=(Linklist *)malloc(sizeof(Linklist));//分配内存
    q->data=num;
    q->next=NULL;
    p=head;
    if(head->next==NULL){//最后一次为空还需要插入值
        head->next=q;
    }else{
        while(p->next!=NULL&&num>p->next->data){
            p=p->next;
        }
        q->next=p->next;
        p->next=q;
    }
    return head;
}
//删除头元素
Linklist *delHead(Linklist *head){
    Linklist *p;
    p=head->next;
    head->next=p->next;
    free(p);
    return head;
}
int main(void){
    int n,i,j,temp;
    int array[41];
    int sum,sum1,sum2,count;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    //给数组排序
    for(i=1;i<n;i++){
        for(j=i;j>0;j--){
            if(array[j]<array[j-1]){
                temp=array[j];
                array[j]=array[j-1];
                array[j-1]=temp;
            }
        }
    }
    //创建链表
    Linklist *head=create(array,n);
    Linklist *p;
    count=0;//表示路径长度
    while(head->next->next!=NULL){
        sum1=head->next->data;
        head=delHead(head);
        sum2=head->next->data;
        head=delHead(head);
        sum=sum1+sum2;
        count+=sum;
        head=insert(head,sum);
    }
    printf("%d",count);
    return 0;
}

/*
#include <iostream>
using namespace std;
struct BiTreeNode{
    int data;//表示权值
    BiTreeNode* lchild;//左孩子
    BiTreeNode* rchild;//右孩子
}bnode;

BiTreeNode* createHuffman(int arr[n],int n){
    BiTreeNode ** b,
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;//n的值，表示电文由n个字符组成
    int i;
    cin >> n;
    int arr[31];//4<n<30
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    /**for (i = 0; i < n; i++) {//检查输入是否成功
        cout << arr[i] << ' ';
    }*/
    
    //std::cout << "Hello, World!\n";
    /*return 0;
}
*/

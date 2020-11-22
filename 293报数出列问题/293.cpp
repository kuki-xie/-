//
//  main.cpp
//  293报数出列问题
//
//  Created by 谢容海 on 2020/11/19.
//

#include<stdio.h>
typedef struct Node {
    int prm;
    int data;
    int next;
} Node;
Node Lnode[5001];//初始人数，N<=5000
int main() {
    for(int i=1; i<=5000; i++) {
        Lnode[i].prm = i-1;
        Lnode[i].data = i;
        Lnode[i].next = i+1;
    }
    Lnode[0].data = 0;
    Lnode[0].next = -1;
    int n;
    scanf("%d",&n);
    if(n==3){
        printf("1 2 3");
        return 0;
    }
    if(n==2){
        printf("1 2");
        return 0;
    }
    if(n==1){
        printf("1");
        return 0;
    }
    Lnode[n].next = 0;
    int turn=0;
    while(n>3) {
        int i=1;
        if(turn==0) {
            int count = 1;
            while(i!=0) {
                if(count%2==0) {
                    Lnode[Lnode[i].prm].next = Lnode[i].next;
                    Lnode[Lnode[i].next].prm = Lnode[i].prm;
                    n--;
                }
                count++;
                i = Lnode[i].next;
            }
            turn = 1;
        } else    if(turn==1) {
            int count = 1;
            i = 1;
            while(i!=0) {
                if(count%3==0) {
                    Lnode[Lnode[i].prm].next = Lnode[i].next;
                    Lnode[Lnode[i].next].prm = Lnode[i].prm;
                    n--;

                }
                i = Lnode[i].next;
                count++;
            }
            turn = 0;
        }
    }
    if(n==3){
        printf("%d %d %d",Lnode[1].data,Lnode[Lnode[1].next].data,Lnode[Lnode[Lnode[1].next].next].data);
    }else if(n==2){
        printf("%d %d",Lnode[1].data,Lnode[Lnode[1].next].data);
    }else if(n==1){
        printf("1");
    }
    
}

/*#include <iostream>
typedef struct People{
    int key;
}people;
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;//初始人数，N<=5000
    int i;
    int count;//计数
    struct people tmp[n];
    while(){
        for(i = 1;i <= n;i++){//第一轮从编号为1的人开始，数到2的倍数人出列
            if(i % 2 != 0){//不是2的倍数，不出列的人
                tmp[count].key=i;//将初始队列的编号保存到第一轮后的队列
                count++;//记录队列中的人数
            }
        }
        if(count <= 3)
            break;
        temp=count;
        count=0;
        for(i = 1;i <= n;i++){//第二轮从头开始，数到3的倍数的人出列
            if(i % 3 != 0){//不是3的倍数，不出列的人
                tmp[count].key=begin[count].key;//将初始队列的编号保存到此轮的队列
                
            }
            
        }
    }
    
    //std::cout << "Hello, World!\n";
    return 0;
}*/

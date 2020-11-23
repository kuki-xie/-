//
//  main.cpp
//  293报数出列问题
//
//  Created by 谢容海 on 2020/11/19.
//

#include <iostream>
using namespace std;
typedef struct Node {
    int prm;//前一个人的编号
    int data;//表示编号
    int next;//下一个人的
} Node;
Node Lnode[5001];//初始人数，N<=5000
int main(int argc, const char * argv[]){
    for(int i=1; i<=5000; i++) {//对1-N的队列初始化
        Lnode[i].prm = i-1;
        Lnode[i].data = i;//赋编号
        Lnode[i].next = i+1;//下一个人的编号
    }
    Lnode[0].data = 0;//初始化Lnode[0]
    Lnode[0].next = -1;
    int n;//n,表示初始人数
    scanf("%d",&n);//输入N
    if(n==3){//如果三个人
        printf("1 2 3");//直接输出初始队列编号
        return 0;
    }
    if(n==2){//如果两个人
        printf("1 2");
        return 0;
    }
    if(n==1){//如果一个人
        printf("1");
        return 0;
    }
    Lnode[n].next = 0;//对队列末尾进行初始化,表示队列报结束的标志
    int turn=0;
    while(n>3) {//当队列中人数大于3个的时候
        int i=1;//i表示初始队列中的人的编号
        if(turn==0) {
            int count = 1;//count表示人在这个changing队列中的编号
            while(i!=0) {
                if(count%2==0) {//如果此人是2的倍数
                    Lnode[Lnode[i].prm].next = Lnode[i].next;//此人即将出列，它的下一人编号赋给它的前一人
                    Lnode[Lnode[i].next].prm = Lnode[i].prm;//它的下一人的前一人编号赋给它前一人
                    n--;//此人出列，队列数-1
                }
                count++;//到达队列中的下一人
                i = Lnode[i].next;//初始队列中下一个人
            }
            turn = 1;//该轮结束，进入下一轮数3
        } else if(turn==1) {//turn为1表示该队列报3出列
            int count = 1;//还是从changing队列中的第一人开始
            i = 1;
            while(i!=0) {//未报到队列末尾
                if(count%3==0) {//如果该人报到了3
                    Lnode[Lnode[i].prm].next = Lnode[i].next;//进行删除此人操作，同时需要保留此人前一人编号和后一人编号
                    Lnode[Lnode[i].next].prm = Lnode[i].prm;
                    n--;//此人出列，队列数-1
                }
                i = Lnode[i].next;
                count++;//轮到下一个人报数
            }
            turn = 0;
        }
    }
    if(n==3){//如果队列中只剩3人
        printf("%d %d %d",Lnode[1].data,Lnode[Lnode[1].next].data,Lnode[Lnode[Lnode[1].next].next].data);
    }else if(n==2){//如果队列中只剩2人
        printf("%d %d",Lnode[1].data,Lnode[Lnode[1].next].data);
    }else if(n==1){//如果队列中只剩1人
        printf("1");
    }
    
}

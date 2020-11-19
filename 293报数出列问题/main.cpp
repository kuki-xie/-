//
//  main.cpp
//  293报数出列问题
//
//  Created by 谢容海 on 2020/11/19.
//

#include <iostream>
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
        for(i = 1;i <= temp;i++){//第二轮从头开始，数到3的倍数的人出列
            if(i % 3 != 0){//不是3的倍数，不出列的人
                tmp[count].key=begin[count].key;//将初始队列的编号保存到此轮的队列
                
            }
            
        }
    }
    
    //std::cout << "Hello, World!\n";
    return 0;
}

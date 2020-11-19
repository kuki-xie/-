//
//  main.cpp
//  258lianbiaoquchong
//
//  Created by 谢容海 on 2020/11/16.
//

#include <iostream>
#include <cstring>
#include <set>
using namespace std;
typedef struct Node{
    int key;
    char src[100];
    char dest[100];
}Node;
int main(int argc, const char * argv[]) {
    // insert code here...
    char begin;//
    int n;//结点个数
    int i;
    char temp[100];
    int count = 0;//去重后的链表内的数量
    cin>>begin>>n;//输入两个数，begin在前，n在后
    struct Node arr[n];//输入用的数组
    struct Node tmp[n];//排队后的链表
    struct Node fin[n];//去重后的链表
    set<int> window;// set类型
    for(i=0;i<n;i++)
    {
        cin>>arr[i].src>>arr[i].key>>arr[i].dest;// source源文件,destination目标; 分别输入结点地址，key，下一个结点的地址
    }
    //将输入的结点按照地址放入链表
    while(count<n)
    {
        strcpy(temp, begin);//先将begin(链表的第一个结点的地址)赋值给temp
        for (i=0; i<n; i++) {
            if (strcmp(arr[i].src, temp) == 0) {//如果给定的第一个结点的地址和输入的n个结点中的一个结点的地址相同
                strcpy(tmp[count].src,arr[i].src);//开始读入结点的地址
                tmp[count].key = arr[i].key;
                strcpy(tmp[count].dest, arr[i].dest);
                count++;
                strcpy(begin,arr[i].dest);//将下一个结点的地址赋给temp，准备比较
            }
        }
    }
    count = 0;//重置count
    for (i=0; i<n; i++) {
        if(window.insert(abs(tmp[i].key)).second)//插入第一个key的绝对值，second判断成功(set集合中不可以包含重复的元素，以此去重)
        {
            strcpy(fin[count].dest, tmp[i].dest);//将下一个结点的地址赋入
            fin[count].key= tmp[i].key;
            strcpy(fin[count].src,tmp[i].src);
            count++;
        }
        else
        {
            strcpy(fin[count-1].dest,tmp[i].dest);//将下一结点的地址赋给回退的那个结点
        }
    }
    cout<<window.size()<<endl;//输出去重后的链表的长度
    for(i=0;i<window.size();i++){
        cout<<fin[i].src<<' '<<fin[i].key<<' '<<fin[i].dest<<endl;//按顺序输出去重后的链表
    }
    //std::cout << "Hello, World!\n";
    return 0;
}

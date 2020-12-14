//
//  main.cpp
//  328哈希表
//
//  Created by 谢容海 on 2020/12/14.
//

#include <iostream>
using namespace std;
int m,p;// 哈希表表长m,除数p
int data;// 输入的关键字
int hashMap[100];// 哈希表数组
int sizeOfMap;
void init(){
    cin >> m >> p;// 输入表长和除数
    memset(hashMap, -1, sizeof(int)*100);// 对哈希表初始化，分配内存
}
int insert(int target){// 定义插入关键字
    if (sizeOfMap == m - 1) {// 如果表中关键字个数达到m-1
        for (int i = 0; i < m - 1; i++) {// 遍历表
            if (hashMap[i] == target) {// 如果输入的关键字在哈希表中已存在
                return i;// 输出该关键字在哈希表中的位置
            }
        }
        return -1;// 返回-1，表示哈希表已满
    }
    int key = target % p;// 关键字位置，由除留余数法构造哈希函数
    for (int i = key; i < m - 1; i++) {// 从这个位置往后开始遍历
        if (hashMap[i] == target) {// 如果输入的关键字在哈希表中已存在
            return i;// 输出该关键字在哈希表中的位置
        }
        if (hashMap[i] == -1) {// 输入的关键字在哈希表中不存在
            hashMap[i] = target;// 将关键字插入哈希表
            sizeOfMap++;// 哈希表中关键字个数增加
            return i;// 输出关键字在哈希表中的位置
        }
    }
    for (int i = 0; i < key; i++) {// 如果key后位置没有，那就回头再找
        if (hashMap[i] == target) {// 如果找到了这个结点的值
            return i;// 返回位置
        }
        if (hashMap[i] == -1) {
            hashMap[i] = target;
            sizeOfMap++;
            return i;
        }
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    init();// 完成哈希表长度和除数的输入
    while (true) {
        scanf("%d",&data);
        if (data == -1) {// 以-1作为输入的结束
            break;
        }
        int temp = insert(data);
        if (temp == -1) {// 此时哈希表已经满
            cout << "Table full" << endl;// 输出Table full
            break;
        }
        else
            cout << temp << endl;
    }
    return 0;
}

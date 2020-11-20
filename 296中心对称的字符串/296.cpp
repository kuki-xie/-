//
//  main.cpp
//  296中心对称的字符串
//
//  Created by 谢容海 on 2020/11/20.
//

#include <iostream>
using namespace std;//此处有分号
int main(int argc, const char * argv[]) {
    int n;//表示字符的个数
    int i;
    char arr[100];//输入的字符串数组
    cin >> n;//第一行输入整数n,表示字符的个数，n小于100
    cin >> arr;
    int count = 0;//计数
    //cout << arr << endl;//检查输入
    for(i = 0;i < n;i++){
        if(arr[i] == arr [n - 1 - i]){//前后同时比较
            count++;//计数，判断是否扫描完，若中途停止则不对称
        }
        else{
            printf("NO");//出现不等情况，不对称
            break;//跳出for循环
        }
    }
    if(count == n)//说明扫描完了，没有不对称情况
        printf("YES");
    return 0;
}

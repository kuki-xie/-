//
//  main.cpp
//  296中心对称的字符串
//
//  Created by 谢容海 on 2020/11/20.
//

#include <iostream>
using namespace std
int main(int argc, const char * argv[]) {
    int n;//表示字符的个数
    int i;
    cin >> n;//第一行输入整数n,表示字符的个数，n小于100
    char arr[100];//输入的字符串数组
    for(i = 0;i < n;i++){
        cin >> arr[i];
    }
    for(i=0;i<n;i++){
        cout << arr[i] << endl;
    }
    return 0;
}

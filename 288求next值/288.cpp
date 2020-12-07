//
//  main.cpp
//  288求next值
//
//  Created by 谢容海 on 2020/12/7.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int next[100];
    int n;// n表示串的长度
    cin >> n;
    int i = 0;
    char str[100];//str存储输入的串
    for (i = 0; i < n; i++) {
        cin >> str[i];
    }
    /*for (i = 0; i < n; i++) {//检查输入是否正确
        cout << str[i] << ' ';
    }*/
    next[0] = -1;
    i = 0;
    int j = -1;//代表next值
    while (i < n) {
        if (j == -1 || str[i] == str[j]) {//如果
            ++i;
            ++j;
            next[i] = j;
        }
        else j = next[j];// i不变，j后退
    }
    for (i = 0; i < n; i++) {
        cout << next[i] << ' ';
    }
    //std::cout << "Hello, World!\n";
    return 0;
}

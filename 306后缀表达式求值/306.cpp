//
//  main.cpp
//  306后缀表达式求值
//
//  Created by 谢容海 on 2020/12/7.
//

#include <iostream>
#include <stack>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    char str[100];
    char* arr = str;// 逆波兰式
    cin >> arr;
    // cout << arr << endl;
    stack<int> a;// 栈
    int left;// 左操作数
    int right;// 右操作数
    int temp;// 保存运算的结果
    while(*arr != '\0'){
        if(isdigit(*arr)){// isdigit函数，检查是否为十进制字符,
            int c = *arr - 48;// 减去0的ASCII码,得到对应的int值
            a.push(c);// 如果是数字则入栈
        }
        else{// 是运算符
            right = a.top();// 获取栈顶元素，右操作数
            a.pop();// 出栈
            left = a.top();// 获取栈顶元素，左操作数
            a.pop();// 出栈
            if(*arr == '+'){// 如果运算符是+就执行加法
                temp = left + right;
            }
            if (*arr == '-') {// 如果运算符是-就执行减法
                temp = left - right;
            }
            if (*arr == '*') {// 如果运算符是*就执行乘法
                temp = left * right;
            }
            if (*arr == '/') {//如果运算符是/就执行除法
                temp = left / right;
            }
            a.push(temp);// 把结果压入栈
        }
        arr++;// 字符串向后遍历
    }
    int num = a.top();// 获取结果
    cout << num << endl;
    //std::cout << "Hello, World!\n";
    return 0;
}

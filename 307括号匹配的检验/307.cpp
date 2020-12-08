//
//  main.cpp
//  307括号匹配的检验
//
//  Created by 谢容海 on 2020/12/8.
//

#include <iostream>
#include <stack>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    stack<char> sc;// 定义一个栈的对象
    char str[50];// 创建一个字符数组
    char* arr = str;// 为指针分配内存
    gets(arr);// 输入表达式
    while(*arr != '\0'){
        if (*arr == '(' || *arr == '[' || *arr == '{') {//把括号的左部分入栈
            sc.push(*arr);
        }
        else if (*arr == ')'){// 遇到')'
            if (sc.top() == '(') {// 看栈顶元素是不是它的左半部分
                sc.pop();// 是，则弹出
            }
            else{//不是，则不匹配
                cout << "wrong" << endl;
                break;
            }
        }
        else if (*arr == ']') {// 遇到']'
            if (sc.top() == '[') {// 看栈顶元素是不是它的左半部分
                sc.pop();// 是，则弹出
            }
            else{
                cout << "wrong" << endl;
                break;
            }
        }
        else if (*arr == '}') {// 遇到'}'
            if (sc.top() == '{') {// 看栈顶元素是不是它的左半部分
                sc.pop();// 是，则弹出
            }
            else{
                cout << "wrong" << endl;
                break;
            }
        }
        arr++;
    }
    if (sc.size() == 0) {
        cout << "right" << endl;
    }
    //std::cout << "Hello, World!\n";
    return 0;
}

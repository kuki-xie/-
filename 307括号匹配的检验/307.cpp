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
    char str[51];
    char ch;// 创建一个字符数组
    int i = 0;
    while(1){
        scanf("%c",&ch);
        if (ch == '\n') {
            break;
        }
        str[i++] = ch;
    }
    str[i++] = '\0';
    char* arr = str;// 为指针分配内存
    stack<char> sc;// 定义一个栈的对象
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
    else{
        cout << "wrong" << endl;
    }
    //std::cout << "Hello, World!\n";
    return 0;
}

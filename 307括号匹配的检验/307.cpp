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
    char str[201];// 定义一个字符数组
    char ch;// 创建一个字符数组
    int i = 0;
    while(1){
        scanf("%c",&ch);// 输入字符
        if (ch == '\n') {// 当读到回车键时
            break;// 停止跳出循环
        }
        str[i++] = ch;// 将读入的字符存储到str
    }
    str[i++] = '\0';// 添加结束标志
    char* arr = str;// 为指针分配内存
    //cout << arr; // 检查是否读人成功

    stack<char> sc;// 定义一个栈的对象
    bool flag = true;// 标志，用来判断是否匹配
    while(*arr != '\0'){
        if (*arr == '(' || *arr == '[' || *arr == '{') {//把括号的左部分入栈
            sc.push(*arr);// 是括号的左部分则压栈
        }
        else if (*arr == ')'){// 遇到')'
            // 貌似是其他的错
            /**
             sc.top()会在sc为空时报错，分开判断
             */
            if (sc.empty()) {// 看栈顶元素不是它的左半部分或此栈此刻不含元素
                flag = false;// 更改标志为错误
                break;// 跳出循环
            }
            else if(sc.top() != '('){//是，则弹栈
                flag = false;// 更改标志为错误
                break;// 跳出循环
            }
            else
                sc.pop();
        }
        else if (*arr == ']') {// 遇到']'
            // .empty(): true if the underlying container is empty, false otherwise
            if (sc.empty()) {// 看栈顶元素不是它的左半部分或此栈此刻否含元素
                flag = false;// 更改标志为错误
                break;// 跳出循环
            }
            else if(sc.top() != '['){
                flag = false;// 更改标志为错误
                break;// 跳出循环
            }
            else{
                sc.pop(); // 是，弹栈
            }
        }
        else if (*arr == '}') {// 遇到'}'
            if (sc.empty()) {// 看栈顶元素不是它的左半部分或此栈此刻不含元素
                flag = false;// 更改标志为错误
                break;
            }
            else if(sc.top() != '{'){
                flag = false;// 更改标志为错误
                break;
            }
            else{
                sc.pop();
            }
        }
        arr++;
    }
    if (sc.size() != 0 || flag == false) {// 如果此时栈有元素则wrong
        cout << "wrong" << endl;
    }
    else{
        cout << "right" << endl;
    }
    return 0;
}

//
//  main.cpp
//  308前缀表达式求值
//
//  Created by 谢容海 on 2020/12/9.
//

#include <iostream>
#include <stack>
using namespace std;

stack<int> s;//定义一个栈s，int类型
char a[305];// 连着空格一起读入，表达式的长度不能超过100
int len = 1;// 初始化长度

void init(){// 输入操作
    cin.getline(a,sizeof(a),'\n');// 输入表达式,读到回车符停止
}
bool isNumber(char t){// 判断是否为数字
    return t >= '0' && t <= '9';
}
int dealNumber(){// 对字符型数字处理，转换成int型
    int temp = 1, ans = 0;// 初始化输出结果和代表位数的temp,
    while (len >= 0 && a[len] != ' ') {// 当未读到空格时对于像36的数字进行转换
        ans += (a[len] - '0') *temp;// 判断数字有几位
        temp *=10;
        len--;
    }
    return ans;
}
int main(){
    init();// 进行输入
    len = strlen(a); // len为表达式的长度
    for (len = len - 1; len >= 0; len--) {
        if (a[len] == ' ') {// 如果读到了空格，忽略
            continue;
        }
        if (isNumber(a[len])) {// 如果读到了数字，开始操作
            int ans = dealNumber();// 将字符转换为int型，压入栈中
            s.push(ans);// 将操作数压入栈中
        }
        else{//读到了数字操作符号
            int right = s.top();// 定义右操作数
            s.pop();// 弹栈
            int left = s.top();// 定义左操作数
            s.pop();// 弹栈
            switch (a[len]) {// 判断数字操作符号
                case '+':
                    s.push(left + right);// 如果是加
                    break;
                case '-':
                    s.push(right - left);// 如果是减
                    break;
                case '*':
                    s.push(left * right);// 如果是乘
                    break;
                case '/':
                    s.push(right / left);// 如果是除
                    break;
                default:
                    break;
            }
        }
    }
    cout << s.top();// 输出栈顶数
    return 0;
}

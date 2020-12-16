//
//  main.cpp
//  333找位置
//
//  Created by 谢容海 on 2020/12/16.
//

#include <iostream>
using namespace std;
void Find(char *str){
    int i,j,k;
    int flag,count,past,loc[100];
    int len = strlen(str);// 获得字符串的长度
    for (i = 0; i < len; i++) {
        flag = 0;// 判断是否有重复的字符
        count = 0;// 记录重复字符数量
        past = 0;// 以前是否出现过相同的字符
        for (k = 0; k < i - 1; k++) {// 若之前有相同的元素出现，置past标记为1
            if (str[k] == str[i]) {// 若之前有相同的元素出现，
                past = 1;// 置past标记为1
            }
        }
        for (j = i + 1; j < len; j++) {// 从当前的字符后一个开始找，若有相同的且前面没有重复的，记录其下标
            if ((str[i] == str[j]) && past == 0) {// 如果有相同的，且在之前未出现过
                flag = 1;// 置标记
                loc[count++] = j;// 记录其下标
            }
        }

        if (flag) {// 如果有重复的字符
            printf("%c:%d,",str[i],i);// i从0开始，输出第一个数字
            for (j = 0; j < count - 1; j++) {// 输出count - 1个需要逗号的
                printf("%c:%d,",str[loc[j]],loc[j]);
            }
            printf("%c:%d",str[loc[j]],loc[j]);// 输出最后一个没有逗号的
            printf("\n");
        }
    }
}
int main(){
    char str[100] = "\0";// 数组初始化
    scanf("%s",str);
    Find(str);
    return 0;
}
    

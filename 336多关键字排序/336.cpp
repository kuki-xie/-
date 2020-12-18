//
//  main.cpp
//  336多关键字排序
//
//  Created by 谢容海 on 2020/12/18.
//

#include <iostream>
#include <algorithm>
using namespace std;
struct stu{
    char name[20];
    int age,score;
}stu[100];// 整数小于等于100
bool compare(struct stu stu1,struct stu stu2){
    if (stu1.score != stu2.score) {
        return stu1.score > stu2.score;
    }
    else{
        if (strcmp(stu1.name,stu2.name) != 0) {
            return strcmp(stu1.name, stu2.name) < 0;
        }
        else
            return stu1.age < stu2.age;
    }
}
int main(){
    int n,i = 0;
    cin >> n;// n个学生的数据
    for (i = 0; i < n; i++) {
        cin >> stu[i].name >> stu[i].age >> stu[i].score;
    }
    sort(stu, stu + n, compare);
    for (i = 0; i < n; i++) {
        cout << stu[i].name << ' ' << stu[i].age << ' ' << stu[i].score << endl;
    }
    return 0;
}

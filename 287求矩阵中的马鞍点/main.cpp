//
//  main.cpp
//  287求矩阵中的马鞍点
//
//  Created by 谢容海 on 2020/11/23.
//

#include <iostream>
using namespace std;
typedef struct node{
    int row;//定义行
    int cow;//定义列
    int data;//定义元素所含值
}node;
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m;//为矩阵维数
    int arr[5][5];//储存输入的矩阵中的元素值
    //输入
    cin >> n >> m;//输入矩阵的维数，m为行数，n为列数
    int i,j;
    for(i = 0;i < m; i++){//通过二维数组输入并存储二维矩阵的元素值
        for (j = 0; j < n; j++) {
            cin >> arr[i][j];//i代表行，j代表列
        }
    }
    /*for(i = 0;i < m; i++){//检查输入是否正确
     for (j = 0; j < n; j++) {
     cout << arr[i][j] << ' ';
     }
     }*/
    //遍历寻找马鞍点
    int count = 0;//计数器，数有几个马鞍点
    node ans[50];//用来存储所找到马鞍点的信息
    int a = 0;//a代表最小值所在列
    int b = 0;//b代表最大值所在行
    int k = 0;
    for (i = 0; i < m; i++) {
        int min = arr[i][0];//初始定义第i行中的最小值
        for (j = 0; j < n; j++) {//寻找i行中的最小值
            if(min > arr[i][j]){//如果第i行有比初始定义的min更小的，就用这个去替换
                min = arr[i][j];
                a = j;//a代表当前行中最小的列数
            }
        }
        
        int max= arr[0][a];//初始定义其为上面所找的最小值所在列的第a列中的最大值
        for(k = 0; k < m; k++){//寻找第j列中的最大值
            if(max < arr[k][a]){//如果第j列有比初始定义的max更大的，则将其赋值为最大值
                max = arr[k][a];
                b = k;//b为此列的最大值所在行数
            }
        }
        if (max == min) {
            ans[count].row = a;//存储所找的行数
            ans[count].cow = b;//存储所找的列数
            ans[count].data = max;//存储所找的值
            count++;
        }
    }
    //处理输出
    if (count == 0) {
        cout << "NO" << endl;//没有马鞍点输出NO
    }
    else{
        for (i = 0; i < count; i++) {
            cout << ans[i].row + 1<< ' ' << ans[i].cow + 1<< ans[i].data << endl;
        }
    }
    //std::cout << "Hello, World!\n";
    return 0;
}

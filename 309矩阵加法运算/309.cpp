//
//  main.cpp
//  309矩阵加法运算
//
//  Created by 谢容海 on 2020/12/9.
//

#include <iostream>
using namespace std;
int main(int argc, const char *argv[])
{
    // 行row 列column
    int rownum, colnum;      // 矩阵维数，分别代表行数和列数
    cin >> rownum >> colnum; // 输入矩阵维数
    //cout << rownum << ' ' << colnum << ' ' << endl; 检查输出
    int b1[10][10]; //用来存储0-1矩阵
    int v1[100];    // 用来存储矩阵的非零元
    int b2[10][10]; // 用来存储第二个矩阵的0-1
    int v2[100];
    int b3[10][10]; // 用来存储结果的0-1 矩阵
    int v3[100];// 用来存储结果的非零元
    int i, j = 0;
    int count_v1 = 0;
    int count_v2 = 0; // 记录先输入矩阵中的非零元个数
    for (i = 0; i < rownum; i++)
    { // 输入B1矩阵的值
        for (j = 0; j < colnum; j++)
        {
            cin >> b1[i][j];
            if (b1[i][j] == 1)
            {
                count_v1++;
            }
        }
    }
    for (i = 0; i < count_v1; i++)
    {
        cin >> v1[i];
    }
    /*for (i = 0; i < rownum; i++) {// 检查B1矩阵的输入
     for (j = 0; j < colnum; j++) {
     cout << b1[i][j] << ' ';
     }
     }*/
    /*for (i = 0; i < count_v1; i++) {// 检查一维数组的输入
     cout << v1[i] << ' ';
     }*/
    for (i = 0; i < rownum; i++)
    { // 输入B2 0-1矩阵的值
        for (j = 0; j < colnum; j++)
        {
            cin >> b2[i][j];
            if (b2[i][j] == 1)
            {
                count_v2++;
            }
        }
    }
    for (i = 0; i < count_v2; i++)
    { // 输入B2的值
        cin >> v2[i];
    }
    /*for (i = 0; i < count_v2; i++) {// 检查一维数组的输入
        cout << v2[i] << ' ';
    }*/
    count_v1 = count_v2 = 0;
    int count_v3 = 0; // 记录相加结果的一维数组的长度
    for (i = 0; i < rownum; i++)
    { // 进行加法
        for (j = 0; j < colnum; j++)
        {
            if (b1[i][j] == 0 && b2[i][j] == 0)
            {                 // 1.当两处都为0时
                b3[i][j] = 0; // 结果此处为0
            }
            else if (b1[i][j] == 0 && b2[i][j] == 1)
            {                                    // 当b1矩阵此处为0，b2矩阵为1时
                b3[i][j] = 1;                    // b3矩阵此处为非零元，1
                v3[count_v3++] = v2[count_v2++]; // 将v2矩阵的值赋值给v3
            }
            else if (b1[i][j] == 1 && b2[i][j] == 0)
            {                                    // 当b2矩阵此处为1，b1矩阵为0时
                b3[i][j] = 1;                    // b3矩阵此处为非零元 1
                v3[count_v3++] = v1[count_v1++]; // 将v1矩阵的值赋值给v1
            }
            else if (b1[i][j] == 1 && b2[i][j] == 1)
            { // 当b1 b2矩阵此处都不为0时
                if(v1[count_v1] + v2[count_v2] == 0)
                {
                    //如果此时两值相加 = 0
                    b3[i][j] = 0; // 此处b3矩阵赋值0；
                    count_v1++;
                    count_v2++;
                }
                else
                {
                    b3[i][j] = 1; // 此处b3赋值1
                    v3[count_v3++] = v1[count_v1++] + v2[count_v2++];
                }
            }
        }
    }
    for (i = 0; i < rownum; i++)
    { // 输入B2 0-1矩阵的值
        for (j = 0; j < colnum; j++)
        {
            cout << b3[i][j] << ' ';
        }
        printf("\n");
    }
    for (i = 0; i < count_v3; i++) {// 检查一维数组的输入
        cout << v3[i] << ' ';
    }
    return 0;
}


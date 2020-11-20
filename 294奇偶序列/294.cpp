//
//  main.cpp
//  294奇偶序列
//
//  Created by 谢容海 on 2020/11/19.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n=0;//表示序列长度
    int i;
    cin >> n;//输入n,表示序列长度
    int fin[101];//调整后的数组
    int arr[101];//原数组
    int start = 0;//从左往右扫用
    int end = n - 1;//从右往左扫用
    for(i = 0;i < n;i++){
        cin >> arr[i];//输入序列中的元素
    }
    /*for(i = 0;i < n;i++){//检查输入
        cout << arr[i] << ' ';
    }*/
    for(i = 0;i <= n;i++){
        if((i + 1) % 2 != 0){//从左向右扫，若扫到奇数位置，
            fin[start++]=arr[i];//则从左向右存储
        }
    }
    for(i = n - 1;i >= 0; i--){
        if((i + 1) % 2 == 0){
            fin[end--]=arr[i];
        }
    }
    for(i = 0;i < n;i++){
        cout<<fin[i]<<' ';
    }
    return 0;
}

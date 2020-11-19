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
    //int final[n];//调整后的数组
    //int count=0;
    cin >> n;//输入n,表示序列长度
    int arr[n];//原数组
    for(i = 0;i < n;i++){
        cin >> arr[i];//输入序列中的元素
    }
    for(i = 0;i < n;i++){
        cout << arr[i] << ' ';
    }
    /*for(i = 0;i < n;i++){
        if(arr[i] % 2 != 0){//为奇数
            final[count++]=arr[i];
        }
    }
    for(i = 0;i < n;i++){
        if(arr[i] % 2 == 0){//为偶数
            final[count++]=arr[i];
        }
    }
    for(i = 0;i < count;i++){
        cout<<final[i]<<' '<<endl;
    }*/
    return 0;
}

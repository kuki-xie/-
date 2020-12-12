//
//  main.cpp
//  315二叉树扩展先序遍历
//
//  Created by 谢容海 on 2020/12/10.
//

#include <iostream>
using namespace std;
typedef struct TreeNode{// 定义树的结构体
    char val;// 结点的值
    struct TreeNode* pleft;// 定义左子树
    struct TreeNode* pright;// 定义右子树
}TreeNode;
TreeNode* CreateTree(char* arr,int *pi){// 创建树
    if (arr[*pi] == '#') {// 表示空格，空格表示空树
        return NULL;
    }
    else{
        TreeNode* root = (TreeNode *)malloc(sizeof(TreeNode));// 分配内存
        // 先序遍历
        root -> val = arr[*pi];// 将值赋给结点
        ++(*pi);// 继续读
        root -> pleft = CreateTree(arr, pi);// 将值赋值给左子树
        ++(*pi);// 继续读
        root -> pright = CreateTree(arr, pi);// 将值赋值给右子树
        return root; // 返回结点
    }
}
void InorderTraversal(TreeNode* root){// 中序遍历
    if (root == NULL) {// 如果为空树
        return;
    }
    InorderTraversal(root -> pleft);// 中序遍历左子树
    printf("%c ", root->val);// 输出
    //cout << root -> val << ' ';
    InorderTraversal(root -> pright);// 中序遍历右子树
}
int main(int argc, const char * argv[]) {
    char str[101];// 定义一个字符串
    cin >> str;// 输入字符串回车停止
    int i = 0;
    TreeNode *root = CreateTree(str, &i);
    InorderTraversal(root);
    //cout << str;// 检查输入
    return 0;
}

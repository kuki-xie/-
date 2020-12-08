#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX  8   //最大顶点数
 
typedef struct node{ //边节点
        int adjvex;  //该边指向的顶点位置
        //int weight
        struct node* next;  //指向下一条边的指针
}ArcNode;//边表结点
 
typedef struct VNode{
        int vertex;
        ArcNode* firstarc; //指向第一条依附该顶点的指针
}VNode;//顶点表结点
 
typedef VNode Adjlist[MAX+1];//adj_list是邻接表类型
 
typedef struct {
        int n, m;//图中顶点数和边数
        Adjlist adjlist;//邻接表
}ALGraph;
 
void create_algraph(ALGraph* g)//建立无向图的邻接表
{
    ArcNode* newnode;
    int i, j, k;
    printf("please input node number and edge number: ");
    scanf("%d%d", &g->n, &g->m);
    printf("node number = %d, edges = %d\n", g->n, g->m);
    for(i = 1; i <= g->n; i++){
        g->adjlist[i].vertex = i;
        g->adjlist[i].firstarc = NULL;
    }
    printf("please input new edge: \n");//用相邻的两个顶点来表示边
    for(k = 1; k <= g->m; k++){
        scanf("%d %d", &i, &j);
        //printf("\n");
        newnode = (ArcNode* )malloc(sizeof(ArcNode));
        newnode->adjvex = j;
        //newnode->weight = 0;
        newnode->next = g->adjlist[i].firstarc;
        g->adjlist[i].firstarc = newnode;
        newnode = (ArcNode* )malloc(sizeof(ArcNode));
        newnode->adjvex = i;
        //newnode->weight = 0;
        newnode->next = g->adjlist[j].firstarc;
        g->adjlist[j].firstarc = newnode;
    }
}
 
void pr_algraph(ALGraph* g)//输出邻接表
{
    ArcNode* node;
    int i;
    for(i = 1; i<= g->n; i++){
        node = g->adjlist[i].firstarc;
        printf("g->adjlist[%d] = %d: ", i, g->adjlist[i].vertex);
        while(node != NULL){
                printf("%d \t", node->adjvex);
                node = node->next;
        }
        printf("\n");
    }
}
 
int visted[MAX+1];//记录节点状态
void DFS(ALGraph *g,int v)
{
    visted[v] = 1;            //访问初始点
    ArcNode *p = g->adjlist[v].firstarc;
    while(p!=NULL)
    {
        if (visted[p->adjvex]==0){    //如果没有被访问过，则递归调用DFS访问
            printf("%d ",p->adjvex);
            DFS(g,p->adjvex);
        }
        p = p->next;//继续下一条边
    }
    //printf("\n");
}
 
void BFS(ALGraph *g,int v)
{
    //for (int i=0;i<g->n;i++) visted[i] = 0;
    int queue[MAX],front,rear;
    front = rear = 0;
    rear = (rear+1)%MAX;
    queue[rear] = v; //v顶点入队
    int u;
    ArcNode *p;
    while(/*rear!=0*/front!=rear)//当队列满时
    {
        front = (front+1)%MAX;
        u = queue[front];
        p = g->adjlist[u].firstarc;
        while(p!=NULL)    //首先访问u的所有节点
        {
            if (visted[p->adjvex]==0)
            {
                visted[p->adjvex] = 1;    //访问p->adjvex节点，标记为访问
                rear = (rear+1)%MAX;
                printf("%d ",p->adjvex);
                queue[rear] = p->adjvex;    //p->adjvex节点入队
            }
            p = p->next;
        }
    }
    printf("\n");
}
 
int main(int argc, char** argv)
{
    ALGraph* g;//定义一个无向图
 
    g = (ALGraph* )malloc(sizeof(ALGraph));
    printf("begin create algraph\n");
    create_algraph(g);
    printf("finish create algraph\n");
 
    printf("the algraph is:\n");
    pr_algraph(g);
    memset(visted,0,sizeof(visted));
    visted[1]=1;
    printf("BFS is:\n");
    printf("1 ");
    BFS(g,1);
    memset(visted,0,sizeof(visted));
    printf("DFS is:\n");
    printf("1 ");
    DFS(g,1);
    printf("\n");
    return 0;
}

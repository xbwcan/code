#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
int edge[21][21];//邻接矩阵
int dis[20];//各个点到MST的距离
int vis[20]={0};//标记每个点是否被访问过
int pre[20] = {0};//保存每个节点是由谁拉入队列
struct node
{
       int d,u;
       bool operator < (const node& rhs) const
       {
            return d>rhs.d;
       }
};
priority_queue<node> q;//保存相邻的节点
int main()
{
    for (int i = 0; i < 10; i++)
    {
        dis[i] = 0x7ffff;
        for (int j = 0; j < 10;j++)
        {
            edge[i][j] = 0x7ffff;
        }
    }
    int u, v;
    int n=10, m=19;//n为顶点数，m为边数
    for (int i = 1; i <= m;i++)
    {
        scanf("%d%d", &u, &v);
        scanf("%d", &edge[u][v]);
        edge[v][u] = edge[u][v];
    }
    dis[0] = 0;
    cout << endl;
    q.push((node){0,0});
    while(!q.empty())
    {
        node x= q.top();
        q.pop();
        u=x.u;
        if(vis[u])continue;
        vis[u]=true;
        for(int i=0;i<n;i++)
        {
            if(u==0&&i==1)
            {
                cout << endl
                     << endl
                     << dis[i] << "     " << edge[0][1] << "      " << endl
                     << endl;
            }
            if(dis[i]>edge[u][i])
            {
                dis[i]=edge[u][i];
                pre[i] = u;
                cout << u << " " << i << endl;
                q.push((node){dis[i],i});
            }
        }
    }
    for (int i = 1; i <10;i++)
    {
        cout << i << "  " << pre[i] << endl;
    }
}
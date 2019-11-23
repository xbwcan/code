#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int u[200], v[200], w[200];//u 数组保存起始点 v数组保存终点 w数组保存边权
int p[200],r[200];//p 保存并查集中的父亲 r用于对边进行间接排序
int ans[200];//记录最小生成树是那条边
int cmp(const int i, const int j)//间接排序函数
{
    return w[i] < w[j];
}
int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}
int main()
{
    for (int i = 0; i < 19;i++)
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
    for (int i = 0; i < 10;i++)
        p[i] = i;
    for (int i = 0; i < 19;i++)
        r[i] = i;
    sort(r, r + 19, cmp);
    for (int i = 0; i < 19;i++)
    {
        int e = r[i];
        int x = find(u[e]), y = find(v[e]);
        if(x!=y)
        {
            ans[e] = 1;
            p[x] = y;
        }
    }
    for (int i = 0; i < 19;i++)
    {
        if(ans[i])
            cout << i << " ";
    }
    return 0;
} 
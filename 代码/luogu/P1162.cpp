#include<bits/stdc++.h>
using namespace std;
int n,arr[35][35],flag=1;
queue <int> s;
int main()
{
    int u,v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==1&&flag)
            {
                u=i+1;v=j+1;
                flag=0;
            }
        }
    }
    s.push(u);
    s.push(v);
 	while(!s.empty())
 	{
 		u=s.front();
        s.pop();
        v=s.front();
        s.pop();
        arr[u][v]=2;
 		if(u>1&&arr[u-1][v]==0){s.push(pair(u-1,v))}
 		if(u<n&&arr[u+1][v]==0){s.push(u+1);s.push(v);}
 		if(v>1&&arr[u][v-1]==0){s.push(u);s.push(v-1);}
 		if(v<n&&arr[u][v+1]==0){s.push(u);s.push(v+1);}
 	}
 	for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d",arr[i][j]);
            if(j!=n)printf(" ");
        }
        if(i!=n)printf("\n");
    }
    return 0;
}
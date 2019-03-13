#include<bits/stdc++.h>
using namespace std;
int vis[6]={0,1,5,10,25,50};
int f[251]={0};
int main()
{
	f[1]=1;f[5]=1;f[10]=1;f[25]=1;f[50]=1;
	for(int i=1;i<=250;i++)
	{
		for(int j=1;j<=5;j++)
		{
			if(i>vis[j])
			{
				f[i]+=f[i-vis[j]];
			}
		}
		cout<<f[i]<<endl;
	}
	int x;
	while(~scanf("%d",&x))
	{
		printf("%d\n",f[x]);
	}
	return 0;
}
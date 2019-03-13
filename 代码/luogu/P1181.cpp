#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,x,sum=0;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x>=m)cnt++;
		else 
		{
			if(sum+x<m)sum+=x;
			else if(sum+x==m)
			{
				cnt++;
				sum=0;
			}
			else 
			{
				cnt++;
				sum=x;
			}
		}
	}
	if(sum)cnt++;
	cout<<cnt;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,sum=0,num[101];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		sum+=num[i];
	}
	sum/=n;
	for(int i=1;i<=n;i++)
		num[i]-=sum;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(num[i-1]!=0)
		{
			cnt++;
			num[i]+=num[i-1];
		}
	}
	cout<<cnt;
	return 0;
}
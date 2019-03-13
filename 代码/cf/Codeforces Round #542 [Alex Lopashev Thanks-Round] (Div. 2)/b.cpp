#include<bits/stdc++.h>
using namespace std;
int num[200001],cur[100001][2];
int fan(int a)
{
	if(a<0)a=-a;
	return a;
}
int main()
{
	int n,len,cnt1,cnt2,x=1,y=1;
	long long sum=0;
	scanf("%d",&n);
	len = 2*n;
	for(int i=1;i<=len;i++)
	{
		scanf("%d",&num[i]);
		if(cur[num[i]][0])cur[num[i]][1]=i;
		else cur[num[i]][0]=i;
	}
	for(int i=1;i<=n;i++)
	{
		cnt1=fan(cur[i][0]-x)+fan(cur[i][1]-y);
		cnt2=fan(cur[i][0]-y)+fan(cur[i][1]-x);
		if(cnt1>cnt2)
		{
			sum+=cnt2;
			y=cur[i][0];
			x=cur[i][1];
		}
		else 
		{
			sum+=cnt1;
			x=cur[i][0];
			y=cur[i][1];
		}
		//cout<<x<<" "<<y<<" "<<sum<<endl;
	}
	cout<<sum;
	return 0;
}
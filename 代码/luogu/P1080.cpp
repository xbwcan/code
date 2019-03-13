#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}arr[10001];
bool cmp(node a,node b)
{
	return a.y*(a.x+1)<b.y*(b.x-1);
}
int gcd(int a,int b)
{
	return a%b==0?0:gcd(b,a%b);
}
int main()
{
	int n,a,b,cnt=0;
	scanf("%d",&n);
	scanf("%d%d",&a,&b);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&arr[i].x,&arr[i].y);
	}
	sort(arr+1,arr+1+n,cmp);
	int pre=a,tmp;
	for(int i=1;i<=n;i++)
	{
		pre=a;
		for(int j=1;j<i;j++)
		{
			pre*=arr[j].x;
			if(arr[i].y!=1)
			{
				tmp=gcd(pre,arr[i].y);
				pre/=tmp;
				arr[i].y/=tmp;
			}
			pre/=arr[i].y;
			cnt+=pre;
		}
	}
	cout<<cnt;
	return 0;
}
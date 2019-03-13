#include<bits/stdc++.h>
using namespace std;
int n,num[101];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	if(n==1)
	{
		cout<<"YES";
		return 0;
	}
	int flag;
	if(num[2]>num[1])flag=1;
	else if(num[2]==num[1])flag=2;
	else flag=3;
	for(int i=3;i<=n;i++)
	{
		if(flag==1)
		{
			if(num[i]<num[i-1])
			{
				flag=3;
			}
			else if(num[i]==num[i-1])
				flag=2;
		}
		else if(flag==2)
		{
			if(num[i]>num[i-1])
			{
				cout<<"NO";
				return 0;
			}
			else if(num[i]<num[i-1])
				flag=3;
		}
		else 
		{
			if(!(num[i]<num[i-1]))
			{
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES";
	return 0;
}
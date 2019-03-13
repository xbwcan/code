#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> > q; 
int main()
{
	int n,x,u,v;
	long long sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		q.push(x);
	}
	while(q.size()!=1)
	{
		u=q.top();q.pop();
		v=q.top();q.pop();
		sum+=u+v;
		q.push(u+v);
	}
	cout<<sum;
	return 0;
} 
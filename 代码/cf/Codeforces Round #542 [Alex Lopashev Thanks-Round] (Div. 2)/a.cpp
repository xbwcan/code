#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,num[101];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(num[i]>0)cnt++;
	}
	int mid;
	if(n%2)mid=(n+1)/2;
	else mid=n/2;
	if(cnt>=mid)printf("1");
	else printf("0");
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,arr[1001];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	sort(arr+1,arr+1+n);
	int end=unique(arr+1,arr+1+n)-arr-1;
	printf("%d\n",end);
	for(int i=1;i<=end;i++)
		printf("%d ",arr[i]);
	return 0;
}
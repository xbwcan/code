#include<bits/stdc++.h>
using namespace std;
struct peo{
	int num,key;
}arr[5001];
bool cmp(peo x,peo y)
{
	if(x.key!=y.key)
		return x.key>y.key;
	else 
		return x.num<y.num;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&arr[i].num,&arr[i].key);
	m=(int)((float)m*1.5);
	sort(arr+1,arr+1+n,cmp);
	int cur;
	cur=arr[m].key;
	while(arr[m+1].key==cur)m++;
	printf("%d %d\n",cur,m);
	for(int i=1;i<=m;i++)
	{
		printf("%d %d",arr[i].num,arr[i].key);
		if(i!=m)printf("\n");
	}
	return 0;
}
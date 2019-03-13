#include<cstdio>
long long  f[55];
int main()
{
	f[1]=1;
	for(int i=2;i<=54;i++)
		f[i]=f[i-1]+f[i-2];
	int x;
	scanf("%d",&x);
	while(x!=-1)
	{
		printf("%lld\n",f[x]);
		scanf("%d",&x);
	}
	return 0;
}
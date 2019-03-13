#include<bits/stdc++.h>
using namespace std;
long long f[21][21][21];
long long slove(long long a,long long b,long long c);
int main()
{
	long long a,b,c;
	memset(f,0,sizeof(f));
	while(~scanf("%lld%lld%lld",&a,&b,&c))
	{
		if(a==-1&&b==-1&&c==-1)break;
		printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,slove(a,b,c));
	}
	return 0;
}
long long slove(long long a,long long b,long long c)
{
	if(a<=0||b<=0||c<=0)return (long long )1;
	else if(a>20||b>20||c>20)return slove(20,20,20);
	else if(f[a][b][c])return f[a][b][c];
	else if(a<b&&b<c)
	{
		f[a][b][c]=slove(a,b,c-1)+slove(a,b-1,c-1)-slove(a,b-1,c);
		return f[a][b][c];
	}
	else 
	{
		f[a][b][c]=slove(a-1,b,c)+slove(a-1,b-1,c)+slove(a-1,b,c-1)-slove(a-1,b-1,c-1);
		return f[a][b][c];
	}
}
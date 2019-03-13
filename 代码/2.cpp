#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int cnt=1;
	while(n>=cnt)
	{
		n-=cnt;
		if(n!=0)cnt++;
	}
	if(n==0)
	{
		if(cnt%2)printf("1/%d",cnt);
		else printf("%d/1",cnt);
	}
	else 
	{
		n--;
		if(cnt%2==0)printf("%d/%d",1+n,cnt-n);
		else printf("%d/%d",cnt-n,1+n);
	}
	return 0;
}
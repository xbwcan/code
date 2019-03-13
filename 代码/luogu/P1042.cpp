#include<bits/stdc++.h>
using namespace std;
char c;
string s;
int w,l,cnt;
int main()
{
	while(~scanf("%c",&c))
	{
		if(c=='E')break;
		if(c=='\n')continue;
		else s+=c;
	}
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]=='W')w++;
		else if(s[i]=='L')l++;
		cnt++;
		if((w>=11||l>=11)&&(w>=l+2||l>=w+2))
		{
			cout<<w<<":"<<l<<endl;
			w=l=cnt=0;
		}
	}
	cout<<w<<":"<<l<<endl<<endl;
	w=l=cnt=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='W')w++;
		else if(s[i]=='L')l++;
		cnt++;
		if((w>=21||l>=21)&&(w>=l+2||l>=w+2))
		{
			cout<<w<<":"<<l<<endl;
			w=l=cnt=0;
		}
	}
	cout<<w<<":"<<l;
	return 0;
}
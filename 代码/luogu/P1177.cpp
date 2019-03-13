#include<bits/stdc++.h>
using namespace std;
int n;
int qs(int arr[],int l,int r);
int partition(int arr[],int l,int r);
int main()
{
	int arr[100001];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	qs(arr,1,n);
	for(int i=1;i<=n;i++)
		printf("%d ",arr[i]);
	return 0;
}
int qs(int arr[],int l,int r)
{
	if(r<=l)return 0;
	int j=partition(arr,l,r);
	qs(arr,l,j-1);
	qs(arr,j+1,r);
	return 0;
}
int partition(int arr[],int l,int r)
{
	int x;
	x=arr[r];
	int i=l-1;
	for(int j=l;j<r;j++)
	{
		if(arr[j]<=x)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[r]);
	return i+1;
}
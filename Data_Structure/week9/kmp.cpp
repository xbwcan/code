#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char s1[205], s2[205];
int nxt[205];
int get_nxt();
int kmp(int pos);
int main()
{
    scanf("%s", s1 + 1);
    scanf("%s", s2 + 1);
    get_nxt();
    int len2 = strlen(s2+1);
    get_nxt();
    for (int i = 1; i <= len2;i++)
    {
        printf("%d,", nxt[i]);
    }
    cout << endl;
    int ans = 0,ok = 0;
    while(ans!=-1)
    {
        ans = kmp(ans + 1);
        if(ans!=-1)
        {
            ok = 1;
            printf("%d\n", ans);
        }
    }
    if(!ok)
    {
        printf("-1\n");
    }
    return 0;
}
int get_nxt()
{
    int len = strlen(s2+1);
    //cout << len << endl;
    int j = 1, k = 0;
    nxt[1] = 0;
    while(j<=len)
    {
        if(k==0||s2[j]==s2[k])
        {
            j++;
            k++;
            nxt[j] = k;
        }
        else
            k = nxt[k];
    }
    return 0;
}
int kmp(int pos)
{
    int i = pos, j = 1;
    int len1 = strlen(s1+1), len2 = strlen(s2+1);
    while(i<=len1&&j<=len2)
    {
        if(j==0||s1[i]==s2[j])
        {
            i++;
            j++;
        }
        else
            j = nxt[j];
    }
    if(j>len2)
        return i - len2;
    else
        return -1;
}
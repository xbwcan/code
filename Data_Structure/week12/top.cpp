#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
queue<int> q;
int dis[500][500],cnt[500];
// A B C D E F G H I  S T
// 1 2 3 4 5 6 7 8 9 10 11
int main()
{
    memset(cnt, -1, sizeof(cnt));
    dis['S' - 'A' + 1]['A' - 'A' + 1] = 1;
    dis['S' - 'A' + 1]['D' - 'A' + 1] = 1;
    dis['S' - 'A' + 1]['G' - 'A' + 1] = 1;
    dis['A' - 'A' + 1]['B' - 'A' + 1] = 1;
    dis['A' - 'A' + 1]['E' - 'A' + 1] = 1;
    dis['D' - 'A' + 1]['A' - 'A' + 1] = 1;
    dis['D' - 'A' + 1]['E' - 'A' + 1] = 1;
    dis['G' - 'A' + 1]['D' - 'A' + 1] = 1;
    dis['G' - 'A' + 1]['E' - 'A' + 1] = 1;
    dis['G' - 'A' + 1]['H' - 'A' + 1] = 1;
    dis['B' - 'A' + 1]['C' - 'A' + 1] = 1;
    dis['H' - 'A' + 1]['E' - 'A' + 1] = 1;
    dis['H' - 'A' + 1]['I' - 'A' + 1] = 1;
    dis['E' - 'A' + 1]['C' - 'A' + 1] = 1;
    dis['E' - 'A' + 1]['F' - 'A' + 1] = 1;
    dis['E' - 'A' + 1]['I' - 'A' + 1] = 1;
    dis['C' - 'A' + 1]['T' - 'A' + 1] = 1;
    dis['F' - 'A' + 1]['C' - 'A' + 1] = 1;
    dis['F' - 'A' + 1]['T' - 'A' + 1] = 1;
    dis['I' - 'A' + 1]['F' - 'A' + 1] = 1;
    dis['I' - 'A' + 1]['T' - 'A' + 1] = 1;
    int u, v;
    char c1, c2;
    scanf("%c,%c", &c1, &c2);
    u = c1 - 'A' + 1;
    v = c2 - 'A' + 1;
    dis[u][v] = 0;
    for (int i = 1; i <= 26;i++)
    {
        for (int j = 1; j <= 26;j++)
        {
            if(dis[i][j])
            {
                if(cnt[j]==-1)
                    cnt[j] = 1;
                else 
                    cnt[j]++;
            }
        }
    }
    if(cnt[v]==-1)
        cnt[v] = 0;
    cnt['S' - 'A' + 1] = 0;
    q.push('S' - 'A' + 1);
    for (int i = 1; i <= 26;i++)
    {
        //printf("%d ", cnt[i]);
        if(i=='S' - 'A' + 1)
            continue;
        if(cnt[i]==0)
            q.push(i);
    }
    //cout << endl;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        printf("%c,", 'A' + u-1);
        for (int i = 1; i <= 26;i++)
        {
            if(dis[u][i])
            {
                cnt[i]--;
                if(cnt[i]==0)
                    q.push(i);
            }
        }
    }
    return 0;
}
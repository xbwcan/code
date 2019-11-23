#include<cstdio>
#include<iostream>
using namespace std;
int num[200]={0}, lft[200]={0}, rgt[200]={0};
int insert(int root,int cur);
int postorder(int root);
int inorder(int root);
int main()
{
    int len = 1;
    while(cin>>num[len++])
    {
        getchar();
    }
    len-=2;
    //cout << len << endl;
    //for (int i = 1; i <= len;i++)
        //cout << num[i] << endl;
    for (int i = 2; i <= len; i++)
    {
        insert(1, i);
    }
    postorder(1);
    cout << endl;
    inorder(1);
    return 0;
}
int insert(int root,int cur)
{
    if(num[cur]<num[root])
    {
        if(lft[root]==0)
            lft[root] = cur;
        else
            insert(lft[root], cur);
    }
    else 
    {
        if(rgt[root]==0)
            rgt[root] = cur;
        else
            insert(rgt[root], cur);
    }
    return 0;
}
int postorder(int root)
{
    if(lft[root]==0&&rgt[root]==0)
    {
        printf("%d,", num[root]);
        return 0;
    }
    else
    {
        if(lft[root])
            postorder(lft[root]);
        if(rgt[root])
            postorder(rgt[root]);
        printf("%d,", num[root]);
    }
    return 0;
}
int inorder(int root)
{
    if(lft[root]==0&&rgt[root]==0)
    {
        printf("%d,", num[root]);
        return 0;
    }
    else
    {
        if(lft[root])
            inorder(lft[root]);

        
        printf("%d,", num[root]);


        if(rgt[root])
            inorder(rgt[root]);
    }
    return 0;
}
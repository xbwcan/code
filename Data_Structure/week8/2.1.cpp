#include <cstdio>
#include <cstring>
#include <stack>
#include <iostream>
using namespace std;
char s[10],ans[10];
stack<char> s1;
stack<double> s2;
int main()
{
    scanf("%s", s);
    int len = strlen(s),cur=0;
    for (int i = 0; i < len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            ans[cur] = s[i];
            cur++;
        }
        else if(s[i]=='*'||s[i]=='/')
        {
            //2*(cout << s1.empty() << endl;
            if(s1.empty())
            {
                s1.push(s[i]);
            }
            else
            {
                while(s1.top()!='+'&&s1.top()!='-'&&s1.top()!='(')
                {
                    ans[cur] = s1.top();
                    cur++;
                    s1.pop();
                    if(s1.empty())
                        break;
                }
                s1.push(s[i]);
            }
        }
        else if(s[i]=='+'||s[i]=='-')
        {
            if(s1.empty())
                s1.push(s[i]);
            else
            {
                while(s1.top()!='(')
                {
                    ans[cur] = s1.top();
                    cur++;
                    s1.pop();
                    if(s1.empty())
                        break;
                }
                s1.push(s[i]);
            }
        }
        else if(s[i]=='(')
            s1.push(s[i]);
        else 
        {
            while(s1.top()!='(')
            {
                ans[cur] = s1.top();
                cur++;
                s1.pop();
            }
            s1.pop();
        }
    }
    while(!s1.empty())
    {
        ans[cur] = s1.top();
        cur++;
        s1.pop();
    }
    //printf("%s", ans);
    double x1 = 0.0, x2 = 0.0;
    for (int i = 0; i < cur;i++)
    {
        if(ans[i]>='0'&&ans[i]<='9')
            s2.push((double)(ans[i] - '0'));
        else 
        {
            x1 = s2.top();
            s2.pop();
            x2 = s2.top();
            s2.pop();
            if(ans[i]=='+')
                s2.push(x1 + x2);
            else if(ans[i]=='-')
                s2.push(x2 - x1);
            else if(ans[i]=='*')
                s2.push(x1 * x2);
            else
                s2.push(x2 / x1);
        }
    }
    printf("%.2lf\n", s2.top());
    for (int i = 0; i < cur;i++)
        printf("%c ", ans[i]);
    return 0;
}
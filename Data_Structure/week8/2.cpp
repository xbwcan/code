#include<cstdio>
#include<cstring>
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
char s[1000], ans[1000];
float sum = 0.0;
stack<char> st;
stack<float> sa;
int main()
{
    scanf("%s", s);
    int len = strlen(s),cur=0;
    for (int i = 0; i < len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            ans[cur++] = s[i];
        }
        else
        {
            if(st.empty())
                st.push(s[i]);
            else
            {
                if(s[i]=='*'||s[i]=='/')
                {
                    while(!(st.top()=='+'||st.top()=='-'||st.top()=='('))
                    {
                        ans[cur++] = st.top();
                        st.pop();
                        if(st.empty())
                            break;
                    }
                    st.push(s[i]);
                }
                else if(s[i]=='-'||s[i]=='+')
                {
                    while(st.top()!='(')
                    {
                        ans[cur++] = st.top();
                        st.pop();
                        if(st.empty())
                            break;
                    }
                    st.push(s[i]);
                }
                else if(s[i]=='(')
                    st.push(s[i]);
                else if(s[i]==')')
                {
                    while(!(st.top()=='('))
                    {
                        ans[cur++] = st.top();
                        st.pop();
                    }
                    st.pop();
                }
            }
        }
    }
    while(!st.empty())
    {
        ans[cur++] = st.top();
        st.pop();
    }
    float x1, x2;
    for (int i = 0; i < cur;i++)
    {
        if(ans[i]>='0'&&ans[i]<='9')
        {
            sa.push((float)(ans[i] - '0'));
        }
        else
        {
            x1 = sa.top();
            sa.pop();
            x2 = sa.top();
            sa.pop();
            if(ans[i]=='+')
                sa.push(x1 + x2);
            else if(ans[i]=='-')
                sa.push(x2 - x1);
            else if(ans[i]=='*')
                sa.push(x1 * x2);
            else
                sa.push(x2 / x1);
        }
    }
    printf("%.2f\n", sa.top());
    for (int i = 0; i < len;i++)
    {
        printf("%c ", ans[i]);
    }
    printf("\n");
    return 0;
}

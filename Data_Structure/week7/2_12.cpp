#include <cstdio>
#include <iostream>
using namespace std;


/*
    The running time is O(n)
    the input is O(n)
    the loop is O(n)
    So the running time of the programe is O(n)
*/
int main()
{
    int n;
    cin >> n;
    int *num;
    num = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i]);
        num[i] = -num[i];
    }
    int sum = num[1], maxsum = num[1];
    for (int i = 2; i <= n; i++)
    {
        if(sum + num[i] < 0)
        {
            maxsum = max(maxsum, sum);
            sum = num[i];
        }
        else
            sum += num[i];
    }
    cout <<-maxsum;
    return 0;
}
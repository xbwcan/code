#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

/*
    The running time is O(logn)
*/
int main()
{                                           
    int n ;  // the number of noun
    cin >> n;
    int *num;
    num = new int[n+1];
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i]);
    }
    int l = 1, r = n, mid;
    while(l < r)
    {
        mid = (l + r) >> 1;
        if(mid == num[mid])
        {
            cout << "Yes";
            return 0;
        }
        else if(mid < num[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << "No";
    return 0;
}
#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
long long int A[1000+5][1000+5];
int main()
{
    int N;
    string a,ans;
    int i,j;
    while(cin >> N)
    {
        if(N == 0) break;
        cin >> a;
        ans = a;
        N = a.length()/N;
        for(i = 0;i < a.length();i = i + N)
        {
            for(j = i;j < i + N;j++)
            {
                ans[j] = a[i + i + N - j - 1];
            }
        }
        cout << ans << endl;
    }
}


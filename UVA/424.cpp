#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int ans[100 + 5];
int main()
{
    int SZ,P,i,j,ll;
    double t;
    int L,M,a,b,c,d;
    int even,odd,evans;
    int trash;
    string N;
    int high,low;
    int temp;
    for(i = 0;i < 105;i++)
    {
        ans[i] = 0;
    }

    while(cin >> N)
    {
        if(N == "0") break;
        for(i = 0;i < N.length();i++)
        {
            ans[104 - i] += N[N.length() - i - 1] - '0';
        }
    }
    for(i = 104;i >= 1;i--)
    {
        if(ans[i] >= 10)
        {
            ans[i - 1] += ans[i] / 10;
            ans[i] = ans[i] % 10;
        }
    }
    temp = 0;
    for(i = 0;i < 105;i++)
    {

        if(ans[i] != 0)
            temp = 1;
        if(temp == 1)
            cout << ans[i];
    }
    cout << endl;
}


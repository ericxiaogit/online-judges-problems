#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
unsigned long long int ans[105][65];//eggs times
int main()
{

    unsigned long long int n,i,j,a,b,c;
    int k;
    for(i = 1;i < 105;i++)
    {
        ans[i][1] = 1;
    }
    for(i = 1;i < 65;i++)
    {
        ans[1][i] = i;
    }
    //cout <<"-----" <<ans[2][1] << endl;
    for(i = 2;i < 105;i++)
    {
        for(j = 2;j < 65;j++)
        {
            ans[i][j] = ans[i-1][j-1] + 1 + ans[i][j-1];
        }
    }
    /*
    cout <<"-----" <<ans[2][1] << endl;
    for(i = 1;i < 10;i++)
    {
        for(j = 1;j < 10;j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }*/
    while(cin >> k >> n)
    {
        if(k == 0) break;
        a = 65;
        for(i = 1;i < 65;i++)
        {
            if(ans[k][i] >= n)
            {
                a = i;
                break;
            }
        }
        if(a > 63)
            cout << "More than 63 trials needed." << endl;
        else
            cout << a <<endl;
    }
}


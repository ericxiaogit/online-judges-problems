#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
int ans[105][105];
int main()
{
    int C,S,Q,N = 0;
    int i,j,k,a,b,c;
    while(cin >> C >> S >> Q)
    {
        if(C == 0 && S == 0 && Q == 0) break;
        N++;
        for(i = 0;i < C;i++)
        {
            for(j = 0;j < C;j++)
            {
                ans[i][j] = 2147483647;
                ans[j][i] = 2147483647;
            }
        }
        for(i = 0;i < S;i++)
        {
            cin >> a >> b >> c;
            ans[a-1][b-1] = c;
            ans[b-1][a-1] = c;

        }
        for(k = 0;k < C;k++)
        {
            for(i = 0;i < C;i++)
            {
                for(j = 0;j < C;j++)
                {
                    if(ans[i][k] != 2147483647 && ans[j][k] != 2147483647 && max(ans[i][k],ans[j][k]) < ans[i][j])
                    {
                        ans[i][j] = max(ans[i][k],ans[j][k]);
                        ans[j][i] = max(ans[i][k],ans[j][k]);

                    }
                }
            }
        }
        /*
        for(i = 0;i < C;i++)
        {
            for(j = 0;j < C;j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }*/
        if(N != 1)
            cout <<endl;
        cout << "Case #" << N << endl;
        for(i = 0;i <Q;i++)
        {
            cin >>a >> b;
            if(ans[a-1][b-1] !=  2147483647)
                cout << ans[a-1][b-1] << endl;
            else
                cout << "no path" << endl;
        }
    }
}



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
    while(cin >> C >> S)
    {
        if(C == 0 && S == 0) break;
        N++;
        for(i = 0;i < C;i++)
        {
            for(j = 0;j < C;j++)
            {
                ans[i][j] = 0;
                ans[j][i] = 0;
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
                    if(ans[i][k] != 2147483647 && ans[j][k] != 2147483647 && min(ans[i][k],ans[j][k]) > ans[i][j])
                    {
                        ans[i][j] = min(ans[i][k],ans[j][k]);
                        ans[j][i] = min(ans[i][k],ans[j][k]);

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
        cin >>a >> b >>c;
        cout << "Scenario #" << N << endl;
        //cout << "ans = " << ans[a-1][b-1] << endl;
        cout << "Minimum Number of Trips = ";
        if(c % (ans[a-1][b-1]-1) == 0)
            cout << ((c)/(ans[a-1][b-1]-1)) << endl << endl;
        else
            cout << ((c)/(ans[a-1][b-1]-1) + 1) << endl <<endl;


    }
}



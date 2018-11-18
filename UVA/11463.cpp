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
    int i,j,k,a,b,c,p,an;
    cin >> N;
    for(p = 0;p < N;p++)
    {
        cin >> C >> S;
        for(i = 0;i < C;i++)
        {
            for(j = 0;j < C;j++)
            {

                ans[i][j] = 2147483647;
                ans[j][i] = 2147483647;
                if(i == j)
                {
                    ans[i][j] = 0;
                    ans[j][i] = 0;
                }
            }
        }
        for(i = 0;i < S;i++)
        {
            cin >> a >> b;
            ans[a][b] = 1;
            ans[b][a] = 1;

        }
        for(k = 0;k < C;k++)
        {
            for(i = 0;i < C;i++)
            {
                for(j = 0;j < C;j++)
                {
                    if(ans[i][k] != 2147483647 && ans[j][k] != 2147483647 && ans[i][k]+ans[j][k] < ans[i][j])
                    {
                        ans[i][j] =ans[i][k]+ans[j][k];
                        ans[j][i] = ans[i][k]+ans[j][k];

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
        cin >> a >> b;
        cout << "Case " << p + 1<< ": ";
        an = 0;
        for(i = 0;i < C;i++)
        {
            if(ans[a][i]+ans[i][b] > an)
                an = ans[a][i]+ans[i][b];
        }
        cout << an << endl;
    }
}



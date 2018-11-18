#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int t[50];
int d[50];
int e[50];
int have_car[200][50][2];
int dp[200][50];
int main()
{
    int N,i,M1,M2,j,T,temp = 0,now;
    while(cin >> N)
    {
        if(N == 0) break;
        temp ++;
        cin >> T;
        for(i = 0;i < N-1;i++)
        {
            cin >> t[i];
        }
        cin >> M1;
        for(i = 0;i < M1;i++)
        {
            cin >> d[i];
        }
        cin >> M2;
        for(i = 0;i < M2;i++)
        {
            cin >> e[i];
        }
        for(i = 0;i <= T;i++)
        {
            for(j = 0;j < N;j++)
            {
                have_car[i][j][0] = 0;
                have_car[i][j][1] = 0;//0 go   1 back
            }
        }
        now = 0;
        for(i = 0;i < M1;i++)
        {
            have_car[d[i]][0][0] = 1;
            now = d[i];
            for(j = 0;j < N - 1;j++)
            {
                now += t[j];
                if(now > T) break;
                have_car[now][j + 1][0] = 1;

            }
        }
        now = 0;
        for(i = 0;i < M2;i++)
        {
            have_car[e[i]][N-1][1] = 1;
            now = e[i];
            for(j = N - 2;j >= 0;j--)
            {
                now += t[j];
                if(now > T) break;
                have_car[now][j][1] = 1;

            }
        }
        dp[T][N - 1] = 0;
        for(i = 0;i < N - 1;i++)
        {
            dp[T][i] = 1000;
        }
        for(i = T-1;i >= 0;i--)
        {
            for(j = N-1;j >= 0;j--)
            {
                dp[i][j] = dp[i+1][j] + 1;
                if(j < N-1 && have_car[i][j][0] == 1 && i+t[j] <= T)
                {
                    dp[i][j] = min(dp[i][j],dp[i+t[j]][j+1]);
                }
                if(j > 0 && have_car[i][j][1] == 1 && i+t[j-1] <= T)
                {
                    dp[i][j] = min(dp[i][j],dp[i+t[j-1]][j-1]);
                }

            }
        }
        /*
        for(i = 0;i <= T;i++)
        {
            for(j = 0;j < N;j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;

        }*/
        cout << "Case Number " << temp << ": ";
        if(dp[0][0] >= 1000)
            cout << "impossible" << endl;
        else
            cout << dp[0][0] <<endl;
    }



}


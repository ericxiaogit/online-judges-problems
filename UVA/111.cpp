#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
int index[1000];
int A[1000];
int dp[1000][1000];
int N;
using namespace std;
int LCS()
{
    int i,j;
    for(i = 0;i <= N;i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for(i = 1;i<=N;i++)
    {
        for(j = 1;j <= N;j++)
        {
            if(A[i] == index[j])
                dp[i][j] = dp[i-1][j-1]+ 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[N][N];
}
int main()
{
    int i,j,k,temp;
    cin >> N;
    for(i = 0;i < N;i++)
    {
        cin >> temp;
        index[temp] = i+1;
    }
    while(cin >> temp)
    {
        A[temp] = 1;
        for(i = 1;i < N;i++)
        {
            cin >> temp;
            A[temp] = i+1;
        }
        cout << "hello" << endl;
        cout << LCS() << endl;
    }

}




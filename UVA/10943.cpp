#include<bits/stdc++.h>
#define MOD 1000000
using namespace std;/*
long long int ways(long long int val,long long int much)
{
    if(val == 0)
        return 1;
    if(much == 1) return 1;
    long long int p = 0;
    for(long long int i = 0;i <= val;i++)
    {
        p += ways(val - i,much -1);
        p = p%MOD;
    }
    return p;
}*/
long long int dp[100+5][100+5];
int main()
{
    long long int N,M,i,j,k;
    for(i = 0;i <= 100;i++)
    {
        for(j = 0;j <= 100;j++)
        {
            if(i == 0)
            {
                dp[i][j] = 1;
            }
            else if(j == 1)
            {
                dp[i][j] = 1;
            }
            else
            {
                for(k = 0;k <= i;k++)
                {
                    dp[i][j] += dp[i-k][j-1];
                    dp[i][j] %= MOD;
                }
            }

        }
    }
    while(cin >> N >> M)
    {
        cout <<dp[N][M] <<endl;
    }


}




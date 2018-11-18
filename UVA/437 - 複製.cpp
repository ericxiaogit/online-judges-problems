#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
long long int N;
long long int length[30][3];
long long int ans[30][3];
long long int dp(long long int idx,long long int k)
{
    //cout << "idx = " << idx << " k = " << k << endl;
    if(ans[idx][k] > 0)
    {
        return ans[idx][k];
    }
    long long int i,j;
    ans[idx][k] = length[idx][k];
    for(i = 0;i < N;i++)
    {
        for(j = 0;j < 3;j++)
        {
            if(((length[i][(j+1)%3] < length[idx][(k+1)%3]) && (length[i][(j+2)%3] < length[idx][(k+2)%3])) || ((length[i][(j+1)%3] < length[idx][(k+2)%3]) && (length[i][(j+2)%3] < length[idx][(k+1)%3])))
            {
                ans[idx][k] = max(ans[idx][k],(dp(i,j) + length[idx][k]));
                //cout << idx << " " << k << " " <<i << " " << j <<endl;
            }
        }
    }
    return ans[idx][k];
}
int main()
{
    long long int i,j,k,answer,temp = 0;
    while(cin >> N)
    {
        if(N == 0) break;
        temp ++;
        for(i = 0;i < N;i++)
        {
            for(j = 0;j < 3;j++)
            {
                ans[i][j] = 0;
                cin >> length[i][j];
            }
        }
        answer = 0;
        for(i = 0;i < N;i++)
        {
            for(j = 0;j < 3;j++)
            {
                answer = max(answer,dp(i,j));
                //cout << ans[i][j] << " ";
            }
            //cout << endl;
        }
        cout << "Case " << temp << ": maximum height = ";
        cout << answer <<endl;
    }
}


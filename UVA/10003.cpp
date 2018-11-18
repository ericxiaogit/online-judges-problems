#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int A[100];
int ans[55][55];
int dp(int a,int b)
{
    //cout <<a << " " << b << endl;
    //system("pause");
    if(ans[a][b] != 0)
    {
        return ans[a][b];
    }
    int i,j,temp;
    if(abs(a - b) < 2)
        return 0;
    for(i = a + 1;i < b;i++)
    {
        temp = dp(a,i) + dp(i,b) + A[b] - A[a];
        if(ans[a][b] == 0 || ans[a][b] > temp)
            ans[a][b] = temp;
    }
    return ans[a][b];
}
int main()
{
    int L,N,i,j;
    while(cin >> L)
    {
        if(L == 0) break;
        cin >> N;
        A[0] = 0;
        A[N+1] = L;
        for(i = 0;i <= N+1;i++)
        {
            for(j = 0;j <= N+1;j++)
            {
                ans[i][j] = 0;
            }
        }
        for(i = 0;i < N;i++)
        {
            cin >> A[i +1];
        }
        //cout << dp(0,N+1) << endl;
        int K = dp(0,N+1);
        printf("The minimum cutting is %d.\n",K);
    }
}


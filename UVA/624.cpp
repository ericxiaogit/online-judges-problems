#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int length[100005];
int people[100000];
int ans[100000];
int num[100000];
int in[10000][10000];
int main()
{
    long long int i,j,T,k,big;
    long long int N,G;
    long long int now,temp;
    int a,b;
    now = 3;
    temp = 0;
    while(cin >> N >> T)
    {
        big = 0;
        for(i = 0;i < T;i++)
        {
            cin >> length[i];
        }
        for(i = 0;i <= N;i++)
        {
            ans[i] = 0;
            num[i] = 0;
        }
        for(i = 0;i < T;i++)
        {
            for(j = N;j - length[i] >= 0;j--)
            {
                if(ans[j - length[i]]+length[i] > ans[j])
                {
                    num[j]=num[j - length[i]] + 1;
                    for(k = 0;k < num[j - length[i]];k++)
                    {
                        in[j][k] = in[j - length[i]][k];
                    }
                    in[j][num[j] - 1] = length[i];
                    ans[j] = ans[j - length[i]]+length[i];
                }
            }
        }
        //cout << num[N] <<endl;
        for(i = 0;i < num[N];i++)
        {
            cout << in[N][i] << " ";
        }

        cout << "sum:" << ans[N] <<endl;



    }
}


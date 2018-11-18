#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int value[1005];
int ans[50000+5];
int main()
{
    long long int i,j,T,k,big;
    long long int N,G;
    long long int now,temp;
    int a,b;
    int half,sum;
    now = 3;
    temp = 0;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            cin >> T;
            sum = 0;
            for(j = 0;j < T;j++)
            {
                cin >> value[j];
                sum += value[j];
            }
            half = sum/2;
            for(j = 0;j <= half;j++)
            {
                ans[j] = 0;
            }
            for(j = 0;j < T;j++)
            {
                for(k = half;k-value[j] >= 0;k--)
                {
                    ans[k] = max(ans[k],ans[k-value[j]] + value[j]);
                }
            }
            //cout << "big = " << big <<endl;

            //for(j = 0;j <= big;j++)
            //{
            //    cout << j << " :" << ans[j] <<endl;
            //}
            cout << sum - ans[half]  - ans[half]<< endl;
        }




    }
}


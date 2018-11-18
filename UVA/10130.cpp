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
int weight[1005];
int people[100000];
int ans[40];
int main()
{
    long long int i,j,T,k,big;
    long long int N,G;
    long long int now,temp;
    int a,b;
    now = 3;
    temp = 0;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            cin >> T;
            for(j = 0;j < T;j++)
            {
                cin >> value[j] >> weight[j];
            }
            cin >> G;
            for(j = 0;j < G;j++)
            {
                cin >> people[j];
            }
            sort(people,people + G);
            reverse(people,people + G);
            big = people[0];
            for(j = 0;j < 40;j++)
            {
                ans[j] = 0;
            }
            for(j = 0;j < T;j++)
            {
                for(k = big;k-weight[j] >= 0;k--)
                {
                    ans[k] = max(ans[k],ans[k-weight[j]] + value[j]);
                }
            }
            //cout << "big = " << big <<endl;

            int last = 0;
            //for(j = 0;j <= big;j++)
            //{
            //    cout << j << " :" << ans[j] <<endl;
            //}
            for(j = 0;j < G;j++)
            {
                last += ans[people[j]];
            }
            cout << last <<endl;
        }




    }
}


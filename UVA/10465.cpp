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
int people[10000 + 5];
int ans[10000 + 5];
int a[10000+5];
int b[10000+5];
int main()
{
    int i,j,T,k,big;
    long long int N,G;
    long long int now,temp;
    int trash;
    int m,n,t;
    //int a,b;
    now = 3;
    temp = 0;
    while(cin >> m >> n >> t)
    {
        for(i = 0;i <= t;i++)
        {
            ans[i] = 0;
            a[i] = 0;
            b[i] = 0;
        }
        if(m > n)
            swap(m,n);
        //system("pause");
        for(i = t;i - m >= 0;i--)
        {
            trash = i/m;
            ans[i] = trash * m;
            a[i] += trash;

        }
        //system("pause");

            for(j = n;j <= t;j = j + n)
            {
                //ans[i] = max(ans[i],ans[i-j] + j);
                if(ans[t] < ans[t-j] + j)
                {
                    ans[t] = ans[t-j] + j;
                    a[t] = a[t-j];
                    b[t] = b[t-j] + j/n;
                }
            }

        //system("pause");
        cout << a[t] + b[t];
        if(t - ans[t] != 0)
            cout << " " << t - ans[t];
        cout << endl;


    }
}


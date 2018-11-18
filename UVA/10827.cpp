#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
int A[105][105];
int S[105][105];
using namespace std;
int main()
{
    int sum;
    int a,b;
    int N,i,k,j;
    double avg,temp;
    int ans,now,low,T;
    int fin;
    int p;
    cin >> T;
    for(p = 0;p < T;p++)
    {
        cin >>N;
        for(i = 0;i < N;i++)
        {
            for(j = 0;j < N;j++)
            {
                cin >> A[i][j];
                if(i > 0)
                {
                    S[i][j] = S[i - 1][j] + A[i][j];
                }
                else
                    S[i][j] = A[i][j];
            }
        }
        fin = 0;
        for(i = 0;i < N;i++)
        {
            for(j = 0;j <= i;j++)
            {
                low = 0;
                ans = 0;
                now = 0;
                for(k = 0;k < N;k++)
                {
                    if(j == 0)
                        a = S[i][k];
                    else
                        a = S[i][k] - S[j - 1][k];
                    //cout << "i = " <<i << ",j = " << j << ",k = " << k << ",a = " << a << endl;
                    /*
                    now += a;
                    if(now < low)
                        low = now;
                    if(now - low > ans)
                    {
                        ans = now - low;

                    }
                    */
                    if(a > 0)
                        ans += a;

                }
                if(ans > fin)
                    fin = ans;
            }
        }
        cout << fin << endl;
    }

}




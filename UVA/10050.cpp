#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int A[4000];
int main()
{
    //string a;
    long long int num,N,i,how,temp,T,j,a,big,print,ans,x,y,P,k;
    while(cin >> T)
    {
        for(i = 0;i < T;i++)
        {
            cin >> N >> P;
            for(j = 0;j < P;j++)
            {
                cin >>a;
                for(k = a;k <= N;k += a)
                {
                    A[k] = 1;
                }
            }
            ans = 0;
            for(j = 1;j <= N;j++)
            {
                if(A[j] == 1 && (j % 7 != 0) && (j % 7 != 6))
                    ans++;
                A[j] = 0;
            }
            cout << ans << endl;
        }
    }
}


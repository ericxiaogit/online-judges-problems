#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int Y[30];
int A[10000];
int B[20];
int main()
{
     int N,i,a,b,c,d,temp,j,t,big,K;
    t = 0;
    int rolls,cig,ans;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            cin >> K;
            ans = 0;
            for(j = 0;j < K;j++)
            {
                cin >> A[j];
            }
            sort(A,A+K);
            temp = A[K/2];
            for(j = 0;j < K;j++)
            {
                ans += abs(temp - A[j]);
            }
            //cout << "temp = " << temp << endl;
            cout << ans << endl;
        }
    }


}


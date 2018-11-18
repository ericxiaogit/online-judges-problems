#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
long long int A[1000+5][1000+5];
int main()
{
    long long int N;
    long long int i,j;
    long long int a,b,c,T;
    long long int now;
    long long int m,n;
    long long int temp;
    scanf("%lld",&N);
    //cout << N << endl;
        for(i = 0;i < N;i++)
        {
            scanf("%lld %lld",&m,&n);
            now = m - 1;
            temp = sqrt((n - now)*2 + 2);
            if(now == n)
            {
                cout << now << endl;
                continue;
            }
            else if(n - now == 1)
            {
                cout << now - 2<< endl;
                continue;
            }
            while((temp)*(temp - 1)/2  < n - now)
            {
                temp++;
            }
            cout << now - temp << endl;
        }

}


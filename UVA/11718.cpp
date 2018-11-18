#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
long long int mod;
long long int pows(long long int a,long long int b)
{
    if(b == 1)
    {
        return (a % mod);
    }
    if(b == 0)
    {
        return 1;
    }
    else if(b % 2 == 0)
        return ((pows(a,b/2) % mod)*(pows(a,b/2) % mod))%mod;
    else
        return ((pows(a,b/2) % mod)*(pows(a,b/2) % mod)*a)%mod;
}
int main()
{
    long long int N,n,k,sum,temp,t,i,j;
    while(cin >> N)
    {
        for(j = 0;j < N;j++)
        {
            cin >> n >> k >> mod;
            sum = 0;
            for(i = 0;i < n;i++)
            {
                cin >>temp;
                sum += temp;
            }
            t = pows(n,k-1);
            cout << "Case " << j+1 << ": ";
            cout << (((t*k)%mod)*sum)%mod <<endl;
        }

    }
    return 0;
}


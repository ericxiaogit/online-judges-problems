#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
long long int A[40000];
long long int prime[40000];
using namespace std;
int main()
{
    long long int N;
    long long int i,j,how = 0;
    for(i = 2;i < 40000;i++)
    {
        if(A[i] == 0)
        {
            prime[how] = i;
            how++;
            if(i <= sqrt(40000))
            {
                for(j = i * i;j < 40000;j+= i)
                {
                    A[j] = 1;
                }
            }

        }
    }

    long long a,b,temp,start;
    while(cin >> N)
    {
        start = N;
        if(N == 0) break;
        if(N == 1)
        {
            cout << 0 << endl;
            continue;
        }
        a = 1;
        b = 1;
        for(i = 0;prime[i] < start;i++)
        {
            //cout << i << " " << prime[i] << endl;
            temp = 0;
            if(i >= how) break;
            while(N % prime[i] == 0)
            {
                temp = 1;
                N = N / prime[i];
            }
            if(temp == 1)
            {
                a = a*(prime[i] - 1);
                b = b*(prime[i]);
            }
            //cout <<"N = " << N << endl;
            //cout << a << " " << b <<endl;
        }
        //cout <<start << " " << a << " " << b <<endl;
        if(N == start)
            cout << start - 1 << endl;
        else if(N != 1)
            cout << start * a/b * (N-1)/N<<endl;
        else
            cout << start * a/b << endl;
    }

}




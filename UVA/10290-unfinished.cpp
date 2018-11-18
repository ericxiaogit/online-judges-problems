#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <bits/stdc++.h>
using namespace std;
long long int prime[1000000];
long long int numbers[1000000];
long long int ans[1000000];

int main()
{
    //string a;
    long long int num,N,i,how,temp,nows,j,a,big,print;
    how = 0;

    for(i = 0;i < 1000000;i++)
    {
        numbers[i] = 0;
    }
    prime[how] = 2;
    how ++;
    for(j = 4;j < 1000000;j = j + 2)
    {
        numbers[j] = 1;
    }
    ans[0] = 0;
    ans[1] = 0;
    ans[2] = 0;

    for(i = 3;i <= sqrt(1000000);i++)
    {
        ans[i] = 0;
        if(numbers[i] == 0)
        {
            prime[how] = i;
            how ++;
            for(j = i*i;j < 1000000;j = j + 2 * i)
            {
                numbers[j] = 1;
            }
        }

    }
    for(i = 3;i < 1000000;i++)
    {
        if(numbers[i] == 0)
        {
            prime[how] = i;
            how ++;
        }

    }
    cout << "hello" <<endl;
    cout << "how = " << how << endl;
    while(cin >> N)
    {
        if(N == 0)
        {
            cout << 0 <<endl;
            continue;
        }
        while(N % 2 == 0)
        {
            N = N/2;
        }
        for(i = 0;i < 1000000;i++)
        {
            ans[i] = 0;
        }
        a = -1;
        temp = sqrt(N) +2;
        for(i = 1;i < 78665;i++)
        {
            if(N == 1) break;
            if(prime[i] > temp)
            {
                //cout << "prime = " << prime[i] << endl;
                i = N - 1;
                continue;
            }
            if(N % prime[i] == 0)
            {
                //cout << prime[i] << endl;
                //cout << "a++" << endl;
                a ++;
            }
            while(N % prime[i] == 0)
            {

                N /= prime[i];
                ans[a] ++;
            }
        }
        print = 1;

        for(i = 0;i <= a;i++)
        {
            //cout << "ans[i] = " <<ans[i] << endl;
            print *= (ans[i] + 1);
        }
        if(a == -1 && N > 1000000 && N%2 == 1)
            cout << 2 << "hello" << endl;
        else if(N == 1)
            cout << print << endl;
        else
            cout << print * 2 << endl;
    }
}


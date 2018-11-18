#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int Y[30];
int numbers[10000001 + 5];
int prime[10000001 + 5];
int ans[10000001 + 5];
int aa[10000001 + 5];
int how;
int main()
{
     int N,i,a,b,c,d,temp,j,big,K;

    int how;
    how = 1;
    prime[0] = 2;
    int t = sqrt(2703664);
    int p = sqrt(t);
    //cout << "t = " << t << " p = " << p << endl;
    for(i = 4;i < t;i += 2)
    {
        numbers[i] = 1;
    }
    for(i = 3;i <= t;i+=2)
    {
        if(numbers[i] == 0)
        {
            //cout << "i = " << i << endl;
            prime[how] = i;
            how ++;
            for(j = i*i;j < 2703664;j += 2 * i)
            {
                numbers[j] = 1;
            }
        }
    }
    for(i = t + 1;i < 2703664;i+= 2)
    {
        if(numbers[i] == 0)
        {
            //cout << "i = " << i << endl;
            prime[how] = i;
            how++;
        }

    }
    ans[0] = 1;
    ans[1] = 1;
    for(i = 0;i < how;i++)
    {
        for(j = prime[i];j < 2703665;j += prime[i])
        {
            int l = j;
            while(l % prime[i] == 0)
            {
                l /= prime[i];
                aa[j] ++;
            }
        }
    }
    for(i = 2;i < 2703665;i++)
    {
        ans[i] = ans[i - 1] + aa[i];

    }
    int h;
    h = 0;
    while(cin >> N)
    {
        h++;
        if(N < 0) break;
        N++;
        int i;
        i = 0;
        int tf = 0;
        while(1)
        {
            if(ans[i] == N) break;
            if(ans[i] > N)
            {
                tf = 1;
                break;
            }
            i++;
        }
        cout << "Case " << h << ": ";
        if(tf == 1)
            cout << "Not possible." << endl;
        else
            cout << i << "!" << endl;
    }


}


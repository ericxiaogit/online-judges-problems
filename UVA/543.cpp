#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int Y[30];
int numbers[1000001 + 5];
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
    numbers[1] = 1;
    numbers[0] = 1;
    for(i = 4;i < 1000001 + 5;i += 2)
    {
        numbers[i] = 1;
    }
    for(i = 3;i <= sqrt(1000001 + 5);i+=2)
    {
        if(numbers[i] == 0)
        {
            //cout << "i = " << i << endl;
            for(j = i*i;j < 1000001 + 5;j += 2 * i)
            {
                numbers[j] = 1;
            }
        }
    }
    while(cin >> N)
    {
        if(N == 0) break;
        int i;
        i = 0;
        int tf = 0;
        int a = 0,b = 0;
        for(i = 0;i < N;i++)
        {
            if(numbers[i] == 0 && numbers[N - i] == 0)
            {
                a = i;
                b = N - i;
                tf = 1;
                break;
            }
        }
        if(tf = 0)
            cout << "Goldbach's conjecture is wrong." << endl;
        if(a > b)
            swap(a,b);
        else
            cout << N << " = " << a << " + " << b <<endl;
    }


}


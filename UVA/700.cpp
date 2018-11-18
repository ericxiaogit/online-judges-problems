#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int Y[30];
int A[30];
int B[20];
int g(int a,int b)
{
    int t,c,d;
    c = a;
    d = b;
    while(1)
    {
        a = a % b;
        if(a == 0 || b == 0)
        {
            break;
        }
        b = b % a;
        if(a == 0 || b == 0)
        {
            break;
        }
    }
    t = abs(a - b);
    return (c * d) / t;
}
int f(int a,int b,int c,int d)// X%a == b  X % c == d return
{
    int i = 1;
    for(i = 1;2 > 1;i++)
    {
        if(i % a == b && i % c == d)
        {
            return i;
            break;
        }
    }

}
int main()
{
    int N,i,a,b,c,d,ans,temp,j,t,big;
    t = 0;
    while(cin >> N)
    {
        t++;
        if(N == 0) break;

        ans = -1;
        big = 0;
        for(i = 0;i < N;i++)
        {
            cin >> Y[i] >> A[i] >> B[i];
            if(Y[i] > big)
                big = Y[i];
        } /*
        if(Y[0] < A[0])
        {
            ans = A[0];
        }
        a = B[0] - A[0];
        b = Y[0] % (B[0] - A[0]);
        for(i = 1;i < N;i++)
        {
            if(ans != -1) break;
            if(Y[i] < A[i])
            {
                ans = Y[i];
                break;
            }
            c = B[i] - A[i];
            d = Y[i] % (B[i] - A[i]);
            b = f(a,b,c,d);
            a = g(a,c);
            cout << a  <<" " <<  b;
        }
        cout << a + b <<endl;*/
        temp = 0;
        for(i = big;i < 10000;i++)
        {
            temp = 0;
            for(j = 0;j < N;j++)
            {

                if((i % (B[j] - A[j])) != (Y[j] % (B[j] - A[j])))
                {
                    temp = 1;
                    break;
                }
            }
            if(temp == 0)
            {
                ans = i;
                break;
            }

        }
        //cout << 2141 - 2005;
        cout << "Case #" << t << ":" << endl;
        if(ans == -1)
            cout << "Unknown bugs detected." << endl;
        else
            cout << "The actual year is "<< ans << "." << endl;
        cout <<endl;
    }


}


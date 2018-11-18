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
    int i,c,d,j,t,K;
    t = 0;
    int rolls,cig,ans;
    int a,b;
    int temp;
    int N;
    int sum;
    temp = 0;
    int big,eq;
    while(cin >> N)
    {
        temp ++;
        if(N == 0) break;
        cout << "Case " << temp << ": ";
        big = 0;
        eq = 0;
        for(i = 0;i <N;i++)
        {
            cin >>a;
            if(a > 0)
                big++;
            else if(a == 0)
                eq ++;
        }
        cout << big - eq <<endl;

    }


}


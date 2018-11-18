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
    int i,c,d,j,t,big,K;
    t = 0;
    int rolls,cig,ans;
    int a,b;
    int temp;
    string N;
    int sum;
    temp = 0;
    while(cin >> K)
    {
        sum = 0;
        for(i = 0;i <K;i++)
        {
            cin >>N;
            if(N == "donate")
            {
                cin >> temp;
                sum += temp;
            }
            else
                cout << sum << endl;
        }
    }


}


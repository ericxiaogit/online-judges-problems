#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
int A[100000];
bool in[100000];
using namespace std;
int maxn;
int ans;
int searc(int s)
{
    if(s == A[s])
    {
        return A[s];
    }
    else
    {
        A[s] = searc(A[s]);
        return A[s];
    }
}
int main()
{
    int N,a,b,rr,i;
    int tempa,tempb,cas;
    for(i = 0;i < 100000;i++)
    {
        A[i] = i;
        in[i] = 0;
    }
    ans = 0;
    maxn = 0;
    cas = 1;
    while(cin >> a >> b)
    {
        if(a == 0 & b == 0)
        {
            for(i = 1;i < maxn;i++)
            {
                if(in[i] == 1)
                {
                    rr = searc(i);
                    break;
                }
            }
            for(i = 1;i < maxn;i++)
            {

                if(in[i] == 1 && searc(i) != rr)
                {

                    ans = 1;
                    break;
                }
            }
            cout <<"Case " << cas;
            if(ans == 0)
            {
                cout << " is a tree." <<endl;
            }
            else
            {
                cout << " is not a tree." <<endl;
            }
            for(i = 0;i < 100000;i++)
            {
                A[i] = i;
                in[i] = 0;
            }
            ans = 0;
            maxn = 0;
            cas ++;

        }
        else if(a < 0 && b < 0)
        {
            break;
        }
        else
        {
            in[a] = 1;
            in[b] = 1;
            if(a > maxn)
            {
                maxn = a;
            }
            if(b > maxn)
            {
                maxn = b;
            }
            N++;
            tempa = searc(a);
            tempb = searc(b);
            if(tempa == tempb)
            {
                ans = 1;
            }
            else
            {
                A[tempa] = tempb;
            }
        }
    }
}




#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int A[500000 + 5];
int B[500000 + 5];
string name[50000];
int ans;
int finds(int r)
{
    if(A[r] == r)
    {
        //ans = r;
        return r;
    }
    else
    {
        A[r] = finds(A[r]);
        return A[r];
    }
}
int main()
{
    int K,M,N,i,j,c,d,an,bn;
    string a,b;
    int C,R;
    while(cin >> C >> R)
    {
        if(C == 0 && R == 0) break;
        for(i = 0;i < C;i++)
        {
            cin >> name[i];
            A[i] = i;
            B[i] = 1;
        }
        for(i = 0;i < R;i++)
        {
            cin >> a>> b;
            for(j = 0;j < C;j++)
            {
                if(a == name[j])
                    an = j;
                if(b == name[j])
                    bn = j;
            }
            c = finds(an);
            d = finds(bn);
            if(c != d)
            {
                A[c] = d;
                B[d] += B[c];
            }
        }
        ans = 1;
        for(i = 0;i < C;i++)
        {
            if(B[i] > ans)
                ans = B[i];
        }
        cout << ans <<endl;
    }
}



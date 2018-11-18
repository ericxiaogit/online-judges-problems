#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
long long int A[1000000];
long long int B[1000000];
using namespace std;
int main()
{
    int N,i,j;
    int a,b;
    int ans;
    int p,q;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            ans = 0;
            cin >> a >> b;
            for(j = 0;j < a;j++)
            {
                cin >> A[j];
            }
            for(j = 0;j < b;j++)
            {
                cin >> B[j];
            }
            sort(A,A+a);
            sort(B,B+b);
            p = 0;
            q = 0;
            while(1)
            {
                if(p >= a || q >= b) break;
                if(A[p] == B[q])
                {
                    p++;
                    q++;
                }
                else if(A[p] > B[q])
                {
                    ans++;
                    q++;
                }
                else if(A[p] < B[q])
                {
                    ans++;
                    p++;
                }
            }
            cout << ans + a + b - p -q << endl;
        }


    }

}




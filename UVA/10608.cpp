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
    int K,M,N,i,j,a,b,c,d;
    cin >> K;
    for(i = 0;i < K;i++)
    {
        cin >> N >> M;
        for(j = 1;j <=N;j++)
        {
            A[j] = j;
            B[j] = 1;
        }
        for(j = 0;j < M;j++)
        {
            cin >> a >> b;
            c = finds(a);
            d = finds(b);
            //cout << c << " " << d << endl;
            if(c == d)
                continue;
            A[c] = A[d];
            B[d] += B[c];
        }
        ans = 1;
        for(j = 1;j <= N;j++)
        {
            //cout << A[j] << " ";
            if(B[j] > ans)
                ans = B[j];
        }
        //cout << endl;
        cout << ans << endl;
    }

}



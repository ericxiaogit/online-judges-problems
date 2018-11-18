#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
int A[50 + 5];
int B[50 + 5];
using namespace std;
struct vec
{
    int a,b;
};
vec C[50 + 5];
int main()
{
    vec v,u;
    int N,i,j,k,ans = 0,temp;
    while(cin >> N)
    {
        if(N == 0) break;
        ans = 0;
        cin >> A[0] >>B[0] >> A[1] >> B[1] >> A[2] >> B[2];
        C[1].a = A[1] - A[0];
        C[1].b = B[1] - B[0];
        C[2].a = A[2] - A[1];
        C[2].b = B[2]-B[1];
        //cout << C[1].a << " " <<C[1].b << " " << C[2].a << " " << C[2].b << endl;
        temp = C[1].a * C[2].b - C[1].b * C[2].a;
        for(i = 3;i < N;i++)
        {
            cin >> A[i]>>B[i];
            C[i].a = A[i] - A[i - 1];
            C[i].b = B[i] - B[i - 1];
            //cout <<temp << " " << C[i - 1].a * C[i].b - C[i].a*C[i - 1].b << endl;
            if((C[i - 1].a * C[i].b - C[i].a*C[i - 1].b) * temp < 0)
                ans = 1;
        }
        if(ans == 0)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }

}




#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int A[100000];
int B[100000];
int L,S;
int recure(int a,int b,int c)//now,sum,front
{
    //cout << "Sa = " << S << endl;
    int i,ans=0;
    for(i = c + 1;i <= 26;i++)
    {
        //cout << "bye" << endl;
        //cout << b << " " << i << " " << S << endl;
        if(b + i >= S)
        {
            break;
        }
        //cout << "hello" << endl;
        ans += recure(a+1,b+i,i);
    }
    cout << a << " " << b << " " << c << " " << ans << endl;
    return ans;
}
int main()
{
    int i,temp;
    temp = 0;
    while(cin >> L >> S)
    {
        //cout << "S = " << S << endl;
        temp ++;
        if(L == 0 && S ==0) break;
        cout << recure(0,0,0) << endl;

    }
}



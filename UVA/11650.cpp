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
int main()
{
    int N;
    int i,j;
    char t;
    int a,b;
    int ans1,ans2;
    cin >> N;
    for(i = 0;i < N;i++)
    {
        cin >> a >> t >> b;
        if(a == 12)
            a == 0;
        ans1 = 11 - a;
        ans2 = 60 - b;
        if(ans1 <= 0)
            ans1 += 12;
        if(ans2 >= 60)
        {
            ans2 -= 60;
            ans1++;
        }
        if(ans1 < 10)
        {
            cout << 0;
        }
        cout << ans1;
        cout << ":";
        if(ans2< 10)
            cout << 0;
        cout << ans2;
        cout << endl;
    }
}



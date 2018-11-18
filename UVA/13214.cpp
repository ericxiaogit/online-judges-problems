#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
long long int ans[30][30];
int main()
{
    int SZ,P,i,j,ll;
    double t;
    int even,odd,evans;
    int trash,temp;
    int N;
    trash = 0;
    int flag;
    int tempi,tempj;
    ans[1][1] = 1;
    for(i = 1;i <= 25;i++)
    {
        ans[i][1] = 1;
        for(j = 2;j <= 25;j++)
        {
            ans[i][j] = ans[i][j-1] + ans[i -1][j];
        }
    }
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            cin >> tempi >> tempj;
            cout << ans[tempi][tempj] << endl;
        }
    }
}


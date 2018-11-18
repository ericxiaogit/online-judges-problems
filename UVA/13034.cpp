#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int letters[26];
int coun[30 + 5];

int main()
{
    int sum,P,i,j,ll;
    double t;
    int even,odd,evans;
    int trash,temp;
    int W , N,M;
    int day,month,year,qy;
    trash = 0;
    int zero;
    int flag;
    int n,m;
    int a;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            flag = 0;
            for(j = 0;j < 13;j++)
            {
                cin >> a;
                if(a == 0)
                    flag = 1;
            }
            cout << "Set #" << i + 1 << ": " ;
            if(flag == 0)
                cout << "Yes" << endl;
            else
                cout << "No" <<endl;
        }

    }
}


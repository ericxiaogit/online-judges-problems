#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    int SZ,P,i,j,ll;
    double t;
    int even,odd,evans;
    int trash,temp;
    string N;
    trash = 0;
    int flag;
    while(cin >> N)
    {
        if(N == "#") break;
        flag = 0;
        for(i = N.length() - 2;i >= 0;i--)
        {
            if(N[i] < N[i + 1])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            cout << "No Successor" <<endl;
            continue;
        }
        trash = i + 1;
        for(j = N.length() - 1;j > i;j--)
        {
            if(N[j] < N[trash] && N[j] > N[i])
            {
                trash = j;
            }
        }
        //cout << i << " " << trash << endl;
        swap(N[trash],N[i]);
        //cout << N << endl;
        sort(N.begin() + i + 1,N.end());
        cout << N << endl;
    }
}


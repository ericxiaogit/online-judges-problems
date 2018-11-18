#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int A[100000 + 5];
int main()
{
    int i,ans;
    int high,low,mid,last;
    int a,b;
    int temp;
    string N;
    while(cin >> N)
    {
        for(i = 0;i < N.length();i++)
        {
            if(N[i] == '-' || N[i] == '1' || N[i] == '0')
                cout << N[i];
            else
            {
                if(N[i] > 'R')
                    N[i]--;
                temp = (N[i] - 'A') / 3 + 2;
                if(temp > 9)
                    temp = 9;
                cout << temp;
            }
        }
        cout << endl;
    }
}


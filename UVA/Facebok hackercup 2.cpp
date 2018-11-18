#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
string name[500];
int A[500];
int main()
{
    long long int T,N,K,V,i,j,head,trash;
    cin >> T;
    for(i = 0;i < T;i++)
    {
        cin >> N;
        for(j = 0;j <= N;j++)
        {
            cin >>trash;
        }
        cout << "Case #" << i+1 << ": ";
        if(N%2 == 0)
            cout << 0 << endl;
        else
        {
            cout << 1 << endl;
            cout << "0.0" << endl;
        }
    }



}



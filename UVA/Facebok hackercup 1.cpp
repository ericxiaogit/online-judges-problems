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
    long long int T,N,K,V,i,j,head;
    cin >> T;
    for(j = 0;j <T;j++)
    {
        cin >> N >> K >> V;
        for(i = 1;i <= N;i++)
        {
            cin >> name[i];
        }
        long long int temp = (K*V)%N;
        for(i = 0;i < K;i++)
        {
            if(temp - i > 0)
                A[i] = temp - i;
            else
                A[i] = temp - i + N;
        }
        sort(A,A+K);
        cout << "Case: #" << j+1 << ":";
        for(i = 0;i < K;i++)
        {
            cout << " " << name[A[i]];
        }
        cout <<endl;
    }




}



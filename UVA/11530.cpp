#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int A[26] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
int main()
{
    int i,c,d,j,t,big,K;
    t = 0;
    int rolls,cig,ans;
    int a,b;
    int temp;
    string N;
    int sum;
    temp = 0;
    while(cin >> K)
    {
        getline(cin,N);
        for(j = 0;j < K;j++)
        {

            getline(cin,N);
            sum = 0;
            for(i = 0;i < N.length();i++)
            {
                if(N[i] == ' ')
                    sum++;
                else
                    sum += A[N[i] - 'a'];
            }
            cout << "Case #" << j+1 <<": ";
            cout << sum << endl;
        }

    }


}


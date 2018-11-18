#define _USE_MATH_DEFINES
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
# define XX 1035671
using namespace std;

int main()
{
    int N,a,b,temp,i,j;
    int left,right;
    cin >> N;
    for(i = 0;i < N;i++)
    {
        cin >> a >> b;
        temp = pow(2,a-1);
        left = 0;
        right = temp;
        for(j = 0;j < a - 1;j++)
        {
            //cout << left << " " <<right << endl;
            if(b%((int)pow(2,j+1)) > ((int)pow(2,j)) || b%((int)pow(2,j+1)) == 0)
            {
                left += (right - left)/2;
            }
            else
            {
                right -= (right - left)/2;
            }
        }
        cout << temp + left << endl;

    }
}



